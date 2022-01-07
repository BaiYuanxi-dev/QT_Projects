#include "rankwid.h"
#include "ui_rankwid.h"

RankWid::RankWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankWid)
{
    ui->setupUi(this);
}

RankWid::~RankWid()
{
    delete ui;
}
