#include "QGraphicsMapWidget.h"
#include "../core.h"
#include <QGraphicsScene>

QGraphicsMapWidget::QGraphicsMapWidget(QGraphicsItem *parent) :
    QGraphicsWidget(parent)
{
    m_layout = new QGraphicsGridLayout();
    for (int y = 0; y < 500; y++)
        for (int x = 0; x < 500; x++)
            m_layout->addItem(new QGraphicsLayoutTileItem(this), y, x);
    m_layout->setGeometry(geometry());
    m_pixmap = new QGraphicsPixmapItem(this);
    m_scale = 1.0;
    w = 0;
    h = 0;
}

float QGraphicsMapWidget::scale() const
{
    return m_scale;
}

void QGraphicsMapWidget::onMapChange()
{
    if (!Core::map())
    {
        m_pixmap->setVisible(false);
        w = 0;
        h = 0;
        return;
    }
    m_pixmap->setVisible(true);
    w = Core::map()->width;
    h = Core::map()->height;
    for (unsigned int i = 0; i < Core::map()->events.size(); i++)
    {
        QGraphicsLayoutTileItem item = m_layout->itemAt(Core::map()->events[i].y,
                                                        Core::map()->events[i].x);
        item.setEvent(&(Core::map()->events[i]));
    }
    QPixmap pix(Core::tileSize()*w, Core::tileSize()*h);
    pix.fill(QColor(0,0,0,0));
    for (int y = 0; y < Core::map()->height; y++)
        for(int x = 0; x < Core::map()->width; x++)
        {
            QGraphicsLayoutTileItem *item = static_cast<QGraphicsLayoutTileItem*>(m_layout->itemAt(y,x));
            item->setLowerTile(Core::map()->lower_layer[x+y*Core::map()->width]);
            item->setUpperTile(Core::map()->upper_layer[x+y*Core::map()->width]);
            item->redraw(pix, x, y);
        }
    m_pixmap->setPixmap(pix);
    setScale(m_scale);
}

void QGraphicsMapWidget::setScale(float scale)
{
    m_scale = scale;
    if (!Core::map())
        return;
    m_pixmap->setScale(m_scale);
    this->setGeometry(0,
                      0,
                      w*Core::tileSize()*m_scale,
                      h*Core::tileSize()*m_scale);
    this->scene()->setSceneRect(0,
                                0,
                                w*Core::tileSize()*m_scale,
                                h*Core::tileSize()*m_scale);
}
