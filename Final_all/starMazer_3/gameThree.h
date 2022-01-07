#ifndef GAMETHREE_H
#define GAMETHREE_H

#include "headers.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gameThree; }
QT_END_NAMESPACE

class gameThree : public QWidget{
    Q_OBJECT

public:
    gameThree(QWidget *parent = nullptr);
    ~gameThree();

    void closeEvent(QCloseEvent *);
private slots:
    void checkIfBack();
    void on_pauseBtn_clicked();
    bool eraseBoxes();
    void on_progressBtn_clicked();

    void on_pushButton_clicked();

    void on_endGameBtn_clicked();

private:
    Ui::gameThree *ui;
    QVector<QVector<MyButton *>> buttons;
    QVector<Node *> changePosVec;
    int flag = false;
    QTimer * timer;
    QTimer * timetEnd;
    endGame * end;
    int x0 = 100, y0 = 160;
    int slowSpeed = 800, midSpeed = 500, fastSpeed = 300;
    int curSpeed;
    int gameSize = 10;
    PauseWidget * pauseWidget;
    QMediaPlayer * myPlayer;
    int score;
    bool flush;
    bool endGameFlag = false;

    bool magicFlag = false;
    bool magicFlag1 = false;
    bool magicFlag2 = false;
    bool magicFlag3 = false;

    bool energyFlag = true;
    bool energyFlag1 = true;
    bool energyFlag2 = true;
    bool energyFlag3 = true;

    int eggPosx = 2;
    int eggPosy = 2;

    int eggPos1x = 7;
    int eggPos1y = 7;

    int eggPos2x = 2;
    int eggPos2y = 7;

    int eggPos3x = 7;
    int eggPos3y = 2;

    void eraseMusic();
    void playMusic(QString s);
    void paintEvent(QPaintEvent *);
    void slotWhich2Change(MyButton *);
    bool checkIfCanBeChanged();
    bool checkCurGUI();
    void moveBtn(MyButton * btn, QPoint start, QPoint end, int duration);
    int restSteps;
    int dickNum;
    void doMagic();
};
#endif // WIDGET_H
