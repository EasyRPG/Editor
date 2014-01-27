#include "EasyRPGCore.h"
#include <QApplication>
#include <QPainter>

//define static members
QListWidget* EasyRPGCore::m_debugChipset = 0;
GameProject* EasyRPGCore::m_currentProject = 0;
GameMap* EasyRPGCore::m_currentMap = 0;
int EasyRPGCore::m_tileSize = 48;
QString EasyRPGCore::m_currentGameTitle = QString();
QString EasyRPGCore::m_currentProjectPath = QString();
EasyRPGCore::Layer EasyRPGCore::m_currentLayer = EasyRPGCore::LOWER;
EasyRPGCore::Tool EasyRPGCore::m_currentTool = EasyRPGCore::PENCIL;
EasyRPGCore::Zoom EasyRPGCore::m_currentZoom = EasyRPGCore::Z_11;
QMap<int,QPixmap> EasyRPGCore::m_currentChipset = QMap<int,QPixmap>();
QMap<int,short> EasyRPGCore::m_dictionary = QMap<int,short>();


GameProject *EasyRPGCore::currentProject()
{
    return m_currentProject;
}

void EasyRPGCore::Init()
{
    m_dictionary[UPLEFT]                            = 1;
    m_dictionary[UPRIGHT]                           = 2;
    m_dictionary[UPLEFT+UPRIGHT]                    = 3;
    m_dictionary[DOWNRIGHT]                         = 4;
    m_dictionary[UPLEFT+DOWNRIGHT]                  = 5;
    m_dictionary[UPRIGHT+DOWNRIGHT]                 = 6;
    m_dictionary[UPLEFT+UPRIGHT+DOWNRIGHT]          = 7;
    m_dictionary[DOWNLEFT]                          = 8;
    m_dictionary[DOWNLEFT+UPLEFT]                   = 9;
    m_dictionary[DOWNLEFT+UPRIGHT]                  = 10;
    m_dictionary[DOWNLEFT+UPLEFT+UPRIGHT]           = 11;
    m_dictionary[DOWNLEFT+DOWNRIGHT]                = 12;
    m_dictionary[DOWNLEFT+DOWNRIGHT+UPLEFT]         = 13;
    m_dictionary[DOWNLEFT+DOWNRIGHT+UPRIGHT]        = 14;
    m_dictionary[DOWNLEFT+DOWNRIGHT+UPLEFT+UPRIGHT] = 15;
    m_dictionary[LEFT]                              = 16;
    m_dictionary[LEFT+UPRIGHT]                      = 17;
    m_dictionary[LEFT+DOWNRIGHT]                    = 18;
    m_dictionary[LEFT+UPRIGHT+DOWNRIGHT]            = 19;
    m_dictionary[UP]                                = 20;
    m_dictionary[UP+DOWNRIGHT]                      = 21;
    m_dictionary[UP+DOWNLEFT]                       = 22;
    m_dictionary[UP+DOWNRIGHT+DOWNLEFT]             = 23;
    m_dictionary[RIGHT]                             = 24;
    m_dictionary[RIGHT+DOWNLEFT]                    = 25;
    m_dictionary[RIGHT+UPLEFT]                      = 26;
    m_dictionary[RIGHT+UPLEFT+DOWNLEFT]             = 27;
    m_dictionary[DOWN]                              = 28;
    m_dictionary[DOWN+UPLEFT]                       = 29;
    m_dictionary[DOWN+UPRIGHT]                      = 30;
    m_dictionary[DOWN+UPLEFT+UPRIGHT]               = 31;
    m_dictionary[LEFT+RIGHT]                        = 32;
    m_dictionary[UP+DOWN]                           = 33;
    m_dictionary[UP+LEFT]                           = 34;
    m_dictionary[UP+LEFT+DOWNRIGHT]                 = 35;
    m_dictionary[UP+RIGHT]                          = 36;
    m_dictionary[UP+RIGHT+DOWNLEFT]                 = 37;
    m_dictionary[DOWN+RIGHT]                        = 38;
    m_dictionary[DOWN+RIGHT+UPLEFT]                 = 39;
    m_dictionary[DOWN+LEFT]                         = 40;
    m_dictionary[DOWN+LEFT+UPRIGHT]                 = 41;
    m_dictionary[UP+LEFT+RIGHT]                     = 42;
    m_dictionary[UP+LEFT+DOWN]                      = 43;
    m_dictionary[LEFT+RIGHT+DOWN]                   = 44;
    m_dictionary[UP+RIGHT+DOWN]                     = 45;
    m_dictionary[UP+DOWN+LEFT+RIGHT]                = 46;
}

