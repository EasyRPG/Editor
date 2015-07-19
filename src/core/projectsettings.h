#ifndef PROJECTSETTINGS_H
#define PROJECTSETTINGS_H

/****************************
 *     PROJECT SETTINGS     *
 * **************************/
#define LAYER "Layer"
#define MAPS "ActiveMaps"
//#define SCALES "ActiveMapScales"
#define TILESIZE "TileSize"
#define GAMETITLE "GameTitle"

#include <QList>
#include <QFileInfo>
#include <QSettings>
#include "enums.h"

class ProjectSettings : public QObject
{
    Q_OBJECT
public:
    ProjectSettings(QObject *parent, const QString &filePath);

    QString getGameTitle();
    void setGameTitle(const QString &n_title);

    Layer getEditionLayer() const;
    void setEditionLayer(Layer layer);

    int getTileSize();
    void setTileSize(int size);

    QList<int> getLastSesionMaps() const;
    void setLastSesionMaps(const QList<int> &maps);

private:

    QSettings *settings;
};

#endif // PROJECTSETTINGS_H
