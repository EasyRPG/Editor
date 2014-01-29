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

#ifndef _RPG_SAVEVEHICLELOCATION_H_
#define _RPG_SAVEVEHICLELOCATION_H_

// Headers
#include <string>
#include "rpg_moveroute.h"

/**
 * RPG::SaveVehicleLocation class.
 */
namespace RPG {
	class SaveVehicleLocation {
	public:
		SaveVehicleLocation();

		int map_id;
		int position_x;
		int position_y;
		int facing1;
		int facing2;
		int unknown_17;
		int unknown_20;
		int unknown_21;
		int unknown_23;
		int unknown_25;
		MoveRoute move_route;
		int unknown_2a;
		int unknown_2b;
		int unknown_34;
		int unknown_35;
		int unknown_36;
		std::string sprite_name;
		int sprite_id;
		int unknown_4b;
		int unknown_65;
		std::string sprite2_name;
		int sprite2_id;
	};
}

#endif
