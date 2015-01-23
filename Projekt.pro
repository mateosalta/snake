#-------------------------------------------------
#
# Project created by QtCreator 2014-12-14T20:04:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projekt
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    board.cpp \
    field.cpp \
    snake.cpp \
    space.cpp \
    pixmaps.cpp \
    wall.cpp \
    apple.cpp \
    rib.cpp \
    straight.cpp \
    head.cpp \
    tail.cpp \
    toleft.cpp \
    toright.cpp

HEADERS  += game.h \
    board.h \
    field.h \
    snake.h \
    space.h \
    pixmaps.h \
    wall.h \
    apple.h \
    rib.h \
    straight.h \
    head.h \
    tail.h \
    toleft.h \
    toright.h

FORMS    += game.ui

RESOURCES += \
    resources.qrc

# CONFIG += qt console
