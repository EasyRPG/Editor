#include "gameproject.h"
#include <QString>

GameProject::GameProject()
{
    m_backdrop = QStringList();

}

QStringList GameProject::backdroplist(bool with_none) const
{
    QStringList list = QStringList(m_backdrop);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::battlelist(bool with_none) const
{
    QStringList list = QStringList(m_battle);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::battle2list(bool with_none) const
{
    QStringList list = QStringList(m_battle2);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::battlecharsetlist(bool with_none)
{
    QStringList list = QStringList(m_battlecharset);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::battleweaponlist(bool with_none) const
{
    QStringList list = QStringList(m_battleweapon);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::charsetlist(bool with_none) const
{
    QStringList list = QStringList(m_charset);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::chipsetlist(bool with_none) const
{
    QStringList list = QStringList(m_chipset);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::facesetlist(bool with_none) const
{
    QStringList list = QStringList( m_faceset);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::framelist(bool with_none) const
{
    QStringList list = QStringList(m_frame);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::gameoverlist(bool with_none) const
{
    QStringList list = QStringList(m_gameover);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::monsterlist(bool with_none) const
{
    QStringList list = QStringList(m_monster);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::movielist(bool with_none) const
{
    QStringList list = QStringList(m_movie);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::musiclist(bool with_none) const
{
    QStringList list = QStringList(m_music);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::backgroundlist(bool with_none) const
{
    QStringList list = QStringList(m_background);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::picturelist(bool with_none) const
{
    QStringList list = QStringList(m_picture);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::soundlist(bool with_none) const
{
    QStringList list = QStringList(m_sound);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::systemlist(bool with_none) const
{
    QStringList list = QStringList(m_system);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::system2list(bool with_none) const
{
    QStringList list = QStringList(m_system2);
    if (with_none)
        list.prepend("<none>");
    return list;
}

QStringList GameProject::titlelist(bool with_none) const
{
    QStringList list = QStringList(m_title);
    if (with_none)
        list.prepend("<none>");
    return list;
}
