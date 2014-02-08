#ifndef QGRAPHICSMAPSCENE_H
#define QGRAPHICSMAPSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "../rpg_map.h"

class QGraphicsMapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit QGraphicsMapScene(int id, QObject *parent = 0);

    float scale() const;
    int id() const;
    int chipsetId() const;
signals:

public slots:
    void redrawMap();
    void setScale(float scale);

private:
    int _x(int index);
    int _y(int index);
    int _index(int x, int y);
    void redrawTile(int x, int y);

    QGraphicsPixmapItem *m_pixmap;
    QGraphicsPixmapItem *m_background;
    std::auto_ptr<RPG::Map> m_map;
    std::vector<short> m_lower;
    std::vector<short> m_upper;
    float m_scale;
};

#endif // QGRAPHICSMAPSCENE_H
