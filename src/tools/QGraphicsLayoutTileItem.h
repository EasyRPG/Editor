#ifndef QGRAPHICSLAYOUTTILEITEM_H
#define QGRAPHICSLAYOUTTILEITEM_H

#include <QGraphicsLayoutItem>
#include <QGraphicsPixmapItem>

class QGraphicsLayoutTileItem : public QGraphicsLayoutItem
{
public:
    QGraphicsLayoutTileItem(QGraphicsLayoutItem *parent);
    // Inherited from QGraphicsLayoutItem
    void setGeometry(const QRectF &geom);
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const;

    void setLowerPixmap(QPixmap pix);
    void setUpperPixmap(QPixmap pix);
    void setEventPixmap(QPixmap pix);
    void setPixmaps(QPixmap lower, QPixmap upper, QPixmap event);
private:
    void createGraphicItem();

    QPixmap m_lowerPix;
    QPixmap m_upperPix;
    QPixmap m_eventPix;
};

#endif // QGRAPHICSLAYOUTTILEITEM_H
