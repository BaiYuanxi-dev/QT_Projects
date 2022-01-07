#include "mainwindow.h"
#include "ui_mainwindow.h"


mainWindow::mainWindow(QWidget *parent): QWidget(parent), ui(new Ui::mainWindow){
    ui->setupUi(this);
    QPalette palette;
    QPixmap pixmap("E://uiProject//background0.png");
    palette.setBrush(backgroundRole(), QBrush(pixmap));


    this->setPalette(palette);
    //设置最上方的“开心消消乐”字样
    //scale
    QPropertyAnimation *pScaleAnimation1 = new QPropertyAnimation(ui->label, "geometry");
    pScaleAnimation1->setDuration(2000);
    pScaleAnimation1->setStartValue(QRect(0, 0, 0, 0));
    pScaleAnimation1->setEndValue(QRect(0, 0, 650, 300));
    pScaleAnimation1->setEasingCurve(QEasingCurve::OutBounce);
    pScaleAnimation1->start(QAbstractAnimation::DeleteWhenStopped);

    setStyleSheet("QPushButton:hover{background-color: rgb(255, 238, 19);border-radius:50px;border:none;color:rgb(255, 238, 19);}"
                  "QPushButton:checked{background-color: rgb(64, 65, 66);border:none;color:rgb(255, 255, 255);}");

    //设置槽函数
    connect(ui->classOne,&QPushButton::clicked,this,&mainWindow::deal_classOne_Button);
    connect(ui->helpButton,&QPushButton::clicked,this,&mainWindow::deal_help_Button);
    connect(ui->infoButton,&QPushButton::clicked,this,&mainWindow::deal_info_Button);
    connect(ui->achiveButton,&QPushButton::clicked,this,&mainWindow::deal_achive_Button);

    ui->game1Btn->hide();
    ui->game2Btn->hide();
    ui->game3Btn->hide();
    ui->game4Btn->hide();
}

mainWindow::~mainWindow(){
    delete ui;
}

void mainWindow::on_classThree_clicked(){
    QString * str = new QString[8];
    for(int i = 0; i < 8; i ++){
        str[i] = " -  -";
    }
    EnterGameWin * enterWidget = new EnterGameWin(1, str, 8);
    enterWidget->show();
    QTimer * t = new QTimer(enterWidget);
    auto conn = std::make_shared<QMetaObject::Connection>();
    *conn = connect(t, &QTimer::timeout, this, [=](){
        if(enterWidget->close == 1){
            emit ui->game3Btn->click();
            disconnect(*conn);
        }
    });
    t->start(300);
}

void mainWindow::deal_classOne_Button(){

}

void mainWindow::on_classFour_clicked(){
    gameFour * g = new gameFour();
    g->show();
}

void mainWindow::on_classTwo_clicked(){
    gameThree * g = new gameThree();
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

void mainWindow::closeEvent(QCloseEvent* ){
    QApplication::exit(0);
}


void mainWindow::on_game1Btn_clicked(){
    gameOne * g = new gameOne();
    g->show();
}

void mainWindow::on_game2Btn_clicked(){
    gameTwo * g = new gameTwo();
    g->show();
}

void mainWindow::on_game3Btn_clicked(){
    gameThree * g = new gameThree();
    g->show();
}

void mainWindow::on_game4Btn_clicked(){
    gameFour * g = new gameFour();
    g->show();
}
