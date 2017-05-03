#-------------------------------------------------
#
# Project created by QtCreator 2017-04-14T07:39:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoClick
TEMPLATE = app

SOURCES += main.cpp\
        dialog.cpp \
    getposition.cpp \
    action.cpp

HEADERS  += dialog.h \
    getposition.h \
    standard.h \
    action.h

LIBS += -lKernel32

RESOURCES += \
    myres.qrc
