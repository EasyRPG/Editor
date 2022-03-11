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
#include "commonevent.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	CommonEvent::CommonEvent(ProjectData& project, lcf::rpg::CommonEvent& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_event_commands = new ArrayAdapter(this);
			auto& arr = m_event_commands->data();
			for (auto& var: m_data.event_commands)
				arr.push_back(new Binding::EventCommand(m_project, var, this));
		}
	}
	int CommonEvent::id() {
		return m_data.ID;
	}
	QString CommonEvent::name() {
		return ToQString(m_data.name);
	}
	void CommonEvent::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	int CommonEvent::trigger() {
		return m_data.trigger;
	}
	void CommonEvent::set_trigger(const int& new_trigger) {
		if (m_data.trigger == new_trigger)
			return;
		m_data.trigger = new_trigger;
		emit trigger_changed();
	}

	bool CommonEvent::switch_flag() {
		return m_data.switch_flag;
	}
	void CommonEvent::set_switch_flag(const bool& new_switch_flag) {
		if (m_data.switch_flag == new_switch_flag)
			return;
		m_data.switch_flag = new_switch_flag;
		emit switch_flag_changed();
	}

	int CommonEvent::switch_id() {
		return m_data.switch_id;
	}
	void CommonEvent::set_switch_id(const int& new_switch_id) {
		if (m_data.switch_id == new_switch_id)
			return;
		m_data.switch_id = new_switch_id;
		emit switch_id_changed();
	}

	ArrayAdapter* CommonEvent::event_commands() {
		return m_event_commands;
	}

} // namespace Binding::Generated
