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
#include <lcf/rpg/savetarget.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::SaveTarget class.
 * Exposes lcf::rpg::SaveTarget to QML.
 */
namespace Binding::Generated {
class SaveTarget : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(int map_id READ map_id WRITE set_map_id NOTIFY map_id_changed)
	Q_PROPERTY(int map_x READ map_x WRITE set_map_x NOTIFY map_x_changed)
	Q_PROPERTY(int map_y READ map_y WRITE set_map_y NOTIFY map_y_changed)
	Q_PROPERTY(bool switch_on READ switch_on WRITE set_switch_on NOTIFY switch_on_changed)
	Q_PROPERTY(int switch_id READ switch_id WRITE set_switch_id NOTIFY switch_id_changed)

public:
	SaveTarget(ProjectData& project, lcf::rpg::SaveTarget& data, QObject* parent = nullptr);

	lcf::rpg::SaveTarget& data();
	int id();
	int map_id();
	void set_map_id(const int& new_map_id);
	int map_x();
	void set_map_x(const int& new_map_x);
	int map_y();
	void set_map_y(const int& new_map_y);
	bool switch_on();
	void set_switch_on(const bool& new_switch_on);
	int switch_id();
	void set_switch_id(const int& new_switch_id);

signals:
	void map_id_changed();
	void map_x_changed();
	void map_y_changed();
	void switch_on_changed();
	void switch_id_changed();

protected:
	lcf::rpg::SaveTarget& m_data;
};
} // namespace Binding::Generated
