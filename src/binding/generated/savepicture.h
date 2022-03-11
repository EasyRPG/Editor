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
#include <lcf/rpg/savepicture.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::SavePicture class.
 * Exposes lcf::rpg::SavePicture to QML.
 */
namespace Binding::Generated {
class SavePicture : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(double start_x READ start_x WRITE set_start_x NOTIFY start_x_changed)
	Q_PROPERTY(double start_y READ start_y WRITE set_start_y NOTIFY start_y_changed)
	Q_PROPERTY(double current_x READ current_x WRITE set_current_x NOTIFY current_x_changed)
	Q_PROPERTY(double current_y READ current_y WRITE set_current_y NOTIFY current_y_changed)
	Q_PROPERTY(bool fixed_to_map READ fixed_to_map WRITE set_fixed_to_map NOTIFY fixed_to_map_changed)
	Q_PROPERTY(double current_magnify READ current_magnify WRITE set_current_magnify NOTIFY current_magnify_changed)
	Q_PROPERTY(double current_top_trans READ current_top_trans WRITE set_current_top_trans NOTIFY current_top_trans_changed)
	Q_PROPERTY(bool use_transparent_color READ use_transparent_color WRITE set_use_transparent_color NOTIFY use_transparent_color_changed)
	Q_PROPERTY(double current_red READ current_red WRITE set_current_red NOTIFY current_red_changed)
	Q_PROPERTY(double current_green READ current_green WRITE set_current_green NOTIFY current_green_changed)
	Q_PROPERTY(double current_blue READ current_blue WRITE set_current_blue NOTIFY current_blue_changed)
	Q_PROPERTY(double current_sat READ current_sat WRITE set_current_sat NOTIFY current_sat_changed)
	Q_PROPERTY(int32_t effect_mode READ effect_mode CONSTANT)
	Q_PROPERTY(double current_effect_power READ current_effect_power WRITE set_current_effect_power NOTIFY current_effect_power_changed)
	Q_PROPERTY(double current_bot_trans READ current_bot_trans WRITE set_current_bot_trans NOTIFY current_bot_trans_changed)
	Q_PROPERTY(int spritesheet_cols READ spritesheet_cols WRITE set_spritesheet_cols NOTIFY spritesheet_cols_changed)
	Q_PROPERTY(int spritesheet_rows READ spritesheet_rows WRITE set_spritesheet_rows NOTIFY spritesheet_rows_changed)
	Q_PROPERTY(int spritesheet_frame READ spritesheet_frame WRITE set_spritesheet_frame NOTIFY spritesheet_frame_changed)
	Q_PROPERTY(int spritesheet_speed READ spritesheet_speed WRITE set_spritesheet_speed NOTIFY spritesheet_speed_changed)
	Q_PROPERTY(int frames READ frames WRITE set_frames NOTIFY frames_changed)
	Q_PROPERTY(bool spritesheet_play_once READ spritesheet_play_once WRITE set_spritesheet_play_once NOTIFY spritesheet_play_once_changed)
	Q_PROPERTY(int32_t map_layer READ map_layer CONSTANT)
	Q_PROPERTY(int32_t battle_layer READ battle_layer CONSTANT)
	Q_PROPERTY(double finish_x READ finish_x WRITE set_finish_x NOTIFY finish_x_changed)
	Q_PROPERTY(double finish_y READ finish_y WRITE set_finish_y NOTIFY finish_y_changed)
	Q_PROPERTY(int finish_magnify READ finish_magnify WRITE set_finish_magnify NOTIFY finish_magnify_changed)
	Q_PROPERTY(int finish_top_trans READ finish_top_trans WRITE set_finish_top_trans NOTIFY finish_top_trans_changed)
	Q_PROPERTY(int finish_bot_trans READ finish_bot_trans WRITE set_finish_bot_trans NOTIFY finish_bot_trans_changed)
	Q_PROPERTY(int finish_red READ finish_red WRITE set_finish_red NOTIFY finish_red_changed)
	Q_PROPERTY(int finish_green READ finish_green WRITE set_finish_green NOTIFY finish_green_changed)
	Q_PROPERTY(int finish_blue READ finish_blue WRITE set_finish_blue NOTIFY finish_blue_changed)
	Q_PROPERTY(int finish_sat READ finish_sat WRITE set_finish_sat NOTIFY finish_sat_changed)
	Q_PROPERTY(int finish_effect_power READ finish_effect_power WRITE set_finish_effect_power NOTIFY finish_effect_power_changed)
	Q_PROPERTY(int time_left READ time_left WRITE set_time_left NOTIFY time_left_changed)
	Q_PROPERTY(double current_rotation READ current_rotation WRITE set_current_rotation NOTIFY current_rotation_changed)
	Q_PROPERTY(int current_waver READ current_waver WRITE set_current_waver NOTIFY current_waver_changed)
	Q_PROPERTY(int32_t easyrpg_flip READ easyrpg_flip CONSTANT)
	Q_PROPERTY(int easyrpg_blend_mode READ easyrpg_blend_mode WRITE set_easyrpg_blend_mode NOTIFY easyrpg_blend_mode_changed)

public:
	SavePicture(ProjectData& project, lcf::rpg::SavePicture& data, QObject* parent = nullptr);

