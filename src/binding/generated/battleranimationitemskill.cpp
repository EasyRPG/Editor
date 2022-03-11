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

// Headers
#include "battleranimationitemskill.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	BattlerAnimationItemSkill::BattlerAnimationItemSkill(ProjectData& project, lcf::rpg::BattlerAnimationItemSkill& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int BattlerAnimationItemSkill::id() {
		return m_data.ID;
	}
	int BattlerAnimationItemSkill::unknown02() {
		return m_data.unknown02;
	}
	void BattlerAnimationItemSkill::set_unknown02(const int& new_unknown02) {
		if (m_data.unknown02 == new_unknown02)
			return;
		m_data.unknown02 = new_unknown02;
		emit unknown02_changed();
	}

	int BattlerAnimationItemSkill::type() {
		return m_data.type;
	}
	void BattlerAnimationItemSkill::set_type(const int& new_type) {
		if (m_data.type == new_type)
			return;
		m_data.type = new_type;
		emit type_changed();
	}

	int BattlerAnimationItemSkill::weapon_animation_id() {
		return m_data.weapon_animation_id;
	}
	void BattlerAnimationItemSkill::set_weapon_animation_id(const int& new_weapon_animation_id) {
		if (m_data.weapon_animation_id == new_weapon_animation_id)
			return;
		m_data.weapon_animation_id = new_weapon_animation_id;
		emit weapon_animation_id_changed();
	}

	int BattlerAnimationItemSkill::movement() {
		return m_data.movement;
	}
	void BattlerAnimationItemSkill::set_movement(const int& new_movement) {
		if (m_data.movement == new_movement)
			return;
		m_data.movement = new_movement;
		emit movement_changed();
	}

	int BattlerAnimationItemSkill::after_image() {
		return m_data.after_image;
	}
	void BattlerAnimationItemSkill::set_after_image(const int& new_after_image) {
		if (m_data.after_image == new_after_image)
			return;
		m_data.after_image = new_after_image;
		emit after_image_changed();
	}

	int BattlerAnimationItemSkill::attacks() {
		return m_data.attacks;
	}
	void BattlerAnimationItemSkill::set_attacks(const int& new_attacks) {
		if (m_data.attacks == new_attacks)
			return;
		m_data.attacks = new_attacks;
		emit attacks_changed();
	}

	bool BattlerAnimationItemSkill::ranged() {
		return m_data.ranged;
	}
	void BattlerAnimationItemSkill::set_ranged(const bool& new_ranged) {
		if (m_data.ranged == new_ranged)
			return;
		m_data.ranged = new_ranged;
		emit ranged_changed();
	}

	int BattlerAnimationItemSkill::ranged_animation_id() {
		return m_data.ranged_animation_id;
	}
	void BattlerAnimationItemSkill::set_ranged_animation_id(const int& new_ranged_animation_id) {
		if (m_data.ranged_animation_id == new_ranged_animation_id)
			return;
		m_data.ranged_animation_id = new_ranged_animation_id;
		emit ranged_animation_id_changed();
	}

	int BattlerAnimationItemSkill::ranged_speed() {
		return m_data.ranged_speed;
	}
	void BattlerAnimationItemSkill::set_ranged_speed(const int& new_ranged_speed) {
		if (m_data.ranged_speed == new_ranged_speed)
			return;
		m_data.ranged_speed = new_ranged_speed;
		emit ranged_speed_changed();
	}

	int BattlerAnimationItemSkill::battle_animation_id() {
		return m_data.battle_animation_id;
	}
	void BattlerAnimationItemSkill::set_battle_animation_id(const int& new_battle_animation_id) {
		if (m_data.battle_animation_id == new_battle_animation_id)
			return;
		m_data.battle_animation_id = new_battle_animation_id;
		emit battle_animation_id_changed();
	}

	int BattlerAnimationItemSkill::pose() {
		return m_data.pose;
	}
	void BattlerAnimationItemSkill::set_pose(const int& new_pose) {
		if (m_data.pose == new_pose)
			return;
		m_data.pose = new_pose;
		emit pose_changed();
	}

} // namespace Binding::Generated
