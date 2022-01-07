#include "widget.h"
#include "ui_widget.h"
#include "pausewidget.h"
#include "ui_widget.h"
#include "endgame.h"

#include <QGraphicsOpacityEffect>
#include <QPainter>
#include <qpropertyanimation.h>

#include <iostream>
/**
 * @brief Widget::Widget: constructor function
 * @param parent
 */
Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget){
    ui->setupUi(this);
    //设置随机数种子
    srand((unsigned int)time(nullptr));
    //设置默认速度
    curSpeed = this->fastSpeed;
    //初始分数
    this->score = 0;

    this->numOfCircle = 0;

    //设置背景
    QPalette palette;
    QPixmap pixmap("D:/Qt/Final_Project2/Game4_3/uiProject/gameBackground.png");
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);

    //设置按钮样式表
    setStyleSheet("QPushButton:hover{background-color: rgb(255, 255, 255);border-radius:15px;border:none;color:rgb(255, 255, 255);}"
                                "QPushButton:checked{background-color: rgb(64, 65, 66);border:none;color:rgb(255, 255, 255);}");

    //初始化按钮数组大小
    this->buttons.resize(8);
    for(int i = 0; i < 8; i++)
        this->buttons[i].resize(8);

    this->labels.resize(8);
    for(int i = 0; i < 8; i++)
        this->labels[i].resize(8);

    int isCircleImg;
    int isIce;

    this->numOfIce = 0;



    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            isIce = rand() % 2;
            this->labels[i][j] = new MyLabel(this, j ,i, isIce);
            this->labels[i][j]->move(this->x0 + j * 65, this->y0 + i * 63);
            this->labels[i][j]->setStyleSheet("border:none");

        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            if(this->labels[i][j]->iceNum > 0){
                numOfIce++;
            }

        }
    }


    //为每一个按钮添加属性（位置，icon，slot函数）
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            isCircleImg = rand() % 2;
            if(isCircleImg == 1){
                numOfCircle++;
            }
            if(numOfCircle >= 9){
                isCircleImg = 0;
            }
            this->buttons[i][j] = new MyButton(this, j, i, rand() % 5);
            connect(this->buttons[i][j], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[i][j]);});
            this->buttons[i][j]->setFlag(isCircleImg);
            this->buttons[i][j]->move(this->x0 + j * 65, this->y0 + i * 63);
            this->buttons[i][j]->setStyleSheet("border:none");
            if( this->buttons[i][j]->flag == 1 ){
                this->buttons[i][j]->reset(this->buttons[i][j]->flag);
            }

            if( this->labels[i][j]->flag >= 1 ){
                this->buttons[i][j]->setIce(1);
                this->buttons[i][j]->setThisOpacity();
            }

        }
    }


    //设置暂停按钮
    ui->pauseBtn->setStyleSheet("border:none;border-radius:10px;");
    ui->pauseBtn->setIcon(QIcon(QString("D:/Qt/Final_Project2/Game4_3/uiProject/pauseBtn.png")));
    ui->pauseBtn->setIconSize(QSize(64, 62));

    //每300毫秒执行消除函数
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(eraseBoxes()));
    timer->start(600);

    //背景音乐循环播放
    playMusic("backgroundMusic.mp3");

    //进度条
    QtConcurrent::run([=](){
        while(true){
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            emit(ui->progressBtn->click());
            if(this->endGameFlag){
                emit(ui->endGameBtn->click());
                break;
            }
        }});
    ui->progressBtn->setVisible(false);

    this->restSteps = 30;
    ui->stepLabel->setStyleSheet("color:#ff6600;");
    ui->stepLabel->setText(QString(QString::fromStdString(to_string(this->restSteps))));

    ui->iceNum->setStyleSheet("color:blue");
    //ui->iceNum->setText("冰块数:");
    ui->iceNum->setText(ui->iceNum->text() + QString(QString::number(numOfIce)));
    this->flush = true;

    this->ui->endGameBtn->setVisible(false);
}

