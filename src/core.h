#ifndef CORE_H
#define CORE_H

#define chipsetIsNull() Core::tile(0).isNull()

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
/****************************/
#define EV 0x7FFE

#define CURRENT_PROJECT_KEY "current_project"
#define DEFAULT_DIR_KEY "default_dir"

#include <QPixmap>
#include <QListWidget>
#include "rpg_map.h"
#include "rpg_chipset.h"

class Core
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

    Core(){}

    static void Init();

    static void LoadMaps();
    static void LoadChipset();

    static int tileSize();
    static void setTileSize(int tileSize);

    static QString projectPath();
    static void setprojectPath(const QString &projectPath);

    static Layer layer();
    static void setLayer(const Layer &layer);

    static Tool tool();
    static void setTool(const Tool &tool);

    static QString gameTitle();
    static void setGameTitle(const QString &gameTitle);

    static RPG::Map *map();
    static void setMap(int id);

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

    static RPG::Map *m_map;
    static RPG::Chipset m_chipset;
    static int m_tileSize;
    static QString m_gameTitle;
    static QString m_projectPath;
    static Layer m_layer;
    static Tool m_tool;
    static QMap<int, QPixmap> m_tileCache;
    static QMap<int, short> m_dictionary;
    static QMap<int, RPG::Map> m_maps;
};

#endif // CORE_H
