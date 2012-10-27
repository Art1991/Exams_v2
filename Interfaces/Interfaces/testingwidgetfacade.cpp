#include "testingwidgetfacade.hpp"

TestingWidgetFacade::TestingWidgetFacade() {
    // ������� ��������� �� �����������, �������� �������, ��������� �� ����������, �������� �����
    QObject::connect(twptr, SIGNAL(jumpToTaskRequest(QString)), this, SLOT(setValue(displayTaskById(QString))), Qt::AutoConnection);
}

void TestingWidgetFacade::displayTaskById(QString id) {
    QString taskText = tlptr->getTaskTextById(id);
    ttwptr->showTaskText(taskText);
    if(id.startsWith("A")) {
        QStringList answers = tlptr->getAnswersById(id);
        ttwptr->showAnswers(answers);
    }
}
