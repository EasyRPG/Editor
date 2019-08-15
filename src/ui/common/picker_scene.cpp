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

#include "picker_scene.h"

PickerScene::PickerScene(QObject *parent,
										   QGraphicsPixmapItem *backgroundItem,
										   int rowCount,
										   int columnCount) :
	QGraphicsScene(parent)
{
	if (!backgroundItem)
		return;
	m_backgroundItem = backgroundItem;
	addItem(m_backgroundItem);
	m_selection = new QGraphicsRectItem(0,0,sceneRect().width(),sceneRect().height());
	setSceneRect(m_selection->rect());
	addItem(m_selection);
	setColumnCount(columnCount);
	setRowCount(rowCount);
}

void PickerScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (!sceneRect().contains(event->scenePos()))
		return;
	int x = static_cast<int>(event->scenePos().x()/m_selection->rect().width());
	int y = static_cast<int>(event->scenePos().y()/m_selection->rect().height());
	m_selection->setPos(x*static_cast<int>(m_selection->rect().width()),
						y*static_cast<int>(m_selection->rect().height()));
}
int PickerScene::columnCount() const
{
	return m_columnCount;
}

void PickerScene::setColumnCount(int columnCount)
{
	m_columnCount = columnCount;
	QRectF rect = m_selection->rect();
	rect.setWidth(sceneRect().width()/columnCount);
	m_selection->setRect(rect);
}

int PickerScene::index()
{
	int x = static_cast<int>(m_selection->pos().x()/m_selection->rect().width());
	int y = static_cast<int>(m_selection->pos().y()/m_selection->rect().height());
	return (x+y*columnCount());
}

void PickerScene::setIndex(int index)
{
	m_selection->setPos((index%columnCount())*m_selection->rect().width(),
						index/columnCount()*m_selection->rect().height());
}

int PickerScene::rowCount() const
{
	return m_rowCount;
}

void PickerScene::setRowCount(int rowCount)
{
	m_rowCount = rowCount;
	QRectF rect = m_selection->rect();
	rect.setHeight(sceneRect().height()/rowCount);
	m_selection->setRect(rect);
}

