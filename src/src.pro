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
    kroghmodel_std2param.cpp \
    kroghmodel_std3param.cpp

HEADERS += \
    experiment.h \
    fitsvd.h \
    kroghmodel_std2param.h \
    kroghmodel_std3param.h

