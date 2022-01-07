#include "helpform.h"
#include "ui_helpform.h"

helpForm::helpForm(QWidget *parent) :QWidget(parent),ui(new Ui::helpForm){
    ui->setupUi(this);
    QPalette palette0;
    QPixmap pixmap0("C:/Users/Lenovo/Desktop/source/helpInfo.png");
    palette0.setBrush(backgroundRole(), QBrush(pixmap0));
    this->setPalette(palette0);
}

helpForm::~helpForm(){
    delete ui;
}
