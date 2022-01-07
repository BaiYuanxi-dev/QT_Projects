/********************************************************************************
** Form generated from reading UI file 'entergamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERGAMEWIDGET_H
#define UI_ENTERGAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterGameWidget
{
public:

    void setupUi(QWidget *EnterGameWidget)
    {
        if (EnterGameWidget->objectName().isEmpty())
            EnterGameWidget->setObjectName(QString::fromUtf8("EnterGameWidget"));
        EnterGameWidget->resize(800, 600);

        retranslateUi(EnterGameWidget);

        QMetaObject::connectSlotsByName(EnterGameWidget);
    } // setupUi

    void retranslateUi(QWidget *EnterGameWidget)
    {
        EnterGameWidget->setWindowTitle(QApplication::translate("EnterGameWidget", "EnterGameWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterGameWidget: public Ui_EnterGameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERGAMEWIDGET_H
