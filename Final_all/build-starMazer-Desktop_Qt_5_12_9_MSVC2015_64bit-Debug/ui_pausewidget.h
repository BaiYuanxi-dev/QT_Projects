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
    QLabel *pausedLabel;
    QPushButton *pushButton;

    void setupUi(QWidget *PauseWidget)
    {
        if (PauseWidget->objectName().isEmpty())
            PauseWidget->setObjectName(QString::fromUtf8("PauseWidget"));
        PauseWidget->resize(584, 497);
        pausedLabel = new QLabel(PauseWidget);
        pausedLabel->setObjectName(QString::fromUtf8("pausedLabel"));
        pausedLabel->setGeometry(QRect(140, 50, 281, 111));
        pausedLabel->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;\n"
"border-image:url(\"E://uiProject//paused.png\");"));
        pushButton = new QPushButton(PauseWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(490, 20, 61, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(E://uiProject//back1.png)"));

        retranslateUi(PauseWidget);

        QMetaObject::connectSlotsByName(PauseWidget);
    } // setupUi

    void retranslateUi(QWidget *PauseWidget)
    {
        PauseWidget->setWindowTitle(QApplication::translate("PauseWidget", "Form", nullptr));
        pausedLabel->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PauseWidget: public Ui_PauseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEWIDGET_H
