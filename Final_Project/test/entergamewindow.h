#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include "rankwidget.h"
#include <QPushButton>
#include "mypushbutton.h"

class EnterGameWindow : public QWidget
{
    Q_OBJECT

public:
    /*
     * 构造函数
     * param:
     *      level 关卡
     *      *rankStr 存储排名信息字符串 的 数组
     *      numOfRank 字符串数组长度
     * */
    EnterGameWindow(int level = 1, QString *rankStr = nullptr, int numOfRank = 8, QWidget *parent = nullptr);

    ~EnterGameWindow();

    //重载关闭窗口方法
    void closeEvent(QCloseEvent *event);

    //重载绘制方法：画背景图片
    void paintEvent(QPaintEvent *event);
signals:
    void gameIn(); // 点击Start，进入游戏。
    void backToMain();//点击退出，回到游戏关卡选择界面（MainWindow）
private:

    int numOfRank;//排名个数

    int level;//表示关卡数字

    QString *rankStr;//存储排名信息字符串 的 数组: 默认取前8？

    RankWidget* rankWid;// 排名窗口

    QScrollArea *scrollArea;//滚动条区域

    QWidget* enterGameWidget;//进入游戏子窗口

    MyPushButton* gameStartButton;//点击按钮发送开始游戏信号

    void setRankWidget();//设置排名窗口

    void setEnterWidget();//设置进入游戏子窗口

    void sleep(unsigned int msec);//暂停程序进程
};
#endif // MAINWINDOW_H
