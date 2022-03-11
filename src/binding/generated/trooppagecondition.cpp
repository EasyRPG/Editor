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
#include "trooppagecondition.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	TroopPageCondition::TroopPageCondition(ProjectData& project, lcf::rpg::TroopPageCondition& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int TroopPageCondition::switch_a_id() {
		return m_data.switch_a_id;
	}
	void TroopPageCondition::set_switch_a_id(const int& new_switch_a_id) {
		if (m_data.switch_a_id == new_switch_a_id)
			return;
		m_data.switch_a_id = new_switch_a_id;
		emit switch_a_id_changed();
	}

	int TroopPageCondition::switch_b_id() {
		return m_data.switch_b_id;
	}
	void TroopPageCondition::set_switch_b_id(const int& new_switch_b_id) {
		if (m_data.switch_b_id == new_switch_b_id)
			return;
		m_data.switch_b_id = new_switch_b_id;
		emit switch_b_id_changed();
	}

	int TroopPageCondition::variable_id() {
		return m_data.variable_id;
	}
	void TroopPageCondition::set_variable_id(const int& new_variable_id) {
		if (m_data.variable_id == new_variable_id)
			return;
		m_data.variable_id = new_variable_id;
		emit variable_id_changed();
	}

	int TroopPageCondition::variable_value() {
		return m_data.variable_value;
	}
	void TroopPageCondition::set_variable_value(const int& new_variable_value) {
		if (m_data.variable_value == new_variable_value)
			return;
		m_data.variable_value = new_variable_value;
		emit variable_value_changed();
	}

	int TroopPageCondition::turn_a() {
		return m_data.turn_a;
	}
	void TroopPageCondition::set_turn_a(const int& new_turn_a) {
		if (m_data.turn_a == new_turn_a)
			return;
		m_data.turn_a = new_turn_a;
		emit turn_a_changed();
	}

	int TroopPageCondition::turn_b() {
		return m_data.turn_b;
	}
	void TroopPageCondition::set_turn_b(const int& new_turn_b) {
		if (m_data.turn_b == new_turn_b)
			return;
		m_data.turn_b = new_turn_b;
		emit turn_b_changed();
	}

	int TroopPageCondition::fatigue_min() {
		return m_data.fatigue_min;
	}
	void TroopPageCondition::set_fatigue_min(const int& new_fatigue_min) {
		if (m_data.fatigue_min == new_fatigue_min)
			return;
		m_data.fatigue_min = new_fatigue_min;
		emit fatigue_min_changed();
	}

	int TroopPageCondition::fatigue_max() {
		return m_data.fatigue_max;
	}
	void TroopPageCondition::set_fatigue_max(const int& new_fatigue_max) {
		if (m_data.fatigue_max == new_fatigue_max)
			return;
		m_data.fatigue_max = new_fatigue_max;
		emit fatigue_max_changed();
	}

	int TroopPageCondition::enemy_id() {
		return m_data.enemy_id;
	}
	void TroopPageCondition::set_enemy_id(const int& new_enemy_id) {
		if (m_data.enemy_id == new_enemy_id)
			return;
		m_data.enemy_id = new_enemy_id;
		emit enemy_id_changed();
	}

	int TroopPageCondition::enemy_hp_min() {
		return m_data.enemy_hp_min;
	}
	void TroopPageCondition::set_enemy_hp_min(const int& new_enemy_hp_min) {
		if (m_data.enemy_hp_min == new_enemy_hp_min)
			return;
		m_data.enemy_hp_min = new_enemy_hp_min;
		emit enemy_hp_min_changed();
	}

	int TroopPageCondition::enemy_hp_max() {
		return m_data.enemy_hp_max;
	}
	void TroopPageCondition::set_enemy_hp_max(const int& new_enemy_hp_max) {
		if (m_data.enemy_hp_max == new_enemy_hp_max)
			return;
		m_data.enemy_hp_max = new_enemy_hp_max;
		emit enemy_hp_max_changed();
	}

	int TroopPageCondition::actor_id() {
		return m_data.actor_id;
	}
	void TroopPageCondition::set_actor_id(const int& new_actor_id) {
		if (m_data.actor_id == new_actor_id)
			return;
		m_data.actor_id = new_actor_id;
		emit actor_id_changed();
	}

	int TroopPageCondition::actor_hp_min() {
		return m_data.actor_hp_min;
	}
	void TroopPageCondition::set_actor_hp_min(const int& new_actor_hp_min) {
		if (m_data.actor_hp_min == new_actor_hp_min)
			return;
		m_data.actor_hp_min = new_actor_hp_min;
		emit actor_hp_min_changed();
	}

	int TroopPageCondition::actor_hp_max() {
		return m_data.actor_hp_max;
	}
	void TroopPageCondition::set_actor_hp_max(const int& new_actor_hp_max) {
		if (m_data.actor_hp_max == new_actor_hp_max)
			return;
		m_data.actor_hp_max = new_actor_hp_max;
		emit actor_hp_max_changed();
	}

	int TroopPageCondition::turn_enemy_id() {
		return m_data.turn_enemy_id;
	}
	void TroopPageCondition::set_turn_enemy_id(const int& new_turn_enemy_id) {
		if (m_data.turn_enemy_id == new_turn_enemy_id)
			return;
		m_data.turn_enemy_id = new_turn_enemy_id;
		emit turn_enemy_id_changed();
	}

	int TroopPageCondition::turn_enemy_a() {
		return m_data.turn_enemy_a;
	}
	void TroopPageCondition::set_turn_enemy_a(const int& new_turn_enemy_a) {
		if (m_data.turn_enemy_a == new_turn_enemy_a)
			return;
		m_data.turn_enemy_a = new_turn_enemy_a;
		emit turn_enemy_a_changed();
	}

	int TroopPageCondition::turn_enemy_b() {
		return m_data.turn_enemy_b;
	}
	void TroopPageCondition::set_turn_enemy_b(const int& new_turn_enemy_b) {
		if (m_data.turn_enemy_b == new_turn_enemy_b)
			return;
		m_data.turn_enemy_b = new_turn_enemy_b;
		emit turn_enemy_b_changed();
	}

	int TroopPageCondition::turn_actor_id() {
		return m_data.turn_actor_id;
	}
	void TroopPageCondition::set_turn_actor_id(const int& new_turn_actor_id) {
		if (m_data.turn_actor_id == new_turn_actor_id)
			return;
		m_data.turn_actor_id = new_turn_actor_id;
		emit turn_actor_id_changed();
	}

	int TroopPageCondition::turn_actor_a() {
		return m_data.turn_actor_a;
	}
	void TroopPageCondition::set_turn_actor_a(const int& new_turn_actor_a) {
		if (m_data.turn_actor_a == new_turn_actor_a)
			return;
		m_data.turn_actor_a = new_turn_actor_a;
		emit turn_actor_a_changed();
	}

	int TroopPageCondition::turn_actor_b() {
		return m_data.turn_actor_b;
	}
	void TroopPageCondition::set_turn_actor_b(const int& new_turn_actor_b) {
		if (m_data.turn_actor_b == new_turn_actor_b)
			return;
		m_data.turn_actor_b = new_turn_actor_b;
		emit turn_actor_b_changed();
	}

	int TroopPageCondition::command_actor_id() {
		return m_data.command_actor_id;
	}
	void TroopPageCondition::set_command_actor_id(const int& new_command_actor_id) {
		if (m_data.command_actor_id == new_command_actor_id)
			return;
		m_data.command_actor_id = new_command_actor_id;
		emit command_actor_id_changed();
	}

	int TroopPageCondition::command_id() {
		return m_data.command_id;
	}
	void TroopPageCondition::set_command_id(const int& new_command_id) {
		if (m_data.command_id == new_command_id)
			return;
		m_data.command_id = new_command_id;
		emit command_id_changed();
	}

} // namespace Binding::Generated
