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
#include <lcf/rpg/encounter.h>
#include "binding/binding_base.h"

class ProjectData;

/**
 * Binding::Generated::Encounter class.
 * Exposes lcf::rpg::Encounter to QML.
 */
namespace Binding::Generated {
class Encounter : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(int32_t troop_id READ troop_id CONSTANT)

public:
	Encounter(ProjectData& project, lcf::rpg::Encounter& data, QObject* parent = nullptr);

	lcf::rpg::Encounter& data();
	int id();
	int32_t troop_id();

signals:

protected:
	lcf::rpg::Encounter& m_data;
};
} // namespace Binding::Generated
