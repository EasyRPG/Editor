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
#include "battleranimationpose.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	BattlerAnimationPose::BattlerAnimationPose(ProjectData& project, lcf::rpg::BattlerAnimationPose& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int BattlerAnimationPose::id() {
		return m_data.ID;
	}
	QString BattlerAnimationPose::name() {
		return ToQString(m_data.name);
	}
	void BattlerAnimationPose::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	QString BattlerAnimationPose::battler_name() {
		return ToQString(m_data.battler_name);
	}
	void BattlerAnimationPose::set_battler_name(const QString& new_battler_name) {
		if (ToQString(m_data.battler_name) == new_battler_name)
			return;
		m_data.battler_name = ToDBString(new_battler_name);
		emit battler_name_changed();
	}

	int BattlerAnimationPose::battler_index() {
		return m_data.battler_index;
	}
	void BattlerAnimationPose::set_battler_index(const int& new_battler_index) {
		if (m_data.battler_index == new_battler_index)
			return;
		m_data.battler_index = new_battler_index;
		emit battler_index_changed();
	}

	int BattlerAnimationPose::animation_type() {
		return m_data.animation_type;
	}
	void BattlerAnimationPose::set_animation_type(const int& new_animation_type) {
		if (m_data.animation_type == new_animation_type)
			return;
		m_data.animation_type = new_animation_type;
		emit animation_type_changed();
	}

	int BattlerAnimationPose::battle_animation_id() {
		return m_data.battle_animation_id;
	}
	void BattlerAnimationPose::set_battle_animation_id(const int& new_battle_animation_id) {
		if (m_data.battle_animation_id == new_battle_animation_id)
			return;
		m_data.battle_animation_id = new_battle_animation_id;
		emit battle_animation_id_changed();
	}

} // namespace Binding::Generated
