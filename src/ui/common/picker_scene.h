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
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>

class PickerScene : public QGraphicsScene
{
public:
	PickerScene(QObject *parent = nullptr,
						 QGraphicsPixmapItem* backgroundItem = nullptr,
						 int rowCount = 1,
						 int columnCount = 1);

	int rowCount() const;
	void setRowCount(int rowCount);

	int columnCount() const;
	void setColumnCount(int columnCount);

	int index();
	void setIndex(int index);

signals:

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	int m_rowCount;
	int m_columnCount;
	QGraphicsPixmapItem *m_backgroundItem;
	QGraphicsRectItem *m_selection;
	QRectF m_defaultRect;
};

