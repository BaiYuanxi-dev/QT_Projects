#include "gameTwo.h"
#include "ui_gameTwo.h"

/**
 * @brief Widget::Widget: constructor function
 * @param parent
 */
gameTwo::gameTwo(QWidget *parent): QWidget(parent), ui(new Ui::gameTwo){
    ui->setupUi(this);
    //设置随机数种子
    srand((unsigned int)time(nullptr));
    //设置默认速度
    curSpeed = this->fastSpeed;
    //初始分数
    this->score = 0;

    //设置背景
    QPalette palette;
    QPixmap pixmap("E://uiProject//gameBackground.png");
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);

    //设置按钮样式表
    setStyleSheet("QPushButton:hover{background-color: rgb(255, 255, 255);border-radius:15px;border:none;color:rgb(255, 255, 255);}"
                                "QPushButton:checked{background-color: rgb(64, 65, 66);border:none;color:rgb(255, 255, 255);}");

    //初始化按钮数组大小
    this->buttons.resize(10);
    for(int i = 0; i < 10; i++)
        this->buttons[i].resize(10);

    //为余下按钮添加属性（位置，icon，slot函数）
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            this->buttons[i][j] = new MyButton(this, j, i, rand() % 6);
            connect(this->buttons[i][j], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[i][j]);});
            this->buttons[i][j]->move(this->x0 + j * 65, this->y0 + i * 63);
            this->buttons[i][j]->setStyleSheet("border:none");
        }
    }

    //随机给七行八列放置豆子
    for(int i=0;i<12;i++){
        int m=rand()%9;
        int n=rand()%10;
        buttons[m][n]->icon=2000;
        buttons[m][n]->reset(0, 2000);
        connect(this->buttons[m][n], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[m][n]);});
        this->buttons[m][n]->move(this->x0 + n * 65, this->y0 + m * 63);
        this->buttons[m][n]->setStyleSheet("border:none");
    }

    //设置暂停按钮
    ui->pauseBtn->setStyleSheet("border:none;border-radius:10px;");
    ui->pauseBtn->setIcon(QIcon(QString("E://uiProject//pauseBtn.png")));
    ui->pauseBtn->setIconSize(QSize(64, 62));

    //每300毫秒执行消除函数
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(eraseBoxes()));
    timer->start(300);

    //背景音乐循环播放
    QtConcurrent::run([=](){
        myPlayer= new QMediaPlayer;
        myPlayer->setMedia(QUrl::fromLocalFile("E://uiProject//mp3//backgroundMusic.mp3"));
        myPlayer->setVolume(7);
        myPlayer->play();});

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
    ui->stepLabel->setText(QString(QString::fromStdString(std::to_string(this->restSteps))));

    this->stepLeft=0;
    QFont font ( "Microsoft YaHei", 14, 75);

    int countBeans=0;
    //计算图有几个beans
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10 ; j++){
            if(buttons[i][j]->icon==2000){
                countBeans++;
            }
        }
    }
    this->beans=countBeans;

    ui->beanLeft->setText(QString(QString::fromStdString(std::to_string(this->beans))));

    this->flush = true;

    this->ui->endGameBtn->setVisible(false);
}

void gameTwo::on_endGameBtn_clicked(){
    endGame * end = new endGame();

    end->show();
    myPlayer->stop();
}

void gameTwo::on_progressBtn_clicked(){
    if(this->score < 5000){
        if(this->score / 50 > 100)
            ui->progressBar->setValue(100);
        else
            ui->progressBar->setValue(this->score / 50);
    }
    else{
        this->endGameFlag = true;
    }
}

/**
 * @brief Widget::~Widget: 析构函数
 */
gameTwo::~gameTwo(){
    delete ui;
}

void gameTwo::checkIfBack(){
    if(this->end->end == 1){
        this->~gameTwo();
    }
}
/**
 * @brief Widget::moveBtn: 将Btn从start移动到end
 * @param btn
 * @param start
 * @param end
 * @param duration: animation的参数
 */
