/********************************************************************************
** Form generated from reading UI file 'helpform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPFORM_H
#define UI_HELPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helpForm
{
public:

    void setupUi(QWidget *helpForm)
    {
        if (helpForm->objectName().isEmpty())
            helpForm->setObjectName(QString::fromUtf8("helpForm"));
        helpForm->resize(400, 300);

        retranslateUi(helpForm);

        QMetaObject::connectSlotsByName(helpForm);
    } // setupUi

    void retranslateUi(QWidget *helpForm)
    {
        helpForm->setWindowTitle(QCoreApplication::translate("helpForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helpForm: public Ui_helpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPFORM_H
