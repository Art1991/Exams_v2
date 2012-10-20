#ifndef USER_INFORMATIONS_HPP
#define USER_INFORMATIONS_HPP

#include <qstring.h>
#include <QVector>
#include <QtXml/QtXml>
#include <QtXmlPatterns/QtXmlPatterns>
#include <QFile>

class User_informations {
protected:
    QString fio;
    QString number_of_test;
    QString time_date;
    QString total_number_of_task;
    QString number_of_correct_task;
    QString procent_of_correct_task;
    QVector<QString> test_answers;
    QVector<QString> correctness_answers;

public:
    User_informations();
    void save_Information();
    void read_Information();
};

#endif // USER_INFORMATIONS_HPP
