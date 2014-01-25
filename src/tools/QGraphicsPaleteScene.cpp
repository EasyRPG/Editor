#include "QGraphicsPaleteScene.h"
#include <QPainter>

QGraphicsPaleteScene::QGraphicsPaleteScene(QObject *parent) :
    QGraphicsScene(parent),
    m_cancel(false),
    m_pressed(false)
{
    this->setSceneRect(QRect(0,0,192,896));
    m_selectionItem = new QGraphicsRectItem(QRectF(QRect(0,32,32,32)));
    last_selection = QRectF(QRect(0,32,32,32));
    this->addItem(m_selectionItem);
    m_tiles = new QGraphicsPixmapItem();
    this->addItem(m_tiles);
    m_tiles->setVisible(false);
    QPen selPen(Qt::yellow);
    selPen.setWidth(3);
    m_selectionItem->setPen(selPen);
    m_selectionItem->setVisible(false);
    m_tiles->stackBefore(m_selectionItem);
}

void QGraphicsPaleteScene::onLayerChange()
{
    if (EasyRPGCore::currentLayer() == EasyRPGCore::LOWER)
    {
        m_tiles->setPixmap(m_lowerTiles);
    }
    else
    {
        m_tiles->setPixmap(m_upperTiles);
    }
}

void QGraphicsPaleteScene::onChipsetChange()
{
    if (chipsetIsNull())
    {
        m_tiles->setVisible(false);
        m_selectionItem->setVisible(false);
        return;
    }
    m_tiles->setVisible(true);
    m_selectionItem->setVisible(true);
    m_lowerTiles = QPixmap(192, 896);
    m_upperTiles = QPixmap(192, 896);
    QPainter l(&m_lowerTiles);
    QPainter u(&m_upperTiles);
    l.drawPixmap(0,0,192,32,QPixmap(":/embedded/share/eraser.png"));
    u.drawPixmap(0,0,192,32,QPixmap(":/embedded/share/eraser.png"));
    for (int terrain_id = 0; terrain_id < 162; terrain_id++)
    {
        int col =((terrain_id)%6)*32;
        int row = (terrain_id/6+1)*32;
        l.drawPixmap(col,row,32,32,EasyRPGCore::tile(EasyRPGCore::translate(terrain_id,15)));
        u.drawPixmap(col,row,32,32,EasyRPGCore::tile(EasyRPGCore::translate(terrain_id)));
    }
}

void QGraphicsPaleteScene::updateSelectionRect()
{
    QRectF selRect;
    int small_x = (m_initial.x() <= m_current.x()) ? m_initial.x()/32.0 : m_current.x()/32.0;
    int big_x = (m_initial.x() >= m_current.x()) ? m_initial.x()/32.0 : m_current.x()/32.0;
    int small_y = (m_initial.y() <= m_current.y()) ? m_initial.y()/32.0 : m_current.y()/32.0;
    int big_y = (m_initial.y() >= m_current.y()) ? m_initial.y()/32.0 : m_current.y()/32.0;
    //keep inside the scene
    if (small_x < 0)
        small_x = 0;
    if (small_x > 5)
        small_x = 5;
    if (big_x > 5)
        big_x = 5;
    if (small_y < 0)
        small_y = 0;
    if (big_y > 27)
        big_y = 27;
    if (big_y - small_y > 5)
    {
        if ((int)m_initial.y()/32 == small_y)
            big_y = small_y + 5;
        else
            small_y = big_y - 5;
    }
    if (m_initial.y() < 32.0)
        selRect = QRectF(QRect(0,0,192,32));
    else
        selRect = QRectF(QRect(small_x*32,small_y*32,(big_x-small_x+1)*32,(big_y-small_y+1)*32));

    m_selectionItem->setRect(selRect);
}

void QGraphicsPaleteScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        cancelSelection();
        return;
    }
    else if (event->button() != Qt::LeftButton)
        return;
    m_initial = event->scenePos();
    m_current = event->scenePos();
    updateSelectionRect();
    QGraphicsScene::mousePressEvent(event);
}

void QGraphicsPaleteScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_cancel)
        return;
    if (m_initial.y() < 32) //eraser selected
        return;
    if (m_initial.y() >= 32 && event->scenePos().y() < 32) //avoid mix with eraser
        m_current = QPointF(event->scenePos().x(), m_current.y());
    else
        m_current = event->scenePos();

    updateSelectionRect();
    QGraphicsScene::mouseMoveEvent(event);
}

void QGraphicsPaleteScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_cancel)
    {
        m_cancel = false;
        return;
    }
    if (event->button() != Qt::LeftButton)
        return;

    //TODO: set selection
    last_selection = m_selectionItem->boundingRect();
    QGraphicsScene::mouseReleaseEvent(event);
}

void QGraphicsPaleteScene::cancelSelection()
{
    m_cancel = true;
    m_selectionItem->setRect(last_selection);
}


