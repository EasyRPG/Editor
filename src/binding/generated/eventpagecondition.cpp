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
#include "eventpagecondition.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	EventPageCondition::EventPageCondition(ProjectData& project, lcf::rpg::EventPageCondition& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int EventPageCondition::switch_a_id() {
		return m_data.switch_a_id;
	}
	void EventPageCondition::set_switch_a_id(const int& new_switch_a_id) {
		if (m_data.switch_a_id == new_switch_a_id)
			return;
		m_data.switch_a_id = new_switch_a_id;
		emit switch_a_id_changed();
	}

	int EventPageCondition::switch_b_id() {
		return m_data.switch_b_id;
	}
	void EventPageCondition::set_switch_b_id(const int& new_switch_b_id) {
		if (m_data.switch_b_id == new_switch_b_id)
			return;
		m_data.switch_b_id = new_switch_b_id;
		emit switch_b_id_changed();
	}

	int EventPageCondition::variable_id() {
		return m_data.variable_id;
	}
	void EventPageCondition::set_variable_id(const int& new_variable_id) {
		if (m_data.variable_id == new_variable_id)
			return;
		m_data.variable_id = new_variable_id;
		emit variable_id_changed();
	}

	int EventPageCondition::variable_value() {
		return m_data.variable_value;
	}
	void EventPageCondition::set_variable_value(const int& new_variable_value) {
		if (m_data.variable_value == new_variable_value)
			return;
		m_data.variable_value = new_variable_value;
		emit variable_value_changed();
	}

	int EventPageCondition::item_id() {
		return m_data.item_id;
	}
	void EventPageCondition::set_item_id(const int& new_item_id) {
		if (m_data.item_id == new_item_id)
			return;
		m_data.item_id = new_item_id;
		emit item_id_changed();
	}

	int EventPageCondition::actor_id() {
		return m_data.actor_id;
	}
	void EventPageCondition::set_actor_id(const int& new_actor_id) {
		if (m_data.actor_id == new_actor_id)
			return;
		m_data.actor_id = new_actor_id;
		emit actor_id_changed();
	}

	int EventPageCondition::timer_sec() {
		return m_data.timer_sec;
	}
	void EventPageCondition::set_timer_sec(const int& new_timer_sec) {
		if (m_data.timer_sec == new_timer_sec)
			return;
		m_data.timer_sec = new_timer_sec;
		emit timer_sec_changed();
	}

	int EventPageCondition::timer2_sec() {
		return m_data.timer2_sec;
	}
	void EventPageCondition::set_timer2_sec(const int& new_timer2_sec) {
		if (m_data.timer2_sec == new_timer2_sec)
			return;
		m_data.timer2_sec = new_timer2_sec;
		emit timer2_sec_changed();
	}

	int EventPageCondition::compare_operator() {
		return m_data.compare_operator;
	}
	void EventPageCondition::set_compare_operator(const int& new_compare_operator) {
		if (m_data.compare_operator == new_compare_operator)
			return;
		m_data.compare_operator = new_compare_operator;
		emit compare_operator_changed();
	}

} // namespace Binding::Generated
