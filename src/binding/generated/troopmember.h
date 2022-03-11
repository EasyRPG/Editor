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
#include <lcf/rpg/troopmember.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::TroopMember class.
 * Exposes lcf::rpg::TroopMember to QML.
 */
namespace Binding::Generated {
class TroopMember : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(int enemy_id READ enemy_id WRITE set_enemy_id NOTIFY enemy_id_changed)
	Q_PROPERTY(int x READ x WRITE set_x NOTIFY x_changed)
	Q_PROPERTY(int y READ y WRITE set_y NOTIFY y_changed)
	Q_PROPERTY(bool invisible READ invisible WRITE set_invisible NOTIFY invisible_changed)

public:
	TroopMember(ProjectData& project, lcf::rpg::TroopMember& data, QObject* parent = nullptr);

	lcf::rpg::TroopMember& data();
	int id();
	int enemy_id();
	void set_enemy_id(const int& new_enemy_id);
	int x();
	void set_x(const int& new_x);
	int y();
	void set_y(const int& new_y);
	bool invisible();
	void set_invisible(const bool& new_invisible);

signals:
	void enemy_id_changed();
	void x_changed();
	void y_changed();
	void invisible_changed();

protected:
	lcf::rpg::TroopMember& m_data;
};
} // namespace Binding::Generated
