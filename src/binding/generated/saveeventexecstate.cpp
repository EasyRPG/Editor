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
#include "saveeventexecstate.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveEventExecState::SaveEventExecState(ProjectData& project, lcf::rpg::SaveEventExecState& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_stack = new ArrayAdapter(this);
			auto& arr = m_stack->data();
			for (auto& var: m_data.stack)
				arr.push_back(new Binding::SaveEventExecFrame(m_project, var, this));
		}
	}
	ArrayAdapter* SaveEventExecState::stack() {
		return m_stack;
	}

	bool SaveEventExecState::show_message() {
		return m_data.show_message;
	}
	void SaveEventExecState::set_show_message(const bool& new_show_message) {
		if (m_data.show_message == new_show_message)
			return;
		m_data.show_message = new_show_message;
		emit show_message_changed();
	}

	bool SaveEventExecState::abort_on_escape() {
		return m_data.abort_on_escape;
	}
	void SaveEventExecState::set_abort_on_escape(const bool& new_abort_on_escape) {
		if (m_data.abort_on_escape == new_abort_on_escape)
			return;
		m_data.abort_on_escape = new_abort_on_escape;
		emit abort_on_escape_changed();
	}

	bool SaveEventExecState::wait_movement() {
		return m_data.wait_movement;
	}
	void SaveEventExecState::set_wait_movement(const bool& new_wait_movement) {
		if (m_data.wait_movement == new_wait_movement)
			return;
		m_data.wait_movement = new_wait_movement;
		emit wait_movement_changed();
	}

	bool SaveEventExecState::keyinput_wait() {
		return m_data.keyinput_wait;
	}
	void SaveEventExecState::set_keyinput_wait(const bool& new_keyinput_wait) {
		if (m_data.keyinput_wait == new_keyinput_wait)
			return;
		m_data.keyinput_wait = new_keyinput_wait;
		emit keyinput_wait_changed();
	}

	int SaveEventExecState::keyinput_variable() {
		return m_data.keyinput_variable;
	}
	void SaveEventExecState::set_keyinput_variable(const int& new_keyinput_variable) {
		if (m_data.keyinput_variable == new_keyinput_variable)
			return;
		m_data.keyinput_variable = new_keyinput_variable;
		emit keyinput_variable_changed();
	}

	bool SaveEventExecState::keyinput_all_directions() {
		return m_data.keyinput_all_directions;
	}
	void SaveEventExecState::set_keyinput_all_directions(const bool& new_keyinput_all_directions) {
		if (m_data.keyinput_all_directions == new_keyinput_all_directions)
			return;
		m_data.keyinput_all_directions = new_keyinput_all_directions;
		emit keyinput_all_directions_changed();
	}

	int SaveEventExecState::keyinput_decision() {
		return m_data.keyinput_decision;
	}
	void SaveEventExecState::set_keyinput_decision(const int& new_keyinput_decision) {
		if (m_data.keyinput_decision == new_keyinput_decision)
			return;
		m_data.keyinput_decision = new_keyinput_decision;
		emit keyinput_decision_changed();
	}

	int SaveEventExecState::keyinput_cancel() {
		return m_data.keyinput_cancel;
	}
	void SaveEventExecState::set_keyinput_cancel(const int& new_keyinput_cancel) {
		if (m_data.keyinput_cancel == new_keyinput_cancel)
			return;
		m_data.keyinput_cancel = new_keyinput_cancel;
		emit keyinput_cancel_changed();
	}

	int SaveEventExecState::keyinput_2kshift_2k3numbers() {
		return m_data.keyinput_2kshift_2k3numbers;
	}
	void SaveEventExecState::set_keyinput_2kshift_2k3numbers(const int& new_keyinput_2kshift_2k3numbers) {
		if (m_data.keyinput_2kshift_2k3numbers == new_keyinput_2kshift_2k3numbers)
			return;
		m_data.keyinput_2kshift_2k3numbers = new_keyinput_2kshift_2k3numbers;
		emit keyinput_2kshift_2k3numbers_changed();
	}

	int SaveEventExecState::keyinput_2kdown_2k3operators() {
		return m_data.keyinput_2kdown_2k3operators;
	}
	void SaveEventExecState::set_keyinput_2kdown_2k3operators(const int& new_keyinput_2kdown_2k3operators) {
		if (m_data.keyinput_2kdown_2k3operators == new_keyinput_2kdown_2k3operators)
			return;
		m_data.keyinput_2kdown_2k3operators = new_keyinput_2kdown_2k3operators;
		emit keyinput_2kdown_2k3operators_changed();
	}

	int SaveEventExecState::keyinput_2kleft_2k3shift() {
		return m_data.keyinput_2kleft_2k3shift;
	}
	void SaveEventExecState::set_keyinput_2kleft_2k3shift(const int& new_keyinput_2kleft_2k3shift) {
		if (m_data.keyinput_2kleft_2k3shift == new_keyinput_2kleft_2k3shift)
			return;
		m_data.keyinput_2kleft_2k3shift = new_keyinput_2kleft_2k3shift;
		emit keyinput_2kleft_2k3shift_changed();
	}

	int SaveEventExecState::keyinput_2kright() {
		return m_data.keyinput_2kright;
	}
	void SaveEventExecState::set_keyinput_2kright(const int& new_keyinput_2kright) {
		if (m_data.keyinput_2kright == new_keyinput_2kright)
			return;
		m_data.keyinput_2kright = new_keyinput_2kright;
		emit keyinput_2kright_changed();
	}

	int SaveEventExecState::keyinput_2kup() {
		return m_data.keyinput_2kup;
	}
	void SaveEventExecState::set_keyinput_2kup(const int& new_keyinput_2kup) {
		if (m_data.keyinput_2kup == new_keyinput_2kup)
			return;
		m_data.keyinput_2kup = new_keyinput_2kup;
		emit keyinput_2kup_changed();
	}

	int SaveEventExecState::wait_time() {
		return m_data.wait_time;
	}
	void SaveEventExecState::set_wait_time(const int& new_wait_time) {
		if (m_data.wait_time == new_wait_time)
			return;
		m_data.wait_time = new_wait_time;
		emit wait_time_changed();
	}

	int SaveEventExecState::keyinput_time_variable() {
		return m_data.keyinput_time_variable;
	}
	void SaveEventExecState::set_keyinput_time_variable(const int& new_keyinput_time_variable) {
		if (m_data.keyinput_time_variable == new_keyinput_time_variable)
			return;
		m_data.keyinput_time_variable = new_keyinput_time_variable;
		emit keyinput_time_variable_changed();
	}

	int SaveEventExecState::keyinput_2k3down() {
		return m_data.keyinput_2k3down;
	}
	void SaveEventExecState::set_keyinput_2k3down(const int& new_keyinput_2k3down) {
		if (m_data.keyinput_2k3down == new_keyinput_2k3down)
			return;
		m_data.keyinput_2k3down = new_keyinput_2k3down;
		emit keyinput_2k3down_changed();
	}

	int SaveEventExecState::keyinput_2k3left() {
		return m_data.keyinput_2k3left;
	}
	void SaveEventExecState::set_keyinput_2k3left(const int& new_keyinput_2k3left) {
		if (m_data.keyinput_2k3left == new_keyinput_2k3left)
			return;
		m_data.keyinput_2k3left = new_keyinput_2k3left;
		emit keyinput_2k3left_changed();
	}

	int SaveEventExecState::keyinput_2k3right() {
		return m_data.keyinput_2k3right;
	}
	void SaveEventExecState::set_keyinput_2k3right(const int& new_keyinput_2k3right) {
		if (m_data.keyinput_2k3right == new_keyinput_2k3right)
			return;
		m_data.keyinput_2k3right = new_keyinput_2k3right;
		emit keyinput_2k3right_changed();
	}

	int SaveEventExecState::keyinput_2k3up() {
		return m_data.keyinput_2k3up;
	}
	void SaveEventExecState::set_keyinput_2k3up(const int& new_keyinput_2k3up) {
		if (m_data.keyinput_2k3up == new_keyinput_2k3up)
			return;
		m_data.keyinput_2k3up = new_keyinput_2k3up;
		emit keyinput_2k3up_changed();
	}

	bool SaveEventExecState::keyinput_timed() {
		return m_data.keyinput_timed;
	}
	void SaveEventExecState::set_keyinput_timed(const bool& new_keyinput_timed) {
		if (m_data.keyinput_timed == new_keyinput_timed)
			return;
		m_data.keyinput_timed = new_keyinput_timed;
		emit keyinput_timed_changed();
	}

	bool SaveEventExecState::wait_key_enter() {
		return m_data.wait_key_enter;
	}
	void SaveEventExecState::set_wait_key_enter(const bool& new_wait_key_enter) {
		if (m_data.wait_key_enter == new_wait_key_enter)
			return;
		m_data.wait_key_enter = new_wait_key_enter;
		emit wait_key_enter_changed();
	}

} // namespace Binding::Generated
