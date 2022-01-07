/********************************************************************************
** Form generated from reading UI file 'entergamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERGAMEWINDOW_H
#define UI_ENTERGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterGameWindow
{
public:
    QWidget *centralwidget;
    QListWidget *rankListWidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EnterGameWindow)
    {
        if (EnterGameWindow->objectName().isEmpty())
            EnterGameWindow->setObjectName(QString::fromUtf8("EnterGameWindow"));
        EnterGameWindow->resize(800, 600);
        centralwidget = new QWidget(EnterGameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        rankListWidget = new QListWidget(centralwidget);
        QIcon icon;
        icon.addFile(QString::fromUtf8("image/rankImg/head (1).jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(rankListWidget);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image/rankImg/head (2).jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(rankListWidget);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("image/rankImg/head (3).jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(rankListWidget);
        __qlistwidgetitem2->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("image/rankImg/head (4).jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(rankListWidget);
        __qlistwidgetitem3->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("image/rankImg/head (5).jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(rankListWidget);
        __qlistwidgetitem4->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("image/rankImg/head (6).jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(rankListWidget);
        __qlistwidgetitem5->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("image/rankImg/head (7).jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(rankListWidget);
        __qlistwidgetitem6->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("image/rankImg/head (8).jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(rankListWidget);
        __qlistwidgetitem7->setIcon(icon7);
        rankListWidget->setObjectName(QString::fromUtf8("rankListWidget"));
        rankListWidget->setGeometry(QRect(220, 350, 91, 201));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 290, 93, 28));
        EnterGameWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EnterGameWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        EnterGameWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EnterGameWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EnterGameWindow->setStatusBar(statusbar);

        retranslateUi(EnterGameWindow);

        QMetaObject::connectSlotsByName(EnterGameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EnterGameWindow)
    {
        EnterGameWindow->setWindowTitle(QApplication::translate("EnterGameWindow", "EnterGameWindow", nullptr));

        const bool __sortingEnabled = rankListWidget->isSortingEnabled();
        rankListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = rankListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("EnterGameWindow", "str1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = rankListWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("EnterGameWindow", "str2", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = rankListWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("EnterGameWindow", "str3", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = rankListWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("EnterGameWindow", "str4", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = rankListWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("EnterGameWindow", "str5", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = rankListWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("EnterGameWindow", "str6", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = rankListWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("EnterGameWindow", "str7", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = rankListWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("EnterGameWindow", "str8", nullptr));
        rankListWidget->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("EnterGameWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterGameWindow: public Ui_EnterGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERGAMEWINDOW_H
