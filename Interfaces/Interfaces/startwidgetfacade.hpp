#ifndef STARTWIDGETFACADE_HPP
#define STARTWIDGETFACADE_HPP

#include <QObject>
#include "startwidgetui.hpp"
#include "../../Logic/startwidgetlogic.hpp"

// это класс - фасад, связывающий UI стартового окна с логикой работы стартового окна
// фактически классы StartWidgetUi и StartWidgetLogic
//


class StartWidgetFacade : public QObject
{
    Q_OBJECT
public:
    explicit StartWidgetFacade(QObject *parent = 0);

    void setSwlptr(StartWidgetLogics*); // функции установки указателей
    void setSwptr(StartWidgetUI*);

    bool connectingSignalsSlots(); // функция, в которой будут коннекты

signals:

private:
    StartWidgetLogics* swlptr; // указатель на объект логики
    StartWidgetUI* swptr; // указательна объект-стартовый виджет
    void showWidget(QWidget*);
    
public slots:

    // нужно поймать в фасаде тоесть сдесь сигнал reviewedTestLEarningRequest
    void showTestPreparingWidget(); // используем для этого слот showTestPreparingWidget()
    void settingsDisplay();
    void theoryDisplay();
    void beginTesting();
    void closeWidget();
};

#endif // STARTWIDGETFACADE_HPP
