#include "game4widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game4Widget w;
    w.show();
    return a.exec();
}
