TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS += \
    src \
    app \
    tests

app.depends = src
tests.depends = src

LIBS += -larmadillo -lblas -llapack

OTHER_FILES += \
    defaults.pri
