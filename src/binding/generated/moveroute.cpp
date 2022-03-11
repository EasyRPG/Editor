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

// Headers
#include "moveroute.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	MoveRoute::MoveRoute(ProjectData& project, lcf::rpg::MoveRoute& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_move_commands = new ArrayAdapter(this);
			auto& arr = m_move_commands->data();
			for (auto& var: m_data.move_commands)
				arr.push_back(new Binding::MoveCommand(m_project, var, this));
		}
	}
	ArrayAdapter* MoveRoute::move_commands() {
		return m_move_commands;
	}

	bool MoveRoute::repeat() {
		return m_data.repeat;
	}
	void MoveRoute::set_repeat(const bool& new_repeat) {
		if (m_data.repeat == new_repeat)
			return;
		m_data.repeat = new_repeat;
		emit repeat_changed();
	}

	bool MoveRoute::skippable() {
		return m_data.skippable;
	}
	void MoveRoute::set_skippable(const bool& new_skippable) {
		if (m_data.skippable == new_skippable)
			return;
		m_data.skippable = new_skippable;
		emit skippable_changed();
	}

} // namespace Binding::Generated
