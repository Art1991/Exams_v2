#include "testingwidgetfacade.hpp"

TestingWidgetFacade::TestingWidgetFacade() {
    // коннект указатель на отправителя, название сигнала, указатель на получателя, название слота
    QObject::connect(twptr, SIGNAL(jumpToTaskRequest(QString taskId)), this, SLOT(displayTaskById(QString id)), Qt::AutoConnection);
}

void TestingWidgetFacade::displayTaskById(QString id) {
    QString taskText = tlptr->getTaskTextById(id);
    ttwptr->showTaskText(taskText);
    if(id.startsWith("A")) {
        QStringList answers = tlptr->getAnswersById(id);
        ttwptr->showAnswers(answers);
    }
}
