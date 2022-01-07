#ifndef ENTERGAMEWIDGET_H
#define ENTERGAMEWIDGET_H

#include <QWidget>
#include "rankwidget.h"
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class EnterGameWidget; }
QT_END_NAMESPACE

class EnterGameWidget : public QWidget
{
    Q_OBJECT

public:
    EnterGameWidget(QString *rankStr, QWidget *parent = nullptr);
    ~EnterGameWidget();
    void paintEvent(QPaintEvent *event);
private:
    Ui::EnterGameWidget *ui;
    RankWidget *rankWid;
    void setButton();
    void zoom1();
    void zoom2();
    void sleep(unsigned int msec);

};
#endif // ENTERGAMEWIDGET_H
