#include "mylabel.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

/**
 * @brief MyLabel::MyLabel 构造函数
 * @param parent 父窗口
 * @param x 横坐标（对应button）
 * @param y 纵坐标（对应button）
 * @param flag 显示标志
 */
MyLabel::MyLabel(QWidget *parent, int x, int y, int flag) : QLabel(parent)
{
    this->x = x;
    this->y = y;
    this->flag = flag;
    this->iceNum = 2;
//    if(flag == 0){
//        this->iceNum = 0;
//    }
    this->resize(68, 64);
    QPixmap pixmap("D:/Qt/Final_Project2/Game4_3/uiProject/ice2.png");
    pixmap = pixmap.scaled(this->width(), this->height());
    this->setPixmap(pixmap);

    if(flag == 1){
        this->show();
    }else{
        this->iceNum = 0;
        this->setVisible(false);
    }


}

/**
 * @brief MyLabel::reset 重新绘制
 * @param iceNum 冰块编号
 */
void MyLabel::reset(int iceNum){
    if(flag == 0){
        this->setVisible(false);
    }

    this->setAttribute(Qt::WA_TranslucentBackground, true);
    if(iceNum <= 0){
        this->setVisible(false);
    } else if (iceNum == 1){
        QGraphicsOpacityEffect * opa = new QGraphicsOpacityEffect(this);
        opa->setOpacity(1);
        this->setGraphicsEffect(opa);
        QPropertyAnimation * pro = new QPropertyAnimation(opa, "opacity", this);
        pro->setStartValue(1);
        pro->setEndValue(0);
        pro->setDuration(200);
        pro->start();

        delete opa;
        delete pro;
        QPixmap pixmap("D:/Qt/Final_Project2/Game4_3/uiProject/ice3.png");
        pixmap = pixmap.scaled(this->width(), this->height());
        this->setPixmap(pixmap);

        opa = new QGraphicsOpacityEffect(this);
        opa->setOpacity(0);
        this->setGraphicsEffect(opa);
        pro = new QPropertyAnimation(opa, "opacity", this);
        pro->setStartValue(0);
        pro->setEndValue(1);
        pro->setDuration(200);
        pro->start();
    }
}
