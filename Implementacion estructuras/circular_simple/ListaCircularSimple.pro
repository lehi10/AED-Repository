QMAKE_CXXFLAGS += -std=c++0x

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    listcs.h \
    Nodo.h

