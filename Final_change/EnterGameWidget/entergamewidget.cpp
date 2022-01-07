#include "entergamewidget.h"
#include "ui_entergamewidget.h"
#include <QPropertyAnimation>
#include <QTime>
#include <QCoreApplication>
EnterGameWidget::EnterGameWidget(QString* rankStr, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EnterGameWidget)
{


    ui->setupUi(this);
    rankWid = new RankWidget(rankStr);
    ui->scrollArea->setWidget(rankWid);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//���غ��������
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//�������������

    setButton();

    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        zoom1();
        zoom2();
        sleep(200);
    });
}

EnterGameWidget::~EnterGameWidget()
{
    delete ui;
}

/**
 * @brief EnterGameWidget::paintEvent ����
 * @param event
 */
void EnterGameWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load("E://uiProject//enterImg//background3.jpg");
    painter.drawPixmap(0, 0, pix);
}

void EnterGameWidget::setButton(){


//    ui->pushButton->setStyleSheet("QPushButton{border:0px;}");//�����ؼ��ϣ����򿴵��ľ��Ǿ����ˣ������ǲ�����ͼ����
//    ui->pushButton->setIcon(QPixmap("E://uiProject//enterImg//startButton.png"));
//    ui->pushButton->setIconSize(QPixmap("E://uiProject//enterImg//startButton.png").size());
//    ui->pushButton->resize(QPixmap("E://uiProject//enterImg//startButton.png").size());

    ui->pushButton->setFixedSize(QPixmap("E://uiProject//enterImg//startButton.png").size());
    ui->pushButton->setStyleSheet("border-image:url(E://uiProject//enterImg//startButton.png)");
}

//������
void EnterGameWidget::zoom1(){
    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->pushButton, "geometry");//��ʼ�������࣬��geometry�� ��ʾ�ھ��ο���

    animation1->setDuration(200);//����ʱ����

    animation1->setStartValue(QRect(ui->pushButton->x(), ui->pushButton->y(), ui->pushButton->width(), ui->pushButton->height()));

    animation1->setEndValue(QRect(ui->pushButton->x(), ui->pushButton->y() + 10, ui->pushButton->width(), ui->pushButton->height()));

    animation1->setEasingCurve(QEasingCurve::OutBounce);

    animation1->start();

    //delete  animation1;
}

//������
void EnterGameWidget::zoom2(){
    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->pushButton, "geometry");//��ʼ�������࣬��geometry�� ��ʾ�ھ��ο���

    animation2->setDuration(200);//����ʱ����

    animation2->setStartValue(QRect(ui->pushButton->x(), ui->pushButton->y() + 10, ui->pushButton->width(), ui->pushButton->height()));

    animation2->setEndValue(QRect(ui->pushButton->x(), ui->pushButton->y(), ui->pushButton->width(), ui->pushButton->height()));

    animation2->setEasingCurve(QEasingCurve::OutBounce);

    animation2->start();

    //delete  animation2;
}

void EnterGameWidget::sleep(unsigned int msec){
    QTime newTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < newTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
