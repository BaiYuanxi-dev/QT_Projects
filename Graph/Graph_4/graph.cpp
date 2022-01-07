#include"graph.h"
#include<fstream>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <cmath>
Graph::Graph() {

}
Graph::Graph(const char* fileName) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1"); //设置数据库主机名
    db.setDatabaseName(fileName); //设置数据库名
    db.setUserName("root"); //设置数据库登入用户名
    db.setPassword("qq130727"); //设计数据库登入密码

    if (!db.open())
    {
        throw "failed opening the database";
    }

    QSqlQuery query;
    query.exec("select * from vertexs");
    int x_cod;//点的横坐标的相对值
    int y_cod;//点的纵坐标的相对值
    string name;//点的名称
    int price;//景点票价
    numOfNodes = 0;//景点个数，初始化为0
    numOfPath = 0;//DFS路径条数，初始化为0
    //读景点个数
    while(query.next()){
        numOfNodes++;
    }


    nodes = new HeadNode * [numOfNodes];
    path1 = new int[numOfNodes];
    dist = new double[numOfNodes];
    visited = new bool[numOfNodes];
    mst = new struct closedge[numOfNodes];
    matrix = new int*[numOfNodes];
    for(int i = 0;i < numOfNodes; i++){
        matrix[i] = new int[numOfNodes];
    }
    for(int i = 0; i < numOfNodes; i ++ ){
        for (int j = 0; j < numOfNodes; j ++ ){
            matrix[i][j] = 0;
        }
    }
    for(int i = 0;i < numOfNodes;i++){
        visited[i] = false;
        path1[i] = 0;//初始化path的前驱都为0
        dist[i] = 0;//初始化最短距离都为0
    }
    query.exec("select * from vertexs");

    int index = 0;
    //初始化景点nodes数组
    while(query.next()){
        name = query.value(1).toString().toStdString();
        price = query.value(2).toInt();
        x_cod = query.value(3).toInt();
        y_cod = query.value(4).toInt();
        struct HeadNode* newNode;
        newNode = new HeadNode(x_cod, y_cod, name, price, nullptr);
        nodes[index] = newNode;
        index++;
    }
    db.close();
    list1 = new LinkedList<int>;
    list2 = new LinkedList<int>;
}

