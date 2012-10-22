#ifndef KEYSTORAGENODE_HPP
#define KEYSTORAGENODE_HPP

#include "key.hpp"
#include <QString>
#include <QMetaEnum>

class KeyStorageNode
{
public:
   enum KeyBind {
        ExamsTestTask,
        ExamsTest,
        ReviewedTestTask,
        ReviewedTest,
        Theory,
        Plugin,
        PluginUnit
    };


    KeyStorageNode();
    KeyStorageNode(const QList<Key> &_KeyList, const KeyBind &_Bind, const QString &_name,
                   const QString &_fileLink, const QString &_params):KeyList(_KeyList), Bind(_Bind),
        name(_name), fileLink(_fileLink), params(_params) {}

    const QString getPluginName() const;
    const QString getLinkOnPlugin() const;
    const QString getElementName() const;

    const QList<Key> getKeyList() const;
    const KeyBind getBind() const;

    static  QString enumToStr(KeyBind enumVal);
    static  KeyBind strToEnum(const QString &str);
private:

    QList<Key> KeyList; // список ключей
    KeyBind Bind; // к чему список ключей относится
    // где искать
    QString name; //имя плагина
    QString fileLink; //ссылка на плагин
    QString params; // имя элемента в плагине
};

#endif // KEYSTORAGENODE_HPP
