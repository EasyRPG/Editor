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
#include <lcf/rpg/savevehiclelocation.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::SaveVehicleLocation class.
 * Exposes lcf::rpg::SaveVehicleLocation to QML.
 */
namespace Binding::Generated {
class SaveVehicleLocation : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int vehicle READ vehicle WRITE set_vehicle NOTIFY vehicle_changed)
	Q_PROPERTY(int remaining_ascent READ remaining_ascent WRITE set_remaining_ascent NOTIFY remaining_ascent_changed)
	Q_PROPERTY(int remaining_descent READ remaining_descent WRITE set_remaining_descent NOTIFY remaining_descent_changed)
	Q_PROPERTY(QString orig_sprite_name READ orig_sprite_name WRITE set_orig_sprite_name NOTIFY orig_sprite_name_changed)
	Q_PROPERTY(int orig_sprite_id READ orig_sprite_id WRITE set_orig_sprite_id NOTIFY orig_sprite_id_changed)

public:
	SaveVehicleLocation(ProjectData& project, lcf::rpg::SaveVehicleLocation& data, QObject* parent = nullptr);

	lcf::rpg::SaveVehicleLocation& data();
	int vehicle();
	void set_vehicle(const int& new_vehicle);
	int remaining_ascent();
	void set_remaining_ascent(const int& new_remaining_ascent);
	int remaining_descent();
	void set_remaining_descent(const int& new_remaining_descent);
	QString orig_sprite_name();
	void set_orig_sprite_name(const QString& new_orig_sprite_name);
	int orig_sprite_id();
	void set_orig_sprite_id(const int& new_orig_sprite_id);

signals:
	void vehicle_changed();
	void remaining_ascent_changed();
	void remaining_descent_changed();
	void orig_sprite_name_changed();
	void orig_sprite_id_changed();

protected:
	lcf::rpg::SaveVehicleLocation& m_data;
};
} // namespace Binding::Generated
