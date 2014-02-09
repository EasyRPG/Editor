#include "QGraphicsMapScene.h"
#include <QPainter>
#include <iomanip>
#include <sstream>
#include "../core.h"
#include "../lmu_reader.h"

QGraphicsMapScene::QGraphicsMapScene(int id, QObject *parent) :
    QGraphicsScene(parent)
{
    std::stringstream ss;
    ss << mCore()->filePath(ROOT).toStdString()
       << "Map"
       << std::setfill('0')
       << std::setw(4)
       << id
       << ".emu";
    RPG::Map *map = LMU_Reader::LoadXml(ss.str()).get();
    m_map = *map;
    m_map.ID = id;
    mCore()->LoadChipset(m_map.chipset_id);
    m_lower =  m_map.lower_layer;
    m_upper =  m_map.upper_layer;
    m_pixmap = new QGraphicsPixmapItem();
    m_background = new QGraphicsPixmapItem();
    m_scale = 1.0;
    if(m_map.parallax_flag)
    {
        QPixmap back(mCore()->filePath(PANORAMA, m_map.parallax_name.c_str()));
        m_background->setPixmap(back);
    }
    redrawMap();
    addItem(m_background);
    addItem(m_pixmap);
}

QGraphicsMapScene::~QGraphicsMapScene()
{
    delete m_pixmap;
    delete m_background;
}

float QGraphicsMapScene::scale() const
{
    return m_scale;
}

int QGraphicsMapScene::id() const
{
    return m_map.ID;
}

int QGraphicsMapScene::chipsetId() const
{
    return m_map.chipset_id;
}

void QGraphicsMapScene::redrawMap()
{
    QPixmap pix(mCore()->tileSize()*m_map.width,
                mCore()->tileSize()*m_map.height);
    pix.fill(QColor(0,0,0,0));
    mCore()->beginPainting(pix);
    for (unsigned int i = 0; i < m_lower.size(); i++)
        {
            redrawTile(_x(i), _y(i));
        }
    for (unsigned int i = 0; i <  m_map.events.size(); i++)
    {
        QRect rect(m_map.events[i].x* mCore()->tileSize(),
                   m_map.events[i].y* mCore()->tileSize(),
                   mCore()->tileSize(),
                   mCore()->tileSize());
        mCore()->renderTile(EV, rect);
    }
    mCore()->endPainting();
    m_pixmap->setPixmap(pix);
    setScale(m_scale);
}

void QGraphicsMapScene::setScale(float scale)
{
    m_scale = scale;
    m_pixmap->setScale(m_scale);
    m_background->setScale(m_scale);
    this->setSceneRect(0,
                       0,
                       m_map.width* mCore()->tileSize()*m_scale,
                       m_map.height* mCore()->tileSize()*m_scale);
}

int QGraphicsMapScene::_x(int index)
{
    return (index%m_map.width);
}

int QGraphicsMapScene::_y(int index)
{
    return (index/m_map.width);
}

int QGraphicsMapScene::_index(int x, int y)
{
    return (m_map.width*y+x);
}

void QGraphicsMapScene::redrawTile(int x, int y)
{
    QRect rect(x* mCore()->tileSize(),
               y* mCore()->tileSize(),
               mCore()->tileSize(),
               mCore()->tileSize());
    mCore()->renderTile(m_lower[_index(x,y)],rect);
    mCore()->renderTile(m_upper[_index(x,y)],rect);
}
