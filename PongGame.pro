#-------------------------------------------------
#
# Project created by QtCreator 2017-04-22T22:45:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PongGame
TEMPLATE = app
CONFIG += c++14
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
    Menus/mainmenu.cpp \
    Menus/settings.cpp \
    Game/gameobject.cpp \
    Game/paddle.cpp \
    Game/ball.cpp \
    Game/gameobjectcontroller.cpp \
    Game/playerpaddlecontroller.cpp \
    Game/aipaddlecontroller.cpp \
    Game/game.cpp \
    Game/gamescene.cpp \
    Game/ballbehaviour.cpp \
    Game/gamebackground.cpp \
    Game/scoreboard.cpp \
    Menus/pausemenu.cpp \
    Menus/mainwindow.cpp \
    Menus/customkeysequenceedit.cpp

HEADERS  += \
    Menus/mainmenu.h \
    Menus/settings.h \
    Game/gameobject.h \
    Game/paddle.h \
    Game/ball.h \
    Game/gameobjectcontroller.h \
    Game/playerpaddlecontroller.h \
    Game/aipaddlecontroller.h \
    Game/game.h \
    Game/gamescene.h \
    Game/ballbehaviour.h \
    Game/gamebackground.h \
    Game/scoreboard.h \
    Menus/mainwindow.h \
    Menus/pausemenu.h \
    Menus/customkeysequenceedit.h

FORMS += \
    mainmenu.ui \
    settings.ui \
    pausemenu.ui
