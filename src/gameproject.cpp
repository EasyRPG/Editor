#include "gameproject.h"
#include <QStringList>

GameProject::GameProject()
{
}

QStringList GameProject::backdroplist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_backdrop.size();i++)
        list.append(m_backdrop.at(i).split(".").at(0));
    for (int i = 0; i < r_backdrop.size();i++)
        list.append("<RTP> " + r_backdrop[i].split(".").at(0));
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::battlelist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_battle.size();i++)
        list.append(m_battle[i].split(".")[0]);
    for (int i = 0; i < r_battle.size();i++)
        list.append("<RTP> " + r_battle[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::battle2list(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_battle2.size();i++)
        list.append(m_battle2[i].split(".")[0]);
    for (int i = 0; i < r_battle2.size();i++)
        list.append("<RTP> " + r_battle2[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::battlecharsetlist(bool with_none)
{
    QStringList list;
    for (int i = 0; i < m_battlecharset.size();i++)
        list.append(m_battlecharset[i].split(".")[0]);
    for (int i = 0; i < r_battlecharset.size();i++)
        list.append("<RTP> " + r_battlecharset[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::battleweaponlist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_battleweapon.size();i++)
        list.append(m_battleweapon[i].split(".")[0]);
    for (int i = 0; i < r_battleweapon.size();i++)
        list.append("<RTP> " + r_battleweapon[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::charsetlist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_charset.size();i++)
        list.append(m_charset[i].split(".")[0]);
    for (int i = 0; i < r_charset.size();i++)
        list.append("<RTP> " + r_charset[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::chipsetlist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_chipset.size();i++)
        list.append(m_chipset[i].split(".")[0]);
    for (int i = 0; i < r_chipset.size();i++)
        list.append("<RTP> " + r_chipset[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::facesetlist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_faceset.size();i++)
        list.append(m_faceset[i].split(".")[0]);
    for (int i = 0; i < r_faceset.size();i++)
        list.append("<RTP> " + r_faceset[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::framelist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_frame.size();i++)
        list.append(m_frame[i].split(".")[0]);
    for (int i = 0; i < r_frame.size();i++)
        list.append("<RTP> " + r_frame[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::gameoverlist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_gameover.size();i++)
        list.append(m_gameover[i].split(".")[0]);
    for (int i = 0; i < r_gameover.size();i++)
        list.append("<RTP> " + r_gameover[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::monsterlist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_monster.size();i++)
        list.append(m_monster[i].split(".")[0]);
    for (int i = 0; i < r_monster.size();i++)
        list.append("<RTP> " + r_monster[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::movielist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_movie.size();i++)
        list.append(m_movie[i].split(".")[0]);
    for (int i = 0; i < r_movie.size();i++)
        list.append("<RTP> " + r_movie[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::musiclist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_music.size();i++)
        list.append(m_music[i].split(".")[0]);
    for (int i = 0; i < r_music.size();i++)
        list.append("<RTP> " + r_music[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::backgroundlist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_background.size();i++)
        list.append(m_background[i].split(".")[0]);
    for (int i = 0; i < r_background.size();i++)
        list.append("<RTP> " + r_background[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::picturelist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_picture.size();i++)
        list.append(m_picture[i].split(".")[0]);
    for (int i = 0; i < r_picture.size();i++)
        list.append("<RTP> " + r_picture[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::soundlist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_sound.size();i++)
        list.append(m_sound[i].split(".")[0]);
    for (int i = 0; i < r_sound.size();i++)
        list.append("<RTP> " + r_sound[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::systemlist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_system.size();i++)
        list.append(m_system[i].split(".")[0]);
    for (int i = 0; i < r_system.size();i++)
        list.append("<RTP> " + r_system[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::system2list(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_system2.size();i++)
        list.append(m_system2[i].split(".")[0]);
    for (int i = 0; i < r_system2.size();i++)
        list.append("<RTP> " + r_system2[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::titlelist(bool with_none) const
{
    QStringList list;
    for (int i = 0; i < m_title.size();i++)
        list.append(m_title[i].split(".")[0]);
    for (int i = 0; i < r_title.size();i++)
        list.append("<RTP> " + r_title[i].split(".")[0]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}
