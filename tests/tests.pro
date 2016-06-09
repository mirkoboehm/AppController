SOURCES = \
    tests.cpp
INCLUDEPATH += ../src
QT+=testlib
macx:CONFIG -= app_bundle
INCLUDEPATH += ../src
LIBS += -L../src -lsrc

HEADERS += \
    ThrowingControllerFactory.h
