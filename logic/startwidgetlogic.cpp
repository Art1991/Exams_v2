#include "startwidgetlogic.hpp"

StartWidgetLogics::StartWidgetLogics(QObject *parent) : QObject(parent)
{
}

void StartWidgetLogics::connectSignalsSlots(QWidget* w) {
        QObject::connect(this, SIGNAL(askTaskPreparingWidget()), w, SLOT(switchToTestPreparingWidget()), Qt::AutoConnection);
}

void StartWidgetLogics::showRequestedWidget() {
    //какимто образом залеззать в стект виджет и показывать нужные виджеты
}


void StartWidgetLogics::showTestPreparingWidget() {
    // нужно выпустить сигнал, который впоследствии будет пойман в классе MainWindow
    // это текущий вариант, вообще-то этот сигнал в классе Navigation или где-то там в подпроекте Navigation
    // но пока что мы навигацию не трогаем

    // 1 создаем сигнал в файле startwidgetlogic.hpp
    // 2 выпускаем сигнал askTaskPreparingWidget()
    emit askTaskPreparingWidget();
    // 3 теперь нужно создать и подключить слот, которым мы этот сигнал поймаем
    // следуем в файл Interfaces/MainWindow.hpp
    // теперь соединяем сигналы со слотами
    // сигнал испускается в этом классе, ловится в классе MainWindow
    // есть смысл коннектить в этом классе по причине того, что в файле main.cpp (стартовый файл программы)
    // уже содежится указатель на MainWindow (ну или сам объект - не важно)
    // тоже делаем функцию соединения connectSignalsSlots()

}

void StartWidgetLogics::showSettings() {
    //какимто образом залеззать в стект виджет и показывать нужные виджеты
}

void StartWidgetLogics::showTestingWidget() {
    //какимто образом залеззать в стект виджет и показывать нужные виджеты
}

void StartWidgetLogics::closeStartWidget() {
    //какимто образом залеззать в стект виджет и показывать нужные виджеты
}

void StartWidgetLogics::showTheoryParagraph() {

}


