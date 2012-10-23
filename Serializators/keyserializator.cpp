
#include "keyserializator.hpp"
#include <QDir>

KeySerializator::KeySerializator()
{
}

QList<KeyStorageNode> KeySerializator::loadKeys(const QString &filename, const KeyStorageNode::KeyBind &typeXml) {
    QDomDocument xml;
    QString type =  KeyStorageNode::enumToStr(typeXml).toLower();
    KeyStorageNode::KeyBind a = KeyStorageNode::strToEnum("plugin");
    try
    {
        loadXmlSchema(":/xsd/xsd/" + type + "config.xsd");
        xml = loadXml(filename);
        if (!checkXml(xml))
        {
            throw Exception(Exception::BadXMLFile, QString("Bad XML file - " + filename));
        }
    }
    catch (const Exception &err)
    {
        throw;
    }
    QList<KeyStorageNode> outList;
    QString elementName = getElementName(type);
    QDomNodeList elements= xml.elementsByTagName(elementName);
    for(int i =0; i < elements.count();i++) {
        outList.push_back( KeyStorageNode(getKeyList(elements.at(0).toElement()), typeXml,
                                          xml.elementsByTagName("title").at(0).toElement().text(),
                                          filename,elementName));

    }
    QList<Key> keyList;
    for (int i = 0; i < outList.count(); i++) {
        keyList.append(outList.at(i).getKeyList());
    }
    outList.push_front(KeyStorageNode(keyList,typeXml, xml.elementsByTagName("title").at(0).toElement().text(),
                                      filename, KeyStorageNode::enumToStr(typeXml))); return outList;
}



QList<Key> KeySerializator::getKeyList(const QDomElement &element){
    QDomNodeList childs = element.childNodes();
    QList<Key> keyList;
    for(int i = 0; i< childs.count(); i++){
        Key::KeyType nodeName = Key::strToEnum(childs.at(i).nodeName());
        if (nodeName == Key::innerCode || nodeName == Key::outerCode) {
            keyList.push_back(Key(childs.at(i).toElement().text()
                                  ,nodeName));
        }
    }
    return keyList;
}

QString KeySerializator::getElementName(const QString &type) {
    if (type.compare("examstest")*type.compare("reviewedtest") == 0) {
        return "task";
    }
    if (type.compare( "plugin") == 0) {
        return "unit";
    }
    if (type.compare("theory") == 0 ) {
        return "theory";
    }
    return "";
}


QList<KeyStorageNode> KeySerializator::loadKeys(const QString &url) {
    QFileInfoList allHtml = getAllHtml(url);
    QList<KeyStorageNode> outList;
    for (int i = 0; i < allHtml.count(); i++) {
        QString key = allHtml.at(i).fileName().split("_").at(0);
        QString name = allHtml.at(i).fileName().split("_").at(1);
        QList<Key> list;
        list.push_back(Key(key, Key::innerCode));
        outList.push_back(KeyStorageNode(list, KeyStorageNode::Theory, name, allHtml.at(i).filePath(), "theory"));
    }
    return outList;
}

QFileInfoList KeySerializator::getAllHtml(const QString &dir) {
    QFileInfoList list;
    QDirIterator iterator (dir, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while(iterator.hasNext())
    {
        iterator.next();
        QDir directory(iterator.fileInfo().absolutePath());

        QFileInfoList dirContent = directory.entryInfoList(QStringList()
                                                           << "*.html" << "*.htm",
                                                           QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

       list.append(dirContent);
    }
    return list;
}



