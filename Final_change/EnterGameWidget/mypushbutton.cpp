#include "mypushbutton.h"

MyPushButton::MyPushButton(QString normalImg, QString pressImg, QWidget *parent)
{
    this->setParent(parent);
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pixmap;
    pixmap.load(normalImg);

    //TODO加载失败判定


    this->setFixedSize( pixmap.width(), pixmap.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pixmap);
    //this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    this->setIconSize(pixmap.size());
}

//向下跳
void MyPushButton::zoom1(){
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");//初始化动画类，“geometry” 表示在矩形框内

    animation1->setDuration(200);//设置时间间隔

    animation1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));

    animation1->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    animation1->setEasingCurve(QEasingCurve::OutBounce);

    animation1->start();

    //delete  animation1;
}

void MyPushButton::zoom2(){
    QPropertyAnimation *animation2 = new QPropertyAnimation(this, "geometry");//初始化动画类，“geometry” 表示在矩形框内

    animation2->setDuration(200);//设置时间间隔

    animation2->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    animation2->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    animation2->setEasingCurve(QEasingCurve::OutBounce);

    animation2->start();

    //delete  animation2;
}
