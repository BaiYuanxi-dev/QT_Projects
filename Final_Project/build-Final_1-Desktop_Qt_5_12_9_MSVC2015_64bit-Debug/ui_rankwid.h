/********************************************************************************
** Form generated from reading UI file 'rankwid.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKWID_H
#define UI_RANKWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RankWid
{
public:

    void setupUi(QWidget *RankWid)
    {
        if (RankWid->objectName().isEmpty())
            RankWid->setObjectName(QString::fromUtf8("RankWid"));
        RankWid->resize(400, 300);

        retranslateUi(RankWid);

        QMetaObject::connectSlotsByName(RankWid);
    } // setupUi

    void retranslateUi(QWidget *RankWid)
    {
        RankWid->setWindowTitle(QApplication::translate("RankWid", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankWid: public Ui_RankWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKWID_H
