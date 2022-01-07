/********************************************************************************
** Form generated from reading UI file 'pausewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
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
    QLabel *speedLabel;
    QPushButton *midSpeedBtn;
    QLabel *curSpeedLabel;
    QLabel *pausedLabel;
    QPushButton *backBtn;
    QPushButton *slowSpeedbtn;
    QPushButton *fastSpeedBtn;

    void setupUi(QWidget *PauseWidget)
    {
        if (PauseWidget->objectName().isEmpty())
            PauseWidget->setObjectName(QString::fromUtf8("PauseWidget"));
        PauseWidget->resize(439, 359);
        speedLabel = new QLabel(PauseWidget);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        speedLabel->setGeometry(QRect(140, 100, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(12);
        speedLabel->setFont(font);
        midSpeedBtn = new QPushButton(PauseWidget);
        midSpeedBtn->setObjectName(QString::fromUtf8("midSpeedBtn"));
        midSpeedBtn->setGeometry(QRect(160, 160, 131, 51));
        midSpeedBtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//midSpeed.png\");"));
        curSpeedLabel = new QLabel(PauseWidget);
        curSpeedLabel->setObjectName(QString::fromUtf8("curSpeedLabel"));
        curSpeedLabel->setGeometry(QRect(40, 100, 91, 31));
        curSpeedLabel->setFont(font);
        pausedLabel = new QLabel(PauseWidget);
        pausedLabel->setObjectName(QString::fromUtf8("pausedLabel"));
        pausedLabel->setGeometry(QRect(130, 0, 181, 71));
        pausedLabel->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//paused.png\");"));
        backBtn = new QPushButton(PauseWidget);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(20, 240, 401, 91));
        backBtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//back.png\");"));
        slowSpeedbtn = new QPushButton(PauseWidget);
        slowSpeedbtn->setObjectName(QString::fromUtf8("slowSpeedbtn"));
        slowSpeedbtn->setGeometry(QRect(20, 160, 131, 51));
        slowSpeedbtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//slowSpeed.png\");"));
        fastSpeedBtn = new QPushButton(PauseWidget);
        fastSpeedBtn->setObjectName(QString::fromUtf8("fastSpeedBtn"));
        fastSpeedBtn->setGeometry(QRect(300, 160, 121, 51));
        fastSpeedBtn->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"background-image:url(\"E://uiProject//fastSpeed.png\");"));

        retranslateUi(PauseWidget);

        QMetaObject::connectSlotsByName(PauseWidget);
    } // setupUi

    void retranslateUi(QWidget *PauseWidget)
    {
        PauseWidget->setWindowTitle(QCoreApplication::translate("PauseWidget", "Form", nullptr));
        speedLabel->setText(QCoreApplication::translate("PauseWidget", "\345\277\253\351\200\237", nullptr));
        midSpeedBtn->setText(QString());
        curSpeedLabel->setText(QCoreApplication::translate("PauseWidget", "\345\275\223\345\211\215\351\200\237\345\272\246:", nullptr));
        pausedLabel->setText(QString());
        backBtn->setText(QString());
        slowSpeedbtn->setText(QString());
        fastSpeedBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PauseWidget: public Ui_PauseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEWIDGET_H
