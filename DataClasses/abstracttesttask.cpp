#include "abstracttesttask.hpp"

AbstractTestTask::AbstractTestTask()
{
}

const QStringList AbstractTestTask::getInnerCodes() const
{
    QStringList res;
    for (int i = 0; i < keys.count(); i++)
    {
        if (keys.at(i).getKeyType() == keys.at(i).InnerCode)
        {
            res << keys.at(i).getKey();
        }
    }
    return res;
}

const QStringList AbstractTestTask::getOuterCodes() const
{
    QStringList res;
    for (int i = 0; i < keys.count(); i++)
    {
        if (keys.at(i).getKeyType() == keys.at(i).OuterCode)
        {
            res << keys.at(i).getKey();
        }
    }
    return res;
}

bool AbstractTestTask::isInnerCodeRepresent(const Key &key) const
{
    for (int i = 0; i < keys.length(); i++)
    {
        if (key == keys.at(i) && key.getKeyType() == key.InnerCode)
        {
            return true;
        }
    }

    return false;
}

bool AbstractTestTask::isOuterCodeRepresent(const Key &key) const
{
    for (int i = 0; i < keys.length(); i++)
    {
        if (key == keys.at(i) && key.getKeyType() == key.OuterCode)
        {
            return true;
        }
    }

    return false;
}

