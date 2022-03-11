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
#include <lcf/rpg/start.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::Start class.
 * Exposes lcf::rpg::Start to QML.
 */
namespace Binding::Generated {
class Start : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int party_map_id READ party_map_id WRITE set_party_map_id NOTIFY party_map_id_changed)
	Q_PROPERTY(int party_x READ party_x WRITE set_party_x NOTIFY party_x_changed)
	Q_PROPERTY(int party_y READ party_y WRITE set_party_y NOTIFY party_y_changed)
	Q_PROPERTY(int boat_map_id READ boat_map_id WRITE set_boat_map_id NOTIFY boat_map_id_changed)
	Q_PROPERTY(int boat_x READ boat_x WRITE set_boat_x NOTIFY boat_x_changed)
	Q_PROPERTY(int boat_y READ boat_y WRITE set_boat_y NOTIFY boat_y_changed)
	Q_PROPERTY(int ship_map_id READ ship_map_id WRITE set_ship_map_id NOTIFY ship_map_id_changed)
	Q_PROPERTY(int ship_x READ ship_x WRITE set_ship_x NOTIFY ship_x_changed)
	Q_PROPERTY(int ship_y READ ship_y WRITE set_ship_y NOTIFY ship_y_changed)
	Q_PROPERTY(int airship_map_id READ airship_map_id WRITE set_airship_map_id NOTIFY airship_map_id_changed)
	Q_PROPERTY(int airship_x READ airship_x WRITE set_airship_x NOTIFY airship_x_changed)
	Q_PROPERTY(int airship_y READ airship_y WRITE set_airship_y NOTIFY airship_y_changed)

public:
	Start(ProjectData& project, lcf::rpg::Start& data, QObject* parent = nullptr);

	lcf::rpg::Start& data();
	int party_map_id();
	void set_party_map_id(const int& new_party_map_id);
	int party_x();
	void set_party_x(const int& new_party_x);
	int party_y();
	void set_party_y(const int& new_party_y);
	int boat_map_id();
	void set_boat_map_id(const int& new_boat_map_id);
	int boat_x();
	void set_boat_x(const int& new_boat_x);
	int boat_y();
	void set_boat_y(const int& new_boat_y);
	int ship_map_id();
	void set_ship_map_id(const int& new_ship_map_id);
	int ship_x();
	void set_ship_x(const int& new_ship_x);
	int ship_y();
	void set_ship_y(const int& new_ship_y);
	int airship_map_id();
	void set_airship_map_id(const int& new_airship_map_id);
	int airship_x();
	void set_airship_x(const int& new_airship_x);
	int airship_y();
	void set_airship_y(const int& new_airship_y);

signals:
	void party_map_id_changed();
	void party_x_changed();
	void party_y_changed();
	void boat_map_id_changed();
	void boat_x_changed();
	void boat_y_changed();
	void ship_map_id_changed();
	void ship_x_changed();
	void ship_y_changed();
	void airship_map_id_changed();
	void airship_x_changed();
	void airship_y_changed();

protected:
	lcf::rpg::Start& m_data;
};
} // namespace Binding::Generated
