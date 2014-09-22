#-------------------------------------------------
#
# Project created by QtCreator 2011-08-23T15:13:51
#
#-------------------------------------------------

QT       += core gui

TARGET = Efecto_Mondrian
TEMPLATE = app

# OpenCV
CVCFG = $$system(/bin/echo "pkg-config opencv")

SOURCES +=\
    Observable.cpp \
    Controller.cpp \
    ManejoCamara.cpp \
    VentanaPrincipal.cpp

HEADERS  += \
    Observable.h \
    Observer.h \
    Controller.h \
    ManejoCamara.h \
    Constantes.h \
    VentanaPrincipal.h

FORMS    += \
    VentanaPrincipal.ui

RESOURCES += Imagenes.qrc

CVLIB = $$system($$CVCFG --libs)

LIBS += $$CVLIB
