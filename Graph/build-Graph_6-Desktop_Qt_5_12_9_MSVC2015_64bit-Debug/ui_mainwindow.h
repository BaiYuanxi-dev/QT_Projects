/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *choice;
    QRadioButton *MSTRadBut;
    QRadioButton *DFSRadBut;
    QRadioButton *shortPathRadBut;
    QRadioButton *msgRadBut;
    QPushButton *initButton;
    QPushButton *pathButton;
    QPushButton *exitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1043, 722);
        MainWindow->setMinimumSize(QSize(1043, 722));
        MainWindow->setMaximumSize(QSize(1043, 722));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        choice = new QGroupBox(centralwidget);
        choice->setObjectName(QString::fromUtf8("choice"));
        choice->setGeometry(QRect(820, 70, 221, 421));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        choice->setFont(font);
        choice->setAlignment(Qt::AlignCenter);
        MSTRadBut = new QRadioButton(choice);
        MSTRadBut->setObjectName(QString::fromUtf8("MSTRadBut"));
        MSTRadBut->setGeometry(QRect(60, 270, 161, 16));
        DFSRadBut = new QRadioButton(choice);
        DFSRadBut->setObjectName(QString::fromUtf8("DFSRadBut"));
        DFSRadBut->setGeometry(QRect(60, 50, 115, 19));
        shortPathRadBut = new QRadioButton(choice);
        shortPathRadBut->setObjectName(QString::fromUtf8("shortPathRadBut"));
        shortPathRadBut->setGeometry(QRect(60, 160, 115, 19));
        msgRadBut = new QRadioButton(choice);
        msgRadBut->setObjectName(QString::fromUtf8("msgRadBut"));
        msgRadBut->setGeometry(QRect(60, 370, 115, 19));
        initButton = new QPushButton(centralwidget);
        initButton->setObjectName(QString::fromUtf8("initButton"));
        initButton->setGeometry(QRect(850, 500, 171, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        initButton->setFont(font1);
        pathButton = new QPushButton(centralwidget);
        pathButton->setObjectName(QString::fromUtf8("pathButton"));
        pathButton->setGeometry(QRect(850, 550, 171, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        pathButton->setFont(font2);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(850, 600, 171, 31));
        exitButton->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1043, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        choice->setTitle(QApplication::translate("MainWindow", "\345\212\237\350\203\275", nullptr));
        MSTRadBut->setText(QApplication::translate("MainWindow", "\351\223\272\350\256\276\347\272\277\350\267\257\350\247\204\345\210\222", nullptr));
        DFSRadBut->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204\345\257\274\350\210\252", nullptr));
        shortPathRadBut->setText(QApplication::translate("MainWindow", "\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        msgRadBut->setText(QApplication::translate("MainWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        initButton->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\345\233\276", nullptr));
        pathButton->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\346\235\241\350\267\257\345\276\204", nullptr));
        exitButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
