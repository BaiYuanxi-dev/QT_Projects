#include "listitemwidget.h"

listItemWidget::listItemWidget(int rank, QString rankStr, QString pathOfImg, QWidget *parent) : QWidget(parent)
{
    this->rank = rank;
    this->rankStr = rankStr;
    this->pathOfImg = pathOfImg;
    //hLayOut = new QHBoxLayout;
    grid = new QGridLayout;
    this->resize(280, 80);
    setItemWidget();
}

listItemWidget::~listItemWidget(){

}

void listItemWidget::setItemWidget(){
    rankLabel = new QLabel(this);

    QString rankNumPath = ":/image/rankImg/rank (";
    rankNumPath += QString::number(rank);
    rankNumPath += ").png";
    //QString rankNumPath = "image/rankImg/rank (1).png";
    QPixmap pixmap;
    pixmap.load(rankNumPath);
    rankLabel->setPixmap(pixmap);


    //rankLabel->setFont(QFont("楷体", 12, QFont::Bold));
    //rankLabel->move(5, 5);


    imgLabel = new QLabel(this);
    QPixmap pix;
    pix.load(pathOfImg);
    //rankLabel->setPixmap(pix);
    imgLabel->setPixmap(pix);
    imgLabel->setStyleSheet("QWidget{background-color:gray;border-top-left-radius:15px;border-top-right-radius:5px;}");


//    rankStr += QString::number(rank) + " ";
//    QString rankStr2 = " ";
//    rankStr2 = QString::number(rank);
//    rankStr2 += rankStr;


//    msgLabel = new QLabel(rankStr,this);
//    msgLabel->setFont(QFont("楷体", 12, QFont::Bold));
//    msgLabel->move(100, 50);
    msgLine = new QLineEdit;

    msgLine->setFont(QFont("微软雅黑", 10));

    //msgLine->setStyleSheet("color:red");
    msgLine->setText(rankStr);
    msgLine->setEnabled(false);
    msgLine->setStyleSheet("background:transparent;border-width:0;border-style:outset;color:black");

    //rankLabel->show();
    //imgLabel->show();

    //msgLabel->show();

    this->grid->addWidget(rankLabel, 0, 0);
    this->grid->addWidget(imgLabel, 0, 1);

    this->grid->addWidget(msgLine, 0, 2);
    this->setLayout(grid);


}


