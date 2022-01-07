#include "entergamewin.h"
#include "ui_entergamewin.h"

//EnterGameWin::EnterGameWin(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::EnterGameWin)
//{
//    ui->setupUi(this);
//}


#include <string>
#include <QDebug>
#include <QIcon>
#include <QTimer>
#include <QTime>
#include  <QCoreApplication>
#include <QPainter>

/**
 * @brief EnterGameWidget::EnterGameWidget 构造函数
 * @param level 关卡
 * @param rankStr 排名字符串 排名字符串：id + 分数
 * @param numOfRank 排名的个数 默认8个
 * @param parent
 */
EnterGameWin::EnterGameWin(int level, QString *rankStr, int numOfRank, QWidget *parent):
    QWidget(parent),
    ui(new Ui::EnterGameWin){
    this->level = level;
    this->rankStr = rankStr;
    this->numOfRank = numOfRank;
    this->setFixedSize(350, 600);

    //设置排名界面
    rankWid = new RankWidget(rankStr, numOfRank, this);//排名窗口
    scrollArea = new QScrollArea(this);//滚动条创建
    scrollArea->setGeometry(35,220,280,350);
    scrollArea->setWidget(rankWid);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖向滚动条

    //设置进入界面
    enterGameWidget = new QWidget(this);//进入游戏窗口
    //进入游戏窗口背景图片
    enterGameWidget->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap("E://uiProject//enterImg//enterWidBackground2.png");
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    enterGameWidget->setPalette(palette);
    //TODO：游戏开始按钮设置，添加到新的方法中去
    gameStartButton = new MyPushButton("E://uiProject//enterImg//startButton.png","", enterGameWidget);
    enterGameWidget->setGeometry(75, 30, 200, 190);
    gameStartButton->move(50, 60);

    connect(gameStartButton, &QPushButton::clicked, this, [=](){
//        QTimer * timer = new QTimer(this);
//        connect(timer, SIGNAL(timeout()), this, SLOT(~EnterGameWidget()));
//        timer->start(400);
//        timer->setSingleShot(true);
        this->~EnterGameWin();
    });

}


EnterGameWin::~EnterGameWin(){
    gameStartButton->zoom1();
    QTimer::singleShot(400, this, [=](){
        this->rankStr->~QString();
        this->rankWid->~RankWidget();
        this->gameStartButton->~MyPushButton();
        this->enterGameWidget->~QWidget();
    });
    delete ui;
}

/**
 * @brief EnterGameWidget::paintEvent 背景
 * @param event
 */
void EnterGameWin::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load("E://uiProject//enterImg//background4.jpg");
    painter.drawPixmap(0, 0, pix);
}

/**
 * @brief EnterGameWidget::closeEvent关闭后发送信号
 * @param event
 */
void EnterGameWin::closeEvent(QCloseEvent *){
    emit this->backToMain();
}


