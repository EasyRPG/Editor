#include "QGraphicsMapScene.h"
#include <QPainter>
#include "../core.h"

QGraphicsMapScene::QGraphicsMapScene(QObject *parent) :
    QGraphicsScene(parent)
{
    m_pixmap = new QGraphicsPixmapItem();
    m_background = new QGraphicsPixmapItem();
    addItem(m_background);
    addItem(m_pixmap);
    m_scale = 1.0;
    w = 0;
    h = 0;
}

float QGraphicsMapScene::scale() const
{
    return m_scale;
}

void QGraphicsMapScene::onMapChange()
{
    if (! mCore()->map() ||  mCore()->map()->ID == 0)
    {
        m_pixmap->setVisible(false);
        w = 0;
        h = 0;
        return;
    }
    m_pixmap->setVisible(true);
    w =  mCore()->map()->width;
    h =  mCore()->map()->height;
    if( mCore()->map()->parallax_name != "")
    {
        QPixmap back( mCore()->projectPath() +
                     "Panorama/" +
                     QString::fromStdString( mCore()->map()->parallax_name));
        m_background->setPixmap(back);
        m_background->setVisible(true);
    }
    else
        m_background->setVisible(false);
    QPixmap pix( mCore()->tileSize()*w,  mCore()->tileSize()*h);
    pix.fill(QColor(0,0,0,0));
    m_lower =  mCore()->map()->lower_layer;
    m_upper =  mCore()->map()->upper_layer;
    for (unsigned int i = 0; i < m_lower.size(); i++)
        {
            redrawTile(pix, _x(i), _y(i));
        }

    QPainter p(&pix);
    for (unsigned int i = 0; i <  mCore()->map()->events.size(); i++)
    {
        p.drawPixmap( mCore()->map()->events[i].x* mCore()->tileSize(),
                      mCore()->map()->events[i].y* mCore()->tileSize(),
                      mCore()->tileSize(),
                      mCore()->tileSize(),
                      mCore()->tile(EV));
    }
    m_pixmap->setPixmap(pix);
    setScale(m_scale);
}

void QGraphicsMapScene::setScale(float scale)
{
    m_scale = scale;
    if (! mCore()->map())
        return;
    m_pixmap->setScale(m_scale);
    this->setSceneRect(0,
                       0,
                       w* mCore()->tileSize()*m_scale,
                       h* mCore()->tileSize()*m_scale);
}

int QGraphicsMapScene::_x(int index)
{
    return (index%w);
}

int QGraphicsMapScene::_y(int index)
{
    return (index/w);
}

int QGraphicsMapScene::_index(int x, int y)
{
    return (w*y+x);
}

void QGraphicsMapScene::redrawTile(QPixmap &dest, int x, int y)
{
    QPainter p(&dest);
    p.drawPixmap(x* mCore()->tileSize(),
                 y* mCore()->tileSize(),
                  mCore()->tileSize(),
                  mCore()->tileSize(),
                  mCore()->tile(m_lower[_index(x,y)]));
    p.drawPixmap(x* mCore()->tileSize(),
                 y* mCore()->tileSize(),
                  mCore()->tileSize(),
                  mCore()->tileSize(),
                  mCore()->tile(m_upper[_index(x,y)]));
}
