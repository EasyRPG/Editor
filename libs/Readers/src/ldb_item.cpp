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
#include "ldb_reader.h"
#include "ldb_chunks.h"
#include "reader_struct.h"

// Read Item.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT Item

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::string, name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, description),
	EASYRPG_STRUCT_TYPED_FIELD(int, type),
	EASYRPG_STRUCT_TYPED_FIELD(int, price),
	EASYRPG_STRUCT_TYPED_FIELD(int, uses),
	EASYRPG_STRUCT_TYPED_FIELD(int, atk_points1),
	EASYRPG_STRUCT_TYPED_FIELD(int, def_points1),
	EASYRPG_STRUCT_TYPED_FIELD(int, spi_points1),
	EASYRPG_STRUCT_TYPED_FIELD(int, agi_points1),
	EASYRPG_STRUCT_TYPED_FIELD(bool, two_handed),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_cost),
	EASYRPG_STRUCT_TYPED_FIELD(int, hit),
	EASYRPG_STRUCT_TYPED_FIELD(int, critical_hit),
	EASYRPG_STRUCT_TYPED_FIELD(int, animation_id),
	EASYRPG_STRUCT_TYPED_FIELD(bool, preemptive),
	EASYRPG_STRUCT_TYPED_FIELD(bool, dual_attack),
	EASYRPG_STRUCT_TYPED_FIELD(bool, attack_all),
	EASYRPG_STRUCT_TYPED_FIELD(bool, ignore_evasion),
	EASYRPG_STRUCT_TYPED_FIELD(bool, prevent_critical),
	EASYRPG_STRUCT_TYPED_FIELD(bool, raise_evasion),
	EASYRPG_STRUCT_TYPED_FIELD(bool, half_sp_cost),
	EASYRPG_STRUCT_TYPED_FIELD(bool, no_terrain_damage),
	EASYRPG_STRUCT_TYPED_FIELD(bool, cursed),
	EASYRPG_STRUCT_TYPED_FIELD(bool, entire_party),
	EASYRPG_STRUCT_TYPED_FIELD(int, recover_hp_rate),
	EASYRPG_STRUCT_TYPED_FIELD(int, recover_hp),
	EASYRPG_STRUCT_TYPED_FIELD(int, recover_sp_rate),
	EASYRPG_STRUCT_TYPED_FIELD(int, recover_sp),
	EASYRPG_STRUCT_TYPED_FIELD(bool, occasion_field1),
	EASYRPG_STRUCT_TYPED_FIELD(bool, ko_only),
	EASYRPG_STRUCT_TYPED_FIELD(int, max_hp_points),
	EASYRPG_STRUCT_TYPED_FIELD(int, max_sp_points),
	EASYRPG_STRUCT_TYPED_FIELD(int, atk_points2),
	EASYRPG_STRUCT_TYPED_FIELD(int, def_points2),
	EASYRPG_STRUCT_TYPED_FIELD(int, spi_points2),
	EASYRPG_STRUCT_TYPED_FIELD(int, agi_points2),
	EASYRPG_STRUCT_TYPED_FIELD(int, using_message),
	EASYRPG_STRUCT_TYPED_FIELD(int, skill_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_id),
	EASYRPG_STRUCT_TYPED_FIELD(bool, occasion_field2),
	EASYRPG_STRUCT_TYPED_FIELD(bool, occasion_battle),
	EASYRPG_STRUCT_SIZE_FIELD(bool, actor_set),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<bool>, actor_set),
	EASYRPG_STRUCT_SIZE_FIELD(bool, state_set),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<bool>, state_set),
	EASYRPG_STRUCT_SIZE_FIELD(bool, attribute_set),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<bool>, attribute_set),
	EASYRPG_STRUCT_TYPED_FIELD(int, state_chance),
	EASYRPG_STRUCT_TYPED_FIELD(bool, state_effect),
	EASYRPG_STRUCT_TYPED_FIELD(int, weapon_animation),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::ItemAnimation>, animation_data),
	EASYRPG_STRUCT_TYPED_FIELD(bool, use_skill),
	EASYRPG_STRUCT_SIZE_FIELD(bool, class_set),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<bool>, class_set),
	EASYRPG_STRUCT_TYPED_FIELD(int, ranged_trajectory),
	EASYRPG_STRUCT_TYPED_FIELD(int, ranged_target),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
