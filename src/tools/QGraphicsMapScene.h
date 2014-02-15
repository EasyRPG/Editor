#ifndef QGRAPHICSMAPSCENE_H
#define QGRAPHICSMAPSCENE_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include "../rpg_map.h"
#include "../core.h"

class QGraphicsMapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit QGraphicsMapScene(int id, QObject *parent = 0);
    ~QGraphicsMapScene();

    float scale() const;
    int id() const;
    int chipsetId() const;
signals:

public slots:
    void redrawMap();
    void setScale(float scale);

    void onLayerChange();
private:
    int _x(int index);
    int _y(int index);
    int _index(int x, int y);
    void redrawTile(Core::Layer layer, int x, int y);

    QGraphicsPixmapItem *m_lowerpix;
    QGraphicsPixmapItem *m_upperpix;
    QVector<QGraphicsPixmapItem*> m_eventpixs;
    QVector<QGraphicsLineItem*> m_lines;
    std::auto_ptr<RPG::Map> m_map;
    std::vector<short> m_lower;
    std::vector<short> m_upper;
    float m_scale;
};

#endif // QGRAPHICSMAPSCENE_H
