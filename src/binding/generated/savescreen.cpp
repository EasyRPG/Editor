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
#include "savescreen.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveScreen::SaveScreen(ProjectData& project, lcf::rpg::SaveScreen& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int SaveScreen::tint_finish_red() {
		return m_data.tint_finish_red;
	}
	void SaveScreen::set_tint_finish_red(const int& new_tint_finish_red) {
		if (m_data.tint_finish_red == new_tint_finish_red)
			return;
		m_data.tint_finish_red = new_tint_finish_red;
		emit tint_finish_red_changed();
	}

	int SaveScreen::tint_finish_green() {
		return m_data.tint_finish_green;
	}
	void SaveScreen::set_tint_finish_green(const int& new_tint_finish_green) {
		if (m_data.tint_finish_green == new_tint_finish_green)
			return;
		m_data.tint_finish_green = new_tint_finish_green;
		emit tint_finish_green_changed();
	}

	int SaveScreen::tint_finish_blue() {
		return m_data.tint_finish_blue;
	}
	void SaveScreen::set_tint_finish_blue(const int& new_tint_finish_blue) {
		if (m_data.tint_finish_blue == new_tint_finish_blue)
			return;
		m_data.tint_finish_blue = new_tint_finish_blue;
		emit tint_finish_blue_changed();
	}

	int SaveScreen::tint_finish_sat() {
		return m_data.tint_finish_sat;
	}
	void SaveScreen::set_tint_finish_sat(const int& new_tint_finish_sat) {
		if (m_data.tint_finish_sat == new_tint_finish_sat)
			return;
		m_data.tint_finish_sat = new_tint_finish_sat;
		emit tint_finish_sat_changed();
	}

	double SaveScreen::tint_current_red() {
		return m_data.tint_current_red;
	}
	void SaveScreen::set_tint_current_red(const double& new_tint_current_red) {
		if (m_data.tint_current_red == new_tint_current_red)
			return;
		m_data.tint_current_red = new_tint_current_red;
		emit tint_current_red_changed();
	}

	double SaveScreen::tint_current_green() {
		return m_data.tint_current_green;
	}
	void SaveScreen::set_tint_current_green(const double& new_tint_current_green) {
		if (m_data.tint_current_green == new_tint_current_green)
			return;
		m_data.tint_current_green = new_tint_current_green;
		emit tint_current_green_changed();
	}

	double SaveScreen::tint_current_blue() {
		return m_data.tint_current_blue;
	}
	void SaveScreen::set_tint_current_blue(const double& new_tint_current_blue) {
		if (m_data.tint_current_blue == new_tint_current_blue)
			return;
		m_data.tint_current_blue = new_tint_current_blue;
		emit tint_current_blue_changed();
	}

	double SaveScreen::tint_current_sat() {
		return m_data.tint_current_sat;
	}
	void SaveScreen::set_tint_current_sat(const double& new_tint_current_sat) {
		if (m_data.tint_current_sat == new_tint_current_sat)
			return;
		m_data.tint_current_sat = new_tint_current_sat;
		emit tint_current_sat_changed();
	}

	int SaveScreen::tint_time_left() {
		return m_data.tint_time_left;
	}
	void SaveScreen::set_tint_time_left(const int& new_tint_time_left) {
		if (m_data.tint_time_left == new_tint_time_left)
			return;
		m_data.tint_time_left = new_tint_time_left;
		emit tint_time_left_changed();
	}

	bool SaveScreen::flash_continuous() {
		return m_data.flash_continuous;
	}
	void SaveScreen::set_flash_continuous(const bool& new_flash_continuous) {
		if (m_data.flash_continuous == new_flash_continuous)
			return;
		m_data.flash_continuous = new_flash_continuous;
		emit flash_continuous_changed();
	}

	int SaveScreen::flash_red() {
		return m_data.flash_red;
	}
	void SaveScreen::set_flash_red(const int& new_flash_red) {
		if (m_data.flash_red == new_flash_red)
			return;
		m_data.flash_red = new_flash_red;
		emit flash_red_changed();
	}

	int SaveScreen::flash_green() {
		return m_data.flash_green;
	}
	void SaveScreen::set_flash_green(const int& new_flash_green) {
		if (m_data.flash_green == new_flash_green)
			return;
		m_data.flash_green = new_flash_green;
		emit flash_green_changed();
	}

	int SaveScreen::flash_blue() {
		return m_data.flash_blue;
	}
	void SaveScreen::set_flash_blue(const int& new_flash_blue) {
		if (m_data.flash_blue == new_flash_blue)
			return;
		m_data.flash_blue = new_flash_blue;
		emit flash_blue_changed();
	}

	double SaveScreen::flash_current_level() {
		return m_data.flash_current_level;
	}
	void SaveScreen::set_flash_current_level(const double& new_flash_current_level) {
		if (m_data.flash_current_level == new_flash_current_level)
			return;
		m_data.flash_current_level = new_flash_current_level;
		emit flash_current_level_changed();
	}

	int SaveScreen::flash_time_left() {
		return m_data.flash_time_left;
	}
	void SaveScreen::set_flash_time_left(const int& new_flash_time_left) {
		if (m_data.flash_time_left == new_flash_time_left)
			return;
		m_data.flash_time_left = new_flash_time_left;
		emit flash_time_left_changed();
	}

	bool SaveScreen::shake_continuous() {
		return m_data.shake_continuous;
	}
	void SaveScreen::set_shake_continuous(const bool& new_shake_continuous) {
		if (m_data.shake_continuous == new_shake_continuous)
			return;
		m_data.shake_continuous = new_shake_continuous;
		emit shake_continuous_changed();
	}

	int SaveScreen::shake_strength() {
		return m_data.shake_strength;
	}
	void SaveScreen::set_shake_strength(const int& new_shake_strength) {
		if (m_data.shake_strength == new_shake_strength)
			return;
		m_data.shake_strength = new_shake_strength;
		emit shake_strength_changed();
	}

	int SaveScreen::shake_speed() {
		return m_data.shake_speed;
	}
	void SaveScreen::set_shake_speed(const int& new_shake_speed) {
		if (m_data.shake_speed == new_shake_speed)
			return;
		m_data.shake_speed = new_shake_speed;
		emit shake_speed_changed();
	}

	int SaveScreen::shake_position() {
		return m_data.shake_position;
	}
	void SaveScreen::set_shake_position(const int& new_shake_position) {
		if (m_data.shake_position == new_shake_position)
			return;
		m_data.shake_position = new_shake_position;
		emit shake_position_changed();
	}

	int SaveScreen::shake_position_y() {
		return m_data.shake_position_y;
	}
	void SaveScreen::set_shake_position_y(const int& new_shake_position_y) {
		if (m_data.shake_position_y == new_shake_position_y)
			return;
		m_data.shake_position_y = new_shake_position_y;
		emit shake_position_y_changed();
	}

	int SaveScreen::shake_time_left() {
		return m_data.shake_time_left;
	}
	void SaveScreen::set_shake_time_left(const int& new_shake_time_left) {
		if (m_data.shake_time_left == new_shake_time_left)
			return;
		m_data.shake_time_left = new_shake_time_left;
		emit shake_time_left_changed();
	}

	int SaveScreen::pan_x() {
		return m_data.pan_x;
	}
	void SaveScreen::set_pan_x(const int& new_pan_x) {
		if (m_data.pan_x == new_pan_x)
			return;
		m_data.pan_x = new_pan_x;
		emit pan_x_changed();
	}

	int SaveScreen::pan_y() {
		return m_data.pan_y;
	}
	void SaveScreen::set_pan_y(const int& new_pan_y) {
		if (m_data.pan_y == new_pan_y)
			return;
		m_data.pan_y = new_pan_y;
		emit pan_y_changed();
	}

	int SaveScreen::battleanim_id() {
		return m_data.battleanim_id;
	}
	void SaveScreen::set_battleanim_id(const int& new_battleanim_id) {
		if (m_data.battleanim_id == new_battleanim_id)
			return;
		m_data.battleanim_id = new_battleanim_id;
		emit battleanim_id_changed();
	}

	int SaveScreen::battleanim_target() {
		return m_data.battleanim_target;
	}
	void SaveScreen::set_battleanim_target(const int& new_battleanim_target) {
		if (m_data.battleanim_target == new_battleanim_target)
			return;
		m_data.battleanim_target = new_battleanim_target;
		emit battleanim_target_changed();
	}

	int SaveScreen::battleanim_frame() {
		return m_data.battleanim_frame;
	}
	void SaveScreen::set_battleanim_frame(const int& new_battleanim_frame) {
		if (m_data.battleanim_frame == new_battleanim_frame)
			return;
		m_data.battleanim_frame = new_battleanim_frame;
		emit battleanim_frame_changed();
	}

	bool SaveScreen::battleanim_active() {
		return m_data.battleanim_active;
	}
	void SaveScreen::set_battleanim_active(const bool& new_battleanim_active) {
		if (m_data.battleanim_active == new_battleanim_active)
			return;
		m_data.battleanim_active = new_battleanim_active;
		emit battleanim_active_changed();
	}

	bool SaveScreen::battleanim_global() {
		return m_data.battleanim_global;
	}
	void SaveScreen::set_battleanim_global(const bool& new_battleanim_global) {
		if (m_data.battleanim_global == new_battleanim_global)
			return;
		m_data.battleanim_global = new_battleanim_global;
		emit battleanim_global_changed();
	}

	int SaveScreen::weather() {
		return m_data.weather;
	}
	void SaveScreen::set_weather(const int& new_weather) {
		if (m_data.weather == new_weather)
			return;
		m_data.weather = new_weather;
		emit weather_changed();
	}

	int SaveScreen::weather_strength() {
		return m_data.weather_strength;
	}
	void SaveScreen::set_weather_strength(const int& new_weather_strength) {
		if (m_data.weather_strength == new_weather_strength)
			return;
		m_data.weather_strength = new_weather_strength;
		emit weather_strength_changed();
	}

} // namespace Binding::Generated
