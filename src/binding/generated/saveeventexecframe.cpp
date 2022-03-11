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
#include "saveeventexecframe.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveEventExecFrame::SaveEventExecFrame(ProjectData& project, lcf::rpg::SaveEventExecFrame& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_commands = new ArrayAdapter(this);
			auto& arr = m_commands->data();
			for (auto& var: m_data.commands)
				arr.push_back(new Binding::EventCommand(m_project, var, this));
		}
	}
	int SaveEventExecFrame::id() {
		return m_data.ID;
	}
	ArrayAdapter* SaveEventExecFrame::commands() {
		return m_commands;
	}

	int SaveEventExecFrame::current_command() {
		return m_data.current_command;
	}
	void SaveEventExecFrame::set_current_command(const int& new_current_command) {
		if (m_data.current_command == new_current_command)
			return;
		m_data.current_command = new_current_command;
		emit current_command_changed();
	}

	int SaveEventExecFrame::event_id() {
		return m_data.event_id;
	}
	void SaveEventExecFrame::set_event_id(const int& new_event_id) {
		if (m_data.event_id == new_event_id)
			return;
		m_data.event_id = new_event_id;
		emit event_id_changed();
	}

	bool SaveEventExecFrame::triggered_by_decision_key() {
		return m_data.triggered_by_decision_key;
	}
	void SaveEventExecFrame::set_triggered_by_decision_key(const bool& new_triggered_by_decision_key) {
		if (m_data.triggered_by_decision_key == new_triggered_by_decision_key)
			return;
		m_data.triggered_by_decision_key = new_triggered_by_decision_key;
		emit triggered_by_decision_key_changed();
	}

	QVector<int> SaveEventExecFrame::subcommand_path() {
		return QVector<int>(m_data.subcommand_path.begin(), m_data.subcommand_path.end());
	}
	void SaveEventExecFrame::set_subcommand_path(const QVector<int>& new_subcommand_path) {
		if (QVector<int>(m_data.subcommand_path.begin(), m_data.subcommand_path.end()) == new_subcommand_path)
			return;
		m_data.subcommand_path = decltype(m_data.subcommand_path)(new_subcommand_path.begin(), new_subcommand_path.end());
		emit subcommand_path_changed();
	}

	int SaveEventExecFrame::maniac_event_info() {
		return m_data.maniac_event_info;
	}
	void SaveEventExecFrame::set_maniac_event_info(const int& new_maniac_event_info) {
		if (m_data.maniac_event_info == new_maniac_event_info)
			return;
		m_data.maniac_event_info = new_maniac_event_info;
		emit maniac_event_info_changed();
	}

	int SaveEventExecFrame::maniac_event_id() {
		return m_data.maniac_event_id;
	}
	void SaveEventExecFrame::set_maniac_event_id(const int& new_maniac_event_id) {
		if (m_data.maniac_event_id == new_maniac_event_id)
			return;
		m_data.maniac_event_id = new_maniac_event_id;
		emit maniac_event_id_changed();
	}

	int SaveEventExecFrame::maniac_event_page_id() {
		return m_data.maniac_event_page_id;
	}
	void SaveEventExecFrame::set_maniac_event_page_id(const int& new_maniac_event_page_id) {
		if (m_data.maniac_event_page_id == new_maniac_event_page_id)
			return;
		m_data.maniac_event_page_id = new_maniac_event_page_id;
		emit maniac_event_page_id_changed();
	}

	int SaveEventExecFrame::maniac_loop_info_size() {
		return m_data.maniac_loop_info_size;
	}
	void SaveEventExecFrame::set_maniac_loop_info_size(const int& new_maniac_loop_info_size) {
		if (m_data.maniac_loop_info_size == new_maniac_loop_info_size)
			return;
		m_data.maniac_loop_info_size = new_maniac_loop_info_size;
		emit maniac_loop_info_size_changed();
	}

	QVector<int> SaveEventExecFrame::maniac_loop_info() {
		return QVector<int>(m_data.maniac_loop_info.begin(), m_data.maniac_loop_info.end());
	}
	void SaveEventExecFrame::set_maniac_loop_info(const QVector<int>& new_maniac_loop_info) {
		if (QVector<int>(m_data.maniac_loop_info.begin(), m_data.maniac_loop_info.end()) == new_maniac_loop_info)
			return;
		m_data.maniac_loop_info = decltype(m_data.maniac_loop_info)(new_maniac_loop_info.begin(), new_maniac_loop_info.end());
		emit maniac_loop_info_changed();
	}

} // namespace Binding::Generated
