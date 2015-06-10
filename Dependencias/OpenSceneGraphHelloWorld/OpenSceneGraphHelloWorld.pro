#-------------------------------------------------
#
# Project created by QtCreator 2014-07-26T20:06:33
#
#-------------------------------------------------

INCLUDEPATH += "C:\Program Files (x86)\OpenSceneGraph\include"

LIBS += -L"C:\Program Files (x86)\OpenSceneGraph\lib"
LIBS += -lOpenThreads -losg -losgAnimation -losgDB -losgFX -losgGA -losgManipulator -losgParticle -losgPresentation -losgShadow -losgSim -losgTerrain -losgText -losgUtil -losgViewer -losgVolume -losgWidget

QT       += core
QT       -= gui

TARGET = OpenSceneGraphHelloWorld

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
