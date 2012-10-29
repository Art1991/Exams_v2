#include "keystorage.hpp"



const QList<KeyStorageNode> KeyStorage::getNodes(const Key &value) const
{
    QList<KeyStorageNode> outList;
    for(int i = 0; i < Storage.count(); i++)
    {
        for(int j = 0; j < Storage.at(i).getKeyList().count(); j++)
        {
            if(value == Storage.at(i).getKeyList().at(j))
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
    int index = -1;
    Key key = value;
    for(int i = 0; i < Storage.count(); i++)
    {
        for(int j = 0; j < Storage.at(i).getKeyList().count(); j++)
        {
            if (key.isChildrenFor(Storage.at(i).getKeyList().at(j)))
            {
                key = Storage.at(i).getKeyList().at(j);
                index = i;
                i = 0;
                break;
            }

        }
    }
    if (index == -1) {
        QList<Key> list;
         KeyStorageNode outKey(list ,KeyStorageNode::Null ,"null","null","null");
        return outKey;
    }
    return Storage.at(index);
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
