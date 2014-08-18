#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QStandardItemModel>
#include <QTableView>
#include <QTableWidget>
#include <QLayout>
#include <QFormLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnAdd, SIGNAL(clicked()), SLOT(slotOnButtonAddClicked()));
    connect(ui->btnRemove, SIGNAL(clicked()), SLOT(slotOnButtonRemoveClicked()));

    _model = new KJModel(0);
    _styledItemDelegate = new KJStyledItemDelegate(0);
    _styledItemDelegate->tableView = ui->tableView;
    QList<KJConversationWidget*> widgets = _styledItemDelegate->widgets;

    ui->tableView->viewport()->setLayout(new QVBoxLayout());
    for (int i = 0; i < widgets.count(); i++) {
        ui->tableView->viewport()->layout()->addWidget(widgets.at(i));
    }

    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setModel(_model);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setItemDelegate(_styledItemDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotOnButtonAddClicked()
{
    int rows = ui->ledRows->text().toInt();
    if (rows < 1) rows = 1;
    for (int i = 0; i < rows; i++) {
        _model->addItem();
    }
    if (_model->rowCount() > 0) {
        _styledItemDelegate->refreshWidgets(false);
    }
    _model->reloadData();
}

void MainWindow::slotOnButtonRemoveClicked()
{
    int rows = ui->ledRows->text().toInt();
    if (rows < 1) rows = 1;
    for (int i = 0; i < rows; i++) {
        _model->removeItem();
    }
    if (_model->rowCount() == 0) {
        _styledItemDelegate->refreshWidgets(true);
    }
    _model->reloadData();
}
