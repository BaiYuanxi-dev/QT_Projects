#ifndef ENDGAME_H
#define ENDGAME_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
namespace Ui {
class endGame;
}

class endGame : public QWidget
{
    Q_OBJECT

public:
    explicit endGame(QWidget *parent = nullptr);
    ~endGame();

    void paintEvent(QPaintEvent *event);
private slots:

private:
    Ui::endGame *ui;
    int num;
    const int x0 = 100;
    const int y0 = 350;
    QLabel **labels;
    QLabel *bonusLabel;
    QLabel *buttonLabel;

    QPushButton* button;

    void setLabels();
    void setButton();
    void setBonusLabel();
    void setButtonLabel();
    void showMove(QLabel *label);

};

#endif // ENDGAME_H
