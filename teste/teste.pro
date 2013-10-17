#-------------------------------------------------
#
# Project created by QtCreator 2013-09-27T17:03:46
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = teste
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ChatLibrary/release/ -lChatLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ChatLibrary/debug/ -lChatLibrary
else:unix: LIBS += -L$$OUT_PWD/../ChatLibrary/ -lChatLibrary

INCLUDEPATH += $$PWD/../ChatLibrary
DEPENDPATH += $$PWD/../ChatLibrary

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ChatLibrary/release/libChatLibrary.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ChatLibrary/debug/libChatLibrary.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../ChatLibrary/libChatLibrary.a
