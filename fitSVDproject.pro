TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS += \
    app \
    src \
    tests

app.depends = src
tests.depends = src

OTHER_FILES += \
    defaults.pri
