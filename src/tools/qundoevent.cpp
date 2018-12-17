#include "qundoevent.h"

QUndoEvent::QUndoEvent(RPG::Event data,
					   QGraphicsMapScene *scene,
					   QUndoCommand *parent) :
QUndoCommand(parent),
m_data(data),
m_scene(scene)
{}

void QUndoEvent::undo()
{
	m_scene->setEventData(m_data.ID, m_data);
}
