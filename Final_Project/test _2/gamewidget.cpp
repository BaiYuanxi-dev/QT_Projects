#include "gamewidget.h"
/**
 * @brief MainWindow::MainWindow: constructor function
 * @param parent
 */
GameWidget::GameWidget(QWidget *parent): QWidget(parent){
    //设置随机数种子
    srand((unsigned int)time(nullptr));

    //设置背景
    QPalette palette;
    QPixmap pixmap(":/image/gameImg/gameBackground.png");
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);

    //初始化按钮数组大小
    this->buttons.resize(8);
    for(int i = 0; i < 8; i++)
        this->buttons[i].resize(8);

    //为每一个按钮添加属性（位置，icon，slot函数）
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->buttons[i][j] = new MyButton(this, j, i, rand() % 5);
            connect(this->buttons[i][j], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[i][j]);});

            this->buttons[i][j]->resize(64 ,62);
            this->buttons[i][j]->move(this->x0 + j * 65, this->y0 + i * 63);
            this->buttons[i][j]->show();

            this->buttons[i][j]->setIcon(QIcon(QString(":/image/gameImg/box%0.png").arg(buttons[i][j]->icon)));
            this->buttons[i][j]->setIconSize(QSize(64, 62));
            this->buttons[i][j]->setStyleSheet("border:none");
            setStyleSheet("QPushButton:hover{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}"
                          "QPushButton:checked{background-color: rgb(64, 65, 66);border:none;color:rgb(255, 255, 255);}");
        }
    }
    //每300毫秒执行消除函数
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(eraseBoxes()));
    timer->start(300);
}
/**
 * @brief MainWindow::~MainWindow: 析构函数
 */
GameWidget::~GameWidget(){
}

void GameWidget::closeEvent(QCloseEvent *event){
    emit this->backToMain();
}
/**
 * @brief MainWindow::slotChangePos: 当点击了两个按钮之后，交换两个按钮的位置
 * @return void
 */
void GameWidget::slotChangePos(){
    int x1 = this->changePosVec[0]->x, x2 = this->changePosVec[1]->x;
    int y1 = this->changePosVec[0]->y, y2 = this->changePosVec[1]->y;
    QPropertyAnimation * propertyAnimation1 = new QPropertyAnimation(this->buttons[y1][x1], "pos");
    propertyAnimation1->setDuration(200);
    propertyAnimation1->setStartValue(this->changePosVec[0]->point);

    propertyAnimation1->setEndValue(this->changePosVec[1]->point);

    QPropertyAnimation * propertyAnimation2 = new QPropertyAnimation(this->buttons[y2][x2], "pos");
    propertyAnimation2->setDuration(200);

    propertyAnimation2->setStartValue(this->changePosVec[1]->point);
    propertyAnimation2->setEndValue(this->changePosVec[0]->point);
    propertyAnimation1->start();
    propertyAnimation2->start();

    swap(this->buttons[y1][x1]->x, this->buttons[y2][x2]->x);
    swap(this->buttons[y1][x1]->y, this->buttons[y2][x2]->y);
    swap(this->buttons[y1][x1], this->buttons[y2][x2]);

    disconnect(this->buttons[y1][x1], 0, 0, 0);
    disconnect(this->buttons[y2][x2], 0, 0, 0);

    connect(this->buttons[y1][x1], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[y1][x1]);});
    connect(this->buttons[y2][x2], &QPushButton::clicked, this, [=](){this->slotWhich2Change(this->buttons[y2][x2]);});
}
/**
 * @brief MainWindow::slotWhich2Change: 判断两个按钮是否可以交换
 * @param btn： 槽函数的参数
 */
void GameWidget::slotWhich2Change(MyButton * btn){

    if(this->changePosVec.empty()){
        this->changePosVec.push_back(new Node(btn->x, btn->y, btn->icon, btn->pos()));
        return;
    }
    else if(this->changePosVec.size() == 1){
        this->changePosVec.push_back(new Node(btn->x, btn->y, btn->icon, btn->pos()));
        //如果两个按钮可以交换
        if(checkIfCanBeChanged() != 0){
            slotChangePos();
        }
        this->changePosVec.clear();
    }else if(this->changePosVec.size() == 2){
        this->changePosVec.clear();
        this->changePosVec.push_back(new Node(btn->x, btn->y, btn->icon, btn->pos()));
    }
}
/**
 * @brief MainWindow::eraseBoxes: 消除当前所有连着的方块
 * @return true: 有消除
 *         false: 没有消除
 */
bool GameWidget::eraseBoxes(){
    //先将所有有相连的button的icon设置为-1
    flag = checkCurGUI();
    if(!flag)
        return false;

    //处理icon为-1的button，将其都swap到数组的上端
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8 ; j++)
            if(buttons[j][i]->icon == -1)
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

    //替换所有icon为-1的button, 更新button的x, y坐标，并且移动所有的Button
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(buttons[i][j]->icon != -1){
                QPropertyAnimation * propertyAnimation = new QPropertyAnimation(buttons[i][j], "pos");
                propertyAnimation->setDuration(150);
                propertyAnimation->setStartValue(buttons[i][j]->pos());
                propertyAnimation->setEndValue(QPoint(this->x0 + buttons[i][j]->x * 65, this->y0 + buttons[i][j]->y * 63));
                propertyAnimation->start();
            }
            if(buttons[i][j]->icon == -1){
                buttons[i][j]->icon = rand() % 5;
                buttons[i][j]->setIcon(QIcon(QString(":/image/gameImg/box%0.png").arg(buttons[i][j]->icon)));

                QPropertyAnimation * propertyAnimation = new QPropertyAnimation(buttons[i][j], "pos");
                propertyAnimation->setDuration(150);
                propertyAnimation->setStartValue(QPoint(buttons[i][j]->pos().x(), 0));
                propertyAnimation->setEndValue(QPoint(this->x0 + buttons[i][j]->x * 65, this->y0 + buttons[i][j]->y * 63));
                propertyAnimation->start();
            }
        }
    }
