#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "listitem.h"
namespace Ui {
class MyListWidget;
}

class MyListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyListWidget(QWidget *parent = nullptr);
    ~MyListWidget();
    void add(QWidget *a);
private:
    Ui::MyListWidget *ui;
    QVBoxLayout* myLayOut;
    ListItem* listItem;
};

#endif // MYLISTWIDGET_H