void Widget::on_endGameBtn_clicked(){
    endGame * end = new endGame();
    end->show();
//    this->~Widget();
}

void Widget::on_progressBtn_clicked(){
    if(this->score < 500){
        if(this->score / 20 > 100)
            ui->progressBar->setValue(100);
        else
            ui->progressBar->setValue(this->score / 20);
    }
    else{
        this->endGameFlag = true;
    }
}

/**
 * @brief Widget::~Widget: 析构函数
 */
Widget::~Widget(){
    delete ui;
}
/**
 * @brief Widget::moveBtn: 将Btn从start移动到end
 * @param btn
 * @param start
 * @param end
 * @param duration: animation的参数
 */
void Widget::moveBtn(MyButton *btn, QPoint start, QPoint end, int duration){
    QPropertyAnimation * propertyAnimation = new QPropertyAnimation(btn, "pos");
    propertyAnimation->setDuration(duration);
    propertyAnimation->setStartValue(start);
    propertyAnimation->setEndValue(end);
    propertyAnimation->setEasingCurve(QEasingCurve::OutBack);
    propertyAnimation->start();
}

/**
 * @brief Widget::slotWhich2Change: 判断两个按钮是否可以交换
 * @param btn： 槽函数的参数
 */
void Widget::slotWhich2Change(MyButton * btn){
    QtConcurrent::run([=](){
        QMediaPlayer *myPlayer= new QMediaPlayer;
        myPlayer->setMedia(QUrl::fromLocalFile("D:/Qt/Final_Project2/Game4_3/uiProject/mp3/click.mp3"));
        myPlayer->setVolume(10);
        myPlayer->play();});
    if(this->changePosVec.empty()){
        this->changePosVec.push_back(new Node(btn->x, btn->y, btn->icon, btn->pos()));
        return;
    }
    else if(this->changePosVec.size() == 1){
        this->restSteps--;

        this->numOfIce = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if ( labels[i][j]->iceNum > 0 ) {
                    this->numOfIce++;
                }
            }
        }
        ui->iceNum->setText(ui->iceNum->text().mid(0, 4) + QString(QString::number(numOfIce)));


        ui->stepLabel->setText(QString(QString::fromStdString(to_string(this->restSteps))));

        this->changePosVec.push_back(new Node(btn->x, btn->y, btn->icon, btn->pos()));
        //如果两个按钮可以交换
        if(checkIfCanBeChanged() != 0){

            int x1 = this->changePosVec[0]->x, x2 = this->changePosVec[1]->x;
            int y1 = this->changePosVec[0]->y, y2 = this->changePosVec[1]->y;

            moveBtn(this->buttons[y1][x1], this->changePosVec[0]->point, this->changePosVec[1]->point, curSpeed);
            moveBtn(this->buttons[y2][x2], this->changePosVec[1]->point, this->changePosVec[0]->point, curSpeed);

            swap(this->buttons[y1][x1]->x, this->buttons[y2][x2]->x);
            swap(this->buttons[y1][x1]->y, this->buttons[y2][x2]->y);
            swap(this->buttons[y1][x1], this->buttons[y2][x2]);

            disconnect(this->buttons[y1][x1], 0, 0, 0);
            disconnect(this->buttons[y2][x2], 0, 0, 0);

            connect(this->buttons[y1][x1], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[y1][x1]);});
            connect(this->buttons[y2][x2], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[y2][x2]);});

            eraseBoxes();


            //动画，渐变
            int initIcon;
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    initIcon = buttons[i][j]->icon;
                    if(buttons[i][j]->flag == 1){
                        do{
                            buttons[i][j]->icon = rand() % 5;
                        } while(buttons[i][j]->icon == initIcon);
                        buttons[i][j]->reset(buttons[i][j]->flag);
                    }
                }
            }
        }
        this->changePosVec.clear();
    }else if(this->changePosVec.size() == 2){
        this->changePosVec.clear();
        this->changePosVec.push_back(new Node(btn->x, btn->y, btn->icon, btn->pos()));
    }
}
/**
 * @brief Widget::eraseBoxes: 消除当前所有连着的方块
 * @return true: 有消除
 *         false: 没有消除
 */
