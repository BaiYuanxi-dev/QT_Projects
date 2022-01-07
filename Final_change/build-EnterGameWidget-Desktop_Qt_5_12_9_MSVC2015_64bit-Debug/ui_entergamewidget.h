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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterGameWidget
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton;

    void setupUi(QWidget *EnterGameWidget)
    {
        if (EnterGameWidget->objectName().isEmpty())
            EnterGameWidget->setObjectName(QString::fromUtf8("EnterGameWidget"));
        EnterGameWidget->resize(348, 723);
        scrollArea = new QScrollArea(EnterGameWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(35, 220, 281, 491));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 279, 600));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 600));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(EnterGameWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 90, 101, 28));

        retranslateUi(EnterGameWidget);

        QMetaObject::connectSlotsByName(EnterGameWidget);
    } // setupUi

    void retranslateUi(QWidget *EnterGameWidget)
    {
        EnterGameWidget->setWindowTitle(QApplication::translate("EnterGameWidget", "EnterGameWidget", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EnterGameWidget: public Ui_EnterGameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERGAMEWIDGET_H
