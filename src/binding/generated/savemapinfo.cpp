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
#include "savemapinfo.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveMapInfo::SaveMapInfo(ProjectData& project, lcf::rpg::SaveMapInfo& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_events = new ArrayAdapter(this);
			auto& arr = m_events->data();
			for (auto& var: m_data.events)
				arr.push_back(new Binding::SaveMapEvent(m_project, var, this));
		}
	}
	int SaveMapInfo::position_x() {
		return m_data.position_x;
	}
	void SaveMapInfo::set_position_x(const int& new_position_x) {
		if (m_data.position_x == new_position_x)
			return;
		m_data.position_x = new_position_x;
		emit position_x_changed();
	}

	int SaveMapInfo::position_y() {
		return m_data.position_y;
	}
	void SaveMapInfo::set_position_y(const int& new_position_y) {
		if (m_data.position_y == new_position_y)
			return;
		m_data.position_y = new_position_y;
		emit position_y_changed();
	}

	int SaveMapInfo::encounter_rate() {
		return m_data.encounter_rate;
	}
	void SaveMapInfo::set_encounter_rate(const int& new_encounter_rate) {
		if (m_data.encounter_rate == new_encounter_rate)
			return;
		m_data.encounter_rate = new_encounter_rate;
		emit encounter_rate_changed();
	}

	int SaveMapInfo::chipset_id() {
		return m_data.chipset_id;
	}
	void SaveMapInfo::set_chipset_id(const int& new_chipset_id) {
		if (m_data.chipset_id == new_chipset_id)
			return;
		m_data.chipset_id = new_chipset_id;
		emit chipset_id_changed();
	}

	ArrayAdapter* SaveMapInfo::events() {
		return m_events;
	}

	QVector<int> SaveMapInfo::lower_tiles() {
		return QVector<int>(m_data.lower_tiles.begin(), m_data.lower_tiles.end());
	}
	void SaveMapInfo::set_lower_tiles(const QVector<int>& new_lower_tiles) {
		if (QVector<int>(m_data.lower_tiles.begin(), m_data.lower_tiles.end()) == new_lower_tiles)
			return;
		m_data.lower_tiles = decltype(m_data.lower_tiles)(new_lower_tiles.begin(), new_lower_tiles.end());
		emit lower_tiles_changed();
	}

	QVector<int> SaveMapInfo::upper_tiles() {
		return QVector<int>(m_data.upper_tiles.begin(), m_data.upper_tiles.end());
	}
	void SaveMapInfo::set_upper_tiles(const QVector<int>& new_upper_tiles) {
		if (QVector<int>(m_data.upper_tiles.begin(), m_data.upper_tiles.end()) == new_upper_tiles)
			return;
		m_data.upper_tiles = decltype(m_data.upper_tiles)(new_upper_tiles.begin(), new_upper_tiles.end());
		emit upper_tiles_changed();
	}

	QString SaveMapInfo::parallax_name() {
		return QString::fromStdString(m_data.parallax_name);
	}
	void SaveMapInfo::set_parallax_name(const QString& new_parallax_name) {
		if (QString::fromStdString(m_data.parallax_name) == new_parallax_name)
			return;
		m_data.parallax_name = new_parallax_name.toStdString();
		emit parallax_name_changed();
	}

	bool SaveMapInfo::parallax_horz() {
		return m_data.parallax_horz;
	}
	void SaveMapInfo::set_parallax_horz(const bool& new_parallax_horz) {
		if (m_data.parallax_horz == new_parallax_horz)
			return;
		m_data.parallax_horz = new_parallax_horz;
		emit parallax_horz_changed();
	}

	bool SaveMapInfo::parallax_vert() {
		return m_data.parallax_vert;
	}
	void SaveMapInfo::set_parallax_vert(const bool& new_parallax_vert) {
		if (m_data.parallax_vert == new_parallax_vert)
			return;
		m_data.parallax_vert = new_parallax_vert;
		emit parallax_vert_changed();
	}

	bool SaveMapInfo::parallax_horz_auto() {
		return m_data.parallax_horz_auto;
	}
	void SaveMapInfo::set_parallax_horz_auto(const bool& new_parallax_horz_auto) {
		if (m_data.parallax_horz_auto == new_parallax_horz_auto)
			return;
		m_data.parallax_horz_auto = new_parallax_horz_auto;
		emit parallax_horz_auto_changed();
	}

	int SaveMapInfo::parallax_horz_speed() {
		return m_data.parallax_horz_speed;
	}
	void SaveMapInfo::set_parallax_horz_speed(const int& new_parallax_horz_speed) {
		if (m_data.parallax_horz_speed == new_parallax_horz_speed)
			return;
		m_data.parallax_horz_speed = new_parallax_horz_speed;
		emit parallax_horz_speed_changed();
	}

	bool SaveMapInfo::parallax_vert_auto() {
		return m_data.parallax_vert_auto;
	}
	void SaveMapInfo::set_parallax_vert_auto(const bool& new_parallax_vert_auto) {
		if (m_data.parallax_vert_auto == new_parallax_vert_auto)
			return;
		m_data.parallax_vert_auto = new_parallax_vert_auto;
		emit parallax_vert_auto_changed();
	}

	int SaveMapInfo::parallax_vert_speed() {
		return m_data.parallax_vert_speed;
	}
	void SaveMapInfo::set_parallax_vert_speed(const int& new_parallax_vert_speed) {
		if (m_data.parallax_vert_speed == new_parallax_vert_speed)
			return;
		m_data.parallax_vert_speed = new_parallax_vert_speed;
		emit parallax_vert_speed_changed();
	}

} // namespace Binding::Generated
