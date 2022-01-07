//#include "mainwindow.h"

#include <QApplication>
#include "controlclass.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    ControlClass* control = new ControlClass;
    return a.exec();
}
