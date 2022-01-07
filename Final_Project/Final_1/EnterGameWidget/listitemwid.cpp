#include "listitemwid.h"
#include "ui_listitemwid.h"


/**
 * @brief listItemWid::listItemWid
 * @param rank 排名
 * @param rankStr 排名字符串：id + 分数
 * @param pathOfImg
 * @param parent
 */
ListItemWid::ListItemWid(int rank, QString rankStr, QString pathOfImg, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListItemWid)
{
    ui->setupUi(this);
    this->rank = rank;
    this->rankStr = rankStr;
    this->pathOfImg = pathOfImg;
    //grid = new QGridLayout;
    this->resize(280, 80);
    setItemWidget();
}







ListItemWid::~ListItemWid(){
    delete ui;
}

/**
 * @brief listItemWidget::setItemWidget 设置每一项的界面
 */
void ListItemWid::setItemWidget(){
    //ui->rankLabel = new QLabel(this);

    QString rankNumPath = ":/image/rankImg/rank (";
    rankNumPath += QString::number(rank);
    rankNumPath += ").png";
    QPixmap pixmap;
    pixmap.load(rankNumPath);
    ui->rankLabel->setPixmap(pixmap);


    //ui->imgLabel = new QLabel(this);
    QPixmap pix;
    pix.load(pathOfImg);
    ui->imgLabel->setPixmap(pix);
    //ui->msgLine = new QLineEdit;

    ui->msgLine->setFont(QFont("微软雅黑", 10));
    ui->msgLine->setText(rankStr);
    ui->msgLine->setEnabled(false);
    ui->msgLine->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");

    //ui->grid->addWidget(ui->rankLabel, 0, 0);
    //this->grid->addWidget(ui->imgLabel, 0, 1);

    //this->grid->addWidget(ui->msgLine, 0, 2);
    //this->setLayout(grid);


}


