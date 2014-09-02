#-------------------------------------------------
#
# Project created by QtCreator 2011-08-23T15:13:51
#
#-------------------------------------------------

QT       += core gui

TARGET = Efecto_Mondrian
TEMPLATE = app


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
