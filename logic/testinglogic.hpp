#ifndef TESTINGLOGIC_H
#define TESTINGLOGIC_H

#include "dependancies.h"
#include <QString>
#include <QStringList>
#include "../DataClasses/dataclasses.hpp"

class TestingLogic {
public:
    User_informations* currInfo;
    ExamsTest* currTest;

    TestingLogic();
    void saveResult();
    void transitionToParagraph();
    void showExercise();

    QStringList getResults();
    QString getTaskTextById(QString id);
    QStringList getAnswersById(QString id);
    //загрузка теста
    //сохранение результата
    //
};

#endif // TESTINGLOGIC_H
