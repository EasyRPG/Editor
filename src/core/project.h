#ifndef PROJECT_H
#define PROJECT_H

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

#include <QObject>
#include <QDebug>
#include <data.h>
#include <ldb_reader.h>
#include <lmt_reader.h>
#include <string>
#include "enums.h"
#include "projectsettings.h"
#include "../mainwindow.h"

//class MainWindow;

class Project : public QObject
{
    Q_OBJECT
public:
    explicit Project(QObject *parent = 0);

    void Load(QString projectPath);

    QString getGameTitle();
    void setGameTitle(const QString &n_gameTitle);

    Layer getEditionLayer() const;
    void setEditionLayer(Layer layer);

    static void setCurrent(Project *n_current);
signals:

    void gameTitleChanged(QString n_gameTitle);

    void editionLayerChanged(Layer layer);

private:

    QString path;
    QString filePath(const QString &folder, const QString &filename);
    RPG::Database data;
    ProjectSettings *settings;
    MainWindow *window;

    static Project *m_current;
};
#endif // PROJECT_H
