#ifndef QGRAPHICSMAPWIDGET_H
#define QGRAPHICSMAPWIDGET_H

#include <QGraphicsWidget>
#include <QGraphicsGridLayout>
#include "QGraphicsLayoutTileItem.h"

class QGraphicsMapWidget : public QGraphicsWidget
{
    Q_OBJECT
public:
    explicit QGraphicsMapWidget(QGraphicsItem *parent = 0);

signals:

public slots:
    void onMapChange();

private:

    QGraphicsGridLayout *m_layout;
    QVector<QGraphicsLayoutTileItem> m_tiles;
};

#endif // QGRAPHICSMAPWIDGET_H
