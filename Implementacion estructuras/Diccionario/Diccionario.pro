#-------------------------------------------------
#
# Project created by QtCreator 2013-09-15T11:42:52
#
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++0x


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Diccionario
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    nodo.h \
    listD.h

FORMS    += mainwindow.ui
