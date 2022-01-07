#ifndef NEWTRY_H
#define NEWTRY_H

#include <QWidget>
#include <entergamewin.h>
class NewTry : public QWidget
{
    Q_OBJECT
public:
    explicit NewTry(QWidget *parent = nullptr);

    EnterGameWin *w;
signals:

};

#endif // NEWTRY_H
