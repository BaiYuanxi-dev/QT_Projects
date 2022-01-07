#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>

/**
 * @brief The MyPushButton class
 * 开始按钮封装
 */
class MyPushButton : public QPushButton{
    Q_OBJECT
public:
    MyPushButton(QString normalImg, QString pressImg = "", QWidget *parent = nullptr);
    ~MyPushButton();
    void zoom1();
signals:
private:
    QString normalImgPath;//正常状态下按钮图片路径
    QString pressImgPath;//按下按钮后显示的图片的路径
};

#endif // MYPUSHBUTTON_H
