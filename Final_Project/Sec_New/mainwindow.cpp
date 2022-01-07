#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logWidget = new LogWidget;
    logWidget->show();

    glWidget = new MyGLWidget;
    glWidget->resize(1200, 900);

    connect(logWidget, &LogWidget::log, this, [=](){
        glWidget->move(200, 100);
        glWidget->show();
        logWidget->close();
    });


    connect(glWidget, &MyGLWidget::gameIn, this, [=](){
        startWidget = new StartWidget;
        startWidget->show();
    });

    //startWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

