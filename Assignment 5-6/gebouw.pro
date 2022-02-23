#-------------------------------------------------
#
# Project created by QtCreator 2017-01-31T22:51:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gebouw
TEMPLATE = app

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
        CardLock.cpp \
        CodeLock.cpp \
        Door.cpp \
        HallSensor.cpp \
        IdCard.cpp \
        KeyLock.cpp \
        LockException.cpp \
        PrinterQBox.cpp \
        QLineLock.cpp \
        RecognitionLock.cpp \
        RevolvingDoor.cpp \
        Sensor.cpp \
        SlidingDoor.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h \
    CardLock.h \
    CodeLock.h \
    Door.h \
    HallSensor.h \
    IdCard.h \
    KeyLock.h \
    Lock.h \
    LockException.h \
    Printer.h \
    PrinterQBox.h \
    QLineLock.h \
    RecognitionLock.h \
    RevolvingDoor.h \
    Sensor.h \
    SlidingDoor.h

FORMS    += mainwindow.ui
