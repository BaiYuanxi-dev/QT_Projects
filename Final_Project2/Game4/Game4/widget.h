#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mybutton4.h"

#include <QPushButton>
#include <random>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <QQueue>
#include <QPropertyAnimation>
#include <QTimer>
#include "pausewidget.h"
#include <QFileInfo>
#include <QtMultimedia>
#include <QtConcurrent>

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

class Widget : public QWidget{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pauseBtn_clicked();
    bool eraseBoxes();
    void on_progressBtn_clicked();

    void on_pushButton_clicked();

    void on_endGameBtn_clicked();

private:
    Ui::Widget *ui;
    QVector<QVector<MyButton4 *>> buttons;
    QVector<Node *> changePosVec;
    int flag = false;
    QTimer * timer;
    int x0 = 100, y0 = 160;
    int slowSpeed = 800, midSpeed = 500, fastSpeed = 300;
    int curSpeed;
    PauseWidget pauseWidget;
    QMediaPlayer * myPlayer;
    int score;
    bool flush;
    bool endGameFlag = false;

    int numOfCircle;

    void eraseMusic();
    void playMusic(QString s);
    void paintEvent(QPaintEvent *);
    void slotWhich2Change(MyButton *);
    bool checkIfCanBeChanged();
    bool checkCurGUI();
    void moveBtn(MyButton * btn, QPoint start, QPoint end, int duration);
    int restSteps;

};
#endif // WIDGET_H
