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
		{
			m_poses = new ArrayAdapter(this);
			auto& arr = m_poses->data();
			for (auto& var: m_data.poses)
				arr.push_back(new Binding::BattlerAnimationPose(m_project, var, this));
		}
		{
			m_weapons = new ArrayAdapter(this);
			auto& arr = m_weapons->data();
			for (auto& var: m_data.weapons)
				arr.push_back(new Binding::BattlerAnimationWeapon(m_project, var, this));
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

	int BattlerAnimation::speed() {
		return m_data.speed;
	}
	void BattlerAnimation::set_speed(const int& new_speed) {
		if (m_data.speed == new_speed)
			return;
		m_data.speed = new_speed;
		emit speed_changed();
	}

	ArrayAdapter* BattlerAnimation::poses() {
		return m_poses;
	}

	ArrayAdapter* BattlerAnimation::weapons() {
		return m_weapons;
	}

} // namespace Binding::Generated
