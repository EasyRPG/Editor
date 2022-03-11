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
#include "battleranimationweapon.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	BattlerAnimationWeapon::BattlerAnimationWeapon(ProjectData& project, lcf::rpg::BattlerAnimationWeapon& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int BattlerAnimationWeapon::id() {
		return m_data.ID;
	}
	QString BattlerAnimationWeapon::name() {
		return ToQString(m_data.name);
	}
	void BattlerAnimationWeapon::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	QString BattlerAnimationWeapon::weapon_name() {
		return ToQString(m_data.weapon_name);
	}
	void BattlerAnimationWeapon::set_weapon_name(const QString& new_weapon_name) {
		if (ToQString(m_data.weapon_name) == new_weapon_name)
			return;
		m_data.weapon_name = ToDBString(new_weapon_name);
		emit weapon_name_changed();
	}

	int BattlerAnimationWeapon::weapon_index() {
		return m_data.weapon_index;
	}
	void BattlerAnimationWeapon::set_weapon_index(const int& new_weapon_index) {
		if (m_data.weapon_index == new_weapon_index)
			return;
		m_data.weapon_index = new_weapon_index;
		emit weapon_index_changed();
	}

} // namespace Binding::Generated