bool Widget::eraseBoxes(){
    //先将所有有相连的button的icon设置为-1
    flag = checkCurGUI();

    if(!flag)
        return false;

    //处理icon为-1的button，将其都swap到数组的上端
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8 ; j++)
            if(buttons[j][i]->isErased == -1)
                for(int n = j; n > 0; n--)
                    swap(buttons[n][i], buttons[n - 1][i]);

    //更新槽函数
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            buttons[i][j]->x = j;
            buttons[i][j]->y = i;
            disconnect(buttons[i][j], 0, 0, 0);
            connect(buttons[i][j], &QPushButton::clicked, this, [=](){this->slotWhich2Change(buttons[i][j]);});
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->labels[i][j]->reset(this->labels[i][j]->iceNum);
        }
    }

    //替换所有icon为-1的button, 更新button的x, y坐标，并且移动所有的Button
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(buttons[i][j]->isErased != -1)
                moveBtn(buttons[i][j], buttons[i][j]->pos(), QPoint(this->x0 + buttons[i][j]->x * 65, this->y0 + buttons[i][j]->y * 63), curSpeed);
            if(buttons[i][j]->isErased == -1){
                buttons[i][j]->reset(0);
                moveBtn(buttons[i][j], QPoint(this->x0 + buttons[i][j]->x * 65, 0), QPoint(this->x0 + buttons[i][j]->x * 65, this->y0 + buttons[i][j]->y * 63), curSpeed);
            }
        }
    }

    this->numOfIce = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if( labels[i][j]->iceNum >= 1){
                buttons[i][j]->setIce(1);
                buttons[i][j]->setThisOpacity();
            } else {
                buttons[i][j]->setIce(0);
                buttons[i][j]->setThisOpacity();
            }
        }
    }
    return flag;
}

/**
 * @brief Widget::paintEvent: 为每一个方块绘制背景
 */
void Widget::paintEvent(QPaintEvent *){
    QPainter * painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(QColor(28, 46, 70), 2));
    painter->setBrush(QColor(28, 46, 70));
    for(int i = 0; i < 8; i++){
        for(int j= 0; j < 8; j++){
            painter->drawRect(QRect(this->x0 + j * 65, this->y0 + i * 63, 65, 63));
        }
    }
    painter->end();
}

/**
 * @brief Widget::checkIfChanged: 在相邻的情况下检查两个button是否可以交换
 * @return true: 可以交换
 *         false: 不可以交换
 */
bool Widget::checkIfCanBeChanged(){
    int x1 = this->changePosVec[0]->x, x2 = this->changePosVec[1]->x;
    int y1 = this->changePosVec[0]->y, y2 = this->changePosVec[1]->y;

    //两个相同的无法交换
    if(this->changePosVec[0]->icon == this->changePosVec[1]->icon)
        return false;

    //两个不挨着的无法交换
    if(abs(this->changePosVec[0]->x - this->changePosVec[1]->x) + abs(this->changePosVec[0]->y - this->changePosVec[1]->y) > 1)
        return false;

    //交换之后无法构成三个一行或三个一列的无法交换
    //检查两个点能否交换
    swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
    int xx = 1, yy = 1;
    for(int i = x1 + 1; i < 8; i++){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon) xx++;
        else break;
    }
    for(int i = x1 - 1; i >= 0; i--){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon) xx++;
        else break;
    }
    for(int i = y1 + 1; i < 8; i++){
        if(buttons[i][x1]->icon == buttons[y1][x1]->icon) yy++;
        else break;
    }
    for(int i = y1 - 1; i >= 0; i--){
        if(buttons[i][x1]->icon == buttons[y1][x1]->icon) yy++;
        else break;
    }
    if(xx >= 3 || yy >= 3){
        swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
        return true;
    }
    xx = 1, yy = 1;
    for(int i = x2 + 1; i < 8; i++){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon) xx++;
        else break;
    }
    for(int i = x2 - 1; i >= 0; i--){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon) xx++;
        else break;
    }
    for(int i = y2 + 1; i < 8; i++){
        if(buttons[i][x2]->icon == buttons[y2][x2]->icon) yy++;
        else break;
    }
    for(int i = y2 - 1; i >= 0; i--){
        if(buttons[i][x2]->icon == buttons[y2][x2]->icon) yy++;
        else break;
    }
    if(xx >= 3 || yy >= 3){
        swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
        return true;
    }
    swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
    //如果两个点不能交换
    return false;
}
/**
 * @brief Widget::checkCurGUI: 检查当前界面是否有可以消去的, 如果有，将所有的icon替换为-1
 * @return
 */
