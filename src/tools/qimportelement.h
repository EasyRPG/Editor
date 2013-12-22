#ifndef QIMPORTVIEW_H
#define QIMPORTVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class QImportElement : public QGraphicsPixmapItem
{
public:
    explicit QImportElement(const QPixmap pix);
    
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void updateKeyColor(QPointF pos);

    QPixmap m_original_pix;
    
public slots:
    
};

#endif // QIMPORTVIEW_H
