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
#include "savevehiclelocation.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveVehicleLocation::SaveVehicleLocation(ProjectData& project, lcf::rpg::SaveVehicleLocation& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int SaveVehicleLocation::vehicle() {
		return m_data.vehicle;
	}
	void SaveVehicleLocation::set_vehicle(const int& new_vehicle) {
		if (m_data.vehicle == new_vehicle)
			return;
		m_data.vehicle = new_vehicle;
		emit vehicle_changed();
	}

	int SaveVehicleLocation::remaining_ascent() {
		return m_data.remaining_ascent;
	}
	void SaveVehicleLocation::set_remaining_ascent(const int& new_remaining_ascent) {
		if (m_data.remaining_ascent == new_remaining_ascent)
			return;
		m_data.remaining_ascent = new_remaining_ascent;
		emit remaining_ascent_changed();
	}

	int SaveVehicleLocation::remaining_descent() {
		return m_data.remaining_descent;
	}
	void SaveVehicleLocation::set_remaining_descent(const int& new_remaining_descent) {
		if (m_data.remaining_descent == new_remaining_descent)
			return;
		m_data.remaining_descent = new_remaining_descent;
		emit remaining_descent_changed();
	}

	QString SaveVehicleLocation::orig_sprite_name() {
		return QString::fromStdString(m_data.orig_sprite_name);
	}
	void SaveVehicleLocation::set_orig_sprite_name(const QString& new_orig_sprite_name) {
		if (QString::fromStdString(m_data.orig_sprite_name) == new_orig_sprite_name)
			return;
		m_data.orig_sprite_name = new_orig_sprite_name.toStdString();
		emit orig_sprite_name_changed();
	}

	int SaveVehicleLocation::orig_sprite_id() {
		return m_data.orig_sprite_id;
	}
	void SaveVehicleLocation::set_orig_sprite_id(const int& new_orig_sprite_id) {
		if (m_data.orig_sprite_id == new_orig_sprite_id)
			return;
		m_data.orig_sprite_id = new_orig_sprite_id;
		emit orig_sprite_id_changed();
	}

} // namespace Binding::Generated
