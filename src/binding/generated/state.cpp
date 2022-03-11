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
#include "state.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	State::State(ProjectData& project, lcf::rpg::State& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int State::id() {
		return m_data.ID;
	}
	QString State::name() {
		return ToQString(m_data.name);
	}
	void State::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	int32_t State::type() {
		return m_data.type;
	}

	int State::color() {
		return m_data.color;
	}
	void State::set_color(const int& new_color) {
		if (m_data.color == new_color)
			return;
		m_data.color = new_color;
		emit color_changed();
	}

	int State::priority() {
		return m_data.priority;
	}
	void State::set_priority(const int& new_priority) {
		if (m_data.priority == new_priority)
			return;
		m_data.priority = new_priority;
		emit priority_changed();
	}

	int32_t State::restriction() {
		return m_data.restriction;
	}

	int State::a_rate() {
		return m_data.a_rate;
	}
	void State::set_a_rate(const int& new_a_rate) {
		if (m_data.a_rate == new_a_rate)
			return;
		m_data.a_rate = new_a_rate;
		emit a_rate_changed();
	}

	int State::b_rate() {
		return m_data.b_rate;
	}
	void State::set_b_rate(const int& new_b_rate) {
		if (m_data.b_rate == new_b_rate)
			return;
		m_data.b_rate = new_b_rate;
		emit b_rate_changed();
	}

	int State::c_rate() {
		return m_data.c_rate;
	}
	void State::set_c_rate(const int& new_c_rate) {
		if (m_data.c_rate == new_c_rate)
			return;
		m_data.c_rate = new_c_rate;
		emit c_rate_changed();
	}

	int State::d_rate() {
		return m_data.d_rate;
	}
	void State::set_d_rate(const int& new_d_rate) {
		if (m_data.d_rate == new_d_rate)
			return;
		m_data.d_rate = new_d_rate;
		emit d_rate_changed();
	}

	int State::e_rate() {
		return m_data.e_rate;
	}
	void State::set_e_rate(const int& new_e_rate) {
		if (m_data.e_rate == new_e_rate)
			return;
		m_data.e_rate = new_e_rate;
		emit e_rate_changed();
	}

	int State::hold_turn() {
		return m_data.hold_turn;
	}
	void State::set_hold_turn(const int& new_hold_turn) {
		if (m_data.hold_turn == new_hold_turn)
			return;
		m_data.hold_turn = new_hold_turn;
		emit hold_turn_changed();
	}

	int State::auto_release_prob() {
		return m_data.auto_release_prob;
	}
	void State::set_auto_release_prob(const int& new_auto_release_prob) {
		if (m_data.auto_release_prob == new_auto_release_prob)
			return;
		m_data.auto_release_prob = new_auto_release_prob;
		emit auto_release_prob_changed();
	}

	int State::release_by_damage() {
		return m_data.release_by_damage;
	}
	void State::set_release_by_damage(const int& new_release_by_damage) {
		if (m_data.release_by_damage == new_release_by_damage)
			return;
		m_data.release_by_damage = new_release_by_damage;
		emit release_by_damage_changed();
	}

	int32_t State::affect_type() {
		return m_data.affect_type;
	}

	bool State::affect_attack() {
		return m_data.affect_attack;
	}
	void State::set_affect_attack(const bool& new_affect_attack) {
		if (m_data.affect_attack == new_affect_attack)
			return;
		m_data.affect_attack = new_affect_attack;
		emit affect_attack_changed();
	}

	bool State::affect_defense() {
		return m_data.affect_defense;
	}
	void State::set_affect_defense(const bool& new_affect_defense) {
		if (m_data.affect_defense == new_affect_defense)
			return;
		m_data.affect_defense = new_affect_defense;
		emit affect_defense_changed();
	}

	bool State::affect_spirit() {
		return m_data.affect_spirit;
	}
	void State::set_affect_spirit(const bool& new_affect_spirit) {
		if (m_data.affect_spirit == new_affect_spirit)
			return;
		m_data.affect_spirit = new_affect_spirit;
		emit affect_spirit_changed();
	}

	bool State::affect_agility() {
		return m_data.affect_agility;
	}
	void State::set_affect_agility(const bool& new_affect_agility) {
		if (m_data.affect_agility == new_affect_agility)
			return;
		m_data.affect_agility = new_affect_agility;
		emit affect_agility_changed();
	}

	int State::reduce_hit_ratio() {
		return m_data.reduce_hit_ratio;
	}
	void State::set_reduce_hit_ratio(const int& new_reduce_hit_ratio) {
		if (m_data.reduce_hit_ratio == new_reduce_hit_ratio)
			return;
		m_data.reduce_hit_ratio = new_reduce_hit_ratio;
		emit reduce_hit_ratio_changed();
	}

	bool State::avoid_attacks() {
		return m_data.avoid_attacks;
	}
	void State::set_avoid_attacks(const bool& new_avoid_attacks) {
		if (m_data.avoid_attacks == new_avoid_attacks)
			return;
		m_data.avoid_attacks = new_avoid_attacks;
		emit avoid_attacks_changed();
	}

	bool State::reflect_magic() {
		return m_data.reflect_magic;
	}
	void State::set_reflect_magic(const bool& new_reflect_magic) {
		if (m_data.reflect_magic == new_reflect_magic)
			return;
		m_data.reflect_magic = new_reflect_magic;
		emit reflect_magic_changed();
	}

	bool State::cursed() {
		return m_data.cursed;
	}
	void State::set_cursed(const bool& new_cursed) {
		if (m_data.cursed == new_cursed)
			return;
		m_data.cursed = new_cursed;
		emit cursed_changed();
	}

	int32_t State::battler_animation_id() {
		return m_data.battler_animation_id;
	}

	bool State::restrict_skill() {
		return m_data.restrict_skill;
	}
	void State::set_restrict_skill(const bool& new_restrict_skill) {
		if (m_data.restrict_skill == new_restrict_skill)
			return;
		m_data.restrict_skill = new_restrict_skill;
		emit restrict_skill_changed();
	}

	int State::restrict_skill_level() {
		return m_data.restrict_skill_level;
	}
	void State::set_restrict_skill_level(const int& new_restrict_skill_level) {
		if (m_data.restrict_skill_level == new_restrict_skill_level)
			return;
		m_data.restrict_skill_level = new_restrict_skill_level;
		emit restrict_skill_level_changed();
	}

	bool State::restrict_magic() {
		return m_data.restrict_magic;
	}
	void State::set_restrict_magic(const bool& new_restrict_magic) {
		if (m_data.restrict_magic == new_restrict_magic)
			return;
		m_data.restrict_magic = new_restrict_magic;
		emit restrict_magic_changed();
	}

	int State::restrict_magic_level() {
		return m_data.restrict_magic_level;
	}
	void State::set_restrict_magic_level(const int& new_restrict_magic_level) {
		if (m_data.restrict_magic_level == new_restrict_magic_level)
			return;
		m_data.restrict_magic_level = new_restrict_magic_level;
		emit restrict_magic_level_changed();
	}

	int32_t State::hp_change_type() {
		return m_data.hp_change_type;
	}

	int32_t State::sp_change_type() {
		return m_data.sp_change_type;
	}

	QString State::message_actor() {
		return ToQString(m_data.message_actor);
	}
	void State::set_message_actor(const QString& new_message_actor) {
		if (ToQString(m_data.message_actor) == new_message_actor)
			return;
		m_data.message_actor = ToDBString(new_message_actor);
		emit message_actor_changed();
	}

	QString State::message_enemy() {
		return ToQString(m_data.message_enemy);
	}
	void State::set_message_enemy(const QString& new_message_enemy) {
		if (ToQString(m_data.message_enemy) == new_message_enemy)
			return;
		m_data.message_enemy = ToDBString(new_message_enemy);
		emit message_enemy_changed();
	}

	QString State::message_already() {
		return ToQString(m_data.message_already);
	}
	void State::set_message_already(const QString& new_message_already) {
		if (ToQString(m_data.message_already) == new_message_already)
			return;
		m_data.message_already = ToDBString(new_message_already);
		emit message_already_changed();
	}

	QString State::message_affected() {
		return ToQString(m_data.message_affected);
	}
	void State::set_message_affected(const QString& new_message_affected) {
		if (ToQString(m_data.message_affected) == new_message_affected)
			return;
		m_data.message_affected = ToDBString(new_message_affected);
		emit message_affected_changed();
	}

	QString State::message_recovery() {
		return ToQString(m_data.message_recovery);
	}
	void State::set_message_recovery(const QString& new_message_recovery) {
		if (ToQString(m_data.message_recovery) == new_message_recovery)
			return;
		m_data.message_recovery = ToDBString(new_message_recovery);
		emit message_recovery_changed();
	}

	int State::hp_change_max() {
		return m_data.hp_change_max;
	}
	void State::set_hp_change_max(const int& new_hp_change_max) {
		if (m_data.hp_change_max == new_hp_change_max)
			return;
		m_data.hp_change_max = new_hp_change_max;
		emit hp_change_max_changed();
	}

	int State::hp_change_val() {
		return m_data.hp_change_val;
	}
	void State::set_hp_change_val(const int& new_hp_change_val) {
		if (m_data.hp_change_val == new_hp_change_val)
			return;
		m_data.hp_change_val = new_hp_change_val;
		emit hp_change_val_changed();
	}

	int State::hp_change_map_steps() {
		return m_data.hp_change_map_steps;
	}
	void State::set_hp_change_map_steps(const int& new_hp_change_map_steps) {
		if (m_data.hp_change_map_steps == new_hp_change_map_steps)
			return;
		m_data.hp_change_map_steps = new_hp_change_map_steps;
		emit hp_change_map_steps_changed();
	}

	int State::hp_change_map_val() {
		return m_data.hp_change_map_val;
	}
	void State::set_hp_change_map_val(const int& new_hp_change_map_val) {
		if (m_data.hp_change_map_val == new_hp_change_map_val)
			return;
		m_data.hp_change_map_val = new_hp_change_map_val;
		emit hp_change_map_val_changed();
	}

	int State::sp_change_max() {
		return m_data.sp_change_max;
	}
	void State::set_sp_change_max(const int& new_sp_change_max) {
		if (m_data.sp_change_max == new_sp_change_max)
			return;
		m_data.sp_change_max = new_sp_change_max;
		emit sp_change_max_changed();
	}

	int State::sp_change_val() {
		return m_data.sp_change_val;
	}
	void State::set_sp_change_val(const int& new_sp_change_val) {
		if (m_data.sp_change_val == new_sp_change_val)
			return;
		m_data.sp_change_val = new_sp_change_val;
		emit sp_change_val_changed();
	}

	int State::sp_change_map_steps() {
		return m_data.sp_change_map_steps;
	}
	void State::set_sp_change_map_steps(const int& new_sp_change_map_steps) {
		if (m_data.sp_change_map_steps == new_sp_change_map_steps)
			return;
		m_data.sp_change_map_steps = new_sp_change_map_steps;
		emit sp_change_map_steps_changed();
	}

	int State::sp_change_map_val() {
		return m_data.sp_change_map_val;
	}
	void State::set_sp_change_map_val(const int& new_sp_change_map_val) {
		if (m_data.sp_change_map_val == new_sp_change_map_val)
			return;
		m_data.sp_change_map_val = new_sp_change_map_val;
		emit sp_change_map_val_changed();
	}

	QVector<bool> State::easyrpg_immune_states() {
		return QVector<bool>(m_data.easyrpg_immune_states.begin(), m_data.easyrpg_immune_states.end());
	}
	void State::set_easyrpg_immune_states(const QVector<bool>& new_easyrpg_immune_states) {
		if (QVector<bool>(m_data.easyrpg_immune_states.begin(), m_data.easyrpg_immune_states.end()) == new_easyrpg_immune_states)
			return;
		m_data.easyrpg_immune_states = decltype(m_data.easyrpg_immune_states)(new_easyrpg_immune_states.begin(), new_easyrpg_immune_states.end());
		emit easyrpg_immune_states_changed();
	}

} // namespace Binding::Generated
