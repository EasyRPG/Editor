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
#include <lcf/rpg/battleranimationweapon.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::BattlerAnimationWeapon class.
 * Exposes lcf::rpg::BattlerAnimationWeapon to QML.
 */
namespace Binding::Generated {
class BattlerAnimationWeapon : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(QString weapon_name READ weapon_name WRITE set_weapon_name NOTIFY weapon_name_changed)
	Q_PROPERTY(int weapon_index READ weapon_index WRITE set_weapon_index NOTIFY weapon_index_changed)

public:
	BattlerAnimationWeapon(ProjectData& project, lcf::rpg::BattlerAnimationWeapon& data, QObject* parent = nullptr);

	lcf::rpg::BattlerAnimationWeapon& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	QString weapon_name();
	void set_weapon_name(const QString& new_weapon_name);
	int weapon_index();
	void set_weapon_index(const int& new_weapon_index);

signals:
	void name_changed();
	void weapon_name_changed();
	void weapon_index_changed();

protected:
	lcf::rpg::BattlerAnimationWeapon& m_data;
};
} // namespace Binding::Generated
