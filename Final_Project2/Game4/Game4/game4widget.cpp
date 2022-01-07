#include "game4widget.h"
#include "ui_game4widget.h"

Game4Widget::Game4Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game4Widget)
{
    ui->setupUi(this);
}

Game4Widget::~Game4Widget()
{
    delete ui;
}

