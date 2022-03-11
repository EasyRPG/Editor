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
#include <lcf/rpg/battlecommands.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/battlecommand.h"

class ProjectData;

/**
 * Binding::Generated::BattleCommands class.
 * Exposes lcf::rpg::BattleCommands to QML.
 */
namespace Binding::Generated {
class BattleCommands : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int32_t placement READ placement CONSTANT)
	Q_PROPERTY(bool death_handler_unused READ death_handler_unused WRITE set_death_handler_unused NOTIFY death_handler_unused_changed)
	Q_PROPERTY(int32_t row READ row CONSTANT)
	Q_PROPERTY(int32_t battle_type READ battle_type CONSTANT)
	Q_PROPERTY(bool unused_display_normal_parameters READ unused_display_normal_parameters WRITE set_unused_display_normal_parameters NOTIFY unused_display_normal_parameters_changed)
	Q_PROPERTY(ArrayAdapter* commands READ commands CONSTANT)
	Q_PROPERTY(bool death_handler READ death_handler WRITE set_death_handler NOTIFY death_handler_changed)
	Q_PROPERTY(int32_t death_event READ death_event CONSTANT)
	Q_PROPERTY(int32_t window_size READ window_size CONSTANT)
	Q_PROPERTY(int32_t transparency READ transparency CONSTANT)
	Q_PROPERTY(bool death_teleport READ death_teleport WRITE set_death_teleport NOTIFY death_teleport_changed)
	Q_PROPERTY(int32_t death_teleport_id READ death_teleport_id CONSTANT)
	Q_PROPERTY(int death_teleport_x READ death_teleport_x WRITE set_death_teleport_x NOTIFY death_teleport_x_changed)
	Q_PROPERTY(int death_teleport_y READ death_teleport_y WRITE set_death_teleport_y NOTIFY death_teleport_y_changed)
	Q_PROPERTY(int32_t death_teleport_face READ death_teleport_face CONSTANT)
	Q_PROPERTY(int32_t easyrpg_default_atb_mode READ easyrpg_default_atb_mode CONSTANT)
	Q_PROPERTY(bool easyrpg_enable_battle_row_command READ easyrpg_enable_battle_row_command WRITE set_easyrpg_enable_battle_row_command NOTIFY easyrpg_enable_battle_row_command_changed)
	Q_PROPERTY(bool easyrpg_sequential_order READ easyrpg_sequential_order WRITE set_easyrpg_sequential_order NOTIFY easyrpg_sequential_order_changed)
	Q_PROPERTY(bool easyrpg_disable_row_feature READ easyrpg_disable_row_feature WRITE set_easyrpg_disable_row_feature NOTIFY easyrpg_disable_row_feature_changed)

public:
	BattleCommands(ProjectData& project, lcf::rpg::BattleCommands& data, QObject* parent = nullptr);

	lcf::rpg::BattleCommands& data();
	int32_t placement();
	bool death_handler_unused();
	void set_death_handler_unused(const bool& new_death_handler_unused);
	int32_t row();
	int32_t battle_type();
	bool unused_display_normal_parameters();
	void set_unused_display_normal_parameters(const bool& new_unused_display_normal_parameters);
	ArrayAdapter* commands();
	bool death_handler();
	void set_death_handler(const bool& new_death_handler);
	int32_t death_event();
	int32_t window_size();
	int32_t transparency();
	bool death_teleport();
	void set_death_teleport(const bool& new_death_teleport);
	int32_t death_teleport_id();
	int death_teleport_x();
	void set_death_teleport_x(const int& new_death_teleport_x);
	int death_teleport_y();
	void set_death_teleport_y(const int& new_death_teleport_y);
	int32_t death_teleport_face();
	int32_t easyrpg_default_atb_mode();
	bool easyrpg_enable_battle_row_command();
	void set_easyrpg_enable_battle_row_command(const bool& new_easyrpg_enable_battle_row_command);
	bool easyrpg_sequential_order();
	void set_easyrpg_sequential_order(const bool& new_easyrpg_sequential_order);
	bool easyrpg_disable_row_feature();
	void set_easyrpg_disable_row_feature(const bool& new_easyrpg_disable_row_feature);

signals:
	void death_handler_unused_changed();
	void unused_display_normal_parameters_changed();
	void death_handler_changed();
	void death_teleport_changed();
	void death_teleport_x_changed();
	void death_teleport_y_changed();
	void easyrpg_enable_battle_row_command_changed();
	void easyrpg_sequential_order_changed();
	void easyrpg_disable_row_feature_changed();

protected:
	lcf::rpg::BattleCommands& m_data;
	ArrayAdapter* m_commands;
};
} // namespace Binding::Generated
