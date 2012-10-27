#ifndef TESTINGWIDGETFACADE_H
#define TESTINGWIDGETFACADE_H

#include <QString>
#include <QStringList>
#include "testingwidget.hpp"
#include "testingtaskwidget.hpp"
#include "../../Logic/testinglogic.hpp"

class TestingWidgetFacade {

friend class testingwidget;

private:
    TestingWidget* twptr;
    TestingLogic* tlptr;
    TestingTaskWidget* ttwptr;

public:
    TestingWidgetFacade();
    TestingWidgetFacade(TestingWidget*, TestingLogic*, TestingTaskWidget*);
    void setTestingWidgetPointer(TestingWidget*);
    void setTestingLogicPointer(TestingLogic*);
    void setTestingLogicPointer(TestingTaskWidget*);
    void clearTestingWidgetPointer();
    void clearTestingLogicPointer();
    void clearTestingTaskWidgetPointer();

signals:


public slots:
    // jumpToTaskRequest(taskId)
    void displayTaskById(QString);

};

#endif // TESTINGWIDGETFACADE_H
