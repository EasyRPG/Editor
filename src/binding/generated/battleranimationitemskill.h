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
#include <lcf/rpg/battleranimationitemskill.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::BattlerAnimationItemSkill class.
 * Exposes lcf::rpg::BattlerAnimationItemSkill to QML.
 */
namespace Binding::Generated {
class BattlerAnimationItemSkill : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(int unknown02 READ unknown02 WRITE set_unknown02 NOTIFY unknown02_changed)
	Q_PROPERTY(int32_t type READ type CONSTANT)
	Q_PROPERTY(int32_t weapon_animation_id READ weapon_animation_id CONSTANT)
	Q_PROPERTY(int32_t movement READ movement CONSTANT)
	Q_PROPERTY(int32_t after_image READ after_image CONSTANT)
	Q_PROPERTY(int attacks READ attacks WRITE set_attacks NOTIFY attacks_changed)
	Q_PROPERTY(bool ranged READ ranged WRITE set_ranged NOTIFY ranged_changed)
	Q_PROPERTY(int32_t ranged_animation_id READ ranged_animation_id CONSTANT)
	Q_PROPERTY(int32_t ranged_speed READ ranged_speed CONSTANT)
	Q_PROPERTY(int32_t battle_animation_id READ battle_animation_id CONSTANT)
	Q_PROPERTY(int32_t pose READ pose CONSTANT)

public:
	BattlerAnimationItemSkill(ProjectData& project, lcf::rpg::BattlerAnimationItemSkill& data, QObject* parent = nullptr);

	lcf::rpg::BattlerAnimationItemSkill& data();
	int id();
	int unknown02();
	void set_unknown02(const int& new_unknown02);
	int32_t type();
	int32_t weapon_animation_id();
	int32_t movement();
	int32_t after_image();
	int attacks();
	void set_attacks(const int& new_attacks);
	bool ranged();
	void set_ranged(const bool& new_ranged);
	int32_t ranged_animation_id();
	int32_t ranged_speed();
	int32_t battle_animation_id();
	int32_t pose();

signals:
	void unknown02_changed();
	void attacks_changed();
	void ranged_changed();

protected:
	lcf::rpg::BattlerAnimationItemSkill& m_data;
};
} // namespace Binding::Generated
