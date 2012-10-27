#include "reviewedtesttask.hpp"

ReviewedTestTask::ReviewedTestTask(const QString &taskId,
                                   const QList<Key> &keys,
                                   const QString &htmlSource,
                                   const QStringList &xmlTestTasks)
{
    this->taskId = taskId;
    this->keys = keys;
    this->htmlSource = htmlSource;
    this->xmlTestTasks = xmlTestTasks;
}

const QString ReviewedTestTask::getTaskId() const
{
    return taskId;
}

const QString ReviewedTestTask::getHtmlSource() const
{
    return htmlSource;
}

const QStringList ReviewedTestTask::getXmlTestTasks() const
{
    return xmlTestTasks;
}

