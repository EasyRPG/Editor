#ifndef QGRAPHICSMAPSCENE_H
#define QGRAPHICSMAPSCENE_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <rpg_map.h>
#include "../core.h"

class QGraphicsMapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit QGraphicsMapScene(int id,QGraphicsView *view, QObject *parent = 0);
    ~QGraphicsMapScene();

    float scale() const;
    int id() const;
    int chipsetId() const;
signals:

public slots:
    void redrawMap();

    void setScale(float scale);

    void onLayerChanged();

    void onToolChanged();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    int _x(int index);
    int _y(int index);
    int _index(int x, int y);
    void redrawTile(const Core::Layer &layer,
                    const int &x,
                    const int &y,
                    const QRect &dest_rec);
    void stopDrawing();
    void stopSelecting();
    void updateArea(int x1, int y1, int x2, int y2);
    void redrawLayer(Core::Layer layer);
    void drawPen();
    short bind(int x, int y);

    QGraphicsPixmapItem *m_lowerpix;
    QGraphicsPixmapItem *m_upperpix;
    QVector<QGraphicsPixmapItem*> m_eventpixs;
    QVector<QGraphicsLineItem*> m_lines;
    std::auto_ptr<RPG::Map> m_map;
    std::vector<short> m_lower;
    std::vector<short> m_upper;
    float m_scale;
    int s_tileSize;
    int cur_x;
    int cur_y;
    int fst_x;
    int fst_y;
    int lst_x;
    int lst_y;
    QGraphicsView* m_view;
    bool m_drawing;
    bool m_cancelled;
    bool m_selecting;
};

#endif // QGRAPHICSMAPSCENE_H
