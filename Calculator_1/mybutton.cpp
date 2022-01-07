#include "mybutton.h"

MyButton::MyButton(QPushButton *parent) : QPushButton(parent)
{
    connect(this, &MyButton:: clicked, this, &MyButton:: sendButtonText);
}


//set the position, size and text of button
QPushButton& MyButton::setThisButton(QWidget* parent, int x, int y, int width, int height, const char* text){
    this->setParent(parent);
    this->move(x, y);
    this->resize(width, height);
    this->setText(text);
    this->setFont(QFont("宋体", 24));
    return *this;
}


//function to response "click button"
void MyButton::sendButtonText(){
    emit isClickedButton(this->text().toStdString());
}
