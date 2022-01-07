#include "startwidget.h"
#include <QPainter>
StartWidget::StartWidget(QWidget *parent) : QWidget(parent)
{
    //this->setAutoFillBackground(true);
    this->resize(1022, 755);
    //QPalette palette;
    //palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/background/back1.jpg")));
    //this->setPalette(palette);
}

void StartWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/background/back1.jpg");
    painter.drawPixmap(0, 0, pix);
}
