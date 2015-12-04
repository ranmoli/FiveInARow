#-------------------------------------------------
#
# Project created by QtCreator 2015-11-27T19:40:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FiveInARow
TEMPLATE = app
CONFIG += C++11

SOURCES += main.cpp\
        MenuWindow.cpp \
    GameWindow.cpp \
    ChessBoard.cpp \
    Piece.cpp \
    Player.cpp \
    AI.cpp

HEADERS  += MenuWindow.h \
    GameWindow.h \
    ChessBoard.h \
    Piece.h \
    Player.h \
    AI.h

FORMS    += MenuWindow.ui \
    GameWindow.ui
