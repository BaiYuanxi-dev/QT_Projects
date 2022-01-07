#ifndef ENDGAME_H
#define ENDGAME_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

#include <QPauseAnimation>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QPainter>

namespace Ui {class endGame;}

/**
 * @brief The EndWidget class
 * 结束窗口
 */
class endGame : public QWidget{
    Q_OBJECT

public:
    int end = 0;
    explicit endGame(QWidget *parent = nullptr);
    ~endGame();
    Ui::endGame *ui;
    void paintEvent(QPaintEvent *event);
private slots:
   void deleteThis();
private:

    int num;//动画图片标志
    const int x0 = 100;//动画位置常量
    const int y0 = 350;//动画位置常量
    QLabel **labels;//动画标签数组
    QLabel *bonusLabel;//胜利图片标签
    QLabel *buttonLabel;//按钮图片标签

    QPushButton* button;//按钮


    void setLabels();
    void setButton();
    void setBonusLabel();
    void setButtonLabel();
    void showMove(QLabel *label);

};

#endif // ENDGAME_H
