#include "examstest.hpp"

ExamsTest::ExamsTest()
{
}

void ExamsTest::clear()
{
    tasks.clear();
}

void ExamsTest::addTask(const TestTask &task)
{
    tasks.append(task);
}

const int ExamsTest::getTasksCount() const
{
    return tasks.length();
}

const TestTask ExamsTest::getTask(const QString &taskId) const throw (Exception)
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


const TestTask ExamsTest::getTask(const int &taskNumber) const throw (Exception)
{
    if (taskNumber >= tasks.length() || (taskNumber < 0))
    {
        throw Exception(Exception::ItemNotFound, "The task " + QString::number(taskNumber, 10) + " is not found");
    }

    return tasks.at(taskNumber);
}


const QString ExamsTest::getTestTitle() const
{
    return title;
}


const QString ExamsTest::getTestVersion() const
{
    return testVersion;
}
