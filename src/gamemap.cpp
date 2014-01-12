#include "gamemap.h"
#include "EasyRPGCore.h"

GameMap::GameMap(QString n_name,
                 int w,
                 int h,
                 QString n_tileset,
                 ScrollType n_scrollType,
                 bool n_hasBackground,
                 QString background,
                 bool n_background_h_loop,
                 bool n_background_v_loop,
                 bool n_background_h_autoscroll,
                 bool n_background_v_autoscroll,
                 int n_background_h_autoscroll_speed,
                 int n_background_v_autoscroll_speed,
                 AttType n_bgmType,
                 QString n_bgm_name,
                 AttType n_backdropType,
                 QString n_backdrop_name,
                 AttType n_teleport_type,
                 bool n_teleport_allow,
                 AttType n_escape_type,
                 bool n_escape_allow,
                 AttType n_save_type,
                 bool n_save_allow,
                 int n_encounter_steps):
    m_name(n_name),
    m_tileset(n_tileset),
    m_w(w),
    m_h(h),
    m_scroll(n_scrollType),
    m_has_background(n_hasBackground),
    m_background(background),
    m_background_h_loop(n_background_h_loop),
    m_background_v_loop(n_background_v_loop),
    m_background_h_autoscroll(n_background_h_autoscroll),
    m_background_v_autoscroll(n_background_v_autoscroll),
    m_background_h_autoscroll_speed(n_background_h_autoscroll_speed),
    m_background_v_autoscroll_speed(n_background_v_autoscroll_speed),
    m_bgmtype(n_bgmType),
    m_bgmname(n_bgm_name),
    m_backdroptype(n_backdropType),
    m_backdropname(n_backdrop_name),
    m_teleporttype(n_teleport_type),
    m_teleportallow(n_teleport_allow),
    m_escapetype(n_escape_type),
    m_escapeallow(n_escape_allow),
    m_savetype(n_save_type),
    m_saveallow(n_save_allow),
    m_encountersteps(n_encounter_steps)
{
    m_lower_layer = new int*[w];
    m_upper_layer = new int*[w];
    for (int i = 0; i < w; i++)
    {
        m_lower_layer[i] = new int[h];
        m_upper_layer[i] = new int[h];
    }
    for (int y = 0; y < height(); y++)
        for (int x = 0; x < width(); x++)
        {
            m_lower_layer[x][y] = 1;
            m_upper_layer[x][y] = 0;
        }
}

int GameMap::width()
{
    return m_w;
}

int GameMap::height()
{
    return m_h;
}

void GameMap::setWidth(int w)
{
    setSize(w, height());
}

void GameMap::setHeight(int h)
{
    setSize(width(), h);
}

void GameMap::setSize(int w, int h)
{
    if (w == width() && h == height())
        return;

    int** n_lower_layer = new int*[w];
    int** n_upper_layer = new int*[w];
    for (int i = 0; i < w; i++)
    {
        n_lower_layer[i] = new int[h];
        n_upper_layer[i] = new int[h];
    }

    for (int y = 0; y < height(); y++)
        for (int x = 0; x < width(); x++)
        {
            m_lower_layer[x][y] = 1;
            m_upper_layer[x][y] = 0;
        }

    //Get minimum size to copy map contents
    int smaller_width = (w < width()) ? w : width();
    int smaller_height = (h < height()) ? h : height();

    //Copy old map data
    for (int y = 0; y < smaller_height; y++)
        for (int x = 0; x < smaller_width; x++)
        {
            n_lower_layer[x][y] = m_lower_layer[x][y];
            n_upper_layer[x][y] = m_upper_layer[x][y];
        }
    m_w = w;
    m_h = h;
    m_lower_layer = n_lower_layer;
    m_upper_layer = n_upper_layer;
}

void GameMap::shift(int direction, int amount)
{
    switch (direction)
    {
        case RIGHT:
            for (int y = 0; y < height(); y++)
                for (int x = width()-1; x >= 0; x--) {
                    if (x - amount >= 0) {
                            m_lower_layer[y][x] = m_lower_layer[y][x-amount];
                            m_upper_layer[y][x] = m_upper_layer[y][x-amount];
                    } else {
                            m_lower_layer[y][x] = 0;
                            m_upper_layer[y][x] = 0;
                    }
                }
            break;
        case LEFT:
            for (int y = 0; y < height(); y++) {
                for (int x = 0; x < width(); x++) {
                    if (x + amount < width()) {
                            m_lower_layer[y][x] = m_lower_layer[y][x+amount];
                            m_upper_layer[y][x] = m_upper_layer[y][x+amount];
                    } else {
                            m_lower_layer[y][x] = 0;
                            m_upper_layer[y][x] = 0;
                    }
                }
            }
            break;
        case UP:
            for (int y = 0; y < height(); y++) {
                for (int x = 0; x < width(); x++) {
                    if (y + amount < height()) {
                            m_lower_layer[y][x] = m_lower_layer[y+amount][x];
                            m_upper_layer[y][x] = m_upper_layer[y+amount][x];
                    } else {
                            m_lower_layer[y][x] = 0;
                            m_upper_layer[y][x] = 0;
                    }
                }
            }
            break;
        case DOWN:
            for (int y = height()-1; y >= 0; y--) {
                for (int x = 0; x < width(); x++) {
                    if (y - amount >= 0) {
                            m_lower_layer[y][x] = m_lower_layer[y-amount][x];
                            m_upper_layer[y][x] = m_upper_layer[y-amount][x];
                    } else {
                            m_lower_layer[y][x] = 0;
                            m_upper_layer[y][x] = 0;
                    }
                }
            }
            break;
        default:
            break;
    }
}

