#include "QGraphicsMapWidget.h"
#include "../EasyRPGCore.h"
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
    if (!_map())
        return;
    int w = _map()->width;
    for (int y = 0; y < _map()->height; y++)
        for(int x = 0; x < w; x++)
        {
            QGraphicsLayoutTileItem *item = new QGraphicsLayoutTileItem(this);
            item->setPixmaps(EasyRPGCore::tile(_map()->lower_layer[x+y*w]),
                             EasyRPGCore::tile(_map()->upper_layer[x+y*w]),
                             QPixmap());
            m_layout->addItem(item, y,x);
            m_tiles.push_back(item);
        }
    setScale(m_scale);
}

void QGraphicsMapWidget::setScale(float scale)
{
    m_scale = scale;
    if (!_map())
        return;
    for (int i = 0; i < m_tiles.count(); i++)
    {
        QRectF geom(i%_map()->width*EasyRPGCore::tileSize()*m_scale,
                    i/_map()->width*EasyRPGCore::tileSize()*m_scale,
                    EasyRPGCore::tileSize()*m_scale,
                    EasyRPGCore::tileSize()*m_scale);
        m_tiles[i]->setGeometry(geom);
    }
    this->setGeometry(0,
                      0,
                      _map()->width*EasyRPGCore::tileSize()*m_scale,
                      _map()->height*EasyRPGCore::tileSize()*m_scale);
    this->scene()->setSceneRect(0,
                                0,
                                _map()->width*EasyRPGCore::tileSize()*m_scale,
                                _map()->height*EasyRPGCore::tileSize()*m_scale);
}
