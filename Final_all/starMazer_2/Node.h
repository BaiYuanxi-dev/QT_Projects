#ifndef NODE_H
#define NODE_H

#include <QPoint>

struct Node{
    int x, y;
    int icon;
    QPoint point;
    Node(int x, int y, int icon, QPoint point): x(x), y(y), icon(icon), point(point){};
};
#endif // NODE_H
