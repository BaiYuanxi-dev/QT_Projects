#ifndef GRAPH_H
#define GRAPH_H

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



    //获得最短路径
    void getshortestPath(int initIndex);
    int* getshortestPath(int initIndex, int endIndex, int &num);

    //获得最小生成树
    struct closedge* getMST(int initIndex);

    //返回顶点个数
    int getNumOfNode() { return numOfNodes; };
    //返回顶点数组
    struct HeadNode** getVerAndEdge() { return this->nodes; } ;




    //打印最短路径
    void showPathAndDist();
    //打印顶点
    void showVertex();
    //打印顶点和边
    void showAll();

    void showMatrix();


    //TODO
    int** DFS(int initIndex, int &nums);
    void DFSAlgo(int nVex, int &nIndex,int aPath[]);
    //TODO

private:
    //顶点
    struct HeadNode** nodes;
    //邻接矩阵
    int** matrix;
    //顶点个数
    int numOfNodes;
    int *path1;//存放最短路径的前驱节点
    //存放最短路径
    int *list1;
    double *dist;//存放的是最短路径的值
    bool *visited;//访问标志

    struct closedge* mst;//最小生成树


    int** paths;

    //TODO
    //所有路径的链表
    int numOfPath;

    int *aPath;

    int index0;

};
#endif // GRAPH_H
