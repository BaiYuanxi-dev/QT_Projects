#include "mainwindow.h"

#include <QApplication>
#include "linkedlist.hpp"



int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    Graph* graph;
    graph = new Graph("graph.db");

    graph->showVertex();

    graph->initGraph("graph.db");

    graph->showAll();
    graph->showMatrix();
    LinkedList<int> * list;
    list = graph->getshortestPath(6, 2);
    cout <<">>"<<endl;
    //graph->showPathAndDist();

    cout <<"--------------------------------------"<<endl;
    struct closedge* mst =  graph->getMST(1);
    //graph->DFS(0);
    cout << "true out " <<endl;
    delete graph;
    return 0;
}