QString GameMap::name() const
{
    return m_name;
}

void GameMap::setName(const QString &name)
{
    m_name = name;
}
QString GameMap::tileset() const
{
    return m_tileset;
}

void GameMap::setTileset(const QString &tileset)
{
    m_tileset = tileset;
}
GameMap::ScrollType GameMap::scroll() const
{
    return m_scroll;
}

void GameMap::setScroll(const ScrollType &scroll)
{
    m_scroll = scroll;
}
bool GameMap::hasBackground() const
{
    return m_has_background;
}

void GameMap::sethasBackground(bool hasBackground)
{
    m_has_background = hasBackground;
}
bool GameMap::background_v_loop() const
{
    return m_background_v_loop;
}

void GameMap::setBackground_v_loop(bool background_v_loop)
{
    m_background_v_loop = background_v_loop;
}
bool GameMap::background_h_loop() const
{
    return m_background_h_loop;
}

void GameMap::setBackground_h_loop(bool background_h_loop)
{
    m_background_h_loop = background_h_loop;
}
bool GameMap::background_v_autoscroll() const
{
    return m_background_v_autoscroll;
}

void GameMap::setBackground_v_autoscroll(bool background_v_autoscroll)
{
    m_background_v_autoscroll = background_v_autoscroll;
}
bool GameMap::background_h_autoscroll() const
{
    return m_background_h_autoscroll;
}

void GameMap::setBackground_h_autoscroll(bool background_h_autoscroll)
{
    m_background_h_autoscroll = background_h_autoscroll;
}
int GameMap::background_v_autoscroll_speed() const
{
    return m_background_v_autoscroll_speed;
}

void GameMap::setBackground_v_autoscroll_speed(int background_v_autoscroll_speed)
{
    m_background_v_autoscroll_speed = background_v_autoscroll_speed;
}
int GameMap::background_h_autoscroll_speed() const
{
    return m_background_h_autoscroll_speed;
}

void GameMap::setBackground_h_autoscroll_speed(int background_h_autoscroll_speed)
{
    m_background_h_autoscroll_speed = background_h_autoscroll_speed;
}
GameMap::AttType GameMap::bgmtype() const
{
    return m_bgmtype;
}

void GameMap::setBgmtype(const AttType &bgmtype)
{
    m_bgmtype = bgmtype;
}
QString GameMap::bgmname() const
{
    return m_bgmname;
}

void GameMap::setBgmname(const QString &bgmname)
{
    m_bgmname = bgmname;
}
GameMap::AttType GameMap::backdroptype() const
{
    return m_backdroptype;
}

void GameMap::setBackdroptype(const AttType &backdroptype)
{
    m_backdroptype = backdroptype;
}
QString GameMap::backdropname() const
{
    return m_backdropname;
}

void GameMap::setBackdropname(const QString &backdropname)
{
    m_backdropname = backdropname;
}
GameMap::AttType GameMap::teleporttype() const
{
    return m_teleporttype;
}

void GameMap::setTeleporttype(const AttType &teleporttype)
{
    m_teleporttype = teleporttype;
}
bool GameMap::teleportallow() const
{
    return m_teleportallow;
}

void GameMap::setTeleportallow(bool teleportallow)
{
    m_teleportallow = teleportallow;
}
GameMap::AttType GameMap::escapetype() const
{
    return m_escapetype;
}

void GameMap::setEscapetype(const AttType &escapetype)
{
    m_escapetype = escapetype;
}
bool GameMap::escapeallow() const
{
    return m_escapeallow;
}

void GameMap::setEscapeallow(bool escapeallow)
{
    m_escapeallow = escapeallow;
}
GameMap::AttType GameMap::savetype() const
{
    return m_savetype;
}

void GameMap::setSavetype(const AttType &savetype)
{
    m_savetype = savetype;
}
bool GameMap::saveallow() const
{
    return m_saveallow;
}

void GameMap::setSaveallow(bool saveallow)
{
    m_saveallow = saveallow;
}
int GameMap::encountersteps() const
{
    return m_encountersteps;
}

void GameMap::setEncountersteps(int encountersteps)
{
    m_encountersteps = encountersteps;
}
