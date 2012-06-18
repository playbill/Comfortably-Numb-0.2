#############################################################################
# Makefile for building: Calculator.app/Contents/MacOS/Calculator
# Generated by qmake (2.01a) (Qt 4.8.1) on: Mon Jun 18 19:14:36 2012
# Project:  Calculator.pro
# Template: app
# Command: /Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake -spec ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/macx-g++ CONFIG+=release CONFIG+=x86_64 -o Makefile Calculator.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -O2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
INCPATH       = -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/macx-g++ -I. -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/lib/QtCore.framework/Versions/4/Headers -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/include/QtCore -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/lib/QtGui.framework/Versions/4/Headers -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/include/QtGui -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/include -I. -I. -F/Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/lib
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5
LIBS          = $(SUBLIBS) -F/Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/lib -L/Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/lib -framework QtGui -L/usr/local/pgsql/lib -L/tmp/qt-stuff-85167/source/qt-everywhere-opensource-src-4.8.1/Desktop/Qt/4.8.1/gcc/lib -F/tmp/qt-stuff-85167/source/qt-everywhere-opensource-src-4.8.1/Desktop/Qt/4.8.1/gcc/lib -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		element.cpp \
		pile.cpp \
		calculateur.cpp \
		command.cpp \
		commandcalculateur.cpp moc_mainwindow.cpp
OBJECTS       = main.o \
		mainwindow.o \
		element.o \
		pile.o \
		calculateur.o \
		command.o \
		commandcalculateur.o \
		moc_mainwindow.o
DIST          = ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/mac.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-macx.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-macx.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/default_pre.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/default_post.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/x86_64.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/objective_c.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/rez.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/sdk.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		Calculator.pro
QMAKE_TARGET  = Calculator
DESTDIR       = 
TARGET        = Calculator.app/Contents/MacOS/Calculator

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-O2 \
		-arch \
		x86_64 \
		-Xarch_x86_64 \
		-mmacosx-version-min=10.5 \
		-Wall \
		-W


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

all: Makefile Calculator.app/Contents/PkgInfo Calculator.app/Contents/Resources/empty.lproj Calculator.app/Contents/Info.plist $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) Calculator.app/Contents/MacOS/ || $(MKDIR) Calculator.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Calculator.pro  ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/macx-g++/qmake.conf ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/mac.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-macx.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-macx.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/default_pre.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/default_post.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/x86_64.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/objective_c.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/rez.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/sdk.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		/Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/lib/QtGui.framework/QtGui.prl \
		/Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/lib/QtCore.framework/QtCore.prl
	$(QMAKE) -spec ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/macx-g++ CONFIG+=release CONFIG+=x86_64 -o Makefile Calculator.pro
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/mac.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-macx.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-macx.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/default_pre.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/default_post.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/x86_64.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/objective_c.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/rez.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/mac/sdk.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf:
/Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/lib/QtGui.framework/QtGui.prl:
/Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/lib/QtCore.framework/QtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/macx-g++ CONFIG+=release CONFIG+=x86_64 -o Makefile Calculator.pro

Calculator.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) Calculator.app/Contents || $(MKDIR) Calculator.app/Contents 
	@$(DEL_FILE) Calculator.app/Contents/PkgInfo
	@echo "APPL????" >Calculator.app/Contents/PkgInfo
Calculator.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) Calculator.app/Contents/Resources || $(MKDIR) Calculator.app/Contents/Resources 
	@touch Calculator.app/Contents/Resources/empty.lproj
	
Calculator.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) Calculator.app/Contents || $(MKDIR) Calculator.app/Contents 
	@$(DEL_FILE) Calculator.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,Calculator,g" -e "s,@TYPEINFO@,????,g" ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/macx-g++/Info.plist.app >Calculator.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/Calculator1.0.0 || $(MKDIR) .tmp/Calculator1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Calculator1.0.0/ && $(COPY_FILE) --parents mainwindow.h element.h pile.h calculateur.h command.h commandcalculateur.h .tmp/Calculator1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp element.cpp pile.cpp calculateur.cpp command.cpp commandcalculateur.cpp .tmp/Calculator1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/Calculator1.0.0/ && (cd `dirname .tmp/Calculator1.0.0` && $(TAR) Calculator1.0.0.tar Calculator1.0.0 && $(COMPRESS) Calculator1.0.0.tar) && $(MOVE) `dirname .tmp/Calculator1.0.0`/Calculator1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Calculator1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r Calculator.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: commandcalculateur.h \
		command.h \
		calculateur.h \
		pile.h \
		element.h \
		mainwindow.h
	/Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/Users/Titouan/QtSDK/Desktop/Qt/4.8.1/gcc/bin/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		commandcalculateur.h \
		command.h \
		calculateur.h \
		pile.h \
		element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		commandcalculateur.h \
		command.h \
		calculateur.h \
		pile.h \
		element.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

element.o: element.cpp element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o element.o element.cpp

pile.o: pile.cpp pile.h \
		element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pile.o pile.cpp

calculateur.o: calculateur.cpp calculateur.h \
		command.h \
		pile.h \
		element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o calculateur.o calculateur.cpp

command.o: command.cpp command.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o command.o command.cpp

commandcalculateur.o: commandcalculateur.cpp commandcalculateur.h \
		command.h \
		calculateur.h \
		pile.h \
		element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o commandcalculateur.o commandcalculateur.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

