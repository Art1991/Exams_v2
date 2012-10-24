#include <QStringList>
#include "key.hpp"

Key::Key(const QString &_code)
{
    levels = toLevels(_code);
    type = InnerCode;
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

bool Key::isParentFor(const Key &value) const
{
    Key key = value;
    QString strValue = key.getKey(); // родитель
    return (getKey().startsWith(strValue)
            && (strValue.count() < getKey().count())) ? true : false;
}

bool Key::isDirectParentFor(const Key &value) const
{
    bool isParent = isParentFor(value);
    if (isParent && (value.levels.length() == this->levels.length() + 1))
    {
        return true;
    }
    return false;
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

bool Key::isChildrenFor(const Key &value) const
{
    Key key = value;
    QString strValue = key.getKey();
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

QList<int> Key::toLevels() const
{
    return levels;
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

Key::KeyType Key::strToEnum(const QString &str) {
    QString str1 = str.toLower();
    if (str1.compare("innercode") == 0) {
        return Key::InnerCode;
    }
    if (str1.compare("outercode") == 0) {
        return Key::OuterCode;
    }
    return Key::Null;
}

QString Key::enumToStr( Key::KeyType type) {
    switch(type) {
    case Key::InnerCode:
        return "InnerCode";
    case Key::OuterCode:
        return "OuterCode";
    case Key::Null:
        return "Null";
    }
}


