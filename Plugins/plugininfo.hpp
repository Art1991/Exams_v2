#ifndef PLUGININFO_H
#define PLUGININFO_H

#include <QString>
#include <QStringList>

class PluginInfo
{
public:

   QString getTitle() const;
   QString getAuthor() const;
   QString getVersion() const;
   QString getDescription() const;
   QStringList getCodes() const;

    PluginInfo();
    PluginInfo (QString Title, QString Author, QString Version, QString Description, QStringList Codes) :
        title(Title), author(Author), version(Version), description(Description),  codes(Codes) {}

private:

    QString title;
    QString author;
    QString version;
    QString description;
    QStringList codes;

};

#endif // PLUGININFO_H
