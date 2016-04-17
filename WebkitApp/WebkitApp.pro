#-------------------------------------------------
#
# Project created by QtCreator 2016-04-08T17:28:20
#
#-------------------------------------------------

QT       += core gui printsupport
QT       += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebkitApp
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    betterwebview.cpp

HEADERS  += mainwindow.h \
    betterwebview.h

FORMS    += mainwindow.ui
