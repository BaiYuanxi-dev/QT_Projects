#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //this->level = level;
    //this->rankStr = rankStr;
}

MainWindow::~MainWindow()
{

}


void MainWindow::closeEvent(QCloseEvent *event){
    emit this->backToMain();
}


//设置界面相关函数
void MainWindow::setWidget(){

}
