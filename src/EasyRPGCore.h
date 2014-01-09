#ifndef EASYRPGCORE_H
#define EASYRPGCORE_H

/****************************
 *      Global Access       *
 * **************************/
#define project() EasyRPGCore::currentProject()
#define projectPath() EasyRPGCore::currentProjectPath()

#include <QPixmap>
#include "gameproject.h"

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

private:
    static GameProject* m_currentProject;
    static QPixmap* m_currentChipset;
    static int m_tileSize;
    static QString m_currentGameTitle;
    static QString m_currentProjectPath;
    static QString m_RtpPath;
    static Layer m_currentLayer;
    static Tool m_currentTool;
    static Zoom m_currentZoom;
};

#endif // EASYRPGCORE_H
