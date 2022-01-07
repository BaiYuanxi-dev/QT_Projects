#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "helpform.h"
#include "game1/widget.h"

namespace Ui {class mainWindow;}

class mianWindow : public QWidget
{
    Q_OBJECT

public:
    mianWindow(QWidget *parent = nullptr);
    ~mianWindow();

//public slots:
signals:
    void enterGameWid();
private:
    Ui::mainWindow *ui;
    helpForm helpFo;
    void deal_classOne_Button();//自定义切换到子窗口槽函数
    void deal_help_Button();
};

#endif // MAINWINDOW_H
