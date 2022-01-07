//#ifndef GAMEWIDGET_H
//#define GAMEWIDGET_H

//#include <QWidget>

//class GameWidget : public QWidget
//{
//    Q_OBJECT
//public:
//    explicit GameWidget(QWidget *parent = nullptr);

//signals:

//};

//#endif // GAMEWIDGET_H

////#ifndef GAMEWIDGET_H
////#define GAMEWIDGET_H

////#include <QWidget>

////class GameWidget : public QWidget
////{
////    Q_OBJECT
////public:
////    explicit GameWidget(QWidget *parent = nullptr);

////signals:

////};

////#endif // GAMEWIDGET_H
#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "mybutton.h"

#include <QMainWindow>
#include <QPushButton>
#include <random>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <QQueue>
#include <QPropertyAnimation>
#include <QTimer>
//#include "pausewidget.h"
#include <QFileInfo>
//#include <QtMultimedia>
//#include <QtConcurrent>

using namespace std;

struct Node{
    int x, y;
    int icon;
    QPoint point;
    Node(int x, int y, int icon, QPoint point): x(x), y(y), icon(icon), point(point){};
};

class GameWidget : public QWidget{ Q_OBJECT
public:
    GameWidget(int level, QWidget *parent = nullptr);
    ~GameWidget();

protected slots:
    bool eraseBoxes();
    //void on_pauseBtn_clicked();

protected:
    int level;//关卡
    int row;
    int col;
    int x0, y0;//初始按钮坐标

    const int slowSpeed = 800, midSpeed = 500, fastSpeed = 300;//按钮动画速度常量
    int score;//分数
    QVector<QVector<MyButton *>> buttons;
    QVector<Node *> changePosVec;//数组长度为2，存储要进行交换的按钮对应Node
    int flag = false;//flag是啥
    QTimer * timer;//定时器
    int curSpeed;//当前速度
    //PauseWidget pauseWidget;//自定义暂停界面？是不是Dialog更好
    //QMediaPlayer * myPlayer;//音乐播放




    //void eraseMusic();//???

    //void playMusic(QString s, bool autoPlay = false);//播放音乐？

    virtual void initial();
    void paintEvent(QPaintEvent *);//重绘？为每一个方块绘制背景
    void slotWhich2Change(MyButton *);//判断两个按钮是否可以交换
    virtual bool checkIfCanBeChanged();//在相邻的情况下检查两个button是否可以交换

    //检查当前界面是否有可以消去的, 如果有，将所有的icon替换为-1
    virtual bool checkCurGUI();

    //将Btn从start移动到end
    void moveBtn(MyButton * btn, QPoint start, QPoint end, int duration);
private:








};
#endif // MAINWINDOW_H
