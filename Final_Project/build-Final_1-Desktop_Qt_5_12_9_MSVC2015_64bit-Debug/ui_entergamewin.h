/********************************************************************************
** Form generated from reading UI file 'entergamewin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERGAMEWIN_H
#define UI_ENTERGAMEWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterGameWin
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *EnterGameWin)
    {
        if (EnterGameWin->objectName().isEmpty())
            EnterGameWin->setObjectName(QString::fromUtf8("EnterGameWin"));
        EnterGameWin->resize(350, 600);
        scrollArea = new QScrollArea(EnterGameWin);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(35, 220, 280, 350));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 278, 348));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(EnterGameWin);

        QMetaObject::connectSlotsByName(EnterGameWin);
    } // setupUi

    void retranslateUi(QWidget *EnterGameWin)
    {
        EnterGameWin->setWindowTitle(QApplication::translate("EnterGameWin", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterGameWin: public Ui_EnterGameWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERGAMEWIN_H
