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
#include "rpg_item.h"

/**
 * Constructor.
 */
RPG::Item::Item() {
	ID = 0;
	name = "";
	description = "";
	type = 0;
	price = 0;
	uses = 1;
	atk_points1 = 0;
	def_points1 = 0;
	spi_points1 = 0;
	agi_points1 = 0;
	two_handed = false;
	sp_cost = 0;
	hit = 90;
	critical_hit = 0;
	animation_id = 1;
	preemptive = false;
	dual_attack = false;
	attack_all = false;
	ignore_evasion = false;
	prevent_critical = false;
	raise_evasion = false;
	half_sp_cost = false;
	no_terrain_damage = false;
	cursed = false;
	entire_party = false;
	recover_hp_rate = 0;
	recover_hp = 0;
	recover_sp_rate = 0;
	recover_sp = 0;
	occasion_field1 = false;
	ko_only = false;
	max_hp_points = 0;
	max_sp_points = 0;
	atk_points2 = 0;
	def_points2 = 0;
	spi_points2 = 0;
	agi_points2 = 0;
	using_message = 0;
	skill_id = 1;
	switch_id = 1;
	occasion_field2 = true;
	occasion_battle = false;
	state_chance = 0;
	state_effect = false;
	weapon_animation = 1;
	use_skill = false;
	ranged_trajectory = 0;
	ranged_target = 0;
}
