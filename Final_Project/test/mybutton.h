#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>



class MyButton: public QPushButton{
public:
    int x;
    int y;
    int icon;
    MyButton(QWidget *parent, int x, int y, int icon);
};

#endif // MYBUTTON_H
