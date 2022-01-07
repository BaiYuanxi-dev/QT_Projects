#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QMessageBox>
#include <iostream>
#include <sstream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    canPaint = true;
    pathIndex = 0;
    //图的创建:需要顶点和边的信息，画图
    graph = new Graph("graph.db");


    graph->initGraph("graph.db");

    this->nodes = graph->getVerAndEdge();
    this->numOfNodes = graph->getNumOfNode();
    buttons = new MyButton*[numOfNodes];

    //创建button对象
    for(int i = 0;i < numOfNodes;i ++){
        MyButton *newButton = new MyButton;
        buttons[i] = newButton;
        buttons[i]->setParent(this);
    }

    setButtons();


    this->functionChoice = 0;


    //按钮
    connect(ui->DFSRadBut, &QRadioButton::clicked, this, [=](){
        canPaint = false;
        functionChoice = 1;
    });

    connect(ui->shortPathRadBut, &QRadioButton::clicked, this, [=](){
        canPaint = false;
        pathIndex = 0;
        functionChoice = 2;
    });

    connect(ui->MSTRadBut, &QRadioButton::clicked, this, [=](){
        canPaint = false;
        pathIndex = 0;
        functionChoice = 3;
    });

    connect(ui->initButton, &QPushButton::clicked, this, [=](){
        functionChoice = 0;
        pathIndex = 0;
        canPaint = true;
        update();
    });

    connect(ui->msgRadBut, &QPushButton::clicked, this, [=](){
        functionChoice = 4;
        pathIndex = 0;
        //canPaint = false;
    });

    connect(ui->exitButton, &QPushButton::clicked, this, [=](){
        exit(0);
    });




    //i是button下标，对应点nodes的下标
    for(int i = 0;i < numOfNodes; i ++){
        connect(buttons[i], &QPushButton::clicked, this, [=](){
           if(functionChoice == 0){
               canPaint = true;
               update();
               return;
           } else if (functionChoice == 1) {
               //DFS
               buttonIndex = i;
           } else if (functionChoice == 2) {
               //最短路径
               bool ok;
               QStringList items;
               items << tr("A") << tr("B")<< tr("C") << tr("D")<< tr("E") << tr("F")<<tr("G");
               // 获取条目
               QString item = QInputDialog::getItem(this, tr("inpiy"), tr("choose"), items, 0, true, &ok);


               for(int j = 0;j < numOfNodes; j ++){
                   if(buttons[j]->text() == item){
                       num = 0;
                       path1 = graph->getshortestPath(i, j, num);


                       canPaint = true;
                       update();
                   }
               }


           } else if (functionChoice == 3) {
               //MST
               mst =  graph->getMST(i);
               canPaint = true;
               update();
           } else if (functionChoice == 4) {
               canPaint = true;
               string message;
               stringstream toStr;

               message = "编号: ";
               message += to_string(i);
               message += "\n";
               message += "名字: " + nodes[i]->name + "\n";
               message += "票价: ";
               message += to_string(nodes[i]->price) + "\n";

               QMessageBox::information(this, "信息", QString::fromStdString(message));

            }
        });
    }

    connect(ui->pathButton, &QPushButton::clicked, this, [=](){
        //画下一条路径
        if(functionChoice == 1){


            paths = graph->DFS(buttonIndex, numOfPath);
            if(pathIndex >= numOfPath){
                QMessageBox::information(this, "信息", "完毕");
                pathIndex = 0;
                canPaint = true;
                functionChoice = 0;
                update();
                return;
            } else {
                canPaint = true;
                update();
                //pathIndex++;
            }

        } else {
            return;
        }
    });
    tmpcount = 0;

}

MainWindow::~MainWindow()
{
    delete graph;
    for(int i = 0;i < numOfNodes;i ++){
        delete buttons[i];
    }
    delete[] buttons;
    delete ui;
}

