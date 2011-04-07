#-------------------------------------------------
#
# Project created by QtCreator 2011-04-06T12:53:21
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = SimplisticGraphing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphobject.cpp \
    connector.cpp \
    graphshape.cpp \
    idmanager.cpp \
    connectionpoint.cpp \
    graphsquare.cpp \
    graphellipse.cpp \
    graphdiamond.cpp \
    graphrectangle.cpp \
    graphtextbox.cpp

HEADERS  += mainwindow.h \
    graphobject.h \
    connector.h \
    graphshape.h \
    idmanager.h \
    connectionpoint.h \
    graphellipse.h \
    graphdiamond.h \
    graphrectangle.h \
    graphtextbox.h

FORMS    += mainwindow.ui
