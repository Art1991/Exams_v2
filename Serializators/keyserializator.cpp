
#include "keyserializator.hpp"


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
         KeyStorageNode a(getKeyList(elements.at(0).toElement()), typeXml,
                       xml.elementsByTagName("title").at(0).toElement().text(),
                       filename,elementName);

    }

    //....
    return outList;
}
QList<Key> KeySerializator::getKeyList(const QDomElement &element){
   QDomNodeList childs = element.childNodes();
//QString q1 = element.attributes().item(0).nodeName();
   QList<Key> keyList;
   for(int i = 0; i< childs.count(); i++){
       Key::KeyType nodeName= Key::strToEnum(childs.at(i).nodeName());
       if (nodeName == Key::innerCode || nodeName == Key::outerCode) {
           keyList.push_back(Key(childs.at(i).toElement().text()
                                ,nodeName));
       }
   }
   return keyList;
}

QString KeySerializator::getElementName(const QString &type) {
    if (type == "examstest" || type == "reviewedtest") {
        return "task";
    }
    if (type == "plugin") {
        return "unit";
    }
    if (type == "theory" ) {
        return "";
    }
}


