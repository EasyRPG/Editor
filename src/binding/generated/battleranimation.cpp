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
#include "battleranimation.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	BattlerAnimation::BattlerAnimation(ProjectData& project, lcf::rpg::BattlerAnimation& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		for (auto& var: m_data.poses) {
			m_poses.push_back(new Binding::BattlerAnimationPose(m_project, var, this));
		}
		for (auto& var: m_data.weapons) {
			m_weapons.push_back(new Binding::BattlerAnimationWeapon(m_project, var, this));
		}
	}
	int BattlerAnimation::id() {
		return m_data.ID;
	}
	QString BattlerAnimation::name() {
		return ToQString(m_data.name);
	}
	void BattlerAnimation::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	int32_t BattlerAnimation::speed() {
		return m_data.speed;
	}

	QVector<Binding::BattlerAnimationPose*>& BattlerAnimation::poses() {
		return m_poses;
	}

	QVector<Binding::BattlerAnimationWeapon*>& BattlerAnimation::weapons() {
		return m_weapons;
	}

} // namespace Binding::Generated
