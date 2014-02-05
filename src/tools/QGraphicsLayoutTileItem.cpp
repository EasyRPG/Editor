#include "QGraphicsLayoutTileItem.h"
#include "../core.h"
#include <QPainter>

QGraphicsLayoutTileItem::QGraphicsLayoutTileItem(QGraphicsLayoutItem *parent, int n_x, int n_y) :
    QGraphicsLayoutItem(parent),
    x(n_x),
    y(n_y)
{
}

void QGraphicsLayoutTileItem::setGeometry(const QRectF &geom)
{
    QGraphicsLayoutItem::setGeometry(geom);
    graphicsItem()->setPos(geom.topLeft());
    graphicsItem()->setScale(geom.width()/Core::tileSize());
}

QSizeF QGraphicsLayoutTileItem::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
    case Qt::MaximumSize:
        return QSizeF(Core::tileSize(),Core::tileSize());
    default:
        break;
    }
    return constraint;
}

void QGraphicsLayoutTileItem::setLowerTile(short lower)
{
    m_lower = lower;
    createGraphicItem();
}

void QGraphicsLayoutTileItem::setUpperTile(short upper)
{
    m_upper = upper;
    createGraphicItem();
}

void QGraphicsLayoutTileItem::setTiles(short lower, short upper)
{
    m_lower = lower;
    m_upper = upper;
    createGraphicItem();
}

void QGraphicsLayoutTileItem::createGraphicItem()
{
    QPixmap pixmap(Core::tileSize(),Core::tileSize());
    QPainter p(&pixmap);
    p.drawPixmap(pixmap.rect(), Core::tile(m_lower));
    p.drawPixmap(pixmap.rect(), Core::tile(m_upper));
    for (unsigned int i = 0; i < Core::map()->events.size(); i++)
    {
        RPG::Event ev = Core::map()->events[i];
        if (ev.x == x && ev.y == y)
        {
            p.drawPixmap(pixmap.rect(),Core::tile(0x7FFE));
            break;
        }
    }
    QGraphicsPixmapItem* m_pix = new QGraphicsPixmapItem(pixmap);
    setGraphicsItem(m_pix);
}
