#include "newtry.h"

NewTry::NewTry(QWidget *parent) : QWidget(parent)
{

    this->resize(400, 400);
    QString* str;//鎺掑悕瀛楃涓叉暟缁勶紝寰呰緭鍏
    str = new QString[8];
    for(int i = 0; i < 8; i ++){
        str[i] = " ZhaoHong  100000";
    }

    str[5] = " nimass l e    ";
    str[3] = "asdsad ascdxin";
    QPushButton *p = new QPushButton(this);

    p->move(100, 100);
    p->resize(100, 60);
    p->setText("open");
    p->show();

    QPushButton *q = new QPushButton(this);

    q->move(240, 100);
    q->resize(100, 60);
    q->setText("close");
    q->show();

    connect(p, &QPushButton::clicked, this, [=](){
        w = new EnterGameWin();
    });

    connect(q, &QPushButton::clicked, this, [=](){
        delete w;
    });
}
