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
#include "savepicture.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SavePicture::SavePicture(ProjectData& project, lcf::rpg::SavePicture& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int SavePicture::id() {
		return m_data.ID;
	}
	QString SavePicture::name() {
		return QString::fromStdString(m_data.name);
	}
	void SavePicture::set_name(const QString& new_name) {
		if (QString::fromStdString(m_data.name) == new_name)
			return;
		m_data.name = new_name.toStdString();
		emit name_changed();
	}

	double SavePicture::start_x() {
		return m_data.start_x;
	}
	void SavePicture::set_start_x(const double& new_start_x) {
		if (m_data.start_x == new_start_x)
			return;
		m_data.start_x = new_start_x;
		emit start_x_changed();
	}

	double SavePicture::start_y() {
		return m_data.start_y;
	}
	void SavePicture::set_start_y(const double& new_start_y) {
		if (m_data.start_y == new_start_y)
			return;
		m_data.start_y = new_start_y;
		emit start_y_changed();
	}

	double SavePicture::current_x() {
		return m_data.current_x;
	}
	void SavePicture::set_current_x(const double& new_current_x) {
		if (m_data.current_x == new_current_x)
			return;
		m_data.current_x = new_current_x;
		emit current_x_changed();
	}

	double SavePicture::current_y() {
		return m_data.current_y;
	}
	void SavePicture::set_current_y(const double& new_current_y) {
		if (m_data.current_y == new_current_y)
			return;
		m_data.current_y = new_current_y;
		emit current_y_changed();
	}

	bool SavePicture::fixed_to_map() {
		return m_data.fixed_to_map;
	}
	void SavePicture::set_fixed_to_map(const bool& new_fixed_to_map) {
		if (m_data.fixed_to_map == new_fixed_to_map)
			return;
		m_data.fixed_to_map = new_fixed_to_map;
		emit fixed_to_map_changed();
	}

	double SavePicture::current_magnify() {
		return m_data.current_magnify;
	}
	void SavePicture::set_current_magnify(const double& new_current_magnify) {
		if (m_data.current_magnify == new_current_magnify)
			return;
		m_data.current_magnify = new_current_magnify;
		emit current_magnify_changed();
	}

	double SavePicture::current_top_trans() {
		return m_data.current_top_trans;
	}
	void SavePicture::set_current_top_trans(const double& new_current_top_trans) {
		if (m_data.current_top_trans == new_current_top_trans)
			return;
		m_data.current_top_trans = new_current_top_trans;
		emit current_top_trans_changed();
	}

	bool SavePicture::use_transparent_color() {
		return m_data.use_transparent_color;
	}
	void SavePicture::set_use_transparent_color(const bool& new_use_transparent_color) {
		if (m_data.use_transparent_color == new_use_transparent_color)
			return;
		m_data.use_transparent_color = new_use_transparent_color;
		emit use_transparent_color_changed();
	}

	double SavePicture::current_red() {
		return m_data.current_red;
	}
	void SavePicture::set_current_red(const double& new_current_red) {
		if (m_data.current_red == new_current_red)
			return;
		m_data.current_red = new_current_red;
		emit current_red_changed();
	}

	double SavePicture::current_green() {
		return m_data.current_green;
	}
	void SavePicture::set_current_green(const double& new_current_green) {
		if (m_data.current_green == new_current_green)
			return;
		m_data.current_green = new_current_green;
		emit current_green_changed();
	}

	double SavePicture::current_blue() {
		return m_data.current_blue;
	}
	void SavePicture::set_current_blue(const double& new_current_blue) {
		if (m_data.current_blue == new_current_blue)
			return;
		m_data.current_blue = new_current_blue;
		emit current_blue_changed();
	}

	double SavePicture::current_sat() {
		return m_data.current_sat;
	}
	void SavePicture::set_current_sat(const double& new_current_sat) {
		if (m_data.current_sat == new_current_sat)
			return;
		m_data.current_sat = new_current_sat;
		emit current_sat_changed();
	}

	int32_t SavePicture::effect_mode() {
		return m_data.effect_mode;
	}

	double SavePicture::current_effect_power() {
		return m_data.current_effect_power;
	}
	void SavePicture::set_current_effect_power(const double& new_current_effect_power) {
		if (m_data.current_effect_power == new_current_effect_power)
			return;
		m_data.current_effect_power = new_current_effect_power;
		emit current_effect_power_changed();
	}

	double SavePicture::current_bot_trans() {
		return m_data.current_bot_trans;
	}
	void SavePicture::set_current_bot_trans(const double& new_current_bot_trans) {
		if (m_data.current_bot_trans == new_current_bot_trans)
			return;
		m_data.current_bot_trans = new_current_bot_trans;
		emit current_bot_trans_changed();
	}

	int SavePicture::spritesheet_cols() {
		return m_data.spritesheet_cols;
	}
	void SavePicture::set_spritesheet_cols(const int& new_spritesheet_cols) {
		if (m_data.spritesheet_cols == new_spritesheet_cols)
			return;
		m_data.spritesheet_cols = new_spritesheet_cols;
		emit spritesheet_cols_changed();
	}

	int SavePicture::spritesheet_rows() {
		return m_data.spritesheet_rows;
	}
	void SavePicture::set_spritesheet_rows(const int& new_spritesheet_rows) {
		if (m_data.spritesheet_rows == new_spritesheet_rows)
			return;
		m_data.spritesheet_rows = new_spritesheet_rows;
		emit spritesheet_rows_changed();
	}

	int SavePicture::spritesheet_frame() {
		return m_data.spritesheet_frame;
	}
	void SavePicture::set_spritesheet_frame(const int& new_spritesheet_frame) {
		if (m_data.spritesheet_frame == new_spritesheet_frame)
			return;
		m_data.spritesheet_frame = new_spritesheet_frame;
		emit spritesheet_frame_changed();
	}

	int SavePicture::spritesheet_speed() {
		return m_data.spritesheet_speed;
	}
	void SavePicture::set_spritesheet_speed(const int& new_spritesheet_speed) {
		if (m_data.spritesheet_speed == new_spritesheet_speed)
			return;
		m_data.spritesheet_speed = new_spritesheet_speed;
		emit spritesheet_speed_changed();
	}

	int SavePicture::frames() {
		return m_data.frames;
	}
	void SavePicture::set_frames(const int& new_frames) {
		if (m_data.frames == new_frames)
			return;
		m_data.frames = new_frames;
		emit frames_changed();
	}

	bool SavePicture::spritesheet_play_once() {
		return m_data.spritesheet_play_once;
	}
	void SavePicture::set_spritesheet_play_once(const bool& new_spritesheet_play_once) {
		if (m_data.spritesheet_play_once == new_spritesheet_play_once)
			return;
		m_data.spritesheet_play_once = new_spritesheet_play_once;
		emit spritesheet_play_once_changed();
	}

	int32_t SavePicture::map_layer() {
		return m_data.map_layer;
	}

	int32_t SavePicture::battle_layer() {
		return m_data.battle_layer;
	}

	double SavePicture::finish_x() {
		return m_data.finish_x;
	}
	void SavePicture::set_finish_x(const double& new_finish_x) {
		if (m_data.finish_x == new_finish_x)
			return;
		m_data.finish_x = new_finish_x;
		emit finish_x_changed();
	}

	double SavePicture::finish_y() {
		return m_data.finish_y;
	}
	void SavePicture::set_finish_y(const double& new_finish_y) {
		if (m_data.finish_y == new_finish_y)
			return;
		m_data.finish_y = new_finish_y;
		emit finish_y_changed();
	}

	int SavePicture::finish_magnify() {
		return m_data.finish_magnify;
	}
	void SavePicture::set_finish_magnify(const int& new_finish_magnify) {
		if (m_data.finish_magnify == new_finish_magnify)
			return;
		m_data.finish_magnify = new_finish_magnify;
		emit finish_magnify_changed();
	}

	int SavePicture::finish_top_trans() {
		return m_data.finish_top_trans;
	}
	void SavePicture::set_finish_top_trans(const int& new_finish_top_trans) {
		if (m_data.finish_top_trans == new_finish_top_trans)
			return;
		m_data.finish_top_trans = new_finish_top_trans;
		emit finish_top_trans_changed();
	}

	int SavePicture::finish_bot_trans() {
		return m_data.finish_bot_trans;
	}
	void SavePicture::set_finish_bot_trans(const int& new_finish_bot_trans) {
		if (m_data.finish_bot_trans == new_finish_bot_trans)
			return;
		m_data.finish_bot_trans = new_finish_bot_trans;
		emit finish_bot_trans_changed();
	}

	int SavePicture::finish_red() {
		return m_data.finish_red;
	}
	void SavePicture::set_finish_red(const int& new_finish_red) {
		if (m_data.finish_red == new_finish_red)
			return;
		m_data.finish_red = new_finish_red;
		emit finish_red_changed();
	}

	int SavePicture::finish_green() {
		return m_data.finish_green;
	}
	void SavePicture::set_finish_green(const int& new_finish_green) {
		if (m_data.finish_green == new_finish_green)
			return;
		m_data.finish_green = new_finish_green;
		emit finish_green_changed();
	}

	int SavePicture::finish_blue() {
		return m_data.finish_blue;
	}
	void SavePicture::set_finish_blue(const int& new_finish_blue) {
		if (m_data.finish_blue == new_finish_blue)
			return;
		m_data.finish_blue = new_finish_blue;
		emit finish_blue_changed();
	}

	int SavePicture::finish_sat() {
		return m_data.finish_sat;
	}
	void SavePicture::set_finish_sat(const int& new_finish_sat) {
		if (m_data.finish_sat == new_finish_sat)
			return;
		m_data.finish_sat = new_finish_sat;
		emit finish_sat_changed();
	}

	int SavePicture::finish_effect_power() {
		return m_data.finish_effect_power;
	}
	void SavePicture::set_finish_effect_power(const int& new_finish_effect_power) {
		if (m_data.finish_effect_power == new_finish_effect_power)
			return;
		m_data.finish_effect_power = new_finish_effect_power;
		emit finish_effect_power_changed();
	}

	int SavePicture::time_left() {
		return m_data.time_left;
	}
	void SavePicture::set_time_left(const int& new_time_left) {
		if (m_data.time_left == new_time_left)
			return;
		m_data.time_left = new_time_left;
		emit time_left_changed();
	}

	double SavePicture::current_rotation() {
		return m_data.current_rotation;
	}
	void SavePicture::set_current_rotation(const double& new_current_rotation) {
		if (m_data.current_rotation == new_current_rotation)
			return;
		m_data.current_rotation = new_current_rotation;
		emit current_rotation_changed();
	}

	int SavePicture::current_waver() {
		return m_data.current_waver;
	}
	void SavePicture::set_current_waver(const int& new_current_waver) {
		if (m_data.current_waver == new_current_waver)
			return;
		m_data.current_waver = new_current_waver;
		emit current_waver_changed();
	}

	int32_t SavePicture::easyrpg_flip() {
		return m_data.easyrpg_flip;
	}

	int SavePicture::easyrpg_blend_mode() {
		return m_data.easyrpg_blend_mode;
	}
	void SavePicture::set_easyrpg_blend_mode(const int& new_easyrpg_blend_mode) {
		if (m_data.easyrpg_blend_mode == new_easyrpg_blend_mode)
			return;
		m_data.easyrpg_blend_mode = new_easyrpg_blend_mode;
		emit easyrpg_blend_mode_changed();
	}

} // namespace Binding::Generated
