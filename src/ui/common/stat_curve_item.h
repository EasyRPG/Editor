#ifndef QGRAPHICSCURVEITEM_H
#define QGRAPHICSCURVEITEM_H

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

private:
	std::vector<int16_t> m_data;
	QColor m_color;
	qreal m_maxValue;
};

#endif // QGRAPHICSCURVEITEM_H
