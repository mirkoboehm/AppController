SOURCES = \
    tests.cpp
INCLUDEPATH += ../src
CONFIG += qtestlib
macx:CONFIG -= app_bundle
INCLUDEPATH += ../src
LIBS += -L../src -lsrc

HEADERS += \
    ThrowingControllerFactory.h
