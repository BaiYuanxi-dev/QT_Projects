#include "mybutton.h"

MyButton::MyButton(QWidget *parent, int x, int y, int icon):QPushButton(parent){
    this->x = x;
    this->y = y;
    this->isErased = 0;
    this->icon = icon;
    this->setIcon(QIcon(QString("D:/Qt/Final_Project/Qt_Project/StarMaze/resource/gameImg/box%0.png").arg(this->icon)));
    this->setIconSize(QSize(64, 62));
    this->resize(64, 62);
    this->show();
}

void MyButton::reset(){
    this->isErased = 0;
    this->icon = rand() % 5;
    this->setIcon(QIcon(QString("D:/Qt/Final_Project/Qt_Project/StarMaze/resource/gameImg/box%0.png").arg(this->icon)));
}


