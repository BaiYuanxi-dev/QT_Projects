#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "game.h"

/*
 * 游戏主界面
 * */
class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    //重载closeEvent函数，关闭窗口时返回到关卡选择界面
    void closeEvent(QCloseEvent *event);
signals:
    void backToMain();//点击关闭回到关卡选择界面
private:
    Game *game;
};

#endif // GAMEWIDGET_H
