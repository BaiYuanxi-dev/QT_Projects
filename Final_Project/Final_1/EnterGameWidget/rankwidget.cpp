#include "rankwidget.h"

/**
 * @brief RankWidget::RankWidget 排名界面
 * @param rankStr 排名字符串
 * @param numOfRank 排名的数量
 * @param parent
 */
RankWidget::RankWidget(QString *rankStr, int numOfRank,QWidget *parent) : QWidget(parent)
{
    this->rankStr = rankStr;
    this->numOfRank = numOfRank;
    this->setBk();
    listItems = new listItemWidget*[numOfRank];
    vLayout = new QVBoxLayout;
    vLayout->setContentsMargins(0, 50, 22, 0);
    setRankWidget();
    this->setLayout(vLayout);
}

RankWidget::~RankWidget(){
    delete [] rankStr;
    delete vLayout;
    delete titleLabel;
    for(int i = 0; i < numOfRank; i++){
        delete listItems[i];
    }
    delete [] listItems;
}


void RankWidget::setRankWidget(){

    QString pathOfImg;
    titleLabel = new QLabel();
    QPixmap pix;
    pix.load(":/image/rankImg/title2.png");
    titleLabel->setPixmap(pix);
    titleLabel->setParent(this);
    titleLabel->setGeometry(55, 2, 220, 50);
    //vLayout->addWidget(titleLabel);

    for (int i = 0; i < numOfRank; i ++) {
        pathOfImg = ":/image/rankImg/head (";
        pathOfImg += QString::number(i + 1);
        pathOfImg += ").png";
        listItems[i] = new listItemWidget(i + 1, rankStr[i], pathOfImg);
        vLayout->addWidget(listItems[i]);
    }
}

/**
 * @brief RankWidget::setBk 设置背景
 */
void RankWidget::setBk(){
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/image/rankBk/RankBk2.jpg");
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);

}
