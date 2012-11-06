#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QObject>
#include <QList>
#include "../KeyStorage/key.hpp"
#include "dialognavigation.h"

class Navigation : public QObject
{
    Q_OBJECT
public:
    explicit Navigation(QObject *parent = 0);
    

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
    void onStartTestRequest(QList<Key> innerKeys, QList<Key> outerKeys);
    void onLearningTestRequest();
    void onExtendedTheoryRequest();
    void onExecutingTestRequest();

private:

    DialogNavigation dialogNavigation;
    //WindowNavigation windowNavigation;
};

#endif // NAVIGATION_H
