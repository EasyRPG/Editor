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
#include <lcf/rpg/testbattler.h>
#include "binding/binding_base.h"

class ProjectData;

/**
 * Binding::Generated::TestBattler class.
 * Exposes lcf::rpg::TestBattler to QML.
 */
namespace Binding::Generated {
class TestBattler : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(int32_t actor_id READ actor_id CONSTANT)
	Q_PROPERTY(int level READ level WRITE set_level NOTIFY level_changed)
	Q_PROPERTY(int32_t weapon_id READ weapon_id CONSTANT)
	Q_PROPERTY(int32_t shield_id READ shield_id CONSTANT)
	Q_PROPERTY(int32_t armor_id READ armor_id CONSTANT)
	Q_PROPERTY(int32_t helmet_id READ helmet_id CONSTANT)
	Q_PROPERTY(int32_t accessory_id READ accessory_id CONSTANT)

public:
	TestBattler(ProjectData& project, lcf::rpg::TestBattler& data, QObject* parent = nullptr);

	lcf::rpg::TestBattler& data();
	int id();
	int32_t actor_id();
	int level();
	void set_level(const int& new_level);
	int32_t weapon_id();
	int32_t shield_id();
	int32_t armor_id();
	int32_t helmet_id();
	int32_t accessory_id();

signals:
	void level_changed();

protected:
	lcf::rpg::TestBattler& m_data;
};
} // namespace Binding::Generated
