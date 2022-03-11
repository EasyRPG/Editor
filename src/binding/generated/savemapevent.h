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
#include <lcf/rpg/savemapevent.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/saveeventexecstate.h"

class ProjectData;

/**
 * Binding::Generated::SaveMapEvent class.
 * Exposes lcf::rpg::SaveMapEvent to QML.
 */
namespace Binding::Generated {
class SaveMapEvent : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(bool waiting_execution READ waiting_execution WRITE set_waiting_execution NOTIFY waiting_execution_changed)
	Q_PROPERTY(int original_move_route_index READ original_move_route_index WRITE set_original_move_route_index NOTIFY original_move_route_index_changed)
	Q_PROPERTY(bool triggered_by_decision_key READ triggered_by_decision_key WRITE set_triggered_by_decision_key NOTIFY triggered_by_decision_key_changed)
	Q_PROPERTY(Binding::SaveEventExecState* parallel_event_execstate READ parallel_event_execstate CONSTANT)

public:
	SaveMapEvent(ProjectData& project, lcf::rpg::SaveMapEvent& data, QObject* parent = nullptr);

	lcf::rpg::SaveMapEvent& data();
	int id();
	bool waiting_execution();
	void set_waiting_execution(const bool& new_waiting_execution);
	int original_move_route_index();
	void set_original_move_route_index(const int& new_original_move_route_index);
	bool triggered_by_decision_key();
	void set_triggered_by_decision_key(const bool& new_triggered_by_decision_key);
	Binding::SaveEventExecState* parallel_event_execstate();

signals:
	void waiting_execution_changed();
	void original_move_route_index_changed();
	void triggered_by_decision_key_changed();

protected:
	lcf::rpg::SaveMapEvent& m_data;
	Binding::SaveEventExecState* m_parallel_event_execstate;
};
} // namespace Binding::Generated
