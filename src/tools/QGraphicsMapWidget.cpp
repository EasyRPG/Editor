#include "QGraphicsMapWidget.h"
#include "../core.h"
#include <QGraphicsScene>

QGraphicsMapWidget::QGraphicsMapWidget(QGraphicsItem *parent) :
    QGraphicsWidget(parent)
{
    m_layout = new QGraphicsGridLayout();
    m_layout->setHorizontalSpacing(0.0);
    m_layout->setVerticalSpacing(0.0);
    setLayout(m_layout);
    m_layout->setGeometry(geometry());
    m_scale = 1.0;
}

float QGraphicsMapWidget::scale() const
{
    return m_scale;
}

void QGraphicsMapWidget::onMapChange()
{
    for (int i = 0; i < m_tiles.count(); i++)
    {
        m_layout->removeItem(m_tiles[i]);
        this->scene()->removeItem(m_tiles[i]->graphicsItem());
    }
    m_tiles.clear();
    if (!Core::map())
        return;
    int w = Core::map()->width;
    for (int y = 0; y < Core::map()->height; y++)
        for(int x = 0; x < w; x++)
        {
            QGraphicsLayoutTileItem *item = new QGraphicsLayoutTileItem(this, x, y);
            item->setTiles(Core::map()->lower_layer[x+y*Core::map()->width],
                           Core::map()->upper_layer[x+y*Core::map()->width]);
            m_layout->addItem(item, y,x);
            m_tiles.push_back(item);
        }
    setScale(m_scale);
}

void QGraphicsMapWidget::setScale(float scale)
{
    m_scale = scale;
    if (!Core::map() || Core::map()->ID == 0)
        return;
    for (int i = 0; i < m_tiles.count(); i++)
    {
        QRectF geom(i%Core::map()->width*Core::tileSize()*m_scale,
                    i/Core::map()->width*Core::tileSize()*m_scale,
                    Core::tileSize()*m_scale,
                    Core::tileSize()*m_scale);
        m_tiles[i]->setGeometry(geom);
    }
    this->setGeometry(0,
                      0,
                      Core::map()->width*Core::tileSize()*m_scale,
                      Core::map()->height*Core::tileSize()*m_scale);
    this->scene()->setSceneRect(geometry());
}
