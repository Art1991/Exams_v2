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
    void setSwlptr(StartWidgetLogics*);
signals:

private:
    StartWidgetLogics* swlptr;
    StartWidgetUI* swptr;
    void showWidget(QWidget*);
    
public slots:

    //reviewedTestLEarningRequest
    void showTestPreparingWidget();
    void settingsDisplay();
    void theoryDisplay();
    void beginTesting();
    void closeWidget();
};

#endif // STARTWIDGETFACADE_HPP
