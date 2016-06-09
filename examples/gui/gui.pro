HEADERS = MainWindow.h \
    GuiController.h
SOURCES = MainWindow.cpp main.cpp \
    GuiController.cpp
FORMS += MainWindow.ui
INCLUDEPATH += ../../src
LIBS += -L../../src -lsrc
