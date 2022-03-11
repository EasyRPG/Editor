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
#include <lcf/rpg/actor.h>
#include "binding/binding_base.h"
#include "binding/equipment.h"
#include "binding/parameters.h"
#include "binding/learning.h"

class ProjectData;

/**
 * Binding::Generated::Actor class.
 * Exposes lcf::rpg::Actor to QML.
 */
namespace Binding::Generated {
class Actor : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(QString title READ title WRITE set_title NOTIFY title_changed)
	Q_PROPERTY(QString character_name READ character_name WRITE set_character_name NOTIFY character_name_changed)
	Q_PROPERTY(int character_index READ character_index WRITE set_character_index NOTIFY character_index_changed)
	Q_PROPERTY(bool transparent READ transparent WRITE set_transparent NOTIFY transparent_changed)
	Q_PROPERTY(int initial_level READ initial_level WRITE set_initial_level NOTIFY initial_level_changed)
	Q_PROPERTY(int final_level READ final_level WRITE set_final_level NOTIFY final_level_changed)
	Q_PROPERTY(bool critical_hit READ critical_hit WRITE set_critical_hit NOTIFY critical_hit_changed)
	Q_PROPERTY(int critical_hit_chance READ critical_hit_chance WRITE set_critical_hit_chance NOTIFY critical_hit_chance_changed)
	Q_PROPERTY(QString face_name READ face_name WRITE set_face_name NOTIFY face_name_changed)
	Q_PROPERTY(int face_index READ face_index WRITE set_face_index NOTIFY face_index_changed)
	Q_PROPERTY(bool two_weapon READ two_weapon WRITE set_two_weapon NOTIFY two_weapon_changed)
	Q_PROPERTY(bool lock_equipment READ lock_equipment WRITE set_lock_equipment NOTIFY lock_equipment_changed)
	Q_PROPERTY(bool auto_battle READ auto_battle WRITE set_auto_battle NOTIFY auto_battle_changed)
	Q_PROPERTY(bool super_guard READ super_guard WRITE set_super_guard NOTIFY super_guard_changed)
	Q_PROPERTY(Binding::Parameters* parameters READ parameters CONSTANT)
	Q_PROPERTY(int exp_base READ exp_base WRITE set_exp_base NOTIFY exp_base_changed)
	Q_PROPERTY(int exp_inflation READ exp_inflation WRITE set_exp_inflation NOTIFY exp_inflation_changed)
	Q_PROPERTY(int exp_correction READ exp_correction WRITE set_exp_correction NOTIFY exp_correction_changed)
	Q_PROPERTY(Binding::Equipment* initial_equipment READ initial_equipment CONSTANT)
	Q_PROPERTY(int32_t unarmed_animation READ unarmed_animation CONSTANT)
	Q_PROPERTY(int32_t class_id READ class_id CONSTANT)
	Q_PROPERTY(int battle_x READ battle_x WRITE set_battle_x NOTIFY battle_x_changed)
	Q_PROPERTY(int battle_y READ battle_y WRITE set_battle_y NOTIFY battle_y_changed)
	Q_PROPERTY(int32_t battler_animation READ battler_animation CONSTANT)
	Q_PROPERTY(QVector<Binding::Learning*> skills READ skills CONSTANT)
	Q_PROPERTY(bool rename_skill READ rename_skill WRITE set_rename_skill NOTIFY rename_skill_changed)
	Q_PROPERTY(QString skill_name READ skill_name WRITE set_skill_name NOTIFY skill_name_changed)
	Q_PROPERTY(QVector<int> state_ranks READ state_ranks WRITE set_state_ranks NOTIFY state_ranks_changed)
	Q_PROPERTY(QVector<int> attribute_ranks READ attribute_ranks WRITE set_attribute_ranks NOTIFY attribute_ranks_changed)
	Q_PROPERTY(QVector<int> battle_commands READ battle_commands WRITE set_battle_commands NOTIFY battle_commands_changed)
	Q_PROPERTY(int easyrpg_actorai READ easyrpg_actorai WRITE set_easyrpg_actorai NOTIFY easyrpg_actorai_changed)
	Q_PROPERTY(bool easyrpg_prevent_critical READ easyrpg_prevent_critical WRITE set_easyrpg_prevent_critical NOTIFY easyrpg_prevent_critical_changed)
	Q_PROPERTY(bool easyrpg_raise_evasion READ easyrpg_raise_evasion WRITE set_easyrpg_raise_evasion NOTIFY easyrpg_raise_evasion_changed)
	Q_PROPERTY(bool easyrpg_immune_to_attribute_downshifts READ easyrpg_immune_to_attribute_downshifts WRITE set_easyrpg_immune_to_attribute_downshifts NOTIFY easyrpg_immune_to_attribute_downshifts_changed)
	Q_PROPERTY(bool easyrpg_ignore_evasion READ easyrpg_ignore_evasion WRITE set_easyrpg_ignore_evasion NOTIFY easyrpg_ignore_evasion_changed)
	Q_PROPERTY(int easyrpg_unarmed_hit READ easyrpg_unarmed_hit WRITE set_easyrpg_unarmed_hit NOTIFY easyrpg_unarmed_hit_changed)
	Q_PROPERTY(QVector<bool> easyrpg_unarmed_state_set READ easyrpg_unarmed_state_set WRITE set_easyrpg_unarmed_state_set NOTIFY easyrpg_unarmed_state_set_changed)
	Q_PROPERTY(int easyrpg_unarmed_state_chance READ easyrpg_unarmed_state_chance WRITE set_easyrpg_unarmed_state_chance NOTIFY easyrpg_unarmed_state_chance_changed)
	Q_PROPERTY(QVector<bool> easyrpg_unarmed_attribute_set READ easyrpg_unarmed_attribute_set WRITE set_easyrpg_unarmed_attribute_set NOTIFY easyrpg_unarmed_attribute_set_changed)
	Q_PROPERTY(bool easyrpg_dual_attack READ easyrpg_dual_attack WRITE set_easyrpg_dual_attack NOTIFY easyrpg_dual_attack_changed)
	Q_PROPERTY(bool easyrpg_attack_all READ easyrpg_attack_all WRITE set_easyrpg_attack_all NOTIFY easyrpg_attack_all_changed)

public:
	Actor(ProjectData& project, lcf::rpg::Actor& data, QObject* parent = nullptr);

