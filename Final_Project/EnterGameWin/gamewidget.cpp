#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{

}


void GameWidget::closeEvent(QCloseEvent *event){
    emit this->backToMain();
}
