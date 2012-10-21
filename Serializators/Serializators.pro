#-------------------------------------------------
#
# Project created by QtCreator 2012-08-26T17:39:09
#
#-------------------------------------------------

QT       += core xml xmlpatterns

TARGET = Serializators
TEMPLATE = app

CONFIG += console

SOURCES += \
    main.cpp \
    abstractserializator.cpp \
    examstestserializator.cpp \
    fieldschecker.cpp \
    reviewedtestserializator.cpp\
    keyserializator.cpp\
    pluginconfigserializator.cpp

HEADERS  += \
    serializators.hpp \
    abstractserializator.hpp \
    examstestserializator.hpp \
    fieldschecker.hpp \
    reviewedtestserializator.hpp\
    keyserializator.hpp\
    pluginconfigserializator.hpp

RESOURCES += \
    serializators.qrc

# Подключаем классы данных

SOURCES += \
    ../DataClasses/reviewedtesttask.cpp \
    ../DataClasses/testtask.cpp \
    ../DataClasses/examstest.cpp \
    ../DataClasses/exception.cpp \
    ../DataClasses/reviewedtest.cpp \
    ../DataClasses/abstracttest.cpp \
    ../DataClasses/abstracttesttask.cpp\
    ../Plugins/plugininfo.cpp

HEADERS  +=  \
    ../DataClasses/reviewedtesttask.hpp \
    ../DataClasses/dataclasses.hpp \
    ../DataClasses/testtask.hpp \
    ../DataClasses/examstest.hpp \
    ../DataClasses/exception.hpp \
    ../DataClasses/reviewedtest.hpp \
    ../DataClasses/abstracttest.hpp \
    ../DataClasses/abstracttesttask.hpp\
    ../Plugins/plugininfo.hpp






