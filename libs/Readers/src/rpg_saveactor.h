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

#ifndef _RPG_SAVEACTOR_H_
#define _RPG_SAVEACTOR_H_

// Headers
#include <string>
#include <vector>
#include "reader_types.h"

/**
 * RPG::SaveActor class.
 */
namespace RPG {
	class SaveActor {
	public:
		SaveActor();
		void Setup(int actor_id);

		int ID;
		std::string name;
		std::string title;
		std::string sprite_name;
		int sprite_id;
		int sprite_flags;
		std::string face_name;
		int face_id;
		int level;
		int exp;
		int hp_mod;
		int sp_mod;
		int attack_mod;
		int defense_mod;
		int spirit_mod;
		int agility_mod;
		int skills_size;
		std::vector<int16_t> skills;
		std::vector<int16_t> equipped;
		int current_hp;
		int current_sp;
		std::vector<uint32_t> battle_commands;
		int status_size;
		std::vector<int16_t> status;
		bool changed_class;
		int class_id;
		int row;
		bool two_weapon;
		bool lock_equipment;
		bool auto_battle;
		bool mighty_guard;
		int unknown_60;
	};
}

#endif
