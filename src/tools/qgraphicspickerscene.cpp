#include "qgraphicspickerscene.h"

QGraphicsPickerScene::QGraphicsPickerScene(QObject *parent,
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

void QGraphicsPickerScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!sceneRect().contains(event->scenePos()))
        return;
    int x = static_cast<int>(event->scenePos().x()/m_selection->rect().width());
    int y = static_cast<int>(event->scenePos().y()/m_selection->rect().height());
    m_selection->setPos(x*static_cast<int>(m_selection->rect().width()),
                        y*static_cast<int>(m_selection->rect().height()));
}
int QGraphicsPickerScene::columnCount() const
{
    return m_columnCount;
}

void QGraphicsPickerScene::setColumnCount(int columnCount)
{
    m_columnCount = columnCount;
    QRectF rect = m_selection->rect();
    rect.setWidth(sceneRect().width()/columnCount);
    m_selection->setRect(rect);
}

int QGraphicsPickerScene::index()
{
    int x = static_cast<int>(m_selection->pos().x()/m_selection->rect().width());
    int y = static_cast<int>(m_selection->pos().y()/m_selection->rect().height());
    return (x+y*columnCount());
}

void QGraphicsPickerScene::setIndex(int index)
{
    m_selection->setPos((index%columnCount())*m_selection->rect().width(),
                        index/columnCount()*m_selection->rect().height());
}

int QGraphicsPickerScene::rowCount() const
{
    return m_rowCount;
}

void QGraphicsPickerScene::setRowCount(int rowCount)
{
    m_rowCount = rowCount;
    QRectF rect = m_selection->rect();
    rect.setHeight(sceneRect().height()/rowCount);
    m_selection->setRect(rect);
}

