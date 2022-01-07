/********************************************************************************
** Form generated from reading UI file 'endgame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAME_H
#define UI_ENDGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_endGame
{
public:

    void setupUi(QWidget *endGame)
    {
        if (endGame->objectName().isEmpty())
            endGame->setObjectName(QString::fromUtf8("endGame"));
        endGame->resize(606, 600);
        endGame->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(endGame);

        QMetaObject::connectSlotsByName(endGame);
    } // setupUi

    void retranslateUi(QWidget *endGame)
    {
        endGame->setWindowTitle(QApplication::translate("endGame", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class endGame: public Ui_endGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAME_H
