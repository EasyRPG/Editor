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
#include <lcf/rpg/battleranimation.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/battleranimationpose.h"
#include "binding/battleranimationweapon.h"

class ProjectData;

/**
 * Binding::Generated::BattlerAnimation class.
 * Exposes lcf::rpg::BattlerAnimation to QML.
 */
namespace Binding::Generated {
class BattlerAnimation : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(int speed READ speed WRITE set_speed NOTIFY speed_changed)
	Q_PROPERTY(ArrayAdapter* poses READ poses CONSTANT)
	Q_PROPERTY(ArrayAdapter* weapons READ weapons CONSTANT)

public:
	BattlerAnimation(ProjectData& project, lcf::rpg::BattlerAnimation& data, QObject* parent = nullptr);

	lcf::rpg::BattlerAnimation& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	int speed();
	void set_speed(const int& new_speed);
	ArrayAdapter* poses();
	ArrayAdapter* weapons();

signals:
	void name_changed();
	void speed_changed();

protected:
	lcf::rpg::BattlerAnimation& m_data;
	ArrayAdapter* m_poses;
	ArrayAdapter* m_weapons;
};
} // namespace Binding::Generated
