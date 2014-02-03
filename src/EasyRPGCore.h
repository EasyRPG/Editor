#ifndef EASYRPGCORE_H
#define EASYRPGCORE_H

/****************************
 *      Global Access       *
 * **************************/
#define project() EasyRPGCore::currentProject()
#define projectPath() EasyRPGCore::currentProjectPath()
#define _map() EasyRPGCore::currentMap()

#define chipsetIsNull() EasyRPGCore::tile(0).isNull()

/****************************
 *     Binding Constants    *
 * **************************/
#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 8
#define UPLEFT 16
#define UPRIGHT  32
#define DOWNLEFT  64
#define DOWNRIGHT  128

#include <QPixmap>
#include <QListWidget>
#include "rpg_map.h"

class GameMap;

class EasyRPGCore
{
public:

    enum Layer
    {
        LOWER,
        UPPER,
        EVENT
    };

    enum Tool
    {
        SELECTION,
        ZOOM,
        PENCIL,
        RECTANGLE,
        CIRCLE,
        FILL
    };

    //TODO: Replace old ugly zoom mode with a percentual zoom mode
    enum Zoom
    {
        Z_11,
        Z_12,
        Z_14,
        Z_18
    };

    EasyRPGCore(){}

    static void Init();

    static void LoadChipset(QString n_chipset);

    static int tileSize();
    static void setTileSize(int tileSize);

    static QString currentProjectPath();
    static void setCurrentProjectPath(const QString &currentProjectPath);

    static Layer currentLayer();
    static void setCurrentLayer(const Layer &currentLayer);

    static Tool currentTool();
    static void setCurrentTool(const Tool &currentTool);

    static Zoom currentZoom();
    static void setCurrentZoom(const Zoom &currentZoom);

    static QString RtpPath();
    static void setRtpPath(const QString &RtpPath);

    static QString currentGameTitle();
    static void setCurrentGameTitle(const QString &currentGameTitle);

    static int currentMapWidth();

    static int currentMapHeight();

    static RPG::Map *currentMap();
    static void setCurrentMap(RPG::Map *currentMap);

    static QListWidget* debugChipset();

    static QPixmap tile(short tile_id);

    static short translate(int terrain_id, int _code = 0, int _scode = 0);
    static int translate(short tile_id);

private:
    static bool isWater(int terrain_id);
    static bool isABWater(int terrain_id);
    static bool isDWater(int terrain_id);
    static bool isAnimation(int terrain_id);
    static bool isDblock(int terrain_id);
    static bool isEblock(int terrain_id);
    static bool isFblock(int terrain_id);

    static QListWidget* m_debugChipset;

    static RPG::Map *m_currentMap;
    static int m_tileSize;
    static QString m_currentGameTitle;
    static QString m_currentProjectPath;
    static QString m_RtpPath;
    static Layer m_currentLayer;
    static Tool m_currentTool;
    static Zoom m_currentZoom;
    static QMap<int, QPixmap> m_currentChipset;
    static QMap<int, short> m_dictionary;
};

#endif // EASYRPGCORE_H
