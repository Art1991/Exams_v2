#include "plugininfo.hpp"

PluginInfo::PluginInfo(){
}

QString PluginInfo::getTitle() const{
    return title;
}

QString PluginInfo::getAuthor() const{
    return author;
}

QString PluginInfo::getVersion() const {
    return version;
}

QString PluginInfo::getDescription() const {
    return description;
}

QStringList PluginInfo::getCodes() const{
    return codes;
}

