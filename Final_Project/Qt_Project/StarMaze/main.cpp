#include <QApplication>
#include "game1/widget.h"
#include "Login/login.h"
#include "mainWindow/mainwindow.h"
#include "controlclass.h"
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    ControlClass* con = new ControlClass;
    //con->show();

    return a.exec();
}
