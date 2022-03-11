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
#include "chipset.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Chipset::Chipset(ProjectData& project, lcf::rpg::Chipset& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int Chipset::id() {
		return m_data.ID;
	}
	QString Chipset::name() {
		return ToQString(m_data.name);
	}
	void Chipset::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	QString Chipset::chipset_name() {
		return ToQString(m_data.chipset_name);
	}
	void Chipset::set_chipset_name(const QString& new_chipset_name) {
		if (ToQString(m_data.chipset_name) == new_chipset_name)
			return;
		m_data.chipset_name = ToDBString(new_chipset_name);
		emit chipset_name_changed();
	}

	QVector<int> Chipset::terrain_data() {
		return QVector<int>(m_data.terrain_data.begin(), m_data.terrain_data.end());
	}
	void Chipset::set_terrain_data(const QVector<int>& new_terrain_data) {
		if (QVector<int>(m_data.terrain_data.begin(), m_data.terrain_data.end()) == new_terrain_data)
			return;
		m_data.terrain_data = decltype(m_data.terrain_data)(new_terrain_data.begin(), new_terrain_data.end());
		emit terrain_data_changed();
	}

	QVector<int> Chipset::passable_data_lower() {
		return QVector<int>(m_data.passable_data_lower.begin(), m_data.passable_data_lower.end());
	}
	void Chipset::set_passable_data_lower(const QVector<int>& new_passable_data_lower) {
		if (QVector<int>(m_data.passable_data_lower.begin(), m_data.passable_data_lower.end()) == new_passable_data_lower)
			return;
		m_data.passable_data_lower = decltype(m_data.passable_data_lower)(new_passable_data_lower.begin(), new_passable_data_lower.end());
		emit passable_data_lower_changed();
	}

	QVector<int> Chipset::passable_data_upper() {
		return QVector<int>(m_data.passable_data_upper.begin(), m_data.passable_data_upper.end());
	}
	void Chipset::set_passable_data_upper(const QVector<int>& new_passable_data_upper) {
		if (QVector<int>(m_data.passable_data_upper.begin(), m_data.passable_data_upper.end()) == new_passable_data_upper)
			return;
		m_data.passable_data_upper = decltype(m_data.passable_data_upper)(new_passable_data_upper.begin(), new_passable_data_upper.end());
		emit passable_data_upper_changed();
	}

	int32_t Chipset::animation_type() {
		return m_data.animation_type;
	}

	int Chipset::animation_speed() {
		return m_data.animation_speed;
	}
	void Chipset::set_animation_speed(const int& new_animation_speed) {
		if (m_data.animation_speed == new_animation_speed)
			return;
		m_data.animation_speed = new_animation_speed;
		emit animation_speed_changed();
	}

} // namespace Binding::Generated
