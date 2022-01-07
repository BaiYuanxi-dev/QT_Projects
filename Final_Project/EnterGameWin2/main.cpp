#include "entergamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EnterGameWindow w;
    w.show();
    return a.exec();
}
