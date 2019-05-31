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

#include "stat_curve_item.h"
#include "QGraphicsScene"

CurveItem::CurveItem(QColor color, std::vector<int16_t> &data, QGraphicsItem *parent) :
	QGraphicsItem(parent),
	m_data(data)
{
	m_color = color;
	m_maxValue = 999.0;
}

QRectF CurveItem::boundingRect() const
{
	if (!scene())
		return QRectF();

	return scene()->sceneRect();
}

void CurveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	if (m_data.empty() || !scene())
		return;

	QRectF r = scene()->sceneRect();
	QVector<QPointF> p;
	p.append(r.bottomLeft());
	for (size_t i = 0; i < m_data.size(); i++)
		p.append(QPointF((static_cast<qreal>(i)*r.width())/99.0,
						 r.height()-r.height()*static_cast<qreal>(m_data[i])/m_maxValue));
	p.append(r.bottomRight());

	painter->fillRect(r, Qt::black);
	painter->setBrush(QBrush(m_color));
	painter->drawPolygon(QPolygonF(p));
	painter->setPen(QPen(m_color.light()));
	painter->drawPoints(p);
}

void CurveItem::setData(std::vector<int16_t> &data)
{
	m_data = data;
	update();
}
qreal CurveItem::maxValue() const
{
	return m_maxValue;
}

void CurveItem::setMaxValue(const qreal &maxValue)
{
	m_maxValue = maxValue;
}



