#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

/**
 * @brief The MyLabel class
 * 冰块Label
 */
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    int x; //label在数组中的横坐标
    int y; //label在数组中的纵坐标
    int flag;
    int iceNum;
    MyLabel(QWidget *parent, int x, int y, int flag); //构造函数
    void reset(int flag);
    void setFlag(int flag){ this->flag = flag; };
signals:

};

#endif // MYLABEL_H