	lcf::rpg::SavePicture& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	double start_x();
	void set_start_x(const double& new_start_x);
	double start_y();
	void set_start_y(const double& new_start_y);
	double current_x();
	void set_current_x(const double& new_current_x);
	double current_y();
	void set_current_y(const double& new_current_y);
	bool fixed_to_map();
	void set_fixed_to_map(const bool& new_fixed_to_map);
	double current_magnify();
	void set_current_magnify(const double& new_current_magnify);
	double current_top_trans();
	void set_current_top_trans(const double& new_current_top_trans);
	bool use_transparent_color();
	void set_use_transparent_color(const bool& new_use_transparent_color);
	double current_red();
	void set_current_red(const double& new_current_red);
	double current_green();
	void set_current_green(const double& new_current_green);
	double current_blue();
	void set_current_blue(const double& new_current_blue);
	double current_sat();
	void set_current_sat(const double& new_current_sat);
	int32_t effect_mode();
	double current_effect_power();
	void set_current_effect_power(const double& new_current_effect_power);
	double current_bot_trans();
	void set_current_bot_trans(const double& new_current_bot_trans);
	int spritesheet_cols();
	void set_spritesheet_cols(const int& new_spritesheet_cols);
	int spritesheet_rows();
	void set_spritesheet_rows(const int& new_spritesheet_rows);
	int spritesheet_frame();
	void set_spritesheet_frame(const int& new_spritesheet_frame);
	int spritesheet_speed();
	void set_spritesheet_speed(const int& new_spritesheet_speed);
	int frames();
	void set_frames(const int& new_frames);
	bool spritesheet_play_once();
	void set_spritesheet_play_once(const bool& new_spritesheet_play_once);
	int32_t map_layer();
	int32_t battle_layer();
	double finish_x();
	void set_finish_x(const double& new_finish_x);
	double finish_y();
	void set_finish_y(const double& new_finish_y);
	int finish_magnify();
	void set_finish_magnify(const int& new_finish_magnify);
	int finish_top_trans();
	void set_finish_top_trans(const int& new_finish_top_trans);
	int finish_bot_trans();
	void set_finish_bot_trans(const int& new_finish_bot_trans);
	int finish_red();
	void set_finish_red(const int& new_finish_red);
	int finish_green();
	void set_finish_green(const int& new_finish_green);
	int finish_blue();
	void set_finish_blue(const int& new_finish_blue);
	int finish_sat();
	void set_finish_sat(const int& new_finish_sat);
	int finish_effect_power();
	void set_finish_effect_power(const int& new_finish_effect_power);
	int time_left();
	void set_time_left(const int& new_time_left);
	double current_rotation();
	void set_current_rotation(const double& new_current_rotation);
	int current_waver();
	void set_current_waver(const int& new_current_waver);
	int32_t easyrpg_flip();
	int easyrpg_blend_mode();
	void set_easyrpg_blend_mode(const int& new_easyrpg_blend_mode);

signals:
	void name_changed();
	void start_x_changed();
	void start_y_changed();
	void current_x_changed();
	void current_y_changed();
	void fixed_to_map_changed();
	void current_magnify_changed();
	void current_top_trans_changed();
	void use_transparent_color_changed();
	void current_red_changed();
	void current_green_changed();
	void current_blue_changed();
	void current_sat_changed();
	void current_effect_power_changed();
	void current_bot_trans_changed();
	void spritesheet_cols_changed();
	void spritesheet_rows_changed();
	void spritesheet_frame_changed();
	void spritesheet_speed_changed();
	void frames_changed();
	void spritesheet_play_once_changed();
	void finish_x_changed();
	void finish_y_changed();
	void finish_magnify_changed();
	void finish_top_trans_changed();
	void finish_bot_trans_changed();
	void finish_red_changed();
	void finish_green_changed();
	void finish_blue_changed();
	void finish_sat_changed();
	void finish_effect_power_changed();
	void time_left_changed();
	void current_rotation_changed();
	void current_waver_changed();
	void easyrpg_blend_mode_changed();

protected:
	lcf::rpg::SavePicture& m_data;
};
} // namespace Binding::Generated
