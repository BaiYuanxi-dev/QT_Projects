#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "graph.h"
#include "mybutton.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setButtons();

    void paintEvent(QPaintEvent *e);

private:
    Ui::MainWindow *ui;
    Graph* graph;//图
    struct HeadNode** nodes;//顶点;
    int numOfNodes;//顶点个数
    MyButton** buttons;//按钮
    int* path1;//最短路径数组
    int functionChoice;//选择功能
    struct closedge* mst;//最小生成树
    bool canPaint;//表示
    int tmpcount;

    int num;//最短路径节点个数
    int numOfPath;
    int** paths;
    int pathIndex;
    int buttonIndex;
};
#endif // MAINWINDOW_H
