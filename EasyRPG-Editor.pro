#-------------------------------------------------
#
# Project created by QtCreator 2013-09-28T16:21:38
#
#-------------------------------------------------

QT       += core gui multimedia concurrent
win32:QT += winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32:TARGET = EasyRPG-Editor
TEMPLATE = app

SOURCES += src/mainwindow.cpp \
    src/main.cpp \
    src/dialogresourcemanager.cpp \
    src/dialogdatabase.cpp \
    src/dialogimportimage.cpp \
    src/dialognewproject.cpp \
    src/gamecharacter.cpp \
    src/dialogopenproject.cpp \
    src/musicplayer.cpp \
    src/volumebutton.cpp \
    src/core.cpp \
    src/dialogimportproject.cpp \
    src/dialogrtppath.cpp \
    src/dialogrungame.cpp \
    src/tools/qundodraw.cpp \
    src/dialogevent.cpp \
    src/dialogmapproperties.cpp \
    src/tools/qundoevent.cpp \
    src/dialogcharapicker.cpp \
    src/dialogsplash.cpp \
    src/tools/qeventpagewidget.cpp \
    src/tools/qgraphicscharaitem.cpp \
    src/tools/qgraphicsimportitem.cpp \
    src/tools/qgraphicsmapscene.cpp \
    src/tools/qgraphicspaletescene.cpp \
    src/tools/qgraphicspickerscene.cpp \
    src/tools/qdbpageactors.cpp \
    src/tools/qgraphicsfaceitem.cpp \
    src/dialogfacepicker.cpp \
    src/tools/qgraphicsbattleanimationitem.cpp \
    src/tools/qdbpageclasses.cpp \
    src/tools/qdbpageskills.cpp \
    src/tools/qdbpageitems.cpp \
    src/tools/qdbpageenemies.cpp \
    src/tools/qdbpageenemygroups.cpp \
    src/tools/qdbpageherostatus.cpp \
    src/tools/qdbpagebattleanimations.cpp \
    src/tools/qdbpagebattleanimations2.cpp \
    src/tools/qdbpagebattlescreen.cpp \
    src/tools/qdbpageterrain.cpp \
    src/tools/qdbpagechipset.cpp \
    src/tools/qdbpagevocabulary.cpp \
    src/tools/qdbpagesystem.cpp \
    src/tools/qdbpagesystem2.cpp \
    src/tools/qdbpagecommonevents.cpp \
    src/tools/qdbpageattributes.cpp \
    src/tools/qgraphicscurveitem.cpp \
    src/tools/qactordelegate.cpp \
    src/tools/qencounterdelegate.cpp \
    src/stringizer.cpp \
    src/core/project.cpp \
    src/core/exception.cpp \
    src/core/projectsettings.cpp

HEADERS  += src/mainwindow.h \
    src/dialogresourcemanager.h \
    src/dialogdatabase.h \
    src/gamecharacter.h \
    src/dialogimportimage.h \
    src/dialognewproject.h \
    src/dialogopenproject.h \
    src/musicplayer.h \
    src/volumebutton.h \
    src/core.h \
    src/dialogimportproject.h \
    src/dialogrtppath.h \
    src/dialogrungame.h \
    src/tools/qundodraw.h \
    src/dialogmapproperties.h \
    src/dialogevent.h \
    src/tools/qundoevent.h \
    src/dialogcharapicker.h \
    src/dialogsplash.h \
    src/tools/qeventpagewidget.h \
    src/tools/qgraphicscharaitem.h \
    src/tools/qgraphicsimportitem.h \
    src/tools/qgraphicsmapscene.h \
    src/tools/qgraphicspaletescene.h \
    src/tools/qgraphicspickerscene.h \
    src/tools/qdbpageactors.h \
    src/tools/qgraphicsfaceitem.h \
    src/dialogfacepicker.h \
    src/tools/qgraphicsbattleanimationitem.h \
    src/tools/qdbpageclasses.h \
    src/tools/qdbpageskills.h \
    src/tools/qdbpageitems.h \
    src/tools/qdbpageenemies.h \
    src/tools/qdbpageenemygroups.h \
    src/tools/qdbpageherostatus.h \
    src/tools/qdbpagebattleanimations.h \
    src/tools/qdbpagebattleanimations2.h \
    src/tools/qdbpagebattlescreen.h \
    src/tools/qdbpageterrain.h \
    src/tools/qdbpagechipset.h \
    src/tools/qdbpagevocabulary.h \
    src/tools/qdbpagesystem.h \
    src/tools/qdbpagesystem2.h \
    src/tools/qdbpagecommonevents.h \
    src/tools/qdbpageattributes.h \
    src/tools/qgraphicscurveitem.h \
    src/tools/qactordelegate.h \
    src/tools/qencounterdelegate.h \
    src/stringizer.h \
    src/core/project.h \
    src/core/exception.h \
    src/core/projectsettings.h \
    src/core/enums.h

