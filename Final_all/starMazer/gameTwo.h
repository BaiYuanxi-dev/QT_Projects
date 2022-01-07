#ifndef GAMETWO_H
#define GAMETWO_H

#include "headers.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gameTwo; }
QT_END_NAMESPACE

class gameTwo : public QWidget{
    Q_OBJECT

public:
    gameTwo(QWidget *parent = nullptr);
    ~gameTwo();

private slots:
    void checkIfBack();
    void on_pauseBtn_clicked();
    bool eraseBoxes();
    void on_progressBtn_clicked();
    void on_pushButton_clicked();
    void on_endGameBtn_clicked();

private:
    Ui::gameTwo *ui;
    QVector<QVector<MyButton *>> buttons;
    QVector<Node *> changePosVec;
    int flag = false;
    QTimer * timer;
    endGame * end;
    int x0 = 100, y0 = 160;
    int slowSpeed = 800, midSpeed = 500, fastSpeed = 300;
    int curSpeed;
    PauseWidget * pauseWidget;

    int score;
    bool flush;
    bool endGameFlag = false;


    void eraseMusic();
    void playMusic(QString s);
    void paintEvent(QPaintEvent *);
    void slotWhich2Change(MyButton *);
    bool checkIfCanBeChanged();
    bool checkCurGUI();
    void moveBtn(MyButton * btn, QPoint start, QPoint end, int duration);
    bool judgeBean(int i,int j,int *store1,int *store2);

    int restSteps;
    int stepLeft;
    int beans;
};


#endif // WIDGET_H
