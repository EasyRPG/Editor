#ifndef GAMEPROJECT_H
#define GAMEPROJECT_H

#include <QStringList>
#include <QVector>
#include "gamecharacter.h"
#include "tools/picojson.h"

class GameProject
{
public:
    GameProject();

    bool Load();
    bool Save();

    QVector<GameCharacter> characters();
    GameCharacter* character(int id);

    QString getRtpPath();
    void setRtpPath(QString n_path);

    QString getProjectPath();
    void setProjectPath(QString n_path);

    QString getGameTitle();
    void setGameTitle(QString n_name);

    int getTileSize();
    void setTileSize(int n_size);

    QString pathBackdrop();
    QString pathBackdrop(QString fileName);
    QString pathBattle();
    QString pathBattle(QString fileName);
    QString pathBattle2();
    QString pathBattle2(QString fileName);
    QString pathBattleCharSet();
    QString pathBattleCharSet(QString fileName);
    QString pathBattleWeapon();
    QString pathBattleWeapon(QString fileName);
    QString pathCharSet();
    QString pathCharSet(QString fileName);
    QString pathChipSet();
    QString pathChipSet(QString fileName);
    QString pathFaceSet();
    QString pathFaceSet(QString fileName);
    QString pathFrame();
    QString pathFrame(QString fileName);
    QString pathGameOver();
    QString pathGameOver(QString fileName);
    QString pathMonster();
    QString pathMonster(QString fileName);
    QString pathMovie();
    QString pathMovie(QString fileName);
    QString pathMusic();
    QString pathMusic(QString fileName);
    QString pathBackground();
    QString pathBackground(QString fileName);
    QString pathPicture();
    QString pathPicture(QString fileName);
    QString pathSound();
    QString pathSound(QString fileName);
    QString pathSystem();
    QString pathSystem(QString fileName);
    QString pathSystem2();
    QString pathSystem2(QString fileName);
    QString pathTitle();
    QString pathTitle(QString fileName);


    QStringList backdroplist(bool with_none = false) const;
    QStringList battlelist(bool with_none = false) const;
    QStringList battle2list(bool with_none = false) const;
    QStringList battlecharsetlist(bool with_none = false);
    QStringList battleweaponlist(bool with_none = false) const;
    QStringList charsetlist(bool with_none = false) const;
    QStringList chipsetlist(bool with_none = false) const;
    QStringList facesetlist(bool with_none = false) const;
    QStringList framelist(bool with_none = false) const;
    QStringList gameoverlist(bool with_none = false) const;
    QStringList monsterlist(bool with_none = false) const;
    QStringList movielist(bool with_none = false) const;
    QStringList musiclist(bool with_none = false) const;
    QStringList backgroundlist(bool with_none = false) const;
    QStringList picturelist(bool with_none = false) const;
    QStringList soundlist(bool with_none = false) const;
    QStringList systemlist(bool with_none = false) const;
    QStringList system2list(bool with_none = false) const;
    QStringList titlelist(bool with_none = false) const;

    void regbackdrop(QString file);
    void regbattle(QString file);
    void regbattle2(QString file);
    void regbattlecharset(QString file);
    void regbattleweapon(QString file);
    void regcharset(QString file);
    void regchipset(QString file);
    void regfaceset(QString file);
    void regframe(QString file);
    void reggameover(QString file);
    void regmonster(QString file);
    void regmovie(QString file);
    void regmusic(QString file);
    void regbackground(QString file);
    void regpicture(QString file);
    void regsound(QString file);
    void regsystem(QString file);
    void regsystem2(QString file);
    void regtitle(QString file);
private:
    QString m_path;
    QString r_path;
    QString m_gametitle;
    int m_tilesize;
    QVector<GameCharacter> m_characters;
    QStringList m_backdrop;
    QStringList m_battle;
    QStringList m_battle2;
    QStringList m_battlecharset;
    QStringList m_battleweapon;
    QStringList m_charset;
    QStringList m_chipset;
    QStringList m_faceset;
    QStringList m_frame;
    QStringList m_gameover;
    QStringList m_monster;
    QStringList m_movie;
    QStringList m_music;
    QStringList m_background;
    QStringList m_picture;
    QStringList m_sound;
    QStringList m_system;
    QStringList m_system2;
    QStringList m_title;
    QStringList r_backdrop;
    QStringList r_battle;
    QStringList r_battle2;
    QStringList r_battlecharset;
    QStringList r_battleweapon;
    QStringList r_charset;
    QStringList r_chipset;
    QStringList r_faceset;
    QStringList r_frame;
    QStringList r_gameover;
    QStringList r_monster;
    QStringList r_movie;
    QStringList r_music;
    QStringList r_background;
    QStringList r_picture;
    QStringList r_sound;
    QStringList r_system;
    QStringList r_system2;
    QStringList r_title;
};

#endif // GAMEPROJECT_H
