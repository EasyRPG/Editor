#ifndef QGRAPHICSMAPSCENE_H
#define QGRAPHICSMAPSCENE_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMenu>
#include <QUndoStack>
#include <memory>
#include <rpg_map.h>
#include <rpg_mapinfo.h>
#include "../core.h"

class QGraphicsMapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit QGraphicsMapScene(int id,QGraphicsView *view, QObject *parent = 0);
    ~QGraphicsMapScene();

    void Init();
    float scale() const;
    void setScale(float scale);
    QString mapName() const;
    bool isModified() const;
    int id() const;
    int chipsetId() const;
    void setLayerData(Core::Layer layer, std::vector<short> data);

signals:
    void actionRunHereTriggered(int map_id, int x, int y);

    void mapChanged();

    void mapSaved();

    void mapReverted();

public slots:
    void redrawMap();

    void onLayerChanged();

    void onToolChanged();

    void Save();

    void Load();

    void undo();

private slots:
    void on_actionRunHere();

    void on_actionSetStartPosition();

    void on_view_V_Scroll();

    void on_view_H_Scroll();

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


    QMenu *m_eventMenu;
    QGraphicsPixmapItem *m_lowerpix;
    QGraphicsPixmapItem *m_upperpix;
    QVector<QGraphicsPixmapItem*> m_eventpixs;
    QVector<QGraphicsLineItem*> m_lines;
    QUndoStack *m_undoStack;
    std::auto_ptr<RPG::Map> m_map;
    RPG::MapInfo *m_mapInfo;
    RPG::MapInfo *n_mapInfo; //To store unsaved changes
    std::vector<short> m_lower;
    std::vector<short> m_upper;
    float m_scale;
    bool m_init;
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
