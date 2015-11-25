TEMPLATE = app

include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -L../src -lmyapp
