/********************************************************************************
** Form generated from reading UI file 'endwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDWIDGET_H
#define UI_ENDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndWidget
{
public:

    void setupUi(QWidget *EndWidget)
    {
        if (EndWidget->objectName().isEmpty())
            EndWidget->setObjectName(QString::fromUtf8("EndWidget"));
        EndWidget->resize(606, 600);

        retranslateUi(EndWidget);

        QMetaObject::connectSlotsByName(EndWidget);
    } // setupUi

    void retranslateUi(QWidget *EndWidget)
    {
        EndWidget->setWindowTitle(QApplication::translate("EndWidget", "EndWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndWidget: public Ui_EndWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDWIDGET_H
