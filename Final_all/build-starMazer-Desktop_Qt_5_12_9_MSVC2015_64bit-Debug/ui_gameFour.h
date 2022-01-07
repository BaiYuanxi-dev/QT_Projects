/********************************************************************************
** Form generated from reading UI file 'gameFour.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFOUR_H
#define UI_GAMEFOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameFour
{
public:
    QProgressBar *progressBar;
    QLabel *restStepLabel;
    QLabel *scoreNumLabel;
    QLabel *stepLabel;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pauseBtn;
    QPushButton *progressBtn;
    QPushButton *endGameBtn;
    QLabel *iceLabel;

    void setupUi(QWidget *gameFour)
    {
        if (gameFour->objectName().isEmpty())
            gameFour->setObjectName(QString::fromUtf8("gameFour"));
        gameFour->resize(728, 816);
        progressBar = new QProgressBar(gameFour);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(100, 120, 381, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        progressBar->setFont(font);
        progressBar->setStyleSheet(QString::fromUtf8("font:9pt;\n"
"	border-radius:5px;\n"
"	text-align:center;\n"
"	border:1px solid #E8EDF2;\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-color: rgb(169, 77, 23);\n"
"\n"
"border-radius:5px;\n"
"	background-color:rgb(169, 77, 23);\n"
""));
        progressBar->setValue(0);
        restStepLabel = new QLabel(gameFour);
        restStepLabel->setObjectName(QString::fromUtf8("restStepLabel"));
        restStepLabel->setGeometry(QRect(560, 10, 121, 131));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(20);
        restStepLabel->setFont(font1);
        restStepLabel->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//score.png);\n"
""));
        restStepLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        scoreNumLabel = new QLabel(gameFour);
        scoreNumLabel->setObjectName(QString::fromUtf8("scoreNumLabel"));
        scoreNumLabel->setGeometry(QRect(30, 140, 71, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(12);
        scoreNumLabel->setFont(font2);
        scoreNumLabel->setAlignment(Qt::AlignCenter);
        stepLabel = new QLabel(gameFour);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));
        stepLabel->setGeometry(QRect(581, 74, 81, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        stepLabel->setFont(font3);
        stepLabel->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(gameFour);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 10, 91, 101));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//bigBox.png);"));
        label_2 = new QLabel(gameFour);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 700, 681, 51));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//bottom.png);\n"
""));
        label = new QLabel(gameFour);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 110, 61, 21));
        label->setFont(font2);
        pushButton = new QPushButton(gameFour);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 700, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//flush.png);"));
        pauseBtn = new QPushButton(gameFour);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        pauseBtn->setGeometry(QRect(40, 20, 64, 62));
        pauseBtn->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0)"));
        progressBtn = new QPushButton(gameFour);
        progressBtn->setObjectName(QString::fromUtf8("progressBtn"));
        progressBtn->setGeometry(QRect(200, 30, 61, 61));
        endGameBtn = new QPushButton(gameFour);
        endGameBtn->setObjectName(QString::fromUtf8("endGameBtn"));
        endGameBtn->setGeometry(QRect(200, 30, 61, 61));
        iceLabel = new QLabel(gameFour);
        iceLabel->setObjectName(QString::fromUtf8("iceLabel"));
        iceLabel->setGeometry(QRect(330, 20, 71, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        iceLabel->setFont(font4);
        iceLabel->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//ice.png);"));
        iceLabel->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        retranslateUi(gameFour);

        QMetaObject::connectSlotsByName(gameFour);
    } // setupUi

    void retranslateUi(QWidget *gameFour)
    {
        gameFour->setWindowTitle(QApplication::translate("gameFour", "Form", nullptr));
        restStepLabel->setText(QString());
        scoreNumLabel->setText(QString());
        stepLabel->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        label->setText(QApplication::translate("gameFour", "\345\210\206 \346\225\260", nullptr));
        pushButton->setText(QString());
        pauseBtn->setText(QString());
        progressBtn->setText(QString());
        endGameBtn->setText(QString());
        iceLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameFour: public Ui_gameFour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFOUR_H
