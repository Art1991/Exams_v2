#-------------------------------------------------
#
# Project created by QtCreator 2012-11-06T18:42:12
#
#-------------------------------------------------

QT       += core gui xml webkit

TARGET = Navigation
TEMPLATE = app


SOURCES += main.cpp \
    dialognavigation.cpp \
    navigation.cpp \
    windownavigation.cpp \
    ../Interfaces/Dialogs/testresultsdialog.cpp \
    ../Interfaces/Dialogs/testhelpselectingdialog.cpp \
    ../Interfaces/Dialogs/personalizationdialog.cpp \
    ../Interfaces/Dialogs/learningtestselectingdialog.cpp \
    ../Interfaces/Dialogs/extendedtheoryselectingdialog.cpp \
    ../Interfaces/Dialogs/executingtestselectingdialog.cpp \
    ../KeyStorage/keystoragenode.cpp \
    ../KeyStorage/keystorage.cpp \
    ../KeyStorage/key.cpp \
    ../logic/testinglogic.cpp \
    ../logic/startwidgetlogic.cpp \
    ../Interfaces/Interfaces/testpreparingwidget.cpp \
    ../Interfaces/Interfaces/testingwidgetfacade.cpp \
    ../Interfaces/Interfaces/testingwidget.cpp \
    ../Interfaces/Interfaces/testingtaskwidget.cpp \
    ../Interfaces/Interfaces/startwidgetui.cpp \
    ../Interfaces/Interfaces/startwidgetfacade.cpp \
    ../Interfaces/Interfaces/extendstheorylearningwidget.cpp



HEADERS += \
    dialognavigation.h \
    navigation.h \
    windownavigation.h \
    ../Interfaces/Dialogs/testresultsdialog.hpp \
    ../Interfaces/Dialogs/testhelpselectingdialog.hpp \
    ../Interfaces/Dialogs/personalizationdialog.hpp \
    ../Interfaces/Dialogs/learningtestselectingdialog.hpp \
    ../Interfaces/Dialogs/extendedtheoryselectingdialog.hpp \
    ../Interfaces/Dialogs/executingtestselectingdialog.hpp \
    ../KeyStorage/keystoragenode.hpp \
    ../KeyStorage/keystorage.hpp \
    ../KeyStorage/key.hpp \
    ../logic/testinglogic.hpp \
    ../logic/startwidgetlogic.hpp \
    ../Interfaces/Interfaces/testpreparingwidget.hpp \
    ../Interfaces/Interfaces/testingwidgetfacade.hpp \
    ../Interfaces/Interfaces/testingwidget.hpp \
    ../Interfaces/Interfaces/testingtaskwidget.hpp \
    ../Interfaces/Interfaces/startwidgetui.hpp \
    ../Interfaces/Interfaces/startwidgetfacade.hpp \
    ../Interfaces/Interfaces/extendstheorylearningwidget.hpp


FORMS += \
    ../Interfaces/Dialogs/testresultsdialog.ui \
    ../Interfaces/Dialogs/testhelpselectingdialog.ui \
    ../Interfaces/Dialogs/personalizationdialog.ui \
    ../Interfaces/Dialogs/learningtestselectingdialog.ui \
    ../Interfaces/Dialogs/extendedtheoryselectingdialog.ui \
    ../Interfaces/Dialogs/executingtestselectingdialog.ui \
    ../Interfaces/Interfaces/testpreparingwidget.ui \
    ../Interfaces/Interfaces/testingwidget.ui \
    ../Interfaces/Interfaces/startwidgetui.ui \
    ../Interfaces/Interfaces/extendstheorylearningwidget.ui

RESOURCES += \
    ../Interfaces/Interfaces/icons.qrc

