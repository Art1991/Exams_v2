#include "pluginconfigserializator.hpp"

PluginConfigSerializator::PluginConfigSerializator()
{
}

PluginInfo PluginConfigSerializator::loadPluginConfig(const QString &filename) {
    QDomDocument xml;
    try
    {
        loadXmlSchema(":/xsd/xsd/pluginconfig.xsd");

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

    QString title = xml.elementsByTagName("title").at(0).toElement().text();
    QString version = xml.elementsByTagName("testVersion").at(0).toElement().text();
    QString startCode = xml.elementsByTagName("startCode").at(0).toElement().text();
    QString author = xml.elementsByTagName("author").at(0).toElement().text();


    QDomNodeList units = xml.elementsByTagName("unit");
    QStringList codes;

    for (int i = 0; i < units.length(); i++)
    {

        codes.push_back(units.at(i).toElement().elementsByTagName("innerCode").at(0).toElement().text());
        codes.push_back(units.at(i).toElement().elementsByTagName("title").at(0).toElement().text());
        codes.push_back(units.at(i).toElement().elementsByTagName("practiceFile").at(0).toElement().text());
        codes.push_back(units.at(i).toElement().elementsByTagName("testFile").at(0).toElement().text());
    }
    PluginInfo t(title, author, version, startCode, codes );
    return t;
}




QDomDocument PluginConfigSerializator::getPluginConfigXML(PluginInfo info) {
    resultXml.clear();

    QDomElement root = resultXml.createElement("root");
    resultXml.appendChild(root);

    QDomElement globals = resultXml.createElement("globals");
    QDomElement title = resultXml.createElement("title");
    title.appendChild(resultXml.createTextNode(info.getTitle()));
    QDomElement version = resultXml.createElement("version");
    version.appendChild(resultXml.createTextNode(info.getVersion()));
    QDomElement startCode = resultXml.createElement("startCode");
    startCode.appendChild(resultXml.createTextNode(info.getDescription()));
    QDomElement author = resultXml.createElement("author");
    author.appendChild(resultXml.createTextNode(info.getAuthor()));
    globals.appendChild(title);
    globals.appendChild(version);
    globals.appendChild(startCode);
    globals.appendChild(author);
    root.appendChild(globals);

    for(int i = 0; i < info.getCodes().length() - 3; i = i + 4)
    {
        QDomElement unit = resultXml.createElement("unit");
        QDomElement innerCode = resultXml.createElement("innerCode");
        innerCode.appendChild(resultXml.createTextNode(info.getCodes().at(i)));
        unit.appendChild(innerCode);

        QDomElement title = resultXml.createElement("title");
        title.appendChild(resultXml.createTextNode(info.getCodes().at(i + 1)));
        unit.appendChild(title);
        QDomElement practiceFile = resultXml.createElement("practiceFile");
        practiceFile.appendChild(resultXml.createTextNode(info.getCodes().at(i + 2)));
        unit.appendChild(practiceFile);
        QDomElement testFile = resultXml.createElement("testFile");
        testFile.appendChild(resultXml.createTextNode(info.getCodes().at(i + 3)));
        unit.appendChild(testFile);
        root.appendChild(unit);
    }

    return resultXml;
}

void PluginConfigSerializator::savePluginConfig(PluginInfo info, const QString &filename) throw (Exception) {
    QFile xmlFile(filename);

    if (!xmlFile.open(QIODevice::WriteOnly))
    {
        throw Exception(Exception::FileOperationError, QString("Couldn't open file - " + filename));
    }

    xmlFile.write(getPluginConfigXML(info).toByteArray());

    xmlFile.close();
}
