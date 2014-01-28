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

// Headers
#include "rpg_savepicture.h"

/**
 * Constructor.
 */
RPG::SavePicture::SavePicture() {
	ID = 0;
	name = "";
	start_x = 160.0;
	start_y = 120.0;
	current_x = 160.0;
	current_y = 120.0;
	picture_scrolls = false;
	current_magnify = -1.0;
	current_top_trans = -1.0;
	transparency = false;
	current_red = -1.0;
	current_green = -1.0;
	current_blue = -1.0;
	current_sat = -1.0;
	effect_mode = -1;
	effect_speed = -1.0;
	current_bot_trans = -1.0;
	finish_x = -1.0;
	finish_y = -1.0;
	finish_magnify = -1;
	finish_top_trans = 0;
	finish_bot_trans = 0;
	finish_red = -1;
	finish_green = -1;
	finish_blue = -1;
	finish_sat = -1;
	effect2_speed = -1;
	time_left = -1;
	current_rotation = -1.0;
	current_waver = -1;
}
