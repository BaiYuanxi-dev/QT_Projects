/********************************************************************************
** Form generated from reading UI file 'gameOne.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEONE_H
#define UI_GAMEONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameOne
{
public:
    QLabel *label_2;
    QPushButton *pauseBtn;
    QLabel *restStepLabel;
    QLabel *scoreNumLabel;
    QLabel *label;
    QPushButton *progressBtn;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QLabel *stepLabel;
    QPushButton *endGameBtn;

    void setupUi(QWidget *gameOne)
    {
        if (gameOne->objectName().isEmpty())
            gameOne->setObjectName(QString::fromUtf8("gameOne"));
        gameOne->resize(717, 845);
        label_2 = new QLabel(gameOne);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 690, 681, 51));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//bottom.png);\n"
""));
        pauseBtn = new QPushButton(gameOne);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        pauseBtn->setGeometry(QRect(50, 10, 64, 62));
        pauseBtn->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0)"));
        restStepLabel = new QLabel(gameOne);
        restStepLabel->setObjectName(QString::fromUtf8("restStepLabel"));
        restStepLabel->setGeometry(QRect(570, 0, 121, 131));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(20);
        restStepLabel->setFont(font);
        restStepLabel->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//score.png);\n"
""));
        restStepLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        scoreNumLabel = new QLabel(gameOne);
        scoreNumLabel->setObjectName(QString::fromUtf8("scoreNumLabel"));
        scoreNumLabel->setGeometry(QRect(40, 120, 71, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(12);
        scoreNumLabel->setFont(font1);
        scoreNumLabel->setAlignment(Qt::AlignCenter);
        label = new QLabel(gameOne);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 90, 61, 21));
        label->setFont(font1);
        progressBtn = new QPushButton(gameOne);
        progressBtn->setObjectName(QString::fromUtf8("progressBtn"));
        progressBtn->setGeometry(QRect(210, 20, 61, 61));
        progressBar = new QProgressBar(gameOne);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(110, 100, 381, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        progressBar->setFont(font2);
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
        pushButton = new QPushButton(gameOne);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 690, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//flush.png);"));
        stepLabel = new QLabel(gameOne);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));
        stepLabel->setGeometry(QRect(590, 70, 81, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font3.setPointSize(26);
        font3.setBold(true);
        font3.setWeight(75);
        stepLabel->setFont(font3);
        stepLabel->setAlignment(Qt::AlignCenter);
        endGameBtn = new QPushButton(gameOne);
        endGameBtn->setObjectName(QString::fromUtf8("endGameBtn"));
        endGameBtn->setGeometry(QRect(310, 20, 61, 61));

        retranslateUi(gameOne);

        QMetaObject::connectSlotsByName(gameOne);
    } // setupUi

    void retranslateUi(QWidget *gameOne)
    {
        gameOne->setWindowTitle(QApplication::translate("gameOne", "Form", nullptr));
        label_2->setText(QString());
        pauseBtn->setText(QString());
        restStepLabel->setText(QString());
        scoreNumLabel->setText(QString());
        label->setText(QApplication::translate("gameOne", "\345\210\206 \346\225\260", nullptr));
        progressBtn->setText(QString());
        pushButton->setText(QString());
        stepLabel->setText(QString());
        endGameBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameOne: public Ui_gameOne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEONE_H
