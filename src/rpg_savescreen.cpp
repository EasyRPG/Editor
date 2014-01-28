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
#include "rpg_savescreen.h"

/**
 * Constructor.
 */
RPG::SaveScreen::SaveScreen() {
	tint_finish_red = -1;
	tint_finish_green = -1;
	tint_finish_blue = -1;
	tint_finish_sat = -1;
	tint_current_red = -1.0;
	tint_current_green = -1.0;
	tint_current_blue = -1.0;
	tint_current_sat = -1.0;
	tint_time_left = -1;
	flash_continuous = false;
	flash_red = -1;
	flash_green = -1;
	flash_blue = -1;
	flash_current_level = -1.0;
	flash_time_left = -1;
	shake_continuous = false;
	shake_strength = -1;
	shake_speed = -1;
	shake_position = 0;
	shake_time_left = -1;
	pan_x = -1;
	pan_y = -1;
	battleanim_id = -1;
	battleanim_target = -1;
	battleanim_unk_2d = -1;
	battleanim_global = false;
	weather = 0;
	weather_strength = 0;
}
