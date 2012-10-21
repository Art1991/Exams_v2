#ifndef KEYSERIALIZATOR_HPP
#define KEYSERIALIZATOR_HPP

#include "../KeyStorage/keystoragenode.hpp"
#include "abstractserializator.hpp"

class KeySerializator : public AbstractSerializator
{
public:
    KeySerializator();
    QList<KeyStorageNode> loadKeys(const QString &filename);

};

#endif // KEYSERIALIZATOR_HPP
