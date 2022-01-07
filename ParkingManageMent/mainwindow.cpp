#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>

#include <QListWidget>
#include <QDockWidget>
#include <QPushButton>
#include <QMessageBox>
#include <sstream>
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QPalette>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    operate = "";
    empNo = new int[16];
    partingLot = new PartingLot(16);
    dialog = new MsgDialog;
    ui->setupUi(this);

    labels = new QLabel *[16];
    QLabel* tmpLabel;

    for( int i = 0; i < partingLot->getMaxSize(); i++){
        tmpLabel = new QLabel(this);
        //TODO....................................................................................................
        tmpLabel->setParent(this);
        labels[i] = tmpLabel;
    }

    ui->emptyNumLine->setReadOnly(true);
    ui->emptyNumLine->setText(QString::number(partingLot->getEmptySize()));

    ui->queueNumLine_2->setReadOnly(true);
    ui->queueNumLine_2->setText(QString::number(partingLot->getQueueLength()));

    InitSpace();//初始化车位GUI

    setStyles();
    //点击“进入等待”，车辆进入等待队列
    connect(ui->addQueueButton, &QPushButton::clicked, [=](){
        if ( ui->idLine->text().toStdString() == "" ) {
            QMessageBox::information(this, "warning", "Please input id of car");
            return;
        }
        partingLot->regist(ui->idLine->text().toStdString());
        ui->queueNumLine_2->setText(QString::number(partingLot->getQueueLength()));
        operate += ui->idLine->text().toStdString();
        operate += " 进入等待队列";
        operate += "\n";
        ui->textEdit->setText(QString::fromStdString(operate));
        ui->idLine->setText("");
    });

    //点击“进入车位”，应该先进行动画，结束后再入队
    connect(ui->addInSpaceButton, &QPushButton::clicked, [=](){
        QLabel* tmp;
        Position* position;
        if ( partingLot->enter(this->noIn) ) {
            QPixmap *pix1 = new QPixmap;
            pix1->load(":/road/Image/car2.png");

            tmp = labels[this->noIn - 1];
            tmp->setPixmap(*pix1);
            tmp->setScaledContents(true);
            tmp->show();
            tmp->move(305,512);
            tmp->resize(78,52);
            this->carMoveIn(noIn, tmp);
            partingLot->getPositionList()->getElement(this->noIn, position);
            ui->queueNumLine_2->setText(QString::number(partingLot->getQueueLength()));
            ui->emptyNumLine->setText(QString::number(partingLot->getEmptySize()));
            operate += position->getCar()->getId();
            operate += " 进入车位 ";
            stringstream intTostr;
            intTostr << this->noIn;
            operate += intTostr.str();
            operate += "\n";
            ui->textEdit->setText(QString::fromStdString(operate));
        } else {
            QMessageBox::critical(this, "critical", "停车场满或车位空");
        }

    });

    //点击“离开”
    connect(ui->outButton, &QPushButton::clicked, [=](){

        Position* aposition;
        try {
            aposition = partingLot->query(std::atoi(ui->noLine->text().toLatin1().data()));
        } catch (const char* error) {
            string s(error);
            if( s == "not found" ){
                QMessageBox::critical(this, "critical", "该车位为空");
                ui->noLine->setText("");
                return;
            }
        }


        if (ui->noLine->text().toStdString() == ""){
            QMessageBox::information(this, "warning", "Please input number of space where the car will go out");
            return;
        }


        string moneyMsg;
        moneyMsg = "车位 ";
        moneyMsg += ui->noLine->text().toStdString();
        string posStr = ui->noLine->text().toStdString();
        moneyMsg += "\n车量 ";
        moneyMsg += aposition->getCar()->getId();
        string idStr = aposition->getCar()->getId();
        moneyMsg += " 离开\n";

        double money = 0;
        money = partingLot->out(std::atoi(ui->noLine->text().toLatin1().data()));


        stringstream doubleToStr;
        doubleToStr <<"停车费用：" << money << " 元";
        moneyMsg += doubleToStr.str();


        if ( money == -1 ) {
            QMessageBox::critical(this, "critical", "该车位为空");
        } else{
            this->carMoveOut(std::atoi(ui->noLine->text().toLatin1().data()), labels[std::atoi(ui->noLine->text().toLatin1().data()) - 1]);
            ui->emptyNumLine->setText(QString::number(partingLot->getEmptySize()));
            QMessageBox::information(this, "info", QString::fromStdString(moneyMsg));
            operate += "车辆 ";
            operate += idStr;
            operate += " 从车位";
            operate += posStr;
            operate += "离开, ";
            operate += doubleToStr.str();
            operate += " \n";
            ui->textEdit->setText(QString::fromStdString(operate));

        }
        ui->noLine->setText("");

    });

    //点击“信息查询”，弹出dialog并显示信息。
    connect(ui->queryButton, &QPushButton::clicked,[=](){
        if ( ui->noLine->text().toStdString() == "" ) {
            QMessageBox::information(this, "warning", "请输入想要查询的位置信息");
            return;
        }
        this->no = std::atoi(ui->noLine->text().toLatin1().data());
        try {
            this->position = partingLot->query(this->no);
        } catch (const char* error) {
            string s(error);
            if( s == "not found" ){
                QMessageBox::critical(this, "critical", "该车位为空");
                ui->noLine->setText("");
                return;
            }
        }

        try {
            this->dialog->setTheDialog(this->position,this->no);
        } catch (const char* error) {
            string s2(error);
            if(s2 == "without car"){
                QMessageBox::critical(this, "critical", "该车位为空");
                ui->noLine->setText("");
                return;
            }
        }

        this->dialog->show();
        this->dialog->exec();
        ui->noLine->setText("");
    });

    connect(ui->exitButton, &QPushButton::clicked, [=](){
        exit(0);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}



//void MainWindow::on_exitButton_clicked()
//{
//    //exit(0);
//}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/road/Image/background.jpg");
    painter.drawPixmap(272, 0, pix);
}

