/********************************************************************************
** Form generated from reading UI file 'listitemwid.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTITEMWID_H
#define UI_LISTITEMWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListItemWid
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *rankLabel;
    QLineEdit *msgLine;
    QLabel *imgLabel;

    void setupUi(QWidget *ListItemWid)
    {
        if (ListItemWid->objectName().isEmpty())
            ListItemWid->setObjectName(QString::fromUtf8("ListItemWid"));
        ListItemWid->resize(400, 300);
        gridLayoutWidget = new QWidget(ListItemWid);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(90, 100, 160, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        rankLabel = new QLabel(gridLayoutWidget);
        rankLabel->setObjectName(QString::fromUtf8("rankLabel"));

        gridLayout->addWidget(rankLabel, 0, 0, 1, 1);

        msgLine = new QLineEdit(gridLayoutWidget);
        msgLine->setObjectName(QString::fromUtf8("msgLine"));

        gridLayout->addWidget(msgLine, 0, 2, 1, 1);

        imgLabel = new QLabel(gridLayoutWidget);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));

        gridLayout->addWidget(imgLabel, 0, 1, 1, 1);


        retranslateUi(ListItemWid);

        QMetaObject::connectSlotsByName(ListItemWid);
    } // setupUi

    void retranslateUi(QWidget *ListItemWid)
    {
        ListItemWid->setWindowTitle(QApplication::translate("ListItemWid", "Form", nullptr));
        rankLabel->setText(QString());
        imgLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListItemWid: public Ui_ListItemWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTITEMWID_H
