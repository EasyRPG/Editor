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

#pragma once

// Headers
#include <lcf/rpg/map.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/event.h"

class ProjectData;

/**
 * Binding::Generated::Map class.
 * Exposes lcf::rpg::Map to QML.
 */
namespace Binding::Generated {
class Map : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int chipset_id READ chipset_id WRITE set_chipset_id NOTIFY chipset_id_changed)
	Q_PROPERTY(int width READ width WRITE set_width NOTIFY width_changed)
	Q_PROPERTY(int height READ height WRITE set_height NOTIFY height_changed)
	Q_PROPERTY(int scroll_type READ scroll_type WRITE set_scroll_type NOTIFY scroll_type_changed)
	Q_PROPERTY(bool parallax_flag READ parallax_flag WRITE set_parallax_flag NOTIFY parallax_flag_changed)
	Q_PROPERTY(QString parallax_name READ parallax_name WRITE set_parallax_name NOTIFY parallax_name_changed)
	Q_PROPERTY(bool parallax_loop_x READ parallax_loop_x WRITE set_parallax_loop_x NOTIFY parallax_loop_x_changed)
	Q_PROPERTY(bool parallax_loop_y READ parallax_loop_y WRITE set_parallax_loop_y NOTIFY parallax_loop_y_changed)
	Q_PROPERTY(bool parallax_auto_loop_x READ parallax_auto_loop_x WRITE set_parallax_auto_loop_x NOTIFY parallax_auto_loop_x_changed)
	Q_PROPERTY(int parallax_sx READ parallax_sx WRITE set_parallax_sx NOTIFY parallax_sx_changed)
	Q_PROPERTY(bool parallax_auto_loop_y READ parallax_auto_loop_y WRITE set_parallax_auto_loop_y NOTIFY parallax_auto_loop_y_changed)
	Q_PROPERTY(int parallax_sy READ parallax_sy WRITE set_parallax_sy NOTIFY parallax_sy_changed)
	Q_PROPERTY(bool generator_flag READ generator_flag WRITE set_generator_flag NOTIFY generator_flag_changed)
	Q_PROPERTY(int generator_mode READ generator_mode WRITE set_generator_mode NOTIFY generator_mode_changed)
	Q_PROPERTY(bool top_level READ top_level WRITE set_top_level NOTIFY top_level_changed)
	Q_PROPERTY(int generator_tiles READ generator_tiles WRITE set_generator_tiles NOTIFY generator_tiles_changed)
	Q_PROPERTY(int generator_width READ generator_width WRITE set_generator_width NOTIFY generator_width_changed)
	Q_PROPERTY(int generator_height READ generator_height WRITE set_generator_height NOTIFY generator_height_changed)
	Q_PROPERTY(bool generator_surround READ generator_surround WRITE set_generator_surround NOTIFY generator_surround_changed)
	Q_PROPERTY(bool generator_upper_wall READ generator_upper_wall WRITE set_generator_upper_wall NOTIFY generator_upper_wall_changed)
	Q_PROPERTY(bool generator_floor_b READ generator_floor_b WRITE set_generator_floor_b NOTIFY generator_floor_b_changed)
	Q_PROPERTY(bool generator_floor_c READ generator_floor_c WRITE set_generator_floor_c NOTIFY generator_floor_c_changed)
	Q_PROPERTY(bool generator_extra_b READ generator_extra_b WRITE set_generator_extra_b NOTIFY generator_extra_b_changed)
	Q_PROPERTY(bool generator_extra_c READ generator_extra_c WRITE set_generator_extra_c NOTIFY generator_extra_c_changed)
	Q_PROPERTY(QVector<int> generator_x READ generator_x WRITE set_generator_x NOTIFY generator_x_changed)
	Q_PROPERTY(QVector<int> generator_y READ generator_y WRITE set_generator_y NOTIFY generator_y_changed)
	Q_PROPERTY(QVector<int> generator_tile_ids READ generator_tile_ids WRITE set_generator_tile_ids NOTIFY generator_tile_ids_changed)
	Q_PROPERTY(QVector<int> lower_layer READ lower_layer WRITE set_lower_layer NOTIFY lower_layer_changed)
	Q_PROPERTY(QVector<int> upper_layer READ upper_layer WRITE set_upper_layer NOTIFY upper_layer_changed)
	Q_PROPERTY(ArrayAdapter* events READ events CONSTANT)
	Q_PROPERTY(int save_count_2k3e READ save_count_2k3e WRITE set_save_count_2k3e NOTIFY save_count_2k3e_changed)
	Q_PROPERTY(int save_count READ save_count WRITE set_save_count NOTIFY save_count_changed)

