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
#include <lcf/rpg/state.h>
#include "binding/binding_base.h"

class ProjectData;

/**
 * Binding::Generated::State class.
 * Exposes lcf::rpg::State to QML.
 */
namespace Binding::Generated {
class State : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(int32_t type READ type CONSTANT)
	Q_PROPERTY(int color READ color WRITE set_color NOTIFY color_changed)
	Q_PROPERTY(int priority READ priority WRITE set_priority NOTIFY priority_changed)
	Q_PROPERTY(int32_t restriction READ restriction CONSTANT)
	Q_PROPERTY(int a_rate READ a_rate WRITE set_a_rate NOTIFY a_rate_changed)
	Q_PROPERTY(int b_rate READ b_rate WRITE set_b_rate NOTIFY b_rate_changed)
	Q_PROPERTY(int c_rate READ c_rate WRITE set_c_rate NOTIFY c_rate_changed)
	Q_PROPERTY(int d_rate READ d_rate WRITE set_d_rate NOTIFY d_rate_changed)
	Q_PROPERTY(int e_rate READ e_rate WRITE set_e_rate NOTIFY e_rate_changed)
	Q_PROPERTY(int hold_turn READ hold_turn WRITE set_hold_turn NOTIFY hold_turn_changed)
	Q_PROPERTY(int auto_release_prob READ auto_release_prob WRITE set_auto_release_prob NOTIFY auto_release_prob_changed)
	Q_PROPERTY(int release_by_damage READ release_by_damage WRITE set_release_by_damage NOTIFY release_by_damage_changed)
	Q_PROPERTY(int32_t affect_type READ affect_type CONSTANT)
	Q_PROPERTY(bool affect_attack READ affect_attack WRITE set_affect_attack NOTIFY affect_attack_changed)
	Q_PROPERTY(bool affect_defense READ affect_defense WRITE set_affect_defense NOTIFY affect_defense_changed)
	Q_PROPERTY(bool affect_spirit READ affect_spirit WRITE set_affect_spirit NOTIFY affect_spirit_changed)
	Q_PROPERTY(bool affect_agility READ affect_agility WRITE set_affect_agility NOTIFY affect_agility_changed)
	Q_PROPERTY(int reduce_hit_ratio READ reduce_hit_ratio WRITE set_reduce_hit_ratio NOTIFY reduce_hit_ratio_changed)
	Q_PROPERTY(bool avoid_attacks READ avoid_attacks WRITE set_avoid_attacks NOTIFY avoid_attacks_changed)
	Q_PROPERTY(bool reflect_magic READ reflect_magic WRITE set_reflect_magic NOTIFY reflect_magic_changed)
	Q_PROPERTY(bool cursed READ cursed WRITE set_cursed NOTIFY cursed_changed)
	Q_PROPERTY(int32_t battler_animation_id READ battler_animation_id CONSTANT)
	Q_PROPERTY(bool restrict_skill READ restrict_skill WRITE set_restrict_skill NOTIFY restrict_skill_changed)
	Q_PROPERTY(int restrict_skill_level READ restrict_skill_level WRITE set_restrict_skill_level NOTIFY restrict_skill_level_changed)
	Q_PROPERTY(bool restrict_magic READ restrict_magic WRITE set_restrict_magic NOTIFY restrict_magic_changed)
	Q_PROPERTY(int restrict_magic_level READ restrict_magic_level WRITE set_restrict_magic_level NOTIFY restrict_magic_level_changed)
	Q_PROPERTY(int32_t hp_change_type READ hp_change_type CONSTANT)
	Q_PROPERTY(int32_t sp_change_type READ sp_change_type CONSTANT)
	Q_PROPERTY(QString message_actor READ message_actor WRITE set_message_actor NOTIFY message_actor_changed)
	Q_PROPERTY(QString message_enemy READ message_enemy WRITE set_message_enemy NOTIFY message_enemy_changed)
	Q_PROPERTY(QString message_already READ message_already WRITE set_message_already NOTIFY message_already_changed)
	Q_PROPERTY(QString message_affected READ message_affected WRITE set_message_affected NOTIFY message_affected_changed)
	Q_PROPERTY(QString message_recovery READ message_recovery WRITE set_message_recovery NOTIFY message_recovery_changed)
	Q_PROPERTY(int hp_change_max READ hp_change_max WRITE set_hp_change_max NOTIFY hp_change_max_changed)
	Q_PROPERTY(int hp_change_val READ hp_change_val WRITE set_hp_change_val NOTIFY hp_change_val_changed)
	Q_PROPERTY(int hp_change_map_steps READ hp_change_map_steps WRITE set_hp_change_map_steps NOTIFY hp_change_map_steps_changed)
	Q_PROPERTY(int hp_change_map_val READ hp_change_map_val WRITE set_hp_change_map_val NOTIFY hp_change_map_val_changed)
	Q_PROPERTY(int sp_change_max READ sp_change_max WRITE set_sp_change_max NOTIFY sp_change_max_changed)
	Q_PROPERTY(int sp_change_val READ sp_change_val WRITE set_sp_change_val NOTIFY sp_change_val_changed)
	Q_PROPERTY(int sp_change_map_steps READ sp_change_map_steps WRITE set_sp_change_map_steps NOTIFY sp_change_map_steps_changed)
	Q_PROPERTY(int sp_change_map_val READ sp_change_map_val WRITE set_sp_change_map_val NOTIFY sp_change_map_val_changed)
	Q_PROPERTY(QVector<bool> easyrpg_immune_states READ easyrpg_immune_states WRITE set_easyrpg_immune_states NOTIFY easyrpg_immune_states_changed)

public:
	State(ProjectData& project, lcf::rpg::State& data, QObject* parent = nullptr);

