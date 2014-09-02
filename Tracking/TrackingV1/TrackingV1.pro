#-------------------------------------------------
#
# Project created by QtCreator 2011-12-10T14:41:11
#
#-------------------------------------------------

QT       += core gui

TARGET = TrackingV1
TEMPLATE = app

# OpenCV
CVCFG = $$system(/bin/echo "pkg-config opencv")

SOURCES += main.cpp\
        mainwindow.cpp \
    Tracking.cpp \
    LabelImagen.cpp \

HEADERS  += mainwindow.h \
    Tracking.h \
    LabelImagen.h \

FORMS    += mainwindow.ui

CVLIB = $$system($$CVCFG --libs)

LIBS += $$CVLIB

RESOURCES += \
    images.qrc
