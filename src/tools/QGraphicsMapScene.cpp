#include "QGraphicsMapScene.h"
#include <QGraphicsBlurEffect>
#include <QGraphicsOpacityEffect>
#include <QPainter>
#include <QScrollBar>
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
    if(m_map.get()->parallax_flag)
        mCore()->LoadBackground(m_map.get()->parallax_name.c_str());
    else
        mCore()->LoadBackground(QString());
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
    mCore()->LoadChipset(m_map.get()->chipset_id);
    int s_tileSize = mCore()->tileSize()*m_scale;
    QSize size = m_view->size();
    if (size.width() > m_map.get()->width*s_tileSize)
        size.setWidth(m_map.get()->width*s_tileSize);
    else
        size.setWidth(size.width()+s_tileSize);
    if (size.height() > m_map.get()->height*s_tileSize)
        size.setHeight(m_map.get()->height*s_tileSize);
    else
        size.setHeight(size.height()+s_tileSize);
    int start_x = 0;
    if (m_view->horizontalScrollBar()->isVisible())
        start_x =m_view->horizontalScrollBar()->value()/s_tileSize;
    int start_y = 0;
    if (m_view->verticalScrollBar()->isVisible())
        start_y = m_view->verticalScrollBar()->value()/s_tileSize;
    int end_x = start_x+(size.width()-1)/s_tileSize;
    int end_y = start_y+(size.height()-1)/s_tileSize;
    QPixmap pix(size);
    pix.fill(QColor(0,0,0,0));
    mCore()->beginPainting(pix);
    for (int x = start_x; x <= end_x; x++)
        for (int y = start_y; y <= end_y; y++)
        {
            if (x >= m_map.get()->width || y >= m_map.get()->height)
                continue;
            QRect dest_rect((x-start_x)* s_tileSize,
                       (y-start_y)* s_tileSize,
                       s_tileSize,
                       s_tileSize);

            redrawTile(Core::LOWER, x, y, dest_rect);
        }
    mCore()->endPainting();
    m_lowerpix->setPixmap(pix);
    m_lowerpix->setPos(start_x*s_tileSize,
                       start_y*s_tileSize);
    pix.fill(QColor(0,0,0,0));
    mCore()->beginPainting(pix);
    for (int x = start_x; x <= end_x; x++)
        for (int y = start_y; y <= end_y; y++)
        {
            if (x >= m_map.get()->width || y >= m_map.get()->height)
                continue;
            QRect dest_rect((x-start_x)* s_tileSize,
                       (y-start_y)* s_tileSize,
                       s_tileSize,
                       s_tileSize);
            redrawTile(Core::UPPER, x, y, dest_rect);
        }
    for (unsigned int i = 0; i <  m_map.get()->events.size(); i++)
    {
        QRect rect((m_map.get()->events[i].x-start_x)* s_tileSize,
                   (m_map.get()->events[i].y-start_y)* s_tileSize,
                   s_tileSize,
                   s_tileSize);
        mCore()->renderTile(EV, rect);
    }
    mCore()->endPainting();
    m_upperpix->setPixmap(pix);
    m_upperpix->setPos(start_x*s_tileSize,
                       start_y*s_tileSize);
}

void QGraphicsMapScene::setScale(float scale)
{
    m_scale = scale;
    for (int i = 0; i < m_lines.count(); i++)
        m_lines[i]->setScale(m_scale);
    this->setSceneRect(0,
                       0,
                       m_map.get()->width* mCore()->tileSize()*m_scale,
                       m_map.get()->height* mCore()->tileSize()*m_scale);
    redrawMap();
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

void QGraphicsMapScene::redrawTile(const Core::Layer &layer,
                                   const int &x,
                                   const int &y,
                                   const QRect &dest_rec)
{
    switch (layer)
    {
    case (Core::LOWER):
        mCore()->renderTile(m_lower[_index(x,y)],dest_rec);
        break;
    case (Core::UPPER):
        mCore()->renderTile(m_upper[_index(x,y)],dest_rec);
        break;
    default:
        break;
    }
}
