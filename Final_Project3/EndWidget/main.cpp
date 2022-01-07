#include "endwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EndWidget w(0);
    w.show();
    return a.exec();
}
