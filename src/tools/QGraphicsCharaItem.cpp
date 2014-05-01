#include "QGraphicsCharaItem.h"
#include "../core.h"

QGraphicsCharaItem::QGraphicsCharaItem(const QPixmap pix) :
    QGraphicsPixmapItem(pix)
{
    m_index = -1;
    m_facing = Direction_down;
    m_frame = Frame_middle;
    m_walk = false;
    m_spin = false;
    frame_count = 0;
}

void QGraphicsCharaItem::setBasePix(const QString &n_pixName)
{
    m_pix = QPixmap(mCore->filePath(CHARSET,n_pixName));
    if (m_pix.isNull())
        m_pix = QPixmap(mCore->rtpPath(CHARSET,n_pixName));
    updatePix();
}

int QGraphicsCharaItem::index() const
{
    return m_index;
}

void QGraphicsCharaItem::setIndex(int index)
{
    m_index = index;
    updatePix();
}

int QGraphicsCharaItem::facing() const
{
    return m_facing;
}

void QGraphicsCharaItem::setFacing(int facing)
{
    m_facing = facing;
    updatePix();
}
int QGraphicsCharaItem::frame() const
{
    return m_frame;
}

void QGraphicsCharaItem::setFrame(int frame)
{
    m_frame = frame;
    updatePix();
}

void QGraphicsCharaItem::updatePix()
{
    if (m_pix.isNull())
        return;
    if (m_index == -1)
    {
        QPixmap n_pix = QPixmap(QSize(96,64));
        QPainter p(&n_pix);
        for (int index = 0; index < 8; index++)
        {
            int src_x = (index%4)*72 + m_frame * 24;
            int src_y = (index/4)*128 + m_facing * 32;
            p.drawPixmap((index%4)*24, (index/4)*32, 24, 32, m_pix.copy(src_x,src_y,24,32));
        }
        p.end();
        this->setPixmap(n_pix);
    }
    else
    {
        int x = (m_index%4)*72 + m_frame * 24;
        int y = (m_index/4)*128 + m_facing * 32;
        this->setPixmap(m_pix.copy(x,y,24,32));
    }
}

void QGraphicsCharaItem::advance(int phase)
{
    static int patterns[4] = {Frame_middle, Frame_right, Frame_middle,Frame_left};
    if (!phase)
    {

        frame_count++;
        if (frame_count == 20)
        {
            frame_count = 0;
            if (m_spin)
            {
                m_facing++;
                if (m_facing > Direction_left)
                    m_facing = Direction_up;
            }
        }
        if (m_walk)
            m_frame = patterns[frame_count%4];
    }
    else
        updatePix();
}
bool QGraphicsCharaItem::walk() const
{
    return m_walk;
}

void QGraphicsCharaItem::setWalk(bool walk)
{
    m_walk = walk;
}

bool QGraphicsCharaItem::spin() const
{
    return m_spin;
}

void QGraphicsCharaItem::setSpin(bool spin)
{
    m_spin = spin;
}



