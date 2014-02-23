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

// Headers
#include "rpg_actor.h"

/**
 * Constructor.
 */
RPG::Actor::Actor() {
	ID = 0;
	name = "";
	title = "";
	character_name = "";
	character_index = 0;
	transparent = false;
	initial_level = 1;
	final_level = 50;
	critical_hit = true;
	critical_hit_chance = 30;
	face_index = 0;
	two_swords_style = false;
	fix_equipment = false;
	auto_battle = false;
	super_guard = false;
	exp_base = 30;
	exp_inflation = 30;
	exp_correction = 0;
	unarmed_animation = 1;
	class_id = 0;
	battle_x = 0;
	battle_y = 0;
	battler_animation = 1;
	rename_skill = false;
	skill_name = "";

	Init();
}
