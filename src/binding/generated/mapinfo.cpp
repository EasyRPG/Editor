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
#include "mapinfo.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	MapInfo::MapInfo(ProjectData& project, lcf::rpg::MapInfo& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_music = new Binding::Music(m_project, m_data.music, this);
		{
			m_encounters = new ArrayAdapter(this);
			auto& arr = m_encounters->data();
			for (auto& var: m_data.encounters)
				arr.push_back(new Binding::Encounter(m_project, var, this));
		}
		m_area_rect = new Binding::Rect(m_project, m_data.area_rect, this);
	}
	int MapInfo::id() {
		return m_data.ID;
	}
	QString MapInfo::name() {
		return ToQString(m_data.name);
	}
	void MapInfo::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	int32_t MapInfo::parent_map() {
		return m_data.parent_map;
	}

	int MapInfo::indentation() {
		return m_data.indentation;
	}
	void MapInfo::set_indentation(const int& new_indentation) {
		if (m_data.indentation == new_indentation)
			return;
		m_data.indentation = new_indentation;
		emit indentation_changed();
	}

	int32_t MapInfo::type() {
		return m_data.type;
	}

	int MapInfo::scrollbar_x() {
		return m_data.scrollbar_x;
	}
	void MapInfo::set_scrollbar_x(const int& new_scrollbar_x) {
		if (m_data.scrollbar_x == new_scrollbar_x)
			return;
		m_data.scrollbar_x = new_scrollbar_x;
		emit scrollbar_x_changed();
	}

	int MapInfo::scrollbar_y() {
		return m_data.scrollbar_y;
	}
	void MapInfo::set_scrollbar_y(const int& new_scrollbar_y) {
		if (m_data.scrollbar_y == new_scrollbar_y)
			return;
		m_data.scrollbar_y = new_scrollbar_y;
		emit scrollbar_y_changed();
	}

	bool MapInfo::expanded_node() {
		return m_data.expanded_node;
	}
	void MapInfo::set_expanded_node(const bool& new_expanded_node) {
		if (m_data.expanded_node == new_expanded_node)
			return;
		m_data.expanded_node = new_expanded_node;
		emit expanded_node_changed();
	}

	int32_t MapInfo::music_type() {
		return m_data.music_type;
	}

	Binding::Music* MapInfo::music() {
		return m_music;
	}

	int32_t MapInfo::background_type() {
		return m_data.background_type;
	}

	QString MapInfo::background_name() {
		return ToQString(m_data.background_name);
	}
	void MapInfo::set_background_name(const QString& new_background_name) {
		if (ToQString(m_data.background_name) == new_background_name)
			return;
		m_data.background_name = ToDBString(new_background_name);
		emit background_name_changed();
	}

	int32_t MapInfo::teleport() {
		return m_data.teleport;
	}

	int32_t MapInfo::escape() {
		return m_data.escape;
	}

	int32_t MapInfo::save() {
		return m_data.save;
	}

	ArrayAdapter* MapInfo::encounters() {
		return m_encounters;
	}

	int MapInfo::encounter_steps() {
		return m_data.encounter_steps;
	}
	void MapInfo::set_encounter_steps(const int& new_encounter_steps) {
		if (m_data.encounter_steps == new_encounter_steps)
			return;
		m_data.encounter_steps = new_encounter_steps;
		emit encounter_steps_changed();
	}

	Binding::Rect* MapInfo::area_rect() {
		return m_area_rect;
	}

} // namespace Binding::Generated
