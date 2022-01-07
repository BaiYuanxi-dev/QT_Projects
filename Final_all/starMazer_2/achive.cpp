#include "achive.h"
#include "ui_achive.h"

achive::achive(QWidget *parent) :QWidget(parent),ui(new Ui::achive){
    ui->setupUi(this);
    QPalette palette0;
    setAutoFillBackground(true);
    QPixmap pixmap0("E:/uiProject/achiveP.png");
    palette0.setBrush(backgroundRole(), QBrush(pixmap0));
    this->setPalette(palette0);
}

achive::~achive(){
    delete ui;
}

void achive::on_pushButton_clicked(){
    this->~achive();
}