void EasyRPGCore::setCurrentProject(GameProject *current_project)
{
    if (m_currentProject)
        delete m_currentProject;
    m_currentProject = current_project;
}

void EasyRPGCore::LoadChipset(QString n_chipset)
{
    QPixmap *o_chipset = new QPixmap(n_chipset);
    if (o_chipset->isNull())
    {
        delete o_chipset;
        return;
    }

    int r_tileSize = o_chipset->width()/30;
    int r_tileHalf = r_tileSize/2;

    /** BindWaterTiles **/
    m_currentChipset = QMap<int,QPixmap>();
    if (m_debugChipset)
        delete m_debugChipset;
    m_debugChipset = new QListWidget();
    m_debugChipset->setIconSize(QSize(tileSize(),tileSize()));
    m_debugChipset->setWindowTitle("Debug: ChipSet cache");
    m_debugChipset->setWindowIcon(QIcon(QPixmap(":/icons/share/old_palette.png")));
    /**
     * TileIDs:
     * 0- WaterA
     * 1- WaterB
     * 2- DeepWater
     * 3- Ground
     **/
    //Go throught all posible combinations
    for (int terrain_id = 0; terrain_id < 4; terrain_id++)
    for (int tile_u = 0; tile_u < 4; tile_u++)
    for (int tile_d = 0; tile_d < 4; tile_d++)
    for (int tile_l = 0; tile_l < 4; tile_l++)
    for (int tile_r = 0; tile_r < 4; tile_r++)
    for (int tile_ul = 0; tile_ul < 4; tile_ul++)
    for (int tile_ur = 0; tile_ur < 4; tile_ur++)
    for (int tile_dl = 0; tile_dl < 4; tile_dl++)
    for (int tile_dr = 0; tile_dr < 4; tile_dr++)
    {
        int _code, _scode;
        if (terrain_id == 3)
            // Once main foreach reaches ground, we have finished
             break;
        int u=0,d=0,l=0,r=0,ul=0,ur=0,dl=0,dr=0,sul=0,sur=0,sdl=0,sdr=0;

        if (!isWater(tile_u))
            u = UP;
        if (!isWater(tile_d))
            d = DOWN;
        if (!isWater(tile_l))
            l = LEFT;
        if (!isWater(tile_r))
            r = RIGHT;
        _code = u+d+l+r;
        // DeepWater Special Corners
        if (isDWater(terrain_id))
        {
            if (isABWater(tile_u) && isABWater (tile_l) && isABWater (tile_ul))
                sul = UPLEFT;
            if (isABWater(tile_u) && isABWater (tile_r) && isABWater (tile_ur))
                sur = UPRIGHT;
            if (isABWater(tile_d) && isABWater (tile_l) && isABWater (tile_dl))
                sdl = DOWNLEFT;
            if (isABWater(tile_d) && isABWater (tile_r) && isABWater (tile_dr))
                sdr = DOWNRIGHT;
        }
        else
        {
            if (isDWater (tile_u) && isDWater (tile_l) && isWater(tile_ul))
                sul = UPLEFT;
            if (isDWater (tile_u) && isDWater (tile_r) && isWater(tile_ur))
                sur = UPRIGHT;
            if (isDWater (tile_d) && isDWater (tile_l) && isWater(tile_dl))
                sdl = DOWNLEFT;
            if (isDWater (tile_d) && isDWater (tile_r) && isWater(tile_dr))
                sdr = DOWNRIGHT;
        }
        _scode = sul+sur+sdl+sdr;
        if ((u+l) == 0 && tile_ul == 3)
            ul = UPLEFT;
        if ((u+r) == 0 && tile_ur == 3)
            ur = UPRIGHT;
        if ((d+l) == 0 && tile_dl == 3)
            dl = DOWNLEFT;
        if ((d+r) == 0 && tile_dr == 3)
            dr = DOWNRIGHT;
        _code += ul+ur+dl+dr;
        short id = translate(terrain_id,_code,_scode);
        if (!m_currentChipset[id].isNull()) //item exist?
            continue;
        // Water B uses second block of 3x4 tiles for borders
        // Water A and Deep Water uses first block
        int border_xoffset = (terrain_id == 1) ? 3*r_tileSize : 0;
        /*
         * Get base
         */
        QPixmap p_tile(tileSize(), tileSize());
        QPainter p(&p_tile);
        if (isABWater (terrain_id))
            p.drawPixmap(0,0,tileSize(),tileSize(),o_chipset->copy(0, 4*r_tileSize,r_tileSize,r_tileSize));
        else
            p.drawPixmap(0,0,tileSize(),tileSize(),o_chipset->copy(0, 7*r_tileSize,r_tileSize,r_tileSize));
        // Draw UpperLeft corner
        int dest_x = 0, dest_y = 0;
#define blit(x,y) p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(x, y,r_tileHalf,r_tileHalf))
        if (u+l == 5)
            blit(border_xoffset, 0);
        else if (u)
            blit(border_xoffset, 2*r_tileSize);
        else if (l)
            blit(border_xoffset, r_tileSize);
        else if (ul)
            blit(border_xoffset, 3*r_tileSize);
        else if (sul)
        {
            if (isABWater (terrain_id))
                blit(0, 5*r_tileSize);
            else
                blit(0, 6*r_tileSize);
        }
        //Draw UpperRight corner
        dest_x = tileSize()/2;
        if (u+r == 9)
            blit(border_xoffset+r_tileHalf, 0);
        else if (u)
            blit(border_xoffset+r_tileHalf, 2*r_tileSize);
        else if (r)
            blit(border_xoffset+r_tileHalf, r_tileSize);
        else if (ur)
            blit(border_xoffset+r_tileHalf, 3*r_tileSize);
        else if (sur)
        {
            if (isABWater (terrain_id))
                blit(r_tileHalf, 5*r_tileSize);
            else
                blit(r_tileHalf, 6*r_tileSize);
        }
        //Draw LowerRight corner
        dest_y = tileSize()/2;
        if (d+r == 10)
            blit(border_xoffset+r_tileHalf, 0.5*r_tileSize);
        else if (d)
            blit(border_xoffset+r_tileHalf, 2.5*r_tileSize);
        else if (r)
            blit(border_xoffset+r_tileHalf, 1.5*r_tileSize);
        else if (dr)
            blit(border_xoffset+r_tileHalf, 3.5*r_tileSize);
        else if (sdr)
        {
            if (isABWater (terrain_id))
                blit(tileSize()/2, 5.5*r_tileSize);
            else
                blit(tileSize()/2, 6.5*r_tileSize);
        }
        //Draw LowerLeft corner
        dest_x = 0;
        if (d+l == 6)
            blit(border_xoffset, 0.5*r_tileSize);
        else if (d)
            blit(border_xoffset, 2.5*r_tileSize);
        else if (l)
            blit(border_xoffset, 1.5*r_tileSize);
        else if (dl)
            blit(border_xoffset, 3.5*r_tileSize);
        else if (sdl)
        {
            if (isABWater (terrain_id))
                blit(0, 5.5*r_tileSize);
            else
                blit(0, 6.5*r_tileSize);
        }
#undef blit
        m_currentChipset[id] = p_tile;
        m_debugChipset->addItem(QString::number(id));
        m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[id]));
    }

    /** Register AnimationTiles **/
    QPixmap a_tile(tileSize(), tileSize());
    QPainter a(&a_tile);
    a.drawPixmap(0,0,tileSize(),tileSize(),o_chipset->copy(3*r_tileSize,4*r_tileSize,r_tileSize,r_tileSize));
    m_currentChipset[3000] = a_tile;
    m_debugChipset->addItem("3000");
    m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[3000]));
    a.drawPixmap(0,0,tileSize(),tileSize(),o_chipset->copy(4*r_tileSize,4*r_tileSize,r_tileSize,r_tileSize));
    m_currentChipset[3050] = a_tile;
    m_debugChipset->addItem("3050");
    m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[3050]));
    a.drawPixmap(0,0,tileSize(),tileSize(),o_chipset->copy(5*r_tileSize,4*r_tileSize,r_tileSize,r_tileSize));
    m_currentChipset[3100] = a_tile;
    m_debugChipset->addItem("3100");
    m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[3100]));

    /** BindGroundTiles **/
    // Each tileset contains 5 columns with a size of 6x16 tiles
    int tileset_col = 0;

    // Each tileset column contains 4 blocks with a size of 3x4 tiles
    // Anyway we should skip water colums because they are already stored
    int block_col = 0;
    int block_row = 2;

    int terrain_id = 6;

    while (tileset_col < 2)
    {
        int orig_x = (2 * tileset_col + block_col) *3*r_tileSize;
        int orig_y = block_row *4*r_tileSize;
        QPixmap p_block = o_chipset->copy(orig_x, orig_y, 3*r_tileSize, 4*r_tileSize);

        /**
         * Generate binded cache and store them on hash table
         */

        //Simulate all posible combinations

        std::vector<bool> is_binded;
        is_binded.push_back(true);
        is_binded.push_back(false);
#define forx(_type,_iter,_coll) for (_type::iterator _iter = _coll.begin(); _iter != _coll.end(); _iter++)

        forx(std::vector<bool>, bu, is_binded)
        forx(std::vector<bool>, bd, is_binded)
        forx(std::vector<bool>, bl, is_binded)
        forx(std::vector<bool>, br, is_binded)
        forx(std::vector<bool>, bul, is_binded)
        forx(std::vector<bool>, bur, is_binded)
        forx(std::vector<bool>, bdl, is_binded)
        forx(std::vector<bool>, bdr, is_binded)
#undef forx
        {
            int u = 0, d = 0, l = 0, r = 0;
            if (*bu) u = UP;
            if (*bd) d = DOWN;
            if (*bl) l = LEFT;
            if (*br) r = RIGHT;
            int ul = 0, ur = 0, dl = 0, dr = 0;
            if (u + l == 0 && *bul)
                ul = UPLEFT;
            if (u + r == 0 && *bur)
                ur = UPRIGHT;
            if (d + l == 0 && *bdl)
                dl = DOWNLEFT;
            if (d + r == 0 && *bdr)
                dr = DOWNRIGHT;

            short id = translate (terrain_id, u+d+l+r+ul+ur+dl+dr);
            if (!m_currentChipset[id].isNull()) //item exist?
                continue;

            /*
             * Get base
             */
            QPixmap p_tile(tileSize(), tileSize());
            QPainter p(&p_tile);

            /*
             * Draw upper_left corner
             */
            int dest_x = 0;
            int dest_y = 0;
#define blit(x,y) p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(x, y,r_tileHalf,r_tileHalf))
            if (u+l == 5)
                blit(0,r_tileSize);
            else if (u)
                blit(r_tileSize, r_tileSize);
            else if (l)
                blit(0, r_tileSize*2);
            else if (ul)
                blit(r_tileSize*2, 0);
            else //0
            {
                if (d+r == 10)
                    blit(r_tileSize*2,r_tileSize*3);
                else if (r)
                    blit(r_tileSize*2,r_tileSize*2);
                else if (d)
                    blit(r_tileSize*1,r_tileSize*3);
                else
                    blit(r_tileSize*1,r_tileSize*2);
            }
            /*
             * Draw upper_right corner
             */
            dest_x = tileSize()/2;
            if (u+r == 9)
                blit(r_tileSize*2.5, r_tileSize);
            else if (u)
                blit(r_tileSize*1.5, r_tileSize);
            else if (r)
                blit(r_tileSize*2.5, r_tileSize*2);
            else if (ur)
                blit(r_tileSize*2.5, 0);
            else //0
            {
                if (d+l == 6)
                    blit(r_tileSize*0.5,r_tileSize*3);
                else if (l)
                    blit(r_tileSize*0.5,r_tileSize*2);
                else if (d)
                    blit(r_tileSize*1.5,r_tileSize*3);
                else
                    blit(r_tileSize*1.5,r_tileSize*2);
            }
            /*
             * Draw down_left corner
             */
            dest_x = 0;
            dest_y = tileSize()/2;
            if (d+l == 6)
                blit(0, r_tileSize*3.5);
            else if (d)
                blit(r_tileSize, r_tileSize*3.5);
            else if (l)
                blit(0, r_tileSize*2.5);
            else if (dl)
                blit(r_tileSize*2, r_tileHalf);
            else
            {
                if (u+r == 9)
                    blit(r_tileSize*2,r_tileSize*1.5);
                else if (r)
                    blit(r_tileSize*2,r_tileSize*2.5);
                else if (u)
                    blit(r_tileSize,r_tileSize*1.5);
                else
                    blit(r_tileSize,r_tileSize*2.5);
            }
            /*
             * Draw down_right corner
             */
            dest_x = tileSize()/2;
            if (d+r == 10)
                blit(r_tileSize*2.5, r_tileSize*3.5);
            else if (d)
                blit(r_tileSize*1.5, r_tileSize*3.5);
            else if (r)
                blit(r_tileSize*2.5, r_tileSize*2.5);
            else if (dr)
                blit(r_tileSize*2.5, r_tileHalf);
            else //0
            {
                if (u+l == 5)
                    blit(r_tileHalf,r_tileSize*1.5);
                else if (l)
                    blit(r_tileHalf,r_tileSize*2.5);
                else if (u)
                    blit(r_tileSize*1.5,r_tileSize*1.5);
                else
                    blit(r_tileSize*1.5,r_tileSize*2.5);
            }
#undef blit
            /*
             * Register tile
             */
            m_currentChipset[id] = p_tile;
            m_debugChipset->addItem(QString::number((int)id));
            m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[id]));
        }

        terrain_id++;
        block_col++;

        // Go to the next block
        if (block_col > 1) {
                block_col = 0;
                block_row++;
        }

        // Go to the next column
        if (block_row > 3) {
                block_row = 0;
                tileset_col++;
        }
    }
    int tile_row = 0;
    /** Register E and F blocks **/
    while (tileset_col < 5 )
    {
        for (int col = 0; col < 6; col++)
        {
            int orig_x = tileset_col*6*r_tileSize+col*r_tileSize;
            int orig_y = tile_row*r_tileSize;
            a.drawPixmap(0,0,tileSize(),tileSize(),o_chipset->copy(orig_x,orig_y,r_tileSize,r_tileSize));
            m_currentChipset[translate(terrain_id)] = a_tile;
            m_debugChipset->addItem(QString::number(translate(terrain_id)));
            m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[translate(terrain_id)]));
            terrain_id++;
        }

        tile_row++;
        if (tile_row == 16)
        {
            tile_row = 0;
            tileset_col++;
        }
    }
    int count = m_debugChipset->count();
    for(int i = 0; i < count; i++)
    {
      QListWidgetItem *item = m_debugChipset->item(i);
      item->setSizeHint(QSize(item->sizeHint().width(), tileSize() + 10));
    }
}
int EasyRPGCore::tileSize()
{
    return m_tileSize;
}

