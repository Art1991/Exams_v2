#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QObject>
#include <QList>
#include "../KeyStorage/key.hpp"
#include "../KeyStorage/keystorage.hpp"
#include "../KeyStorage/keystoragenode.hpp"
#include "../Interfaces/Interfaces/startwidgetfacade.hpp"
#include "../Interfaces/Interfaces/testingwidgetfacade.hpp"
#include "../Logic/testinglogic.hpp"
#include "../Logic/startwidgetlogic.hpp"

#include "dialognavigation.h"
#include "windownavigation.h"

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
    void onExamsTestRequest(QList<Key> innerKeys, QList<Key> outerKeys);
    void onExamsTestRequest();
    void onReviewedTestRequest();
    void onTheoryRequest();
    void onLearningTestRequest();
    void onExtendedTheoryRequest();
    void onExecutingTestRequest();

private:

    DialogNavigation dialogNavigation;
    WindowNavigation windowNavigation;
    KeyStorage *keyStorage;

    QStringList examsTestList;
    QStringList learningTestList;

    //LogicClasses

    TestingLogic testingLogic;
    StartWidgetLogics startWidgetLogic;

};

#endif // NAVIGATION_H
