#include <QStringList>
#include "key.hpp"

Key::Key()
{
}

Key::Key(const QString &_code, const KeyType &_type)
{
    levels = toLevels(_code);
    type = _type;
}

bool Key::operator ==(const Key &value) const
{
    Key key = value;    
    if ((key.levels.count() == levels.count()) && (key.type == type))
    {
        for (int i = 0; i < levels.count(); i++)
        {
            if (key.levels.at(i) != levels.at(i))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Key::isChildrenFor(const Key &value) const
{
    Key key = value;
    QString strValue = key.getKey(); // родитель
    return (getKey().startsWith(strValue)
            && (strValue.count() < getKey().count())) ? true : false;
}

bool Key::isNeighborFor(const Key &value) const
{
    Key key = value;
    if (key.levels.count() == levels.count())
    {
        for (int i = 0; i < levels.count() - 1; i++)
        {
            if (key.levels.at(i) != levels.at(i))
            {
                return false;
            }
        }
        if (key.levels.at(levels.count() - 1) != levels.at(levels.count() - 1))
        {
            return true;
        }
    }
    return false;
}

bool Key::isParentFor(const Key &value) const
{
    Key key = value;
    QString strValue = key.getKey(); // потомок
    return (strValue.startsWith(getKey())
            && (getKey().count() < strValue.count())) ? true : false;
}

QList<int> Key::toLevels(const QString &code)
{
    QList<int> res;
    QString str = code;
    str = str.simplified();
    QStringList strLevels = str.split(".");
    for (int i = 0; i < strLevels.count(); i++)
    {
        res << strLevels.at(i).toInt();
    }
    return res;
}

const Key::KeyType Key::getKeyType() const
{
    return type;
}

const QString Key::getKey() const
{
    QString str = "";
    int sizeLevels = levels.count();
    for (int i = 0; i < sizeLevels - 1; i++)
    {
        str += QString::number(levels.at(i)) + ".";
    }
    str += QString::number(levels.at(sizeLevels - 1));
    return str;
}
