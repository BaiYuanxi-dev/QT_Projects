#include "widget.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

//    std::cout << "wahvpasv" <<std::endl;
    return a.exec();
}
