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
}

void Navigation::showReviewedTest(const QString &filename)
{
}

void Navigation::showExamsTest(const QString &filename)
{
}

void Navigation::showPluginTest(const QString &filename)
{
}

void Navigation::onTheoryRequest(QList<Key> keys)
{
}

void Navigation::onMainMenuRequest()
{
}

void Navigation::onSettingsRequst()
{
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
    ExecutingTestSelectingDialog dialog;
    dialog.setTestsData(examsTestList);

    dialog.exec();


}

void Navigation::onReviewedTestRequest()
{
}

void Navigation::onTheoryRequest()
{
}
