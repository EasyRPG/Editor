#include "gameproject.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>

GameProject::GameProject()
{
}

bool GameProject::Save()
{
    picojson::object j_project;
    j_project["GameTitle"] = picojson::value(m_gametitle.toStdString());
    j_project["TileSize"] = picojson::value((double)m_tilesize);
#define ARR(var,list,key) picojson::array var;for (int i = 0; i < list.size(); i++)var.push_back(picojson::value(list[i].toStdString().c_str()));j_project[key] = picojson::value(var);
    ARR(j_backdrop,m_backdrop,"Backdrop");
    ARR(j_battle,m_battle,"Battle");
    ARR(j_battle2,m_battle2,"Battle2");
    ARR(j_battlecharset,m_battlecharset,"BattleCharSet");
    ARR(j_battleweapon,m_battleweapon,"BattleWeapon");
    ARR(j_charset,m_charset,"CharSet");
    ARR(j_chipset,m_chipset,"ChipSet");
    ARR(j_faceset,m_faceset,"FaceSet");
    ARR(j_frame,m_frame,"Frame");
    ARR(j_gameover,m_gameover,"GameOver");
    ARR(j_monster,m_monster,"Monster");
    ARR(j_movie,m_movie,"Movie");
    ARR(j_music,m_music,"Music");
    ARR(j_background,m_background,"Background");
    ARR(j_picture,m_picture,"Picture");
    ARR(j_sound,m_sound,"Sound");
    ARR(j_system,m_system,"System");
    ARR(j_system2,m_system2,"System2");
    ARR(j_title,m_title,"Title");
#undef ARR
    QString f_text = QString::fromStdString(picojson::value(j_project).serialize());
    if (f_text.isEmpty())
        return false;
    QFile m_file(m_path+"project.erp");
    if (!m_file.open(QFile::WriteOnly | QFile::Text))
        return false;
    QTextStream out(&m_file);
    out << f_text;
    m_file.flush();
    m_file.close();
    return true;
}

bool GameProject::Load()
{
    QFile m_file(m_path+"project.erp");
    if (!m_file.open(QFile::ReadOnly | QFile::Text))
        return false;
    QTextStream in(&m_file);
    QString f_text;
    in >> f_text;
    picojson::value j_project;
    const char *json = f_text.toStdString().c_str();
    QString err = QString::fromStdString(picojson::parse(j_project,json,json+strlen(json)));
    if (!err.isEmpty())
        return false;
    m_gametitle = j_project.get("GameTitle").get<std::string>().c_str();
    m_tilesize = (int)j_project.get("TileSize").get<double>();
#define ARR(var,list,key)picojson::array var = j_project.get(key).get<picojson::array>(); for (picojson::array::iterator iter = var.begin(); iter != var.end(); ++iter) list.push_back((*iter).get<std::string>().c_str());
    ARR(j_backdrop,m_backdrop,"Backdrop");
    ARR(j_battle,m_battle,"Battle");
    ARR(j_battle2,m_battle2,"Battle2");
    ARR(j_battlecharset,m_battlecharset,"BattleCharSet");
    ARR(j_battleweapon,m_battleweapon,"BattleWeapon");
    ARR(j_charset,m_charset,"CharSet");
    ARR(j_chipset,m_chipset,"ChipSet");
    ARR(j_faceset,m_faceset,"FaceSet");
    ARR(j_frame,m_frame,"Frame");
    ARR(j_gameover,m_gameover,"GameOver");
    ARR(j_monster,m_monster,"Monster");
    ARR(j_movie,m_movie,"Movie");
    ARR(j_music,m_music,"Music");
    ARR(j_background,m_background,"Background");
    ARR(j_picture,m_picture,"Picture");
    ARR(j_sound,m_sound,"Sound");
    ARR(j_system,m_system,"System");
    ARR(j_system2,m_system2,"System2");
    ARR(j_title,m_title,"Title");
#undef ARR
    m_file.close();
    return true;
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
