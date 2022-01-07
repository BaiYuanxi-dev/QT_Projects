#include "endgame.h"
#include "ui_endgame.h"

/**
 * @brief EndGame::EndGame
 * @param parent
 */
endGame::endGame(QWidget *parent) :QWidget(parent),ui(new Ui::endGame){
    ui->setupUi(this);

    labels = new QLabel*[3];
    for(int i = 0; i <3; i ++){
        labels[i] = new QLabel(this);
    }
    setLabels();
    bonusLabel = new QLabel(this);
    button = new QPushButton(this);
    buttonLabel = new QLabel(this);

    setButton();
    setBonusLabel();
    setButtonLabel();
}

/**
 * @brief EndGame::~EndGame
 */
endGame::~endGame(){
    for(int i = 0; i <3; i ++){
        delete labels[i];
    }
    delete[] labels;
    delete  bonusLabel;
    delete  button;
    delete  buttonLabel;
    delete ui;
}

/**
 * @brief EndGame::paintEvent 绘制背景
 * @param event
 */
void endGame::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load("E://uiProject//endBk");
    pix.scaled(this->width(), this->height());
    painter.drawPixmap(0, 0, pix);
}

void endGame::deleteThis(){
    this->~endGame();
}

/**
 * @brief EndGame::setLabels
 * 设置动画标签
 */
void endGame::setLabels(){
    QPixmap pixmap("E://uiProject//star.png");
    labels[0]->move(100, 350);
    labels[1]->move(250, 250);
    labels[2]->move(400, 350);

    for(int i = 0; i < 3; i ++){
        labels[i]->setFixedSize(115,115);
        labels[i]->setScaledContents(true);
        pixmap = pixmap.scaled(labels[i]->width(), labels[i]->height());
        labels[i]->setPixmap(pixmap);
        labels[i]->setVisible(false);
    }
}

/**
 * @brief EndGame::setButton设置按钮
 */
void endGame::setButton(){
    button->move(240, 450);
    button->setFixedSize(QSize(300, 100));
    button->show();
    QPixmap pixmap;
    pixmap.load("E://uiProject//button.png");

    pixmap.scaled(300, 100);
    //TODO加载失败判定
    button->setFixedSize(pixmap.width(), pixmap.height());
    button->setStyleSheet("border-image: url(E://uiProject//button.png);");
    button->setIcon(pixmap);
    button->setIconSize(pixmap.size());
    connect(button, &QPushButton::clicked, this, [=](){
        for(int i = 0; i <3; i ++){
            labels[i]->show();
            showMove(labels[i]);
        }
        this->end = 1;
        QTimer::singleShot(500, this, SLOT(deleteThis()));
    });
}

void endGame::setBonusLabel(){
    QPixmap pixmap("E://uiProject//end.png");
    bonusLabel->move(100, 20);

    bonusLabel->setFixedSize(400,300);
    bonusLabel->setScaledContents(true);
    pixmap = pixmap.scaled(bonusLabel->width(), bonusLabel->height());
    bonusLabel->setPixmap(pixmap);
    bonusLabel->setVisible(false);
}

void endGame::setButtonLabel(){
    QPixmap pixmap("E://uiProject//buttonLabel.png");
    buttonLabel->move(140, 460);

    buttonLabel->setFixedSize(110,120);
    buttonLabel->setScaledContents(true);
    pixmap = pixmap.scaled(bonusLabel->width(), bonusLabel->height());
    buttonLabel->setPixmap(pixmap);
    buttonLabel->show();

}
void endGame::showMove(QLabel *label){
    QTimer *timer = new QTimer(this);
    num = 0;
    connect(timer, &QTimer::timeout, this, [=](){
        QString path;
        num++;
        if(num > 8){
            timer->stop();
        }
        path = "E://uiProject//bounce" + QString::number(num) + ".png" ;

        QPixmap pixmap(path);
        pixmap = pixmap.scaled(label->width(), label->height());
        label->setPixmap(pixmap);
    });
    timer->start(200);

    bonusLabel->setVisible(true);
    QGraphicsOpacityEffect * opa = new QGraphicsOpacityEffect(this);
    opa->setOpacity(0);
    this->setGraphicsEffect(opa);
    QPropertyAnimation * pro = new QPropertyAnimation(opa, "opacity", this);
    pro->setStartValue(0);
    pro->setEndValue(1);
    pro->setDuration(2000);
    pro->start();

}

