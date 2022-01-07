#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :QWidget(parent),ui(new Ui::info){
    ui->setupUi(this);
    QPalette palette0;
    setAutoFillBackground(true);
    QPixmap pixmap0("E:/uiProject/infoG.png");
    palette0.setBrush(backgroundRole(), QBrush(pixmap0));
    this->setPalette(palette0);
}

info::~info(){
    delete ui;
}

void info::on_pushButton_clicked(){
    this->~info();
}
