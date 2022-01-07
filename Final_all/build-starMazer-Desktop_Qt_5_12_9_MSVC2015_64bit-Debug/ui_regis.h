/********************************************************************************
** Form generated from reading UI file 'regis.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIS_H
#define UI_REGIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regis
{
public:
    QPushButton *confirm;
    QLabel *user;
    QPushButton *head3;
    QLabel *password1;
    QPushButton *head5;
    QLineEdit *regisUsername;
    QLineEdit *regisPassword2;
    QPushButton *head4;
    QLabel *tips;
    QPushButton *head2;
    QTableView *tableView;
    QLabel *title;
    QPushButton *head6;
    QLabel *password2;
    QPushButton *cancel;
    QLabel *reigsBackground;
    QLineEdit *regisPassword1;
    QPushButton *head1;

    void setupUi(QWidget *regis)
    {
        if (regis->objectName().isEmpty())
            regis->setObjectName(QString::fromUtf8("regis"));
        regis->resize(559, 721);
        confirm = new QPushButton(regis);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setGeometry(QRect(0, 550, 281, 151));
        confirm->setStyleSheet(QString::fromUtf8(""));
        user = new QLabel(regis);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(320, 200, 421, 301));
        user->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//user.png);"));
        head3 = new QPushButton(regis);
        head3->setObjectName(QString::fromUtf8("head3"));
        head3->setGeometry(QRect(40, 420, 91, 91));
        head3->setStyleSheet(QString::fromUtf8(""));
        password1 = new QLabel(regis);
        password1->setObjectName(QString::fromUtf8("password1"));
        password1->setGeometry(QRect(330, 430, 401, 341));
        password1->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//password.png);"));
        head5 = new QPushButton(regis);
        head5->setObjectName(QString::fromUtf8("head5"));
        head5->setGeometry(QRect(430, 290, 91, 91));
        head5->setStyleSheet(QString::fromUtf8(""));
        regisUsername = new QLineEdit(regis);
        regisUsername->setObjectName(QString::fromUtf8("regisUsername"));
        regisUsername->setGeometry(QRect(190, 190, 181, 51));
        regisPassword2 = new QLineEdit(regis);
        regisPassword2->setObjectName(QString::fromUtf8("regisPassword2"));
        regisPassword2->setGeometry(QRect(190, 420, 181, 51));
        head4 = new QPushButton(regis);
        head4->setObjectName(QString::fromUtf8("head4"));
        head4->setGeometry(QRect(430, 180, 91, 91));
        head4->setStyleSheet(QString::fromUtf8(""));
        tips = new QLabel(regis);
        tips->setObjectName(QString::fromUtf8("tips"));
        tips->setGeometry(QRect(320, 480, 251, 91));
        tips->setStyleSheet(QString::fromUtf8("border-image: url(E://c//login//images//tips.png);"));
        head2 = new QPushButton(regis);
        head2->setObjectName(QString::fromUtf8("head2"));
        head2->setGeometry(QRect(40, 300, 91, 91));
        head2->setStyleSheet(QString::fromUtf8(""));
        tableView = new QTableView(regis);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(1131, 30, 20, 20));
        title = new QLabel(regis);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(70, 20, 421, 151));
        title->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//regisTitle.png);"));
        head6 = new QPushButton(regis);
        head6->setObjectName(QString::fromUtf8("head6"));
        head6->setGeometry(QRect(430, 410, 91, 91));
        head6->setStyleSheet(QString::fromUtf8(""));
        password2 = new QLabel(regis);
        password2->setObjectName(QString::fromUtf8("password2"));
        password2->setGeometry(QRect(330, 310, 401, 341));
        password2->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//password.png);"));
        cancel = new QPushButton(regis);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(290, 550, 271, 151));
        cancel->setStyleSheet(QString::fromUtf8(""));
        reigsBackground = new QLabel(regis);
        reigsBackground->setObjectName(QString::fromUtf8("reigsBackground"));
        reigsBackground->setGeometry(QRect(0, 0, 561, 721));
        reigsBackground->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//regisBackground3.png);"));
        regisPassword1 = new QLineEdit(regis);
        regisPassword1->setObjectName(QString::fromUtf8("regisPassword1"));
        regisPassword1->setGeometry(QRect(190, 300, 181, 51));
        head1 = new QPushButton(regis);
        head1->setObjectName(QString::fromUtf8("head1"));
        head1->setGeometry(QRect(40, 180, 91, 91));
        head1->setMouseTracking(false);
        head1->setToolTipDuration(-1);
        head1->setStyleSheet(QString::fromUtf8(""));
        head1->setCheckable(false);
        head1->setAutoExclusive(false);
        reigsBackground->raise();
        head3->raise();
        regisUsername->raise();
        regisPassword2->raise();
        tips->raise();
        head2->raise();
        tableView->raise();
        title->raise();
        head1->raise();
        password1->raise();
        regisPassword1->raise();
        confirm->raise();
        password2->raise();
        user->raise();
        head4->raise();
        head5->raise();
        head6->raise();
        cancel->raise();

        retranslateUi(regis);

        QMetaObject::connectSlotsByName(regis);
    } // setupUi

    void retranslateUi(QWidget *regis)
    {
        regis->setWindowTitle(QApplication::translate("regis", "Form", nullptr));
        confirm->setText(QString());
        user->setText(QString());
        head3->setText(QString());
        password1->setText(QString());
        head5->setText(QString());
        head4->setText(QString());
        tips->setText(QString());
        head2->setText(QString());
        title->setText(QString());
        head6->setText(QString());
        password2->setText(QString());
        cancel->setText(QString());
        reigsBackground->setText(QString());
#ifndef QT_NO_TOOLTIP
        head1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        head1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class regis: public Ui_regis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIS_H
