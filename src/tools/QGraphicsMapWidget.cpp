#include "QGraphicsMapWidget.h"
#include "../EasyRPGCore.h"

QGraphicsMapWidget::QGraphicsMapWidget(QGraphicsItem *parent) :
    QGraphicsWidget(parent)
{
    m_layout = new QGraphicsGridLayout();
    setLayout(m_layout);
    m_layout->setGeometry(geometry());
}

void QGraphicsMapWidget::onMapChange()
{
//    for (int i = m_tiles.count()-1; i >=0; i--)
//    {
//        m_layout->removeItem(m_tiles[i]);
//        m_tiles.pop_back();
//    }

//    for (int y = 0; y < EasyRPGCore::currentMap()->height(); y++)
//        for(int x = 0; x < EasyRPGCore::currentMap()->width(); x++)
//        {
//            QGraphicsLayoutTileItem *item = new QGraphicsLayoutTileItem(this);
//            item->setPixmaps(EasyRPGCore::tile(EasyRPGCore::currentMap()->tileAt(EasyRPGCore::LOWER,x,y)),
//                             EasyRPGCore::tile(EasyRPGCore::currentMap()->tileAt(EasyRPGCore::UPPER,x,y)),
//                             EasyRPGCore::tile(EasyRPGCore::currentMap()->tileAt(EasyRPGCore::EVENT,x,y)));
//            m_layout->addItem(item, y,x);
//        }
}
