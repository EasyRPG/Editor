#ifndef QUNDODRAW_H
#define QUNDODRAW_H

#include <QUndoCommand>
#include "../core.h"
#include "qgraphicsmapscene.h"

class QUndoDraw : public QUndoCommand
{
public:
    explicit QUndoDraw(Layer layer,
                       std::vector<short> data,
                       QGraphicsMapScene *scene,
                       QUndoCommand *parent = 0);

    void undo();
signals:

public slots:

private:
    Layer m_layer;
    std::vector<short> m_data;
    QGraphicsMapScene* m_scene;
};

#endif // QUNDODRAW_H
