#ifndef QGRAPHICSLAYOUTTILEITEM_H
#define QGRAPHICSLAYOUTTILEITEM_H

#include <QGraphicsLayoutItem>
#include <QGraphicsPixmapItem>

class QGraphicsLayoutTileItem : public QGraphicsLayoutItem
{
public:
    QGraphicsLayoutTileItem(QGraphicsLayoutItem *parent,int n_x, int n_y);
    // Inherited from QGraphicsLayoutItem
    void setGeometry(const QRectF &geom);
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const;

    void setLowerTile(short lower);
    void setUpperTile(short upper);
    void setTiles(short lower, short upper);
private:

    void createGraphicItem();

    short m_lower;
    short m_upper;
    int x;
    int y;
};

#endif // QGRAPHICSLAYOUTTILEITEM_H
