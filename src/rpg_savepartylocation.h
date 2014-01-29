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

#ifndef _RPG_SAVEPARTYLOCATION_H_
#define _RPG_SAVEPARTYLOCATION_H_

// Headers
#include <string>
#include "rpg_moveroute.h"

/**
 * RPG::SavePartyLocation class.
 */
namespace RPG {
	class SavePartyLocation {
	public:
		SavePartyLocation();

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
		int unknown_2c;
		bool sprite_transparent;
		int unknown_2f;
		int unknown_33;
		int unknown_34;
		int unknown_35;
		int unknown_36;
		int unknown_3e;
		int unknown_3f;
		std::string sprite_name;
		int sprite_id;
		int unknown_4b;
		int unknown_51;
		int unknown_52;
		int unknown_53;
		int pan_state;
		int pan_current_x;
		int pan_current_y;
		int pan_finish_x;
		int pan_finish_y;
		int unknown_79;
		int encounter_steps;
		int unknown_83;
		int unknown_84;
	};
}

#endif