void EasyRPGCore::setTileSize(int tile_size)
{
    m_tileSize = tile_size;
}
QString EasyRPGCore::currentProjectPath()
{
    return m_currentProjectPath;
}

void EasyRPGCore::setCurrentProjectPath(const QString &current_project_path)
{
    m_currentProjectPath = current_project_path;
}
EasyRPGCore::Layer EasyRPGCore::currentLayer()
{
    return m_currentLayer;
}

void EasyRPGCore::setCurrentLayer(const Layer &current_layer)
{
    m_currentLayer = current_layer;
}
EasyRPGCore::Tool EasyRPGCore::currentTool()
{
    return m_currentTool;
}

void EasyRPGCore::setCurrentTool(const Tool &current_tool)
{
    m_currentTool = current_tool;
}
EasyRPGCore::Zoom EasyRPGCore::currentZoom()
{
    return m_currentZoom;
}

void EasyRPGCore::setCurrentZoom(const Zoom &current_zoom)
{
    m_currentZoom = current_zoom;
}

QString EasyRPGCore::pathBackdrop(QString fileName) {return pathBackdrop()+fileName;}
QString EasyRPGCore::pathBattle(QString fileName) {return pathBattle()+fileName;}
QString EasyRPGCore::pathBattle2(QString fileName) {return pathBattle2()+fileName;}
QString EasyRPGCore::pathBattleCharSet(QString fileName) {return pathBattleCharSet()+fileName;}
QString EasyRPGCore::pathBattleWeapon(QString fileName) {return pathBattleWeapon()+fileName;}
QString EasyRPGCore::pathCharSet(QString fileName) {return pathCharSet()+fileName;}
QString EasyRPGCore::pathChipSet(QString fileName) {return pathChipSet()+fileName;}
QString EasyRPGCore::pathFaceSet(QString fileName) {return pathFaceSet()+fileName;}
QString EasyRPGCore::pathFrame(QString fileName) {return pathFrame()+fileName;}
QString EasyRPGCore::pathGameOver(QString fileName) {return pathGameOver()+fileName;}
QString EasyRPGCore::pathMonster(QString fileName) {return pathMonster()+fileName;}
QString EasyRPGCore::pathMovie(QString fileName) {return pathMovie()+fileName;}
QString EasyRPGCore::pathMusic(QString fileName) {return pathMusic()+fileName;}
QString EasyRPGCore::pathBackground(QString fileName) {return pathBackground()+fileName;}
QString EasyRPGCore::pathPicture(QString fileName) {return pathPicture()+fileName;}
QString EasyRPGCore::pathSound(QString fileName) {return pathSound()+fileName;}
QString EasyRPGCore::pathSystem(QString fileName) {return pathSystem()+fileName;}
QString EasyRPGCore::pathSystem2(QString fileName) {return pathSystem2()+fileName;}
QString EasyRPGCore::pathTitle(QString fileName) {return pathTitle()+fileName;}

