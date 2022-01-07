#include <QApplication>
#include "mainwindow.h"
#include "login.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    mainWindow mainwindow;
    mainwindow.show();
    return a.exec();
}
