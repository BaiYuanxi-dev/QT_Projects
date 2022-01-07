/********************************************************************************
** Form generated from reading UI file 'listitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTITEM_H
#define UI_LISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListItem
{
public:
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *ListItem)
    {
        if (ListItem->objectName().isEmpty())
            ListItem->setObjectName(QString::fromUtf8("ListItem"));
        ListItem->resize(319, 86);
        label_2 = new QLabel(ListItem);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 10, 241, 41));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 238, 174);"));
        label = new QLabel(ListItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 81, 91));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 255, 220);"));

        retranslateUi(ListItem);

        QMetaObject::connectSlotsByName(ListItem);
    } // setupUi

    void retranslateUi(QWidget *ListItem)
    {
        ListItem->setWindowTitle(QApplication::translate("ListItem", "Form", nullptr));
        label_2->setText(QApplication::translate("ListItem", "TextLabel", nullptr));
        label->setText(QApplication::translate("ListItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListItem: public Ui_ListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTITEM_H
