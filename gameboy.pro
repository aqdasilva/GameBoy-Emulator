TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        gameboy.cpp \
        main.cpp \
        screen.cpp

HEADERS += \
    gameboy.h \
    screen.h

DISTFILES += \
    screendump
