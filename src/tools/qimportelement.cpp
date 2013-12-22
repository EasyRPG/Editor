#include "qimportelement.h"
#include <QBitmap>

QImportElement::QImportElement(const QPixmap pix) :
    QGraphicsPixmapItem(pix),
    m_original_pix(pix)
{

}

void QImportElement::mousePressEvent(QGraphicsSceneMouseEvent  *event)
{
    updateKeyColor(event->pos());
    QGraphicsItem::mousePressEvent(event);
}

void QImportElement::updateKeyColor(QPointF pos)
{
    QColor keycolor = QColor(pixmap().toImage().pixel(pos.toPoint()));
    QPixmap pix = QPixmap(m_original_pix);
    pix.setMask(m_original_pix.createMaskFromColor(keycolor));
    this->setPixmap(pix);
}
