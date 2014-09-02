#-------------------------------------------------
#
# Project created by QtCreator 2011-09-09T15:20:01
#
#-------------------------------------------------

QT       += core gui

TARGET = Efecto_Pollock
TEMPLATE = app

# OpenCV
CVCFG = $$system(/bin/echo "pkg-config opencv")

SOURCES +=\
        VentanaPrincipal.cpp \
    Observable.cpp \
    ManejoPrograma.cpp \
    ManejoEfecto.cpp \
    ManejoCamara.cpp \
    Controller.cpp \
    VentanaAjustes.cpp

HEADERS  += VentanaPrincipal.h \
    Observer.h \
    Observable.h \
    ManejoPrograma.h \
    ManejoEfecto.h \
    ManejoCamara.h \
    Controller.h \
    Constantes.h \
    VentanaAjustes.h

FORMS    += VentanaPrincipal.ui \
    VentanaAjustes.ui

RESOURCES += \
    images.qrc

CVLIB = $$system($$CVCFG --libs)

LIBS += $$CVLIB
