/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#include "picker_charset_widget.h"
#include "ui/viewer/rpg_graphics_view.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

void PickerCharsetWidget::clicked(const QPointF& pos) {
	int x = static_cast<int>(pos.x() / 24);
	int y = static_cast<int>(pos.y() / 32);
	m_index = y * 4 + x;
	updateRect();
}

void PickerCharsetWidget::imageChanged(QPixmap image) {
	if (!m_pixmap) {
		m_view->scale(2.0, 2.0);
		m_pixmap = new QGraphicsPixmapItem();
	}

	QPixmap new_image(24 * 4, 32 * 2);

	QPainter* paint = new QPainter(&new_image);

	for (int i = 0; i < 8; ++i) {
		int src_x = 24 + ((i % 4) * 24 * 3);
		int src_y = 2 * 32;
		if (i >= 4) {
			src_y = 6 * 32;
		}

		int target_x = (i % 4) * 24;
		int target_y = i >= 4 ? 32 : 0;
		paint->drawPixmap(QRectF(target_x, target_y, 24, 32), image, QRectF(src_x, src_y, 24, 32));
	}
	delete paint;

	m_pixmap->setPixmap(new_image);
	m_view->setItem(m_pixmap);
	updateRect();
}

void PickerCharsetWidget::updateRect() {
	if (!m_rect) {
		m_rect = new QGraphicsRectItem();

		QPen selPen(Qt::white);
		selPen.setWidth(2);
		m_rect->setPen(selPen);

		m_view->scene()->addItem(m_rect);
	}

	QRect rect = {
		(m_index % 4) * 24,
		m_index / 4 * 32,
		24,
		32
	};

	m_rect->setRect(rect);
}
