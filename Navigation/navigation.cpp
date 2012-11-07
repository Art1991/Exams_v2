#include "navigation.h"

Navigation::Navigation(QObject *parent) :
    QObject(parent)
{
}

Navigation::Navigation(KeyStorage *keyStorage)
{
    this->keyStorage = keyStorage;
}

void Navigation::showTheory(const QString &filename)
{
    // на данной итерации, теория не реализованна
}

void Navigation::showReviewedTest(const QString &filename)
{

}

void Navigation::showExamsTest(const QString &filename)
{

}

void Navigation::showPluginTest(const QString &filename)
{
    // на данный момент нет плагинов
}

void Navigation::onTheoryRequest(QList<Key> keys)
{
}

void Navigation::onMainMenuRequest()
{
    windowNavigation.showStartWidget();
}

void Navigation::onSettingsRequst()
{
    // на данный момент нет доступных настроек
}

void Navigation::onStartTestRequest(QList<Key> keys)
{
}

void Navigation::onExamsTestRequest(QList<Key> innerKeys, QList<Key> outerKeys)
{
}

void Navigation::onLearningTestRequest()
{
}

void Navigation::onExtendedTheoryRequest()
{
}

void Navigation::onExecutingTestRequest()
{
}

void Navigation::onExamsTestRequest()
{
    QString test = dialogNavigation.selectTestForExecuting(examsTestList);
    if (dialogNavigation.getDialogResult() == 0)
    {
        return;
    }

    // Реализовать выборку теста и инициализацию логики
}

void Navigation::onReviewedTestRequest()
{
    QString test = dialogNavigation.selectTestForLearning(learningTestList);
    if (dialogNavigation.getDialogResult() == 0)
    {
        return;
    }

    // Реализовать выборку теста и инициализацию логики
}

void Navigation::onTheoryRequest()
{
    // теория не реализована
}
