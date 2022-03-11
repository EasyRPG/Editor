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
#include "movecommand.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	MoveCommand::MoveCommand(ProjectData& project, lcf::rpg::MoveCommand& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int MoveCommand::command_id() {
		return m_data.command_id;
	}
	void MoveCommand::set_command_id(const int& new_command_id) {
		if (m_data.command_id == new_command_id)
			return;
		m_data.command_id = new_command_id;
		emit command_id_changed();
	}

	QString MoveCommand::parameter_string() {
		return ToQString(m_data.parameter_string);
	}
	void MoveCommand::set_parameter_string(const QString& new_parameter_string) {
		if (ToQString(m_data.parameter_string) == new_parameter_string)
			return;
		m_data.parameter_string = ToDBString(new_parameter_string);
		emit parameter_string_changed();
	}

	int MoveCommand::parameter_a() {
		return m_data.parameter_a;
	}
	void MoveCommand::set_parameter_a(const int& new_parameter_a) {
		if (m_data.parameter_a == new_parameter_a)
			return;
		m_data.parameter_a = new_parameter_a;
		emit parameter_a_changed();
	}

	int MoveCommand::parameter_b() {
		return m_data.parameter_b;
	}
	void MoveCommand::set_parameter_b(const int& new_parameter_b) {
		if (m_data.parameter_b == new_parameter_b)
			return;
		m_data.parameter_b = new_parameter_b;
		emit parameter_b_changed();
	}

	int MoveCommand::parameter_c() {
		return m_data.parameter_c;
	}
	void MoveCommand::set_parameter_c(const int& new_parameter_c) {
		if (m_data.parameter_c == new_parameter_c)
			return;
		m_data.parameter_c = new_parameter_c;
		emit parameter_c_changed();
	}

} // namespace Binding::Generated
