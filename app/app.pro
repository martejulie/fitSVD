include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = app

SOURCES += main.cpp

LIBS += -larmadillo -lblas -llapack
LIBS += -L../src -lmyapp
