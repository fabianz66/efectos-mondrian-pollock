#-------------------------------------------------
#
# Project created by QtCreator 2014-09-16T23:41:24
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

# OpenCV
CVCFG = $$system(/bin/echo "pkg-config opencv")

TARGET = tst_benchmarktesttest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    main.cpp \
    MatchTemplateTest.cpp \
    Parallel_process.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    MatchTemplateTest.h \
    Parallel_process.h

CVLIB = $$system($$CVCFG --libs)

LIBS += $$CVLIB