	lcf::rpg::State& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	int32_t type();
	int color();
	void set_color(const int& new_color);
	int priority();
	void set_priority(const int& new_priority);
	int32_t restriction();
	int a_rate();
	void set_a_rate(const int& new_a_rate);
	int b_rate();
	void set_b_rate(const int& new_b_rate);
	int c_rate();
	void set_c_rate(const int& new_c_rate);
	int d_rate();
	void set_d_rate(const int& new_d_rate);
	int e_rate();
	void set_e_rate(const int& new_e_rate);
	int hold_turn();
	void set_hold_turn(const int& new_hold_turn);
	int auto_release_prob();
	void set_auto_release_prob(const int& new_auto_release_prob);
	int release_by_damage();
	void set_release_by_damage(const int& new_release_by_damage);
	int32_t affect_type();
	bool affect_attack();
	void set_affect_attack(const bool& new_affect_attack);
	bool affect_defense();
	void set_affect_defense(const bool& new_affect_defense);
	bool affect_spirit();
	void set_affect_spirit(const bool& new_affect_spirit);
	bool affect_agility();
	void set_affect_agility(const bool& new_affect_agility);
	int reduce_hit_ratio();
	void set_reduce_hit_ratio(const int& new_reduce_hit_ratio);
	bool avoid_attacks();
	void set_avoid_attacks(const bool& new_avoid_attacks);
	bool reflect_magic();
	void set_reflect_magic(const bool& new_reflect_magic);
	bool cursed();
	void set_cursed(const bool& new_cursed);
	int32_t battler_animation_id();
	bool restrict_skill();
	void set_restrict_skill(const bool& new_restrict_skill);
	int restrict_skill_level();
	void set_restrict_skill_level(const int& new_restrict_skill_level);
	bool restrict_magic();
	void set_restrict_magic(const bool& new_restrict_magic);
	int restrict_magic_level();
	void set_restrict_magic_level(const int& new_restrict_magic_level);
	int32_t hp_change_type();
	int32_t sp_change_type();
	QString message_actor();
	void set_message_actor(const QString& new_message_actor);
	QString message_enemy();
	void set_message_enemy(const QString& new_message_enemy);
	QString message_already();
	void set_message_already(const QString& new_message_already);
	QString message_affected();
	void set_message_affected(const QString& new_message_affected);
	QString message_recovery();
	void set_message_recovery(const QString& new_message_recovery);
	int hp_change_max();
	void set_hp_change_max(const int& new_hp_change_max);
	int hp_change_val();
	void set_hp_change_val(const int& new_hp_change_val);
	int hp_change_map_steps();
	void set_hp_change_map_steps(const int& new_hp_change_map_steps);
	int hp_change_map_val();
	void set_hp_change_map_val(const int& new_hp_change_map_val);
	int sp_change_max();
	void set_sp_change_max(const int& new_sp_change_max);
	int sp_change_val();
	void set_sp_change_val(const int& new_sp_change_val);
	int sp_change_map_steps();
	void set_sp_change_map_steps(const int& new_sp_change_map_steps);
	int sp_change_map_val();
	void set_sp_change_map_val(const int& new_sp_change_map_val);
	QVector<bool> easyrpg_immune_states();
	void set_easyrpg_immune_states(const QVector<bool>& new_easyrpg_immune_states);

signals:
	void name_changed();
	void color_changed();
	void priority_changed();
	void a_rate_changed();
	void b_rate_changed();
	void c_rate_changed();
	void d_rate_changed();
	void e_rate_changed();
	void hold_turn_changed();
	void auto_release_prob_changed();
	void release_by_damage_changed();
	void affect_attack_changed();
	void affect_defense_changed();
	void affect_spirit_changed();
	void affect_agility_changed();
	void reduce_hit_ratio_changed();
	void avoid_attacks_changed();
	void reflect_magic_changed();
	void cursed_changed();
	void restrict_skill_changed();
	void restrict_skill_level_changed();
	void restrict_magic_changed();
	void restrict_magic_level_changed();
	void message_actor_changed();
	void message_enemy_changed();
	void message_already_changed();
	void message_affected_changed();
	void message_recovery_changed();
	void hp_change_max_changed();
	void hp_change_val_changed();
	void hp_change_map_steps_changed();
	void hp_change_map_val_changed();
	void sp_change_max_changed();
	void sp_change_val_changed();
	void sp_change_map_steps_changed();
	void sp_change_map_val_changed();
	void easyrpg_immune_states_changed();

protected:
	lcf::rpg::State& m_data;
};
} // namespace Binding::Generated