void gameTwo::moveBtn(MyButton *btn, QPoint start, QPoint end, int duration){
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
void gameTwo::slotWhich2Change(MyButton * btn){
    QtConcurrent::run([=](){
        QMediaPlayer *myPlayer= new QMediaPlayer;
        myPlayer->setMedia(QUrl::fromLocalFile("E://uiProject//mp3//click.mp3"));
        myPlayer->setVolume(10);
        myPlayer->play();});
    if(this->changePosVec.empty()){
        this->changePosVec.push_back(new Node(btn->x, btn->y, btn->icon, btn->pos()));
        return;
    }
    else if(this->changePosVec.size() == 1){
        if(this->restSteps == 0){
            end = new endGame(0);
            this->endGameFlag = true;
        }
        this->restSteps--;
        this->stepLeft++;
        ui->stepLabel->setText(QString(QString::fromStdString(std::to_string(this->restSteps))));

        this->changePosVec.push_back(new Node(btn->x, btn->y, btn->icon, btn->pos()));
        //如果两个按钮可以交换
        if(checkIfCanBeChanged() != 0){

            int x1 = this->changePosVec[0]->x, x2 = this->changePosVec[1]->x;
            int y1 = this->changePosVec[0]->y, y2 = this->changePosVec[1]->y;

            moveBtn(this->buttons[y1][x1], this->changePosVec[0]->point, this->changePosVec[1]->point, curSpeed);
            moveBtn(this->buttons[y2][x2], this->changePosVec[1]->point, this->changePosVec[0]->point, curSpeed);

            std::swap(this->buttons[y1][x1]->x, this->buttons[y2][x2]->x);
            std::swap(this->buttons[y1][x1]->y, this->buttons[y2][x2]->y);
            std::swap(this->buttons[y1][x1], this->buttons[y2][x2]);

            disconnect(this->buttons[y1][x1], 0, 0, 0);
            disconnect(this->buttons[y2][x2], 0, 0, 0);

            connect(this->buttons[y1][x1], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[y1][x1]);});
            connect(this->buttons[y2][x2], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[y2][x2]);});
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
bool gameTwo::eraseBoxes(){
    //先将所有有相连的button的icon设置为-1
    flag = checkCurGUI();
    //判断
    int tag = 0;


    //循环判断，最后一行若有豆子设isErased=-1
    for(int i = 0; i < 10; i++ ){
        if(buttons[9][i]->icon==2000){
            this->buttons[9][i]->isErased = -1;
            tag = 1;
            this->beans--;
            ui->beanLeft->setText(QString(QString::fromStdString(std::to_string(this->beans))));
            stepLeft=0;

        }
    }


    //若最后一行没有豆子且其他地方没有相连
    if(tag == 0){
        if(!flag)
            return false;
    }

    //处理icon为-1的button，将其都std::swap到数组的上端
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10 ; j++)
            if(buttons[j][i]->isErased == -1)
                for(int n = j; n > 0; n--)
                    std::swap(buttons[n][i], buttons[n - 1][i]);

    //更新槽函数
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            buttons[i][j]->x = j;
            buttons[i][j]->y = i;
            disconnect(buttons[i][j], 0, 0, 0);
            connect(buttons[i][j], &QPushButton::clicked, this, [=](){this->slotWhich2Change(buttons[i][j]);});
        }
    }

    //替换所有icon为-1的button, 更新button的x, y坐标，并且移动所有的Button
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(buttons[i][j]->isErased != -1)
                moveBtn(buttons[i][j], buttons[i][j]->pos(), QPoint(this->x0 + buttons[i][j]->x * 65, this->y0 + buttons[i][j]->y * 63), curSpeed);
            if(buttons[i][j]->isErased == -1){
                buttons[i][j]->reset(0);
                moveBtn(buttons[i][j], QPoint(this->x0 + buttons[i][j]->x * 65, 0), QPoint(this->x0 + buttons[i][j]->x * 65, this->y0 + buttons[i][j]->y * 63), curSpeed);
            }
        }
    }
    return flag;
}

