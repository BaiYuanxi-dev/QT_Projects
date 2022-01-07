#ifndef ENDGAME_H
#define ENDGAME_H

#include <QWidget>

namespace Ui {
class endGame;
}

class endGame : public QWidget
{
    Q_OBJECT

public:
    explicit endGame(QWidget *parent = nullptr);
    ~endGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::endGame *ui;
};

#endif // ENDGAME_H
