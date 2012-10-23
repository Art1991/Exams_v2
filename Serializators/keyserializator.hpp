#ifndef KEYSERIALIZATOR_HPP
#define KEYSERIALIZATOR_HPP

#include "../KeyStorage/keystoragenode.hpp"
#include "abstractserializator.hpp"


class KeySerializator : public AbstractSerializator
{
public:
    KeySerializator();
    QList<KeyStorageNode> loadKeys(const QString &filename, const KeyStorageNode::KeyBind &typeXml);
    QList<Key> getKeyList(const QDomElement &element);
    QString getElementName(const QString &type);

    QList<KeyStorageNode> loadKeys(const QString &url);
    QFileInfoList getAllHtml(const QString &dir);
};

#endif // KEYSERIALIZATOR_HPP
