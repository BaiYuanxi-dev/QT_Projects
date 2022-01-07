#ifndef ENTERGAMEWIDGET_H
#define ENTERGAMEWIDGET_H

#include <QWidget>
#include <QString>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class EnterGameWidget; }
QT_END_NAMESPACE



/*
 * 点击某一关卡后，进入关卡前的界面（包括开始游戏和该关卡的排行榜）
 * */
class EnterGameWidget : public QWidget
{
    Q_OBJECT

public:
    /*
     * 构造函数
     * param: level 关卡数字, 用户排名信息（直接字符串）
     *        *rankStr 排名信息数组（在控制类中赋值最好）
     * */
    EnterGameWidget(int level, QString *rankStr, int rankLen, QWidget *parent = nullptr);
    ~EnterGameWidget();

private:
    Ui::EnterGameWidget *ui;

    int level;//表示关卡数字

    QString *rankStr;//存储排名信息字符串 的 数组

    int rankLen;// 排名信息字符串 数组的长度

    QPushButton* startButton;//点击按钮进入游戏
signals:
    void gameIn();//点击按钮，发送进入游戏信号
};
#endif // ENTERGAMEWIDGET_H
