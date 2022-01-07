#include "logwidget.h"

LogWidget::LogWidget(QWidget *parent) : QWidget(parent)
{
    this->show();
    logButton = new QPushButton("Logging");
    logButton->setParent(this);
    logButton->move(100, 100);
    logButton->resize(100, 50);
    logButton->show();
//    connect(logButton, &QPushButton::clicked, this, [=](){
//        emit this->log();
//    });
}
