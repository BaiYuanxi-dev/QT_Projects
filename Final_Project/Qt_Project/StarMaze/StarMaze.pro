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
    EnterGameWidget/entergamewidget.cpp \
    EnterGameWidget/listitemwidget.cpp \
    EnterGameWidget/mypushbutton.cpp \
    EnterGameWidget/rankwidget.cpp \
    Login/login.cpp \
    controlclass.cpp \
    game1/mybutton.cpp \
    game1/pausewidget.cpp \
    game1/widget.cpp \
    main.cpp \
    mainWindow/helpform.cpp \
    mainWindow/mainwindow.cpp

HEADERS += \
    EnterGameWidget/entergamewidget.h \
    EnterGameWidget/listitemwidget.h \
    EnterGameWidget/mypushbutton.h \
    EnterGameWidget/rankwidget.h \
    Login/login.h \
    controlclass.h \
    game1/mybutton.h \
    game1/pausewidget.h \
    game1/widget.h \
    mainWindow/helpform.h \
    mainWindow/mainwindow.h

FORMS += \
    Login/login.ui \
    game1/pausewidget.ui \
    game1/widget.ui \
    mainWindow/helpform.ui \
    mainWindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
