#ifndef KJCONVERSATIONWIDGET_H
#define KJCONVERSATIONWIDGET_H

#include <QWidget>

namespace Ui {
class KJConversationWidget;
}

class KJConversationWidget : public QWidget
{
    Q_OBJECT

public:
    int widgetIndex;
    explicit KJConversationWidget(QWidget *parent = 0);
    ~KJConversationWidget();
    void init(QString title, QString detail, int found);

private:
    Ui::KJConversationWidget *ui;

private slots:
    void slotOnButtonClicked();
};

#endif // KJCONVERSATIONWIDGET_H
