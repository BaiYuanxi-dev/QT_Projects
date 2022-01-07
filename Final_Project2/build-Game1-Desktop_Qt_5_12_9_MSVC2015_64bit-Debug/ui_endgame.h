/********************************************************************************
** Form generated from reading UI file 'endgame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAME_H
#define UI_ENDGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_endGame
{
public:
    QLabel *label;
    QLabel *star2;
    QLabel *star1;
    QLabel *star3;
    QPushButton *pushButton;

    void setupUi(QWidget *endGame)
    {
        if (endGame->objectName().isEmpty())
            endGame->setObjectName(QString::fromUtf8("endGame"));
        endGame->resize(494, 555);
        endGame->setStyleSheet(QString::fromUtf8("background-color: #ffffcb"));
        label = new QLabel(endGame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 401, 121));
        label->setStyleSheet(QString::fromUtf8("border-image:url(\"E://uiProject//good.png\");"));
        star2 = new QLabel(endGame);
        star2->setObjectName(QString::fromUtf8("star2"));
        star2->setGeometry(QRect(190, 150, 121, 121));
        star2->setStyleSheet(QString::fromUtf8("border-image:url(\"E://uiProject//nullStar.png\");"));
        star1 = new QLabel(endGame);
        star1->setObjectName(QString::fromUtf8("star1"));
        star1->setGeometry(QRect(70, 210, 111, 121));
        star1->setStyleSheet(QString::fromUtf8("border-image:url(\"E://uiProject//nullStar.png\");"));
        star3 = new QLabel(endGame);
        star3->setObjectName(QString::fromUtf8("star3"));
        star3->setGeometry(QRect(320, 210, 121, 121));
        star3->setStyleSheet(QString::fromUtf8("border-image:url(\"E://uiProject//nullStar.png\");"));
        pushButton = new QPushButton(endGame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 360, 251, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(endGame);

        QMetaObject::connectSlotsByName(endGame);
    } // setupUi

    void retranslateUi(QWidget *endGame)
    {
        endGame->setWindowTitle(QApplication::translate("endGame", "Form", nullptr));
        label->setText(QString());
        star2->setText(QString());
        star1->setText(QString());
        star3->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class endGame: public Ui_endGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAME_H
