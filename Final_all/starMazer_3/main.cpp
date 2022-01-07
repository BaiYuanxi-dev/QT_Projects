#include <QApplication>
#include "mainwindow.h"
#include "login.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    mainWindow * mainwindow = new mainWindow();
    mainwindow->show();
    a.exit(0);
    return a.exec();
}
