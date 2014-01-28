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
#include "rpg_saveactor.h"

/**
 * Constructor.
 */
RPG::SaveActor::SaveActor() {
	ID = 0;
	name = "";
	title = "";
	sprite_name = "";
	sprite_id = -1;
	sprite_flags = -1;
	face_name = "";
	face_id = -1;
	level = -1;
	exp = -1;
	hp_mod = 0;
	sp_mod = 0;
	attack_mod = 0;
	defense_mod = 0;
	spirit_mod = 0;
	agility_mod = 0;
	skills_size = -1;
	current_hp = -1;
	current_sp = -1;
	status_size = -1;
	changed_class = false;
	class_id = -1;
	row = -1;
	two_weapon = false;
	lock_equipment = false;
	auto_battle = false;
	mighty_guard = false;
	unknown_60 = -1;
}