Graph::~Graph() {
    for (int i = 0; i < numOfNodes; i++) {
        delete[] nodes[i];
    }
    delete[] nodes;
    delete[] dist;
    delete[] path1;
    delete[] visited;
    delete list1;
    delete list2;
    delete[] mst;

    for (int i = 0; i < numOfNodes; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

//初始化图的边：构建邻接矩阵
void Graph::initGraph(const char* fileName) {
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    //= QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1"); //设置数据库主机名
    db.setDatabaseName(fileName); //设置数据库名
    db.setUserName("root"); //设置数据库登入用户名
    db.setPassword("qq130727"); //设计数据库登入密码

    if (!db.open())
    {
        throw "failed opening the database";
    }

    QSqlQuery query;
    query.exec("select * from edges");
    int vertex1;
    int vertex2;
    double weight;
    while(query.next()){
        vertex1 = query.value(0).toInt();
        vertex2 = query.value(1).toInt();
        weight = sqrt((nodes[vertex2]->x_cod - nodes[vertex1]->x_cod) * (nodes[vertex2]->x_cod - nodes[vertex1]->x_cod)
                      + (nodes[vertex2]->y_cod - nodes[vertex1]->y_cod) * (nodes[vertex2]->y_cod - nodes[vertex1]->y_cod));
        addArc(vertex1,vertex2, weight);
        matrix[vertex1][vertex2] = 1;
        matrix[vertex2][vertex1] = 1;
    }
    db.close();
}

//增加边，无向图
Graph* Graph::addArc(int vertex1, int vertex2, double weight) {
    struct ArcCell* p = nodes[vertex1]->firstArc;
    struct ArcCell* newNode;
    newNode = new struct ArcCell(vertex2, weight, nullptr);
    if (p == nullptr) {
        nodes[vertex1]->firstArc = newNode;
    }
    else {
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newNode;
    }

    struct ArcCell* q = nodes[vertex2]->firstArc;
    newNode = new struct ArcCell(vertex1, weight, nullptr);
    if (q == nullptr) {
        nodes[vertex2]->firstArc = newNode;
    }
    else {
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = newNode;
    }
    return this;
}

//深度优先遍历:遍历结果应当放到一个数组中,遍历前初始化visited[]数组
//需要返回从该点出发的所有路径,所有路径放到链表中
void Graph::DFS(int initIndex){
    //初始化visited数组
    for(int i = 0;i < numOfNodes;i ++){
        visited[i] = false;
    }

    //清空链表
    int temp;
    for (int i = 1; i <= list2->length(); i++) {
        list2->del(1, temp);
    }
    numOfPath = 0;
    int *aPath;
    aPath = new int[numOfPath];
    int index0 = 0;
    DFSAlgo(initIndex, index0, aPath);

    //delete[] aPath;

}

void Graph::DFSAlgo(int nVex, int &nIndex,int aPath[]){
    visited[nVex] = true;
    aPath[nIndex++] = nVex;
    if (nIndex == numOfNodes)//顶点遍历完毕,保存一条路径
    {
        LinkedList<int> *p = new LinkedList<int>;
        //p->vexs = new int[CGraph::m_nVexNum];
        for (int i = 0; i < numOfNodes; i++){
            p->insert(i+1, aPath[i]);
        }
        //把p连到linkedlist之后
        linkTwoLists(list2, p);
        cout <<"**********************************"<<endl;
        for(int i = 0;i < nIndex;i++){
            cout << aPath[i] <<endl;
        }
        cout <<"**********************************"<<endl;

    }
    else
    {
        for (int i = 0; i < numOfNodes; i++)
        {
            if (matrix[nVex][i] == 1 && visited[i] == false)
            {
                DFSAlgo(i, nIndex, aPath);
                visited[i] = false;
                nIndex--;
            }
        }
    }
}
//路径放到path数组中
void Graph::getshortestPath(int initIndex){
    //遍历邻接表的指针
    struct ArcCell* p = nodes[initIndex]->firstArc;

    //初始化visited数组，全部设为false（未访问）

    for (int i = 0; i < numOfNodes; i++) {
        visited[i] = false;
        dist[i] = 0x7FFFFFF;//首先全部设为无穷大
        path1[i] = -1;//path一开始没有前驱
    }


    while ( p != nullptr ) {
        //初始化dist数组:与源点连通的即赋值
        dist[p->index] = p->weight;
        //初始化path1数组:与源点连通的点的前驱设为initIndex
        path1[p->index] = initIndex;
        p = p->next;
    }

    dist[initIndex] = 0;
    visited[initIndex] = true;
    int min;
    int minIndex;
    for (int i = 0; i < numOfNodes; i++) {
        if(i == initIndex){
            continue;
        }
        min = dist[i];
        for (int j = 0; j < numOfNodes; j++) {
            if(!visited[j]){
                //找到未遍历的距离源点的最小距离 和 距离最小的点的下标
                if(dist[j] < min){
                    min = dist[j];
                    minIndex = j;
                }
            }
        }
        //将minIndex加入最短路径中
        visited[minIndex] = true;

        //调整其余未被访问的点
        p = nodes[minIndex]->firstArc;
        while ( p != nullptr ) {
            if(!visited[p->index]){
                if(dist[minIndex] + p->weight < dist[p->index] ){
                    dist[p->index] = dist[minIndex] + p->weight;
                    path1[p->index] = minIndex;
                }
            }
            p = p->next;
        }
    }
}


//获取两点之间最短路径，返回最短路径的链表
LinkedList<int>* Graph::getshortestPath(int initIndex, int endIndex){
    //清空链表
    int temp;
    for (int i = 1; i <= list1->length(); i++) {
        list1->del(1, temp);
    }
    getshortestPath(initIndex);
    //将路径加入链表
    int pathIndex = endIndex;
    while(path1[pathIndex] != -1){
        list1->insert(1, pathIndex);
        pathIndex = path1[pathIndex];
    }
    list1->insert(1, initIndex);
    return list1;
}


//获得最小生成树
struct closedge* Graph::getMST(int initIndex){
    //初始化mst数组
    for(int i = 0; i < numOfNodes; i ++){
        mst[i].adjvex = -1;
        mst[i].lowcost = 0x7FFFFFF;
    }
    struct ArcCell* p = nodes[initIndex]->firstArc;

    //针对initIndex给mst数组赋值
    mst[initIndex].adjvex = -1;
    while ( p != nullptr ) {
        mst[p->index].adjvex = initIndex;
        mst[p->index].lowcost = p->weight;
        p = p->next;
    }
    mst[initIndex].lowcost = 0;


    int k = initIndex;
    double min = 0x7FFFFFF;

    //循环:
    for (int i = 0; i < numOfNodes;i ++){
        if(i == initIndex){
            continue;
        }
        min = 0x7FFFFFF;
        //找到与上一个点最近的点
        for(int j = 0; j < numOfNodes; j++){
            if(mst[j].lowcost != 0 && min > mst[j].lowcost){
                min = mst[j].lowcost;
                k = j;
            }
        }
        //将k加入最小生成树（lowcost = 0）
        mst[k].lowcost = 0;

        //更新mst数组
        p = nodes[k]->firstArc;
        while(p != nullptr){
            if(mst[p->index].lowcost > p->weight){
                mst[p->index].adjvex = k;
                mst[p->index].lowcost = p->weight;
            }
            p = p->next;
        }
    }
    return mst;
}

int Graph::getNumOfNode(){
    return numOfNodes;
}

void Graph::showPathAndDist(){
    for(int i = 0;i < numOfNodes;i ++){
        qDebug() << dist[i] << path1[i];
    }
}


void Graph::showVertex() {
    for (int i = 0; i < numOfNodes; i++) {
        cout << i << " " << nodes[i]->name  <<" "<< nodes[i]->price << endl;
    }
}

void Graph::showAll () {
    struct ArcCell* p;
    for (int i = 0; i < numOfNodes; i++) {
        cout << nodes[i]->name << "->";
        p = nodes[i]->firstArc;
        while (p != nullptr) {
            cout << nodes[p->index]->name << "(" << p->weight << ")" ;
            cout << "->";
            p = p->next;
        }
        cout << "^";
        cout << endl;
    }
}
void Graph::showMatrix(){
    for(int i = 0; i < numOfNodes; i ++ ){
        for (int j = 0; j < numOfNodes; j ++ ){
           cout << matrix[i][j] << " " ;
        }
        cout << endl;
    }
}

//把后一个链表链接到前一个链表尾部并返回前一个链表
LinkedList<int>* linkTwoLists(LinkedList<int>* list1, LinkedList<int>* list2){
    pNode<int> *head1 = list1->head;
    pNode<int> *head2 = list2->head;
    pNode<int> *p = head1;
    if( head1 == nullptr ) {
        list1 = list2;
        return list1;
    }
    while(p->next != nullptr){
        p = p->next;
    }

    p->next = head2;

    return list1;
}

