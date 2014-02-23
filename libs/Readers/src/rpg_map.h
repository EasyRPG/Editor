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

#ifndef _RPG_MAP_H_
#define _RPG_MAP_H_

// Headers
#include <string>
#include <vector>
#include "reader_types.h"
#include "rpg_event.h"

/**
 * RPG::Map class.
 */
namespace RPG {
	class Map {
	public:
		enum ScrollType {
			ScrollType_none = 0,
			ScrollType_vertical = 1,
			ScrollType_horizontal = 2,
			ScrollType_both = 3
		};
		enum GeneratorMode {
			GeneratorMode_single_passage = 0,
			GeneratorMode_linked_rooms = 1,
			GeneratorMode_maze_passage = 2,
			GeneratorMode_open_room = 3
		};
		enum GeneratorTiles {
			GeneratorTiles_one = 0,
			GeneratorTiles_two = 1
		};

		Map();

		int ID;
		int chipset_id;
		int width;
		int height;
		int scroll_type;
		bool parallax_flag;
		std::string parallax_name;
		bool parallax_loop_x;
		bool parallax_loop_y;
		bool parallax_auto_loop_x;
		int parallax_sx;
		bool parallax_auto_loop_y;
		int parallax_sy;
		bool generator_flag;
		int generator_mode;
		bool top_level;
		int generator_tiles;
		int generator_width;
		int generator_height;
		bool generator_surround;
		bool generator_upper_wall;
		bool generator_floor_b;
		bool generator_floor_c;
		bool generator_extra_b;
		bool generator_extra_c;
		std::vector<uint32_t> generator_x;
		std::vector<uint32_t> generator_y;
		std::vector<int16_t> generator_tile_ids;
		std::vector<int16_t> lower_layer;
		std::vector<int16_t> upper_layer;
		std::vector<Event> events;
		int save_times;
	};
}

#endif
