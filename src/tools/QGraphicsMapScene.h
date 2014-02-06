#ifndef QGRAPHICSMAPSCENE_H
#define QGRAPHICSMAPSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class QGraphicsMapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit QGraphicsMapScene(QObject *parent = 0);

    float scale() const;
signals:

public slots:
    void onMapChange();
    void setScale(float scale);

private:
    int _x(int index);
    int _y(int index);
    int _index(int x, int y);

    QGraphicsPixmapItem *m_pixmap;
    QGraphicsPixmapItem *m_background;
    std::vector<short> m_lower;
    std::vector<short> m_upper;
    float m_scale;
    int w;
    int h;
    void redrawTile(QPixmap &dest, int x, int y);
};

#endif // QGRAPHICSMAPSCENE_H
