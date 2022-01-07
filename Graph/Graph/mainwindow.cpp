#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "linkedlist.hpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //图的创建

    graph = new Graph("graph.db");

    graph->showVertex();

    graph->initGraph("graph.db");

    graph->showAll();
    //graph->showMatrix();
//    LinkedList<int> * list;
//    list = graph->getshortestPath(6, 2);
//    cout <<">>"<<endl;
//    //graph->showPathAndDist();

//    cout <<"--------------------------------------"<<endl;
//    struct closedge* mst =  graph->getMST(1);

    graph->DFS(0);
    cout << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}



