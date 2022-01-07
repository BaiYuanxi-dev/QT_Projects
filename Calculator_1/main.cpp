#include "calculatorwin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorWin w;
    w.show();
    return a.exec();
}
