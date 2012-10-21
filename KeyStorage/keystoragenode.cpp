#include "keystoragenode.hpp"

KeyStorageNode::KeyStorageNode()
{
}

const QString KeyStorageNode::getPluginName() const
{
    return name;
}

const QString KeyStorageNode::getLinkOnPlugin() const
{
    return fileLink;
}

const QString KeyStorageNode::getElementName() const
{
    return params;
}

const QList<Key> KeyStorageNode::getKeyList() const
{
    return KeyList;
}

const QList<KeyStorageNode::KeyBind> KeyStorageNode::getBinds() const
{
    return Binds;
}
