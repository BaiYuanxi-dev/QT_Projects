#include "mainwindow.h"
#include "ui_mainwindow.h"


//构造函数
//游戏开始界面显示
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    w = new MyGLWidget;
    w->resize(1200, 900);

    //this->setVisible(false);

    //首先显示的应该是登录界面
    //logWidget = new LogWidget;
    //logWidget->resize(600, 400);
    //QPushButton * b = new QPushButton("???");
    //b->setParent(logWidget);
    //logWidget->show();



    //emit logWidget->log();
    connect(logWidget, &LogWidget::log, this, [=](){
        //关闭当前界面并显示myglwidget,需要把该对象（指针）传入到下一个界面吗？不一定，因为不需要用到登录界面了。
        //需要把client对象作为参数传递吗？需要，但这里不写
        //是不是应该是这里做一个。。。的参数修改，然后在别的地方就可以调用函数生成myglwidget？
        //应该有一个游戏控制的类,（主界面？），控制所有的操作？
        w->move(0, 0);
        w->show();
        this->setVisible(false);
    });

    connect(w, &MyGLWidget::gameIn, this, [=](){
        startWidget = new StartWidget;
        //startWidget->resize(800, 600);
        startWidget->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

