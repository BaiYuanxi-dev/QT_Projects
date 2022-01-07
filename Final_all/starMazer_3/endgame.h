#ifndef ENDWIDGET_H
#define ENDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

#include <QPauseAnimation>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QPainter>
namespace Ui {
class endGame;
}

/**
 * @brief The EndWidget class
 * 缁撴潫绐楀彛
 */
class endGame : public QWidget{
    Q_OBJECT

public:
    explicit endGame(int victflag = 1, QWidget *parent = nullptr);
    ~endGame();
    int end = 0;

    void paintEvent(QPaintEvent *event);
private slots:
    void deleteEnd();
private:
    Ui::endGame *ui;
    QString pathOfBLabel;
    int victFlag;
    int num;//鍔ㄧ敾鍥剧墖鏍囧織
    const int x0 = 100;//鍔ㄧ敾浣嶇疆甯搁噺
    const int y0 = 350;//鍔ㄧ敾浣嶇疆甯搁噺
    QLabel **labels;//鍔ㄧ敾鏍囩鏁扮粍
    QLabel *bonusLabel;//鑳滃埄鍥剧墖鏍囩
    QLabel *buttonLabel;//鎸夐挳鍥剧墖鏍囩

    QPushButton* button;//鎸夐挳

    void setButton();
    void showMove(QLabel *label);
};

#endif // ENDGAME_H
