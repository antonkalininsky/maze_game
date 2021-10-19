QT += core
QT -= gui

TARGET = maze_game
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    funs.cpp

HEADERS += \
    cursor.h \
    funs.h

