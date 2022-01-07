#include "gameThree.h"
#include "ui_gameThree.h"


/**
 * @brief Widget::Widget: constructor function
 * @param parent
 */
gameThree::gameThree(QWidget *parent): QWidget(parent), ui(new Ui::gameThree){
    ui->setupUi(this);
    //�������������
    srand((unsigned int)time(nullptr));
    //����Ĭ���ٶ�
    curSpeed = this->fastSpeed;
    //��ʼ����
    this->score = 0;

    //���ñ���
    QPalette palette;
    QPixmap pixmap("E://uiProject//gameBackground.png");
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);

    //���ð�ť��ʽ��
    setStyleSheet("QPushButton:hover{background-color: rgb(255, 255, 255);border-radius:15px;border:none;color:rgb(255, 255, 255);}"
                  "QPushButton:checked{background-color: rgb(64, 65, 66);border:none;color:rgb(255, 255, 255);}");


    //��ʼ����ť�����С
    this->buttons.resize(gameSize);
    for(int i = 0; i < gameSize; i++)
        this->buttons[i].resize(gameSize);

    //Ϊÿһ����ť������ԣ�λ�ã�icon��slot������
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

    //������ͣ��ť
    ui->pauseBtn->setStyleSheet("border:none;border-radius:10px;");
    ui->pauseBtn->setIcon(QIcon(QString("E://uiProject//pauseBtn.png")));
    ui->pauseBtn->setIconSize(QSize(64, 62));

    //ÿ300����ִ����������
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(eraseBoxes()));
    timer->start(300);

    //��������ѭ������
    QtConcurrent::run([=](){
        myPlayer= new QMediaPlayer;
        myPlayer->setMedia(QUrl::fromLocalFile("E://uiProject//mp3//backgroundMusic.mp3"));
        myPlayer->setVolume(7);
        myPlayer->play();});

    //������
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
    this->dickNum = 100;
    ui->stepLabel->setStyleSheet("color:#ff6600;");
    ui->stepLabel->setText(QString(QString::fromStdString(std::to_string(this->restSteps))));

    ui->dicknumLabel->setText(QString(QString::fromStdString(std::to_string(this->dickNum))));

    this->flush = true;

    this->ui->endGameBtn->setVisible(false);
}

void gameThree::on_endGameBtn_clicked(){
    QTimer * t = new QTimer(end);
    connect(t, SIGNAL(timeout()), this, SLOT(checkIfBack()));
    t->start(300);
    myPlayer->stop();
    end->show();
}

void gameThree::on_progressBtn_clicked(){
    if(this->score < 5000){
        if(this->score / 50 > 100)
            ui->progressBar->setValue(100);
        else
            ui->progressBar->setValue(this->score / 50);
    }
    if(this->dickNum <= 0){
        end = new endGame(1);
        this->endGameFlag = true;
    }
}

/**
 * @brief Widget::~Widget: ��������
 */
gameThree::~gameThree(){
    delete ui;
}

void gameThree::checkIfBack(){
    if(this->end->end == 1){
        this->~gameThree();
    }
}
/**
 * @brief Widget::moveBtn: ��Btn��start�ƶ���end
 * @param btn
 * @param start
 * @param end
 * @param duration: animation�Ĳ���
 */
void gameThree::moveBtn(MyButton *btn, QPoint start, QPoint end, int duration){

    QPropertyAnimation * propertyAnimation = new QPropertyAnimation(btn, "pos");
    propertyAnimation->setDuration(duration);
    propertyAnimation->setStartValue(start);
    propertyAnimation->setEndValue(end);
    propertyAnimation->setEasingCurve(QEasingCurve::OutBack);
    propertyAnimation->start();
}

/**
 * @brief Widget::slotWhich2Change: �ж�������ť�Ƿ���Խ���
 * @param btn�� �ۺ����Ĳ���
 */
