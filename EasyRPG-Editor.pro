lessThan(QT_MAJOR_VERSION, 5): error("Qt 5 required")

QT       += core gui multimedia concurrent widgets
win32:QT += winextras

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
    src/dialogsearch.cpp \
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
    src/dialogedit.cpp \
    src/commands/changemoney.cpp \
    src/commands/changeparty.cpp \
    src/commands/changeitem.cpp \
    src/commands/changeexperience.cpp \
    src/commands/messageoptions.cpp \
    src/commands/showmessage.cpp \
    src/commands/facegraphics.cpp \
    src/commands/inputnumber.cpp \
    src/commands/showchoices.cpp \
    src/commands/switchoperations.cpp \
    src/commands/variableoperations.cpp

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
    src/dialogsearch.h \
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
    src/dialogedit.h \
    src/tools/rpgmodel.h \
    src/tools/rpgcombobox.h \
    src/commands/changemoney.h \
    src/commands/changeparty.h \
    src/commands/changeitem.h

FORMS    += src/mainwindow.ui \
    src/dialogresourcemanager.ui \
    src/dialogdatabase.ui \
    src/dialogimportimage.ui \
    src/dialognewproject.ui \
    src/dialogopenproject.ui \
    src/dialogimportproject.ui \
    src/dialogsearch.ui \
    src/dialogrtppath.ui \
    src/dialogrungame.ui \
    src/dialogmapproperties.ui \
    src/dialogevent.ui \
    src/dialogcharapicker.ui \
    src/dialogsplash.ui \
    src/dialogedit.ui \
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
    src/tools/qdbpageattributes.ui \
    src/commands/changemoney.ui \
    src/commands/changeparty.ui \
    src/commands/changeitem.ui

RESOURCES += \
    src/Resources.qrc

RC_FILE = src/Resources.rc


DESTDIR = bin

CONFIG(debug, debug|release) TARGET = EasyRPG-EditorD

CONFIG += c++11

win32 {
    INCLUDEPATH += $$PWD/libs/liblcf/src
    DEPENDPATH += $$PWD/libs/liblcf/src
    INCLUDEPATH += $$PWD/libs/liblcf/src/generated
    DEPENDPATH += $$PWD/libs/liblcf/src/generated
    INCLUDEPATH += $$(EASYDEV_MSVC)/include
    DEPENDPATH += $$(EASYDEV_MSVC)/include

    LIBS += Advapi32.lib

    CONFIG(debug, debug|release) {
	!contains(QMAKE_HOST.arch, x86_64) {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/x86/Debug -llibexpat
	    LIBS += -lsicudtd -lsicuucd -lsicuind -lliblcf
	} else {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/amd64/Debug -llibexpat
	    LIBS += -lsicudtd -lsicuucd -lsicuind -lliblcf
	}
    }
    CONFIG(release, debug|release) {
	!contains(QMAKE_HOST.arch, x86_64) {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/x86/Release -llibexpat
	    LIBS += -lsicudt -lsicuuc -lsicuin -lliblcf
	} else {
	    LIBS += -L$$(EASYDEV_MSVC)/lib/amd64/Release -llibexpat
	    LIBS += -lsicudt -lsicuuc -lsicuin -lliblcf
	}
    }

    QMAKE_LFLAGS_RELEASE = /LTCG
}

unix {
    TARGET = easyrpg-editor
    QMAKE_CXXFLAGS += -Wall -Wextra -pedantic
    QMAKE_CXXFLAGS_DEBUG += -O0 -g3
    CONFIG += link_pkgconfig silent
    PKGCONFIG += liblcf
}
