#ifndef QUNDOEVENT_H
#define QUNDOEVENT_H

#include <QUndoCommand>
#include <rpg_event.h>
#include "map_scene.h"

class UndoEvent : public QUndoCommand
{
public:
	explicit UndoEvent(RPG::Event data,
						MapScene *scene,
						QUndoCommand *parent = nullptr);
	void undo();

private:
	RPG::Event m_data;
	MapScene* m_scene;
};

#endif // QUNDOEVENT_H
