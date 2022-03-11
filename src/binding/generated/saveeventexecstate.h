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
#include <lcf/rpg/saveeventexecstate.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/saveeventexecframe.h"

class ProjectData;

/**
 * Binding::Generated::SaveEventExecState class.
 * Exposes lcf::rpg::SaveEventExecState to QML.
 */
namespace Binding::Generated {
class SaveEventExecState : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(ArrayAdapter* stack READ stack CONSTANT)
	Q_PROPERTY(bool show_message READ show_message WRITE set_show_message NOTIFY show_message_changed)
	Q_PROPERTY(bool abort_on_escape READ abort_on_escape WRITE set_abort_on_escape NOTIFY abort_on_escape_changed)
	Q_PROPERTY(bool wait_movement READ wait_movement WRITE set_wait_movement NOTIFY wait_movement_changed)
	Q_PROPERTY(bool keyinput_wait READ keyinput_wait WRITE set_keyinput_wait NOTIFY keyinput_wait_changed)
	Q_PROPERTY(int keyinput_variable READ keyinput_variable WRITE set_keyinput_variable NOTIFY keyinput_variable_changed)
	Q_PROPERTY(bool keyinput_all_directions READ keyinput_all_directions WRITE set_keyinput_all_directions NOTIFY keyinput_all_directions_changed)
	Q_PROPERTY(int keyinput_decision READ keyinput_decision WRITE set_keyinput_decision NOTIFY keyinput_decision_changed)
	Q_PROPERTY(int keyinput_cancel READ keyinput_cancel WRITE set_keyinput_cancel NOTIFY keyinput_cancel_changed)
	Q_PROPERTY(int keyinput_2kshift_2k3numbers READ keyinput_2kshift_2k3numbers WRITE set_keyinput_2kshift_2k3numbers NOTIFY keyinput_2kshift_2k3numbers_changed)
	Q_PROPERTY(int keyinput_2kdown_2k3operators READ keyinput_2kdown_2k3operators WRITE set_keyinput_2kdown_2k3operators NOTIFY keyinput_2kdown_2k3operators_changed)
	Q_PROPERTY(int keyinput_2kleft_2k3shift READ keyinput_2kleft_2k3shift WRITE set_keyinput_2kleft_2k3shift NOTIFY keyinput_2kleft_2k3shift_changed)
	Q_PROPERTY(int keyinput_2kright READ keyinput_2kright WRITE set_keyinput_2kright NOTIFY keyinput_2kright_changed)
	Q_PROPERTY(int keyinput_2kup READ keyinput_2kup WRITE set_keyinput_2kup NOTIFY keyinput_2kup_changed)
	Q_PROPERTY(int wait_time READ wait_time WRITE set_wait_time NOTIFY wait_time_changed)
	Q_PROPERTY(int keyinput_time_variable READ keyinput_time_variable WRITE set_keyinput_time_variable NOTIFY keyinput_time_variable_changed)
	Q_PROPERTY(int keyinput_2k3down READ keyinput_2k3down WRITE set_keyinput_2k3down NOTIFY keyinput_2k3down_changed)
	Q_PROPERTY(int keyinput_2k3left READ keyinput_2k3left WRITE set_keyinput_2k3left NOTIFY keyinput_2k3left_changed)
	Q_PROPERTY(int keyinput_2k3right READ keyinput_2k3right WRITE set_keyinput_2k3right NOTIFY keyinput_2k3right_changed)
	Q_PROPERTY(int keyinput_2k3up READ keyinput_2k3up WRITE set_keyinput_2k3up NOTIFY keyinput_2k3up_changed)
	Q_PROPERTY(bool keyinput_timed READ keyinput_timed WRITE set_keyinput_timed NOTIFY keyinput_timed_changed)
	Q_PROPERTY(bool wait_key_enter READ wait_key_enter WRITE set_wait_key_enter NOTIFY wait_key_enter_changed)

public:
	SaveEventExecState(ProjectData& project, lcf::rpg::SaveEventExecState& data, QObject* parent = nullptr);

	lcf::rpg::SaveEventExecState& data();
	ArrayAdapter* stack();
	bool show_message();
	void set_show_message(const bool& new_show_message);
	bool abort_on_escape();
	void set_abort_on_escape(const bool& new_abort_on_escape);
	bool wait_movement();
	void set_wait_movement(const bool& new_wait_movement);
	bool keyinput_wait();
	void set_keyinput_wait(const bool& new_keyinput_wait);
	int keyinput_variable();
	void set_keyinput_variable(const int& new_keyinput_variable);
	bool keyinput_all_directions();
	void set_keyinput_all_directions(const bool& new_keyinput_all_directions);
	int keyinput_decision();
	void set_keyinput_decision(const int& new_keyinput_decision);
	int keyinput_cancel();
	void set_keyinput_cancel(const int& new_keyinput_cancel);
	int keyinput_2kshift_2k3numbers();
	void set_keyinput_2kshift_2k3numbers(const int& new_keyinput_2kshift_2k3numbers);
	int keyinput_2kdown_2k3operators();
	void set_keyinput_2kdown_2k3operators(const int& new_keyinput_2kdown_2k3operators);
	int keyinput_2kleft_2k3shift();
	void set_keyinput_2kleft_2k3shift(const int& new_keyinput_2kleft_2k3shift);
	int keyinput_2kright();
	void set_keyinput_2kright(const int& new_keyinput_2kright);
	int keyinput_2kup();
	void set_keyinput_2kup(const int& new_keyinput_2kup);
	int wait_time();
	void set_wait_time(const int& new_wait_time);
	int keyinput_time_variable();
	void set_keyinput_time_variable(const int& new_keyinput_time_variable);
	int keyinput_2k3down();
	void set_keyinput_2k3down(const int& new_keyinput_2k3down);
	int keyinput_2k3left();
	void set_keyinput_2k3left(const int& new_keyinput_2k3left);
	int keyinput_2k3right();
	void set_keyinput_2k3right(const int& new_keyinput_2k3right);
	int keyinput_2k3up();
	void set_keyinput_2k3up(const int& new_keyinput_2k3up);
	bool keyinput_timed();
	void set_keyinput_timed(const bool& new_keyinput_timed);
	bool wait_key_enter();
	void set_wait_key_enter(const bool& new_wait_key_enter);

signals:
	void show_message_changed();
	void abort_on_escape_changed();
	void wait_movement_changed();
	void keyinput_wait_changed();
	void keyinput_variable_changed();
	void keyinput_all_directions_changed();
	void keyinput_decision_changed();
	void keyinput_cancel_changed();
	void keyinput_2kshift_2k3numbers_changed();
	void keyinput_2kdown_2k3operators_changed();
	void keyinput_2kleft_2k3shift_changed();
	void keyinput_2kright_changed();
	void keyinput_2kup_changed();
	void wait_time_changed();
	void keyinput_time_variable_changed();
	void keyinput_2k3down_changed();
	void keyinput_2k3left_changed();
	void keyinput_2k3right_changed();
	void keyinput_2k3up_changed();
	void keyinput_timed_changed();
	void wait_key_enter_changed();

protected:
	lcf::rpg::SaveEventExecState& m_data;
	ArrayAdapter* m_stack;
};
} // namespace Binding::Generated
