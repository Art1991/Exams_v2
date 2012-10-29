#include "keystoragenode.hpp"



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
    return keyList;
}

const KeyStorageNode::KeyBind KeyStorageNode::getBind() const
{
    return bind;
}

const QList<Key> KeyStorageNode::getInnerKeys() const{
    QList<Key> res;
    for (int i = 0; i < keyList.count(); i++) {
        if (keyList.at(i).getKeyType() == Key::InnerCode) {
            res.push_back(keyList.at(i));
        }
    }
    return res;
}

const QList<Key> KeyStorageNode::getOuterKeys() const{
    QList<Key> res;
    for (int i = 0; i < keyList.count(); i++)
    {
        if (keyList.at(i).getKeyType() == Key::OuterCode) {
            res.push_back(keyList.at(i));
        }
    }
    return res;
}

KeyStorageNode::KeyBind KeyStorageNode::strToEnum(const QString &str) {
    QString str1 = str.toLower();
    if (str1 == "plugin")
        return KeyStorageNode::Plugin;
    if(str1== "pluginunit")
        return KeyStorageNode::PluginUnit;
    if (str1== "theory")
        return KeyStorageNode::Theory;
    if(str1== "examstest")
        return KeyStorageNode::ExamsTest;
    if(str1=="examstesttask")
        return KeyStorageNode::ExamsTestTask;
    if (str1== "reviewedtesttask")
        return KeyStorageNode::ReviewedTestTask;
    if (str1== "reviewedtest")
        return KeyStorageNode::ReviewedTest;
    return KeyStorageNode::Null;

}

QString KeyStorageNode::enumToStr(const KeyStorageNode::KeyBind &enumVal) {
    switch(enumVal) {
    case KeyStorageNode::ExamsTestTask:
        return "ExamsTestTask";
    case KeyStorageNode::ExamsTest:
        return "ExamsTest";
    case KeyStorageNode::ReviewedTestTask:
        return "ReviewedTestTask";
    case KeyStorageNode::ReviewedTest:
        return "ReviewedTest";
    case KeyStorageNode::Theory:
        return "Theory";
    case KeyStorageNode::Plugin:
        return "Plugin";
    case KeyStorageNode::PluginUnit:
        return "PluginUnit";
    default:
        return "";
    }
}

