#include "helpform.h"
#include "ui_helpForm.h"

helpForm::helpForm(QWidget *parent) :QWidget(parent),ui(new Ui::helpForm){
    ui->setupUi(this);
    QPalette palette0;
    QPixmap pixmap0("E:/uiProject/helpback.png");
    palette0.setBrush(backgroundRole(), QBrush(pixmap0));
    this->setPalette(palette0);
    this->setFixedSize(400,418);
}

helpForm::~helpForm(){
    delete ui;
}
