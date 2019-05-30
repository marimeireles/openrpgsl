TEMPLATE = app
TARGET = opennrpgsl
INCLUDEPATH += \bin
QT += gui widgets
DESTDIR=bin
MOC_DIR=bin

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

HEADERS = \
    include\player.h \
    include\playerControls.h \
    include\mainWindow.h
SOURCES = program\main.cpp \
    src\player.cpp \
    src\playerControls.cpp \
    src\mainWindow.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/player
INSTALLS += target
