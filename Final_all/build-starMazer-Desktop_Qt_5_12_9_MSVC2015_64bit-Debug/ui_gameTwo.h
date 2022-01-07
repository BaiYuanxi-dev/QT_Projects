/********************************************************************************
** Form generated from reading UI file 'gameTwo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMETWO_H
#define UI_GAMETWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameTwo
{
public:
    QProgressBar *progressBar;
    QPushButton *progressBtn;
    QLabel *dicknumLabel;
    QPushButton *pauseBtn;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *beanLeft;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *stepLabel;
    QLabel *restStepLabel;
    QLabel *label;
    QLabel *scoreNumLabel;
    QPushButton *endGameBtn;

    void setupUi(QWidget *gameTwo)
    {
        if (gameTwo->objectName().isEmpty())
            gameTwo->setObjectName(QString::fromUtf8("gameTwo"));
        gameTwo->resize(836, 916);
        progressBar = new QProgressBar(gameTwo);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(150, 130, 381, 21));
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
        progressBtn = new QPushButton(gameTwo);
        progressBtn->setObjectName(QString::fromUtf8("progressBtn"));
        progressBtn->setGeometry(QRect(180, 40, 61, 61));
        dicknumLabel = new QLabel(gameTwo);
        dicknumLabel->setObjectName(QString::fromUtf8("dicknumLabel"));
        dicknumLabel->setGeometry(QRect(450, 70, 81, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        dicknumLabel->setFont(font1);
        dicknumLabel->setAlignment(Qt::AlignCenter);
        pauseBtn = new QPushButton(gameTwo);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        pauseBtn->setGeometry(QRect(90, 30, 64, 62));
        pauseBtn->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0)"));
        label_3 = new QLabel(gameTwo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(410, 20, 111, 111));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//bigBox.png);"));
        label_5 = new QLabel(gameTwo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 20, 111, 111));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//bigBox.png);"));
        beanLeft = new QLabel(gameTwo);
        beanLeft->setObjectName(QString::fromUtf8("beanLeft"));
        beanLeft->setGeometry(QRect(295, 25, 81, 81));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        beanLeft->setFont(font2);
        beanLeft->setLayoutDirection(Qt::RightToLeft);
        beanLeft->setStyleSheet(QString::fromUtf8("border-image:url(E://uiProject//bean.png);"));
        beanLeft->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        pushButton = new QPushButton(gameTwo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 830, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//flush.png);"));
        label_2 = new QLabel(gameTwo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 830, 681, 51));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//bottom.png);\n"
""));
        label_4 = new QLabel(gameTwo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(430, 20, 72, 81));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//box4.png);"));
        stepLabel = new QLabel(gameTwo);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));
        stepLabel->setGeometry(QRect(620, 90, 81, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        stepLabel->setFont(font3);
        stepLabel->setAlignment(Qt::AlignCenter);
        restStepLabel = new QLabel(gameTwo);
        restStepLabel->setObjectName(QString::fromUtf8("restStepLabel"));
        restStepLabel->setGeometry(QRect(600, 20, 121, 131));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font4.setPointSize(20);
        restStepLabel->setFont(font4);
        restStepLabel->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//score.png);\n"
""));
        restStepLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label = new QLabel(gameTwo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 120, 61, 21));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font5.setPointSize(12);
        font5.setUnderline(true);
        label->setFont(font5);
        scoreNumLabel = new QLabel(gameTwo);
        scoreNumLabel->setObjectName(QString::fromUtf8("scoreNumLabel"));
        scoreNumLabel->setGeometry(QRect(80, 150, 71, 21));
        scoreNumLabel->setFont(font5);
        scoreNumLabel->setAlignment(Qt::AlignCenter);
        endGameBtn = new QPushButton(gameTwo);
        endGameBtn->setObjectName(QString::fromUtf8("endGameBtn"));
        endGameBtn->setGeometry(QRect(180, 40, 61, 61));
        progressBar->raise();
        progressBtn->raise();
        pauseBtn->raise();
        label_3->raise();
        label_5->raise();
        beanLeft->raise();
        pushButton->raise();
        label_2->raise();
        label_4->raise();
        restStepLabel->raise();
        label->raise();
        scoreNumLabel->raise();
        endGameBtn->raise();
        dicknumLabel->raise();
        stepLabel->raise();

        retranslateUi(gameTwo);

        QMetaObject::connectSlotsByName(gameTwo);
    } // setupUi

    void retranslateUi(QWidget *gameTwo)
    {
        gameTwo->setWindowTitle(QApplication::translate("gameTwo", "Form", nullptr));
        progressBtn->setText(QString());
        dicknumLabel->setText(QApplication::translate("gameTwo", "100", nullptr));
        pauseBtn->setText(QString());
        label_3->setText(QString());
        label_5->setText(QString());
        beanLeft->setText(QString());
        pushButton->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        stepLabel->setText(QString());
        restStepLabel->setText(QString());
        label->setText(QApplication::translate("gameTwo", "\345\210\206 \346\225\260", nullptr));
        scoreNumLabel->setText(QString());
        endGameBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameTwo: public Ui_gameTwo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMETWO_H
