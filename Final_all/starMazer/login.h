#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlTableModel>
#include "regis.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void sort();
    void delect();
    QSqlTableModel *model;
    Regis *regi;

private slots:
    void on_loginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
