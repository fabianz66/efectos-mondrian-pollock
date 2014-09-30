#-------------------------------------------------
#
# Project created by QtCreator 2014-09-29T17:55:54
#
#-------------------------------------------------

QT       += core gui

TARGET = MatchTemplateBenchmarks
TEMPLATE = app

# OpenCV
CVCFG = $$system(/bin/echo "pkg-config opencv")

SOURCES += main.cpp\
        MainWindow.cpp \
    VideoLoader.cpp


HEADERS  += MainWindow.h \
    VideoLoader.h

FORMS    += mainwindow.ui

CVLIB = $$system($$CVCFG --libs)

LIBS += $$CVLIB


