include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = lib

TARGET = myapp

LIBS += -larmadillo -lblas -llapack

SOURCES += \
    experiment.cpp \
    fitsvd.cpp \
    standardkroghmodel.cpp

HEADERS += \
    experiment.h \
    fitsvd.h \
    standardkroghmodel.h

