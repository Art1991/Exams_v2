#-------------------------------------------------
#
# Project created by QtCreator 2012-11-06T18:42:12
#
#-------------------------------------------------

QT       += core gui

TARGET = Navigation
TEMPLATE = app


SOURCES += main.cpp \
    dialognavigation.cpp \
    navigation.cpp \
    ../Interfaces/Dialogs/testresultsdialog.cpp \
    ../Interfaces/Dialogs/testhelpselectingdialog.cpp \
    ../Interfaces/Dialogs/personalizationdialog.cpp \
    ../Interfaces/Dialogs/mainwindow.cpp \
    ../Interfaces/Dialogs/learningtestselectingdialog.cpp \
    ../Interfaces/Dialogs/extendedtheoryselectingdialog.cpp \
    ../Interfaces/Dialogs/executingtestselectingdialog.cpp \
    ../KeyStorage/keystoragenode.cpp \
    ../KeyStorage/keystorage.cpp \
    ../KeyStorage/key.cpp

HEADERS += \
    dialognavigation.h \
    navigation.h \
    ../Interfaces/Dialogs/testresultsdialog.hpp \
    ../Interfaces/Dialogs/testhelpselectingdialog.hpp \
    ../Interfaces/Dialogs/personalizationdialog.hpp \
    ../Interfaces/Dialogs/mainwindow.hpp \
    ../Interfaces/Dialogs/learningtestselectingdialog.hpp \
    ../Interfaces/Dialogs/extendedtheoryselectingdialog.hpp \
    ../Interfaces/Dialogs/executingtestselectingdialog.hpp \
    ../Interfaces/Dialogs/dialogs.hpp \
    ../KeyStorage/keystoragenode.hpp \
    ../KeyStorage/keystorage.hpp \
    ../KeyStorage/key.hpp

FORMS += \
    ../Interfaces/Dialogs/testresultsdialog.ui \
    ../Interfaces/Dialogs/testhelpselectingdialog.ui \
    ../Interfaces/Dialogs/personalizationdialog.ui \
    ../Interfaces/Dialogs/mainwindow.ui \
    ../Interfaces/Dialogs/learningtestselectingdialog.ui \
    ../Interfaces/Dialogs/extendedtheoryselectingdialog.ui \
    ../Interfaces/Dialogs/executingtestselectingdialog.ui
