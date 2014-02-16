#include "QGraphicsMapScene.h"
#include <QGraphicsBlurEffect>
#include <QGraphicsOpacityEffect>
#include <QPainter>
#include <iomanip>
#include <sstream>
#include "../core.h"
#include "../lmu_reader.h"

QGraphicsMapScene::QGraphicsMapScene(int id, QGraphicsView *view, QObject *parent) :
    QGraphicsScene(parent)
{
    m_view = view;
    std::stringstream ss;
    ss << mCore()->filePath(ROOT).toStdString()
       << "Map"
       << std::setfill('0')
       << std::setw(4)
       << id
       << ".emu";
    m_map = LMU_Reader::LoadXml(ss.str());
    m_map.get()->ID = id;
    m_lower =  m_map.get()->lower_layer;
    m_upper =  m_map.get()->upper_layer;
    m_lowerpix = new QGraphicsPixmapItem();
    m_upperpix = new QGraphicsPixmapItem();
    m_scale = 1.0;
    if(m_map.get()->parallax_flag)
        mCore()->LoadBackground(m_map.get()->parallax_name.c_str());
    else
        mCore()->LoadBackground(QString());
    mCore()->LoadChipset(m_map.get()->chipset_id);
    redrawMap();
    addItem(m_lowerpix);
    addItem(m_upperpix);
    QGraphicsBlurEffect * effect = new QGraphicsBlurEffect(this);
    effect->setBlurRadius(2.0);
    effect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
    m_lowerpix->setGraphicsEffect(effect);
    m_upperpix->setGraphicsEffect(new QGraphicsOpacityEffect(this));
    for (int x = 0; x <= m_map.get()->width; x++)
    {
        QGraphicsLineItem* line = new QGraphicsLineItem(x*mCore()->tileSize(),
                                                        0,
                                                        x*mCore()->tileSize(),
                                                        m_map.get()->height*mCore()->tileSize());
        m_lines.append(line);
        addItem(line);
    }
    for (int y = 0; y <= m_map.get()->height; y++)
    {
        QGraphicsLineItem* line = new QGraphicsLineItem(0,
                                                        y*mCore()->tileSize(),
                                                        m_map.get()->width*mCore()->tileSize(),
                                                        y*mCore()->tileSize());
        m_lines.append(line);
        addItem(line);
    }
    onLayerChange();
}

QGraphicsMapScene::~QGraphicsMapScene()
{
    delete m_lowerpix;
    delete m_upperpix;
    m_eventpixs.clear();

}

float QGraphicsMapScene::scale() const
{
    return m_scale;
}

int QGraphicsMapScene::id() const
{
    return m_map.get()->ID;
}

int QGraphicsMapScene::chipsetId() const
{
    return m_map.get()->chipset_id;
}

void QGraphicsMapScene::redrawMap()
{
    QPixmap pix(mCore()->tileSize()*m_map.get()->width,
                mCore()->tileSize()*m_map.get()->height);
    pix.fill(QColor(0,0,0,0));
    mCore()->beginPainting(pix);
    for (unsigned int i = 0; i < m_lower.size(); i++)
            redrawTile(Core::LOWER, _x(i), _y(i));
    mCore()->endPainting();
    m_lowerpix->setPixmap(pix);
    pix.fill(QColor(0,0,0,0));
    mCore()->beginPainting(pix);
    for (unsigned int i = 0; i < m_upper.size(); i++)
            redrawTile(Core::UPPER, _x(i), _y(i));
    for (unsigned int i = 0; i <  m_map.get()->events.size(); i++)
    {
        QRect rect(m_map.get()->events[i].x* mCore()->tileSize(),
                   m_map.get()->events[i].y* mCore()->tileSize(),
                   mCore()->tileSize(),
                   mCore()->tileSize());
        mCore()->renderTile(EV, rect);
    }
    mCore()->endPainting();
    m_upperpix->setPixmap(pix);
    setScale(m_scale);
}

void QGraphicsMapScene::setScale(float scale)
{
    m_scale = scale;
    m_lowerpix->setScale(m_scale);
    m_upperpix->setScale(m_scale);
    for (int i = 0; i < m_lines.count(); i++)
        m_lines[i]->setScale(m_scale);
    this->setSceneRect(0,
                       0,
                       m_map.get()->width* mCore()->tileSize()*m_scale,
                       m_map.get()->height* mCore()->tileSize()*m_scale);
}

void QGraphicsMapScene::onLayerChange()
{
    switch (mCore()->layer())
    {
    case (Core::LOWER):
        m_lowerpix->graphicsEffect()->setEnabled(false);
        m_upperpix->graphicsEffect()->setEnabled(true);
        break;
    case (Core::UPPER):
        m_lowerpix->graphicsEffect()->setEnabled(true);
        m_upperpix->graphicsEffect()->setEnabled(false);
        break;
    default:
        m_lowerpix->graphicsEffect()->setEnabled(false);
        m_upperpix->graphicsEffect()->setEnabled(false);
        break;
    }
    for (int i = 0; i < m_lines.count(); i++)
        m_lines[i]->setVisible(mCore()->layer() == Core::EVENT);
}

int QGraphicsMapScene::_x(int index)
{
    return (index%m_map.get()->width);
}

int QGraphicsMapScene::_y(int index)
{
    return (index/m_map.get()->width);
}

int QGraphicsMapScene::_index(int x, int y)
{
    return (m_map.get()->width*y+x);
}

void QGraphicsMapScene::redrawTile(Core::Layer layer, int x, int y)
{
    QRect rect(x* mCore()->tileSize(),
               y* mCore()->tileSize(),
               mCore()->tileSize(),
               mCore()->tileSize());
    switch (layer)
    {
    case (Core::LOWER):
        mCore()->renderTile(m_lower[_index(x,y)],rect);
        break;
    case (Core::UPPER):
        mCore()->renderTile(m_upper[_index(x,y)],rect);
        break;
    default:
        break;
    }
}
