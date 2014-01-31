#include "QGraphicsMapWidget.h"
#include "../EasyRPGCore.h"

QGraphicsMapWidget::QGraphicsMapWidget(QGraphicsItem *parent) :
    QGraphicsWidget(parent)
{
    m_layout = new QGraphicsGridLayout();
    m_layout->setHorizontalSpacing(0.0);
    m_layout->setVerticalSpacing(0.0);
    setLayout(m_layout);
    m_layout->setGeometry(geometry());
}

void QGraphicsMapWidget::onMapChange()
{
    for (int i = m_tiles.count()-1; i >=0; i--)
    {
        m_layout->removeItem(m_tiles[i]);
        m_tiles.pop_back();
    }
    std::auto_ptr<RPG::Map> map = EasyRPGCore::currentMap();
    if (!map.get())
        return;
    int w = map.get()->width;
    for (int y = 0; y < map.get()->height; y++)
        for(int x = 0; x < w; x++)
        {
            QGraphicsLayoutTileItem *item = new QGraphicsLayoutTileItem(this);
            item->setPixmaps(EasyRPGCore::tile(map.get()->lower_layer[x+y*w]),
                                               EasyRPGCore::tile(map.get()->upper_layer[x+y*w]),
                                               QPixmap());
            item->setGeometry(QRectF(x*EasyRPGCore::tileSize(),
                                     y*EasyRPGCore::tileSize(),
                                     EasyRPGCore::tileSize(),
                                     EasyRPGCore::tileSize()));
            m_layout->addItem(item, y,x);
            m_tiles.push_back(item);
            this->setGeometry(0,
                              0,
                              w*EasyRPGCore::tileSize(),
                              map.get()->height*EasyRPGCore::tileSize());
        }
}