void MainWindow::setButtons(){
    for (int i = 0; i <numOfNodes; i ++){
        buttons[i]->setThisButton(nodes[i]->x_cod * ((this->width() - 230) / 66), nodes[i]->y_cod * (this->height() / 46), nodes[i]->name);
        buttons[i]->show();
    }
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    if(!canPaint){
        return;
    }
    struct ArcCell* p;

    if ( functionChoice == 0 ) {
        painter.setRenderHint(QPainter::Antialiasing);
        for(int i = 0;i < this->numOfNodes; i++){
            p = this->nodes[i]->firstArc;
            while( p != nullptr ) {
                painter.drawLine(QPoint((nodes[i]->x_cod + 1) * ((this->width() - 230) / 66),
                                        (nodes[i]->y_cod + 1) * (this->height() / 46)),
                                 QPoint((nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66),
                                        (nodes[p->index]->y_cod + 1) * (this->height() / 46)));
                painter.drawText(QPoint( ( 2 * (nodes[i]->x_cod + 1) * ((this->width() - 230) / 66) +
                                            (nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66)) / 3,
                                        ( 2 * (nodes[i]->y_cod + 1) * (this->height() / 46) +
                                            (nodes[p->index]->y_cod + 1) * (this->height() / 46)) / 3 ),
                        QString::number(p->weight));
                p = p->next;
            }
        }
        //canPaint = false;
        return;
    } else if ( functionChoice == 1 ) {
        //DFS

        for(int i = 0;i < this->numOfNodes; i++){
            p = this->nodes[i]->firstArc;
            while( p != nullptr ) {
                painter.drawLine(QPoint((nodes[i]->x_cod + 1) * ((this->width() - 230) / 66),
                                        (nodes[i]->y_cod + 1) * (this->height() / 46)),
                                 QPoint((nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66),
                                        (nodes[p->index]->y_cod + 1) * (this->height() / 46)));
                painter.drawText(QPoint( (2 * (nodes[i]->x_cod + 1) * ((this->width() - 230) / 66) +
                                            (nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66)) / 3,
                                        ( 2 * (nodes[i]->y_cod + 1) * (this->height() / 46) +
                                            (nodes[p->index]->y_cod + 1) * (this->height() / 46)) / 3 ),
                        QString::number(p->weight));
                p = p->next;
            }
        }

        QPen pen(QColor(0, 0, 255));
        pen.setWidth(4);
        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing);
        for(int i = 0; i < numOfNodes - 1;i ++){
            painter.drawLine(
                        QPoint((nodes[paths[pathIndex][i]]->x_cod + 1)* ((this->width() - 230) / 66),
                                    (nodes[paths[pathIndex][i]]->y_cod + 1) * (this->height() / 46)),
                        QPoint((nodes[paths[pathIndex][i+1]]->x_cod + 1)* ((this->width() - 230) / 66),
                                    (nodes[paths[pathIndex][i+1]]->y_cod + 1) * (this->height() / 46))
                    );
        }
        pathIndex++;
        canPaint = false;
    } else if ( functionChoice == 2 ) {
        //最短路径
        for(int i = 0;i < this->numOfNodes; i++){
            p = this->nodes[i]->firstArc;
            while( p != nullptr ) {
                painter.drawLine(QPoint((nodes[i]->x_cod + 1) * ((this->width() - 230) / 66),
                                        (nodes[i]->y_cod + 1) * (this->height() / 46)),
                                 QPoint((nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66),
                                        (nodes[p->index]->y_cod + 1) * (this->height() / 46)));
                painter.drawText(QPoint( (2 * (nodes[i]->x_cod + 1) * ((this->width() - 230) / 66) +
                                            (nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66)) / 3,
                                        ( 2 * (nodes[i]->y_cod + 1) * (this->height() / 46) +
                                            (nodes[p->index]->y_cod + 1) * (this->height() / 46)) / 3 ),
                        QString::number(p->weight));
                p = p->next;
            }
        }



        QPen pen(QColor(0, 255, 0));
        pen.setWidth(3);
        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing);

        for(int i = 0;i < num - 1; i++){
            painter.drawLine(
                        QPoint((nodes[path1[i]]->x_cod + 1)* ((this->width() - 230) / 66),
                                    (nodes[path1[i]]->y_cod + 1) * (this->height() / 46)),
                        QPoint((nodes[path1[i+1]]->x_cod + 1)* ((this->width() - 230) / 66),
                                    (nodes[path1[i+1]]->y_cod + 1) * (this->height() / 46))
                    );
        }
        //canPaint = false;
    } else if ( functionChoice == 3 ) {
        //MST

        for(int i = 0;i < this->numOfNodes; i++){
            p = this->nodes[i]->firstArc;
            while( p != nullptr ) {
                painter.drawLine(QPoint((nodes[i]->x_cod + 1) * ((this->width() - 230) / 66),
                                        (nodes[i]->y_cod + 1) * (this->height() / 46)),
                                 QPoint((nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66),
                                        (nodes[p->index]->y_cod + 1) * (this->height() / 46)));
                painter.drawText(QPoint( (2 * (nodes[i]->x_cod + 1) * ((this->width() - 230) / 66) +
                                            (nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66)) / 3,
                                        ( 2 * (nodes[i]->y_cod + 1) * (this->height() / 46) +
                                            (nodes[p->index]->y_cod + 1) * (this->height() / 46)) / 3 ),
                        QString::number(p->weight));
                p = p->next;
            }
        }


        QPen pen(QColor(255, 0, 0));
        pen.setWidth(4);
        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing);
        for(int i = 0; i < numOfNodes; i ++){
            if(mst[i].adjvex == -1){
                continue;
            }
            painter.drawLine(
                        QPoint((nodes[i]->x_cod + 1)* ((this->width() - 230) / 66),
                                    (nodes[i]->y_cod + 1) * (this->height() / 46)),
                        QPoint((nodes[mst[i].adjvex]->x_cod + 1)* ((this->width() - 230) / 66),
                                    (nodes[mst[i].adjvex]->y_cod + 1) * (this->height() / 46))
                    );
        }
        //canPaint = false;
    } else if(functionChoice == 4){
        painter.setRenderHint(QPainter::Antialiasing);
        for(int i = 0;i < this->numOfNodes; i++){
            p = this->nodes[i]->firstArc;
            while( p != nullptr ) {
                painter.drawLine(QPoint((nodes[i]->x_cod + 1) * ((this->width() - 230) / 66),
                                        (nodes[i]->y_cod + 1) * (this->height() / 46)),
                                 QPoint((nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66),
                                        (nodes[p->index]->y_cod + 1) * (this->height() / 46)));
                painter.drawText(QPoint( ( 2 * (nodes[i]->x_cod + 1) * ((this->width() - 230) / 66) +
                                            (nodes[p->index]->x_cod + 1)  * ((this->width() - 230) / 66)) / 3,
                                        ( 2 * (nodes[i]->y_cod + 1) * (this->height() / 46) +
                                            (nodes[p->index]->y_cod + 1) * (this->height() / 46)) / 3 ),
                        QString::number(p->weight));
                p = p->next;
            }
        }
        //canPaint = false;
        return;
    }
}



