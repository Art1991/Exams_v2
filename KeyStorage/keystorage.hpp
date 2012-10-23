#ifndef KEYSTORAGE_HPP
#define KEYSTORAGE_HPP

#include "keystoragenode.hpp"
class KeyStorage
{
    QList<KeyStorageNode> Storage;
public:
    KeyStorage();
    KeyStorage(const QList<KeyStorageNode> &storage):Storage(storage){}

    const QList<KeyStorageNode> getNodes(const Key &value) const;
    const QList<KeyStorageNode> getNodes(const QList<Key> &value) const;
    const KeyStorageNode getBaseNode(const Key &value) const;
    const QList<KeyStorageNode> getAllNodes() const;
    void addNode(const KeyStorageNode &value);
    void addNodes(const QList<KeyStorageNode> &value);
};

#endif // KEYSTORAGE_HPP
