#ifndef GAME4WIDGET_H
#define GAME4WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Game4Widget; }
QT_END_NAMESPACE

class Game4Widget : public QWidget
{
    Q_OBJECT

public:
    Game4Widget(QWidget *parent = nullptr);
    ~Game4Widget();

private:
    Ui::Game4Widget *ui;
};
#endif // GAME4WIDGET_H
