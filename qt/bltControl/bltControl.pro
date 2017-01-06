#-------------------------------------------------
#
# Project created by QtCreator 2017-01-06T00:13:40
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bltControl
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    modelwidget.cpp \
    playerwidget.cpp \
    component.cpp \
    inputwidget.cpp \
    controlwidget.cpp \
    audioanalyzerwidget.cpp \
    metronomwidget.cpp \
    oscinputwidget.cpp \
    input.cpp \
    programs/program.cpp \
    programs/programrandom.cpp \
    programs/programdiagonals.cpp

HEADERS  += mainwindow.h \
    modelwidget.h \
    playerwidget.h \
    component.h \
    inputwidget.h \
    controlwidget.h \
    audioanalyzerwidget.h \
    metronomwidget.h \
    oscinputwidget.h \
    input.h \
    programs/program.h \
    programs/programrandom.h \
    programs/programdiagonals.h

CONFIG += mobility c++11
MOBILITY = 

include(../QOSC/QOSC.pri)
