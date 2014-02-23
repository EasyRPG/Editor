/* !!!! GENERATED FILE - DO NOT EDIT !!!! */

/*
 * This file is part of EasyRPG.
 *
 * EasyRPG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http: *www.gnu.org/licenses/>.
 */

#ifndef _RPG_SAVESCREEN_H_
#define _RPG_SAVESCREEN_H_

/**
 * RPG::SaveScreen class.
 */
namespace RPG {
	class SaveScreen {
	public:
		SaveScreen();

		int tint_finish_red;
		int tint_finish_green;
		int tint_finish_blue;
		int tint_finish_sat;
		double tint_current_red;
		double tint_current_green;
		double tint_current_blue;
		double tint_current_sat;
		int tint_time_left;
		bool flash_continuous;
		int flash_red;
		int flash_green;
		int flash_blue;
		double flash_current_level;
		int flash_time_left;
		bool shake_continuous;
		int shake_strength;
		int shake_speed;
		int shake_position;
		int shake_time_left;
		int pan_x;
		int pan_y;
		int battleanim_id;
		int battleanim_target;
		int battleanim_unk_2d;
		bool battleanim_global;
		int weather;
		int weather_strength;
	};
}

#endif
