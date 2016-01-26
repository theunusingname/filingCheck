#-------------------------------------------------
#
# Project created by QtCreator 2016-01-18T21:46:43
#
#-------------------------------------------------

QT       += core gui
CONFIG  += qaxcontainer
CONFIG += console


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = filingResultsCheck
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    reportvalidator.cpp \
    excelreader.cpp \
    exam.cpp \
    progressWidget.cpp

HEADERS  += mainwindow.h \
    reportvalidator.h \
    excelreader.h \
    exam.h \
    progressWidget.h

FORMS    += mainwindow.ui
