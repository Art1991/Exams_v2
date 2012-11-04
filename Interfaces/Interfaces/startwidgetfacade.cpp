#include "startwidgetfacade.hpp"
#include <QMessageBox>

StartWidgetFacade::StartWidgetFacade(QObject *parent) :
    QObject(parent)
{
    QObject::connect(swptr, SIGNAL(reviewedTestLEarningRequest()), this, SLOT(setValue(showTestPreparingWidget())), Qt::AutoConnection);
}

void StartWidgetFacade::showTestPreparingWidget() {
    //тут вызываем функцию логики
    //функцию показа нужного виджета
    swlptr->showRequestedWidget();
}


