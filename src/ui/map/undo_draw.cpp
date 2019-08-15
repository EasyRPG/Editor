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
