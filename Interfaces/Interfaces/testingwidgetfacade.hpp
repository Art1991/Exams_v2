#ifndef TESTINGWIDGETFACADE_H
#define TESTINGWIDGETFACADE_H

#include <QString>
#include <QStringList>
#include "testingwidget.hpp"
#include "testingtaskwidget.hpp"
#include "../../Logic/testinglogic.hpp"

class TestingWidgetFacade : public QObject {

    Q_OBJECT

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
<<<<<<< HEAD
    void displayTaskById(QString id);

=======
    void displayTaskById(QString);
    void saveResults(QStringList);
    void beginTesting();
>>>>>>> ce21c51cae0efc71d39ff953d0befcc69a7e7798
};

#endif // TESTINGWIDGETFACADE_H
