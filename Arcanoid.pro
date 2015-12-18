#-------------------------------------------------
#
# Project created by QtCreator 2015-12-09T12:46:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Arcanoid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Ball.cpp \
    Block.cpp \
    GameField.cpp \
    mainwidget.cpp \
    collision.cpp

HEADERS  += mainwindow.h \
    gamefield.h \
    ball.h \
    block.h \
    mainwidget.h \
    constants.h \
    collision.h

FORMS    += mainwindow.ui
