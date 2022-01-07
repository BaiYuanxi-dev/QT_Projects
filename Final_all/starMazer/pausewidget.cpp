#include "pausewidget.h"
#include "ui_pausewidget.h"

PauseWidget::PauseWidget(QWidget *parent) :QWidget(parent),ui(new Ui::PauseWidget){
    ui->setupUi(this);
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(252, 213, 118)));
}

PauseWidget::~PauseWidget(){
    delete ui;
}

void PauseWidget::on_pushButton_clicked(){
    this->~PauseWidget();
}
