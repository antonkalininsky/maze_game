QT += core gui
QT += widgets
QT += gui

TARGET = maze_game
CONFIG += gui C++11
CONFIG -= console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    funs.cpp \
    waycreator.cpp \
    tile.cpp \
    game.cpp \
    board.cpp \
    mapcreator.cpp

HEADERS += \
    funs.h \
    waycreator.h \
    tile.h \
    game.h \
    board.h \
    position.h \
    mapcreator.h
