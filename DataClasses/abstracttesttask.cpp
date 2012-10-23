#include "abstracttesttask.hpp"

AbstractTestTask::AbstractTestTask()
{
}

const QStringList AbstractTestTask::getInnerCodes() const
{
    QStringList res;
    for (int i = 0; i < keys.count(); i++)
    {
        if (keys.at(i).getKeyType() == keys.at(i).innerCode)
        {
            res << keys.at(i).getKey();
        }
    }
    return res;
//    return innerCodes;
}

const QStringList AbstractTestTask::getOuterCodes() const
{
    QStringList res;
    for (int i = 0; i < keys.count(); i++)
    {
        if (keys.at(i).getKeyType() == keys.at(i).outerCode)
        {
            res << keys.at(i).getKey();
        }
    }
    return res;
//    return outerCodes;
}

bool AbstractTestTask::isInnerCodeRepresent(const Key &key) const
{
//    for (int i = 0; i < innerCodes.length(); i++)
//    {
//        if (innerCode == innerCodes.at(i))
//        {
//            return true;
//        }
//    }

//    return false;
    (key.getKeyType() == Key::innerCode) ? true : false;
}

bool AbstractTestTask::isOuterCodeRepresent(const Key &key) const
{
//    for (int i = 0; i < outerCodes.length(); i++)
//    {
//        if (outerCode == outerCodes.at(i))
//        {
//            return true;
//        }
//    }

//    return false;
    (key.getKeyType() == Key::outerCode) ? true : false;
}
