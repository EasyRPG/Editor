#ifndef QGRAPHICSCHARAITEM_H
#define QGRAPHICSCHARAITEM_H

#include <QGraphicsPixmapItem>

class QGraphicsCharaItem : public QGraphicsPixmapItem
{
public:
    enum Direction {
        Direction_up = 0,
        Direction_right = 1,
        Direction_down = 2,
        Direction_left = 3
    };

    enum Frame {
        Frame_left = 0,
        Frame_middle = 1,
        Frame_right = 2
    };

    explicit QGraphicsCharaItem(const QPixmap pix = QPixmap(96,64));

    void setBasePix(const QString &n_pixName);

    int index() const;
    void setIndex(int index);

    int facing() const;
    void setFacing(int facing);

    int frame() const;
    void setFrame(int frame);

    void updatePix();

    bool spin() const;
    void setSpin(bool spin);

    bool walk() const;
    void setWalk(bool walk);

signals:

public slots:

protected:
    void advance(int phase);

private:
    QPixmap m_pix;
    int frame_count;
    int m_index;
    int m_facing;
    int m_frame;
    bool m_spin;
    bool m_walk;
};

#endif // QGRAPHICSCHARAITEM_H
