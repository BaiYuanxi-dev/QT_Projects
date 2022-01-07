#include "mainwindow.h"
#include "ui_mainwindow.h"



mainWindow::mainWindow(QWidget *parent): QWidget(parent), ui(new Ui::mainWindow){
    ui->setupUi(this);
    QPalette palette;
    QPixmap pixmap("E://uiProject//background0.png");
    palette.setBrush(backgroundRole(), QBrush(pixmap));


    this->setPalette(palette);
    //设置最上方的“开心消消乐”字样
    ui->label->setStyleSheet("QLabel{background-image:url(E://uiProject//happy.png);"
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

    ui->classOne->setIcon(QIcon("E://uiProject//classOne.png"));
    ui->classOne->setIconSize(QSize(120, 120));
    ui->classOne->setStyleSheet("border:none");

    ui->classTwo->setIcon(QIcon("E://uiProject//classOne.png"));
    ui->classTwo->setIconSize(QSize(120, 120));
    ui->classTwo->setStyleSheet("border:none");

    ui->classThree->setIcon(QIcon("E://uiProject//classOne.png"));
    ui->classThree->setIconSize(QSize(120, 120));
    ui->classThree->setStyleSheet("border:none");

    ui->classFour->setIcon(QIcon("E://uiProject//classOne.png"));
    ui->classFour->setIconSize(QSize(120, 120));
    ui->classFour->setStyleSheet("border:none");

    ui->achiveButton->setIcon(QIcon("E:/uiProject/achive.png"));
    ui->achiveButton->setIconSize(QSize(80,80));
    ui->achiveButton->setStyleSheet("border-radius:35px;");
    ui->achiveButton->raise();

    ui->helpButton->setIcon(QIcon("E:/uiProject/help.png"));
    ui->helpButton->setIconSize(QSize(80,80));
    ui->helpButton->setStyleSheet("border-radius:35px;");
    ui->helpButton->raise();

    ui->infoButton->setIcon(QIcon("E:/uiProject/info.png"));
    ui->infoButton->setIconSize(QSize(80,80));
    ui->infoButton->setStyleSheet("border-radius:35px;");
    ui->infoButton->raise();

    ui->letterButton->setIcon(QIcon("E:/uiProject/letter.png"));
    ui->letterButton->setIconSize(QSize(80,80));
    ui->letterButton->setStyleSheet("border-radius:35px;");
    ui->letterButton->raise();

    ui->label_2->setStyleSheet("background-image:url(E:/uiProject/c.png)");
    ui->label_3->setStyleSheet("background-image:url(E:/uiProject/c.png)");
    ui->label_4->setStyleSheet("background-image:url(E:/uiProject/c.png)");
    ui->label_5->setStyleSheet("background-image:url(E:/uiProject/c.png)");

    setStyleSheet("QPushButton:hover{background-color: rgb(255, 238, 19);border-radius:50px;border:none;color:rgb(255, 238, 19);}"
                  "QPushButton:checked{background-color: rgb(64, 65, 66);border:none;color:rgb(255, 255, 255);}");


    //设置槽函数
    connect(ui->classOne,&QPushButton::clicked,this,&mainWindow::deal_classOne_Button);
    connect(ui->helpButton,&QPushButton::clicked,this,&mainWindow::deal_help_Button);
    connect(ui->infoButton,&QPushButton::clicked,this,&mainWindow::deal_info_Button);
    connect(ui->achiveButton,&QPushButton::clicked,this,&mainWindow::deal_achive_Button);

}

mainWindow::~mainWindow(){
    delete ui;
}

void mainWindow::on_classThree_clicked(){
    gameThree * g = new gameThree;
    g->show();
}

void mainWindow::deal_classOne_Button(){
    gameOne * g = new gameOne();
    g->show();
}

void mainWindow::on_classFour_clicked(){
    gameFour * g = new gameFour();
    g->show();
}

void mainWindow::on_classTwo_clicked(){
    gameTwo * g = new gameTwo();
    g->show();
}

void mainWindow::deal_help_Button(){
    helpFo = new helpForm();
    helpFo->show();
}

void mainWindow::deal_info_Button(){
    info = new class info(this);
    int x = (info->parentWidget()->width() - info->width()) / 2;
    int y = (info->parentWidget()->height() - info->height()) / 2;
    info->move(x, y);
    info->show();
}

void mainWindow::deal_achive_Button(){
    achive = new class achive(this);
    int x = (achive->parentWidget()->width() - achive->width()) / 2;
    int y = (achive->parentWidget()->height() - achive->height()) / 2;
    achive->move(x, y);
    achive->show();
}



