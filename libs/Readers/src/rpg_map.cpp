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
#include "rpg_map.h"

/**
 * Constructor.
 */
RPG::Map::Map() {
	ID = 0;
	chipset_id = 1;
	width = 20;
	height = 15;
	scroll_type = 0;
	parallax_flag = false;
	parallax_name = "";
	parallax_loop_x = false;
	parallax_loop_y = false;
	parallax_auto_loop_x = false;
	parallax_sx = 0;
	parallax_auto_loop_y = false;
	parallax_sy = 0;
	generator_flag = false;
	generator_mode = 0;
	top_level = false;
	generator_tiles = 0;
	generator_width = 4;
	generator_height = 1;
	generator_surround = true;
	generator_upper_wall = true;
	generator_floor_b = true;
	generator_floor_c = true;
	generator_extra_b = true;
	generator_extra_c = true;
	save_times = 0;
}
