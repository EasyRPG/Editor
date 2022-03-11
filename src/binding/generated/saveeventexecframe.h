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
#include <lcf/rpg/saveeventexecframe.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/eventcommand.h"

class ProjectData;

/**
 * Binding::Generated::SaveEventExecFrame class.
 * Exposes lcf::rpg::SaveEventExecFrame to QML.
 */
namespace Binding::Generated {
class SaveEventExecFrame : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(ArrayAdapter* commands READ commands CONSTANT)
	Q_PROPERTY(int current_command READ current_command WRITE set_current_command NOTIFY current_command_changed)
	Q_PROPERTY(int event_id READ event_id WRITE set_event_id NOTIFY event_id_changed)
	Q_PROPERTY(bool triggered_by_decision_key READ triggered_by_decision_key WRITE set_triggered_by_decision_key NOTIFY triggered_by_decision_key_changed)
	Q_PROPERTY(QVector<int> subcommand_path READ subcommand_path WRITE set_subcommand_path NOTIFY subcommand_path_changed)
	Q_PROPERTY(int maniac_event_info READ maniac_event_info WRITE set_maniac_event_info NOTIFY maniac_event_info_changed)
	Q_PROPERTY(int maniac_event_id READ maniac_event_id WRITE set_maniac_event_id NOTIFY maniac_event_id_changed)
	Q_PROPERTY(int maniac_event_page_id READ maniac_event_page_id WRITE set_maniac_event_page_id NOTIFY maniac_event_page_id_changed)
	Q_PROPERTY(int maniac_loop_info_size READ maniac_loop_info_size WRITE set_maniac_loop_info_size NOTIFY maniac_loop_info_size_changed)
	Q_PROPERTY(QVector<int> maniac_loop_info READ maniac_loop_info WRITE set_maniac_loop_info NOTIFY maniac_loop_info_changed)

public:
	SaveEventExecFrame(ProjectData& project, lcf::rpg::SaveEventExecFrame& data, QObject* parent = nullptr);

	lcf::rpg::SaveEventExecFrame& data();
	int id();
	ArrayAdapter* commands();
	int current_command();
	void set_current_command(const int& new_current_command);
	int event_id();
	void set_event_id(const int& new_event_id);
	bool triggered_by_decision_key();
	void set_triggered_by_decision_key(const bool& new_triggered_by_decision_key);
	QVector<int> subcommand_path();
	void set_subcommand_path(const QVector<int>& new_subcommand_path);
	int maniac_event_info();
	void set_maniac_event_info(const int& new_maniac_event_info);
	int maniac_event_id();
	void set_maniac_event_id(const int& new_maniac_event_id);
	int maniac_event_page_id();
	void set_maniac_event_page_id(const int& new_maniac_event_page_id);
	int maniac_loop_info_size();
	void set_maniac_loop_info_size(const int& new_maniac_loop_info_size);
	QVector<int> maniac_loop_info();
	void set_maniac_loop_info(const QVector<int>& new_maniac_loop_info);

signals:
	void current_command_changed();
	void event_id_changed();
	void triggered_by_decision_key_changed();
	void subcommand_path_changed();
	void maniac_event_info_changed();
	void maniac_event_id_changed();
	void maniac_event_page_id_changed();
	void maniac_loop_info_size_changed();
	void maniac_loop_info_changed();

protected:
	lcf::rpg::SaveEventExecFrame& m_data;
	ArrayAdapter* m_commands;
};
} // namespace Binding::Generated
