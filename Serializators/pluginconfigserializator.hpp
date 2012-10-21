#ifndef PLUGINCONFIGSERIALIZATOR_H
#define PLUGINCONFIGSERIALIZATOR_H

#include "../Plugins/plugininfo.hpp"
#include "../DataClasses/dataclasses.hpp"
#include "../DataClasses/exception.hpp"
#include "fieldschecker.hpp"
#include "abstractserializator.hpp"

class PluginConfigSerializator : public AbstractSerializator
{
public:
    PluginConfigSerializator();

    PluginInfo loadPluginConfig(const QString &filename);
    void savePluginConfig(PluginInfo info, const QString &filename) throw (Exception);

private:
    QDomDocument getPluginConfigXML(PluginInfo info);
};

#endif // PLUGINCONFIGSERIALIZATOR_H
