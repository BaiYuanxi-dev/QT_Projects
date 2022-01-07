#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int level = 1;
    QString *rankStr;
    for(int i = 0; i < 8; i ++){
        rankStr[i] = "123";
    }
    MainWindow w;
    w.show();
    return a.exec();
}
