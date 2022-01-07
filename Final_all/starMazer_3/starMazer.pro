QT += core gui
QT += multimedia
QT += concurrent
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EnterGameWidget/entergamewin.cpp \
    achive.cpp \
    endgame.cpp \
    gameFour.cpp \
    gameOne.cpp \
    gameThree.cpp \
    gameTwo.cpp \
    helpForm.cpp \
    info.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    mylabel.cpp \
    pausewidget.cpp \
    regis.cpp\
    EnterGameWidget/listitemwidget.cpp \
    EnterGameWidget/mypushbutton.cpp \
    EnterGameWidget/rankwidget.cpp \

HEADERS += \
    EnterGameWidget/entergamewin.h \
    Login.h \
    Node.h \
    achive.h \
    database.h \
    endgame.h \
    gameFour.h \
    gameOne.h \
    gameThree.h \
    gameTwo.h \
    headers.h \
    helpForm.h \
    info.h \
    mainwindow.h \
    mybutton.h \
    mylabel.h \
    pausewidget.h \
    regis.h\
    EnterGameWidget/listitemwidget.h \
    EnterGameWidget/mypushbutton.h \
    EnterGameWidget/rankwidget.h

FORMS += \
    EnterGameWidget/entergamewin.ui \
    achive.ui \
    endgame.ui \
    gameFour.ui \
    gameOne.ui \
    gameThree.ui \
    gameTwo.ui \
    helpForm.ui \
    info.ui \
    login.ui \
    mainwindow.ui \
    pausewidget.ui \
    regis.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
