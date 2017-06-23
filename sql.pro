#-------------------------------------------------
#
# Project created by QtCreator 2017-06-22T10:49:45
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sql
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    admin.cpp \
    finance.cpp \
    manager.cpp

HEADERS  += mainwindow.h \
    connecttion.h \
    login.h \
    admin.h \
    finance.h \
    global.h \
    manager.h

FORMS    += mainwindow.ui \
    login.ui \
    admin.ui \
    finance.ui \
    manager.ui
