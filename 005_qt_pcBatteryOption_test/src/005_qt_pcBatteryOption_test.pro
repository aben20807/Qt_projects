#-------------------------------------------------
#
# Project created by QtCreator 2016-08-21T20:21:08
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 005_qt_pcBatteryOption_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    schedule.cpp \
    battery.cpp

HEADERS  += mainwindow.h \
    schedule.h \
    battery.h

FORMS    += mainwindow.ui \
    schedule.ui

RESOURCES += \
    resources.qrc
