#include "msgdialog.h"
#include <sstream>
#include <QDebug>
MsgDialog::MsgDialog(QDialog *parent) : QDialog(parent)
{
    this->resize(598, 452);


    titleLabel = new QLabel();
    titleLabel->setFont(QFont("仿宋",13));
    titleLabel->move(250, 30);
    titleLabel->resize(90, 20);
    titleLabel->setParent(this);

    carIdLabel = new QLabel("车牌号:");
    carIdLabel->resize(100, 35);
    carIdLabel->move(50, 98);
    carIdLabel->setParent(this);

    time1Label = new QLabel("进入时间:");
    time1Label->resize(100, 35);
    time1Label->move(50, 172);
    time1Label->setParent(this);

    time2Label = new QLabel("停放时间:");
    time2Label->resize(100, 35);
    time2Label->move(50, 246);
    time2Label->setParent(this);

    moneyLabel= new QLabel("目前费用:");
    moneyLabel->resize(100, 35);
    moneyLabel->move(50, 320);
    moneyLabel->setParent(this);

    carIdLine = new QLineEdit;
    carIdLine->setReadOnly(true);
    carIdLine->resize(380,30);
    carIdLine->move(160, 100);
    carIdLine->setParent(this);
    carIdLine->setAlignment(Qt::AlignCenter);

    time1Line = new QLineEdit;
    time1Line->setReadOnly(true);
    time1Line->resize(380,30);
    time1Line->move(160, 175);
    time1Line->setParent(this);
    time1Line->setAlignment(Qt::AlignCenter);


    time2Line = new QLineEdit;
    time2Line->setReadOnly(true);
    time2Line->resize(380,30);
    time2Line->move(160, 250);
    time2Line->setParent(this);
    time2Line->setAlignment(Qt::AlignCenter);

    moneyLine = new QLineEdit;
    moneyLine->setReadOnly(true);
    moneyLine->resize(380,30);
    moneyLine->move(160, 320);
    moneyLine->setParent(this);
    moneyLine->setAlignment(Qt::AlignCenter);

    this->setVisible(false);


}


void MsgDialog::setTheDialog(Position* position, int no){
    if(position->getCar()->getId() == "#"){
        throw "without car";
    }
    string id = position->getCar()->getId();// 车牌
    int timeInInt = 0;
    time_t timeIn = position->getCar()->getTime();//车辆进入停车场时间
    timeInInt = timeIn;

    time_t timeNow;//当前时间
    time(&timeNow);
    double money = position->getCar()->getMoney();//截止到目前的费用

    //money转字符串
    string moneyStr = "";
    stringstream doubleTostr;
    doubleTostr << money;
    moneyStr = doubleTostr.str();

    struct tm* time1_info;

    time1_info = localtime(&timeIn);
    string time1String = asctime(time1_info);

    string subsTime;

    subsTime = this->getSubsTime(timeInInt, timeNow);

    doubleTostr.str("");
    doubleTostr << "No: " << no;
    string s = doubleTostr.str();

    //titleLabel->setText(QString::fromStdString(s));

    carIdLine->setText(QString::fromStdString(id));

    time1Line->setText(QString::fromStdString(time1String));

    time2Line->setText(QString::fromStdString(subsTime));

    //time2_info = localtime(&timeNow);

    moneyLine->setText(QString::fromStdString(moneyStr));



}

string MsgDialog::getSubsTime(int seconds1, int seconds2){
    string res = "";
    stringstream intToStr;
    int days;
    int hours;
    int minutes;
    int seconds;
    int subs = seconds2 - seconds1;
    days = subs / ( 60 * 60 * 24 );
    hours = subs % ( 60 * 60 * 24 ) / ( 60 * 60 );
    minutes = subs % ( 60 * 60) / 60;
    seconds = subs % 60;
    intToStr << days << " 天 " << hours << " 时 " << minutes << " 分 " << seconds << " 秒";
    res = intToStr.str();
    return res;

}
















