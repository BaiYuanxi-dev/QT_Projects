#ifndef GAMEFOUR_H
#define GAMEFOUR_H

#include "headers.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gameFour; }
QT_END_NAMESPACE

class gameFour : public QWidget{
    Q_OBJECT

public:
    gameFour(QWidget *parent = nullptr);
    ~gameFour();

    void closeEvent(QCloseEvent *);
private slots:
    void checkIfBack();
    void on_pauseBtn_clicked();
    bool eraseBoxes();
    void on_progressBtn_clicked();

    void on_pushButton_clicked();

    void on_endGameBtn_clicked();

private:
    Ui::gameFour *ui;
    QVector<QVector<MyButton *>> buttons;

    QVector<QVector<MyLabel *>> labels;
    QVector<Node *> changePosVec;
    int flag = false;
    QTimer * timer;
    QTimer * timetEnd;
    int x0 = 100, y0 = 160;
    int slowSpeed = 800, midSpeed = 500, fastSpeed = 300;
    int curSpeed;
    endGame * end;
    PauseWidget * pauseWidget;
    QMediaPlayer * myPlayer;
    int score;
    bool flush;
    bool endGameFlag = false;

    int numOfCircle;
    int numOfIce;

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