QString EasyRPGCore::RtpPath()
{
    return (qApp->applicationDirPath() + "/RTP/");
}

QString EasyRPGCore::currentGameTitle()
{
    return m_currentGameTitle;
}

void EasyRPGCore::setCurrentGameTitle(const QString &currentGameTitle)
{
    m_currentGameTitle = currentGameTitle;
}

void EasyRPGCore::setCurrentMapSize(int w, int h)
{
    if (!m_currentMap)
        return;
    m_currentMap->setSize(w,h);
}

bool EasyRPGCore::isWater(int terrain_id)
{
    if (terrain_id >= 0 && terrain_id <= 2)
        return true;
    else
        return false;
}

bool EasyRPGCore::isABWater(int terrain_id)
{
    if (terrain_id == 0 || terrain_id == 1)
        return true;
    else
        return false;
}

bool EasyRPGCore::isDWater(int terrain_id)
{
    if (terrain_id == 2)
        return true;
    else
        return false;
}

bool EasyRPGCore::isAnimation(int terrain_id)
{
    if (terrain_id >= 3 && terrain_id <= 5)
        return true;
    else
        return false;
}

bool EasyRPGCore::isDblock(int terrain_id)
{
    if (terrain_id >= 6 && terrain_id <= 17)
        return true;
    else
        return false;
}

