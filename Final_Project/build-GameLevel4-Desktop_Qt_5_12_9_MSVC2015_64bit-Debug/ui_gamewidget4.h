/********************************************************************************
** Form generated from reading UI file 'gamewidget4.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET4_H
#define UI_GAMEWIDGET4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget4
{
public:

    void setupUi(QWidget *GameWidget4)
    {
        if (GameWidget4->objectName().isEmpty())
            GameWidget4->setObjectName(QString::fromUtf8("GameWidget4"));
        GameWidget4->resize(800, 600);

        retranslateUi(GameWidget4);

        QMetaObject::connectSlotsByName(GameWidget4);
    } // setupUi

    void retranslateUi(QWidget *GameWidget4)
    {
        GameWidget4->setWindowTitle(QApplication::translate("GameWidget4", "GameWidget4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWidget4: public Ui_GameWidget4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET4_H
