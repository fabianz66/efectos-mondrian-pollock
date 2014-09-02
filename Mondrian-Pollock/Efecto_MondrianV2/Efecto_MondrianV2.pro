
# OpenCV
CVCFG = $$system(/bin/echo "pkg-config opencv")

SOURCES += \
    ManejoCamara.cpp

CVLIB = $$system($$CVCFG --libs)

LIBS += $$CVLIB
