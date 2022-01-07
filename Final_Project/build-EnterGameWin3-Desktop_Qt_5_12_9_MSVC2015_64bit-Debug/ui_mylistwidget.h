/********************************************************************************
** Form generated from reading UI file 'mylistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLISTWIDGET_H
#define UI_MYLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyListWidget
{
public:

    void setupUi(QWidget *MyListWidget)
    {
        if (MyListWidget->objectName().isEmpty())
            MyListWidget->setObjectName(QString::fromUtf8("MyListWidget"));
        MyListWidget->resize(400, 300);

        retranslateUi(MyListWidget);

        QMetaObject::connectSlotsByName(MyListWidget);
    } // setupUi

    void retranslateUi(QWidget *MyListWidget)
    {
        MyListWidget->setWindowTitle(QApplication::translate("MyListWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyListWidget: public Ui_MyListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLISTWIDGET_H
