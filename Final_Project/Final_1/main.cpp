//#include "mainwindow.h"

#include <QApplication>
#include "EnterGameWidget/entergamewin.h"
#include "EnterGameWidget/newtry.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QString* str;//排名字符串数组，待输�
    str = new QString[8];
    for(int i = 0; i < 8; i ++){
        str[i] = " ZhaoHong  100000";
    }

    str[5] = " nimass l e    ";
    str[3] = "asdsad ascdxin";
    EnterGameWin *w = new EnterGameWin(1, str, 8);
    w->show();

//    NewTry w;
//    w.show();
    return a.exec();
}
