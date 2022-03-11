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
#include <lcf/rpg/trooppage.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/trooppagecondition.h"
#include "binding/eventcommand.h"

class ProjectData;

/**
 * Binding::Generated::TroopPage class.
 * Exposes lcf::rpg::TroopPage to QML.
 */
namespace Binding::Generated {
class TroopPage : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(Binding::TroopPageCondition* condition READ condition CONSTANT)
	Q_PROPERTY(ArrayAdapter* event_commands READ event_commands CONSTANT)

public:
	TroopPage(ProjectData& project, lcf::rpg::TroopPage& data, QObject* parent = nullptr);

	lcf::rpg::TroopPage& data();
	int id();
	Binding::TroopPageCondition* condition();
	ArrayAdapter* event_commands();

signals:

protected:
	lcf::rpg::TroopPage& m_data;
	Binding::TroopPageCondition* m_condition;
	ArrayAdapter* m_event_commands;
};
} // namespace Binding::Generated