void gameThree::slotWhich2Change(MyButton * btn){
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

        //���������ť���Խ���
        if(checkIfCanBeChanged() != 0){
            if(this->restSteps == 0){
                end = new endGame(0);
                this->endGameFlag = true;
            }
            this->restSteps--;
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
 * @brief Widget::eraseBoxes: ������ǰ�������ŵķ���
 * @return true: ������
 *         false: û������
 */
bool gameThree::eraseBoxes(){
    //�Ƚ�������������button��icon����Ϊ-1
    flag = checkCurGUI();

    if(!flag)
        return false;

    //����iconΪ-1��button�����䶼std::swap��������϶�
    for(int i = 0; i < gameSize; i++)
        for(int j = 0; j < gameSize ; j++){
            if(buttons[j][i]->isErased == -1){
                if(buttons[j][i]->icon == 4){
                    if(dickNum == 0){
                        this->endGameFlag = true;
                        return true;
                    }
                    dickNum = dickNum - 1;
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
    //���²ۺ���
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

    //�滻����iconΪ-1��button, ����button��x, y���꣬�����ƶ����е�Button
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
 * @brief Widget::paintEvent: Ϊÿһ��������Ʊ���
 */
void gameThree::paintEvent(QPaintEvent *){
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
 * @brief Widget::checkIfChanged: �����ڵ�����¼������button�Ƿ���Խ���
 * @return true: ���Խ���
 *         false: �����Խ���
 */
bool gameThree::checkIfCanBeChanged(){
    int x1 = this->changePosVec[0]->x, x2 = this->changePosVec[1]->x;
    int y1 = this->changePosVec[0]->y, y2 = this->changePosVec[1]->y;

    //������ͬ���޷�����
    if(this->changePosVec[0]->icon == this->changePosVec[1]->icon)
        return false;

    //���������ŵ��޷�����
    if(abs(this->changePosVec[0]->x - this->changePosVec[1]->x) + abs(this->changePosVec[0]->y - this->changePosVec[1]->y) > 1)
        return false;

    //����֮���޷���������һ�л�����һ�е��޷�����
    //����������ܷ񽻻�
    std::swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
    int xx = 1, yy = 1;
    for(int i = x1 + 1; i < gameSize; i++){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon) xx++;
        else break;
    }
    for(int i = x1 - 1; i >= 0; i--){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon) xx++;
        else break;
    }
    for(int i = y1 + 1; i < gameSize; i++){
        if(buttons[i][x1]->icon == buttons[y1][x1]->icon) yy++;
        else break;
    }
    for(int i = y1 - 1; i >= 0; i--){
        if(buttons[i][x1]->icon == buttons[y1][x1]->icon) yy++;
        else break;
    }
    if(xx >= 3 || yy >= 3){
        std::swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
        return true;
    }
    xx = 1, yy = 1;
    for(int i = x2 + 1; i < gameSize; i++){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon) xx++;
        else break;
    }
    for(int i = x2 - 1; i >= 0; i--){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon) xx++;
        else break;
    }
    for(int i = y2 + 1; i < gameSize; i++){
        if(buttons[i][x2]->icon == buttons[y2][x2]->icon) yy++;
        else break;
    }
    for(int i = y2 - 1; i >= 0; i--){
        if(buttons[i][x2]->icon == buttons[y2][x2]->icon) yy++;
        else break;
    }
    if(xx >= 3 || yy >= 3){
        std::swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
        return true;
    }
    std::swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
    //��������㲻�ܽ���
    return false;
}
/**
 * @brief Widget::checkCurGUI: ��鵱ǰ�����Ƿ��п�����ȥ��, ����У������е�icon�滻Ϊ-1
 * @return
 */
bool gameThree::checkCurGUI(){
    flag = false;
    int allToErase = 0;
    for(int i = 0; i < gameSize; i++){
        for(int j = 0; j < gameSize; j++){
            if(this->buttons[i][j]->isErased == -1)
                continue;
            int x = 1, y = 1, curIcon = this->buttons[i][j]->icon;
            //������
            for(int k = j + 1; k < gameSize; k++){
                if(this->buttons[i][k]->icon == curIcon) x++;
                else break;
                }
            //������
            for(int k = j - 1; k >= 0; k--){
                if(this->buttons[i][k]->icon == curIcon) x++;
                else break;
            }
            //������
            for(int k = i + 1; k < gameSize; k++){
                if(this->buttons[k][j]->icon == curIcon) y++;
                else break;
            }
            //������
            for(int k = i - 1; k >= 0; k--){
                if(this->buttons[k][j]->icon == curIcon) y++;
                else break;
            }
            //��(i, j)������û����������������
            if(x < 3 && y < 3){
                continue;
            }
            //��(i, j)�����ݶ��д��ڵ���3��������
            //�Ƚ�icon����Ϊ-1
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


void gameThree::on_pauseBtn_clicked(){
    playMusic("popWindow.mp3");
    this->pauseWidget = new PauseWidget(this);

    int x = (pauseWidget->parentWidget()->width() - pauseWidget->width()) / 2;
    int y = (pauseWidget->parentWidget()->height() - pauseWidget->height()) / 2;

    pauseWidget->move(x, y);
    pauseWidget->show();
}

void gameThree::playMusic(QString s){
    QtConcurrent::run([=](){
        QMediaPlayer *myPlayer= new QMediaPlayer;
        myPlayer->setMedia(QUrl::fromLocalFile("E://uiProject//mp3//" + s));
        myPlayer->setVolume(7);
        myPlayer->play();});
}


void gameThree::on_pushButton_clicked(){
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

void gameThree::doMagic(){
    for(int i = 0; i < 6; i++){
        int x = rand() % gameSize;
        int y = rand() % gameSize;
        if((x==eggPosx&&y==eggPosy)||(x==eggPos1x&&y==eggPos1y)||(x==eggPos2x&&y==eggPos2y)||(x==eggPos3x&&y==eggPos3y)){
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


