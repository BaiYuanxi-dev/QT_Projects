/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QTableView *tableView;
    QLabel *background;
    QPushButton *loginButton;
    QLineEdit *password;
    QPushButton *registerButton;
    QLineEdit *username;
    QLabel *label;
    QTableView *tableView_2;
    QLabel *user;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(542, 650);
        tableView = new QTableView(Login);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(780, 410, 61, 31));
        background = new QLabel(Login);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(0, 0, 541, 651));
        background->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//loginBackground.png);"));
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(0, 470, 281, 151));
        loginButton->setStyleSheet(QString::fromUtf8(""));
        loginButton->setCheckable(false);
        loginButton->setAutoExclusive(false);
        password = new QLineEdit(Login);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(160, 340, 211, 51));
        QPalette palette;
        QBrush brush(QColor(170, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        password->setPalette(palette);
        registerButton = new QPushButton(Login);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(300, 420, 261, 151));
        registerButton->setStyleSheet(QString::fromUtf8(""));
        username = new QLineEdit(Login);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(160, 270, 211, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        username->setPalette(palette1);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 350, 331, 321));
        label->setStyleSheet(QString::fromUtf8("border-image: url(E://c//login//images//password.png);"));
        tableView_2 = new QTableView(Login);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(580, 110, 381, 371));
        user = new QLabel(Login);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(330, 280, 291, 291));
        user->setStyleSheet(QString::fromUtf8("border-image: url(E://c//login//images//user.png);"));
        tableView->raise();
        background->raise();
        loginButton->raise();
        password->raise();
        username->raise();
        label->raise();
        tableView_2->raise();
        user->raise();
        registerButton->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        background->setText(QString());
        loginButton->setText(QString());
        registerButton->setText(QString());
        label->setText(QString());
        user->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
