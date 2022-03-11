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
#include <lcf/rpg/trooppagecondition.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::TroopPageCondition class.
 * Exposes lcf::rpg::TroopPageCondition to QML.
 */
namespace Binding::Generated {
class TroopPageCondition : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int switch_a_id READ switch_a_id WRITE set_switch_a_id NOTIFY switch_a_id_changed)
	Q_PROPERTY(int switch_b_id READ switch_b_id WRITE set_switch_b_id NOTIFY switch_b_id_changed)
	Q_PROPERTY(int variable_id READ variable_id WRITE set_variable_id NOTIFY variable_id_changed)
	Q_PROPERTY(int variable_value READ variable_value WRITE set_variable_value NOTIFY variable_value_changed)
	Q_PROPERTY(int turn_a READ turn_a WRITE set_turn_a NOTIFY turn_a_changed)
	Q_PROPERTY(int turn_b READ turn_b WRITE set_turn_b NOTIFY turn_b_changed)
	Q_PROPERTY(int fatigue_min READ fatigue_min WRITE set_fatigue_min NOTIFY fatigue_min_changed)
	Q_PROPERTY(int fatigue_max READ fatigue_max WRITE set_fatigue_max NOTIFY fatigue_max_changed)
	Q_PROPERTY(int enemy_id READ enemy_id WRITE set_enemy_id NOTIFY enemy_id_changed)
	Q_PROPERTY(int enemy_hp_min READ enemy_hp_min WRITE set_enemy_hp_min NOTIFY enemy_hp_min_changed)
	Q_PROPERTY(int enemy_hp_max READ enemy_hp_max WRITE set_enemy_hp_max NOTIFY enemy_hp_max_changed)
	Q_PROPERTY(int actor_id READ actor_id WRITE set_actor_id NOTIFY actor_id_changed)
	Q_PROPERTY(int actor_hp_min READ actor_hp_min WRITE set_actor_hp_min NOTIFY actor_hp_min_changed)
	Q_PROPERTY(int actor_hp_max READ actor_hp_max WRITE set_actor_hp_max NOTIFY actor_hp_max_changed)
	Q_PROPERTY(int turn_enemy_id READ turn_enemy_id WRITE set_turn_enemy_id NOTIFY turn_enemy_id_changed)
	Q_PROPERTY(int turn_enemy_a READ turn_enemy_a WRITE set_turn_enemy_a NOTIFY turn_enemy_a_changed)
	Q_PROPERTY(int turn_enemy_b READ turn_enemy_b WRITE set_turn_enemy_b NOTIFY turn_enemy_b_changed)
	Q_PROPERTY(int turn_actor_id READ turn_actor_id WRITE set_turn_actor_id NOTIFY turn_actor_id_changed)
	Q_PROPERTY(int turn_actor_a READ turn_actor_a WRITE set_turn_actor_a NOTIFY turn_actor_a_changed)
	Q_PROPERTY(int turn_actor_b READ turn_actor_b WRITE set_turn_actor_b NOTIFY turn_actor_b_changed)
	Q_PROPERTY(int command_actor_id READ command_actor_id WRITE set_command_actor_id NOTIFY command_actor_id_changed)
	Q_PROPERTY(int command_id READ command_id WRITE set_command_id NOTIFY command_id_changed)

public:
	TroopPageCondition(ProjectData& project, lcf::rpg::TroopPageCondition& data, QObject* parent = nullptr);

	lcf::rpg::TroopPageCondition& data();
	int switch_a_id();
	void set_switch_a_id(const int& new_switch_a_id);
	int switch_b_id();
	void set_switch_b_id(const int& new_switch_b_id);
	int variable_id();
	void set_variable_id(const int& new_variable_id);
	int variable_value();
	void set_variable_value(const int& new_variable_value);
	int turn_a();
	void set_turn_a(const int& new_turn_a);
	int turn_b();
	void set_turn_b(const int& new_turn_b);
	int fatigue_min();
	void set_fatigue_min(const int& new_fatigue_min);
	int fatigue_max();
	void set_fatigue_max(const int& new_fatigue_max);
	int enemy_id();
	void set_enemy_id(const int& new_enemy_id);
	int enemy_hp_min();
	void set_enemy_hp_min(const int& new_enemy_hp_min);
	int enemy_hp_max();
	void set_enemy_hp_max(const int& new_enemy_hp_max);
	int actor_id();
	void set_actor_id(const int& new_actor_id);
	int actor_hp_min();
	void set_actor_hp_min(const int& new_actor_hp_min);
	int actor_hp_max();
	void set_actor_hp_max(const int& new_actor_hp_max);
	int turn_enemy_id();
	void set_turn_enemy_id(const int& new_turn_enemy_id);
	int turn_enemy_a();
	void set_turn_enemy_a(const int& new_turn_enemy_a);
	int turn_enemy_b();
	void set_turn_enemy_b(const int& new_turn_enemy_b);
	int turn_actor_id();
	void set_turn_actor_id(const int& new_turn_actor_id);
	int turn_actor_a();
	void set_turn_actor_a(const int& new_turn_actor_a);
	int turn_actor_b();
	void set_turn_actor_b(const int& new_turn_actor_b);
	int command_actor_id();
	void set_command_actor_id(const int& new_command_actor_id);
	int command_id();
	void set_command_id(const int& new_command_id);

signals:
	void switch_a_id_changed();
	void switch_b_id_changed();
	void variable_id_changed();
	void variable_value_changed();
	void turn_a_changed();
	void turn_b_changed();
	void fatigue_min_changed();
	void fatigue_max_changed();
	void enemy_id_changed();
	void enemy_hp_min_changed();
	void enemy_hp_max_changed();
	void actor_id_changed();
	void actor_hp_min_changed();
	void actor_hp_max_changed();
	void turn_enemy_id_changed();
	void turn_enemy_a_changed();
	void turn_enemy_b_changed();
	void turn_actor_id_changed();
	void turn_actor_a_changed();
	void turn_actor_b_changed();
	void command_actor_id_changed();
	void command_id_changed();

protected:
	lcf::rpg::TroopPageCondition& m_data;
};
} // namespace Binding::Generated
