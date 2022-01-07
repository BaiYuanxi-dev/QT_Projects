#include "endgame.h"
#include "ui_endgame.h"

#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

endGame::endGame(QWidget *parent) :QWidget(parent),ui(new Ui::endGame){
    ui->setupUi(this);
    setStyleSheet("QPushButton:hover{background-color: rgb(255, 255, 255);border-radius:15px;border:none;color:rgb(255, 255, 255);}"
                                "QPushButton:checked{background-color: rgb(64, 65, 66);border:none;color:rgb(255, 255, 255);}");

    ui->pushButton->setStyleSheet("border:none");
    ui->pushButton->setIcon(QIcon(QString("D:/Qt/Final_Project2/Game4 (2)/uiProject/continue.png")));
    ui->pushButton->setIconSize(QSize(191, 111));

}

endGame::~endGame(){
    delete ui;
}

void endGame::on_pushButton_clicked(){
    QLabel * newStar1 = new QLabel(this);
    QLabel * newStar2 = new QLabel(this);
    QLabel * newStar3 = new QLabel(this);
    newStar1->setStyleSheet("border-image:url(\"D:/Qt/Final_Project2/Game4 (2)/uiProject/fullStar.png\");");
    newStar2->setStyleSheet("border-image:url(\"D:/Qt/Final_Project2/Game4 (2)/uiProject/fullStar.png\");");
    newStar3->setStyleSheet("border-image:url(\"D:/Qt/Final_Project2/Game4 (2)/uiProject/fullStar.png\");");

    QPropertyAnimation * pro1 = new QPropertyAnimation(newStar1, "geometry");
    pro1->setDuration(600);
    pro1->setStartValue(QRect(ui->star1->pos().x() - 50, ui->star1->pos().y() - 50, ui->star1->width() + 100, ui->star1->height() + 100));
    pro1->setEndValue(QRect(ui->star1->pos().x(), ui->star1->pos().y(), ui->star1->width(), ui->star1->height()));

    QPropertyAnimation * pro2 = new QPropertyAnimation(newStar2, "geometry");
    pro2->setDuration(600);
    pro2->setStartValue(QRect(ui->star2->pos().x() - 50, ui->star2->pos().y() - 50, ui->star2->width() + 100, ui->star2->height() + 100));
    pro2->setEndValue(QRect(ui->star2->pos().x(), ui->star2->pos().y(), ui->star2->width(), ui->star2->height()));

    QPropertyAnimation * pro3 = new QPropertyAnimation(newStar3, "geometry");
    pro3->setDuration(600);
    pro3->setStartValue(QRect(ui->star3->pos().x() - 50, ui->star3->pos().y() - 50, ui->star3->width() + 100, ui->star3->height() + 100));
    pro3->setEndValue(QRect(ui->star3->pos().x(), ui->star3->pos().y(), ui->star3->width(), ui->star3->height()));

    QSequentialAnimationGroup * group = new QSequentialAnimationGroup(this);

    newStar1->show();
    newStar2->show();
    newStar3->show();

    group->addAnimation(pro1);
    group->addAnimation(pro2);
    group->addAnimation(pro3);

    group->start(QAbstractAnimation::DeleteWhenStopped);
}
