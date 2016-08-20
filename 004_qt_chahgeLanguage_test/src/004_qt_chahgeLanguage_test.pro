#-------------------------------------------------
#
# Project created by QtCreator 2016-08-20T10:36:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 004_qt_chahgeLanguage_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

TRANSLATIONS = ./language/zh_TW.ts\
               ./language/en_US.ts\
               ./language/ja_JP.ts

