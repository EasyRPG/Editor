#-------------------------------------------------
#
# Project created by QtCreator 2013-09-28T16:21:38
#
#-------------------------------------------------

QT       += core gui multimedia winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  multimedia winextras

TARGET = EasyRPG-Editor
TEMPLATE = app


SOURCES += src/mainwindow.cpp \
    src/main.cpp \
    src/dialogresourcemanager.cpp \
    src/dialogdatabase.cpp \
    src/gameproject.cpp \
    src/dialogimportimage.cpp \
    src/dialognewproject.cpp \
    src/tools/QGraphicsImportItem.cpp \
    src/gamecharacter.cpp \
    src/dialogopenproject.cpp \
    src/EasyRPGCore.cpp \
    src/gamemap.cpp \
    src/musicplayer.cpp \
    src/tools/QGraphicsPaleteScene.cpp \
    src/volumebutton.cpp

HEADERS  += src/mainwindow.h \
    src/dialogresourcemanager.h \
    src/dialogdatabase.h \
    src/gamecharacter.h \
    src/gamecharactermodel.h \
    src/gameproject.h \
    src/dialogimportimage.h \
    src/dialognewproject.h \
    src/tools/QGraphicsImportItem.h \
    src/tools/picojson.h \
    src/dialogopenproject.h \
    src/EasyRPGCore.h \
    src/gamemap.h \
    src/musicplayer.h \
    src/tools/QGraphicsPaleteScene.h \
    src/volumebutton.h

FORMS    += src/mainwindow.ui \
    src/dialogresourcemanager.ui \
    src/dialogdatabase.ui \
    src/dialogimportimage.ui \
    src/dialognewproject.ui \
    src/dialogopenproject.ui

RESOURCES += \
    src/Resources.qrc
