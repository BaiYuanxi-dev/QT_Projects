#include "entergamewidget.h"

#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString *rankStr;
    rankStr = new QString[10];
    for(int i = 0; i < 10; i ++){
        rankStr[i] = i + 1;
    }
    EnterGameWidget *ws = new EnterGameWidget(1, rankStr);

    ws->show();
    return a.exec();
}
