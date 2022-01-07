#ifndef MSGDIALOG_H
#define MSGDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include "position.h"

//信息查询对话框
class MsgDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MsgDialog(QDialog *parent = nullptr);
    //对话框设置显示
    void setTheDialog(Position* position, int no);
    //根据输入time_t显示时间差并返回字符串
    string getSubsTime(int seconds1, int seconds2);
private:
    QLabel* titleLabel;

    QLabel* carIdLabel;//车牌
    QLabel* time1Label;//进入时间
    QLabel* time2Label;//停车时长
    QLabel* moneyLabel;//当前费用

    QLineEdit* carIdLine;//车牌
    QLineEdit* time1Line;//进入时间
    QLineEdit* time2Line;//停车时长
    QLineEdit* moneyLine;//当前费用


signals:

};

#endif // MSGDIALOG_H
