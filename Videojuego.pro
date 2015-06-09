QT += network widgets

INCLUDEPATH += "C:\Program Files (x86)\OpenSceneGraph\include"

LIBS += -L"C:\Program Files (x86)\OpenSceneGraph\lib"
LIBS += -lOpenThreads -losg -losgAnimation -losgDB -losgFX -losgGA -losgManipulator -losgParticle -losgPresentation -losgShadow -losgSim -losgTerrain -losgText -losgUtil -losgViewer -losgVolume -losgWidget

HEADERS = mainwindow.h \
          videojuego.h \
          cconexion.h \
          ccomunicacionservidor.h \
          ccomunicacioncliente.h \
          cesfera.h \
          ccaja.h \
          cpersona.h \
          crobot.h \
          cescena.h \
          cvista2d.h \
          cvista3d.h \
          ccontrolpersona.h \
          ccontrolrobot.h \
          cacercade.h

SOURCES = mainwindow.cpp \
          cconexion.cpp \
          ccomunicacionservidor.cpp \
          ccomunicacioncliente.cpp \
          cesfera.cpp \
          ccaja.cpp \
          cpersona.cpp \
          crobot.cpp \
          cescena.cpp \
          cvista2d.cpp \
          cvista3d.cpp \
          ccontrolpersona.cpp \
          ccontrolrobot.cpp \
          main.cpp \
          cacercade.cpp

FORMS = mainwindow.ui \
        cvista2d.ui \
        ccontrolpersona.ui \
        ccontrolrobot.ui \
        cacercade.ui
