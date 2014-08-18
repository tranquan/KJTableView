#ifndef KJSTYLEDITEMDELEGATE_H
#define KJSTYLEDITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QLabel>
#include <QPushButton>
#include <QTableView>

#include "kjconversationwidget.h"

class KJStyledItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit KJStyledItemDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QTableView *tableView;
    QList<KJConversationWidget*> widgets;

    void refreshWidgets(bool hide);

private:

signals:

public slots:

};

#endif // KJSTYLEDITEMDELEGATE_H
