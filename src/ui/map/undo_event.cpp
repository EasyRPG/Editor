#include "undo_event.h"

UndoEvent::UndoEvent(RPG::Event data,
					   MapScene *scene,
					   QUndoCommand *parent) :
QUndoCommand(parent),
m_data(data),
m_scene(scene)
{}

void UndoEvent::undo()
{
	m_scene->setEventData(m_data.ID, m_data);
}
