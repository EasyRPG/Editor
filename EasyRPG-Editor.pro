#-------------------------------------------------
#
# Project created by QtCreator 2013-09-28T16:21:38
#
#-------------------------------------------------

QT       += core gui multimedia winextras

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
    src/tools/qundodraw.cpp

HEADERS  += src/mainwindow.h \
    src/dialogresourcemanager.h \
    src/dialogdatabase.h \
    src/gamecharacter.h \
    src/gamecharactermodel.h \
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
    src/tools/qundodraw.h

FORMS    += src/mainwindow.ui \
    src/dialogresourcemanager.ui \
    src/dialogdatabase.ui \
    src/dialogimportimage.ui \
    src/dialognewproject.ui \
    src/dialogopenproject.ui \
    src/dialogimportproject.ui \
    src/dialogrtppath.ui

RESOURCES += \
    src/Resources.qrc

RC_FILE = src/Resources.rc

win32: LIBS += -LC:/Expat/Bin/ -llibexpat

INCLUDEPATH += C:/Expat/Bin
DEPENDPATH += C:/Expat/Bin

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/bin/release/ -lReaders
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/bin/debug/ -lReaders

INCLUDEPATH += $$PWD/libs/Readers/src
DEPENDPATH += $$PWD/libs/Readers/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libs/bin/release/libReaders.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libs/bin/debug/libReaders.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libs/bin/release/Readers.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libs/bin/debug/Readers.lib
