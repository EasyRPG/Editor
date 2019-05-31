/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

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