//    if(!flag) this->timer->stop();
    return flag;
}

/**
 * @brief MainWindow::paintEvent: 为每一个方块绘制背景
 */
void GameWidget::paintEvent(QPaintEvent *){
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
 * @brief MainWindow::checkIfChanged: 在相邻的情况下检查两个button是否可以交换
 * @return true: 可以交换
 *         false: 不可以交换
 */
bool GameWidget::checkIfCanBeChanged(){
    int x1 = this->changePosVec[0]->x, x2 = this->changePosVec[1]->x;
    int y1 = this->changePosVec[0]->y, y2 = this->changePosVec[1]->y;
    //两个相同的无法交换
    if(this->changePosVec[0]->icon == this->changePosVec[1]->icon)
        return false;
    //两个不挨着的无法交换
    if(abs(this->changePosVec[0]->x - this->changePosVec[1]->x) + abs(this->changePosVec[0]->y - this->changePosVec[1]->y) > 1)
        return false;
    //交换之后无法构成三个一行或三个一列的无法交换
    if(!check(x1, y1, x2, y2)){
        return false;
    }
    return true;
}
/**
 * @brief MainWindow::checkCurGUI: 检查当前界面是否有可以消去的
 * @return
 */
bool GameWidget::checkCurGUI(){
    flag = false;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(this->buttons[i][j]->icon == -1)
                continue;
            int x = 1, y = 1;
            //右向检查
            for(int k = j + 1; k < 8; k++){
                if(this->buttons[i][k]->icon == this->buttons[i][j]->icon){
                    x++;
                }else break;
            }
            //下向检查
            for(int k = i + 1; k < 8; k++){
                if(this->buttons[k][j]->icon == this->buttons[i][j]->icon){
                    y++;
                } else break;
            }
            //左向检查
            for(int k = j - 1; k >= 0; k--){
                if(this->buttons[i][k]->icon == this->buttons[i][j]->icon){
                    x++;
                } else break;
            }
            //上向检查
            for(int k = i - 1; k >= 0; k--){
                if(this->buttons[k][j]->icon == this->buttons[i][j]->icon){
                    y++;
                } else break;
            }
            //点(i, j)处横纵没有三个以上相连的
            if(x < 3 && y < 3){
                continue;
            }
            //点(i, j)处横纵都有大于等于3个相连的
            //先将icon设置为-1
            if(x >= 3){
                flag = true;
                for(int k = j; k < j + x; k++)
                    this->buttons[i][k]->icon = -1;
            }
            if(y >= 3){
                flag = true;
                for(int k = i; k < i + y; k++)
                    this->buttons[k][j]->icon = -1;
            }
        }
    }
    return flag;
}
/**
 * @brief MainWindow::check： 检查两个点能否交换
 * @param x1 第一个点的横坐标
 * @param y1 第一个点的纵坐标
 * @param x2 第二个点的横坐标
 * @param y2 第二个点的纵坐标
 * @return
 */
bool GameWidget::check(int x1, int y1, int x2, int y2){
    swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
    int xx = 1, yy = 1;
    for(int i = x1 + 1; i < 8; i++){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon)
            xx++;
        else break;
    }
    for(int i = x1 - 1; i >= 0; i--){
        if(buttons[y1][i]->icon == buttons[y1][x1]->icon)
            xx++;
        else break;
    }
    for(int i = y1 + 1; i < 8; i++){
        if(buttons[i][x1]->icon == buttons[y1][x1]->icon)
            yy++;
        else break;
    }
    for(int i = y1 - 1; i >= 0; i--){
        if(buttons[i][x1]->icon == buttons[y1][x1]->icon)
            yy++;
        else break;
    }

    if(xx >= 3 || yy >= 3){
        swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
        return true;
    }
    for(int i = x2 + 1; i < 8; i++){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon)
            xx++;
        else break;
    }
    for(int i = x2 - 1; i >= 0; i--){
        if(buttons[y2][i]->icon == buttons[y2][x2]->icon)
            xx++;
        else break;
    }
    for(int i = y2 + 1; i < 8; i++){
        if(buttons[i][x2]->icon == buttons[y2][x2]->icon)
            yy++;
        else break;
    }
    for(int i = y2 - 1; i >= 0; i--){
        if(buttons[i][x2]->icon == buttons[y2][x2]->icon)
            yy++;
        else break;
    }
    if(xx >= 3 || yy >= 3){
        swap(buttons[y1][x1]->icon, buttons[y2][x2]->icon);
        return true;
    }
    return false;
}
