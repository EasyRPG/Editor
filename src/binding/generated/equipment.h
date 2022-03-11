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
#include <lcf/rpg/equipment.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::Equipment class.
 * Exposes lcf::rpg::Equipment to QML.
 */
namespace Binding::Generated {
class Equipment : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int weapon_id READ weapon_id WRITE set_weapon_id NOTIFY weapon_id_changed)
	Q_PROPERTY(int shield_id READ shield_id WRITE set_shield_id NOTIFY shield_id_changed)
	Q_PROPERTY(int armor_id READ armor_id WRITE set_armor_id NOTIFY armor_id_changed)
	Q_PROPERTY(int helmet_id READ helmet_id WRITE set_helmet_id NOTIFY helmet_id_changed)
	Q_PROPERTY(int accessory_id READ accessory_id WRITE set_accessory_id NOTIFY accessory_id_changed)

public:
	Equipment(ProjectData& project, lcf::rpg::Equipment& data, QObject* parent = nullptr);

	lcf::rpg::Equipment& data();
	int weapon_id();
	void set_weapon_id(const int& new_weapon_id);
	int shield_id();
	void set_shield_id(const int& new_shield_id);
	int armor_id();
	void set_armor_id(const int& new_armor_id);
	int helmet_id();
	void set_helmet_id(const int& new_helmet_id);
	int accessory_id();
	void set_accessory_id(const int& new_accessory_id);

signals:
	void weapon_id_changed();
	void shield_id_changed();
	void armor_id_changed();
	void helmet_id_changed();
	void accessory_id_changed();

protected:
	lcf::rpg::Equipment& m_data;
};
} // namespace Binding::Generated
