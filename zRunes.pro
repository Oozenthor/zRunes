#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T20:40:17
#
#-------------------------------------------------
#QMAKE_CXXFLAGS += -std=c++0x
#CONFIG   += c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zRunes
TEMPLATE = app


SOURCES += main.cpp\
        runes.cpp \
    zrunes.cpp

HEADERS  += runes.h \
    zrunes.h

FORMS    += runes.ui

OTHER_FILES += \
    ElderFuthark.xml \
    LICENSE

#target.file = ElderFuthark.xml
#target.path = $$OUT_PWD
#INSTALLS += target

#message(pwd $$PWD)
#message(out_pwd $$OUT_PWD)
#message(other files $$OTHER_FILES)



