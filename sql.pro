#-------------------------------------------------
#
# Project created by QtCreator 2017-06-22T10:49:45
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT+= network
QMAKE_CFLAGS+=-pg
QMAKE_CXXFLAGS += -pg
QMAKE_LFLAGS += -pg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sql
TEMPLATE = app


SOURCES += main.cpp\
    login.cpp \
    admin.cpp \
    finance.cpp \
    manager.cpp \
    global.cpp \
    inputlicense.cpp

HEADERS  += \
    connecttion.h \
    login.h \
    admin.h \
    finance.h \
    global.h \
    manager.h \
    inputlicense.h

FORMS    += \
    login.ui \
    admin.ui \
    finance.ui \
    manager.ui \
    inputlicense.ui

RESOURCES += \
    image.qrc