bool Widget::checkCurGUI(){
    flag = false;
    int allToErase = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(this->buttons[i][j]->isErased == -1)
                continue;
            int x = 1, y = 1, curIcon = this->buttons[i][j]->icon;
            //右向检查
            for(int k = j + 1; k < 8; k++){
                if(this->buttons[i][k]->icon == curIcon) x++;
                else break;
            }
            //左向检查
            for(int k = j - 1; k >= 0; k--){
                if(this->buttons[i][k]->icon == curIcon) x++;
                else break;
            }
            //下向检查
            for(int k = i + 1; k < 8; k++){
                if(this->buttons[k][j]->icon == curIcon) y++;
                else break;
            }
            //上向检查
            for(int k = i - 1; k >= 0; k--){
                if(this->buttons[k][j]->icon == curIcon) y++;
                else break;
            }
            //点(i, j)处横纵没有三个以上相连的
            if(x < 3 && y < 3){
                continue;
            }
            //点(i, j)处横纵都有大于等于3个相连的
            //先将icon设置为-1
            if(x >= 3){
                flag = true;
                for(int k = j + 1; k < 8; k++){
                    if(buttons[i][k]->icon == curIcon){
                        this->buttons[i][k]->isErased = -1;
                        this->labels[i][k]->iceNum--;
                    }
                    else break;
                }
                for(int k = j; k >= 0; k--){
                    if(buttons[i][k]->icon == curIcon){
                        this->buttons[i][k]->isErased = -1;
                        this->labels[i][k]->iceNum--;
                    }
                    else break;
                }
            }
            if(y >= 3){
                flag = true;
                for(int k = i + 1; k < 8; k++){
                    if(buttons[k][j]->icon == curIcon){
                        this->buttons[k][j]->isErased = -1;
                        this->labels[k][j]->iceNum--;
                    }

                    else break;
                }
                for(int k = i; k >= 0; k--){
                    if(buttons[k][j]->icon == curIcon){
                        this->buttons[k][j]->isErased = -1;
                        this->labels[k][j]->iceNum--;
                    }
                    else break;
                }
            }
            if(x >= 3 || y >= 3){
                x = x < 3 ? 0 : x;
                y = y < 3 ? 0 : y;
                allToErase += x + y;
                this->score += (x + y) * (x + y) * 10;
                this->ui->scoreNumLabel->setText(QString::fromStdString(to_string(this->score)));
            }
        }
    }
    if(allToErase > 5)
        playMusic("unbelievable.mp3");
    else if(allToErase > 4)
        playMusic("amazing.mp3");
    if(flag)
        playMusic("erase.mp3");
    return flag;
}


void Widget::on_pauseBtn_clicked(){
    playMusic("popWindow.mp3");
    pauseWidget.show();
}

void Widget::playMusic(QString s){
    QtConcurrent::run([=](){
        QMediaPlayer *myPlayer= new QMediaPlayer;
        myPlayer->setMedia(QUrl::fromLocalFile("D:/Qt/Final_Project2/Game4_3/uiProject/mp3/" + s));
        myPlayer->setVolume(7);
        myPlayer->play();});
}


void Widget::on_pushButton_clicked(){
    if(this->flush){
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                buttons[i][j]->reset(1);
    }
    this->flush = false;
}


