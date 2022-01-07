#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QTimer>
/**
 * @brief The MyButton class: 继承QPushButton
 *
 */
class MyButton: public QPushButton{
public:
    int x; //button在数组中的横坐标
    int y; //button在数组中的纵坐标
    int icon; //icon的序号
    int isErased;
    int symbol;//圆形和非圆形的区别
    MyButton(QWidget *parent, int x, int y, int icon, int symbol); //构造函数
    void reset();
    float opacity;

    void sleep(unsigned int msec);
};

#endif // MYBUTTON_H
