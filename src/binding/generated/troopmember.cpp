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
#include "troopmember.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	TroopMember::TroopMember(ProjectData& project, lcf::rpg::TroopMember& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int TroopMember::id() {
		return m_data.ID;
	}
	int TroopMember::enemy_id() {
		return m_data.enemy_id;
	}
	void TroopMember::set_enemy_id(const int& new_enemy_id) {
		if (m_data.enemy_id == new_enemy_id)
			return;
		m_data.enemy_id = new_enemy_id;
		emit enemy_id_changed();
	}

	int TroopMember::x() {
		return m_data.x;
	}
	void TroopMember::set_x(const int& new_x) {
		if (m_data.x == new_x)
			return;
		m_data.x = new_x;
		emit x_changed();
	}

	int TroopMember::y() {
		return m_data.y;
	}
	void TroopMember::set_y(const int& new_y) {
		if (m_data.y == new_y)
			return;
		m_data.y = new_y;
		emit y_changed();
	}

	bool TroopMember::invisible() {
		return m_data.invisible;
	}
	void TroopMember::set_invisible(const bool& new_invisible) {
		if (m_data.invisible == new_invisible)
			return;
		m_data.invisible = new_invisible;
		emit invisible_changed();
	}

} // namespace Binding::Generated
