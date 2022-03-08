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

#include <QGraphicsItem>
#include <QPainter>
#include <stdint.h>

class CurveItem : public QGraphicsItem
{
public:
	explicit CurveItem(QColor color, std::vector<int16_t> &data, QGraphicsItem *parent = nullptr);

	QRectF boundingRect() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	void setData(std::vector<int16_t> &data);

	qreal maxValue() const;
	void setMaxValue(const qreal &maxValue);

	qreal maxLevel() const;
	void setMaxLevel(const qreal &maxLevel);

private:
	std::vector<int16_t> m_data;
	QColor m_color;
	qreal m_maxValue;
	qreal m_maxLevel;
};

