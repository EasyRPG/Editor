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

#ifndef _RPG_SKILL_H_
#define _RPG_SKILL_H_

// Headers
#include <string>
#include <vector>
#include "rpg_battleranimationdata.h"
#include "rpg_sound.h"

/**
 * RPG::Skill class.
 */
namespace RPG {
	class Skill {
	public:
		enum Type {
			Type_normal = 0,
			Type_teleport = 1,
			Type_escape = 2,
			Type_switch = 3
		};
		enum SpType {
			SpType_cost = 0,
			SpType_percent = 1
		};
		enum Scope {
			Scope_enemy = 0,
			Scope_enemies = 1,
			Scope_self = 2,
			Scope_ally = 3,
			Scope_party = 4
		};

		Skill();

		int ID;
		std::string name;
		std::string description;
		std::string using_message1;
		std::string using_message2;
		int failure_message;
		int type;
		int sp_type;
		int sp_percent;
		int sp_cost;
		int scope;
		int switch_id;
		int animation_id;
		Sound sound_effect;
		bool occasion_field;
		bool occasion_battle;
		bool state_effect;
		int pdef_f;
		int mdef_f;
		int variance;
		int power;
		int hit;
		bool affect_hp;
		bool affect_sp;
		bool affect_attack;
		bool affect_defense;
		bool affect_spirit;
		bool affect_agility;
		bool absorb_damage;
		bool ignore_defense;
		std::vector<bool> state_effects;
		std::vector<bool> attribute_effects;
		bool affect_attr_defence;
		int battler_animation;
		std::vector<BattlerAnimationData> battler_animation_data;
	};
}

#endif
