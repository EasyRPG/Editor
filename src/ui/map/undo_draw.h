#ifndef QUNDODRAW_H
#define QUNDODRAW_H

#include <QUndoCommand>
#include "core.h"
#include "map_scene.h"

class UndoDraw : public QUndoCommand
{
public:
	explicit UndoDraw(Core::Layer layer,
					   std::vector<short> data,
					   MapScene *scene,
					   QUndoCommand *parent = nullptr);

	void undo();
signals:

public slots:

private:
	Core::Layer m_layer;
	std::vector<short> m_data;
	MapScene* m_scene;
};

#endif // QUNDODRAW_H
