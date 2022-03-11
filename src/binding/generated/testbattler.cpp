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
#include "testbattler.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	TestBattler::TestBattler(ProjectData& project, lcf::rpg::TestBattler& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int TestBattler::id() {
		return m_data.ID;
	}
	int TestBattler::actor_id() {
		return m_data.actor_id;
	}
	void TestBattler::set_actor_id(const int& new_actor_id) {
		if (m_data.actor_id == new_actor_id)
			return;
		m_data.actor_id = new_actor_id;
		emit actor_id_changed();
	}

	int TestBattler::level() {
		return m_data.level;
	}
	void TestBattler::set_level(const int& new_level) {
		if (m_data.level == new_level)
			return;
		m_data.level = new_level;
		emit level_changed();
	}

	int TestBattler::weapon_id() {
		return m_data.weapon_id;
	}
	void TestBattler::set_weapon_id(const int& new_weapon_id) {
		if (m_data.weapon_id == new_weapon_id)
			return;
		m_data.weapon_id = new_weapon_id;
		emit weapon_id_changed();
	}

	int TestBattler::shield_id() {
		return m_data.shield_id;
	}
	void TestBattler::set_shield_id(const int& new_shield_id) {
		if (m_data.shield_id == new_shield_id)
			return;
		m_data.shield_id = new_shield_id;
		emit shield_id_changed();
	}

	int TestBattler::armor_id() {
		return m_data.armor_id;
	}
	void TestBattler::set_armor_id(const int& new_armor_id) {
		if (m_data.armor_id == new_armor_id)
			return;
		m_data.armor_id = new_armor_id;
		emit armor_id_changed();
	}

	int TestBattler::helmet_id() {
		return m_data.helmet_id;
	}
	void TestBattler::set_helmet_id(const int& new_helmet_id) {
		if (m_data.helmet_id == new_helmet_id)
			return;
		m_data.helmet_id = new_helmet_id;
		emit helmet_id_changed();
	}

	int TestBattler::accessory_id() {
		return m_data.accessory_id;
	}
	void TestBattler::set_accessory_id(const int& new_accessory_id) {
		if (m_data.accessory_id == new_accessory_id)
			return;
		m_data.accessory_id = new_accessory_id;
		emit accessory_id_changed();
	}

} // namespace Binding::Generated
