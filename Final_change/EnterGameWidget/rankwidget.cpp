#include "rankwidget.h"
#include "ui_rankwidget.h"

RankWidget::RankWidget(QString *rankStr, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankWidget)
{
    ui->setupUi(this);
    this->rankStr = rankStr;//默认长度为8
    this->setBk();
    setLabels();

}

RankWidget::~RankWidget()
{
    delete ui;
}

void RankWidget::setBk(){
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap("E://uiProject//enterImg//RankBk2.jpg");
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
}

void RankWidget::setLabels(){

    ui->label->setFixedSize(166,49);
    ui->label->setScaledContents(true);
    ui->label->setAttribute(Qt::WA_TranslucentBackground);
    ui->label->setPixmap(QPixmap("E:/uiProject/enterImg/title2.png"));



    ui->rankLabel1->setFixedSize(40,32);
    ui->rankLabel1->setScaledContents(true);
    ui->rankLabel1->setAttribute(Qt::WA_TranslucentBackground);
    ui->rankLabel1->setPixmap(QPixmap("E:/uiProject/enterImg/rank (1).png"));


//    QPixmap pix;
//    pix.load("E:/uiProject/enterImg/head (1)");
//    ui->imgLabel1->setPixmap(pix);

    ui->imgLabel1->setFixedSize(60,60);
    ui->imgLabel1->setScaledContents(true);
    ui->imgLabel1->setAttribute(Qt::WA_TranslucentBackground);
    ui->imgLabel1->setPixmap(QPixmap("E:/uiProject/enterImg/head (1).png"));


    ui->msgLabel1->setFont(QFont("Microsoft yahei", 10));
    ui->msgLabel1->setText(rankStr[0]);
    ui->msgLabel1->setEnabled(false);
    ui->msgLabel1->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");


    //-------------------------------------------
    ui->rankLabel2->setFixedSize(40,32);
    ui->rankLabel2->setScaledContents(true);
    ui->rankLabel2->setAttribute(Qt::WA_TranslucentBackground);
    ui->rankLabel2->setPixmap(QPixmap("E:/uiProject/enterImg/rank (2).png"));

    ui->imgLabel2->setFixedSize(60,60);
    ui->imgLabel2->setScaledContents(true);
    ui->imgLabel2->setAttribute(Qt::WA_TranslucentBackground);
    ui->imgLabel2->setPixmap(QPixmap("E:/uiProject/enterImg/head (2).png"));


    ui->msgLabel2->setFont(QFont("Microsoft yahei", 10));
    ui->msgLabel2->setText(rankStr[1]);
    ui->msgLabel2->setEnabled(false);
    ui->msgLabel2->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");

    //-------------------------------------------
    ui->rankLabel3->setFixedSize(40,32);
    ui->rankLabel3->setScaledContents(true);
    ui->rankLabel3->setAttribute(Qt::WA_TranslucentBackground);
    ui->rankLabel3->setPixmap(QPixmap("E:/uiProject/enterImg/rank (3).png"));

    ui->imgLabel3->setFixedSize(60,60);
    ui->imgLabel3->setScaledContents(true);
    ui->imgLabel3->setAttribute(Qt::WA_TranslucentBackground);
    ui->imgLabel3->setPixmap(QPixmap("E:/uiProject/enterImg/head (3).png"));


    ui->msgLabel3->setFont(QFont("Microsoft yahei", 10));
    ui->msgLabel3->setText(rankStr[2]);
    ui->msgLabel3->setEnabled(false);
    ui->msgLabel3->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");

    //-------------------------------------------
    ui->rankLabel4->setFixedSize(40,32);
    ui->rankLabel4->setScaledContents(true);
    ui->rankLabel4->setAttribute(Qt::WA_TranslucentBackground);
    ui->rankLabel4->setPixmap(QPixmap("E:/uiProject/enterImg/rank (4).png"));

    ui->imgLabel4->setFixedSize(60,60);
    ui->imgLabel4->setScaledContents(true);
    ui->imgLabel4->setAttribute(Qt::WA_TranslucentBackground);
    ui->imgLabel4->setPixmap(QPixmap("E:/uiProject/enterImg/head (4).png"));


    ui->msgLabel4->setFont(QFont("Microsoft yahei", 10));
    ui->msgLabel4->setText(rankStr[3]);
    ui->msgLabel4->setEnabled(false);
    ui->msgLabel4->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");

    //-------------------------------------------
    ui->rankLabel5->setFixedSize(40,32);
    ui->rankLabel5->setScaledContents(true);
    ui->rankLabel5->setAttribute(Qt::WA_TranslucentBackground);
    ui->rankLabel5->setPixmap(QPixmap("E:/uiProject/enterImg/rank (5).png"));

    ui->imgLabel5->setFixedSize(60,60);
    ui->imgLabel5->setScaledContents(true);
    ui->imgLabel5->setAttribute(Qt::WA_TranslucentBackground);
    ui->imgLabel5->setPixmap(QPixmap("E:/uiProject/enterImg/head (5).png"));


    ui->msgLabel5->setFont(QFont("Microsoft yahei", 10));
    ui->msgLabel5->setText(rankStr[4]);
    ui->msgLabel5->setEnabled(false);
    ui->msgLabel5->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");

    //-------------------------------------------
    ui->rankLabel6->setFixedSize(40,32);
    ui->rankLabel6->setScaledContents(true);
    ui->rankLabel6->setAttribute(Qt::WA_TranslucentBackground);
    ui->rankLabel6->setPixmap(QPixmap("E:/uiProject/enterImg/rank (6).png"));

    ui->imgLabel6->setFixedSize(60,60);
    ui->imgLabel6->setScaledContents(true);
    ui->imgLabel6->setAttribute(Qt::WA_TranslucentBackground);
    ui->imgLabel6->setPixmap(QPixmap("E:/uiProject/enterImg/head (6).png"));


    ui->msgLabel6->setFont(QFont("Microsoft yahei", 10));
    ui->msgLabel6->setText(rankStr[5]);
    ui->msgLabel6->setEnabled(false);
    ui->msgLabel6->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");

    //-------------------------------------------
    ui->rankLabel7->setFixedSize(40,32);
    ui->rankLabel7->setScaledContents(true);
    ui->rankLabel7->setAttribute(Qt::WA_TranslucentBackground);
    ui->rankLabel7->setPixmap(QPixmap("E:/uiProject/enterImg/rank (7).png"));

    ui->imgLabel7->setFixedSize(60,60);
    ui->imgLabel7->setScaledContents(true);
    ui->imgLabel7->setAttribute(Qt::WA_TranslucentBackground);
    ui->imgLabel7->setPixmap(QPixmap("E:/uiProject/enterImg/head (7).png"));


    ui->msgLabel7->setFont(QFont("Microsoft yahei", 10));
    ui->msgLabel7->setText(rankStr[6]);
    ui->msgLabel7->setEnabled(false);
    ui->msgLabel7->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");

    //-------------------------------------------
    ui->rankLabel8->setFixedSize(40,32);
    ui->rankLabel8->setScaledContents(true);
    ui->rankLabel8->setAttribute(Qt::WA_TranslucentBackground);
    ui->rankLabel8->setPixmap(QPixmap("E:/uiProject/enterImg/rank (8).png"));

    ui->imgLabel8->setFixedSize(60,60);
    ui->imgLabel8->setScaledContents(true);
    ui->imgLabel8->setAttribute(Qt::WA_TranslucentBackground);
    ui->imgLabel8->setPixmap(QPixmap("E:/uiProject/enterImg/head (8).png"));


    ui->msgLabel8->setFont(QFont("Microsoft yahei", 10));
    ui->msgLabel8->setText(rankStr[7]);
    ui->msgLabel8->setEnabled(false);
    ui->msgLabel8->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");
}
