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
#include "savemapevent.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveMapEvent::SaveMapEvent(ProjectData& project, lcf::rpg::SaveMapEvent& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_parallel_event_execstate = new Binding::SaveEventExecState(m_project, m_data.parallel_event_execstate, this);
	}
	int SaveMapEvent::id() {
		return m_data.ID;
	}
	bool SaveMapEvent::waiting_execution() {
		return m_data.waiting_execution;
	}
	void SaveMapEvent::set_waiting_execution(const bool& new_waiting_execution) {
		if (m_data.waiting_execution == new_waiting_execution)
			return;
		m_data.waiting_execution = new_waiting_execution;
		emit waiting_execution_changed();
	}

	int SaveMapEvent::original_move_route_index() {
		return m_data.original_move_route_index;
	}
	void SaveMapEvent::set_original_move_route_index(const int& new_original_move_route_index) {
		if (m_data.original_move_route_index == new_original_move_route_index)
			return;
		m_data.original_move_route_index = new_original_move_route_index;
		emit original_move_route_index_changed();
	}

	bool SaveMapEvent::triggered_by_decision_key() {
		return m_data.triggered_by_decision_key;
	}
	void SaveMapEvent::set_triggered_by_decision_key(const bool& new_triggered_by_decision_key) {
		if (m_data.triggered_by_decision_key == new_triggered_by_decision_key)
			return;
		m_data.triggered_by_decision_key = new_triggered_by_decision_key;
		emit triggered_by_decision_key_changed();
	}

	Binding::SaveEventExecState* SaveMapEvent::parallel_event_execstate() {
		return m_parallel_event_execstate;
	}

} // namespace Binding::Generated
