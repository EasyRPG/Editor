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

#pragma once

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPainter>
#include <QTimer>
#include <memory>
#include <type_traits>

#include "charset_graphics_item.h"
#include "faceset_graphics_item.h"
#include "tile_graphics_item.h"

class RpgGraphicsViewBase : public QGraphicsView {
	Q_OBJECT

public:
	explicit RpgGraphicsViewBase(QWidget* parent);

	void enableTimer();

signals:
	void clicked(const QPointF&);

protected:
	void mousePressEvent(QMouseEvent* event) override;

	QGraphicsItem* m_item = nullptr;
	std::unique_ptr<QTimer> m_timer;
};

template <typename ITEM>
class RpgGraphicsView : public RpgGraphicsViewBase {
public:
	static_assert(
		std::is_base_of<QGraphicsItem, ITEM>::value,
		"ITEM must be a QGraphicsItem"
	);

	explicit RpgGraphicsView(QWidget* parent) : RpgGraphicsViewBase(parent) {}

	ITEM* item() {
		return reinterpret_cast<ITEM*>(m_item);
	}

	void setItem(ITEM* item) {
		if (item != m_item) {
			scene()->clear();
			if (item) {
				scene()->addItem(item);
			}
		}

		m_item = item;
		if (!item) {
			scene()->setSceneRect(QRectF());
			return;
		}
		scene()->setSceneRect(item->boundingRect());
	}
};

using CharSetGraphicsView = RpgGraphicsView<CharSetGraphicsItem>;
using FaceSetGraphicsView = RpgGraphicsView<FaceSetGraphicsItem>;
using TileGraphicsView = RpgGraphicsView<TileGraphicsItem>;
using PixmapGraphicsView = RpgGraphicsView<QGraphicsPixmapItem>;
