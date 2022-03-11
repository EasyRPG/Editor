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
	Q_PROPERTY(int type READ type WRITE set_type NOTIFY type_changed)
	Q_PROPERTY(int weapon_animation_id READ weapon_animation_id WRITE set_weapon_animation_id NOTIFY weapon_animation_id_changed)
	Q_PROPERTY(int movement READ movement WRITE set_movement NOTIFY movement_changed)
	Q_PROPERTY(int after_image READ after_image WRITE set_after_image NOTIFY after_image_changed)
	Q_PROPERTY(int attacks READ attacks WRITE set_attacks NOTIFY attacks_changed)
	Q_PROPERTY(bool ranged READ ranged WRITE set_ranged NOTIFY ranged_changed)
	Q_PROPERTY(int ranged_animation_id READ ranged_animation_id WRITE set_ranged_animation_id NOTIFY ranged_animation_id_changed)
	Q_PROPERTY(int ranged_speed READ ranged_speed WRITE set_ranged_speed NOTIFY ranged_speed_changed)
	Q_PROPERTY(int battle_animation_id READ battle_animation_id WRITE set_battle_animation_id NOTIFY battle_animation_id_changed)
	Q_PROPERTY(int pose READ pose WRITE set_pose NOTIFY pose_changed)

public:
	BattlerAnimationItemSkill(ProjectData& project, lcf::rpg::BattlerAnimationItemSkill& data, QObject* parent = nullptr);

	lcf::rpg::BattlerAnimationItemSkill& data();
	int id();
	int unknown02();
	void set_unknown02(const int& new_unknown02);
	int type();
	void set_type(const int& new_type);
	int weapon_animation_id();
	void set_weapon_animation_id(const int& new_weapon_animation_id);
	int movement();
	void set_movement(const int& new_movement);
	int after_image();
	void set_after_image(const int& new_after_image);
	int attacks();
	void set_attacks(const int& new_attacks);
	bool ranged();
	void set_ranged(const bool& new_ranged);
	int ranged_animation_id();
	void set_ranged_animation_id(const int& new_ranged_animation_id);
	int ranged_speed();
	void set_ranged_speed(const int& new_ranged_speed);
	int battle_animation_id();
	void set_battle_animation_id(const int& new_battle_animation_id);
	int pose();
	void set_pose(const int& new_pose);

signals:
	void unknown02_changed();
	void type_changed();
	void weapon_animation_id_changed();
	void movement_changed();
	void after_image_changed();
	void attacks_changed();
	void ranged_changed();
	void ranged_animation_id_changed();
	void ranged_speed_changed();
	void battle_animation_id_changed();
	void pose_changed();

protected:
	lcf::rpg::BattlerAnimationItemSkill& m_data;
};
} // namespace Binding::Generated
