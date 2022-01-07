#include "mainwindow.h"
#include "Queue.hpp"
#include "linkedlist.hpp"
#include "partinglot.h"
#include "position.h"
#include "car.h"
#include <QApplication>
#include <iostream>


#include<cstdlib>
#include<ctime>

#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


//    partingLot.showAll();
//    cout << "--------------------------"<<endl;
//    //Position *position;



//    partingLot.regist("666").regist("777").regist("3333").regist("486");
//    partingLot.enter();

//    partingLot.enter();
//    partingLot.enter();
//    partingLot.enter();

//    //cout << "1.time  " << partingLot.out(1) << endl;
//    //cout << "3.time  " << partingLot.out(3) << endl;

//    //position = partingLot.query(15);
//    //cout << position->getCar()->getMoney() <<endl;
//    partingLot.showAll();
