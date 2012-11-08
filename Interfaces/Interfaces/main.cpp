#include <QtGui/QApplication>

#include "mainwindow.hpp"
#include "../../Logic/startwidgetlogic.hpp"
#include "startwidgetfacade.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    // надо создать экземпляр логики
    StartWidgetLogics SWLog;
    SWLog.connectSignalsSlots(&w);
    // и экземпляр фасада
    StartWidgetFacade SWFac;
    SWFac.setSwlptr(&SWLog);
    SWFac.setSwptr(w.getStartWidgetUIPtr());
    SWFac.connectingSignalsSlots();

    w.showMaximized();
    
    return a.exec();
}
