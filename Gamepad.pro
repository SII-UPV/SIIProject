#-------------------------------------------------
#
# Project created by QtCreator 2015-05-25T21:59:07
#
#-------------------------------------------------



TARGET = Gamepad2
TEMPLATE = app

CONFIG    += qt thread c++11

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

MOC_DIR = gen/
UI_DIR = gen/
RCC_DIR = gen/
INCLUDEPATH +=  $$PWD/


SOURCES += main.cpp\
        mainwindow.cpp \
    gamepadinfo.cpp \
    gamepad.cpp \
    gamepaddialog.cpp

HEADERS  += mainwindow.h \
    gamepadinfo.h \
    gamepad.h \
    gamepaddialog.h

FORMS    += mainwindow.ui \
    gamepaddialog.ui

LIBS += -L "C:\SDL1.2\SDL-1.2.15\lib" -lSDL
INCLUDEPATH += "C:\SDL1.2\SDL-1.2.15\include\SDL"
win32 {
    DEFINES += SDL_WIN
}

RESOURCES += \
    resources.qrc
