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

// Read TroopPageCondition.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT TroopPageCondition

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(RPG::TroopPageCondition::Flags, flags),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_a_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_b_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, variable_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, variable_value),
	EASYRPG_STRUCT_TYPED_FIELD(int, turn_a),
	EASYRPG_STRUCT_TYPED_FIELD(int, turn_b),
	EASYRPG_STRUCT_TYPED_FIELD(int, fatigue_min),
	EASYRPG_STRUCT_TYPED_FIELD(int, fatigue_max),
	EASYRPG_STRUCT_TYPED_FIELD(int, enemy_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, enemy_hp_min),
	EASYRPG_STRUCT_TYPED_FIELD(int, enemy_hp_max),
	EASYRPG_STRUCT_TYPED_FIELD(int, actor_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, actor_hp_min),
	EASYRPG_STRUCT_TYPED_FIELD(int, actor_hp_max),
	EASYRPG_STRUCT_TYPED_FIELD(int, turn_enemy_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, turn_enemy_a),
	EASYRPG_STRUCT_TYPED_FIELD(int, turn_enemy_b),
	EASYRPG_STRUCT_TYPED_FIELD(int, turn_actor_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, turn_actor_a),
	EASYRPG_STRUCT_TYPED_FIELD(int, turn_actor_b),
	EASYRPG_STRUCT_TYPED_FIELD(int, command_actor_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, command_id),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
