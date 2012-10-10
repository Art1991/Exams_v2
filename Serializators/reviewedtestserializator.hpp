#ifndef REWIEVEDTESTSERIALIZATOR_H
#define REWIEVEDTESTSERIALIZATOR_H

#include "../DataClasses/dataclasses.hpp"
#include "../DataClasses/exception.hpp"
#include "abstractserializator.hpp"
#include "fieldschecker.hpp"

class ReviewedTestSerializator : public AbstractSerializator
{
public:
    ReviewedTestSerializator();

    ReviewedTest loadTest(const QString &filename);
    void saveTest(const ReviewedTest &test, const QString &filename) throw (Exception);

private:
    ReviewedTestTask getTask(const QDomNode &taskNode);
    QDomElement getTaskXML(const ReviewedTestTask &task);
    QDomDocument getTestXML(const ReviewedTest &test);
};

#endif // REWIEVEDTESTSERIALIZATOR_H