FORMS    += src/mainwindow.ui \
    src/dialogresourcemanager.ui \
    src/dialogdatabase.ui \
    src/dialogimportimage.ui \
    src/dialognewproject.ui \
    src/dialogopenproject.ui \
    src/dialogimportproject.ui \
    src/dialogrtppath.ui \
    src/dialogrungame.ui \
    src/dialogmapproperties.ui \
    src/dialogevent.ui \
    src/dialogcharapicker.ui \
    src/dialogsplash.ui \
    src/tools/qeventpagewidget.ui \
    src/tools/qdbpageactors.ui \
    src/tools/qdbpageclasses.ui \
    src/tools/qdbpageskills.ui \
    src/tools/qdbpageitems.ui \
    src/tools/qdbpageenemies.ui \
    src/tools/qdbpageenemygroups.ui \
    src/tools/qdbpageherostatus.ui \
    src/tools/qdbpagebattleanimations.ui \
    src/tools/qdbpagebattleanimations2.ui \
    src/tools/qdbpagebattlescreen.ui \
    src/tools/qdbpageterrain.ui \
    src/tools/qdbpagechipset.ui \
    src/tools/qdbpagevocabulary.ui \
    src/tools/qdbpagesystem.ui \
    src/tools/qdbpagesystem2.ui \
    src/tools/qdbpagecommonevents.ui \
    src/tools/qdbpageattributes.ui

RESOURCES += \
    src/Resources.qrc

QMAKE_CXXFLAGS += -std=c++11

RC_FILE = src/Resources.rc

DESTDIR = bin

CONFIG(debug, debug|release) TARGET = EasyRPG-EditorD

win32 {
    INCLUDEPATH += $$PWD/libs/liblcf/src
    DEPENDPATH += $$PWD/libs/liblcf/src
    INCLUDEPATH += $$PWD/libs/liblcf/src/generated
    DEPENDPATH += $$PWD/libs/liblcf/src/generated
    INCLUDEPATH += $$(EASYDEV_MSVC)/include
    DEPENDPATH += $$(EASYDEV_MSVC)/include

    LIBS += Advapi32.lib

    CONFIG(debug, debug|release) {
	LIBS += /NODEFAULTLIB:libcmtd.lib
	LIBS += -L$$PWD/libs/liblcf/lib/debug/
	!contains(QMAKE_HOST.arch, x86_64) {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/v100/x86/Debug -llibexpat
	    LIBS += -lsicudtd -lsicuucd -lsicuind -lliblcf
	} else {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/v100/amd64/Debug -llibexpat
	    LIBS += -lsicudtd -lsicuucd -lsicuind -lliblcf64
	}
    }
    CONFIG(release, debug|release) {
	LIBS += /NODEFAULTLIB:libcmt.lib
	LIBS += -L$$PWD/libs/liblcf/lib/release/
	!contains(QMAKE_HOST.arch, x86_64) {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/v100/x86/Release -llibexpat
	    LIBS += -lsicudt -lsicuuc -lsicuin -lliblcf
	} else {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/v100/amd64/Release -llibexpat
	    LIBS += -lsicudt -lsicuuc -lsicuin -lliblcf64
	}
    }
}

!win32:TARGET = easyrpg-editor
!win32:QMAKE_CXXFLAGS += -Wall -Wextra -ansi -pedantic -std=c++0x
!win32:QMAKE_CXXFLAGS_DEBUG += -O0 -g3
!win32:CONFIG += link_pkgconfig silent
!win32:PKGCONFIG += liblcf
