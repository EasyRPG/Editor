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
#include <lcf/rpg/moveroute.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/movecommand.h"

class ProjectData;

/**
 * Binding::Generated::MoveRoute class.
 * Exposes lcf::rpg::MoveRoute to QML.
 */
namespace Binding::Generated {
class MoveRoute : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(ArrayAdapter* move_commands READ move_commands CONSTANT)
	Q_PROPERTY(bool repeat READ repeat WRITE set_repeat NOTIFY repeat_changed)
	Q_PROPERTY(bool skippable READ skippable WRITE set_skippable NOTIFY skippable_changed)

public:
	MoveRoute(ProjectData& project, lcf::rpg::MoveRoute& data, QObject* parent = nullptr);

	lcf::rpg::MoveRoute& data();
	ArrayAdapter* move_commands();
	bool repeat();
	void set_repeat(const bool& new_repeat);
	bool skippable();
	void set_skippable(const bool& new_skippable);

signals:
	void repeat_changed();
	void skippable_changed();

protected:
	lcf::rpg::MoveRoute& m_data;
	ArrayAdapter* m_move_commands;
};
} // namespace Binding::Generated
