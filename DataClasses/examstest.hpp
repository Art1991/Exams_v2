#ifndef EXAMSTEST_H
#define EXAMSTEST_H

#include <QString>
#include <QStringList>
#include <QList>

#include "abstracttest.hpp"
#include "testtask.hpp"
#include "exception.hpp"

class ExamsTest : public AbstractTest<TestTask>
{
public:
    ExamsTest();
    ExamsTest(const QString &title,
              const QString &testVersion) :
              AbstractTest<TestTask>(title, testVersion) {}
private:

};

#endif // EXAMSTEST_H
