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
#include "enemyaction.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	EnemyAction::EnemyAction(ProjectData& project, lcf::rpg::EnemyAction& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int EnemyAction::id() {
		return m_data.ID;
	}
	int32_t EnemyAction::kind() {
		return m_data.kind;
	}

	int32_t EnemyAction::basic() {
		return m_data.basic;
	}

	int32_t EnemyAction::skill_id() {
		return m_data.skill_id;
	}

	int32_t EnemyAction::enemy_id() {
		return m_data.enemy_id;
	}

	int32_t EnemyAction::condition_type() {
		return m_data.condition_type;
	}

	int EnemyAction::condition_param1() {
		return m_data.condition_param1;
	}
	void EnemyAction::set_condition_param1(const int& new_condition_param1) {
		if (m_data.condition_param1 == new_condition_param1)
			return;
		m_data.condition_param1 = new_condition_param1;
		emit condition_param1_changed();
	}

	int EnemyAction::condition_param2() {
		return m_data.condition_param2;
	}
	void EnemyAction::set_condition_param2(const int& new_condition_param2) {
		if (m_data.condition_param2 == new_condition_param2)
			return;
		m_data.condition_param2 = new_condition_param2;
		emit condition_param2_changed();
	}

	int32_t EnemyAction::switch_id() {
		return m_data.switch_id;
	}

	bool EnemyAction::switch_on() {
		return m_data.switch_on;
	}
	void EnemyAction::set_switch_on(const bool& new_switch_on) {
		if (m_data.switch_on == new_switch_on)
			return;
		m_data.switch_on = new_switch_on;
		emit switch_on_changed();
	}

	int32_t EnemyAction::switch_on_id() {
		return m_data.switch_on_id;
	}

	bool EnemyAction::switch_off() {
		return m_data.switch_off;
	}
	void EnemyAction::set_switch_off(const bool& new_switch_off) {
		if (m_data.switch_off == new_switch_off)
			return;
		m_data.switch_off = new_switch_off;
		emit switch_off_changed();
	}

	int32_t EnemyAction::switch_off_id() {
		return m_data.switch_off_id;
	}

	int EnemyAction::rating() {
		return m_data.rating;
	}
	void EnemyAction::set_rating(const int& new_rating) {
		if (m_data.rating == new_rating)
			return;
		m_data.rating = new_rating;
		emit rating_changed();
	}

} // namespace Binding::Generated
