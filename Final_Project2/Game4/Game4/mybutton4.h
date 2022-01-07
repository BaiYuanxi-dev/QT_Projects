#ifndef MYBUTTON4_H
#define MYBUTTON4_H

#include <QWidget>
#include "mybutton.h"
class MyButton4 : public MyButton
{
    Q_OBJECT
public:
    explicit MyButton4(QWidget *parent, int x, int y, int icon);
    int flag;
    int isIce;
    void setFlag(int flag) { this->flag = flag; };
    void setIce(int isIce) { this->isIce = isIce; };
signals:

};

#endif // MYBUTTON4_H
