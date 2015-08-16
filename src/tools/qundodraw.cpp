#include "qundodraw.h"

QUndoDraw::QUndoDraw(Core::Layer layer,
                     std::vector<short> data,
                     QGraphicsMapScene *scene,
                     QUndoCommand *parent) :
QUndoCommand(parent),
m_layer(layer),
m_data(data),
m_scene(scene)
{}

void QUndoDraw::undo()
{
    m_scene->setLayerData(m_layer, m_data);
}
