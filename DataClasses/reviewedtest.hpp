#ifndef REVIEWEDTEST_H
#define REVIEWEDTEST_H

#include <QString>
#include <QStringList>
#include <QList>

#include "reviewedtesttask.hpp"
#include "exception.hpp"

class ReviewedTest
{
public:
    ReviewedTest();
    ReviewedTest(const QString &title,
                 const QString &testVersion) :
                 title(title), testVersion(testVersion) {}

    void clear();
    void addTask(const ReviewedTestTask &task);

    const ReviewedTestTask getTask(const QString &taskId) const throw (Exception);
    const ReviewedTestTask getTask(const int &taskNumber) const throw (Exception);

    const int getTasksCount() const;

    const QString getTestTitle() const;
    const QString getTestVersion() const;

protected:

    QString title;
    QString testVersion;

    QList<ReviewedTestTask> tasks;
};


#endif // REVIEWEDTEST_H
