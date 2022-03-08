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

#include "picker_faceset_widget.h"
#include "ui/viewer/rpg_graphics_view.h"
#include <QGraphicsScene>

void PickerFacesetWidget::clicked(const QPointF& pos) {
	int x = static_cast<int>(pos.x() / 48);
	int y = static_cast<int>(pos.y() / 48);
	m_index = y * 4 + x;
	updateRect();
}

void PickerFacesetWidget::imageChanged(QPixmap image) {
	if (!m_pixmap) {
		m_view->setMinimumSize(196, 196);
		m_view->setMaximumSize(196, 196);
		m_pixmap = new QGraphicsPixmapItem(image);
	}

	m_pixmap->setPixmap(image);
	m_view->setItem(m_pixmap);
	updateRect();
}

void PickerFacesetWidget::updateRect() {
	if (!m_rect) {
		m_rect = new QGraphicsRectItem();

		QPen selPen(Qt::white);
		selPen.setWidth(2);
		m_rect->setPen(selPen);

		m_view->scene()->addItem(m_rect);
	}

	QRect rect = {
		(m_index % 4) * 48,
		m_index / 4 * 48,
		48,
		48
	};

	m_rect->setRect(rect);
}
