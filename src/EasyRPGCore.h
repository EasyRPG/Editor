#ifndef EASYRPGCORE_H
#define EASYRPGCORE_H

/****************************
 *      Global Access       *
 * **************************/
#define project() EasyRPGCore::currentProject()
#define projectPath() EasyRPGCore::currentProjectPath()

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
#define SUPLEFT  21
#define SUPRIGHT  41
#define SDOWNLEFT  70
#define SDOWNRIGHT  138

#include <QPixmap>
#include "gameproject.h"
#include "gamemap.h"

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

    static QString pathBackdrop();
    static QString pathBackdrop(QString fileName);
    static QString pathBattle();
    static QString pathBattle(QString fileName);
    static QString pathBattle2();
    static QString pathBattle2(QString fileName);
    static QString pathBattleCharSet();
    static QString pathBattleCharSet(QString fileName);
    static QString pathBattleWeapon();
    static QString pathBattleWeapon(QString fileName);
    static QString pathCharSet();
    static QString pathCharSet(QString fileName);
    static QString pathChipSet();
    static QString pathChipSet(QString fileName);
    static QString pathFaceSet();
    static QString pathFaceSet(QString fileName);
    static QString pathFrame();
    static QString pathFrame(QString fileName);
    static QString pathGameOver();
    static QString pathGameOver(QString fileName);
    static QString pathMonster();
    static QString pathMonster(QString fileName);
    static QString pathMovie();
    static QString pathMovie(QString fileName);
    static QString pathMusic();
    static QString pathMusic(QString fileName);
    static QString pathBackground();
    static QString pathBackground(QString fileName);
    static QString pathPicture();
    static QString pathPicture(QString fileName);
    static QString pathSound();
    static QString pathSound(QString fileName);
    static QString pathSystem();
    static QString pathSystem(QString fileName);
    static QString pathSystem2();
    static QString pathSystem2(QString fileName);
    static QString pathTitle();
    static QString pathTitle(QString fileName);

    static GameProject *currentProject();
    static void setCurrentProject(GameProject *currentProject);

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
    static void setCurrentMapWidth(int currentMapWidth);

    static int currentMapHeight();
    static void setCurrentMapHeight(int currentMapHeight);

    static void setCurrentMapSize(int w, int h);

    static GameMap *currentMap();
    static void setCurrentMap(GameMap *currentMap);

private:
    static bool isWater(int tile_id);
    static bool isABWater(int tile_id);
    static bool isDWater(int tile_id);

    static GameProject* m_currentProject;
    static GameMap* m_currentMap;
    static int m_tileSize;
    static QString m_currentGameTitle;
    static QString m_currentProjectPath;
    static QString m_RtpPath;
    static Layer m_currentLayer;
    static Tool m_currentTool;
    static Zoom m_currentZoom;
    static QMap<int, QPixmap> m_currentChipset;
};

#endif // EASYRPGCORE_H
