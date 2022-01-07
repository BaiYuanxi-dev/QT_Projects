/********************************************************************************
** Form generated from reading UI file 'pausewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEWIDGET_H
#define UI_PAUSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PauseWidget
{
public:
    QPushButton *slowSpeedbtn;
    QLabel *pausedLabel;
    QPushButton *midSpeedBtn;
    QPushButton *fastSpeedBtn;
    QPushButton *backBtn;
    QLabel *curSpeedLabel;
    QLabel *speedLabel;

    void setupUi(QWidget *PauseWidget)
    {
        if (PauseWidget->objectName().isEmpty())
            PauseWidget->setObjectName(QString::fromUtf8("PauseWidget"));
        PauseWidget->resize(514, 673);
        slowSpeedbtn = new QPushButton(PauseWidget);
        slowSpeedbtn->setObjectName(QString::fromUtf8("slowSpeedbtn"));
        slowSpeedbtn->setGeometry(QRect(60, 170, 131, 51));
        slowSpeedbtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//slowSpeed.png\");"));
        pausedLabel = new QLabel(PauseWidget);
        pausedLabel->setObjectName(QString::fromUtf8("pausedLabel"));
        pausedLabel->setGeometry(QRect(180, 10, 181, 71));
        pausedLabel->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//paused.png\");"));
        midSpeedBtn = new QPushButton(PauseWidget);
        midSpeedBtn->setObjectName(QString::fromUtf8("midSpeedBtn"));
        midSpeedBtn->setGeometry(QRect(200, 170, 131, 51));
        midSpeedBtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//midSpeed.png\");"));
        fastSpeedBtn = new QPushButton(PauseWidget);
        fastSpeedBtn->setObjectName(QString::fromUtf8("fastSpeedBtn"));
        fastSpeedBtn->setGeometry(QRect(340, 170, 121, 51));
        fastSpeedBtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//fastSpeed.png\");"));
        backBtn = new QPushButton(PauseWidget);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(60, 250, 401, 91));
        backBtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//back.png\");"));
        curSpeedLabel = new QLabel(PauseWidget);
        curSpeedLabel->setObjectName(QString::fromUtf8("curSpeedLabel"));
        curSpeedLabel->setGeometry(QRect(80, 110, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(12);
        curSpeedLabel->setFont(font);
        speedLabel = new QLabel(PauseWidget);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        speedLabel->setGeometry(QRect(180, 110, 91, 31));
        speedLabel->setFont(font);

        retranslateUi(PauseWidget);

        QMetaObject::connectSlotsByName(PauseWidget);
    } // setupUi

    void retranslateUi(QWidget *PauseWidget)
    {
        PauseWidget->setWindowTitle(QApplication::translate("PauseWidget", "Form", nullptr));
        slowSpeedbtn->setText(QString());
        pausedLabel->setText(QString());
        midSpeedBtn->setText(QString());
        fastSpeedBtn->setText(QString());
        backBtn->setText(QString());
        curSpeedLabel->setText(QApplication::translate("PauseWidget", "\345\275\223\345\211\215\351\200\237\345\272\246:", nullptr));
        speedLabel->setText(QApplication::translate("PauseWidget", "\345\277\253\351\200\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PauseWidget: public Ui_PauseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEWIDGET_H
