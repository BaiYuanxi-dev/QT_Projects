#include "entergamewidget.h"
#include "ui_entergamewidget.h"


/*
 * 构造函数
 * param: level 关卡数字
 * */
EnterGameWidget::EnterGameWidget(int level, QString *rankStr, int rankLen, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EnterGameWidget)
{
    ui->setupUi(this);
    this->level = level;
    this->rankStr = rankStr;
    this->rankLen= rankLen;
    startButton = new QPushButton;
}



EnterGameWidget::~EnterGameWidget()
{
    delete ui;
}

