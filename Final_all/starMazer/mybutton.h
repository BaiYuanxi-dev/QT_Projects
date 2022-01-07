#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <qpushbutton.h>
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
    int flag;
    int isIce;
    int isBean = 0;
    MyButton(QWidget *parent, int x, int y, int icon); //构造函数
    void reset(int flag, int icon = -1, int isCircle = 0);
    void setThisOpacity();
    void setIce(int isIce){this->isIce = isIce;};
};

#endif // MYBUTTON_H
