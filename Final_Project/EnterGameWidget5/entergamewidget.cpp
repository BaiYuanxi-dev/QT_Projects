#include "entergamewidget.h"
#include "ui_entergamewidget.h"

EnterGameWidget::EnterGameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EnterGameWidget)
{
    ui->setupUi(this);
    this->resize(710, 850);
}

EnterGameWidget::~EnterGameWidget()
{
    delete ui;
}

