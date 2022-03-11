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
#include "map.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Map::Map(ProjectData& project, lcf::rpg::Map& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_events = new ArrayAdapter(this);
			auto& arr = m_events->data();
			for (auto& var: m_data.events)
				arr.push_back(new Binding::Event(m_project, var, this));
		}
	}
	int Map::chipset_id() {
		return m_data.chipset_id;
	}
	void Map::set_chipset_id(const int& new_chipset_id) {
		if (m_data.chipset_id == new_chipset_id)
			return;
		m_data.chipset_id = new_chipset_id;
		emit chipset_id_changed();
	}

	int Map::width() {
		return m_data.width;
	}
	void Map::set_width(const int& new_width) {
		if (m_data.width == new_width)
			return;
		m_data.width = new_width;
		emit width_changed();
	}

	int Map::height() {
		return m_data.height;
	}
	void Map::set_height(const int& new_height) {
		if (m_data.height == new_height)
			return;
		m_data.height = new_height;
		emit height_changed();
	}

	int Map::scroll_type() {
		return m_data.scroll_type;
	}
	void Map::set_scroll_type(const int& new_scroll_type) {
		if (m_data.scroll_type == new_scroll_type)
			return;
		m_data.scroll_type = new_scroll_type;
		emit scroll_type_changed();
	}

	bool Map::parallax_flag() {
		return m_data.parallax_flag;
	}
	void Map::set_parallax_flag(const bool& new_parallax_flag) {
		if (m_data.parallax_flag == new_parallax_flag)
			return;
		m_data.parallax_flag = new_parallax_flag;
		emit parallax_flag_changed();
	}

	QString Map::parallax_name() {
		return ToQString(m_data.parallax_name);
	}
	void Map::set_parallax_name(const QString& new_parallax_name) {
		if (ToQString(m_data.parallax_name) == new_parallax_name)
			return;
		m_data.parallax_name = ToDBString(new_parallax_name);
		emit parallax_name_changed();
	}

	bool Map::parallax_loop_x() {
		return m_data.parallax_loop_x;
	}
	void Map::set_parallax_loop_x(const bool& new_parallax_loop_x) {
		if (m_data.parallax_loop_x == new_parallax_loop_x)
			return;
		m_data.parallax_loop_x = new_parallax_loop_x;
		emit parallax_loop_x_changed();
	}

	bool Map::parallax_loop_y() {
		return m_data.parallax_loop_y;
	}
	void Map::set_parallax_loop_y(const bool& new_parallax_loop_y) {
		if (m_data.parallax_loop_y == new_parallax_loop_y)
			return;
		m_data.parallax_loop_y = new_parallax_loop_y;
		emit parallax_loop_y_changed();
	}

	bool Map::parallax_auto_loop_x() {
		return m_data.parallax_auto_loop_x;
	}
	void Map::set_parallax_auto_loop_x(const bool& new_parallax_auto_loop_x) {
		if (m_data.parallax_auto_loop_x == new_parallax_auto_loop_x)
			return;
		m_data.parallax_auto_loop_x = new_parallax_auto_loop_x;
		emit parallax_auto_loop_x_changed();
	}

	int Map::parallax_sx() {
		return m_data.parallax_sx;
	}
	void Map::set_parallax_sx(const int& new_parallax_sx) {
		if (m_data.parallax_sx == new_parallax_sx)
			return;
		m_data.parallax_sx = new_parallax_sx;
		emit parallax_sx_changed();
	}

	bool Map::parallax_auto_loop_y() {
		return m_data.parallax_auto_loop_y;
	}
	void Map::set_parallax_auto_loop_y(const bool& new_parallax_auto_loop_y) {
		if (m_data.parallax_auto_loop_y == new_parallax_auto_loop_y)
			return;
		m_data.parallax_auto_loop_y = new_parallax_auto_loop_y;
		emit parallax_auto_loop_y_changed();
	}

	int Map::parallax_sy() {
		return m_data.parallax_sy;
	}
	void Map::set_parallax_sy(const int& new_parallax_sy) {
		if (m_data.parallax_sy == new_parallax_sy)
			return;
		m_data.parallax_sy = new_parallax_sy;
		emit parallax_sy_changed();
	}

	bool Map::generator_flag() {
		return m_data.generator_flag;
	}
	void Map::set_generator_flag(const bool& new_generator_flag) {
		if (m_data.generator_flag == new_generator_flag)
			return;
		m_data.generator_flag = new_generator_flag;
		emit generator_flag_changed();
	}

	int Map::generator_mode() {
		return m_data.generator_mode;
	}
	void Map::set_generator_mode(const int& new_generator_mode) {
		if (m_data.generator_mode == new_generator_mode)
			return;
		m_data.generator_mode = new_generator_mode;
		emit generator_mode_changed();
	}

	bool Map::top_level() {
		return m_data.top_level;
	}
	void Map::set_top_level(const bool& new_top_level) {
		if (m_data.top_level == new_top_level)
			return;
		m_data.top_level = new_top_level;
		emit top_level_changed();
	}

	int Map::generator_tiles() {
		return m_data.generator_tiles;
	}
	void Map::set_generator_tiles(const int& new_generator_tiles) {
		if (m_data.generator_tiles == new_generator_tiles)
			return;
		m_data.generator_tiles = new_generator_tiles;
		emit generator_tiles_changed();
	}

	int Map::generator_width() {
		return m_data.generator_width;
	}
	void Map::set_generator_width(const int& new_generator_width) {
		if (m_data.generator_width == new_generator_width)
			return;
		m_data.generator_width = new_generator_width;
		emit generator_width_changed();
	}

	int Map::generator_height() {
		return m_data.generator_height;
	}
	void Map::set_generator_height(const int& new_generator_height) {
		if (m_data.generator_height == new_generator_height)
			return;
		m_data.generator_height = new_generator_height;
		emit generator_height_changed();
	}

	bool Map::generator_surround() {
		return m_data.generator_surround;
	}
	void Map::set_generator_surround(const bool& new_generator_surround) {
		if (m_data.generator_surround == new_generator_surround)
			return;
		m_data.generator_surround = new_generator_surround;
		emit generator_surround_changed();
	}

	bool Map::generator_upper_wall() {
		return m_data.generator_upper_wall;
	}
	void Map::set_generator_upper_wall(const bool& new_generator_upper_wall) {
		if (m_data.generator_upper_wall == new_generator_upper_wall)
			return;
		m_data.generator_upper_wall = new_generator_upper_wall;
		emit generator_upper_wall_changed();
	}

	bool Map::generator_floor_b() {
		return m_data.generator_floor_b;
	}
	void Map::set_generator_floor_b(const bool& new_generator_floor_b) {
		if (m_data.generator_floor_b == new_generator_floor_b)
			return;
		m_data.generator_floor_b = new_generator_floor_b;
		emit generator_floor_b_changed();
	}

	bool Map::generator_floor_c() {
		return m_data.generator_floor_c;
	}
	void Map::set_generator_floor_c(const bool& new_generator_floor_c) {
		if (m_data.generator_floor_c == new_generator_floor_c)
			return;
		m_data.generator_floor_c = new_generator_floor_c;
		emit generator_floor_c_changed();
	}

	bool Map::generator_extra_b() {
		return m_data.generator_extra_b;
	}
	void Map::set_generator_extra_b(const bool& new_generator_extra_b) {
		if (m_data.generator_extra_b == new_generator_extra_b)
			return;
		m_data.generator_extra_b = new_generator_extra_b;
		emit generator_extra_b_changed();
	}

	bool Map::generator_extra_c() {
		return m_data.generator_extra_c;
	}
	void Map::set_generator_extra_c(const bool& new_generator_extra_c) {
		if (m_data.generator_extra_c == new_generator_extra_c)
			return;
		m_data.generator_extra_c = new_generator_extra_c;
		emit generator_extra_c_changed();
	}

	QVector<int> Map::generator_x() {
		return QVector<int>(m_data.generator_x.begin(), m_data.generator_x.end());
	}
	void Map::set_generator_x(const QVector<int>& new_generator_x) {
		if (QVector<int>(m_data.generator_x.begin(), m_data.generator_x.end()) == new_generator_x)
			return;
		m_data.generator_x = decltype(m_data.generator_x)(new_generator_x.begin(), new_generator_x.end());
		emit generator_x_changed();
	}

	QVector<int> Map::generator_y() {
		return QVector<int>(m_data.generator_y.begin(), m_data.generator_y.end());
	}
	void Map::set_generator_y(const QVector<int>& new_generator_y) {
		if (QVector<int>(m_data.generator_y.begin(), m_data.generator_y.end()) == new_generator_y)
			return;
		m_data.generator_y = decltype(m_data.generator_y)(new_generator_y.begin(), new_generator_y.end());
		emit generator_y_changed();
	}

	QVector<int> Map::generator_tile_ids() {
		return QVector<int>(m_data.generator_tile_ids.begin(), m_data.generator_tile_ids.end());
	}
	void Map::set_generator_tile_ids(const QVector<int>& new_generator_tile_ids) {
		if (QVector<int>(m_data.generator_tile_ids.begin(), m_data.generator_tile_ids.end()) == new_generator_tile_ids)
			return;
		m_data.generator_tile_ids = decltype(m_data.generator_tile_ids)(new_generator_tile_ids.begin(), new_generator_tile_ids.end());
		emit generator_tile_ids_changed();
	}

	QVector<int> Map::lower_layer() {
		return QVector<int>(m_data.lower_layer.begin(), m_data.lower_layer.end());
	}
	void Map::set_lower_layer(const QVector<int>& new_lower_layer) {
		if (QVector<int>(m_data.lower_layer.begin(), m_data.lower_layer.end()) == new_lower_layer)
			return;
		m_data.lower_layer = decltype(m_data.lower_layer)(new_lower_layer.begin(), new_lower_layer.end());
		emit lower_layer_changed();
	}

	QVector<int> Map::upper_layer() {
		return QVector<int>(m_data.upper_layer.begin(), m_data.upper_layer.end());
	}
	void Map::set_upper_layer(const QVector<int>& new_upper_layer) {
		if (QVector<int>(m_data.upper_layer.begin(), m_data.upper_layer.end()) == new_upper_layer)
			return;
		m_data.upper_layer = decltype(m_data.upper_layer)(new_upper_layer.begin(), new_upper_layer.end());
		emit upper_layer_changed();
	}

	ArrayAdapter* Map::events() {
		return m_events;
	}

	int Map::save_count_2k3e() {
		return m_data.save_count_2k3e;
	}
	void Map::set_save_count_2k3e(const int& new_save_count_2k3e) {
		if (m_data.save_count_2k3e == new_save_count_2k3e)
			return;
		m_data.save_count_2k3e = new_save_count_2k3e;
		emit save_count_2k3e_changed();
	}

	int Map::save_count() {
		return m_data.save_count;
	}
	void Map::set_save_count(const int& new_save_count) {
		if (m_data.save_count == new_save_count)
			return;
		m_data.save_count = new_save_count;
		emit save_count_changed();
	}

} // namespace Binding::Generated
