#include "testingwidgetfacade.hpp"

TestingWidgetFacade::TestingWidgetFacade(){

    QObject::connect(twptr, SIGNAL(jumpToTaskRequest(QString)), this, SLOT(setValue(displayTaskById(QString))), Qt::AutoConnection);
    QObject::connect(twptr, SIGNAL(finishTestRequest()), this, SLOT(setValue(saveResults())), Qt::AutoConnection);
    QObject::connect(twptr, SIGNAL(startTestRequest()), this, SLOT(setValue(beginTesting())), Qt::AutoConnection);
}

void TestingWidgetFacade::displayTaskById(QString id) {
    QString taskText = tlptr->getTaskTextById(id);
    ttwptr->showTaskText(taskText);
    if(id.startsWith("A")) {
        QStringList answers = tlptr->getAnswersById(id);
        ttwptr->showAnswers(answers);
    }
}

void TestingWidgetFacade::saveResults() {
    ttwptr->toFinishCount();
    tlptr->saveResult();
    QStringList results = tlptr->getResults();
    ttwptr->showResult(results);
}
void TestingWidgetFacade::beginTesting() {
    ttwptr->toReckon();
    ttwptr->dumpingOfAnswers();
    QString taskText = tlptr->getTaskTextById("A1");
    ttwptr->showTaskText(taskText);
}
