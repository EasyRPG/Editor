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

#ifndef _RPG_SAVEPICTURE_H_
#define _RPG_SAVEPICTURE_H_

// Headers
#include <string>

/**
 * RPG::SavePicture class.
 */
namespace RPG {
	class SavePicture {
	public:
		SavePicture();

		int ID;
		std::string name;
		double start_x;
		double start_y;
		double current_x;
		double current_y;
		bool picture_scrolls;
		double current_magnify;
		double current_top_trans;
		bool transparency;
		double current_red;
		double current_green;
		double current_blue;
		double current_sat;
		int effect_mode;
		double effect_speed;
		double current_bot_trans;
		double finish_x;
		double finish_y;
		int finish_magnify;
		int finish_top_trans;
		int finish_bot_trans;
		int finish_red;
		int finish_green;
		int finish_blue;
		int finish_sat;
		int effect2_speed;
		int time_left;
		double current_rotation;
		int current_waver;
	};
}

#endif