/**
 * @brief Widget::paintEvent: 为每一个方块绘制背景
 */
void gameTwo::paintEvent(QPaintEvent *){
    QPainter * painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(QColor(28, 46, 70), 2));
    painter->setBrush(QColor(28, 46, 70));
    for(int i = 0; i < 10; i++){
        for(int j= 0; j < 10; j++){
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
bool gameTwo::checkIfCanBeChanged(){
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
    std::swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
    int xx = 1, yy = 1;
    for(int i = x1 + 1; i < 10; i++){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon&&buttons[y1][x1]->icon!=2000) xx++;
        else break;
    }
    for(int i = x1 - 1; i >= 0; i--){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon&&buttons[y1][x1]->icon!=2000) xx++;
        else break;
    }
    for(int i = y1 + 1; i < 10; i++){
        if(buttons[i][x1]->icon == buttons[y1][x1]->icon&&buttons[y1][x1]->icon!=2000) yy++;
        else break;
    }
    for(int i = y1 - 1; i >= 0; i--){
        if(buttons[i][x1]->icon == buttons[y1][x1]->icon&&buttons[y1][x1]->icon!=2000) yy++;
        else break;
    }
    if(xx >= 3 || yy >= 3){
        std::swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
        return true;
    }
    xx = 1, yy = 1;
    for(int i = x2 + 1; i < 10; i++){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon&&buttons[y2][x2]->icon!=2000) xx++;
        else break;
    }
    for(int i = x2 - 1; i >= 0; i--){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon&&buttons[y2][x2]->icon!=2000) xx++;
        else break;
    }
    for(int i = y2 + 1; i < 10; i++){
        if(buttons[i][x2]->icon == buttons[y2][x2]->icon&&buttons[y2][x2]->icon!=2000) yy++;
        else break;
    }
    for(int i = y2 - 1; i >= 0; i--){
        if(buttons[i][x2]->icon == buttons[y2][x2]->icon&&buttons[y2][x2]->icon!=2000) yy++;
        else break;
    }
    if(xx >= 3 || yy >= 3){
        std::swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
        return true;
    }
    std::swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
    //如果两个点不能交换
    return false;
}
/**
 * @brief Widget::checkCurGUI: 检查当前界面是否有可以消去的, 如果有，将所有的icon替换为-1
 * @return
 */
