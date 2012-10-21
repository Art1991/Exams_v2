#ifndef KEYSTORAGENODE_HPP
#define KEYSTORAGENODE_HPP

#include "key.hpp"
#include <QString>

class KeyStorageNode
{
public:
    enum KeyBind {
        ExamsTestTask,
        ExamsTest,
        ReviewedTestTask,
        ReviewedTest,
        Theory,
        Plugin
    };


    KeyStorageNode();
    KeyStorageNode(const QList<Key> &_KeyList, const QList<KeyBind> &_Binds, const QString &_name,
                   const QString &_fileLink, const QString &_params):KeyList(_KeyList), Binds(_Binds),
        name(_name), fileLink(_fileLink), params(_params) {}

    const QString getPluginName() const;
    const QString getLinkOnPlugin() const;
    const QString getElementName() const;

    const QList<Key> getKeyList() const;
    const QList<KeyBind> getBinds() const;

private:

    QList<Key> KeyList; // список ключей
    QList<KeyBind> Binds; // к чему список ключей относится
    // где искать
    QString name; //имя плагина
    QString fileLink; //ссылка на плагин
    QString params; // имя элемента в плагине
};

#endif // KEYSTORAGENODE_HPP
