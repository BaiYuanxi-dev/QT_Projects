#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :QWidget(parent),ui(new Ui::info){
    ui->setupUi(this);
    QPalette palette0;
    QPixmap pixmap0("E:/uiProject/infoG.png");
    palette0.setBrush(backgroundRole(), QBrush(pixmap0));
    this->setPalette(palette0);
    this->ui->headLabel->setStyleSheet("background-image:url(E:/uiProject/head1.png)");
}

info::~info(){
    delete ui;
}
