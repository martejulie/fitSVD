TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS += \
    src \
    app \
    tests

LIBS += -larmadillo -lblas -llapack

app.depends = src
tests.depends = src

OTHER_FILES += \
    defaults.pri
