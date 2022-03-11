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

	int32_t BattlerAnimationItemSkill::type() {
		return m_data.type;
	}

	int32_t BattlerAnimationItemSkill::weapon_animation_id() {
		return m_data.weapon_animation_id;
	}

	int32_t BattlerAnimationItemSkill::movement() {
		return m_data.movement;
	}

	int32_t BattlerAnimationItemSkill::after_image() {
		return m_data.after_image;
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

	int32_t BattlerAnimationItemSkill::ranged_animation_id() {
		return m_data.ranged_animation_id;
	}

	int32_t BattlerAnimationItemSkill::ranged_speed() {
		return m_data.ranged_speed;
	}

	int32_t BattlerAnimationItemSkill::battle_animation_id() {
		return m_data.battle_animation_id;
	}

	int32_t BattlerAnimationItemSkill::pose() {
		return m_data.pose;
	}

} // namespace Binding::Generated
