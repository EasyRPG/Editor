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

#ifndef _RPG_ITEM_H_
#define _RPG_ITEM_H_

// Headers
#include <string>
#include <vector>
#include "rpg_itemanimation.h"

/**
 * RPG::Item class.
 */
namespace RPG {
	class Item {
	public:
		enum Type {
			Type_normal = 0,
			Type_weapon = 1,
			Type_shield = 2,
			Type_armor = 3,
			Type_helmet = 4,
			Type_accessory = 5,
			Type_medicine = 6,
			Type_book = 7,
			Type_material = 8,
			Type_special = 9,
			Type_switch = 10
		};
		enum Trajectory {
			Trajectory_straight = 0,
			Trajectory_return = 1
		};
		enum Target {
			Target_single = 0,
			Target_center = 1,
			Target_simultaneous = 2,
			Target_sequential = 3
		};

		Item();

		int ID;
		std::string name;
		std::string description;
		int type;
		int price;
		int uses;
		int atk_points1;
		int def_points1;
		int spi_points1;
		int agi_points1;
		bool two_handed;
		int sp_cost;
		int hit;
		int critical_hit;
		int animation_id;
		bool preemptive;
		bool dual_attack;
		bool attack_all;
		bool ignore_evasion;
		bool prevent_critical;
		bool raise_evasion;
		bool half_sp_cost;
		bool no_terrain_damage;
		bool cursed;
		bool entire_party;
		int recover_hp;
		int recover_hp_rate;
		int recover_sp;
		int recover_sp_rate;
		bool occasion_field1;
		bool ko_only;
		int max_hp_points;
		int max_sp_points;
		int atk_points2;
		int def_points2;
		int spi_points2;
		int agi_points2;
		int using_message;
		int skill_id;
		int switch_id;
		bool occasion_field2;
		bool occasion_battle;
		std::vector<bool> actor_set;
		std::vector<bool> state_set;
		std::vector<bool> attribute_set;
		int state_chance;
		bool state_effect;
		int weapon_animation;
		std::vector<ItemAnimation> animation_data;
		bool use_skill;
		std::vector<bool> class_set;
		int ranged_trajectory;
		int ranged_target;
	};
}

#endif
