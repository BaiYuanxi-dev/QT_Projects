#include "mybutton.h"
#include <iostream>
MyButton::MyButton(QPushButton *parent) : QPushButton(parent)
{
    isEnter = false;
}


void MyButton::setThisButton(int x, int y, string name){
    this->move(x, y);
    this->setText(QString::fromStdString(name));
    this->resize(60, 30);
    this->setFont(QFont("楷体", -1, 4));
    this->setStyleSheet("QPushButton{background-color: rgba(18, 62, 111, 255);color:rgb(230, 230, 230);}");
}
