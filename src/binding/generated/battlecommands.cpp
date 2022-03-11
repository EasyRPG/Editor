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
#include "battlecommands.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	BattleCommands::BattleCommands(ProjectData& project, lcf::rpg::BattleCommands& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_commands = new ArrayAdapter(this);
			auto& arr = m_commands->data();
			for (auto& var: m_data.commands)
				arr.push_back(new Binding::BattleCommand(m_project, var, this));
		}
	}
	int32_t BattleCommands::placement() {
		return m_data.placement;
	}

	bool BattleCommands::death_handler_unused() {
		return m_data.death_handler_unused;
	}
	void BattleCommands::set_death_handler_unused(const bool& new_death_handler_unused) {
		if (m_data.death_handler_unused == new_death_handler_unused)
			return;
		m_data.death_handler_unused = new_death_handler_unused;
		emit death_handler_unused_changed();
	}

	int32_t BattleCommands::row() {
		return m_data.row;
	}

	int32_t BattleCommands::battle_type() {
		return m_data.battle_type;
	}

	bool BattleCommands::unused_display_normal_parameters() {
		return m_data.unused_display_normal_parameters;
	}
	void BattleCommands::set_unused_display_normal_parameters(const bool& new_unused_display_normal_parameters) {
		if (m_data.unused_display_normal_parameters == new_unused_display_normal_parameters)
			return;
		m_data.unused_display_normal_parameters = new_unused_display_normal_parameters;
		emit unused_display_normal_parameters_changed();
	}

	ArrayAdapter* BattleCommands::commands() {
		return m_commands;
	}

	bool BattleCommands::death_handler() {
		return m_data.death_handler;
	}
	void BattleCommands::set_death_handler(const bool& new_death_handler) {
		if (m_data.death_handler == new_death_handler)
			return;
		m_data.death_handler = new_death_handler;
		emit death_handler_changed();
	}

	int32_t BattleCommands::death_event() {
		return m_data.death_event;
	}

	int32_t BattleCommands::window_size() {
		return m_data.window_size;
	}

	int32_t BattleCommands::transparency() {
		return m_data.transparency;
	}

	bool BattleCommands::death_teleport() {
		return m_data.death_teleport;
	}
	void BattleCommands::set_death_teleport(const bool& new_death_teleport) {
		if (m_data.death_teleport == new_death_teleport)
			return;
		m_data.death_teleport = new_death_teleport;
		emit death_teleport_changed();
	}

	int32_t BattleCommands::death_teleport_id() {
		return m_data.death_teleport_id;
	}

	int BattleCommands::death_teleport_x() {
		return m_data.death_teleport_x;
	}
	void BattleCommands::set_death_teleport_x(const int& new_death_teleport_x) {
		if (m_data.death_teleport_x == new_death_teleport_x)
			return;
		m_data.death_teleport_x = new_death_teleport_x;
		emit death_teleport_x_changed();
	}

	int BattleCommands::death_teleport_y() {
		return m_data.death_teleport_y;
	}
	void BattleCommands::set_death_teleport_y(const int& new_death_teleport_y) {
		if (m_data.death_teleport_y == new_death_teleport_y)
			return;
		m_data.death_teleport_y = new_death_teleport_y;
		emit death_teleport_y_changed();
	}

	int32_t BattleCommands::death_teleport_face() {
		return m_data.death_teleport_face;
	}

	int32_t BattleCommands::easyrpg_default_atb_mode() {
		return m_data.easyrpg_default_atb_mode;
	}

	bool BattleCommands::easyrpg_enable_battle_row_command() {
		return m_data.easyrpg_enable_battle_row_command;
	}
	void BattleCommands::set_easyrpg_enable_battle_row_command(const bool& new_easyrpg_enable_battle_row_command) {
		if (m_data.easyrpg_enable_battle_row_command == new_easyrpg_enable_battle_row_command)
			return;
		m_data.easyrpg_enable_battle_row_command = new_easyrpg_enable_battle_row_command;
		emit easyrpg_enable_battle_row_command_changed();
	}

	bool BattleCommands::easyrpg_sequential_order() {
		return m_data.easyrpg_sequential_order;
	}
	void BattleCommands::set_easyrpg_sequential_order(const bool& new_easyrpg_sequential_order) {
		if (m_data.easyrpg_sequential_order == new_easyrpg_sequential_order)
			return;
		m_data.easyrpg_sequential_order = new_easyrpg_sequential_order;
		emit easyrpg_sequential_order_changed();
	}

	bool BattleCommands::easyrpg_disable_row_feature() {
		return m_data.easyrpg_disable_row_feature;
	}
	void BattleCommands::set_easyrpg_disable_row_feature(const bool& new_easyrpg_disable_row_feature) {
		if (m_data.easyrpg_disable_row_feature == new_easyrpg_disable_row_feature)
			return;
		m_data.easyrpg_disable_row_feature = new_easyrpg_disable_row_feature;
		emit easyrpg_disable_row_feature_changed();
	}

} // namespace Binding::Generated
