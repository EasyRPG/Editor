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
#include "class.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Class::Class(ProjectData& project, lcf::rpg::Class& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_parameters = new Binding::Parameters(m_project, m_data.parameters, this);
		for (auto& var: m_data.skills) {
			m_skills.push_back(new Binding::Learning(m_project, var, this));
		}
	}
	int Class::id() {
		return m_data.ID;
	}
	QString Class::name() {
		return ToQString(m_data.name);
	}
	void Class::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	bool Class::two_weapon() {
		return m_data.two_weapon;
	}
	void Class::set_two_weapon(const bool& new_two_weapon) {
		if (m_data.two_weapon == new_two_weapon)
			return;
		m_data.two_weapon = new_two_weapon;
		emit two_weapon_changed();
	}

	bool Class::lock_equipment() {
		return m_data.lock_equipment;
	}
	void Class::set_lock_equipment(const bool& new_lock_equipment) {
		if (m_data.lock_equipment == new_lock_equipment)
			return;
		m_data.lock_equipment = new_lock_equipment;
		emit lock_equipment_changed();
	}

	bool Class::auto_battle() {
		return m_data.auto_battle;
	}
	void Class::set_auto_battle(const bool& new_auto_battle) {
		if (m_data.auto_battle == new_auto_battle)
			return;
		m_data.auto_battle = new_auto_battle;
		emit auto_battle_changed();
	}

	bool Class::super_guard() {
		return m_data.super_guard;
	}
	void Class::set_super_guard(const bool& new_super_guard) {
		if (m_data.super_guard == new_super_guard)
			return;
		m_data.super_guard = new_super_guard;
		emit super_guard_changed();
	}

	Binding::Parameters* Class::parameters() {
		return m_parameters;
	}

	int Class::exp_base() {
		return m_data.exp_base;
	}
	void Class::set_exp_base(const int& new_exp_base) {
		if (m_data.exp_base == new_exp_base)
			return;
		m_data.exp_base = new_exp_base;
		emit exp_base_changed();
	}

	int Class::exp_inflation() {
		return m_data.exp_inflation;
	}
	void Class::set_exp_inflation(const int& new_exp_inflation) {
		if (m_data.exp_inflation == new_exp_inflation)
			return;
		m_data.exp_inflation = new_exp_inflation;
		emit exp_inflation_changed();
	}

	int Class::exp_correction() {
		return m_data.exp_correction;
	}
	void Class::set_exp_correction(const int& new_exp_correction) {
		if (m_data.exp_correction == new_exp_correction)
			return;
		m_data.exp_correction = new_exp_correction;
		emit exp_correction_changed();
	}

	int32_t Class::battler_animation() {
		return m_data.battler_animation;
	}

	QVector<Binding::Learning*>& Class::skills() {
		return m_skills;
	}

	QVector<int> Class::state_ranks() {
		return QVector<int>(m_data.state_ranks.begin(), m_data.state_ranks.end());
	}
	void Class::set_state_ranks(const QVector<int>& new_state_ranks) {
		if (QVector<int>(m_data.state_ranks.begin(), m_data.state_ranks.end()) == new_state_ranks)
			return;
		m_data.state_ranks = decltype(m_data.state_ranks)(new_state_ranks.begin(), new_state_ranks.end());
		emit state_ranks_changed();
	}

	QVector<int> Class::attribute_ranks() {
		return QVector<int>(m_data.attribute_ranks.begin(), m_data.attribute_ranks.end());
	}
	void Class::set_attribute_ranks(const QVector<int>& new_attribute_ranks) {
		if (QVector<int>(m_data.attribute_ranks.begin(), m_data.attribute_ranks.end()) == new_attribute_ranks)
			return;
		m_data.attribute_ranks = decltype(m_data.attribute_ranks)(new_attribute_ranks.begin(), new_attribute_ranks.end());
		emit attribute_ranks_changed();
	}

	QVector<int> Class::battle_commands() {
		return QVector<int>(m_data.battle_commands.begin(), m_data.battle_commands.end());
	}
	void Class::set_battle_commands(const QVector<int>& new_battle_commands) {
		if (QVector<int>(m_data.battle_commands.begin(), m_data.battle_commands.end()) == new_battle_commands)
			return;
		m_data.battle_commands = decltype(m_data.battle_commands)(new_battle_commands.begin(), new_battle_commands.end());
		emit battle_commands_changed();
	}

} // namespace Binding::Generated
