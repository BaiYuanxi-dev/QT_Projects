#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>

class StartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StartWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

};

#endif // STARTWIDGET_H
