TEMPLATE = lib
QT += concurrent
HEADERS = ControllerThread.h Controller.h ControllerFactory.h \
    StartupException.h \
    ControllerException.h
SOURCES = ControllerThread.cpp Controller.cpp \
    StartupException.cpp \
    ControllerException.cpp
