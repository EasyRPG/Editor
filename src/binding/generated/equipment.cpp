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
#include "equipment.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Equipment::Equipment(ProjectData& project, lcf::rpg::Equipment& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int Equipment::weapon_id() {
		return m_data.weapon_id;
	}
	void Equipment::set_weapon_id(const int& new_weapon_id) {
		if (m_data.weapon_id == new_weapon_id)
			return;
		m_data.weapon_id = new_weapon_id;
		emit weapon_id_changed();
	}

	int Equipment::shield_id() {
		return m_data.shield_id;
	}
	void Equipment::set_shield_id(const int& new_shield_id) {
		if (m_data.shield_id == new_shield_id)
			return;
		m_data.shield_id = new_shield_id;
		emit shield_id_changed();
	}

	int Equipment::armor_id() {
		return m_data.armor_id;
	}
	void Equipment::set_armor_id(const int& new_armor_id) {
		if (m_data.armor_id == new_armor_id)
			return;
		m_data.armor_id = new_armor_id;
		emit armor_id_changed();
	}

	int Equipment::helmet_id() {
		return m_data.helmet_id;
	}
	void Equipment::set_helmet_id(const int& new_helmet_id) {
		if (m_data.helmet_id == new_helmet_id)
			return;
		m_data.helmet_id = new_helmet_id;
		emit helmet_id_changed();
	}

	int Equipment::accessory_id() {
		return m_data.accessory_id;
	}
	void Equipment::set_accessory_id(const int& new_accessory_id) {
		if (m_data.accessory_id == new_accessory_id)
			return;
		m_data.accessory_id = new_accessory_id;
		emit accessory_id_changed();
	}

} // namespace Binding::Generated
