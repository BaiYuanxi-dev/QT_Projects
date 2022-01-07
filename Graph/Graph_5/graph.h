#ifndef GRAPH_H
#define GRAPH_H

#include "linkedlist.hpp"
#include <string>
using namespace std;



struct closedge
{    int  adjvex;  //图中的一个点的下标
     double lowcost;  //边的权
};

//邻接表节点
struct ArcCell {
    int index;//图顶点所在下标
    double weight;//权重
    struct ArcCell* next;
    ArcCell(int index, double weight, struct ArcCell* next) {
        this->index = index;
        this->weight = weight;
        this->next = next;
    }
};

//图顶点
struct HeadNode {
    int x_cod;//横坐标
    int y_cod;//纵坐标
    string name;//景点名
    int price;//票价
    ArcCell* firstArc;//邻接表，链表
    HeadNode() {
        this->name = "";
        this->price = 0;
        this->x_cod = -1;
        this->y_cod = -1;
        this->firstArc = nullptr;
    }
    HeadNode(int x_cod, int y_cod, string name, int price, ArcCell* firstArc) {
        this->x_cod = x_cod;
        this->y_cod = y_cod;
        this->name = name;
        this->price = price;
        this->firstArc = firstArc;
    }
};

//图
class Graph {
public:
    Graph();
    Graph(const char* fileName);
    ~Graph();

    //加入边
    void initGraph(const char* fileName);
    Graph* addArc(int vertex1, int vertex2, double weight);

    //TODO
    void DFS(int initIndex);
    void DFSAlgo(int nVex, int &nIndex);
    //获得最短路径
    void getshortestPath(int initIndex);
    LinkedList<int>* getshortestPath(int initIndex, int endIndex);
    struct closedge* getMST(int initIndex);
    int getNumOfNode();
    void showPathAndDist();
    void showVertex();
    void showAll();

    void showMatrix();
private:
    struct HeadNode** nodes;
    int** matrix;
    int numOfNodes;
    int *path1;//存放最短路径的前驱节点
    LinkedList<int> *list1;
    double *dist;//存放的是最短路径的值
    bool *visited;//访问标志

    struct closedge* mst;//最小生成树


    //所有路径的链表
    LinkedList<int> *list2;
    int numOfPath;

    int *aPath;
};
#endif // GRAPH_H
