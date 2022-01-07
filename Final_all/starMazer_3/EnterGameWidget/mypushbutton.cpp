#include "mypushbutton.h"

#include <QTimer>

MyPushButton::MyPushButton(QString normalImg, QString pressImg, QWidget *parent){
    this->setParent(parent);
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pixmap;
    pixmap.load(normalImg);

    //TODO加载失败判定
    this->setFixedSize( pixmap.width(), pixmap.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pixmap);
    this->setIconSize(pixmap.size());
}

MyPushButton::~MyPushButton(){
    this->pressImgPath.~QString();
    this->normalImgPath.~QString();
    delete this;
}

//向下跳
void MyPushButton::zoom1(){
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");//初始化动画类，“geometry” 表示在矩形框内
    animation1->setDuration(400);//设置时间间隔
    animation1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation1->setKeyValueAt(0.5, QRect(this->x(), this->y() + 23, this->width(), this->height()));
    animation1->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();

}

