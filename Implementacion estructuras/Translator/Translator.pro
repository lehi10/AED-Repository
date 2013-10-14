#-------------------------------------------------
#
# Project created by QtCreator 2013-10-13T13:23:32
#
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++0x

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Translator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    AVLtree.h

FORMS    += mainwindow.ui
