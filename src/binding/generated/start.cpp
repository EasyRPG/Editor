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
#include "start.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Start::Start(ProjectData& project, lcf::rpg::Start& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int Start::party_map_id() {
		return m_data.party_map_id;
	}
	void Start::set_party_map_id(const int& new_party_map_id) {
		if (m_data.party_map_id == new_party_map_id)
			return;
		m_data.party_map_id = new_party_map_id;
		emit party_map_id_changed();
	}

	int Start::party_x() {
		return m_data.party_x;
	}
	void Start::set_party_x(const int& new_party_x) {
		if (m_data.party_x == new_party_x)
			return;
		m_data.party_x = new_party_x;
		emit party_x_changed();
	}

	int Start::party_y() {
		return m_data.party_y;
	}
	void Start::set_party_y(const int& new_party_y) {
		if (m_data.party_y == new_party_y)
			return;
		m_data.party_y = new_party_y;
		emit party_y_changed();
	}

	int Start::boat_map_id() {
		return m_data.boat_map_id;
	}
	void Start::set_boat_map_id(const int& new_boat_map_id) {
		if (m_data.boat_map_id == new_boat_map_id)
			return;
		m_data.boat_map_id = new_boat_map_id;
		emit boat_map_id_changed();
	}

	int Start::boat_x() {
		return m_data.boat_x;
	}
	void Start::set_boat_x(const int& new_boat_x) {
		if (m_data.boat_x == new_boat_x)
			return;
		m_data.boat_x = new_boat_x;
		emit boat_x_changed();
	}

	int Start::boat_y() {
		return m_data.boat_y;
	}
	void Start::set_boat_y(const int& new_boat_y) {
		if (m_data.boat_y == new_boat_y)
			return;
		m_data.boat_y = new_boat_y;
		emit boat_y_changed();
	}

	int Start::ship_map_id() {
		return m_data.ship_map_id;
	}
	void Start::set_ship_map_id(const int& new_ship_map_id) {
		if (m_data.ship_map_id == new_ship_map_id)
			return;
		m_data.ship_map_id = new_ship_map_id;
		emit ship_map_id_changed();
	}

	int Start::ship_x() {
		return m_data.ship_x;
	}
	void Start::set_ship_x(const int& new_ship_x) {
		if (m_data.ship_x == new_ship_x)
			return;
		m_data.ship_x = new_ship_x;
		emit ship_x_changed();
	}

	int Start::ship_y() {
		return m_data.ship_y;
	}
	void Start::set_ship_y(const int& new_ship_y) {
		if (m_data.ship_y == new_ship_y)
			return;
		m_data.ship_y = new_ship_y;
		emit ship_y_changed();
	}

	int Start::airship_map_id() {
		return m_data.airship_map_id;
	}
	void Start::set_airship_map_id(const int& new_airship_map_id) {
		if (m_data.airship_map_id == new_airship_map_id)
			return;
		m_data.airship_map_id = new_airship_map_id;
		emit airship_map_id_changed();
	}

	int Start::airship_x() {
		return m_data.airship_x;
	}
	void Start::set_airship_x(const int& new_airship_x) {
		if (m_data.airship_x == new_airship_x)
			return;
		m_data.airship_x = new_airship_x;
		emit airship_x_changed();
	}

	int Start::airship_y() {
		return m_data.airship_y;
	}
	void Start::set_airship_y(const int& new_airship_y) {
		if (m_data.airship_y == new_airship_y)
			return;
		m_data.airship_y = new_airship_y;
		emit airship_y_changed();
	}

} // namespace Binding::Generated