bool gameTwo::checkCurGUI(){
    flag = false;
    int allToErase = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(this->buttons[i][j]->isErased == -1)
                continue;
            int x = 1, y = 1, curIcon = this->buttons[i][j]->icon;


            //右向检查
            for(int k = j + 1; k < 10; k++){
                if(this->buttons[i][k]->icon == curIcon &&this->buttons[i][k]->icon!=2000) x++;
                else break;
            }
            //左向检查
            for(int k = j - 1; k >= 0; k--){
                if(this->buttons[i][k]->icon == curIcon&&this->buttons[i][k]->icon!=2000) x++;
                else break;
            }
            //下向检查
            for(int k = i + 1; k < 10; k++){
                if(this->buttons[k][j]->icon == curIcon&&this->buttons[k][j]->icon!=2000) y++;
                else break;
            }
            //上向检查
            for(int k = i - 1; k >= 0; k--){
                if(this->buttons[k][j]->icon == curIcon&&this->buttons[k][j]->icon!=2000) y++;
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
                for(int k = j + 1; k < 10; k++){
                    if(buttons[i][k]->icon == curIcon)
                        this->buttons[i][k]->isErased = -1;
                    else break;
                }
                for(int k = j; k >= 0; k--){
                    if(buttons[i][k]->icon == curIcon)
                        this->buttons[i][k]->isErased = -1;
                    else break;
                }
            }
            if(y >= 3){
                flag = true;
                for(int k = i + 1; k < 10; k++){
                    if(buttons[k][j]->icon == curIcon)
                        this->buttons[k][j]->isErased = -1;
                    else break;
                }
                for(int k = i; k >= 0; k--){
                    if(buttons[k][j]->icon == curIcon)
                        this->buttons[k][j]->isErased = -1;
                    else break;
                }
            }
            if(x >= 3 || y >= 3){
                x = x < 3 ? 0 : x;
                y = y < 3 ? 0 : y;
                allToErase += x + y;
                this->score += (x + y) * (x + y) * 10;
                if(stepLeft==5){
                    this->score-=200;
                    int m=rand()%9;
                    int n=rand()%10;
                    bool flag1=true;
                    while(flag1)
                    {
                        if(buttons[m][n]->icon!=2000){
                            buttons[m][n]->reset(0, 2000);
                            connect(this->buttons[m][n], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[m][n]);});
                            this->buttons[m][n]->move(this->x0 + n * 65, this->y0 + m * 63);
                            this->buttons[m][n]->setStyleSheet("border:none");
                            flag1=false;
                        }
                    }
                    int countBeans=0;
                    //计算图有几个beans
                    for(int i = 0; i < 10; i++){
                        for(int j = 0; j < 10 ; j++){
                            if(buttons[i][j]->icon==2000){
                                countBeans++;
                            }
                        }
                    }
                    this->beans=countBeans;
                    ui->beanLeft->setText(QString(QString::fromStdString(std::to_string(this->beans))));
                    stepLeft=0;
                }
                this->ui->scoreNumLabel->setText(QString::fromStdString(std::to_string(this->score)));
            }
        }
    }
    if(allToErase > 5)
        playMusic("ding.mp3");
    else if(allToErase > 4)
        playMusic("unbelievable.mp3");
    if(flag)
        playMusic("erase.mp3");
    return flag;
}


void gameTwo::on_pauseBtn_clicked(){
    playMusic("popWindow.mp3");
    this->pauseWidget = new PauseWidget(this);

    int x = (pauseWidget->parentWidget()->width() - pauseWidget->width()) / 2;
    int y = (pauseWidget->parentWidget()->height() - pauseWidget->height()) / 2;

    pauseWidget->move(x, y);

    pauseWidget->show();
}

void gameTwo::playMusic(QString s){
        QtConcurrent::run([=](){
            QMediaPlayer *myPlayer= new QMediaPlayer;
            myPlayer->setMedia(QUrl::fromLocalFile("E://uiProject//mp3//" + s));
            myPlayer->setVolume(7);
            myPlayer->play();});
}

void gameTwo::on_pushButton_clicked(){

    //存储豆子的位置
    int store1[12];
    int store2[12];

    //随机给七行八列放置豆子
    for(int i=0;i<12;i++){
        int m=rand()%9;
        int n=rand()%10;
        store1[i]=m;
        store2[i]=n;
        this->buttons[m][n]->reset(1, 2000);
        connect(this->buttons[m][n], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[m][n]);});
    }

    //为余下按钮添加属性（位置，icon，slot函数）
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(judgeBean(i,j,store1,store2)){
                this->buttons[i][j]->reset(1);
                connect(this->buttons[i][j], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[i][j]);});
            }
        }
    }
    int countBeans=0;
    //计算图有几个beans
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10 ; j++){
            if(buttons[i][j]->icon==2000){
                countBeans++;
            }
        }
    }
    this->beans=countBeans;
    ui->beanLeft->setText(QString(QString::fromStdString(std::to_string(this->beans))));
}

bool gameTwo::judgeBean(int i,int j,int *store1,int *store2){
    for(int m=0;m<12;m++){
        if(i==store1[m]&&j==store2[m]){
            return false;
        }
    }
    return true;
}
