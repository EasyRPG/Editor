#-------------------------------------------------
#
# Project created by QtCreator 2013-09-28T16:21:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyRPG-Editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogresourcemanager.cpp \
    dialogdatabase.cpp

HEADERS  += mainwindow.h \
    dialogresourcemanager.h \
    dialogdatabase.h

FORMS    += mainwindow.ui \
    dialogresourcemanager.ui \
    dialogdatabase.ui

RESOURCES += \
    Resources.qrc
