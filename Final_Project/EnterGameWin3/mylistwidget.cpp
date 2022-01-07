#include "mylistwidget.h"
#include "ui_mylistwidget.h"


MyListWidget::MyListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyListWidget)
{
    ui->setupUi(this);


    myLayOut = new QVBoxLayout;
    this->setLayout(myLayOut);
    listItem = new ListItem;
    myLayOut->addWidget(listItem);
}

MyListWidget::~MyListWidget()
{
    delete ui;
}

void MyListWidget::add(QWidget *a){
    myLayOut->addWidget(a);
}
