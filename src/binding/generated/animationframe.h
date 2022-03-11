/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
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

// Headers
#include <lcf/rpg/animationframe.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/animationcelldata.h"

class ProjectData;

/**
 * Binding::Generated::AnimationFrame class.
 * Exposes lcf::rpg::AnimationFrame to QML.
 */
namespace Binding::Generated {
class AnimationFrame : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(ArrayAdapter* cells READ cells CONSTANT)

public:
	AnimationFrame(ProjectData& project, lcf::rpg::AnimationFrame& data, QObject* parent = nullptr);

	lcf::rpg::AnimationFrame& data();
	int id();
	ArrayAdapter* cells();

signals:

protected:
	lcf::rpg::AnimationFrame& m_data;
	ArrayAdapter* m_cells;
};
} // namespace Binding::Generated
