#-------------------------------------------------
#
# Project created by QtCreator 2011-12-10T14:41:11
#
#-------------------------------------------------

QT       += core gui

TARGET = TrackingV1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Tracking.cpp \
    LabelImagen.cpp \

HEADERS  += mainwindow.h \
    Tracking.h \
    LabelImagen.h \

FORMS    += mainwindow.ui

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

RESOURCES += \
    images.qrc
