#ifndef TESTINGLOGIC_H
#define TESTINGLOGIC_H

#include "dependancies.h"
#include <QString>
#include <QStringList>

class TestingLogic {
public:
    User_informations currInfo;
    ExamsTest currTest;

    TestingLogic();
    void saveResult();
    void transitionToParagraph();
    void showExercise();

    QStringList getResult(QStringList );
    QString getTaskTextById(QString id);
    QStringList getAnswersById(QString id);
    //загрузка теста
    //сохранение результата
    //
};

#endif // TESTINGLOGIC_H
