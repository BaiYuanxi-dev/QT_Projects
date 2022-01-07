#ifndef GAMEONE_H
#define GAMEONE_H

#include "headers.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gameOne; }
QT_END_NAMESPACE

class gameOne : public QWidget{
    Q_OBJECT

public:
    gameOne(QWidget *parent = nullptr);
    ~gameOne();

private slots:
    void checkIfBack();
    void on_pauseBtn_clicked();
    bool eraseBoxes();
    void on_progressBtn_clicked();
    void on_pushButton_clicked();
    void on_endGameBtn_clicked();

private:
    Ui::gameOne *ui;
    QVector<QVector<MyButton *>> buttons;
    QVector<Node *> changePosVec;
    int flag = false;
    QTimer * timer;
    int x0 = 100, y0 = 160;
    int slowSpeed = 800, midSpeed = 500, fastSpeed = 300;
    int curSpeed;
    PauseWidget * pauseWidget;
    QMediaPlayer * myPlayer;
    int score;
    bool flush;
    bool endGameFlag = false;
    endGame * end;

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
