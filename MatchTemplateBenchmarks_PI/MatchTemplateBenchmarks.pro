#-------------------------------------------------
#
# Project created by QtCreator 2014-09-29T17:55:54
#
#-------------------------------------------------

QT       += core gui

TARGET = MatchTemplateBenchmarks
TEMPLATE = app

SOURCES += main.cpp\
        MainWindow.cpp \
    VideoLoader.cpp \
    MatchTemplate.cpp \
    Helpers.cpp \
    Benchmark.cpp \
    Paths.cpp


HEADERS  += MainWindow.h \
    VideoLoader.h \
    MatchTemplate.h \
    Constantes.h \
    Helpers.h \
    Benchmark.h \
    Paths.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include/opencv-2.4.9
LIBS += -L/usr/local/lib/
LIBS += -lopencv_core
LIBS += -lopencv_highgui
LIBS += -lopencv_imgproc
LIBS += -lopencv_features2d
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_objdetect

