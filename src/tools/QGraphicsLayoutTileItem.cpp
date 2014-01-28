#include "QGraphicsLayoutTileItem.h"
#include "../EasyRPGCore.h"
#include <QPainter>

QGraphicsLayoutTileItem::QGraphicsLayoutTileItem(QGraphicsLayoutItem *parent) :
    QGraphicsLayoutItem(parent)
{
}

void QGraphicsLayoutTileItem::setGeometry(const QRectF &geom)
{
    QGraphicsLayoutItem::setGeometry(geom);
    graphicsItem()->setPos(geom.topLeft());
    graphicsItem()->setScale(geom.width()/m_lowerPix.width());
}

QSizeF QGraphicsLayoutTileItem::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
    case Qt::MaximumSize:
        return QSizeF(EasyRPGCore::tileSize(),EasyRPGCore::tileSize());
    default:
        break;
    }
    return constraint;
}

void QGraphicsLayoutTileItem::setLowerPixmap(QPixmap pix)
{
    m_lowerPix = pix;
    createGraphicItem();
}

void QGraphicsLayoutTileItem::setUpperPixmap(QPixmap pix)
{
    m_upperPix = pix;
    createGraphicItem();
}

void QGraphicsLayoutTileItem::setEventPixmap(QPixmap pix)
{
    m_eventPix = pix;
    createGraphicItem();
}

void QGraphicsLayoutTileItem::setPixmaps(QPixmap lower, QPixmap upper, QPixmap event)
{
    m_lowerPix = lower;
    m_upperPix = upper;
    m_eventPix = event;
    createGraphicItem();
}

void QGraphicsLayoutTileItem::createGraphicItem()
{
    QPixmap pixmap = m_lowerPix;
    QPainter p(&pixmap);
    p.drawPixmap(m_lowerPix.rect(), m_upperPix);
    p.drawPixmap(m_lowerPix.rect(), m_eventPix);
    QGraphicsPixmapItem* m_pix = new QGraphicsPixmapItem(pixmap);
    setGraphicsItem(m_pix);
}
