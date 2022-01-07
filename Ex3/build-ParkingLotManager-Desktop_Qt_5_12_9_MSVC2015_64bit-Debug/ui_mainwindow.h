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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *idLabel;
    QLineEdit *idLine;
    QPushButton *addQueueButton;
    QPushButton *addInSpaceButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *noLabel;
    QLineEdit *noLine;
    QPushButton *outButton;
    QPushButton *queryButton;
    QPushButton *exitButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *emptyMsgLabel;
    QLineEdit *emptyNumLine;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *queueNumlabel;
    QLineEdit *queueNumLine;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1235, 572);
        MainWindow->setMinimumSize(QSize(1235, 572));
        MainWindow->setMaximumSize(QSize(1235, 572));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 150, 261, 361));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        idLabel = new QLabel(verticalLayoutWidget);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(13);
        idLabel->setFont(font);

        horizontalLayout_3->addWidget(idLabel);

        idLine = new QLineEdit(verticalLayoutWidget);
        idLine->setObjectName(QString::fromUtf8("idLine"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        idLine->setFont(font1);

        horizontalLayout_3->addWidget(idLine);


        verticalLayout->addLayout(horizontalLayout_3);

        addQueueButton = new QPushButton(verticalLayoutWidget);
        addQueueButton->setObjectName(QString::fromUtf8("addQueueButton"));
        addQueueButton->setFont(font);

        verticalLayout->addWidget(addQueueButton);

        addInSpaceButton = new QPushButton(verticalLayoutWidget);
        addInSpaceButton->setObjectName(QString::fromUtf8("addInSpaceButton"));
        addInSpaceButton->setFont(font);

        verticalLayout->addWidget(addInSpaceButton);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        noLabel = new QLabel(verticalLayoutWidget);
        noLabel->setObjectName(QString::fromUtf8("noLabel"));
        noLabel->setFont(font);
        noLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(noLabel);

        noLine = new QLineEdit(verticalLayoutWidget);
        noLine->setObjectName(QString::fromUtf8("noLine"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        noLine->setFont(font2);

        horizontalLayout_4->addWidget(noLine);


        verticalLayout->addLayout(horizontalLayout_4);

        outButton = new QPushButton(verticalLayoutWidget);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setFont(font);

        verticalLayout->addWidget(outButton);

        queryButton = new QPushButton(verticalLayoutWidget);
        queryButton->setObjectName(QString::fromUtf8("queryButton"));
        queryButton->setFont(font);

        verticalLayout->addWidget(queryButton);

        exitButton = new QPushButton(verticalLayoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        exitButton->setFont(font3);
        exitButton->setCheckable(false);

        verticalLayout->addWidget(exitButton);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 80, 261, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        emptyMsgLabel = new QLabel(horizontalLayoutWidget);
        emptyMsgLabel->setObjectName(QString::fromUtf8("emptyMsgLabel"));
        emptyMsgLabel->setFont(font);
        emptyMsgLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(emptyMsgLabel);

        emptyNumLine = new QLineEdit(horizontalLayoutWidget);
        emptyNumLine->setObjectName(QString::fromUtf8("emptyNumLine"));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        emptyNumLine->setFont(font4);
        emptyNumLine->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(emptyNumLine);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 261, 71));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        queueNumlabel = new QLabel(horizontalLayoutWidget_2);
        queueNumlabel->setObjectName(QString::fromUtf8("queueNumlabel"));
        queueNumlabel->setFont(font);

        horizontalLayout_2->addWidget(queueNumlabel);

        queueNumLine = new QLineEdit(horizontalLayoutWidget_2);
        queueNumLine->setObjectName(QString::fromUtf8("queueNumLine"));
        queueNumLine->setFont(font2);
        queueNumLine->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(queueNumLine);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(910, 20, 321, 491));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        textEdit->setFont(font5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1235, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Parking Lot", nullptr));
        idLabel->setText(QApplication::translate("MainWindow", "\350\275\246\347\211\214\345\217\267", nullptr));
        addQueueButton->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\347\255\211\345\276\205", nullptr));
        addInSpaceButton->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\350\275\246\344\275\215", nullptr));
        noLabel->setText(QApplication::translate("MainWindow", "\344\275\215\347\275\256\347\274\226\345\217\267", nullptr));
        outButton->setText(QApplication::translate("MainWindow", "\350\275\246\350\276\206\347\246\273\345\274\200", nullptr));
        queryButton->setText(QApplication::translate("MainWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        exitButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        emptyMsgLabel->setText(QApplication::translate("MainWindow", "\347\251\272\350\275\246\344\275\215\346\225\260", nullptr));
        queueNumlabel->setText(QApplication::translate("MainWindow", "\347\255\211\345\276\205\350\275\246\350\276\206", nullptr));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
