# OpenCV
CVCFG = $$system(/bin/echo "pkg-config opencv")

HEADERS += \
    videoloader.h

SOURCES += \
    videoloader.cpp \
    main.cpp

CVLIB = $$system($$CVCFG --libs)

LIBS += $$CVLIB
