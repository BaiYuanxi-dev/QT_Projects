#ifndef WIDGET_H
#define WIDGET_H

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
    void closeEvent(QCloseEvent *event);
signals:
    void backToMain();
private slots:
    void on_pauseBtn_clicked();
    bool eraseBoxes();
private:
    Ui::Widget *ui;
    QVector<QVector<MyButton *>> buttons;
    QVector<Node *> changePosVec;
    int flag = false;
    QTimer * timer;
    int x0 = 100, y0 = 130;
    int slowSpeed = 800, midSpeed = 500, fastSpeed = 300;
    int curSpeed;
    PauseWidget pauseWidget;
    QMediaPlayer * myPlayer;
    int score;


    void eraseMusic();
    void playMusic(QString s);
    void paintEvent(QPaintEvent *);
    void slotWhich2Change(MyButton *);
    bool checkIfCanBeChanged();
    bool checkCurGUI();
    void moveBtn(MyButton * btn, QPoint start, QPoint end, int duration);
};
#endif // WIDGET_H
