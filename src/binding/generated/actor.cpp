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
#include "actor.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Actor::Actor(ProjectData& project, lcf::rpg::Actor& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_parameters = new Binding::Parameters(m_project, m_data.parameters, this);
		m_initial_equipment = new Binding::Equipment(m_project, m_data.initial_equipment, this);
		{
			m_skills = new ArrayAdapter(this);
			auto& arr = m_skills->data();
			for (auto& var: m_data.skills)
				arr.push_back(new Binding::Learning(m_project, var, this));
		}
	}
	int Actor::id() {
		return m_data.ID;
	}
	QString Actor::name() {
		return ToQString(m_data.name);
	}
	void Actor::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	QString Actor::title() {
		return ToQString(m_data.title);
	}
	void Actor::set_title(const QString& new_title) {
		if (ToQString(m_data.title) == new_title)
			return;
		m_data.title = ToDBString(new_title);
		emit title_changed();
	}

	QString Actor::character_name() {
		return ToQString(m_data.character_name);
	}
	void Actor::set_character_name(const QString& new_character_name) {
		if (ToQString(m_data.character_name) == new_character_name)
			return;
		m_data.character_name = ToDBString(new_character_name);
		emit character_name_changed();
	}

	int Actor::character_index() {
		return m_data.character_index;
	}
	void Actor::set_character_index(const int& new_character_index) {
		if (m_data.character_index == new_character_index)
			return;
		m_data.character_index = new_character_index;
		emit character_index_changed();
	}

	bool Actor::transparent() {
		return m_data.transparent;
	}
	void Actor::set_transparent(const bool& new_transparent) {
		if (m_data.transparent == new_transparent)
			return;
		m_data.transparent = new_transparent;
		emit transparent_changed();
	}

	int Actor::initial_level() {
		return m_data.initial_level;
	}
	void Actor::set_initial_level(const int& new_initial_level) {
		if (m_data.initial_level == new_initial_level)
			return;
		m_data.initial_level = new_initial_level;
		emit initial_level_changed();
	}

	int Actor::final_level() {
		return m_data.final_level;
	}
	void Actor::set_final_level(const int& new_final_level) {
		if (m_data.final_level == new_final_level)
			return;
		m_data.final_level = new_final_level;
		emit final_level_changed();
	}

	bool Actor::critical_hit() {
		return m_data.critical_hit;
	}
	void Actor::set_critical_hit(const bool& new_critical_hit) {
		if (m_data.critical_hit == new_critical_hit)
			return;
		m_data.critical_hit = new_critical_hit;
		emit critical_hit_changed();
	}

	int Actor::critical_hit_chance() {
		return m_data.critical_hit_chance;
	}
	void Actor::set_critical_hit_chance(const int& new_critical_hit_chance) {
		if (m_data.critical_hit_chance == new_critical_hit_chance)
			return;
		m_data.critical_hit_chance = new_critical_hit_chance;
		emit critical_hit_chance_changed();
	}

	QString Actor::face_name() {
		return ToQString(m_data.face_name);
	}
	void Actor::set_face_name(const QString& new_face_name) {
		if (ToQString(m_data.face_name) == new_face_name)
			return;
		m_data.face_name = ToDBString(new_face_name);
		emit face_name_changed();
	}

	int Actor::face_index() {
		return m_data.face_index;
	}
	void Actor::set_face_index(const int& new_face_index) {
		if (m_data.face_index == new_face_index)
			return;
		m_data.face_index = new_face_index;
		emit face_index_changed();
	}

	bool Actor::two_weapon() {
		return m_data.two_weapon;
	}
	void Actor::set_two_weapon(const bool& new_two_weapon) {
		if (m_data.two_weapon == new_two_weapon)
			return;
		m_data.two_weapon = new_two_weapon;
		emit two_weapon_changed();
	}

	bool Actor::lock_equipment() {
		return m_data.lock_equipment;
	}
	void Actor::set_lock_equipment(const bool& new_lock_equipment) {
		if (m_data.lock_equipment == new_lock_equipment)
			return;
		m_data.lock_equipment = new_lock_equipment;
		emit lock_equipment_changed();
	}

	bool Actor::auto_battle() {
		return m_data.auto_battle;
	}
	void Actor::set_auto_battle(const bool& new_auto_battle) {
		if (m_data.auto_battle == new_auto_battle)
			return;
		m_data.auto_battle = new_auto_battle;
		emit auto_battle_changed();
	}

	bool Actor::super_guard() {
		return m_data.super_guard;
	}
	void Actor::set_super_guard(const bool& new_super_guard) {
		if (m_data.super_guard == new_super_guard)
			return;
		m_data.super_guard = new_super_guard;
		emit super_guard_changed();
	}

	Binding::Parameters* Actor::parameters() {
		return m_parameters;
	}

	int Actor::exp_base() {
		return m_data.exp_base;
	}
	void Actor::set_exp_base(const int& new_exp_base) {
		if (m_data.exp_base == new_exp_base)
			return;
		m_data.exp_base = new_exp_base;
		emit exp_base_changed();
	}

	int Actor::exp_inflation() {
		return m_data.exp_inflation;
	}
	void Actor::set_exp_inflation(const int& new_exp_inflation) {
		if (m_data.exp_inflation == new_exp_inflation)
			return;
		m_data.exp_inflation = new_exp_inflation;
		emit exp_inflation_changed();
	}

	int Actor::exp_correction() {
		return m_data.exp_correction;
	}
	void Actor::set_exp_correction(const int& new_exp_correction) {
		if (m_data.exp_correction == new_exp_correction)
			return;
		m_data.exp_correction = new_exp_correction;
		emit exp_correction_changed();
	}

	Binding::Equipment* Actor::initial_equipment() {
		return m_initial_equipment;
	}

	int Actor::unarmed_animation() {
		return m_data.unarmed_animation;
	}
	void Actor::set_unarmed_animation(const int& new_unarmed_animation) {
		if (m_data.unarmed_animation == new_unarmed_animation)
			return;
		m_data.unarmed_animation = new_unarmed_animation;
		emit unarmed_animation_changed();
	}

	int Actor::class_id() {
		return m_data.class_id;
	}
	void Actor::set_class_id(const int& new_class_id) {
		if (m_data.class_id == new_class_id)
			return;
		m_data.class_id = new_class_id;
		emit class_id_changed();
	}

	int Actor::battle_x() {
		return m_data.battle_x;
	}
	void Actor::set_battle_x(const int& new_battle_x) {
		if (m_data.battle_x == new_battle_x)
			return;
		m_data.battle_x = new_battle_x;
		emit battle_x_changed();
	}

	int Actor::battle_y() {
		return m_data.battle_y;
	}
	void Actor::set_battle_y(const int& new_battle_y) {
		if (m_data.battle_y == new_battle_y)
			return;
		m_data.battle_y = new_battle_y;
		emit battle_y_changed();
	}

	int Actor::battler_animation() {
		return m_data.battler_animation;
	}
	void Actor::set_battler_animation(const int& new_battler_animation) {
		if (m_data.battler_animation == new_battler_animation)
			return;
		m_data.battler_animation = new_battler_animation;
		emit battler_animation_changed();
	}

	ArrayAdapter* Actor::skills() {
		return m_skills;
	}

	bool Actor::rename_skill() {
		return m_data.rename_skill;
	}
	void Actor::set_rename_skill(const bool& new_rename_skill) {
		if (m_data.rename_skill == new_rename_skill)
			return;
		m_data.rename_skill = new_rename_skill;
		emit rename_skill_changed();
	}

	QString Actor::skill_name() {
		return ToQString(m_data.skill_name);
	}
	void Actor::set_skill_name(const QString& new_skill_name) {
		if (ToQString(m_data.skill_name) == new_skill_name)
			return;
		m_data.skill_name = ToDBString(new_skill_name);
		emit skill_name_changed();
	}

	QVector<int> Actor::state_ranks() {
		return QVector<int>(m_data.state_ranks.begin(), m_data.state_ranks.end());
	}
	void Actor::set_state_ranks(const QVector<int>& new_state_ranks) {
		if (QVector<int>(m_data.state_ranks.begin(), m_data.state_ranks.end()) == new_state_ranks)
			return;
		m_data.state_ranks = decltype(m_data.state_ranks)(new_state_ranks.begin(), new_state_ranks.end());
		emit state_ranks_changed();
	}

	QVector<int> Actor::attribute_ranks() {
		return QVector<int>(m_data.attribute_ranks.begin(), m_data.attribute_ranks.end());
	}
	void Actor::set_attribute_ranks(const QVector<int>& new_attribute_ranks) {
		if (QVector<int>(m_data.attribute_ranks.begin(), m_data.attribute_ranks.end()) == new_attribute_ranks)
			return;
		m_data.attribute_ranks = decltype(m_data.attribute_ranks)(new_attribute_ranks.begin(), new_attribute_ranks.end());
		emit attribute_ranks_changed();
	}

	QVector<int> Actor::battle_commands() {
		return QVector<int>(m_data.battle_commands.begin(), m_data.battle_commands.end());
	}
	void Actor::set_battle_commands(const QVector<int>& new_battle_commands) {
		if (QVector<int>(m_data.battle_commands.begin(), m_data.battle_commands.end()) == new_battle_commands)
			return;
		m_data.battle_commands = decltype(m_data.battle_commands)(new_battle_commands.begin(), new_battle_commands.end());
		emit battle_commands_changed();
	}

	int Actor::easyrpg_actorai() {
		return m_data.easyrpg_actorai;
	}
	void Actor::set_easyrpg_actorai(const int& new_easyrpg_actorai) {
		if (m_data.easyrpg_actorai == new_easyrpg_actorai)
			return;
		m_data.easyrpg_actorai = new_easyrpg_actorai;
		emit easyrpg_actorai_changed();
	}

	bool Actor::easyrpg_prevent_critical() {
		return m_data.easyrpg_prevent_critical;
	}
	void Actor::set_easyrpg_prevent_critical(const bool& new_easyrpg_prevent_critical) {
		if (m_data.easyrpg_prevent_critical == new_easyrpg_prevent_critical)
			return;
		m_data.easyrpg_prevent_critical = new_easyrpg_prevent_critical;
		emit easyrpg_prevent_critical_changed();
	}

	bool Actor::easyrpg_raise_evasion() {
		return m_data.easyrpg_raise_evasion;
	}
	void Actor::set_easyrpg_raise_evasion(const bool& new_easyrpg_raise_evasion) {
		if (m_data.easyrpg_raise_evasion == new_easyrpg_raise_evasion)
			return;
		m_data.easyrpg_raise_evasion = new_easyrpg_raise_evasion;
		emit easyrpg_raise_evasion_changed();
	}

	bool Actor::easyrpg_immune_to_attribute_downshifts() {
		return m_data.easyrpg_immune_to_attribute_downshifts;
	}
	void Actor::set_easyrpg_immune_to_attribute_downshifts(const bool& new_easyrpg_immune_to_attribute_downshifts) {
		if (m_data.easyrpg_immune_to_attribute_downshifts == new_easyrpg_immune_to_attribute_downshifts)
			return;
		m_data.easyrpg_immune_to_attribute_downshifts = new_easyrpg_immune_to_attribute_downshifts;
		emit easyrpg_immune_to_attribute_downshifts_changed();
	}

	bool Actor::easyrpg_ignore_evasion() {
		return m_data.easyrpg_ignore_evasion;
	}
	void Actor::set_easyrpg_ignore_evasion(const bool& new_easyrpg_ignore_evasion) {
		if (m_data.easyrpg_ignore_evasion == new_easyrpg_ignore_evasion)
			return;
		m_data.easyrpg_ignore_evasion = new_easyrpg_ignore_evasion;
		emit easyrpg_ignore_evasion_changed();
	}

	int Actor::easyrpg_unarmed_hit() {
		return m_data.easyrpg_unarmed_hit;
	}
	void Actor::set_easyrpg_unarmed_hit(const int& new_easyrpg_unarmed_hit) {
		if (m_data.easyrpg_unarmed_hit == new_easyrpg_unarmed_hit)
			return;
		m_data.easyrpg_unarmed_hit = new_easyrpg_unarmed_hit;
		emit easyrpg_unarmed_hit_changed();
	}

	QVector<bool> Actor::easyrpg_unarmed_state_set() {
		return QVector<bool>(m_data.easyrpg_unarmed_state_set.begin(), m_data.easyrpg_unarmed_state_set.end());
	}
	void Actor::set_easyrpg_unarmed_state_set(const QVector<bool>& new_easyrpg_unarmed_state_set) {
		if (QVector<bool>(m_data.easyrpg_unarmed_state_set.begin(), m_data.easyrpg_unarmed_state_set.end()) == new_easyrpg_unarmed_state_set)
			return;
		m_data.easyrpg_unarmed_state_set = decltype(m_data.easyrpg_unarmed_state_set)(new_easyrpg_unarmed_state_set.begin(), new_easyrpg_unarmed_state_set.end());
		emit easyrpg_unarmed_state_set_changed();
	}

	int Actor::easyrpg_unarmed_state_chance() {
		return m_data.easyrpg_unarmed_state_chance;
	}
	void Actor::set_easyrpg_unarmed_state_chance(const int& new_easyrpg_unarmed_state_chance) {
		if (m_data.easyrpg_unarmed_state_chance == new_easyrpg_unarmed_state_chance)
			return;
		m_data.easyrpg_unarmed_state_chance = new_easyrpg_unarmed_state_chance;
		emit easyrpg_unarmed_state_chance_changed();
	}

	QVector<bool> Actor::easyrpg_unarmed_attribute_set() {
		return QVector<bool>(m_data.easyrpg_unarmed_attribute_set.begin(), m_data.easyrpg_unarmed_attribute_set.end());
	}
	void Actor::set_easyrpg_unarmed_attribute_set(const QVector<bool>& new_easyrpg_unarmed_attribute_set) {
		if (QVector<bool>(m_data.easyrpg_unarmed_attribute_set.begin(), m_data.easyrpg_unarmed_attribute_set.end()) == new_easyrpg_unarmed_attribute_set)
			return;
		m_data.easyrpg_unarmed_attribute_set = decltype(m_data.easyrpg_unarmed_attribute_set)(new_easyrpg_unarmed_attribute_set.begin(), new_easyrpg_unarmed_attribute_set.end());
		emit easyrpg_unarmed_attribute_set_changed();
	}

	bool Actor::easyrpg_dual_attack() {
		return m_data.easyrpg_dual_attack;
	}
	void Actor::set_easyrpg_dual_attack(const bool& new_easyrpg_dual_attack) {
		if (m_data.easyrpg_dual_attack == new_easyrpg_dual_attack)
			return;
		m_data.easyrpg_dual_attack = new_easyrpg_dual_attack;
		emit easyrpg_dual_attack_changed();
	}

	bool Actor::easyrpg_attack_all() {
		return m_data.easyrpg_attack_all;
	}
	void Actor::set_easyrpg_attack_all(const bool& new_easyrpg_attack_all) {
		if (m_data.easyrpg_attack_all == new_easyrpg_attack_all)
			return;
		m_data.easyrpg_attack_all = new_easyrpg_attack_all;
		emit easyrpg_attack_all_changed();
	}

} // namespace Binding::Generated
