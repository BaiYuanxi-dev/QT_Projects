#ifndef GAME4WIDGET_H
#define GAME4WIDGET_H


#include <QWidget>
#include "mybutton.h"

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
#include <QPainter>
//#include <QtMultimedia>
//#include <QtConcurrent>

using namespace std;

struct Node{
    int x, y;
    int icon;
    QPoint point;
    Node(int x, int y, int icon, QPoint point): x(x), y(y), icon(icon), point(point){};
};


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Game4Widget : public QWidget{
    Q_OBJECT

public:
    Game4Widget(QWidget *parent = nullptr);
    ~Game4Widget();

private slots:
    //void on_pauseBtn_clicked();
    bool eraseBoxes();
private:
    QVector<QVector<MyButton *>> buttons;
    QVector<Node *> changePosVec;
    int flag = false;
    QTimer * timer;
    int x0 = 100, y0 = 130;
    int slowSpeed = 800, midSpeed = 500, fastSpeed = 300;
    int curSpeed;
    //PauseWidget pauseWidget;
    //QMediaPlayer * myPlayer;
    int score;

    int numOfCircle;



    void initial();

    void eraseMusic();
    //void playMusic(QString s);
    void paintEvent(QPaintEvent *);
    void slotWhich2Change(MyButton *);
    bool checkIfCanBeChanged();
    bool checkCurGUI();
    void moveBtn(MyButton * btn, QPoint start, QPoint end, int duration);
};
#endif // WIDGET_H
