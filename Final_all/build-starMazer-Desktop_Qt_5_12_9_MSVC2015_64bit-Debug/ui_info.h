/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_info
{
public:
    QLabel *headLabel;
    QPushButton *pushButton;

    void setupUi(QWidget *info)
    {
        if (info->objectName().isEmpty())
            info->setObjectName(QString::fromUtf8("info"));
        info->resize(400, 650);
        headLabel = new QLabel(info);
        headLabel->setObjectName(QString::fromUtf8("headLabel"));
        headLabel->setGeometry(QRect(240, 100, 115, 115));
        headLabel->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/head1.png)"));
        pushButton = new QPushButton(info);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 10, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//back1.png);\n"
"\n"
"border-radius:15px;\n"
"border:none;\n"
"color:rgb(255, 255, 255);\n"
""));

        retranslateUi(info);

        QMetaObject::connectSlotsByName(info);
    } // setupUi

    void retranslateUi(QWidget *info)
    {
        info->setWindowTitle(QApplication::translate("info", "Form", nullptr));
        headLabel->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class info: public Ui_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
