#include "startwidgetfacade.hpp"
#include <QMessageBox>

StartWidgetFacade::StartWidgetFacade(QObject *parent) :
    QObject(parent)
{
    QObject::connect(swptr, SIGNAL(reviewedTestLEarningRequest()), this, SLOT(setValue(showTestPreparingWidget())), Qt::AutoConnection);
    QObject::connect(swptr, SIGNAL(extendedTheoryJumpRequest()), this, SLOT(setValue(theoryDisplay()())), Qt::AutoConnection);
    QObject::connect(swptr, SIGNAL(settingsJumpRequest()), this, SLOT(setValue(settingsDisplay())), Qt::AutoConnection);
    QObject::connect(swptr, SIGNAL(exitJumpRequest()), this, SLOT(setValue(beginTesting())), Qt::AutoConnection);
    QObject::connect(swptr, SIGNAL(testingJumpRequest()), this, SLOT(setValue(closeWidget())), Qt::AutoConnection);
}

void StartWidgetFacade::showTestPreparingWidget() {
    swlptr->showRequestedWidget();//показ разбора задач
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
