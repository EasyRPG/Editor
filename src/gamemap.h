#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QString>

class GameMap
{
public:
    enum ScrollType
    {
        NO_SCROLL,
        VERTICAL,
        HORIZONTAL,
        BOTH
    };
    enum AttType
    {
        SAME_AS_PARENT,
        ENTRUST_TO_EVENT,
        FIXED
    };

    GameMap(QString n_name = QString(),
            int w = 20,
            int h = 15,
            QString n_tileset = QString(),
            ScrollType n_scrollType = NO_SCROLL,
            bool n_hasBackground = false,
            QString background = QString(),
            bool n_background_h_loop = false,
            bool n_background_v_loop = false,
            bool n_background_h_autoscroll = false,
            bool n_background_v_autoscroll = false,
            int n_background_h_autoscroll_speed = 0,
            int n_background_v_autoscroll_speed = 0,
            AttType n_bgmType = SAME_AS_PARENT,
            QString n_bgm_name = QString(),
            AttType n_backdropType = SAME_AS_PARENT,
            QString n_backdrop_name = QString(),
            AttType n_teleport_type = SAME_AS_PARENT,
            bool n_teleport_allow = true,
            AttType n_escape_type = SAME_AS_PARENT,
            bool n_escape_allow = true,
            AttType n_save_type = SAME_AS_PARENT,
            bool n_save_allow = true,
            int n_encounter_steps = 25);

    int width();
    int height();
    void setWidth(int w);
    void setHeight(int h);
    void setSize(int w, int h);

    void shift(int direction, int amount);

    QString name() const;
    void setName(const QString &name);

    QString tileset() const;
    void setTileset(const QString &tileset);

    ScrollType scroll() const;
    void setScroll(const ScrollType &scroll);

    bool hasBackground() const;
    void sethasBackground(bool hasBackground);

    bool background_v_loop() const;
    void setBackground_v_loop(bool background_v_loop);

    bool background_h_loop() const;
    void setBackground_h_loop(bool background_h_loop);

    bool background_v_autoscroll() const;
    void setBackground_v_autoscroll(bool background_v_autoscroll);

    bool background_h_autoscroll() const;
    void setBackground_h_autoscroll(bool background_h_autoscroll);

    int background_v_autoscroll_speed() const;
    void setBackground_v_autoscroll_speed(int background_v_autoscroll_speed);

    int background_h_autoscroll_speed() const;
    void setBackground_h_autoscroll_speed(int background_h_autoscroll_speed);

    AttType bgmtype() const;
    void setBgmtype(const AttType &bgmtype);

    QString bgmname() const;
    void setBgmname(const QString &bgmname);

    AttType backdroptype() const;
    void setBackdroptype(const AttType &backdroptype);

    QString backdropname() const;
    void setBackdropname(const QString &backdropname);

    AttType teleporttype() const;
    void setTeleporttype(const AttType &teleporttype);

    bool teleportallow() const;
    void setTeleportallow(bool teleportallow);

    AttType escapetype() const;
    void setEscapetype(const AttType &escapetype);

    bool escapeallow() const;
    void setEscapeallow(bool escapeallow);

    AttType savetype() const;
    void setSavetype(const AttType &savetype);

    bool saveallow() const;
    void setSaveallow(bool saveallow);

    int encountersteps() const;
    void setEncountersteps(int encountersteps);

private:
    QString m_name;
    int m_w;
    int m_h;
    QString m_tileset;
    ScrollType m_scroll;
    bool m_has_background;
    QString m_background;
    bool m_background_v_loop;
    bool m_background_h_loop;
    bool m_background_v_autoscroll;
    bool m_background_h_autoscroll;
    int m_background_v_autoscroll_speed;
    int m_background_h_autoscroll_speed;
    AttType m_bgmtype;
    QString m_bgmname;
    AttType m_backdroptype;
    QString m_backdropname;
    AttType m_teleporttype;
    bool m_teleportallow;
    AttType m_escapetype;
    bool m_escapeallow;
    AttType m_savetype;
    bool m_saveallow;
    int** m_lower_layer;
    int** m_upper_layer;
    int m_encountersteps;
    //int m_save_time ??? what'sthis?
    //https://github.com/MarianoGnu/Editor/blob/master/src/model_map.vala#L229
};

#endif // GAMEMAP_H
