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

#ifndef _RPG_SAVEMAPEVENT_H_
#define _RPG_SAVEMAPEVENT_H_

// Headers
#include <string>
#include "rpg_event.h"
#include "rpg_moveroute.h"
#include "rpg_saveeventdata.h"

/**
 * RPG::SaveMapEvent class.
 */
namespace RPG {
	class SaveMapEvent {
	public:
		SaveMapEvent();
		void Setup(const RPG::Event& event);

		int ID;
		int unknown_01;
		int map_id;
		int position_x;
		int position_y;
		int facing1;
		int facing2;
		int anim_frame;
		int unknown_18;
		int unknown_1f;
		int unknown_20;
		int layer;
		int unknown_22;
		int unknown_23;
		int unknown_24;
		int unknown_25;
		MoveRoute move_route;
		int unknown_2a;
		int unknown_2b;
		int unknown_2f;
		int anim_paused;
		int unknown_33;
		int unknown_34;
		int unknown_35;
		int unknown_36;
		int unknown_3e;
		int unknown_3f;
		int unknown_47;
		std::string sprite_name;
		int sprite_id;
		int unknown_4b;
		int flash_red;
		int flash_green;
		int flash_blue;
		double flash_current_level;
		int flash_time_left;
		int unknown_66;
		int unknown_67;
		SaveEventData event_data;
	};
}

#endif
