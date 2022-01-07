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
    this->buttons.resize(gameSize);
    for(int i = 0; i < gameSize; i++)
        this->buttons[i].resize(gameSize);

    //为每一个按钮添加属性（位置，icon，slot函数）
    for(int i = 0; i < gameSize; i++){
        for(int j = 0; j < gameSize ; j++){
            this->buttons[i][j] = new MyButton(this, j, i, rand() % 5);
            connect(this->buttons[i][j], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[i][j]);});
            this->buttons[i][j]->move(this->x0 + j * 65, this->y0 + i * 63);
            this->buttons[i][j]->setStyleSheet("border:none");
        }
    }
    buttons[eggPosx][eggPosy]->reset(0,6);
    disconnect(this->buttons[eggPosx][eggPosy], 0, 0, 0);

    buttons[eggPos1x][eggPos1y]->reset(0,6);
    disconnect(this->buttons[eggPos1x][eggPos1y], 0, 0, 0);

    buttons[eggPos2x][eggPos2y]->reset(0,6);
    disconnect(this->buttons[eggPos2x][eggPos2y], 0, 0, 0);

    buttons[eggPos3x][eggPos3y]->reset(0,6);
    disconnect(this->buttons[eggPos3x][eggPos3y], 0, 0, 0);

    //随机给七行八列放置豆子
    for(int i=0;i<10;i++){
        int m=rand()%9;
        int n=rand()%10;
        if((m == eggPosx&& n == eggPosy) || (m == eggPos1x&& n == eggPos1y)|| (m == eggPos2x&& n == eggPos2y) || (m == eggPos3x&& n == eggPos3y)){
            i--;
            continue;
        }
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
    playMusic("backgroundMusic.mp3");

    //进度条
    QtConcurrent::run([=](){
        while(true){
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            emit(ui->progressBtn->click());
            if(this->endGameFlag){
                emit(ui->endGameBtn->click());
                break;
            }
        }});

    ui->progressBtn->setVisible(false);

    this->restSteps = 30;
    this->dickNum = 100;
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

    ui->beanLeft->setText(QString(QString::fromStdString(std::to_string(this->beans))));    ui->stepLabel->setStyleSheet("color:#ff6600;");
    ui->stepLabel->setText(QString(QString::fromStdString(std::to_string(this->restSteps))));
    ui->dicknumLabel->setText(QString(QString::fromStdString(std::to_string(this->dickNum))));

    this->flush = true;

    this->ui->endGameBtn->setVisible(false);
}

void gameTwo::on_endGameBtn_clicked(){
    timetEnd = new QTimer(end);
    connect(timetEnd, SIGNAL(timeout()), this, SLOT(checkIfBack()));
    timetEnd->start(300);
    end->show();
}

