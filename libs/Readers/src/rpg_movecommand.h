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

#ifndef _RPG_MOVECOMMAND_H_
#define _RPG_MOVECOMMAND_H_

// Headers
#include <string>

/**
 * RPG::MoveCommand class.
 */
namespace RPG {
	class MoveCommand {
	public:
		struct Code {
			enum Index {
				move_up = 0,
				move_right = 1,
				move_down = 2,
				move_left = 3,
				move_upright = 4,
				move_downright = 5,
				move_downleft = 6,
				move_upleft = 7,
				move_random = 8,
				move_towards_hero = 9,
				move_away_from_hero = 10,
				move_forward = 11,
				face_up = 12,
				face_right = 13,
				face_down = 14,
				face_left = 15,
				turn_90_degree_right = 16,
				turn_90_degree_left = 17,
				turn_180_degree = 18,
				turn_90_degree_random = 19,
				face_random_direction = 20,
				face_hero = 21,
				face_away_from_hero = 22,
				wait = 23,
				begin_jump = 24,
				end_jump = 25,
				lock_facing = 26,
				unlock_facing = 27,
				increase_movement_speed = 28,
				decrease_movement_speed = 29,
				increase_movement_frequence = 30,
				decrease_movement_frequence = 31,
				switch_on = 32,
				switch_off = 33,
				change_graphic = 34,
				play_sound_effect = 35,
				walk_everywhere_on = 36,
				walk_everywhere_off = 37,
				stop_animation = 38,
				start_animation = 39,
				increase_transp = 40,
				decrease_transp = 41
			};
		};

		MoveCommand();

		int command_id;
		std::string parameter_string;
		int parameter_a;
		int parameter_b;
		int parameter_c;
	};
}

#endif
