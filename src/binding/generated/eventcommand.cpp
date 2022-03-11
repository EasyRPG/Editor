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
#include "eventcommand.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	EventCommand::EventCommand(ProjectData& project, lcf::rpg::EventCommand& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int EventCommand::code() {
		return m_data.code;
	}
	void EventCommand::set_code(const int& new_code) {
		if (m_data.code == new_code)
			return;
		m_data.code = new_code;
		emit code_changed();
	}

	int EventCommand::indent() {
		return m_data.indent;
	}
	void EventCommand::set_indent(const int& new_indent) {
		if (m_data.indent == new_indent)
			return;
		m_data.indent = new_indent;
		emit indent_changed();
	}

	QString EventCommand::string() {
		return ToQString(m_data.string);
	}
	void EventCommand::set_string(const QString& new_string) {
		if (ToQString(m_data.string) == new_string)
			return;
		m_data.string = ToDBString(new_string);
		emit string_changed();
	}

	QVector<int> EventCommand::parameters() {
		return QVector<int>(m_data.parameters.begin(), m_data.parameters.end());
	}
	void EventCommand::set_parameters(const QVector<int>& new_parameters) {
		if (QVector<int>(m_data.parameters.begin(), m_data.parameters.end()) == new_parameters)
			return;
		m_data.parameters = decltype(m_data.parameters)(new_parameters.begin(), new_parameters.end());
		emit parameters_changed();
	}

} // namespace Binding::Generated
