#include "QGraphicsLayoutTileItem.h"
#include "../core.h"
#include <QPainter>

QGraphicsLayoutTileItem::QGraphicsLayoutTileItem(QGraphicsLayoutItem *parent) :
    QGraphicsLayoutItem(parent)
{
    m_ev = -1;
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
}

void QGraphicsLayoutTileItem::setUpperTile(short upper)
{
    m_upper = upper;
}

void QGraphicsLayoutTileItem::setEvent(int n_ev)
{
    m_ev = n_ev;
    m_lower = 5000;
}

void QGraphicsLayoutTileItem::redraw(QPixmap &dest, int x, int y)
{
    QPainter p(&dest);
    p.drawPixmap(x*Core::tileSize(),
                 y*Core::tileSize(),
                 Core::tileSize(),
                 Core::tileSize(),
                 Core::tile(m_lower));
    p.drawPixmap(x*Core::tileSize(),
                 y*Core::tileSize(),
                 Core::tileSize(),
                 Core::tileSize(),
                 Core::tile(m_upper));
    if (m_ev != -1)
        p.drawPixmap(x*Core::tileSize(),
                     y*Core::tileSize(),
                     Core::tileSize(),
                     Core::tileSize(),
                     Core::tile(0x7FFE));
}
