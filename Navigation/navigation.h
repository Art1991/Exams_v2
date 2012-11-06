#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QObject>
#include <QList>
#include "../KeyStorage/key.hpp"
#include "../KeyStorage/keystorage.hpp"
#include "../KeyStorage/keystoragenode.hpp"
#include "dialognavigation.h"

class Navigation : public QObject
{
    Q_OBJECT
public:
    explicit Navigation(QObject *parent = 0);
    Navigation(KeyStorage *keyStorage);

    void showTheory(const QString &filename);
    void showReviewedTest(const QString &filename);
    void showExamsTest(const QString &filename);
    void showPluginTest(const QString &filename);

signals:
    
public slots:
    void onTheoryRequest(QList<Key> keys);
    void onMainMenuRequest();
    void onSettingsRequst();
    void onStartTestRequest(QList<Key> keys);
    void onExamTestRequest(QList<Key> innerKeys, QList<Key> outerKeys);
    void onExamTestRequest();
    void onReviewedTestRequest();
    void onTheoryRequest();
    void onLearningTestRequest();
    void onExtendedTheoryRequest();
    void onExecutingTestRequest();

private:

    DialogNavigation dialogNavigation;
    //WindowNavigation windowNavigation;
    KeyStorage *keyStorage;
};

#endif // NAVIGATION_H
