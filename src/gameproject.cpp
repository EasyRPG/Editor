#include "gameproject.h"
#include <QString>

GameProject::GameProject()
{
    m_backdrop = QStringList();

}

QStringList GameProject::backdroplist(bool with_none) const
{
    QStringList list = QStringList(m_backdrop);
    for (int i = 0; i < r_backdrop.size();i++)
        list.append("<RTP> " + r_backdrop[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::battlelist(bool with_none) const
{
    QStringList list = QStringList(m_battle);
    for (int i = 0; i < r_battle.size();i++)
        list.append("<RTP> " + r_battle[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::battle2list(bool with_none) const
{
    QStringList list = QStringList(m_battle2);
    for (int i = 0; i < r_battle2.size();i++)
        list.append("<RTP> " + r_battle2[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::battlecharsetlist(bool with_none)
{
    QStringList list = QStringList(m_battlecharset);
    for (int i = 0; i < r_battlecharset.size();i++)
        list.append("<RTP> " + r_battlecharset[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::battleweaponlist(bool with_none) const
{
    QStringList list = QStringList(m_battleweapon);
    for (int i = 0; i < r_battleweapon.size();i++)
        list.append("<RTP> " + r_battleweapon[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::charsetlist(bool with_none) const
{
    QStringList list = QStringList(m_charset);
    for (int i = 0; i < r_charset.size();i++)
        list.append("<RTP> " + r_charset[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::chipsetlist(bool with_none) const
{
    QStringList list = QStringList(m_chipset);
    for (int i = 0; i < r_chipset.size();i++)
        list.append("<RTP> " + r_chipset[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::facesetlist(bool with_none) const
{
    QStringList list = QStringList(m_faceset);
    for (int i = 0; i < r_faceset.size();i++)
        list.append("<RTP> " + r_faceset[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::framelist(bool with_none) const
{
    QStringList list = QStringList(m_frame);
    for (int i = 0; i < r_frame.size();i++)
        list.append("<RTP> " + r_frame[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::gameoverlist(bool with_none) const
{
    QStringList list = QStringList(m_gameover);
    for (int i = 0; i < r_gameover.size();i++)
        list.append("<RTP> " + r_gameover[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::monsterlist(bool with_none) const
{
    QStringList list = QStringList(m_monster);
    for (int i = 0; i < r_monster.size();i++)
        list.append("<RTP> " + r_monster[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::movielist(bool with_none) const
{
    QStringList list = QStringList(m_movie);
    for (int i = 0; i < r_movie.size();i++)
        list.append("<RTP> " + r_movie[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::musiclist(bool with_none) const
{
    QStringList list = QStringList(m_music);
    for (int i = 0; i < r_music.size();i++)
        list.append("<RTP> " + r_music[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::backgroundlist(bool with_none) const
{
    QStringList list = QStringList(m_background);
    for (int i = 0; i < r_background.size();i++)
        list.append("<RTP> " + r_background[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::picturelist(bool with_none) const
{
    QStringList list = QStringList(m_picture);
    for (int i = 0; i < r_picture.size();i++)
        list.append("<RTP> " + r_picture[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::soundlist(bool with_none) const
{
    QStringList list = QStringList(m_sound);
    for (int i = 0; i < r_sound.size();i++)
        list.append("<RTP> " + r_sound[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::systemlist(bool with_none) const
{
    QStringList list = QStringList(m_system);
    for (int i = 0; i < r_system.size();i++)
        list.append("<RTP> " + r_system[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::system2list(bool with_none) const
{
    QStringList list = QStringList(m_system2);
    for (int i = 0; i < r_system2.size();i++)
        list.append("<RTP> " + r_system2[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}

QStringList GameProject::titlelist(bool with_none) const
{
    QStringList list = QStringList(m_title);
    for (int i = 0; i < r_title.size();i++)
        list.append("<RTP> " + r_title[i]);
    if (with_none)
        list.prepend("<none>");
    list.sort(Qt::CaseInsensitive);
    return list;
}
