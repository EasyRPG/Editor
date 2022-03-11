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
	int EnemyAction::kind() {
		return m_data.kind;
	}
	void EnemyAction::set_kind(const int& new_kind) {
		if (m_data.kind == new_kind)
			return;
		m_data.kind = new_kind;
		emit kind_changed();
	}

	int EnemyAction::basic() {
		return m_data.basic;
	}
	void EnemyAction::set_basic(const int& new_basic) {
		if (m_data.basic == new_basic)
			return;
		m_data.basic = new_basic;
		emit basic_changed();
	}

	int EnemyAction::skill_id() {
		return m_data.skill_id;
	}
	void EnemyAction::set_skill_id(const int& new_skill_id) {
		if (m_data.skill_id == new_skill_id)
			return;
		m_data.skill_id = new_skill_id;
		emit skill_id_changed();
	}

	int EnemyAction::enemy_id() {
		return m_data.enemy_id;
	}
	void EnemyAction::set_enemy_id(const int& new_enemy_id) {
		if (m_data.enemy_id == new_enemy_id)
			return;
		m_data.enemy_id = new_enemy_id;
		emit enemy_id_changed();
	}

	int EnemyAction::condition_type() {
		return m_data.condition_type;
	}
	void EnemyAction::set_condition_type(const int& new_condition_type) {
		if (m_data.condition_type == new_condition_type)
			return;
		m_data.condition_type = new_condition_type;
		emit condition_type_changed();
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

	int EnemyAction::switch_id() {
		return m_data.switch_id;
	}
	void EnemyAction::set_switch_id(const int& new_switch_id) {
		if (m_data.switch_id == new_switch_id)
			return;
		m_data.switch_id = new_switch_id;
		emit switch_id_changed();
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

	int EnemyAction::switch_on_id() {
		return m_data.switch_on_id;
	}
	void EnemyAction::set_switch_on_id(const int& new_switch_on_id) {
		if (m_data.switch_on_id == new_switch_on_id)
			return;
		m_data.switch_on_id = new_switch_on_id;
		emit switch_on_id_changed();
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

	int EnemyAction::switch_off_id() {
		return m_data.switch_off_id;
	}
	void EnemyAction::set_switch_off_id(const int& new_switch_off_id) {
		if (m_data.switch_off_id == new_switch_off_id)
			return;
		m_data.switch_off_id = new_switch_off_id;
		emit switch_off_id_changed();
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
