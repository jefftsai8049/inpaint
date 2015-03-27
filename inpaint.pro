#-------------------------------------------------
#
# Project created by QtCreator 2015-01-13T13:51:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = inpaint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h
INCLUDEPATH += C:\\opencv30b\\x64\\include \
                C:\\opencv30b\\x64\\include\\opencv \
                C:\\opencv30b\\x64\\include\\opencv2


LIBS += C:\\opencv30b\\x64\\lib\\opencv_world300.lib \
        C:\\opencv30b\\x64\\lib\\opencv_world300d.lib \
        C:\\opencv30b\\x64\\lib\\opencv_ts300.lib

FORMS    += mainwindow.ui
