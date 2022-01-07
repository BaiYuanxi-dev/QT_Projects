#include "listitemwidget.h"

/**
 * @brief listItemWidget::listItemWidget
 * @param rank 排名
 * @param rankStr 排名字符串：id + 分数
 * @param pathOfImg
 * @param parent
 */
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
    delete rankLabel;
    delete imgLabel;
    delete msgLine;
    delete grid;
}

/**
 * @brief listItemWidget::setItemWidget 设置每一项的界面
 */
void listItemWidget::setItemWidget(){
    rankLabel = new QLabel(this);

    QString rankNumPath = ":/image/rankImg/rank (";
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


