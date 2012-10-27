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
    void save_Results();
    void transition_To_Paragraph();
    void show_Exercise();

    QString getTaskTextById(QString id);
    QStringList getAnswersById(QString id);
    //загрузка теста
    //сохранение результата
    //
};

#endif // TESTINGLOGIC_H
