#ifndef GAMEPROJECT_H
#define GAMEPROJECT_H

#define reg(string, list) if (list.contains(string)) return; list.append(string);list.sort(Qt::CaseInsensitive);

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

    inline QVector<GameCharacter> characters() {return m_characters;}
    inline GameCharacter* character(int id) {return &m_characters[id];}

    inline QString getRtpPath() {return r_path;}
    inline void setRtpPath(QString n_path) {r_path = n_path;}

    inline QString getProjectPath() {return m_path;}
    inline void setProjectPath(QString n_path) {m_path = n_path;}

    inline QString getGameTitle() {return m_gametitle;}
    inline void setGameTitle(QString n_name) {m_gametitle = n_name;}

    inline int getTileSize() {return m_tilesize;}
    inline void setTileSize(int n_size) {m_tilesize = n_size;}

    inline QString pathBackdrop() {return m_path+"Backdrop\\";}
    inline QString pathBackdrop(QString fileName) {return pathBackdrop()+fileName;}
    inline QString pathBattle() {return m_path+"Battle\\";}
    inline QString pathBattle(QString fileName) {return pathBattle()+fileName;}
    inline QString pathBattle2() {return m_path+"Battle2\\";}
    inline QString pathBattle2(QString fileName) {return pathBattle2()+fileName;}
    inline QString pathBattleCharSet() {return m_path+"BattleCharSet\\";}
    inline QString pathBattleCharSet(QString fileName) {return pathBattleCharSet()+fileName;}
    inline QString pathBattleWeapon() {return m_path+"BattleWeapon\\";}
    inline QString pathBattleWeapon(QString fileName) {return pathBattleWeapon()+fileName;}
    inline QString pathCharSet() {return m_path+"CharSet\\";}
    inline QString pathCharSet(QString fileName) {return pathCharSet()+fileName;}
    inline QString pathChipSet() {return m_path+"ChipSet\\";}
    inline QString pathChipSet(QString fileName) {return pathChipSet()+fileName;}
    inline QString pathFaceSet() {return m_path+"FaceSet\\";}
    inline QString pathFaceSet(QString fileName) {return pathFaceSet()+fileName;}
    inline QString pathFrame() {return m_path+"Frame\\";}
    inline QString pathFrame(QString fileName) {return pathFrame()+fileName;}
    inline QString pathGameOver() {return m_path+"GameOver\\";}
    inline QString pathGameOver(QString fileName) {return pathGameOver()+fileName;}
    inline QString pathMonster() {return m_path+"Monster\\";}
    inline QString pathMonster(QString fileName) {return pathMonster()+fileName;}
    inline QString pathMovie() {return m_path+"Movie\\";}
    inline QString pathMovie(QString fileName) {return pathMovie()+fileName;}
    inline QString pathMusic() {return m_path+"Music\\";}
    inline QString pathMusic(QString fileName) {return pathMusic()+fileName;}
    inline QString pathBackground() {return m_path+"Background\\";}
    inline QString pathBackground(QString fileName) {return pathBackground()+fileName;}
    inline QString pathPicture() {return m_path+"Picture\\";}
    inline QString pathPicture(QString fileName) {return pathPicture()+fileName;}
    inline QString pathSound() {return m_path+"Sound\\";}
    inline QString pathSound(QString fileName) {return pathSound()+fileName;}
    inline QString pathSystem() {return m_path+"System\\";}
    inline QString pathSystem(QString fileName) {return pathSystem()+fileName;}
    inline QString pathSystem2() {return m_path+"System2\\";}
    inline QString pathSystem2(QString fileName) {return pathSystem2()+fileName;}
    inline QString pathTitle() {return m_path+"Title\\";}
    inline QString pathTitle(QString fileName) {return pathTitle()+fileName;}


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

    inline void regbackdrop(QString file) {reg(file, m_backdrop);}
    inline void regbattle(QString file) {reg(file, m_battle);}
    inline void regbattle2(QString file) {reg(file, m_battle2);}
    inline void regbattlecharset(QString file) {reg(file, m_battlecharset);}
    inline void regbattleweapon(QString file) {reg(file, m_battleweapon);}
    inline void regcharset(QString file) {reg(file, m_charset);}
    inline void regchipset(QString file) {reg(file, m_chipset);}
    inline void regfaceset(QString file) {reg(file, m_faceset);}
    inline void regframe(QString file) {reg(file, m_frame);}
    inline void reggameover(QString file) {reg(file, m_gameover);}
    inline void regmonster(QString file) {reg(file, m_monster);}
    inline void regmovie(QString file) {reg(file, m_movie);}
    inline void regmusic(QString file) {reg(file, m_music);}
    inline void regbackground(QString file) {reg(file, m_background);}
    inline void regpicture(QString file) {reg(file, m_picture);}
    inline void regsound(QString file) {reg(file, m_sound);}
    inline void regsystem(QString file) {reg(file, m_system);}
    inline void regsystem2(QString file) {reg(file, m_system2);}
    inline void regtitle(QString file) {reg(file, m_title); }
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
