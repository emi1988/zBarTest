#-------------------------------------------------
#
# Project created by QtCreator 2016-02-11T22:34:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zBarTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


#LIBS += "C:\Program Files (x86)\ZBar\lib\libzbar-0.lib"

#INCLUDEPATH += "C:\Program Files (x86)\ZBar\include"
#DEPENDPATH += "C:\Program Files (x86)\ZBar\include"

unix:!macx: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lzbar

INCLUDEPATH += $$PWD/../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../usr/local/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../../usr/local/lib/libzbar.a
