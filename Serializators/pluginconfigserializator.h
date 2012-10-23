#ifndef PLUGINCONFIGSERIALIZATOR_H
#define PLUGINCONFIGSERIALIZATOR_H

#include "../Plugins/plugininfo.h"
#include "../DataClasses/dataclasses.h"
#include "../DataClasses/exception.h"
#include "fieldschecker.h"
#include "abstractserializator.h"

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
