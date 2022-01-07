#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QPixmap pix;
    pix.load(":/image/rankImg/head (1).jpg");
    ui->label->setPixmap(pix);
    //ui->label->setStyleSheet("QLabel{border-image:url(images/frame.png)}" )


}

Form::~Form()
{
    delete ui;
}
