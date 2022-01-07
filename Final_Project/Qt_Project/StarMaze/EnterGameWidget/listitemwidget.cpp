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

    QString rankNumPath = ":/Image/resource/image/rankImg/rank (";
    rankNumPath += QString::number(rank);
    rankNumPath += ").png";
    QPixmap pixmap;
    pixmap.load(rankNumPath);
    rankLabel->setPixmap(pixmap);


    imgLabel = new QLabel(this);
    QPixmap pix;
    pix.load(pathOfImg);
    imgLabel->setPixmap(pix);
    msgLine = new QLineEdit;

    msgLine->setFont(QFont("微软雅黑", 10));
    msgLine->setText(rankStr);
    msgLine->setEnabled(false);
    msgLine->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");

    this->grid->addWidget(rankLabel, 0, 0);
    this->grid->addWidget(imgLabel, 0, 1);

    this->grid->addWidget(msgLine, 0, 2);
    this->setLayout(grid);


}


