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

// Read State.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT State

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::string, name),
	EASYRPG_STRUCT_TYPED_FIELD(int, type),
	EASYRPG_STRUCT_TYPED_FIELD(int, color),
	EASYRPG_STRUCT_TYPED_FIELD(int, priority),
	EASYRPG_STRUCT_TYPED_FIELD(int, restriction),
	EASYRPG_STRUCT_TYPED_FIELD(int, a_rate),
	EASYRPG_STRUCT_TYPED_FIELD(int, b_rate),
	EASYRPG_STRUCT_TYPED_FIELD(int, c_rate),
	EASYRPG_STRUCT_TYPED_FIELD(int, d_rate),
	EASYRPG_STRUCT_TYPED_FIELD(int, e_rate),
	EASYRPG_STRUCT_TYPED_FIELD(int, hold_turn),
	EASYRPG_STRUCT_TYPED_FIELD(int, auto_release_prob),
	EASYRPG_STRUCT_TYPED_FIELD(int, release_by_damage),
	EASYRPG_STRUCT_TYPED_FIELD(int, affect_type),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_attack),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_defense),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_spirit),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_agility),
	EASYRPG_STRUCT_TYPED_FIELD(int, reduce_hit_ratio),
	EASYRPG_STRUCT_TYPED_FIELD(bool, avoid_attacks),
	EASYRPG_STRUCT_TYPED_FIELD(bool, reflect_magic),
	EASYRPG_STRUCT_TYPED_FIELD(bool, cursed),
	EASYRPG_STRUCT_TYPED_FIELD(int, battler_animation_id),
	EASYRPG_STRUCT_TYPED_FIELD(bool, restrict_skill),
	EASYRPG_STRUCT_TYPED_FIELD(int, restrict_skill_level),
	EASYRPG_STRUCT_TYPED_FIELD(bool, restrict_magic),
	EASYRPG_STRUCT_TYPED_FIELD(int, restrict_magic_level),
	EASYRPG_STRUCT_TYPED_FIELD(int, hp_change_type),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_change_type),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, message_actor),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, message_enemy),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, message_already),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, message_affected),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, message_recovery),
	EASYRPG_STRUCT_TYPED_FIELD(int, hp_change_max),
	EASYRPG_STRUCT_TYPED_FIELD(int, hp_change_val),
	EASYRPG_STRUCT_TYPED_FIELD(int, hp_change_map_val),
	EASYRPG_STRUCT_TYPED_FIELD(int, hp_change_map_steps),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_change_max),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_change_val),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_change_map_val),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_change_map_steps),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