//动画：点击“进入车位”按钮后，应当首先进行车辆移动的动画，
//对于每一个车位，应当设置一条路线
void MainWindow::carMoveIn(int spaceId, QLabel* label){
    ui->addInSpaceButton->setEnabled(false);
    ui->outButton->setEnabled(false);
    ui->queryButton->setEnabled(false);
    ui->exitButton->setEnabled(false);
    QPixmap *pix1 = new QPixmap;
    pix1->load(":/road/Image/car1.png");

    QMatrix leftmatrix;
    leftmatrix.rotate(90);

    QMatrix leftmatrix2;
    leftmatrix2.rotate(180);

    QMatrix leftmatrix3;
    leftmatrix3.rotate(270);

    while(label->x() <= 785){
        label->setGeometry(label->x()+10, label->y(), label->width(), label->height());
        sleep(40);
    }

    label->setPixmap(*pix1);
    label->setScaledContents(true);
    label->resize(52,78);
    label->move(840,478);
    sleep(40);

    if( spaceId >= 1 && spaceId <= 6 ){

        while(label->y() >= 25){
            label->setGeometry(label->x(), label->y() - 10, label->width(), label->height());
            sleep(40);
        }

        label->resize(78,52);
        label->setScaledContents(true);
        label->setPixmap(pix1->transformed(leftmatrix3,Qt::SmoothTransformation));
        label->move(805,14);


        while(label->x() >= xCord[spaceId - 1]){
            label->setGeometry(label->x() - 10, label->y(), label->width(), label->height());
            sleep(40);
        }

        label->setPixmap(pix1->transformed(leftmatrix2, Qt::SmoothTransformation));
        label->setScaledContents(true);
        label->resize(52,78);
        label->move(xCord[spaceId - 1], yCord[spaceId - 1]);


    } else if ( spaceId >= 7 && spaceId <= 12 ) {

        while(label->y() >= 296){
            label->setGeometry(label->x(), label->y() - 10, label->width(), label->height());
            sleep(40);
        }
        label->setPixmap(pix1->transformed(leftmatrix3, Qt::SmoothTransformation));
        //label->setScaledContents(true);
        label->resize(78,52);
        label->move(805,295);

        while(label->x() >= xCord[spaceId - 1] + 5){
            label->setGeometry(label->x() - 10, label->y(), label->width(), label->height());
            sleep(40);
        }

        label->setPixmap(*pix1);
        //label->setScaledContents(true);
        label->resize(52,78);
        label->move(xCord[spaceId - 1], yCord[spaceId - 1]);

    } else if ( spaceId >= 13 && spaceId <= 16 ){

        while(label->y() >= 296){
            label->setGeometry(label->x(), label->y() - 10, label->width(), label->height());
            sleep(40);
        }


        label->setPixmap(pix1->transformed(leftmatrix3,Qt::SmoothTransformation));
        //label->setScaledContents(true);
        label->resize(78,52);
        label->move(805,295);

        while(label->x() >= xCord[spaceId - 1] + 5){
            label->setGeometry(label->x() - 10, label->y(), label->width(), label->height());
            sleep(40);
        }
        label->setPixmap(pix1->transformed(leftmatrix2,Qt::SmoothTransformation));
        label->setScaledContents(true);
        label->resize(52,78);
        label->move(xCord[spaceId - 1], yCord[spaceId - 1]);
    }
    ui->addInSpaceButton->setEnabled(true);
    ui->outButton->setEnabled(true);
    ui->queryButton->setEnabled(true);
    ui->exitButton->setEnabled(true);


}


