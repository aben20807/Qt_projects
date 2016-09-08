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
    battery.cpp \
    cmdprocess.cpp \
    log.cpp

HEADERS  += mainwindow.h \
    schedule.h \
    battery.h \
    cmdprocess.h \
    log.h

FORMS    += mainwindow.ui \
    schedule.ui \
    log.ui

RESOURCES += \
    resources.qrc

TRANSLATIONS = ./res/language/zh_TW.ts\
               ./res/language/en_US.ts

win32:RC_ICONS += ./res/icon/ic_battery_alert_black_48dp.ico


