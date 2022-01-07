/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pauseBtn;
    QProgressBar *progressBar;
    QPushButton *progressBtn;
    QLabel *label;
    QLabel *scoreNumLabel;
    QLabel *restStepLabel;
    QLabel *stepLabel;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *endGameBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(710, 926);
        pauseBtn = new QPushButton(Widget);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        pauseBtn->setGeometry(QRect(20, 10, 64, 62));
        pauseBtn->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0)"));
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(80, 100, 381, 21));
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
        progressBtn = new QPushButton(Widget);
        progressBtn->setObjectName(QString::fromUtf8("progressBtn"));
        progressBtn->setGeometry(QRect(180, 20, 61, 61));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 61, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(12);
        label->setFont(font1);
        scoreNumLabel = new QLabel(Widget);
        scoreNumLabel->setObjectName(QString::fromUtf8("scoreNumLabel"));
        scoreNumLabel->setGeometry(QRect(10, 120, 71, 21));
        scoreNumLabel->setFont(font1);
        scoreNumLabel->setAlignment(Qt::AlignCenter);
        restStepLabel = new QLabel(Widget);
        restStepLabel->setObjectName(QString::fromUtf8("restStepLabel"));
        restStepLabel->setGeometry(QRect(540, 0, 121, 131));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(20);
        restStepLabel->setFont(font2);
        restStepLabel->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//score.png);\n"
""));
        restStepLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        stepLabel = new QLabel(Widget);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));
        stepLabel->setGeometry(QRect(561, 64, 81, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        stepLabel->setFont(font3);
        stepLabel->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 690, 681, 51));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//bottom.png);\n"
""));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 690, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//flush.png);"));
        endGameBtn = new QPushButton(Widget);
        endGameBtn->setObjectName(QString::fromUtf8("endGameBtn"));
        endGameBtn->setGeometry(QRect(280, 20, 61, 61));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pauseBtn->setText(QString());
        progressBtn->setText(QString());
        label->setText(QApplication::translate("Widget", "\345\210\206 \346\225\260", nullptr));
        scoreNumLabel->setText(QString());
        restStepLabel->setText(QString());
        stepLabel->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QString());
        endGameBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
