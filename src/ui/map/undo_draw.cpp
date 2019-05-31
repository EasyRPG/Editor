#include "undo_draw.h"

UndoDraw::UndoDraw(Core::Layer layer,
					 std::vector<short> data,
					 MapScene *scene,
					 QUndoCommand *parent) :
QUndoCommand(parent),
m_layer(layer),
m_data(data),
m_scene(scene)
{}

void UndoDraw::undo()
{
	m_scene->setLayerData(m_layer, m_data);
}
