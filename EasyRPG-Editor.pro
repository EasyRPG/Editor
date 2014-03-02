#-------------------------------------------------
#
# Project created by QtCreator 2013-09-28T16:21:38
#
#-------------------------------------------------

QT       += core gui multimedia
win32:QT += winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyRPG-Editor
TEMPLATE = app

SOURCES += src/mainwindow.cpp \
    src/main.cpp \
    src/dialogresourcemanager.cpp \
    src/dialogdatabase.cpp \
    src/dialogimportimage.cpp \
    src/dialognewproject.cpp \
    src/tools/QGraphicsImportItem.cpp \
    src/gamecharacter.cpp \
    src/dialogopenproject.cpp \
    src/musicplayer.cpp \
    src/tools/QGraphicsPaleteScene.cpp \
    src/volumebutton.cpp \
    src/core.cpp \
    src/tools/QGraphicsMapScene.cpp \
    src/dialogimportproject.cpp \
    src/dialogrtppath.cpp \
    src/dialogrungame.cpp \
    src/tools/qundodraw.cpp \
    src/dialogEvent.cpp

HEADERS  += src/mainwindow.h \
    src/dialogresourcemanager.h \
    src/dialogdatabase.h \
    src/gamecharacter.h \
    src/dialogimportimage.h \
    src/dialognewproject.h \
    src/tools/QGraphicsImportItem.h \
    src/tools/picojson.h \
    src/dialogopenproject.h \
    src/musicplayer.h \
    src/tools/QGraphicsPaleteScene.h \
    src/volumebutton.h \
    src/core.h \
    src/tools/QGraphicsMapScene.h \
    src/dialogimportproject.h \
    src/dialogrtppath.h \
    src/dialogrungame.h \
    src/tools/qundodraw.h \
    src/dialogEvent.h

FORMS    += src/mainwindow.ui \
    src/dialogresourcemanager.ui \
    src/dialogdatabase.ui \
    src/dialogimportimage.ui \
    src/dialognewproject.ui \
    src/dialogopenproject.ui \
    src/dialogimportproject.ui \
    src/dialogrtppath.ui \
    src/dialogevent.ui

RESOURCES += \
    src/Resources.qrc

RC_FILE = src/Resources.rc

INCLUDEPATH += $$PWD/libs/Readers/include
DEPENDPATH += $$PWD/libs/Readers/include

DESTDIR = bin

debug: TARGET = EasyRPG-EditorD

win32 {
    INCLUDEPATH += $$(EASYDEV_MSVC)/include
    DEPENDPATH += $$(EASYDEV_MSVC)/include

CONFIG(debug, debug|release) {
	LIBS += -L$$PWD/libs/Readers/lib/debug/
	!contains(QMAKE_HOST.arch, x86_64) {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/v100/x86/Debug -llibexpat
	    LIBS += -lReaders
	} else {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/v100/amd64/Debug -llibexpat
	    LIBS += -lReaders64
	}
    }
CONFIG(release, debug|release) {
	LIBS += -L$$PWD/libs/Readers/lib/release/
	!contains(QMAKE_HOST.arch, x86_64) {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/v100/x86/Release -llibexpat
	    LIBS += -lReaders
	} else {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/v100/amd64/Release -llibexpat
	    LIBS += -lReaders64
	}
    }
}

!win32:LIBS += -lexpat -lreaders
#!win32:QMAKE_CXXFLAGS += -Wextra -ansi -pedantic
!win32:QMAKE_CXXFLAGS_DEBUG += -O0 -g3
!win32:QMAKE_CXXFLAGS += -std=c++0x
