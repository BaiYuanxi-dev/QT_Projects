/********************************************************************************
** Form generated from reading UI file 'achive.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACHIVE_H
#define UI_ACHIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_achive
{
public:
    QLabel *achiveLabel_5;
    QLabel *achiveLabel_9;
    QLabel *achiveLabel_3;
    QLabel *achiveLabel_6;
    QLabel *achiveLabel_4;
    QLabel *achiveLabel_2;
    QLabel *achiveLabel_1;
    QLabel *achiveLabel_7;
    QLabel *achiveLabel_8;
    QPushButton *pushButton;

    void setupUi(QWidget *achive)
    {
        if (achive->objectName().isEmpty())
            achive->setObjectName(QString::fromUtf8("achive"));
        achive->resize(400, 650);
        achiveLabel_5 = new QLabel(achive);
        achiveLabel_5->setObjectName(QString::fromUtf8("achiveLabel_5"));
        achiveLabel_5->setGeometry(QRect(150, 282, 100, 100));
        achiveLabel_5->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/achive5before.png)"));
        achiveLabel_9 = new QLabel(achive);
        achiveLabel_9->setObjectName(QString::fromUtf8("achiveLabel_9"));
        achiveLabel_9->setGeometry(QRect(270, 430, 100, 100));
        achiveLabel_9->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/achive9before.png)"));
        achiveLabel_3 = new QLabel(achive);
        achiveLabel_3->setObjectName(QString::fromUtf8("achiveLabel_3"));
        achiveLabel_3->setGeometry(QRect(150, 132, 100, 100));
        achiveLabel_3->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/achive3before.png)"));
        achiveLabel_6 = new QLabel(achive);
        achiveLabel_6->setObjectName(QString::fromUtf8("achiveLabel_6"));
        achiveLabel_6->setGeometry(QRect(269, 282, 100, 100));
        achiveLabel_6->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/achive6before.png)"));
        achiveLabel_4 = new QLabel(achive);
        achiveLabel_4->setObjectName(QString::fromUtf8("achiveLabel_4"));
        achiveLabel_4->setGeometry(QRect(28, 282, 100, 100));
        achiveLabel_4->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/achive4before.png)"));
        achiveLabel_2 = new QLabel(achive);
        achiveLabel_2->setObjectName(QString::fromUtf8("achiveLabel_2"));
        achiveLabel_2->setGeometry(QRect(269, 132, 100, 100));
        achiveLabel_2->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/achive2before.png)"));
        achiveLabel_1 = new QLabel(achive);
        achiveLabel_1->setObjectName(QString::fromUtf8("achiveLabel_1"));
        achiveLabel_1->setGeometry(QRect(28, 132, 100, 100));
        achiveLabel_1->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/achive1before.png)"));
        achiveLabel_7 = new QLabel(achive);
        achiveLabel_7->setObjectName(QString::fromUtf8("achiveLabel_7"));
        achiveLabel_7->setGeometry(QRect(28, 430, 100, 100));
        achiveLabel_7->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/achive7before.png)"));
        achiveLabel_8 = new QLabel(achive);
        achiveLabel_8->setObjectName(QString::fromUtf8("achiveLabel_8"));
        achiveLabel_8->setGeometry(QRect(150, 430, 100, 100));
        achiveLabel_8->setStyleSheet(QString::fromUtf8("border-image:url(E:/uiProject/achive8before.png)"));
        pushButton = new QPushButton(achive);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 10, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//back1.png);\n"
"\n"
"border-radius:15px;\n"
"border:none;\n"
"color:rgb(255, 255, 255);"));

        retranslateUi(achive);

        QMetaObject::connectSlotsByName(achive);
    } // setupUi

    void retranslateUi(QWidget *achive)
    {
        achive->setWindowTitle(QApplication::translate("achive", "Form", nullptr));
        achiveLabel_5->setText(QString());
        achiveLabel_9->setText(QString());
        achiveLabel_3->setText(QString());
        achiveLabel_6->setText(QString());
        achiveLabel_4->setText(QString());
        achiveLabel_2->setText(QString());
        achiveLabel_1->setText(QString());
        achiveLabel_7->setText(QString());
        achiveLabel_8->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class achive: public Ui_achive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACHIVE_H
