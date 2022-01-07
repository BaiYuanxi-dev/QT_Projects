#include "entergamewindow.h"

#include <QApplication>
#include "listitemwidget.h"
#include "rankwidget.h"
#include "controlclass.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlClass* controlClass = new ControlClass;
    return a.exec();
}
