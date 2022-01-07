
#include <QApplication>
#include "gamewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWidget *w = new GameWidget(1);
    w->show();
    return a.exec();
}
