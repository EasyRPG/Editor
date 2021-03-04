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

#include "rpg_graphics_view.h"
#include <QMouseEvent>

RpgGraphicsViewBase::RpgGraphicsViewBase(QWidget* parent) : QGraphicsView(parent) {
	setScene(new QGraphicsScene(this));
}

void RpgGraphicsViewBase::enableTimer() {
	m_timer.reset(new QTimer());
	QObject::connect(m_timer.get(), &QTimer::timeout, scene(), &QGraphicsScene::advance);
	m_timer->start(1000 / 33);
}

void RpgGraphicsViewBase::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton && m_item) {
		const auto& p = mapToScene(event->pos());
		if (m_item->boundingRect().contains(p)) {
			emit clicked(p);
		}
	}
	QGraphicsView::mousePressEvent(event);
}
