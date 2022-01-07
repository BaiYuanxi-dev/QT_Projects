#include "entergamewidget.h"
#include <iostream>
#include <QHBoxLayout>
/*
 * 构造函数
 * param: level 关卡数字
 * */
EnterGameWidget::EnterGameWidget(int level, QString *rankStr, QWidget *parent)
    : QWidget(parent)
{
    this->level = level;
    this->rankStr = rankStr;
    startButton = new QPushButton;

    QHBoxLayout *h = new QHBoxLayout;
    rankWidget = new QListWidget;
    setWidget();
    h->addWidget(rankWidget);
    this->setLayout(h);
}



EnterGameWidget::~EnterGameWidget()
{

}

//设置界面函数
void EnterGameWidget::setWidget(){
    QListWidgetItem **items = new QListWidgetItem*[numOfRank];
    QPixmap* pix;
    QString str;
    for(int i = 0; i < numOfRank; i ++){
        pix = new QPixmap;
        str = ":/image/rankImg/head (";
        str += QString::number(i + 1);
        str += ").jpg";
        pix->load(":/image/rankImg/head (7).jpg");

        items[i] = new QListWidgetItem(QIcon(*pix), "msg1234456544");
        this->rankWidget->insertItem(i, items[i]);
    }

    for(int i = 0; i < numOfRank; i++){
        delete items[i];
    }
    delete[] items;
}

void EnterGameWidget::closeEvent(QCloseEvent *event){
    emit this->backToMain();
}

