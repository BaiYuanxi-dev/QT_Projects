#include "endwidget.h"
#include "ui_endwidget.h"

/**
 * @brief EndWidget::EndWidget
 * @param victflag 如果victFlag 值为1，则成功。值为0（其他），则失败
 * @param parent
 */
EndWidget::EndWidget(int victflag, QWidget *parent) :QWidget(parent),ui(new Ui::EndWidget){
    ui->setupUi(this);
    this->victFlag = victflag;
    if(this->victFlag == 1){
        this->pathOfBLabel = "D:/Qt/Final_Project3/EndWidget/endImg/end.png" ;
    } else {
        this->pathOfBLabel = "D:/Qt/Final_Project3/EndWidget/endImg/fail2.png";
    }

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
 * @brief EndWidget::~EndWidget
 */
EndWidget::~EndWidget(){
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
 * @brief EndWidget::paintEvent 绘制背景
 * @param event
 */
void EndWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load("D:/Qt/Final_Project3/EndWidget/endImg/endBk.jpg");
    pix.scaled(this->width(), this->height());
    painter.drawPixmap(0, 0, pix);
}

/**
 * @brief EndWidget::setLabels
 * 设置动画标签
 */
void EndWidget::setLabels(){
    QString labelImg;
    labels[0]->move(100, 350);
    labels[1]->move(250, 250);
    labels[2]->move(400, 350);

    if(victFlag == 1){
        labelImg = "D:/Qt/Final_Project3/EndWidget/endImg/star.png";
        QPixmap pixmap(labelImg);
        for(int i = 0; i < 3; i ++){
            labels[i]->setFixedSize(115,115);
            labels[i]->setScaledContents(true);
            pixmap = pixmap.scaled(labels[i]->width(), labels[i]->height());
            labels[i]->setPixmap(pixmap);
            labels[i]->setVisible(false);
        }
    }


}

/**
 * @brief EndWidget::setButton设置按钮
 */
void EndWidget::setButton(){


    QPixmap pixmap;



    if(victFlag == 1){
        pixmap.load("D:/Qt/Final_Project3/EndWidget/endImg/button.png");
        button->move(240, 450);
        pixmap.scaled(150, 44);
    } else {
        pixmap.load("D:/Qt/Final_Project3/EndWidget/endImg/button2.png");
        button->move(215, 400);
        pixmap.scaled(200, 100);
    }

//    //TODO加载失败判定


    button->show();

    button->setFixedSize( pixmap.width(), pixmap.height());
    button->setStyleSheet("QPushButton{border:0px}");
    button->setIcon(pixmap);
    button->setIconSize(pixmap.size());

    connect(button, &QPushButton::clicked, this, [=](){


        if(victFlag == 1){
            for(int i = 0; i <3; i ++){
                labels[i]->show();
                showMove(labels[i]);
            }


        }

        bonusLabel->setVisible(true);

        QGraphicsOpacityEffect * opa = new QGraphicsOpacityEffect(bonusLabel);
        opa->setOpacity(0);
        bonusLabel->setGraphicsEffect(opa);
        QPropertyAnimation * pro = new QPropertyAnimation(opa, "opacity", bonusLabel);
        pro->setStartValue(0);
        pro->setEndValue(1);
        pro->setDuration(2000);
        pro->start();


    });
}

void EndWidget::setBonusLabel(){
    QPixmap pixmap(this->pathOfBLabel);
    if(victFlag == 1){
        bonusLabel->move(100, 20);
    } else {
        bonusLabel->move(100, 120);
    }


    if(this->victFlag == 1){
        bonusLabel->setFixedSize(400,300);
    }
    else {
        bonusLabel->setFixedSize(400, 200);
    }

    bonusLabel->setScaledContents(true);
    pixmap = pixmap.scaled(bonusLabel->width(), bonusLabel->height());
    bonusLabel->setPixmap(pixmap);
    bonusLabel->setVisible(false);

}

void EndWidget::setButtonLabel(){
    QPixmap pixmap("D:/Qt/Final_Project3/EndWidget/endImg/buttonLabel.png");
    buttonLabel->move(140, 460);


    buttonLabel->setFixedSize(110,120);
    buttonLabel->setScaledContents(true);
    pixmap = pixmap.scaled(bonusLabel->width(), bonusLabel->height());
    buttonLabel->setPixmap(pixmap);
    buttonLabel->show();

}
void EndWidget::showMove(QLabel *label){
    QTimer *timer = new QTimer(this);
    num = 0;
    connect(timer, &QTimer::timeout, this, [=](){
        QString path;
        num++;
        if(num > 8){
            timer->stop();
            this->num = 8;
        }
        path = "D:/Qt/Final_Project3/EndWidget/endImg/bounce" + QString::number(num) + ".png" ;

        QPixmap pixmap(path);
        pixmap = pixmap.scaled(label->width(), label->height());
        label->setPixmap(pixmap);
    });
    timer->start(200);



}

