#include "entergamewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EnterGameWidget w;
    w.show();
    return a.exec();
}
