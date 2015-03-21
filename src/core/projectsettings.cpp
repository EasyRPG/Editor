#include "projectsettings.h"

ProjectSettings::ProjectSettings(QObject *parent, const QString &filePath) :
    QObject(parent)
{
    QFileInfo info(filePath);
    if (info.isDir())
    {
        Exception e;
        e.title = "Error reading project settings";
        e.description = "Invalid file path: " + filePath;
        e.code = Exception::INVALID_FILE_PATH;
        throw (e);
    }
    //When file doesn't exist Qt automatically creates it.
    settings = new QSettings(filePath, QSettings::IniFormat, this);
}

QString ProjectSettings::getGameTitle()
{
    return settings->value(GAMETITLE, tr("Untitled")).toString();
}

void ProjectSettings::setGameTitle(const QString &n_title)
{
    settings->setValue(GAMETITLE, n_title);
}

Layer ProjectSettings::getEditionLayer() const
{
    return (Layer)(settings->value(LAYER, (int)LOWER).toInt());
}

void ProjectSettings::setEditionLayer(Layer layer)
{
    settings->setValue(LAYER, (int)layer);
}

int ProjectSettings::getTileSize()
{
    return settings->value(TILESIZE, 16).toInt();
}

void ProjectSettings::setTileSize(int size)
{
    settings->setValue(TILESIZE, size);
}

QList<int> ProjectSettings::getLastSesionMaps() const
{
    QList<QVariant> v_maps= settings->value(MAPS, QList<QVariant>()).toList();
    QList<int> i_maps = QList<int>();

    bool *ok = new bool;
    foreach (QVariant variant, v_maps)
    {
        int map = variant.toInt(ok);
        if (*ok)
            i_maps.append(map);
    }
    delete ok;

    return i_maps;
}

void ProjectSettings::setLastSesionMaps(const QList<int> &maps)
{
    QList<QVariant> v_maps = QList<QVariant>();

    foreach (int map, maps)
        v_maps.append(QVariant(map));

    settings->setValue(MAPS, v_maps);
}
