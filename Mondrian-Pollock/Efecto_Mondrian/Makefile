#############################################################################
# Makefile for building: Efecto_Mondrian
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue Sep 9 07:56:58 2014
# Project:  Efecto_Mondrian.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Efecto_Mondrian.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_ocl.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_superres.so /usr/local/lib/libopencv_ts.a /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so /usr/lib/i386-linux-gnu/libXext.so /usr/lib/i386-linux-gnu/libX11.so /usr/lib/i386-linux-gnu/libICE.so /usr/lib/i386-linux-gnu/libSM.so /usr/lib/i386-linux-gnu/libGL.so /usr/lib/i386-linux-gnu/libGLU.so -ltbb -lrt -lm -ldl -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = Observable.cpp \
		Controller.cpp \
		ManejoCamara.cpp \
		VentanaPrincipal.cpp moc_VentanaPrincipal.cpp \
		qrc_Imagenes.cpp
OBJECTS       = Observable.o \
		Controller.o \
		ManejoCamara.o \
		VentanaPrincipal.o \
		moc_VentanaPrincipal.o \
		qrc_Imagenes.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Efecto_Mondrian.pro
QMAKE_TARGET  = Efecto_Mondrian
DESTDIR       = 
TARGET        = Efecto_Mondrian

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_VentanaPrincipal.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Efecto_Mondrian.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Efecto_Mondrian.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile Efecto_Mondrian.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Efecto_Mondrian1.0.0 || $(MKDIR) .tmp/Efecto_Mondrian1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Efecto_Mondrian1.0.0/ && $(COPY_FILE) --parents Observable.h Observer.h Controller.h ManejoCamara.h Constantes.h VentanaPrincipal.h .tmp/Efecto_Mondrian1.0.0/ && $(COPY_FILE) --parents Imagenes.qrc .tmp/Efecto_Mondrian1.0.0/ && $(COPY_FILE) --parents Observable.cpp Controller.cpp ManejoCamara.cpp VentanaPrincipal.cpp .tmp/Efecto_Mondrian1.0.0/ && $(COPY_FILE) --parents VentanaPrincipal.ui .tmp/Efecto_Mondrian1.0.0/ && (cd `dirname .tmp/Efecto_Mondrian1.0.0` && $(TAR) Efecto_Mondrian1.0.0.tar Efecto_Mondrian1.0.0 && $(COMPRESS) Efecto_Mondrian1.0.0.tar) && $(MOVE) `dirname .tmp/Efecto_Mondrian1.0.0`/Efecto_Mondrian1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Efecto_Mondrian1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_VentanaPrincipal.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_VentanaPrincipal.cpp
moc_VentanaPrincipal.cpp: Observable.h \
		Observer.h \
		Constantes.h \
		VentanaPrincipal.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) VentanaPrincipal.h -o moc_VentanaPrincipal.cpp

compiler_rcc_make_all: qrc_Imagenes.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_Imagenes.cpp
qrc_Imagenes.cpp: Imagenes.qrc \
		Imagenes/fondo_inicio.jpg \
		Imagenes/fondo_ajustes.jpg \
		Imagenes/help_icon.jpg \
		Imagenes/titulo.jpg \
		Imagenes/icono.jpg \
		Imagenes/boton_small.jpg
	/usr/bin/rcc -name Imagenes Imagenes.qrc -o qrc_Imagenes.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_VentanaPrincipal.h
compiler_uic_clean:
	-$(DEL_FILE) ui_VentanaPrincipal.h
ui_VentanaPrincipal.h: VentanaPrincipal.ui
	/usr/bin/uic-qt4 VentanaPrincipal.ui -o ui_VentanaPrincipal.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

Observable.o: Observable.cpp Observable.h \
		Observer.h \
		Constantes.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Observable.o Observable.cpp

Controller.o: Controller.cpp Controller.h \
		ManejoCamara.h \
		VentanaPrincipal.h \
		Observable.h \
		Observer.h \
		Constantes.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Controller.o Controller.cpp

ManejoCamara.o: ManejoCamara.cpp ManejoCamara.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ManejoCamara.o ManejoCamara.cpp

VentanaPrincipal.o: VentanaPrincipal.cpp VentanaPrincipal.h \
		Observable.h \
		Observer.h \
		Constantes.h \
		ui_VentanaPrincipal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o VentanaPrincipal.o VentanaPrincipal.cpp

moc_VentanaPrincipal.o: moc_VentanaPrincipal.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_VentanaPrincipal.o moc_VentanaPrincipal.cpp

qrc_Imagenes.o: qrc_Imagenes.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_Imagenes.o qrc_Imagenes.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

