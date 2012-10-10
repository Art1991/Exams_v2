#ifndef ExamsTestSerializator_H
#define ExamsTestSerializator_H

#include "../DataClasses/dataclasses.hpp"
#include "../DataClasses/exception.hpp"
#include "abstractserializator.hpp"
#include "fieldschecker.hpp"

class ExamsTestSerializator : public AbstractSerializator
{
public:
    ExamsTestSerializator();
    ExamsTest loadTest(const QString &filename);
    void saveTest(const ExamsTest &test, const QString &filename) throw (Exception);

private:
    TestTask getTask(const QDomNode &taskNode);
    QDomElement getTaskXML(const TestTask &task);
    QDomDocument getTestXML(const ExamsTest &test);
};

#endif // ExamsTestSerializator_H
