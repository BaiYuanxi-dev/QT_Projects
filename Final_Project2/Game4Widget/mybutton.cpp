#include "mybutton.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QTime>
#include <QCoreApplication>
MyButton::MyButton(QWidget *parent, int x, int y, int icon, int symbol):QPushButton(parent){
    this->x = x;
    this->y = y;
    this->isErased = 0;
    this->icon = icon;
    this->symbol = symbol;
    if(symbol == 0){
        this->setIcon(QIcon(QString(":/game4/game4/box%0.png").arg(this->icon)));
    } else {
        this->setIcon(QIcon(QString(":/game4/game4/circle%0.png").arg(this->icon)));
    }

    this->setIconSize(QSize(64, 62));
    this->resize(64, 62);

    this->show();

}

void MyButton::sleep(unsigned int msec){
    QTime newTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < newTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MyButton::reset(){
    this->isErased = 0;

    QTimer* timer;
    timer = new QTimer;
    //TODO：渐变动画
    this->setAttribute(Qt::WA_TranslucentBackground, true);




    if(symbol == 0){
        this->icon = rand() % 5;
        this->setIcon(QIcon(QString(":/game4/game4/box%0.png").arg(this->icon)));
    } else {
        //如何渐变？

        opacity = 1.0;
        QGraphicsOpacityEffect *effect=new QGraphicsOpacityEffect;
        effect->setOpacity(opacity);
        connect(timer, &QTimer::timeout, this, [=](){
            if ( opacity <= 0.0 ) {
                timer->stop();//定时器停止
                disconnect(timer, 0, 0, 0);
                delete timer;
            }
            else{
                effect->setOpacity(opacity);
                this->setGraphicsEffect(effect);
            }
            opacity -= 0.2;//透明度累加
        });
        timer->start(100);

        sleep(100);

        this->icon = rand() % 5;
        this->setIcon(QIcon(QString(":/game4/game4/circle%1.png").arg(this->icon)));


        opacity = 0.0;
        effect=new QGraphicsOpacityEffect;
        effect->setOpacity(opacity);
        connect(timer, &QTimer::timeout, this, [=](){
            if ( opacity >= 1.0 ) {
                timer->stop();//定时器停止
                disconnect(timer, 0, 0, 0);
                delete timer;
            }
            else{
                effect->setOpacity(opacity);
                this->setGraphicsEffect(effect);
            }
            opacity += 0.2;//透明度累加
        });
        timer->start(100);

    }






}

