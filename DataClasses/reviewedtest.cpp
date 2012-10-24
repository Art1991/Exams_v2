#include "reviewedtest.hpp"

ReviewedTest::ReviewedTest()
{
}


void ReviewedTest::clear()
{
    tasks.clear();
}


void ReviewedTest::addTask(const ReviewedTestTask &task)
{
    tasks.append(task);
}


const int ReviewedTest::getTasksCount() const
{
    return tasks.length();
}


const ReviewedTestTask ReviewedTest::getTask(const QString &taskId) const throw (Exception)
{
    for (int i = 0; i < tasks.length(); i++)
    {
        if (tasks.at(i).getTaskId() == taskId)
        {
            return tasks.at(i);
        }
    }

    throw Exception(Exception::ItemNotFound, "The task with id " + taskId + " is not found");
}


const ReviewedTestTask ReviewedTest::getTask(const int &taskNumber) const throw (Exception)
{
    if (taskNumber >= tasks.length() || (taskNumber < 0))
    {
        throw Exception(Exception::ItemNotFound, "The task " + QString::number(taskNumber, 10) + " is not found");
    }

    return tasks.at(taskNumber);
}


const QString ReviewedTest::getTestTitle() const
{
    return title;
}


const QString ReviewedTest::getTestVersion() const
{
    return testVersion;
}
