#include "navigation.h"

Navigation::Navigation(QObject *parent) :
    QObject(parent)
{
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

void Navigation::onStartTestRequest(QList<Key> innerKeys, QList<Key> outerKeys)
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