void MainWindow::carMoveOut(int spaceId, QLabel* label){
    ui->addInSpaceButton->setEnabled(false);
    ui->outButton->setEnabled(false);
    ui->queryButton->setEnabled(false);
    ui->exitButton->setEnabled(false);
    QPixmap *pix1 = new QPixmap;
    pix1->load(":/road/Image/car1.png");
    QMatrix leftmatrix;
    leftmatrix.rotate(90);

    QMatrix leftmatrix2;
    leftmatrix2.rotate(180);

    QMatrix leftmatrix3;
    leftmatrix3.rotate(270);

    if ( spaceId >= 1 && spaceId <= 6 ) {
        while(label->y() >= 19){
            label->setGeometry(label->x(), label->y() - 10, label->width(), label->height());
            sleep(40);
        }
        label->setPixmap(pix1->transformed(leftmatrix3,Qt::SmoothTransformation));
        label->setScaledContents(true);
        label->resize(78,52);
        label->move(xCord[spaceId - 1], 15);

        while ( label->x() >= 273 ) {
            label->setGeometry(label->x() - 10, label->y(), label->width(), label->height());
            sleep(40);
        }
        label->setVisible(false);

    } else if ( spaceId >= 7 && spaceId <= 12 ) {
        while(label->y() <= 256){
            label->setGeometry(label->x(), label->y() + 10, label->width(), label->height());
            sleep(40);
        }

        label->setPixmap(pix1->transformed(leftmatrix,Qt::SmoothTransformation));
        label->setScaledContents(true);
        label->resize(78,52);
        label->move(xCord[spaceId - 1], 291);

        while(label->x() <= 785){
            label->setGeometry(label->x()+10, label->y(), label->width(), label->height());
            sleep(40);
        }


        label->setPixmap(*pix1);
        label->setScaledContents(true);
        label->resize(52,78);
        label->move(840,248);
        sleep(40);


        while(label->y() >= 25){
            label->setGeometry(label->x(), label->y() - 10, label->width(), label->height());
            sleep(40);
        }

        label->resize(78,52);
        label->setScaledContents(true);
        label->setPixmap(pix1->transformed(leftmatrix3,Qt::SmoothTransformation));
        label->move(805,14);

        while ( label->x() >= 273 ) {
            label->setGeometry(label->x() - 10, label->y(), label->width(), label->height());
            sleep(40);
        }
        label->setVisible(false);

    }  else if ( spaceId >= 13 && spaceId <= 16 ) {
        while(label->y() >= 256){
            label->setGeometry(label->x(), label->y() - 10, label->width(), label->height());
            sleep(40);
        }

        label->setPixmap(pix1->transformed(leftmatrix,Qt::SmoothTransformation));
        label->setScaledContents(true);
        label->resize(78,52);
        label->move(xCord[spaceId - 1], 291);

        while(label->x() <= 785){
            label->setGeometry(label->x()+10, label->y(), label->width(), label->height());
            sleep(40);
        }


        label->setPixmap(*pix1);
        label->setScaledContents(true);
        label->resize(52,78);
        label->move(840,248);
        sleep(40);


        while(label->y() >= 25){
            label->setGeometry(label->x(), label->y() - 10, label->width(), label->height());
            sleep(40);
        }

        label->resize(78,52);
        label->setScaledContents(true);
        label->setPixmap(pix1->transformed(leftmatrix3,Qt::SmoothTransformation));
        label->move(805,14);

        while ( label->x() >= 273 ) {
            label->setGeometry(label->x() - 10, label->y(), label->width(), label->height());
            sleep(40);
        }
        label->setVisible(false);
    }
    ui->addInSpaceButton->setEnabled(true);
    ui->outButton->setEnabled(true);
    ui->queryButton->setEnabled(true);
    ui->exitButton->setEnabled(true);
}

