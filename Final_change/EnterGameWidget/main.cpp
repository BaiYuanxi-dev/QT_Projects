#include "entergamewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString* str;//排名字符串数组，待输�
    str = new QString[8];
    for(int i = 0; i < 8; i ++){
        str[i] = "ZhaoHong 100000";
    }

    str[5] = " nimass l e    ";
    str[3] = "asdsad ascdxin";
    EnterGameWidget *w = new EnterGameWidget(str);
    w->show();
    return a.exec();
}
