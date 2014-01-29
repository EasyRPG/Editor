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

#ifndef _RPG_SAVEMAPINFO_H_
#define _RPG_SAVEMAPINFO_H_

// Headers
#include <string>
#include <vector>
#include "reader_types.h"
#include "rpg_map.h"
#include "rpg_mapinfo.h"
#include "rpg_savemapevent.h"

/**
 * RPG::SaveMapInfo class.
 */
namespace RPG {
	class SaveMapInfo {
	public:
		SaveMapInfo();
		void Setup();
		void Setup(const RPG::Map& map);
		void Setup(const RPG::MapInfo& map_info);

		int pan_x;
		int pan_y;
		int encounter_rate;
		int chipset_id;
		std::vector<SaveMapEvent> events;
		std::vector<uint8_t> lower_tiles;
		std::vector<uint8_t> upper_tiles;
		std::string parallax_name;
		bool parallax_horz;
		bool parallax_vert;
		bool parallax_horz_auto;
		int parallax_horz_speed;
		bool parallax_vert_auto;
		int parallax_vert_speed;
	};
}

#endif
