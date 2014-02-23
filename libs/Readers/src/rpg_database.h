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

#ifndef _RPG_DATABASE_H_
#define _RPG_DATABASE_H_

// Headers
#include <vector>
#include "rpg_actor.h"
#include "rpg_animation.h"
#include "rpg_attribute.h"
#include "rpg_battlecommands.h"
#include "rpg_battleranimation.h"
#include "rpg_chipset.h"
#include "rpg_class.h"
#include "rpg_commonevent.h"
#include "rpg_enemy.h"
#include "rpg_item.h"
#include "rpg_skill.h"
#include "rpg_state.h"
#include "rpg_switch.h"
#include "rpg_system.h"
#include "rpg_terms.h"
#include "rpg_terrain.h"
#include "rpg_troop.h"
#include "rpg_variable.h"

/**
 * RPG::Database class.
 */
namespace RPG {
	class Database {
	public:
		std::vector<Actor> actors;
		std::vector<Skill> skills;
		std::vector<Item> items;
		std::vector<Enemy> enemies;
		std::vector<Troop> troops;
		std::vector<Terrain> terrains;
		std::vector<Attribute> attributes;
		std::vector<State> states;
		std::vector<Animation> animations;
		std::vector<Chipset> chipsets;
		Terms terms;
		System system;
		std::vector<Switch> switches;
		std::vector<Variable> variables;
		std::vector<CommonEvent> commonevents;
		BattleCommands battlecommands;
		std::vector<Class> classes;
		std::vector<BattlerAnimation> battleranimations;
	};
}

#endif
