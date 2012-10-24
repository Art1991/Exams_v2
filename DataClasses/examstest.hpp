#ifndef EXAMSTEST_H
#define EXAMSTEST_H

#include <QString>
#include <QStringList>
#include <QList>

#include "testtask.hpp"
#include "exception.hpp"

class ExamsTest
{
public:
    ExamsTest();
    ExamsTest(const QString &title,
                 const QString &testVersion) :
                 title(title), testVersion(testVersion) {}

    void clear();
    void addTask(const TestTask &task);

    const TestTask getTask(const QString &taskId) const throw (Exception);
    const TestTask getTask(const int &taskNumber) const throw (Exception);

    const int getTasksCount() const;

    const QString getTestTitle() const;
    const QString getTestVersion() const;

protected:

    QString title;
    QString testVersion;

    QList<TestTask> tasks;
};

#endif // EXAMSTEST_H
