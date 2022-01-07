#include "endgame.h"
#include "ui_endgame.h"

#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

#include <QPauseAnimation>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QPainter>
endGame::endGame(QWidget *parent) :QWidget(parent),ui(new Ui::endGame){
    ui->setupUi(this);

    labels = new QLabel*[3];
    for(int i = 0; i <3; i ++){
        labels[i] = new QLabel(this);
    }
    setLabels();

    bonusLabel = new QLabel(this);

    button = new QPushButton(this);

    buttonLabel = new QLabel(this);
    setButton();

    setBonusLabel();

    setButtonLabel();
//    QGraphicsOpacityEffect * opa = new QGraphicsOpacityEffect(ui->star1);
//    opa->setOpacity(0.5);
//    ui->star1->setGraphicsEffect(opa);

//    opa = new QGraphicsOpacityEffect(ui->star2);
//    opa->setOpacity(0.5);
//    ui->star2->setGraphicsEffect(opa);

//    opa = new QGraphicsOpacityEffect(ui->star3);
//    opa->setOpacity(0.5);
//    ui->star3->setGraphicsEffect(opa);

//    opa = new QGraphicsOpacityEffect(ui->label);
//    opa->setOpacity(0.5);
//    ui->label->setGraphicsEffect(opa);

//    opa = new QGraphicsOpacityEffect(ui->pushButton);
//    opa->setOpacity(0.5);
//    ui->pushButton->setGraphicsEffect(opa);

////    ui->pushButton->setStyleSheet("border:none");
////    ui->pushButton->setIcon(QIcon(QString("D:/Qt/Final_Project3/Game4_3/uiProject/continue.png")));
////    ui->pushButton->setIconSize(QSize(191, 111));
//    QPixmap pixmap;
//    pixmap.load("D:/Qt/Final_Project3/Game4_3/uiProject/endImg/endButton.png");

//    //TODO加载失败判定


//    pixmap.scaled(ui->pushButton->width(), ui->pushButton->height());
//    //ui->pushButton->setFixedSize( pixmap.width(), pixmap.height());
//    ui->pushButton->setStyleSheet("QPushButton{border:0px}");
//    ui->pushButton->setIcon(pixmap);
//    ui->pushButton->setIconSize(QSize(pixmap.width(), pixmap.height()));
//    ui->pushButton->setIconSize(pixmap.size());



//    ui->endLabel->setVisible(false);

//    opa = new QGraphicsOpacityEffect(ui->endLabel);
//    opa->setOpacity(0.5);
//    ui->endLabel->setGraphicsEffect(opa);

}

endGame::~endGame(){
    for(int i = 0; i <3; i ++){
        delete labels[i];
    }
    delete[] labels;
    delete ui;
}

void endGame::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load("D:/Qt/Final_Project3/Game4_3/uiProject/endImg/endBk.jpg");
    pix.scaled(this->width(), this->height());
    painter.drawPixmap(0, 0, pix);
}

void endGame::setLabels(){
    QPixmap pixmap("D:/Qt/Final_Project3/Game4_3/uiProject/endImg/star.png");
    labels[0]->move(100, 350);
    labels[1]->move(250, 250);
    labels[2]->move(400, 350);

    for(int i = 0; i < 3; i ++){
        labels[i]->setFixedSize(115,115);
        labels[i]->setScaledContents(true);
        pixmap = pixmap.scaled(labels[i]->width(), labels[i]->height());
        labels[i]->setPixmap(pixmap);
        labels[i]->setVisible(false);
    }
}

void endGame::setButton(){
    button->move(240, 450);
    button->show();
    QPixmap pixmap;
    pixmap.load("D:/Qt/Final_Project3/Game4_3/uiProject/endImg/button.png");

    pixmap.scaled(150, 44);
//    //TODO加载失败判定


    button->setFixedSize( pixmap.width(), pixmap.height());
    button->setStyleSheet("QPushButton{border:0px}");
    button->setIcon(pixmap);
    //this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    button->setIconSize(pixmap.size());
    connect(button, &QPushButton::clicked, this, [=](){


        for(int i = 0; i <3; i ++){
            labels[i]->show();
            showMove(labels[i]);
        }
    });
}

void endGame::setBonusLabel(){
    QPixmap pixmap("D:/Qt/Final_Project3/Game4_3/uiProject/endImg/end.png");
    bonusLabel->move(100, 20);


    bonusLabel->setFixedSize(400,300);
    bonusLabel->setScaledContents(true);
    pixmap = pixmap.scaled(bonusLabel->width(), bonusLabel->height());
    bonusLabel->setPixmap(pixmap);
    bonusLabel->setVisible(false);

}

void endGame::setButtonLabel(){
    QPixmap pixmap("D:/Qt/Final_Project3/Game4_3/uiProject/endImg/buttonLabel.png");
    buttonLabel->move(140, 460);


    buttonLabel->setFixedSize(110,120);
    buttonLabel->setScaledContents(true);
    pixmap = pixmap.scaled(bonusLabel->width(), bonusLabel->height());
    buttonLabel->setPixmap(pixmap);
    buttonLabel->show();

}
void endGame::showMove(QLabel *label){
    QTimer *timer = new QTimer(this);
    num = 0;
    connect(timer, &QTimer::timeout, this, [=](){
        QString path;
        num++;
        if(num > 8){
            timer->stop();
        }
        path = "D:/Qt/Final_Project3/Game4_3/uiProject/endImg/bounce" + QString::number(num) + ".png" ;

        QPixmap pixmap(path);
        pixmap = pixmap.scaled(label->width(), label->height());
        label->setPixmap(pixmap);
    });
    timer->start(200);

    bonusLabel->setVisible(true);
    QGraphicsOpacityEffect * opa = new QGraphicsOpacityEffect(this);
    opa->setOpacity(0);
    this->setGraphicsEffect(opa);
    QPropertyAnimation * pro = new QPropertyAnimation(opa, "opacity", this);
    pro->setStartValue(0);
    pro->setEndValue(1);
    pro->setDuration(2000);
    pro->start();

}
