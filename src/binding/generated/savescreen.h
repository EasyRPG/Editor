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
#include <lcf/rpg/savescreen.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::SaveScreen class.
 * Exposes lcf::rpg::SaveScreen to QML.
 */
namespace Binding::Generated {
class SaveScreen : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int tint_finish_red READ tint_finish_red WRITE set_tint_finish_red NOTIFY tint_finish_red_changed)
	Q_PROPERTY(int tint_finish_green READ tint_finish_green WRITE set_tint_finish_green NOTIFY tint_finish_green_changed)
	Q_PROPERTY(int tint_finish_blue READ tint_finish_blue WRITE set_tint_finish_blue NOTIFY tint_finish_blue_changed)
	Q_PROPERTY(int tint_finish_sat READ tint_finish_sat WRITE set_tint_finish_sat NOTIFY tint_finish_sat_changed)
	Q_PROPERTY(double tint_current_red READ tint_current_red WRITE set_tint_current_red NOTIFY tint_current_red_changed)
	Q_PROPERTY(double tint_current_green READ tint_current_green WRITE set_tint_current_green NOTIFY tint_current_green_changed)
	Q_PROPERTY(double tint_current_blue READ tint_current_blue WRITE set_tint_current_blue NOTIFY tint_current_blue_changed)
	Q_PROPERTY(double tint_current_sat READ tint_current_sat WRITE set_tint_current_sat NOTIFY tint_current_sat_changed)
	Q_PROPERTY(int tint_time_left READ tint_time_left WRITE set_tint_time_left NOTIFY tint_time_left_changed)
	Q_PROPERTY(bool flash_continuous READ flash_continuous WRITE set_flash_continuous NOTIFY flash_continuous_changed)
	Q_PROPERTY(int flash_red READ flash_red WRITE set_flash_red NOTIFY flash_red_changed)
	Q_PROPERTY(int flash_green READ flash_green WRITE set_flash_green NOTIFY flash_green_changed)
	Q_PROPERTY(int flash_blue READ flash_blue WRITE set_flash_blue NOTIFY flash_blue_changed)
	Q_PROPERTY(double flash_current_level READ flash_current_level WRITE set_flash_current_level NOTIFY flash_current_level_changed)
	Q_PROPERTY(int flash_time_left READ flash_time_left WRITE set_flash_time_left NOTIFY flash_time_left_changed)
	Q_PROPERTY(bool shake_continuous READ shake_continuous WRITE set_shake_continuous NOTIFY shake_continuous_changed)
	Q_PROPERTY(int shake_strength READ shake_strength WRITE set_shake_strength NOTIFY shake_strength_changed)
	Q_PROPERTY(int shake_speed READ shake_speed WRITE set_shake_speed NOTIFY shake_speed_changed)
	Q_PROPERTY(int shake_position READ shake_position WRITE set_shake_position NOTIFY shake_position_changed)
	Q_PROPERTY(int shake_position_y READ shake_position_y WRITE set_shake_position_y NOTIFY shake_position_y_changed)
	Q_PROPERTY(int shake_time_left READ shake_time_left WRITE set_shake_time_left NOTIFY shake_time_left_changed)
	Q_PROPERTY(int pan_x READ pan_x WRITE set_pan_x NOTIFY pan_x_changed)
	Q_PROPERTY(int pan_y READ pan_y WRITE set_pan_y NOTIFY pan_y_changed)
	Q_PROPERTY(int battleanim_id READ battleanim_id WRITE set_battleanim_id NOTIFY battleanim_id_changed)
	Q_PROPERTY(int battleanim_target READ battleanim_target WRITE set_battleanim_target NOTIFY battleanim_target_changed)
	Q_PROPERTY(int battleanim_frame READ battleanim_frame WRITE set_battleanim_frame NOTIFY battleanim_frame_changed)
	Q_PROPERTY(bool battleanim_active READ battleanim_active WRITE set_battleanim_active NOTIFY battleanim_active_changed)
	Q_PROPERTY(bool battleanim_global READ battleanim_global WRITE set_battleanim_global NOTIFY battleanim_global_changed)
	Q_PROPERTY(int weather READ weather WRITE set_weather NOTIFY weather_changed)
	Q_PROPERTY(int weather_strength READ weather_strength WRITE set_weather_strength NOTIFY weather_strength_changed)

