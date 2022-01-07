#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "partinglot.h"
#include "msgdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    void carMoveIn(int spaceId, QLabel* label);
    void carMoveOut(int spaceId, QLabel* label);
    void InitSpace();
    void sleep(unsigned int msec);
    void setStyles();

private slots:
    //void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    PartingLot *partingLot;
    Position* position;
    int no;
    MsgDialog* dialog;
    int noIn;
    QTimer* timer;

    QLabel* label1;

    QLabel** labels;

    int *empNo;
    const int xCord[16] = {295, 380, 468, 563, 658, 760, 295, 380, 468, 563, 658, 760, 343, 460, 574, 690};
    const int yCord[16] = {81, 81, 81, 81, 81, 81,  193, 193, 193, 193, 193, 193, 354, 354, 354, 354};
    string operate;
};
#endif // MAINWINDOW_H
