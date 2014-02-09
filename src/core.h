#ifndef CORE_H
#define CORE_H

#define mCore() Core::getCore()

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

/****************************
 *      SETTINGS KEYS       *
 * **************************/
#define CURRENT_PROJECT_KEY "current_project"
#define DEFAULT_DIR_KEY "default_dir"
#define RTP_KEY "rtp_path"

/****************************
 *     PROJECT SETTINGS     *
 * **************************/
#define LAYER "layer"
#define MAPS "active_maps"
#define SCALES "active_map_scales"
#define TILESIZE "tile_size"

/****************************
 *      FOLDER CONSTANTS    *
 * **************************/
#define ROOT ""
#define BACKDROP "Backdrop/"
#define BATTLE "Battle/"
#define BATTLE2 "Battle2/"
#define BATTLECHARSET "BattleCharSet/"
#define BATTLEWEAPON "BattleWeapon/"
#define CHARSET "CharSet/"
#define CHIPSET "ChipSet/"
#define FACESET "FaceSet/"
#define FRAME "Frame/"
#define GAMEOVER "GameOver/"
#define MONSTER "Monster/"
#define MOVIE "Movie/"
#define MUSIC "Music/"
#define PANORAMA "Panorama/"
#define PICTURE "Picture/"
#define SOUND "Sound/"
#define SYSTEM "System/"
#define SYSTEM2 "System2/"
#define TITLE "Title/"

/***************************
 *        FILE NAMES       *
 * *************************/
#define RM_DB "RPG_RT.ldb"
#define RM_MT "RPG_RT.lmt"
#define RM_INI "RPG_RT.ini"
//      RM_LMU "MapXXXX.lmu"
/***************************/
#define EASY_DB "EASY_RT.edb"
#define EASY_MT "EASY_RT.emt"
#define EASY_CFG "EASY_RT.cfg"
//      EASY_EMU "MapXXXX.emu"

#include <QPixmap>
#include <QPainter>
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

    Core();

    static Core* getCore();

    void LoadChipset(int n_chipsetid);

    QWidget *getMapTab(int id);
    QWidget *createMapTab(int id, QWidget*parent);
    void deleteMapTab(int id);

    int tileSize();
    void setTileSize(int tileSize);

    QString filePath(QString folder, QString filename = QString());

    Layer layer();
    void setLayer(const Layer &layer);

    Tool tool();
    void setTool(const Tool &tool);

    QString gameTitle();
    void setGameTitle(const QString &gameTitle);

    void beginPainting(QPixmap &dest);
    void renderTile(short tile_id, QRect dest_rect);
    void endPainting();

    QColor keycolor();

    short translate(int terrain_id, int _code = 0, int _scode = 0);
    int translate(short tile_id);

    inline bool chipsetIsNull() {return m_tileCache[0].isNull();}

    bool isWater(int terrain_id);
    bool isABWater(int terrain_id);
    bool isDWater(int terrain_id);
    bool isAnimation(int terrain_id);
    bool isDblock(int terrain_id);
    bool isEblock(int terrain_id);
    bool isFblock(int terrain_id);

    QString defDir() const;
    void setDefDir(const QString &defDir);

    QString projectFolder() const;
    void setProjectFolder(const QString &projectFolder);

private:
    RPG::Map *m_map;
    RPG::Chipset m_chipset;
    int m_tileSize;
    QPainter m_painter;
    QString m_gameTitle;
    QString m_defDir;
    QString m_projectFolder;
    QColor m_keycolor;
    Layer m_layer;
    Tool m_tool;
    QMap<int, QPixmap> m_tileCache;
    QMap<int, short> m_dictionary;
    QMap<int, RPG::Map> m_maps;
    QMap<int, QWidget*> m_mapTabs;
    static Core *core;
};

#endif // CORE_H
