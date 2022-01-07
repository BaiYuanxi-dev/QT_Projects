#include "Queue.hpp"
#include "linkedlist.hpp"
#include "partinglot.h"
#include "position.h"
#include "car.h"
#include "mainwindow.h"
#include <iostream>


#include<cstdlib>
#include<ctime>

#include <fstream>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
