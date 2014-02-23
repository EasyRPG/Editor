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

#ifndef _RPG_ITEMANIMATION_H_
#define _RPG_ITEMANIMATION_H_

/**
 * RPG::ItemAnimation class.
 */
namespace RPG {
	class ItemAnimation {
	public:
		enum Movement {
			Movement_none = 0,
			Movement_step = 1,
			Movement_jump = 2,
			Movement_move = 3
		};
		enum AfterImage {
			AfterImage_none = 0,
			AfterImage_add = 1
		};
		enum Speed {
			Speed_fast = 0,
			Speed_medium = 1,
			Speed_slow = 2
		};

		ItemAnimation();

		int ID;
		int type;
		int weapon_anim;
		int movement;
		int after_image;
		int attacks;
		bool ranged;
		int ranged_anim;
		int ranged_speed;
		int battle_anim;
	};
}

#endif