	lcf::rpg::Actor& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	QString title();
	void set_title(const QString& new_title);
	QString character_name();
	void set_character_name(const QString& new_character_name);
	int character_index();
	void set_character_index(const int& new_character_index);
	bool transparent();
	void set_transparent(const bool& new_transparent);
	int initial_level();
	void set_initial_level(const int& new_initial_level);
	int final_level();
	void set_final_level(const int& new_final_level);
	bool critical_hit();
	void set_critical_hit(const bool& new_critical_hit);
	int critical_hit_chance();
	void set_critical_hit_chance(const int& new_critical_hit_chance);
	QString face_name();
	void set_face_name(const QString& new_face_name);
	int face_index();
	void set_face_index(const int& new_face_index);
	bool two_weapon();
	void set_two_weapon(const bool& new_two_weapon);
	bool lock_equipment();
	void set_lock_equipment(const bool& new_lock_equipment);
	bool auto_battle();
	void set_auto_battle(const bool& new_auto_battle);
	bool super_guard();
	void set_super_guard(const bool& new_super_guard);
	Binding::Parameters* parameters();
	int exp_base();
	void set_exp_base(const int& new_exp_base);
	int exp_inflation();
	void set_exp_inflation(const int& new_exp_inflation);
	int exp_correction();
	void set_exp_correction(const int& new_exp_correction);
	Binding::Equipment* initial_equipment();
	int32_t unarmed_animation();
	int32_t class_id();
	int battle_x();
	void set_battle_x(const int& new_battle_x);
	int battle_y();
	void set_battle_y(const int& new_battle_y);
	int32_t battler_animation();
	QVector<Binding::Learning*>& skills();
	bool rename_skill();
	void set_rename_skill(const bool& new_rename_skill);
	QString skill_name();
	void set_skill_name(const QString& new_skill_name);
	QVector<int> state_ranks();
	void set_state_ranks(const QVector<int>& new_state_ranks);
	QVector<int> attribute_ranks();
	void set_attribute_ranks(const QVector<int>& new_attribute_ranks);
	QVector<int> battle_commands();
	void set_battle_commands(const QVector<int>& new_battle_commands);
	int easyrpg_actorai();
	void set_easyrpg_actorai(const int& new_easyrpg_actorai);
	bool easyrpg_prevent_critical();
	void set_easyrpg_prevent_critical(const bool& new_easyrpg_prevent_critical);
	bool easyrpg_raise_evasion();
	void set_easyrpg_raise_evasion(const bool& new_easyrpg_raise_evasion);
	bool easyrpg_immune_to_attribute_downshifts();
	void set_easyrpg_immune_to_attribute_downshifts(const bool& new_easyrpg_immune_to_attribute_downshifts);
	bool easyrpg_ignore_evasion();
	void set_easyrpg_ignore_evasion(const bool& new_easyrpg_ignore_evasion);
	int easyrpg_unarmed_hit();
	void set_easyrpg_unarmed_hit(const int& new_easyrpg_unarmed_hit);
	QVector<bool> easyrpg_unarmed_state_set();
	void set_easyrpg_unarmed_state_set(const QVector<bool>& new_easyrpg_unarmed_state_set);
	int easyrpg_unarmed_state_chance();
	void set_easyrpg_unarmed_state_chance(const int& new_easyrpg_unarmed_state_chance);
	QVector<bool> easyrpg_unarmed_attribute_set();
	void set_easyrpg_unarmed_attribute_set(const QVector<bool>& new_easyrpg_unarmed_attribute_set);
	bool easyrpg_dual_attack();
	void set_easyrpg_dual_attack(const bool& new_easyrpg_dual_attack);
	bool easyrpg_attack_all();
	void set_easyrpg_attack_all(const bool& new_easyrpg_attack_all);

signals:
	void name_changed();
	void title_changed();
	void character_name_changed();
	void character_index_changed();
	void transparent_changed();
	void initial_level_changed();
	void final_level_changed();
	void critical_hit_changed();
	void critical_hit_chance_changed();
	void face_name_changed();
	void face_index_changed();
	void two_weapon_changed();
	void lock_equipment_changed();
	void auto_battle_changed();
	void super_guard_changed();
	void exp_base_changed();
	void exp_inflation_changed();
	void exp_correction_changed();
	void battle_x_changed();
	void battle_y_changed();
	void rename_skill_changed();
	void skill_name_changed();
	void state_ranks_changed();
	void attribute_ranks_changed();
	void battle_commands_changed();
	void easyrpg_actorai_changed();
	void easyrpg_prevent_critical_changed();
	void easyrpg_raise_evasion_changed();
	void easyrpg_immune_to_attribute_downshifts_changed();
	void easyrpg_ignore_evasion_changed();
	void easyrpg_unarmed_hit_changed();
	void easyrpg_unarmed_state_set_changed();
	void easyrpg_unarmed_state_chance_changed();
	void easyrpg_unarmed_attribute_set_changed();
	void easyrpg_dual_attack_changed();
	void easyrpg_attack_all_changed();

protected:
	lcf::rpg::Actor& m_data;
	Binding::Parameters* m_parameters;
	Binding::Equipment* m_initial_equipment;
	QVector<Binding::Learning*> m_skills;
};
} // namespace Binding::Generated
