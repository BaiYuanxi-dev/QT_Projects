#include "achive.h"
#include "ui_achive.h"

achive::achive(QWidget *parent) :QWidget(parent),ui(new Ui::achive){
    ui->setupUi(this);
    QPalette palette0;
    QPixmap pixmap0("E:/uiProject/achiveP.png");
    palette0.setBrush(backgroundRole(), QBrush(pixmap0));
    this->setPalette(palette0);
    this->ui->achiveLabel_1->setStyleSheet("background-image:url(E:/uiProject/achive1before.png)");
    this->ui->achiveLabel_2->setStyleSheet("background-image:url(E:/uiProject/achive2before.png)");
    this->ui->achiveLabel_3->setStyleSheet("background-image:url(E:/uiProject/achive3before.png)");
    this->ui->achiveLabel_4->setStyleSheet("background-image:url(E:/uiProject/achive4before.png)");
    this->ui->achiveLabel_5->setStyleSheet("background-image:url(E:/uiProject/achive5before.png)");
    this->ui->achiveLabel_6->setStyleSheet("background-image:url(E:/uiProject/achive6before.png)");
    this->ui->achiveLabel_7->setStyleSheet("background-image:url(E:/uiProject/achive7before.png)");
    this->ui->achiveLabel_8->setStyleSheet("background-image:url(E:/uiProject/achive8before.png)");
    this->ui->achiveLabel_9->setStyleSheet("background-image:url(E:/uiProject/achive9before.png)");
}

achive::~achive(){
    delete ui;
}
