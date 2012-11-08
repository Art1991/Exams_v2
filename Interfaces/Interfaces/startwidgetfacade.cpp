#include "startwidgetfacade.hpp"
#include <QMessageBox>

StartWidgetFacade::StartWidgetFacade(QObject *parent) : QObject(parent) {
    swlptr = 0;
    swptr = 0;
}

void StartWidgetFacade::setSwlptr(StartWidgetLogics* logicpointer) {
    swlptr = logicpointer;
}

void StartWidgetFacade::setSwptr(StartWidgetUI* widgetpointer) {
    swptr = widgetpointer;
}

bool StartWidgetFacade::connectingSignalsSlots() {
    // коннектим если ужде есть указатели на логику и стартвиджет
    if ((swlptr == 0) || (swptr == 0)) {
        return false;
    } else {
        QObject::connect(swptr, SIGNAL(reviewedTestLEarningRequest()), this, SLOT(showTestPreparingWidget()), Qt::AutoConnection);
        QObject::connect(swptr, SIGNAL(extendedTheoryJumpRequest()), this, SLOT(theoryDisplay()), Qt::AutoConnection);
        QObject::connect(swptr, SIGNAL(settingsJumpRequest()), this, SLOT(settingsDisplay()), Qt::AutoConnection);
        QObject::connect(swptr, SIGNAL(exitJumpRequest()), this, SLOT(beginTesting()), Qt::AutoConnection);
        QObject::connect(swptr, SIGNAL(testingJumpRequest()), this, SLOT(closeWidget()), Qt::AutoConnection);
        return true;
    }
}

void StartWidgetFacade::showTestPreparingWidget() {
    // показ разбора задач
    // используем указатель на логику стартового окна - swlptr
    swlptr->showTestPreparingWidget();
}

void StartWidgetFacade::settingsDisplay() {
    swlptr->showSettings();//показ настроек
}

void StartWidgetFacade::theoryDisplay() {
    swlptr->showTheoryParagraph();//показ паргарафов теории
}

void StartWidgetFacade::beginTesting() {
    swlptr->showTestingWidget();//показ тестинг виджета
}

void StartWidgetFacade::closeWidget() {
    swlptr->closeStartWidget();//закрытие виджета(и наверное программы)
}
