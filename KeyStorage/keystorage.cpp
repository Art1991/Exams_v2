#include "keystorage.hpp"



const QList<KeyStorageNode> KeyStorage::getNodes(const Key &value) const
{
    QList<KeyStorageNode> outList;
    for(int i = 0; i < Storage.count(); i++)
    {
        for(int j = 0; j < Storage.at(i).getKeyList().count(); j++)
        {
            if(value == Storage.at(i).getKeyList().at(i))
                outList.push_back(Storage.at(i));
        }
    }
    return outList;
}

const QList<KeyStorageNode> KeyStorage::getNodes(const QList<Key> &value) const
{
    QList<KeyStorageNode> outList;
    for(int i = 0; i < value.count(); i++)
    {
        outList.append(getNodes(value.at(i)));
    }
    return outList;
}

const KeyStorageNode KeyStorage::getBaseNode(const Key &value) const
{
  /*  KeyStorageNode outKey; исправить
    Key key = value;
    for(int i = 0; i < Storage.count(); i++)
    {
        for(int j = 0; j < Storage.at(i).getKeyList().count(); j++)
        {
            if (key.isChildrenFor(Storage.at(i).getKeyList().at(j)))
            {
                key = Storage.at(i).getKeyList().at(j);
                outKey = Storage.at(i);
                i = 0;
                break;
            }

        }
    }
    return outKey; */
}

const QList<KeyStorageNode> KeyStorage::getAllNodes() const
{
    return Storage;
}

void KeyStorage::addNode(const KeyStorageNode &value)
{
    Storage.push_back(value);
}

void KeyStorage::addNodes(const QList<KeyStorageNode> &value)
{
    for(int i = 0; i < value.count(); i++)
    {
        addNode(value.at(i));
    }
}
