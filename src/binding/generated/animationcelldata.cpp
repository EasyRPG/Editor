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
#include "animationcelldata.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	AnimationCellData::AnimationCellData(ProjectData& project, lcf::rpg::AnimationCellData& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int AnimationCellData::id() {
		return m_data.ID;
	}
	int AnimationCellData::valid() {
		return m_data.valid;
	}
	void AnimationCellData::set_valid(const int& new_valid) {
		if (m_data.valid == new_valid)
			return;
		m_data.valid = new_valid;
		emit valid_changed();
	}

	int AnimationCellData::cell_id() {
		return m_data.cell_id;
	}
	void AnimationCellData::set_cell_id(const int& new_cell_id) {
		if (m_data.cell_id == new_cell_id)
			return;
		m_data.cell_id = new_cell_id;
		emit cell_id_changed();
	}

	int AnimationCellData::x() {
		return m_data.x;
	}
	void AnimationCellData::set_x(const int& new_x) {
		if (m_data.x == new_x)
			return;
		m_data.x = new_x;
		emit x_changed();
	}

	int AnimationCellData::y() {
		return m_data.y;
	}
	void AnimationCellData::set_y(const int& new_y) {
		if (m_data.y == new_y)
			return;
		m_data.y = new_y;
		emit y_changed();
	}

	int AnimationCellData::zoom() {
		return m_data.zoom;
	}
	void AnimationCellData::set_zoom(const int& new_zoom) {
		if (m_data.zoom == new_zoom)
			return;
		m_data.zoom = new_zoom;
		emit zoom_changed();
	}

	int AnimationCellData::tone_red() {
		return m_data.tone_red;
	}
	void AnimationCellData::set_tone_red(const int& new_tone_red) {
		if (m_data.tone_red == new_tone_red)
			return;
		m_data.tone_red = new_tone_red;
		emit tone_red_changed();
	}

	int AnimationCellData::tone_green() {
		return m_data.tone_green;
	}
	void AnimationCellData::set_tone_green(const int& new_tone_green) {
		if (m_data.tone_green == new_tone_green)
			return;
		m_data.tone_green = new_tone_green;
		emit tone_green_changed();
	}

	int AnimationCellData::tone_blue() {
		return m_data.tone_blue;
	}
	void AnimationCellData::set_tone_blue(const int& new_tone_blue) {
		if (m_data.tone_blue == new_tone_blue)
			return;
		m_data.tone_blue = new_tone_blue;
		emit tone_blue_changed();
	}

	int AnimationCellData::tone_gray() {
		return m_data.tone_gray;
	}
	void AnimationCellData::set_tone_gray(const int& new_tone_gray) {
		if (m_data.tone_gray == new_tone_gray)
			return;
		m_data.tone_gray = new_tone_gray;
		emit tone_gray_changed();
	}

	int AnimationCellData::transparency() {
		return m_data.transparency;
	}
	void AnimationCellData::set_transparency(const int& new_transparency) {
		if (m_data.transparency == new_transparency)
			return;
		m_data.transparency = new_transparency;
		emit transparency_changed();
	}

} // namespace Binding::Generated
