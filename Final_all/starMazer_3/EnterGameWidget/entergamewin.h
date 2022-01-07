#ifndef ENTERGAMEWIN_H
#define ENTERGAMEWIN_H

#include <QWidget>

namespace Ui {
class EnterGameWin;
}

//class EnterGameWin : public QWidget
//{
//    Q_OBJECT

//public:
//    explicit EnterGameWin(QWidget *parent = nullptr);
//    ~EnterGameWin();

//private:
//    Ui::EnterGameWin *ui;
//};

//#endif // ENTERGAMEWIN_H




#include <QWidget>
#include <QScrollArea>
#include "rankwidget.h"
#include <QPushButton>
#include "mypushbutton.h"

/**
 * @brief The EnterGameWidget class
 * 进入游戏前的中间界面，包括开始游戏按钮和每一关的排行榜
 */
class EnterGameWin : public QWidget{
    Q_OBJECT

public:
    /*param:
     *      level 关卡
     *      *rankStr 存储排名信息字符串 的 数组
     *      numOfRank 字符串数组长度
     **/
    explicit EnterGameWin(int level = 1, QString *rankStr = nullptr, int numOfRank = 8, QWidget *parent = nullptr);

    ~EnterGameWin();
    //重载关闭窗口方法
    void closeEvent(QCloseEvent *event);
    //重载绘制方法：画背景图片
    void paintEvent(QPaintEvent *event);
    int close = 0;
signals:
    void gameIn(); // 点击Start，进入游戏。
    void backToMain();//点击退出，回到游戏关卡选择界面（MainWindow）
private:
    Ui::EnterGameWin *ui;
    int numOfRank;//排名个数
    int level;//表示关卡数字
    QString * rankStr;//存储排名信息字符串 的 数组: 默认取前8？
    RankWidget* rankWid;// 排名窗口
    QScrollArea *scrollArea;//滚动条区域
    QWidget* enterGameWidget;//进入游戏子窗口
    MyPushButton* gameStartButton;//点击按钮发送开始游戏信号
};
#endif // ENTERGAMEWIDGET_H
