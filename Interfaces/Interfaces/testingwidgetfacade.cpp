#include "testingwidgetfacade.hpp"

TestingWidgetFacade::TestingWidgetFacade() {
    // ������� ��������� �� �����������, �������� �������, ��������� �� ����������, �������� �����
<<<<<<< HEAD
    QObject::connect(twptr, SIGNAL(jumpToTaskRequest(QString taskId)), this, SLOT(displayTaskById(QString id)), Qt::AutoConnection);
=======
    QObject::connect(twptr, SIGNAL(jumpToTaskRequest(QString)), this, SLOT(setValue(displayTaskById(QString))), Qt::AutoConnection);
    QObject::connect(twptr, SIGNAL(finishTestRequest()), this, SLOT(setValue(saveResults())), Qt::AutoConnection);
    QObject::connect(twptr, SIGNAL(startTestRequest()), this, SLOT(setValue(beginTesting())), Qt::AutoConnection);
>>>>>>> ce21c51cae0efc71d39ff953d0befcc69a7e7798
}

void TestingWidgetFacade::displayTaskById(QString id) {
    QString taskText = tlptr->getTaskTextById(id);
    ttwptr->showTaskText(taskText);
    //if(id.startsWith("A")) {
    //    QStringList answers = tlptr->getAnswersById(id);
    //    ttwptr->showAnswers(answers);
    //} ����� ������ ������ ��������� ��������� � ���������� A,
    // ����� ����� ��������� �������� � ��������� ��� ������ �������?
}

void TestingWidgetFacade::saveResults() {
    ttwptr->toFinishCount();//��������� ������
    tlptr->saveResult();//��������� ���������
    QStringList results = tlptr->getResults();
    ttwptr->showResult(results);//�������� ��������� � ������� �� �������
}
void TestingWidgetFacade::beginTesting() {
    ttwptr->toReckon();//������ ������
    ttwptr->dumpingOfAnswers();//�������� ������
    QString taskText = tlptr->getTaskTextById("A1");//��������� ������ ������� � �1
    ttwptr->showTaskText(taskText);//�������� �������
}