void MainWindow::InitSpace(){
    Position* position;
    QLabel* tmpLabel;
    QPixmap *pix1 = new QPixmap;
    pix1->load(":/road/Image/car1.png");

    QPixmap *pix2 = new QPixmap;
    pix2->load(":/road/Image/car3.png");
    for(int i = 0;i < this->partingLot->getMaxSize(); i++){
        tmpLabel = labels[i];
        partingLot->getPositionList()->getElement(i+1, position);
        if ( !position->ifEmpty() ) {
            empNo[i] = 1;
            if( (i <= 5 && i >= 0) || (i >= 12 && i <= 15)){
                tmpLabel->setPixmap(*pix2);
                tmpLabel->setScaledContents(true);
                switch(i){
                case 0:
                    tmpLabel->setGeometry(295, 81, 52, 78);
                    tmpLabel->show();
                    break;
                case 1:
                    tmpLabel->setGeometry(380, 81, 52, 78);
                    tmpLabel->show();
                    break;
                case 2:
                    tmpLabel->setGeometry(468, 81, 52, 78);
                    tmpLabel->show();
                    break;
                case 3:
                    tmpLabel->setGeometry(563, 81, 52, 78);
                    tmpLabel->show();
                    break;
                case 4:
                    tmpLabel->setGeometry(658, 81, 52, 78);
                    tmpLabel->show();
                    break;
                case 5:
                    tmpLabel->setGeometry(760, 81, 52, 78);
                    tmpLabel->show();
                    break;
                case 12:
                    tmpLabel->setGeometry(343, 354, 52, 78);
                    tmpLabel->show();
                    break;
                case 13:
                    tmpLabel->setGeometry(460, 354, 52, 78);
                    tmpLabel->show();
                    break;
                case 14:
                    tmpLabel->setGeometry(574, 354, 52, 78);
                    tmpLabel->show();
                    break;
                case 15:
                    tmpLabel->setGeometry(690, 354, 52, 78);
                    tmpLabel->show();
                    break;
                }

            } else if ( i >= 6 && i <= 11){
                tmpLabel->setPixmap(*pix1);
                tmpLabel->setScaledContents(true);
                switch(i){
                case 6:
                    tmpLabel->setGeometry(295, 193, 52, 78);
                    tmpLabel->show();
                    break;
                case 7:
                    tmpLabel->setGeometry(380, 193, 52, 78);
                    tmpLabel->show();
                    break;
                case 8:
                    tmpLabel->setGeometry(468, 193, 52, 78);
                    tmpLabel->show();
                    break;
                case 9:
                    tmpLabel->setGeometry(563, 193, 52, 78);
                    tmpLabel->show();
                    break;
                case 10:
                    tmpLabel->setGeometry(658, 193, 52, 78);
                    tmpLabel->show();
                    break;
                case 11:
                    tmpLabel->setGeometry(760, 193, 52, 78);
                    tmpLabel->show();
                    break;
                }
            }
        } else {
            empNo[i] = 0;
        }
    }
}

void MainWindow::sleep(unsigned int msec){
    QTime newTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < newTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}



void MainWindow::setStyles(){
    QPalette palette;

    palette.setColor(QPalette::Text,Qt::red);

    ui->idLine->setPalette(palette);
    ui->noLine->setPalette(palette);
    ui->emptyNumLine->setPalette(palette);
    ui->queueNumLine_2->setPalette(palette);

    QPalette pal = ui->textEdit->palette();
    pal.setBrush(QPalette::Base, Qt::green);
    ui->textEdit->setPalette(pal);

    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximumHeight());
    ui->textEdit->setReadOnly(true);
 }





