#include "mainui.h"
#include "ui_mainui.h"
#include <QPropertyAnimation>


MainUI::MainUI(QWidget *parent): QWidget(parent), ui(new Ui::MainUI){
    ui->setupUi(this);
    QPalette palette;
    QPixmap pixmap(":/mainWindowImg/resource/mainWindowImg/background0.png");
    palette.setBrush(backgroundRole(), QBrush(pixmap));

    this->setPalette(palette);
    //设置最上方的“开心消消乐”字样
    ui->label->setStyleSheet("QLabel{"
                             "background-image:url(:/mainWindowImg/resource/mainWindowImg/happy.png);"
                             "background-position:center;"
                             "background-origin:content;"
                             "background-repeat:none;}");
    //scale
    QPropertyAnimation *pScaleAnimation1 = new QPropertyAnimation(ui->label, "geometry");
    /*  设置动画持续时长为 2 秒钟  */
    pScaleAnimation1->setDuration(1000);
    /*  设置动画的起始状态 起始点 (1,2)  起始大小 (3,4)  */
    pScaleAnimation1->setStartValue(QRect(0, 0, 0, 0));
    /*  设置动画的结束状态 结束点 (100,200)  结束大小 (300,400)  */
    pScaleAnimation1->setEndValue(QRect(0, 0, 650, 300));
    /*  设置动画效果  */
    pScaleAnimation1->setEasingCurve(QEasingCurve::Linear);
    /*  开始执行动画 QAbstractAnimation::DeleteWhenStopped 动画结束后进行自清理 */
    pScaleAnimation1->start(QAbstractAnimation::DeleteWhenStopped);

    ui->classOne->setIcon(QIcon(":/mainWindowImg/resource/mainWindowImg/classOne.png"));
    ui->classOne->setIconSize(QSize(120, 120));
    ui->classOne->setStyleSheet("border:none");

    ui->classTwo->setIcon(QIcon(":/mainWindowImg/resource/mainWindowImg/classTwo.png"));
    ui->classTwo->setIconSize(QSize(120, 120));
    ui->classTwo->setStyleSheet("border:none");

    ui->classThree->setIcon(QIcon(":/mainWindowImg/resource/mainWindowImg/classThree.png"));
    ui->classThree->setIconSize(QSize(120, 120));
    ui->classThree->setStyleSheet("border:none");

    ui->classFour->setIcon(QIcon(":/mainWindowImg/resource/mainWindowImg/classFour.png"));
    ui->classFour->setIconSize(QSize(120, 120));
    ui->classFour->setStyleSheet("border:none");

    ui->helpButton->setIcon(QIcon(":/mainWindowImg/resource/mainWindowImg/help.png"));
    ui->helpButton->setIconSize(QSize(80,80));
    ui->helpButton->setStyleSheet("border-radius:35px;");


    setStyleSheet("QPushButton:hover{background-color: rgb(255, 238, 19);border-radius:50px;border:none;color:rgb(255, 238, 19);}"
                  "QPushButton:checked{background-color: rgb(64, 65, 66);border:none;color:rgb(255, 255, 255);}");

    //设置槽函数
    connect(ui->classOne,&QPushButton::clicked,this,&MainUI::deal_classOne_Button);
    connect(ui->helpButton,&QPushButton::clicked,this,&MainUI::deal_help_Button);
}

MainUI::~MainUI(){
    delete ui;
}

void MainUI::deal_classOne_Button(){
    gameOne * w = new gameOne();
    w->show();
}

void MainUI::deal_help_Button(){
//    helpFo.show();
}
