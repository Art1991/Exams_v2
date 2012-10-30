#-------------------------------------------------
#
# Project created by QtCreator 2012-10-21T18:22:58
#
#-------------------------------------------------

QT       += core xml

QT       -= gui

TARGET = Logic
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    testinglogic.cpp \
    ../DataClasses/userinformations.cpp \
    ../DataClasses/testtask.cpp \
    ../DataClasses/reviewedtesttask.cpp \
    ../DataClasses/reviewedtest.cpp \
    ../DataClasses/exception.cpp \
    ../DataClasses/examstest.cpp \
    ../DataClasses/abstracttesttask.cpp \
    ../KeyStorage/key.cpp \
    ../KeyStorage/keystoragenode.cpp \
    ../KeyStorage/keystorage.cpp



HEADERS += \
    testinglogic.hpp \
    ../DataClasses/userinformations.hpp \
    ../DataClasses/testtask.hpp \
    ../DataClasses/reviewedtesttask.hpp \
    ../DataClasses/reviewedtest.hpp \
    ../DataClasses/exception.hpp \
    ../DataClasses/examstest.hpp \
    ../DataClasses/dataclasses.hpp \
    ../DataClasses/abstracttesttask.hpp \
    ../KeyStorage/key.hpp \
    ../KeyStorage/keystoragenode.hpp \
    ../KeyStorage/keystorage.hpp


OTHER_FILES += \
    ../DataClasses/DataClasses.pro
