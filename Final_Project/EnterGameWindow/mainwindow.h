#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

/*
 * 点击某一关卡后，进入关卡前的界面（包括开始游戏和该关卡的排行榜）
 * */
class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    /*
     * 构造函数
     * param: level 关卡数字, 用户排名信息（直接字符串）
     *        *rankStr 排名信息数组（在控制类中赋值最好）
     * */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);//覆盖 closeEvent方法：点击退出后发送backToMain信号

signals:
    void backToMain();//点击退出，回到游戏关卡选择界面（MainWindow）

private:

    const int numOfRank = 8;//排名个数

    int level;//表示关卡数字

    QString *rankStr;//存储排名信息字符串 的 数组: 默认取前5？

    void setWidget();//设置界面相关函数

    QWidget* startQWidget;
    QWidget* rankQWidget;
};
#endif // MAINWINDOW_H
