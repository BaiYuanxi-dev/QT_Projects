#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "helpform.h"
#include "info.h"
#include "achive.h"

#include "gameOne.h"
#include "gameTwo.h"
#include "gameThree.h"
#include "gameFour.h"

namespace Ui {class mainWindow;}

class mainWindow : public QWidget{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:

    void on_classTwo_clicked();

    void on_classThree_clicked();

    void on_classFour_clicked();

private:
    Ui::mainWindow *ui;
    helpForm helpFo;
    info info;
    achive achive;
    void deal_classOne_Button();//自定义切换到子窗口槽函数
    void deal_help_Button();
    void deal_info_Button();
    void deal_achive_Button();
};

#endif // MAINWINDOW_H
