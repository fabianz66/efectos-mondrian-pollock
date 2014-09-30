# OpenCV
CVCFG = $$system(/bin/echo "pkg-config opencv")

HEADERS += \
    VideoLoader.h \
    VideoLoaderListener.h \
    Test.h

SOURCES += \
    main.cpp \
    VideoLoader.cpp \
    Test.cpp

CVLIB = $$system($$CVCFG --libs)

LIBS += $$CVLIB
