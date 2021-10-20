QT += core gui
QT += widgets
QT += gui

TARGET = maze_game
CONFIG += gui
CONFIG -= console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    funs.cpp \
    waycreator.cpp \
    tile.cpp \
    mazeblueprint.cpp \
    game.cpp \
    board.cpp

HEADERS += \
    cursor.h \
    funs.h \
    waycreator.h \
    tile.h \
    mazeblueprint.h \
    game.h \
    board.h
