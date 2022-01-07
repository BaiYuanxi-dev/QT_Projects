#include "entergamewindow.h"
#include "ui_entergamewindow.h"

EnterGameWindow::EnterGameWindow(int level, QString *rankStr, QWidget *parent)
    : QMainWindow(parent)
{
    this->level = level;
    this->rankStr = rankStr;

    this->resize(800, 800);
    //rankWidget = new QListWidget;
    //setRankWidget();
    //this->addLayout();
    //rankWidget->show();
}

EnterGameWindow::~EnterGameWindow()
{
    //delete rankWidget;
    delete ui;
}

void EnterGameWindow::closeEvent(QCloseEvent *event){
    emit this->backToMain();
}

//void EnterGameWindow::setRankWidget(){
//    QListWidgetItem **items = new QListWidgetItem*[numOfRank+1];
//    QPixmap* pix;
//    QString str;
//    for(int i = 0; i < numOfRank; i ++){
//        pix = new QPixmap;
//        str = "image/rankImg/head (";
//        str += QString::number(i + 1);
//        str += ").jpg";
//        pix->load(str);

//        //items[i] = new QListWidgetItem(QIcon(*pix), "msg");
//        //ui->rankListWidget->addItem(items[i]);
//    }



//    for(int i = 0; i < numOfRank + 1; i++){
//        delete items[i];
//    }
//    delete[] items;


//}

