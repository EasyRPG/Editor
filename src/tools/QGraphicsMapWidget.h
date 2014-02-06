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

    float scale() const;
signals:

public slots:
    void onMapChange();
    void setScale(float scale);

private:
    QGraphicsGridLayout *m_layout;
    QGraphicsPixmapItem *m_pixmap;
    float m_scale;
    int w;
    int h;
};

#endif // QGRAPHICSMAPWIDGET_H
