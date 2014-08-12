#-------------------------------------------------
#
# Project created by QtCreator 2011-09-09T15:20:01
#
#-------------------------------------------------

QT       += core gui

TARGET = Efecto_Pollock
TEMPLATE = app


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

INCLUDEPATH += C:\OpenCV2.1\include\opencv \
               C:\OpenCV2.1\include

LIBS += -LC:\OpenCV2.1\lib \
        -lcv210 \
        -lcv210d \
        -lcvaux210 \
        -lcvaux210d \
        -lcxcore210 \
        -lcxcore210d \
        -lcxts210 \
        -lhighgui210 \
        -lhighgui210d \
        -lml210 \
        -lml210d \
        -lopencv_ffmpeg210 \
        -lopencv_ffmpeg210d
