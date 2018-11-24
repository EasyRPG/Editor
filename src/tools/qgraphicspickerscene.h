#ifndef QGRAPHICSPICKERSCENE_H
#define QGRAPHICSPICKERSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>

class QGraphicsPickerScene : public QGraphicsScene
{
public:
    QGraphicsPickerScene(QObject *parent = nullptr,
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

#endif // QGRAPHICSPICKERSCENE_H
