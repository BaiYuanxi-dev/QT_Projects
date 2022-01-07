#include "pausewidget.h"
#include "ui_pausewidget.h"

PauseWidget::PauseWidget(QWidget *parent) :QWidget(parent),ui(new Ui::PauseWidget){
    ui->setupUi(this);

    //设置已暂停标签
    ui->pausedLabel->setStyleSheet("border:none;border-radius:10px;");
    ui->pausedLabel->setStyleSheet("background-image:url(D:/Qt/Final_change/Game/uiProject/paused.png)");
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(252, 213, 118)));

    //设置慢速按钮
    ui->slowSpeedbtn->setStyleSheet("border:none;border-radius:10px;");
    ui->slowSpeedbtn->setIcon(QIcon(QString("D:/Qt/Final_change/Game/uiProject/slowSpeed.png")));
    ui->slowSpeedbtn->setIconSize(QSize(100, 100));

    //设置快速按钮
    ui->fastSpeedBtn->setStyleSheet("border:none;border-radius:10px;");
    ui->fastSpeedBtn->setIcon(QIcon(QString("D:/Qt/Final_change/Game/uiProject/fastSpeed.png")));
    ui->fastSpeedBtn->setIconSize(QSize(100, 100));

    //设置常速按钮
    ui->midSpeedBtn->setStyleSheet("border:none;border-radius:10px;");
    ui->midSpeedBtn->setIcon(QIcon(QString("D:/Qt/Final_change/Game/uiProject/midSpeed.png")));
    ui->midSpeedBtn->setIconSize(QSize(100, 100));

    //设置返回按钮
    ui->backBtn->setStyleSheet("border:none;border-radius:10px;");
    ui->backBtn->setIcon(QIcon(QString("D:/Qt/Final_change/Game/uiProject/back.png")));
    ui->backBtn->setIconSize(QSize(250,250));

}

PauseWidget::~PauseWidget(){
    delete ui;
}


