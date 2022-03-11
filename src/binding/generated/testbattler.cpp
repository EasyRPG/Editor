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
	int32_t TestBattler::actor_id() {
		return m_data.actor_id;
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

	int32_t TestBattler::weapon_id() {
		return m_data.weapon_id;
	}

	int32_t TestBattler::shield_id() {
		return m_data.shield_id;
	}

	int32_t TestBattler::armor_id() {
		return m_data.armor_id;
	}

	int32_t TestBattler::helmet_id() {
		return m_data.helmet_id;
	}

	int32_t TestBattler::accessory_id() {
		return m_data.accessory_id;
	}

} // namespace Binding::Generated
