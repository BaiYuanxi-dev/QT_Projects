#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "mybutton.h"
#include <QWidget>
#include <QPushButton>
#include <random>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <QQueue>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <qpropertyanimation.h>
using namespace std;

struct Node{
    int x, y;
    int icon;
    QPoint point;
    Node(int x, int y, int icon, QPoint point): x(x), y(y), icon(icon), point(point){};
};

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();
    void closeEvent(QCloseEvent *event);
signals:
    void backToMain();
private slots:

    bool eraseBoxes();

private:
    void paintEvent(QPaintEvent *);

    int x0 = 100, y0 = 130;

    QVector<QVector<MyButton *>> buttons;

    QVector<Node *> changePosVec;

    void slotChangePos();

    void slotWhich2Change(MyButton *);

    bool checkIfCanBeChanged();

    int flag = false;

    QTimer * timer;

    bool checkCurGUI();

    bool check(int x1, int y1, int x2, int y2);

};

#endif // GAMEWIDGET_H
