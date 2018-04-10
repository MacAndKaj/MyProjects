#-------------------------------------------------
#
# Project created by QtCreator 2018-04-09T10:22:04
#
#-------------------------------------------------

QT       += core gui printsupport
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WDSApp
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    condition.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    condition.h

FORMS    += mainwindow.ui
