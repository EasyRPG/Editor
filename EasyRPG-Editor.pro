#-------------------------------------------------
#
# Project created by QtCreator 2013-09-28T16:21:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    src/gamecharacter.cpp

HEADERS  += src/mainwindow.h \
    src/dialogresourcemanager.h \
    src/dialogdatabase.h \
    src/gamecharacter.h \
    src/gamecharactermodel.h \
    src/gameproject.h \
    src/dialogimportimage.h \
    src/dialognewproject.h \
    src/tools/QGraphicsImportItem.h \
    src/tools/picojson.h

FORMS    += src/mainwindow.ui \
    src/dialogresourcemanager.ui \
    src/dialogdatabase.ui \
    src/dialogimportimage.ui \
    src/dialognewproject.ui

RESOURCES += \
    src/Resources.qrc
