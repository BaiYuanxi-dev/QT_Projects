#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>

/*
 * 开始按钮封装
 * */
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QObject *parent = nullptr);

    /*
     * 构造函数
     *
     * */
    MyPushButton(QString normalImg, QString pressImg = "", QWidget *parent = nullptr);
    void zoom1();
    void zoom2();
signals:

private:
    QString normalImgPath;//正常状态下按钮图片路径
    QString pressImgPath;//按下按钮后显示的图片的路径

};

#endif // MYPUSHBUTTON_H
