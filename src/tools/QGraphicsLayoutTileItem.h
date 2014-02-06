#ifndef QGRAPHICSLAYOUTTILEITEM_H
#define QGRAPHICSLAYOUTTILEITEM_H

#include <QGraphicsLayoutItem>
#include <QGraphicsPixmapItem>
#include "../rpg_event.h"

class QGraphicsLayoutTileItem : public QGraphicsLayoutItem
{
public:
    QGraphicsLayoutTileItem(QGraphicsLayoutItem *parent);

    void setLowerTile(short lower);
    void setUpperTile(short upper);
    void setEvent(RPG::Event *n_ev);

    void redraw(QPixmap &dest, int x, int y);

    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;

private:
    short m_lower;
    short m_upper;
    RPG::Event *m_ev;
};

#endif // QGRAPHICSLAYOUTTILEITEM_H
