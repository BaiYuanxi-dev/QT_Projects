//#include "entergamewidget.h"

//EnterGameWidget::EnterGameWidget(QWidget *parent) : QWidget(parent)
//{

//}

#include "entergamewidget.h"
#include <string>
#include <QDebug>
#include <QIcon>
#include <QTimer>
#include <QTime>
#include  <QCoreApplication>
#include <QPainter>

//构造函数：中间窗口
EnterGameWidget::EnterGameWidget(int level, QString *rankStr, int numOfRank, QWidget *parent)
    : QWidget(parent)
{

    this->level = level;
    this->rankStr = rankStr;
    this->numOfRank = numOfRank;
    this->setFixedSize(350, 600);

    setRankWidget();
    setEnterWidget();
}

EnterGameWidget::~EnterGameWidget()
{

}

//重绘，设置背景图片
void EnterGameWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/resource/image/enterWidBk/background4.jpg");
    painter.drawPixmap(0, 0, pix);
}

//关闭窗口，弹出返回信号
void EnterGameWidget::closeEvent(QCloseEvent *event){
    emit this->backToMain();
}

//设置排名窗口
void EnterGameWidget::setRankWidget(){

    rankWid = new RankWidget(rankStr, numOfRank, this);//排名窗口
    scrollArea = new QScrollArea(this);//滚动条创建
    scrollArea->setGeometry(35,220,280,350);
    scrollArea->setWidget(rankWid);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖向滚动条
}

//设置进入游戏窗口
void EnterGameWidget::setEnterWidget(){
    enterGameWidget = new QWidget(this);//进入游戏窗口

    //进入游戏窗口背景图片
    enterGameWidget->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/Image/resource/image/enterWidBk/enterWidBackground2.png");
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    enterGameWidget->setPalette(palette);

    //TODO：游戏开始按钮设置，添加到新的方法中去
    gameStartButton = new MyPushButton(":/Image/resource/image/buttonImg/startButton.png","", enterGameWidget);

    enterGameWidget->setGeometry(75, 30, 200, 190);

    gameStartButton->move(50, 60);

    connect(gameStartButton, &QPushButton::clicked, this, [=](){
        gameStartButton->zoom1();
        gameStartButton->zoom2();

        sleep(500);
        emit this->gameIn();
    });
}

//暂停进程
void EnterGameWidget::sleep(unsigned int msec){
    QTime newTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < newTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
