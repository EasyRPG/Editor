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
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

// Headers
#include "rpg_database.h"
#include "data.h"

/**
 * Data namespace.
 */
namespace Data {
	/** Database Data (ldb). */
	RPG::Database data;

	std::vector<RPG::Actor>& actors = data.actors;
	std::vector<RPG::Skill>& skills = data.skills;
	std::vector<RPG::Item>& items = data.items;
	std::vector<RPG::Enemy>& enemies = data.enemies;
	std::vector<RPG::Troop>& troops = data.troops;
	std::vector<RPG::Terrain>& terrains = data.terrains;
	std::vector<RPG::Attribute>& attributes = data.attributes;
	std::vector<RPG::State>& states = data.states;
	std::vector<RPG::Animation>& animations = data.animations;
	std::vector<RPG::Chipset>& chipsets = data.chipsets;
	std::vector<RPG::CommonEvent>& commonevents = data.commonevents;
	RPG::BattleCommands& battlecommands = data.battlecommands;
	std::vector<RPG::Class>& classes = data.classes;
	std::vector<RPG::BattlerAnimation>& battleranimations = data.battleranimations;
	RPG::Terms& terms = data.terms;
	RPG::System& system = data.system;
	std::vector<RPG::Switch>& switches = data.switches;
	std::vector<RPG::Variable>& variables = data.variables;

	/** TreeMap (lmt). */
	RPG::TreeMap treemap;
}

/**
 * Clears database data.
 */
void Data::Clear() {
	actors.clear();
	skills.clear();
	items.clear();
	enemies.clear();
	troops.clear();
	terrains.clear();
	attributes.clear();
	states.clear();
	animations.clear();
	chipsets.clear();
	commonevents.clear();
	battlecommands.commands.clear();
	classes.clear();
	battleranimations.clear();
	switches.clear();
	variables.clear();
}
