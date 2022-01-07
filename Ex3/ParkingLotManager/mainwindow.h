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
    //绘制
    void paintEvent(QPaintEvent*);
    //车辆进入动画
    void carMoveIn(int spaceId, QLabel* label);
    //车辆驶出动画
    void carMoveOut(int spaceId, QLabel* label);
    //初始化车位
    void InitSpace();
    void sleep(unsigned int msec);
    //设置字体等格式
    void setStyles();

private slots:
    //void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    //停车场对象
    PartingLot *partingLot;
    //车位辅助变量
    Position* position;
    //车位编号
    int no;
    //查询的对话框
    MsgDialog* dialog;
    //随机数
    int noIn;
    QTimer* timer;


    QLabel** labels;

    int *empNo;
    const int xCord[16] = {295, 380, 468, 563, 658, 760, 295, 380, 468, 563, 658, 760, 343, 460, 574, 690};
    const int yCord[16] = {81, 81, 81, 81, 81, 81,  193, 193, 193, 193, 193, 193, 354, 354, 354, 354};
    string operate;
};
#endif // MAINWINDOW_H
