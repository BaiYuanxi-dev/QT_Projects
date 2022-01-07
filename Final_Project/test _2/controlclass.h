#ifndef CONTROLCLASS_H
#define CONTROLCLASS_H

#include <QObject>


#include "entergamewindow.h"
#include "gamewidget.h"

#include <iostream>

using std::cout;
using std::endl;

/*
 * 控制类：控制界面交互
 * */
class ControlClass : public QObject
{
    Q_OBJECT
public:
    explicit ControlClass(QObject *parent = nullptr);

signals:

private:
    EnterGameWindow *w;//进入游戏中间界面
    GameWidget* gamewidget;
    //GameWindow* mainWindow;
    //QMainWindow* gameWindow;//游戏界面
    //GameWidget* gameWidget;


};

#endif // CONTROLCLASS_H
