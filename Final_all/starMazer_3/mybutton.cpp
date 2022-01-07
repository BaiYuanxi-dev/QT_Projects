#include "mybutton.h"

#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>


MyButton::MyButton(QWidget *parent, int x, int y, int icon):QPushButton(parent){
    this->x = x;
    this->y = y;
    this->isErased = 0;
    this->icon = icon;
    this->setIcon(QIcon(QString("E://uiProject//box%1.png").arg(this->icon)));
    this->setIconSize(QSize(64, 62));
    this->resize(64, 62);
    this->show();
}

void MyButton::reset(int flag, int icon, int isCircle){
    this->isErased = 0;
    if(flag == 0){
        this->icon = rand() % 5;
        if(icon == -1)
            this->setIcon(QIcon(QString("E://uiProject//box%1.png").arg(this->icon)));
        else{
            this->icon = icon;
            this->setIcon(QIcon(QString("E://uiProject//box%1.png").arg(icon)));
        }
    }else if(flag == 1){
        QGraphicsOpacityEffect * opa = new QGraphicsOpacityEffect(this);
        opa->setOpacity(1);
        this->setGraphicsEffect(opa);
        QPropertyAnimation * pro = new QPropertyAnimation(opa, "opacity", this);
        pro->setStartValue(1);
        pro->setEndValue(0);
        pro->setDuration(500);
        pro->start();
        delete opa;
        delete pro;
        this->icon = rand() % 5;
        this->setIcon(QIcon(QString("E://uiProject//box%1.png").arg(this->icon)));
        if(isCircle)
            this->setIcon(QIcon(QString("E://uiProject//circle%1.png").arg(this->icon)));
        opa = new QGraphicsOpacityEffect(this);
        opa->setOpacity(0);
        this->setGraphicsEffect(opa);
        pro = new QPropertyAnimation(opa, "opacity", this);
        pro->setStartValue(0);
        pro->setEndValue(1);
        pro->setDuration(500);
        pro->start();
    }
}

void MyButton::setThisOpacity(){
    QGraphicsOpacityEffect *m_pOpacityEffect = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(m_pOpacityEffect);
    if( isIce == 1 )
        m_pOpacityEffect->setOpacity(0.7);
    else
        m_pOpacityEffect->setOpacity(1);
}


