#ifndef QIMPORTVIEW_H
#define QIMPORTVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class QGraphicsImportItem : public QGraphicsPixmapItem
{
public:
    explicit QGraphicsImportItem(const QPixmap pix);
    
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void updateKeyColor(QPointF pos);

    QPixmap m_original_pix;
    
public slots:
    
};

#endif // QIMPORTVIEW_H
