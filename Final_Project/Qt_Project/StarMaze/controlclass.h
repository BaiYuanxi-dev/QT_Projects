#ifndef CONTROLCLASS_H
#define CONTROLCLASS_H

#include <QObject>


#include "EnterGameWidget/entergamewidget.h"
#include "mainWindow/mainwindow.h"
#include "game1/widget.h"
#include <iostream>

using std::cout;
using std::endl;

/*
 * 控制类：控制界面交互
 * 在控制类中创建所有界面的对象，并实现界面间的交互与连接
 * */
class ControlClass : public QObject
{
    Q_OBJECT
public:
    explicit ControlClass(QObject *parent = nullptr);

signals:

private:
    EnterGameWidget *w;//进入游戏中间界面
    mianWindow* mainWin;
    Widget* game1;
    //GameWindow* mainWindow;
    //QMainWindow* gameWindow;//游戏界面
    //GameWidget* gameWidget;


};

#endif // CONTROLCLASS_H