void gameTwo::on_progressBtn_clicked(){
    if(this->score < 5000){
        if(this->score / 50 > 100)
            ui->progressBar->setValue(100);
        else
            ui->progressBar->setValue(this->score / 50);
    }
    if(this->dickNum <= 0 && this->beans <= 0){
        end = new endGame(1);
        endGameFlag = true;
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
        this->changePosVec.push_back(new Node(btn->x, btn->y, btn->icon, btn->pos()));
        int x1 = this->changePosVec[0]->x, x2 = this->changePosVec[1]->x;
        int y1 = this->changePosVec[0]->y, y2 = this->changePosVec[1]->y;

        //如果两个按钮可以交换
        if(checkIfCanBeChanged() != 0){
            if(this->restSteps == 0){
                end = new endGame(0);
                this->endGameFlag = true;
            }
            this->restSteps--;
            this->stepLeft++;
            ui->stepLabel->setText(QString(QString::fromStdString(std::to_string(this->restSteps))));
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
    for(int i = 0; i < gameSize; i++)
        for(int j = 0; j < gameSize ; j++){
            if(buttons[j][i]->isErased == -1){
                if(buttons[j][i]->icon == 4){
                    dickNum = dickNum - 1;
                    if(dickNum <= 0)
                        dickNum = 0;
                    ui->dicknumLabel->setText(QString(QString::fromStdString(std::to_string(this->dickNum))));
                }
                if((i == eggPosx && j == eggPosy + 1)||(i == eggPosx + 1 && j == eggPosy)||(i == eggPosx - 1 &&j == eggPosy)||(i == eggPosx &&j == eggPosy - 1)){
                    magicFlag = true;}
                if((i == eggPos1x && j == eggPos1y + 1)||(i == eggPos1x + 1 && j == eggPos1y)||(i == eggPos1x - 1 &&j == eggPos1y)||(i == eggPos1x &&j == eggPos1y - 1)){
                    magicFlag1 = true;}
                if((i == eggPos2x && j == eggPos2y + 1)||(i == eggPos2x + 1 && j == eggPos2y)||(i == eggPos2x - 1 &&j == eggPos2y)||(i == eggPos2x &&j == eggPos2y - 1)){
                    magicFlag2 = true;}
                if((i == eggPos3x && j == eggPos3y + 1)||(i == eggPos3x + 1 && j == eggPos3y)||(i == eggPos3x - 1 &&j == eggPos3y)||(i == eggPos3x &&j == eggPos3y - 1)){
                    magicFlag3 = true;}

                for(int n = j; n > 0; n--){
                    if((i == eggPosx && n == eggPosy) || (n == eggPos1y && i == eggPos1x) || (n == eggPos2y && i == eggPos2x) || (n == eggPos3y && i == eggPos3x)){
                        continue;}
                    else if((i == eggPosx && n == eggPosy + 1) || (i == eggPos1x && n == eggPos1y + 1) || (i == eggPos2x && n == eggPos2y + 1) || (i == eggPos3x && n == eggPos3y + 1)){
                        std::swap(buttons[n][i], buttons[n - 2][i]);
                        continue;
                    }
                    std::swap(buttons[n][i], buttons[n - 1][i]);
                }
            }
        }
    //更新槽函数
    for(int i = 0; i < gameSize; i++){
        for(int j = 0; j < gameSize ; j++){
            if(!(i == eggPosx && j == eggPosy)&&!(i == eggPos1x && j == eggPos1y)&&!(i == eggPos2x && j == eggPos2y)&&!(i == eggPos3x && j == eggPos3y)){
                buttons[i][j]->x = j;
                buttons[i][j]->y = i;
                disconnect(buttons[i][j], 0, 0, 0);
                connect(buttons[i][j], &QPushButton::clicked, this, [=](){this->slotWhich2Change(buttons[i][j]);});
            }
        }
    }

    //替换所有icon为-1的button, 更新button的x, y坐标，并且移动所有的Button
    for(int i = 0; i < gameSize; i++){
        for(int j = 0; j < gameSize; j++){
            if(buttons[i][j]->isErased != -1){
                if(i == eggPosx && j == eggPosy){
                    if(magicFlag == true){
                        if(energyFlag == false){
                            this->buttons[eggPosx][eggPosy]->reset(0,7);
                            energyFlag = true;
                        }else{
                            this->buttons[eggPosx][eggPosy]->reset(0,6);
                            doMagic();
                            energyFlag = false;
                        }
                        magicFlag = false;
                    }
                }
                if(i == eggPos1x && j == eggPos1y){
                    if(magicFlag1 == true){
                        if(energyFlag1 == false){
                            this->buttons[eggPos1x][eggPos1y]->reset(0,7);
                            energyFlag1 = true;
                        }else{
                            this->buttons[eggPos1x][eggPos1y]->reset(0,6);
                            doMagic();
                            energyFlag1 = false;
                        }
                        magicFlag1 = false;
                    }
                }
                if(i == eggPos2x && j == eggPos2y){
                    if(magicFlag2 == true){
                        if(energyFlag2 == false){
                            this->buttons[eggPos2y][eggPos2x]->reset(0,7);
                            energyFlag2 = true;
                        }else{
                            this->buttons[eggPos2y][eggPos2x]->reset(0,6);
                            doMagic();
                            energyFlag2 = false;
                        }
                        magicFlag2 = false;
                    }
                }
                if(i == eggPos3x && j == eggPos3y){
                    if(magicFlag3 == true){
                        if(energyFlag3 == false){
                            this->buttons[eggPos3y][eggPos3x]->reset(0,7);
                            energyFlag3 = true;
                        }else{
                            this->buttons[eggPos3y][eggPos3x]->reset(0,6);
                            doMagic();
                            energyFlag3 = false;
                        }
                        magicFlag3 = false;
                    }
                }
                else{
                    moveBtn(buttons[i][j], buttons[i][j]->pos(), QPoint(this->x0 + buttons[i][j]->x * 65, this->y0 + buttons[i][j]->y * 63), curSpeed);
                }
            }else{
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
    for(int i = 0; i < gameSize; i++){
        for(int j= 0; j < gameSize; j++){
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
    for(int i = x1 + 1; i < gameSize; i++){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon&&buttons[y1][x1]->icon!=2000) xx++;
        else break;
    }
    for(int i = x1 - 1; i >= 0; i--){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon&&buttons[y1][x1]->icon!=2000) xx++;
        else break;
    }
    for(int i = y1 + 1; i < gameSize; i++){
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
    for(int i = x2 + 1; i < gameSize; i++){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon&&buttons[y2][x2]->icon!=2000) xx++;
        else break;
    }
    for(int i = x2 - 1; i >= 0; i--){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon&&buttons[y2][x2]->icon!=2000) xx++;
        else break;
    }
    for(int i = y2 + 1; i < gameSize; i++){
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
    for(int i = 0; i < gameSize; i++){
        for(int j = 0; j < gameSize; j++){
            if(this->buttons[i][j]->isErased == -1)
                continue;
            int x = 1, y = 1, curIcon = this->buttons[i][j]->icon;
            //右向检查
            for(int k = j + 1; k < gameSize; k++){
                if(this->buttons[i][k]->icon == curIcon&&buttons[i][k]->icon!=2000) x++;
                else break;
            }
            //左向检查
            for(int k = j - 1; k >= 0; k--){
                if(this->buttons[i][k]->icon == curIcon&&buttons[i][k]->icon!=2000) x++;
                else break;
            }
            //下向检查
            for(int k = i + 1; k < gameSize; k++){
                if(this->buttons[k][j]->icon == curIcon&&buttons[k][j]->icon!=2000) y++;
                else break;
            }
            //上向检查
            for(int k = i - 1; k >= 0; k--){
                if(this->buttons[k][j]->icon == curIcon&&buttons[k][j]->icon!=2000) y++;
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
                for(int k = j + 1; k < gameSize; k++){
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
                for(int k = i + 1; k < gameSize; k++){
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
                        if((x==eggPosx&&y==eggPosy)||(x==eggPos1x&&y==eggPos1y)||(x==eggPos2x&&y==eggPos2y)
                                ||(x==eggPos3x&&y==eggPos3y)||buttons[m][n]->icon!=2000){
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
                    if(this->beans <= 0){
                        this->beans = 0;
                    }
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
        if((m == eggPosx&& n == eggPosy) || (m == eggPos1x&& n == eggPos1y)
                || (m == eggPos2x&& n == eggPos2y) || (m == eggPos3x&& n == eggPos3y)){
            i--;
            continue;
        }
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
    if(this->flush){
        for(int i = 0; i < gameSize; i++)
            for(int j = 0; j < gameSize; j++)
                buttons[i][j]->reset(1);
        buttons[eggPosx][eggPosy]->reset(0, 6);
        buttons[eggPos1x][eggPos1y]->reset(0, 6);
        buttons[eggPos2x][eggPos2y]->reset(0, 6);
        buttons[eggPos3x][eggPos3y]->reset(0, 6);
    }
    this->flush = false;
}

void gameTwo::doMagic(){
    for(int i = 0; i < 8; i++){
        int x = rand() % gameSize;
        int y = rand() % gameSize;
        if((x==eggPosx && y==eggPosy)||(x==eggPos1x&&y==eggPos1y)||(x==eggPos2x&&y==eggPos2y)||(x==eggPos3x&&y==eggPos3y)||buttons[x][y]->icon==2000){
            i--;
            continue;
        }else if(buttons[x][y]->icon == 4){
            i--;
            continue;
        }
        else
            this->buttons[x][y]->reset(0,4);
    }
}

bool gameTwo::judgeBean(int i,int j,int *store1,int *store2){
    for(int m = 0; m < 12; m++){
        if(i == store1[m] && j == store2[m]){
            return false;
        }
    }
    return true;
}
void gameTwo::closeEvent(QCloseEvent* ){
    myPlayer->stop();
}


