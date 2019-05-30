TEMPLATE = app
TARGET = openrpgsl
INCLUDEPATH += \bin
QT += gui widgets
DESTDIR=bin
MOC_DIR=bin
OBJECTS_DIR=bin

CONFIG += qt debug

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

HEADERS = \
    include/player.h \
    include/playerControls.h \
    include/mainWindow.h
SOURCES = program/main.cpp \
    src/player.cpp \
    src/playerControls.cpp \
    src/mainWindow.cpp