public:
	SaveScreen(ProjectData& project, lcf::rpg::SaveScreen& data, QObject* parent = nullptr);

	lcf::rpg::SaveScreen& data();
	int tint_finish_red();
	void set_tint_finish_red(const int& new_tint_finish_red);
	int tint_finish_green();
	void set_tint_finish_green(const int& new_tint_finish_green);
	int tint_finish_blue();
	void set_tint_finish_blue(const int& new_tint_finish_blue);
	int tint_finish_sat();
	void set_tint_finish_sat(const int& new_tint_finish_sat);
	double tint_current_red();
	void set_tint_current_red(const double& new_tint_current_red);
	double tint_current_green();
	void set_tint_current_green(const double& new_tint_current_green);
	double tint_current_blue();
	void set_tint_current_blue(const double& new_tint_current_blue);
	double tint_current_sat();
	void set_tint_current_sat(const double& new_tint_current_sat);
	int tint_time_left();
	void set_tint_time_left(const int& new_tint_time_left);
	bool flash_continuous();
	void set_flash_continuous(const bool& new_flash_continuous);
	int flash_red();
	void set_flash_red(const int& new_flash_red);
	int flash_green();
	void set_flash_green(const int& new_flash_green);
	int flash_blue();
	void set_flash_blue(const int& new_flash_blue);
	double flash_current_level();
	void set_flash_current_level(const double& new_flash_current_level);
	int flash_time_left();
	void set_flash_time_left(const int& new_flash_time_left);
	bool shake_continuous();
	void set_shake_continuous(const bool& new_shake_continuous);
	int shake_strength();
	void set_shake_strength(const int& new_shake_strength);
	int shake_speed();
	void set_shake_speed(const int& new_shake_speed);
	int shake_position();
	void set_shake_position(const int& new_shake_position);
	int shake_position_y();
	void set_shake_position_y(const int& new_shake_position_y);
	int shake_time_left();
	void set_shake_time_left(const int& new_shake_time_left);
	int pan_x();
	void set_pan_x(const int& new_pan_x);
	int pan_y();
	void set_pan_y(const int& new_pan_y);
	int battleanim_id();
	void set_battleanim_id(const int& new_battleanim_id);
	int battleanim_target();
	void set_battleanim_target(const int& new_battleanim_target);
	int battleanim_frame();
	void set_battleanim_frame(const int& new_battleanim_frame);
	bool battleanim_active();
	void set_battleanim_active(const bool& new_battleanim_active);
	bool battleanim_global();
	void set_battleanim_global(const bool& new_battleanim_global);
	int weather();
	void set_weather(const int& new_weather);
	int weather_strength();
	void set_weather_strength(const int& new_weather_strength);

signals:
	void tint_finish_red_changed();
	void tint_finish_green_changed();
	void tint_finish_blue_changed();
	void tint_finish_sat_changed();
	void tint_current_red_changed();
	void tint_current_green_changed();
	void tint_current_blue_changed();
	void tint_current_sat_changed();
	void tint_time_left_changed();
	void flash_continuous_changed();
	void flash_red_changed();
	void flash_green_changed();
	void flash_blue_changed();
	void flash_current_level_changed();
	void flash_time_left_changed();
	void shake_continuous_changed();
	void shake_strength_changed();
	void shake_speed_changed();
	void shake_position_changed();
	void shake_position_y_changed();
	void shake_time_left_changed();
	void pan_x_changed();
	void pan_y_changed();
	void battleanim_id_changed();
	void battleanim_target_changed();
	void battleanim_frame_changed();
	void battleanim_active_changed();
	void battleanim_global_changed();
	void weather_changed();
	void weather_strength_changed();

protected:
	lcf::rpg::SaveScreen& m_data;
};
} // namespace Binding::Generated
