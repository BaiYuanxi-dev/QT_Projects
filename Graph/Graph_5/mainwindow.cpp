#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "linkedlist.hpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //图的创建


}

MainWindow::~MainWindow()
{
    delete ui;
}



