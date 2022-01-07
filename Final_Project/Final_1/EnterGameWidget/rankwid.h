#ifndef RANKWID_H
#define RANKWID_H

#include <QWidget>

namespace Ui {
class RankWid;
}

class RankWid : public QWidget
{
    Q_OBJECT

public:
    explicit RankWid(QWidget *parent = nullptr);
    ~RankWid();

private:
    Ui::RankWid *ui;
};

#endif // RANKWID_H