bool EasyRPGCore::isEblock(int terrain_id)
{
    if (terrain_id >= 18 && terrain_id <= 161)
        return true;
    else
        return false;
}

bool EasyRPGCore::isFblock(int terrain_id)
{
    if (terrain_id >= 162 && terrain_id <= 305)
        return true;
    else
        return false;
}

GameMap *EasyRPGCore::currentMap()
{
    return m_currentMap;
}

void EasyRPGCore::setCurrentMap(GameMap *currentMap)
{
    m_currentMap = currentMap;
}

QListWidget *EasyRPGCore::debugChipset()
{
    return m_debugChipset;
}

QPixmap EasyRPGCore::tile(short tile_id)
{
    return m_currentChipset.value(tile_id);
}

short EasyRPGCore::translate(int terrain_id, int _code, int _scode)
{
    if (terrain_id < 0)
        return 0xFFFF;
    if (isWater(terrain_id))
        return (terrain_id*1000+m_dictionary[_code]+m_dictionary[_scode]*50);
    if (isAnimation(terrain_id))
        return (3000+(terrain_id-3)*50);
    if (isDblock(terrain_id))
        return (4000+(terrain_id-6)*50+m_dictionary[_code]);
    if (isEblock(terrain_id))
        return (5000+terrain_id-18);
    if (isFblock(terrain_id))
        return (10000+terrain_id-161);
    return 0xFFFF;
}

