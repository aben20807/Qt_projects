#-------------------------------------------------
#
# Project created by QtCreator 2016-08-14T22:21:21
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 003_qt_loginInterface_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    signup.cpp

HEADERS  += mainwindow.h \
    signup.h

FORMS    += mainwindow.ui \
    signup.ui

RESOURCES += \
    resource.qrc
