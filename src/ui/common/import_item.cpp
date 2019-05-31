#include "import_item.h"
#include <QBitmap>

ImportItem::ImportItem(const QPixmap pix) :
	QGraphicsPixmapItem(pix),
	m_original_pix(pix)
{

}

void ImportItem::mousePressEvent(QGraphicsSceneMouseEvent	*event)
{
	updateKeyColor(event->pos());
	QGraphicsItem::mousePressEvent(event);
}

void ImportItem::updateKeyColor(QPointF pos)
{
	QColor keycolor = QColor(pixmap().toImage().pixel(pos.toPoint()));
	QPixmap pix = QPixmap(m_original_pix);
	pix.setMask(m_original_pix.createMaskFromColor(keycolor));
	this->setPixmap(pix);
}
