#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QScrollArea *m = new QScrollArea(this);
    MyListWidget *a = new MyListWidget(this);
    ListItem *b = new ListItem();
    ListItem *c = new ListItem();
    ListItem *d = new ListItem();
    a->add(b);
    a->add(c);
    a->add(d);
    m->setWidget(a);
    m->setGeometry(200,50,400,500);
    m->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    m->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖向滚动条
}

MainWindow::~MainWindow()
{
    delete ui;
}