public:
	Map(ProjectData& project, lcf::rpg::Map& data, QObject* parent = nullptr);

	lcf::rpg::Map& data();
	int chipset_id();
	void set_chipset_id(const int& new_chipset_id);
	int width();
	void set_width(const int& new_width);
	int height();
	void set_height(const int& new_height);
	int scroll_type();
	void set_scroll_type(const int& new_scroll_type);
	bool parallax_flag();
	void set_parallax_flag(const bool& new_parallax_flag);
	QString parallax_name();
	void set_parallax_name(const QString& new_parallax_name);
	bool parallax_loop_x();
	void set_parallax_loop_x(const bool& new_parallax_loop_x);
	bool parallax_loop_y();
	void set_parallax_loop_y(const bool& new_parallax_loop_y);
	bool parallax_auto_loop_x();
	void set_parallax_auto_loop_x(const bool& new_parallax_auto_loop_x);
	int parallax_sx();
	void set_parallax_sx(const int& new_parallax_sx);
	bool parallax_auto_loop_y();
	void set_parallax_auto_loop_y(const bool& new_parallax_auto_loop_y);
	int parallax_sy();
	void set_parallax_sy(const int& new_parallax_sy);
	bool generator_flag();
	void set_generator_flag(const bool& new_generator_flag);
	int generator_mode();
	void set_generator_mode(const int& new_generator_mode);
	bool top_level();
	void set_top_level(const bool& new_top_level);
	int generator_tiles();
	void set_generator_tiles(const int& new_generator_tiles);
	int generator_width();
	void set_generator_width(const int& new_generator_width);
	int generator_height();
	void set_generator_height(const int& new_generator_height);
	bool generator_surround();
	void set_generator_surround(const bool& new_generator_surround);
	bool generator_upper_wall();
	void set_generator_upper_wall(const bool& new_generator_upper_wall);
	bool generator_floor_b();
	void set_generator_floor_b(const bool& new_generator_floor_b);
	bool generator_floor_c();
	void set_generator_floor_c(const bool& new_generator_floor_c);
	bool generator_extra_b();
	void set_generator_extra_b(const bool& new_generator_extra_b);
	bool generator_extra_c();
	void set_generator_extra_c(const bool& new_generator_extra_c);
	QVector<int> generator_x();
	void set_generator_x(const QVector<int>& new_generator_x);
	QVector<int> generator_y();
	void set_generator_y(const QVector<int>& new_generator_y);
	QVector<int> generator_tile_ids();
	void set_generator_tile_ids(const QVector<int>& new_generator_tile_ids);
	QVector<int> lower_layer();
	void set_lower_layer(const QVector<int>& new_lower_layer);
	QVector<int> upper_layer();
	void set_upper_layer(const QVector<int>& new_upper_layer);
	ArrayAdapter* events();
	int save_count_2k3e();
	void set_save_count_2k3e(const int& new_save_count_2k3e);
	int save_count();
	void set_save_count(const int& new_save_count);

signals:
	void chipset_id_changed();
	void width_changed();
	void height_changed();
	void scroll_type_changed();
	void parallax_flag_changed();
	void parallax_name_changed();
	void parallax_loop_x_changed();
	void parallax_loop_y_changed();
	void parallax_auto_loop_x_changed();
	void parallax_sx_changed();
	void parallax_auto_loop_y_changed();
	void parallax_sy_changed();
	void generator_flag_changed();
	void generator_mode_changed();
	void top_level_changed();
	void generator_tiles_changed();
	void generator_width_changed();
	void generator_height_changed();
	void generator_surround_changed();
	void generator_upper_wall_changed();
	void generator_floor_b_changed();
	void generator_floor_c_changed();
	void generator_extra_b_changed();
	void generator_extra_c_changed();
	void generator_x_changed();
	void generator_y_changed();
	void generator_tile_ids_changed();
	void lower_layer_changed();
	void upper_layer_changed();
	void save_count_2k3e_changed();
	void save_count_changed();

protected:
	lcf::rpg::Map& m_data;
	ArrayAdapter* m_events;
};
} // namespace Binding::Generated
