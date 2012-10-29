#include "testingwidgetfacade.hpp"

TestingWidgetFacade::TestingWidgetFacade() {
    // коннект указатель на отправителя, название сигнала, указатель на получателя, название слота
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
    //} Зачем вообще делать отдельный текстбокс с вариантами A,
    // когда можно загружать варианты в контейнер для текста заданий?
}

void TestingWidgetFacade::saveResults() {
    ttwptr->toFinishCount();//закончить отсчёт
    tlptr->saveResult();//сохранить результат
    QStringList results = tlptr->getResults();
    ttwptr->showResult(results);//показать результат и переход на главную
}
void TestingWidgetFacade::beginTesting() {
    ttwptr->toReckon();//начать отсчёт
    ttwptr->dumpingOfAnswers();//сбросить ответы
    QString taskText = tlptr->getTaskTextById("A1");//загрузить первое задание с А1
    ttwptr->showTaskText(taskText);//показать задание
}
