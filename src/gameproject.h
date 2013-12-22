#ifndef GAMEPROJECT_H
#define GAMEPROJECT_H

#define reg(string, list) if (list.contains(string)) return; list.append(string);list.sort(Qt::CaseInsensitive);

#include <QStringList>
#include <QVector>
#include "gamecharacter.h"

class GameProject
{
public:
    GameProject();

    inline QVector<GameCharacter> characters() {return m_characters;}

    inline QString getProjectPath() {return m_path;}
    inline void setProjectPath(QString n_path) {m_path = n_path;}

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
