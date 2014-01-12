#include "EasyRPGCore.h"
#include <QApplication>
#include <QPainter>

//define static members
QListWidget* EasyRPGCore::m_debugChipset = 0;
GameProject* EasyRPGCore::m_currentProject = 0;
GameMap* EasyRPGCore::m_currentMap = 0;
int EasyRPGCore::m_tileSize = 64;
QString EasyRPGCore::m_currentGameTitle = QString();
QString EasyRPGCore::m_currentProjectPath = QString();
EasyRPGCore::Layer EasyRPGCore::m_currentLayer = EasyRPGCore::LOWER;
EasyRPGCore::Tool EasyRPGCore::m_currentTool = EasyRPGCore::PENCIL;
EasyRPGCore::Zoom EasyRPGCore::m_currentZoom = EasyRPGCore::Z_11;
QMap<int,QPixmap> EasyRPGCore::m_currentChipset = QMap<int,QPixmap>();


GameProject *EasyRPGCore::currentProject()
{
    return m_currentProject;
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
    if (o_chipset->isNull() ||
        o_chipset->size()!=QSize(480*tileSize()/16,256*tileSize()/16))
    {
        delete o_chipset;
        return;
    }
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
     * 1- WaterA
     * 2- WaterB
     * 3- DeepWater
     * 4- Ground
     **/
    //Go throught all posible combinations
    for (int tile_id = 1; tile_id < 5; tile_id++)
    for (int tile_u = 1; tile_u < 5; tile_u++)
    for (int tile_d = 1; tile_d < 5; tile_d++)
    for (int tile_l = 1; tile_l < 5; tile_l++)
    for (int tile_r = 1; tile_r < 5; tile_r++)
    for (int tile_ul = 1; tile_ul < 5; tile_ul++)
    for (int tile_ur = 1; tile_ur < 5; tile_ur++)
    for (int tile_dl = 1; tile_dl < 5; tile_dl++)
    for (int tile_dr = 1; tile_dr < 5; tile_dr++)
    {
        if (tile_id == 4)
            // Once main foreach reaches ground, we have finished
             break;
        int u = 0, d = 0, l = 0,r = 0, ul=0, ur=0, dl=0, dr=0;

        if (!isWater(tile_u))
            u = UP;
        if (!isWater(tile_d))
            d = DOWN;
        if (!isWater(tile_l))
            l = LEFT;
        if (!isWater(tile_r))
            r = RIGHT;

        // DeepWater Special Corners
        if (isDWater(tile_id))
        {
            if (isABWater(tile_u) && isABWater (tile_l) && isABWater (tile_ul))
                ul = SUPLEFT;
            if (isABWater(tile_u) && isABWater (tile_r) && isABWater (tile_ur))
                ur = SUPRIGHT;
            if (isABWater(tile_d) && isABWater (tile_l) && isABWater (tile_dl))
                dl = SDOWNLEFT;
            if (isABWater(tile_d) && isABWater (tile_r) && isABWater (tile_dr))
                dr = SDOWNRIGHT;
        }
        else
        {
            if (isABWater (tile_u) && isABWater (tile_l))
                ul = SUPLEFT;
            if (isABWater (tile_u) && isABWater (tile_r))
                ur = SUPRIGHT;
            if (isABWater (tile_d) && isABWater (tile_l))
                dl = SDOWNLEFT;
            if (isABWater (tile_d) && isABWater (tile_r))
                dr = SDOWNRIGHT;
        }
        if ((u+l) == 0 && tile_ul == 4)
            ul = UPLEFT;
        if ((u+r) == 0 && tile_ur == 4)
            ur = UPRIGHT;
        if ((d+l) == 0 && tile_dl == 4)
            dl = DOWNLEFT;
        if ((d+r) == 0 && tile_dr == 4)
            dr = DOWNRIGHT;

        int _code = tile_id * 300 + u+d+l+r+ul+ur+dl+dr;
        if (!m_currentChipset[_code].isNull()) //item exist?
            continue;
        // Water B uses second block of 3x4 tiles for borders
        // Water A and Deep Water uses first block
        int border_xoffset = (tile_id == 2) ? 3*tileSize() : 0;
        /*
         * Get base
         */
        QPixmap p_tile(tileSize(), tileSize());
        QPainter p(&p_tile);
        if (isABWater (tile_id))
            p.drawPixmap(0,0,tileSize(),tileSize(),o_chipset->copy(0, 4*tileSize(),tileSize(),tileSize()));
        else
            p.drawPixmap(0,0,tileSize(),tileSize(),o_chipset->copy(0, 7*tileSize(),tileSize(),tileSize()));
        // Draw UpperLeft corner
        int corner = u+l+ul, dest_x = 0, dest_y = 0;
        if (corner > 0)
        {
            if (corner == 1)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset, 32*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 4)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset, 16*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 5)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset, 0*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 16)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset, 48*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 21)
            {
                if (isABWater (tile_id))
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(0, 80*tileSize()/16,tileSize()/2,tileSize()/2));
                else
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(0, 96*tileSize()/16,tileSize()/2,tileSize()/2));
            }
        }
        //Draw UpperRight corner
        corner = u+r+ur;
        dest_x = tileSize()/2;
        if (corner > 0)
        {
            if (corner == 1)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset+tileSize()/2, 32*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 2)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset+tileSize()/2, 16*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 3)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset+tileSize()/2, 0*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 32)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset+tileSize()/2, 48*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 41)
            {
                if (isABWater (tile_id))
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(tileSize()/2, 80*tileSize()/16,tileSize()/2,tileSize()/2));
                else
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(tileSize()/2, 96*tileSize()/16,tileSize()/2,tileSize()/2));
            }
        }
        //Draw LowerRight corner
        corner = d+r+dr;
        dest_y = tileSize()/2;
        if (corner > 0)
        {
            if (corner == 2)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset+tileSize()/2, 40*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 8)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset+tileSize()/2, 24*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 10)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset+tileSize()/2, 8*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 128)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset+tileSize()/2, 56*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 138)
            {
                if (isABWater (tile_id))
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(tileSize()/2, 88*tileSize()/16,tileSize()/2,tileSize()/2));
                else
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(tileSize()/2, 104*tileSize()/16,tileSize()/2,tileSize()/2));
            }
        }
        //Draw LowerLeft corner
        corner = d+l+dl;
        dest_x = 0;
        if (corner > 0)
        {
            if (corner == 2)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset, 40*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 4)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset, 24*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 6)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset, 8*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 64)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(border_xoffset, 56*tileSize()/16,tileSize()/2,tileSize()/2));
            if (corner == 70)
            {
                if (isABWater (tile_id))
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(0, 88*tileSize()/16,tileSize()/2,tileSize()/2));
                else
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2,o_chipset->copy(0, 104*tileSize()/16,tileSize()/2,tileSize()/2));
            }
        }
        m_currentChipset[_code] = p_tile;
        m_debugChipset->addItem(QString("[TileID]:%1 [U]:%2 [D]:%3 [L]:%4 [R]:%5 [UL]:%6 [UR]:%7 [DL]:%8 [DR]:%9 [BC]:%10").arg(tile_id).arg(u).arg(d).arg(l).arg(r).arg(ul).arg(ur).arg(dl).arg(dr).arg(_code));
        m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[_code]));
    }

    /** Register AnimationTiles **/
    m_currentChipset[4*200] = o_chipset->copy(3*tileSize(),4*tileSize(),tileSize(),tileSize());
    m_debugChipset->addItem(QString::number(4*200));
    m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[4*200]));
    m_currentChipset[5*200] = o_chipset->copy(4*tileSize(),4*tileSize(),tileSize(),tileSize());
    m_debugChipset->addItem(QString::number(5*200));
    m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[5*200]));
    m_currentChipset[6*200] = o_chipset->copy(5*tileSize(),4*tileSize(),tileSize(),tileSize());
    m_debugChipset->addItem(QString::number(6*200));
    m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[6*200]));

    /** BindGroundTiles **/
    // Each tileset contains 5 columns with a size of 6x16 tiles
    int tileset_col = 0;

    // Each tileset column contains 4 blocks with a size of 3x4 tiles
    // Anyway we should skip water colums because they are already stored
    int block_col = 1;
    int block_row = 1;

    int tile_id = 7;

    while (tileset_col < 2)
    {
        int orig_x = (2 * tileset_col + block_col) *3*tileSize();
        int orig_y = block_row *4*tileSize();
        QPixmap p_block = o_chipset->copy(orig_x, orig_y, 3*tileSize(), 4*tileSize());

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

            /*
             * Get base
             */
            QPixmap p_tile(tileSize(), tileSize());
            QPainter p(&p_tile);
            p.drawPixmap(0,0,tileSize(),tileSize(), p_block.copy(tileSize(), tileSize()*2,tileSize(),tileSize()));

            /*
             * Draw upper_left corner
             */
            int dest_x = 0;
            int dest_y = 0;
            if ((u + l + ul) != 0)
            {
                if (u + l + ul == 1)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize(), tileSize(),tileSize()/2,tileSize()/2));
                if (u + l + ul == 4)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(0, tileSize()*2,tileSize()/2,tileSize()/2));
                if (u + l + ul == 5)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(0, tileSize(),tileSize()/2,tileSize()/2));
                if (u + l + ul == 16)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*2, 0,tileSize()/2,tileSize()/2));
            }

            /*
             * Draw upper_right corner
             */
            dest_x = tileSize()/2;
            if (u + r + ur > 0)
            {
                if (u + r + ur == 1)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*1.5, tileSize(),tileSize()/2,tileSize()/2));
                if (u + r + ur == 8)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*2.5, tileSize()*2,tileSize()/2,tileSize()/2));
                if (u + r + ur == 9)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*2.5, tileSize(),tileSize()/2,tileSize()/2));
                if (u + r + ur == 32)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*2.5, 0,tileSize()/2,tileSize()/2));
            }

            /*
             * Draw down_left corner
             */
            dest_x = 0;
            dest_y = tileSize()/2;
            if (d + l + dl > 0)
            {
                if (d + l + dl == 2)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize(), tileSize()*3.5,tileSize()/2,tileSize()/2));
                if (d + l + dl == 4)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(0, tileSize()*2.5,tileSize()/2,tileSize()/2));
                if (d + l + dl == 6)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(0, tileSize()*3.5,tileSize()/2,tileSize()/2));
                if (d + l + dl == 64)
                    p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*2, tileSize()/2,tileSize()/2,tileSize()/2));
            }

            /*
             * Draw down_right corner
             */
            dest_x = tileSize()/2;
            if (d + r + dr > 0){
            if (d + r + dr == 2)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*1.5, tileSize()*3.5,tileSize()/2,tileSize()/2));
            if (d + r + dr == 8)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*2.5, tileSize()*2.5,tileSize()/2,tileSize()/2));
            if (d + r + dr == 10)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*2.5, tileSize()*3.5,tileSize()/2,tileSize()/2));
            if (d + r + dr == 128)
                p.drawPixmap(dest_x,dest_y,tileSize()/2,tileSize()/2, p_block.copy(tileSize()*2.5, tileSize()/2,tileSize()/2,tileSize()/2));
            }

            /*
             * Register tile
             */
            int _code = (tile_id)*300+ul+u+ur+l+r+dl+d+dr;
            m_currentChipset[_code] = p_tile;
            m_debugChipset->addItem(QString::number(_code));
            m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[_code]));
        }

        tile_id++;
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
            int orig_x = tileset_col*6*tileSize()+col*tileSize();
            int orig_y = tile_row*tileSize();
            m_currentChipset[tile_id*300] = o_chipset->copy(orig_x,orig_y,tileSize(),tileSize());
            m_debugChipset->addItem(QString::number(tile_id*300));
            m_debugChipset->item(m_debugChipset->count()-1)->setIcon(QIcon(m_currentChipset[tile_id*300]));
            tile_id++;
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

bool EasyRPGCore::isWater(int tile_id)
{
    if (tile_id < 4)
        return true;
    else
        return false;
}

bool EasyRPGCore::isABWater(int tile_id)
{
    if (tile_id == 1 || tile_id == 2)
        return true;
    else
        return false;
}

bool EasyRPGCore::isDWater(int tile_id)
{
    if (tile_id == 3)
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



