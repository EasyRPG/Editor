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
    if (!Core::map() || Core::map()->ID == 0)
    {
        m_pixmap->setVisible(false);
        w = 0;
        h = 0;
        return;
    }
    m_pixmap->setVisible(true);
    w = Core::map()->width;
    h = Core::map()->height;
    if(Core::map()->parallax_name != "")
    {
        QPixmap back(Core::projectPath() +
                     "Panorama/" +
                     QString::fromStdString(Core::map()->parallax_name));
        m_background->setPixmap(back);
        m_background->setVisible(true);
    }
    else
        m_background->setVisible(false);
    QPixmap pix(Core::tileSize()*w, Core::tileSize()*h);
    pix.fill(QColor(0,0,0,0));
    m_lower = Core::map()->lower_layer;
    m_upper = Core::map()->upper_layer;
    for (unsigned int i = 0; i < m_lower.size(); i++)
        {
            redrawTile(pix, _x(i), _y(i));
        }

    QPainter p(&pix);
    for (unsigned int i = 0; i < Core::map()->events.size(); i++)
    {
        p.drawPixmap(Core::map()->events[i].x*Core::tileSize(),
                     Core::map()->events[i].y*Core::tileSize(),
                     Core::tileSize(),
                     Core::tileSize(),
                     Core::tile(0x7FFE));
    }
    m_pixmap->setPixmap(pix);
    setScale(m_scale);
}

void QGraphicsMapScene::setScale(float scale)
{
    m_scale = scale;
    if (!Core::map())
        return;
    m_pixmap->setScale(m_scale);
    this->setSceneRect(0,
                       0,
                       w*Core::tileSize()*m_scale,
                       h*Core::tileSize()*m_scale);
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
    p.drawPixmap(x*Core::tileSize(),
                 y*Core::tileSize(),
                 Core::tileSize(),
                 Core::tileSize(),
                 Core::tile(m_lower[_index(x,y)]));
    p.drawPixmap(x*Core::tileSize(),
                 y*Core::tileSize(),
                 Core::tileSize(),
                 Core::tileSize(),
                 Core::tile(m_upper[_index(x,y)]));
}
