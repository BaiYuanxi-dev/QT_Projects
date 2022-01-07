#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>

#include "gameOne.h"

namespace Ui {class MainUI;}

class MainUI : public QWidget{
    Q_OBJECT

public:
    MainUI(QWidget *parent = nullptr);
    ~MainUI();

private slots:

private:
    Ui::MainUI *ui;
//    helpForm helpFo;
    void deal_classOne_Button();//自定义切换到子窗口槽函数
    void deal_help_Button();
};

#endif // MAINWINDOW_H
