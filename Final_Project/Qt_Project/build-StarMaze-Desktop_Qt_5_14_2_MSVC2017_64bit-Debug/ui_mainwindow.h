/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QLabel *label;
    QPushButton *classTwo;
    QPushButton *classOne;
    QPushButton *classThree;
    QPushButton *classFour;
    QPushButton *helpButton;

    void setupUi(QWidget *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(649, 859);
        label = new QLabel(mainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 646, 192));
        classTwo = new QPushButton(mainWindow);
        classTwo->setObjectName(QString::fromUtf8("classTwo"));
        classTwo->setGeometry(QRect(240, 330, 120, 120));
        classOne = new QPushButton(mainWindow);
        classOne->setObjectName(QString::fromUtf8("classOne"));
        classOne->setGeometry(QRect(60, 500, 120, 120));
        classThree = new QPushButton(mainWindow);
        classThree->setObjectName(QString::fromUtf8("classThree"));
        classThree->setGeometry(QRect(450, 370, 120, 120));
        classFour = new QPushButton(mainWindow);
        classFour->setObjectName(QString::fromUtf8("classFour"));
        classFour->setGeometry(QRect(520, 540, 120, 120));
        helpButton = new QPushButton(mainWindow);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setGeometry(QRect(500, 770, 80, 80));

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QWidget *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "Form", nullptr));
        label->setText(QString());
        classTwo->setText(QString());
        classOne->setText(QString());
        classThree->setText(QString());
        classFour->setText(QString());
        helpButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
