#include "rankwidget.h"

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
    for(int i = 0; i < numOfRank; i++){
        delete listItems[i];
    }
    delete [] listItems;
}

void RankWidget::paintEvent(QPaintEvent *event){
//    QPainter painter(this);
//    QPixmap pix;
//    pix.load(":/image/rankBk/RankBackground.png");
//    painter.drawPixmap(0, 0, pix);
}

void RankWidget::setRankWidget(){

    QString pathOfImg;
    titleLabel = new QLabel();
    QPixmap pix;
    pix.load(":/Image/resource/image/rankImg/title2.png");
    titleLabel->setPixmap(pix);
    titleLabel->setParent(this);
    titleLabel->setGeometry(55, 2, 220, 50);
    //vLayout->addWidget(titleLabel);

    for (int i = 0; i < numOfRank; i ++) {
        pathOfImg = ":/Image/resource/image/rankImg/head (";
        pathOfImg += QString::number(i + 1);
        pathOfImg += ").png";
        listItems[i] = new listItemWidget(i + 1, rankStr[i], pathOfImg);
        vLayout->addWidget(listItems[i]);
    }
}

void RankWidget::setBk(){
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/Image/resource/image/rankBk/RankBk2.jpg");
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);

}
