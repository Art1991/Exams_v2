#include "testingwidgetfacade.hpp"

<<<<<<< HEAD
TestingWidgetFacade::TestingWidgetFacade(){

=======
TestingWidgetFacade::TestingWidgetFacade() {
    // ������� ��������� �� �����������, �������� �������, ��������� �� ����������, �������� �����
>>>>>>> 13dcb1a299fe3bfde64ff1891418f66d7c0e17d9
    QObject::connect(twptr, SIGNAL(jumpToTaskRequest(QString)), this, SLOT(setValue(displayTaskById(QString))), Qt::AutoConnection);
    QObject::connect(twptr, SIGNAL(finishTestRequest()), this, SLOT(setValue(saveResults())), Qt::AutoConnection);
    QObject::connect(twptr, SIGNAL(startTestRequest()), this, SLOT(setValue(beginTesting())), Qt::AutoConnection);
}

TestingWidgetFacade::TestingWidgetFacade(TestingWidget *, TestingLogic *, TestingTaskWidget *)
{
}

void TestingWidgetFacade::setTestingWidgetPointer(TestingWidget *)
{
}

void TestingWidgetFacade::setTestingLogicPointer(TestingLogic *)
{
}

void TestingWidgetFacade::clearTestingWidgetPointer()
{
}

void TestingWidgetFacade::clearTestingLogicPointer()
{
}

void TestingWidgetFacade::clearTestingTaskWidgetPointer()
{
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
<<<<<<< HEAD
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
=======
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
>>>>>>> 13dcb1a299fe3bfde64ff1891418f66d7c0e17d9
}
