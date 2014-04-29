#include "qgraphicsfaceitem.h"
#include "../core.h"

QGraphicsFaceItem::QGraphicsFaceItem(const QPixmap pix) :
    QGraphicsPixmapItem(pix)
{
    m_index = -1;
}

void QGraphicsFaceItem::setBasePix(const QString &n_pixName)
{
    m_pix = QPixmap(mCore->filePath(FACESET,n_pixName));
    if (m_pix.isNull())
        m_pix = QPixmap(mCore->rtpPath(FACESET,n_pixName));
    updatePix();
}

int QGraphicsFaceItem::index() const
{
    return m_index;
}

void QGraphicsFaceItem::setIndex(int index)
{
    m_index = index;
    updatePix();
}

int QGraphicsFaceItem::facing() const
{
    return m_facing;
}

void QGraphicsFaceItem::setFacing(int facing)
{
    m_facing = facing;
    updatePix();
}
int QGraphicsFaceItem::frame() const
{
    return m_frame;
}

void QGraphicsFaceItem::setFrame(int frame)
{
    m_frame = frame;
    updatePix();
}

void QGraphicsFaceItem::updatePix()
{
    if (m_pix.isNull())
        return;
    if (m_index == -1)
    {
        QPixmap n_pix = QPixmap(QSize(192,192));
        QPainter p(&n_pix);
        for (int index = 0; index < 8; index++)
        {
            int src_x = (index%4)* 48;
            int src_y = (index/4)* 48;
            p.drawPixmap((index%4)*48, (index/4)*48, 48, 48, m_pix.copy(src_x,src_y,48,48));
        }
        p.end();
        this->setPixmap(n_pix);
    }
    else
    {
        int x = (m_index%4)* 48;
        int y = (m_index/4)* 48;
        this->setPixmap(m_pix.copy(x,y,48,48));
    }
}



