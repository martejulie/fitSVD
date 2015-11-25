include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = lib

TARGET = myapp

SOURCES += \
    experiment.cpp \
    myclass.cpp

HEADERS += \
    experiment.h \
    myclass.h