int EasyRPGCore::translate(short tile_id)
{
    if (tile_id < 0)
        return -1;
    else if (tile_id < 3000)
        return tile_id/1000;
    else if (tile_id >= 3000 && tile_id <= 3150)
        return (tile_id-3000)/50;
    else if (tile_id >=4000 && tile_id < 4600 )
        return (tile_id-4000)/50;
    else if (tile_id >= 5000 && tile_id < 5162)
        return tile_id-5000+18;
    else if (tile_id >= 10000 && tile_id < 10144)
        return tile_id-10000+161;
    else
        return -1;
}

int EasyRPGCore::currentMapHeight()
{
    return (m_currentMap) ? m_currentMap->height() : 0;
}

void EasyRPGCore::setCurrentMapHeight(int currentMapHeight)
{
    setCurrentMapSize(m_currentMap->width(), currentMapHeight);
}

int EasyRPGCore::currentMapWidth()
{
    return (m_currentMap) ? m_currentMap->width() : 0;
}

void EasyRPGCore::setCurrentMapWidth(int currentMapWidth)
{
    setCurrentMapSize(currentMapWidth, m_currentMap->height());
}


QString EasyRPGCore::pathTitle() {return m_currentProjectPath+"Title/";}
QString EasyRPGCore::pathSystem2() {return m_currentProjectPath+"System2/";}
QString EasyRPGCore::pathSystem() {return m_currentProjectPath+"System/";}
QString EasyRPGCore::pathSound() {return m_currentProjectPath+"Sound/";}
QString EasyRPGCore::pathPicture() {return m_currentProjectPath+"Picture/";}
QString EasyRPGCore::pathBackground() {return m_currentProjectPath+"Background/";}
QString EasyRPGCore::pathMusic() {return m_currentProjectPath+"Music/";}
QString EasyRPGCore::pathMovie() {return m_currentProjectPath+"Movie/";}
QString EasyRPGCore::pathMonster() {return m_currentProjectPath+"Monster/";}
QString EasyRPGCore::pathGameOver() {return m_currentProjectPath+"GameOver/";}
QString EasyRPGCore::pathFrame() {return m_currentProjectPath+"Frame/";}
QString EasyRPGCore::pathFaceSet() {return m_currentProjectPath+"FaceSet/";}
QString EasyRPGCore::pathChipSet() {return m_currentProjectPath+"ChipSet/";}
QString EasyRPGCore::pathCharSet() {return m_currentProjectPath+"CharSet/";}
QString EasyRPGCore::pathBattleWeapon() {return m_currentProjectPath+"BattleWeapon/";}
QString EasyRPGCore::pathBattleCharSet() {return m_currentProjectPath+"BattleCharSet/";}
QString EasyRPGCore::pathBattle2() {return m_currentProjectPath+"Battle2/";}
QString EasyRPGCore::pathBattle() {return m_currentProjectPath+"Battle/";}
QString EasyRPGCore::pathBackdrop() {return m_currentProjectPath+"Backdrop/";}



