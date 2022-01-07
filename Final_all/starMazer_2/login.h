#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlTableModel>
#include "regis.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void sort(int column);
    void delect();
    int getInformation(int column);
    void changeInformation(int column,int num);
    int userColumn();
    QSqlTableModel *model;
    regis *regi;

    QString username;//设定登录的用户在可视化表中的第几行

private slots:
    void on_loginButton_clicked();

    void on_registerButton_clicked();

    void on_registerButton_pressed();

    void on_registerButton_released();

    void on_loginButton_pressed();

    void on_loginButton_released();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
