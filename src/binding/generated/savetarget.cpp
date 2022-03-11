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
#include "savetarget.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveTarget::SaveTarget(ProjectData& project, lcf::rpg::SaveTarget& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int SaveTarget::id() {
		return m_data.ID;
	}
	int SaveTarget::map_id() {
		return m_data.map_id;
	}
	void SaveTarget::set_map_id(const int& new_map_id) {
		if (m_data.map_id == new_map_id)
			return;
		m_data.map_id = new_map_id;
		emit map_id_changed();
	}

	int SaveTarget::map_x() {
		return m_data.map_x;
	}
	void SaveTarget::set_map_x(const int& new_map_x) {
		if (m_data.map_x == new_map_x)
			return;
		m_data.map_x = new_map_x;
		emit map_x_changed();
	}

	int SaveTarget::map_y() {
		return m_data.map_y;
	}
	void SaveTarget::set_map_y(const int& new_map_y) {
		if (m_data.map_y == new_map_y)
			return;
		m_data.map_y = new_map_y;
		emit map_y_changed();
	}

	bool SaveTarget::switch_on() {
		return m_data.switch_on;
	}
	void SaveTarget::set_switch_on(const bool& new_switch_on) {
		if (m_data.switch_on == new_switch_on)
			return;
		m_data.switch_on = new_switch_on;
		emit switch_on_changed();
	}

	int SaveTarget::switch_id() {
		return m_data.switch_id;
	}
	void SaveTarget::set_switch_id(const int& new_switch_id) {
		if (m_data.switch_id == new_switch_id)
			return;
		m_data.switch_id = new_switch_id;
		emit switch_id_changed();
	}

} // namespace Binding::Generated
