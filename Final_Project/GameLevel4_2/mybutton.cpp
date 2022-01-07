#include "mybutton.h"


MyButton::MyButton(QWidget *parent, int x, int y, int icon):QPushButton(parent){
    this->x = x;
    this->y = y;
    this->isErased = 0;
    this->icon = icon;
    //TODO：修改路径
    this->setIcon(QIcon(QString("D:/Qt/Final_Project/GameLevel4/uiProject/box%1.png").arg(this->icon)));
    this->setIconSize(QSize(64, 62));
    this->resize(64, 62);
    this->show();
}

//重新设置图片
void MyButton::reset(){
    this->isErased = 0;
    this->icon = rand() % 5;
    this->setIcon(QIcon(QString("D:/Qt/Final_Project/GameLevel4/uiProject/box%1.png").arg(this->icon)));
}


