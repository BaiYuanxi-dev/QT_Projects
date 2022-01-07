/********************************************************************************
** Form generated from reading UI file 'gameThree.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMETHREE_H
#define UI_GAMETHREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameThree
{
public:
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *scoreNumLabel;
    QProgressBar *progressBar;
    QLabel *dicknumLabel;
    QPushButton *pauseBtn;
    QPushButton *progressBtn;
    QLabel *stepLabel;
    QPushButton *endGameBtn;
    QLabel *restStepLabel;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *gameThree)
    {
        if (gameThree->objectName().isEmpty())
            gameThree->setObjectName(QString::fromUtf8("gameThree"));
        gameThree->resize(843, 884);
        label_2 = new QLabel(gameThree);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 820, 681, 51));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//bottom.png);\n"
""));
        pushButton = new QPushButton(gameThree);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 820, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//flush.png);"));
        label = new QLabel(gameThree);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 110, 61, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(12);
        font.setUnderline(true);
        label->setFont(font);
        scoreNumLabel = new QLabel(gameThree);
        scoreNumLabel->setObjectName(QString::fromUtf8("scoreNumLabel"));
        scoreNumLabel->setGeometry(QRect(40, 140, 71, 21));
        scoreNumLabel->setFont(font);
        scoreNumLabel->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(gameThree);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(110, 120, 381, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        progressBar->setFont(font1);
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
        dicknumLabel = new QLabel(gameThree);
        dicknumLabel->setObjectName(QString::fromUtf8("dicknumLabel"));
        dicknumLabel->setGeometry(QRect(410, 60, 81, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        dicknumLabel->setFont(font2);
        dicknumLabel->setAlignment(Qt::AlignCenter);
        pauseBtn = new QPushButton(gameThree);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        pauseBtn->setGeometry(QRect(50, 20, 64, 62));
        pauseBtn->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0)"));
        progressBtn = new QPushButton(gameThree);
        progressBtn->setObjectName(QString::fromUtf8("progressBtn"));
        progressBtn->setGeometry(QRect(210, 30, 61, 61));
        stepLabel = new QLabel(gameThree);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));
        stepLabel->setGeometry(QRect(580, 80, 81, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        stepLabel->setFont(font3);
        stepLabel->setAlignment(Qt::AlignCenter);
        endGameBtn = new QPushButton(gameThree);
        endGameBtn->setObjectName(QString::fromUtf8("endGameBtn"));
        endGameBtn->setGeometry(QRect(290, 30, 61, 61));
        restStepLabel = new QLabel(gameThree);
        restStepLabel->setObjectName(QString::fromUtf8("restStepLabel"));
        restStepLabel->setGeometry(QRect(560, 10, 121, 131));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font4.setPointSize(20);
        restStepLabel->setFont(font4);
        restStepLabel->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//score.png);\n"
""));
        restStepLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_3 = new QLabel(gameThree);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 10, 111, 111));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//bigBox.png);"));
        label_4 = new QLabel(gameThree);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(390, 10, 72, 81));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//box4.png);"));
        label_2->raise();
        pushButton->raise();
        label->raise();
        scoreNumLabel->raise();
        progressBar->raise();
        pauseBtn->raise();
        progressBtn->raise();
        endGameBtn->raise();
        restStepLabel->raise();
        label_3->raise();
        label_4->raise();
        dicknumLabel->raise();
        stepLabel->raise();

        retranslateUi(gameThree);

        QMetaObject::connectSlotsByName(gameThree);
    } // setupUi

    void retranslateUi(QWidget *gameThree)
    {
        gameThree->setWindowTitle(QApplication::translate("gameThree", "Form", nullptr));
        label_2->setText(QString());
        pushButton->setText(QString());
        label->setText(QApplication::translate("gameThree", "\345\210\206 \346\225\260", nullptr));
        scoreNumLabel->setText(QString());
        dicknumLabel->setText(QApplication::translate("gameThree", "100", nullptr));
        pauseBtn->setText(QString());
        progressBtn->setText(QString());
        stepLabel->setText(QString());
        endGameBtn->setText(QString());
        restStepLabel->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameThree: public Ui_gameThree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMETHREE_H
