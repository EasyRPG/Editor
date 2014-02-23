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

// Read Enemy.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT Enemy

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::string, name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, battler_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, battler_hue),
	EASYRPG_STRUCT_TYPED_FIELD(int, max_hp),
	EASYRPG_STRUCT_TYPED_FIELD(int, max_sp),
	EASYRPG_STRUCT_TYPED_FIELD(int, attack),
	EASYRPG_STRUCT_TYPED_FIELD(int, defense),
	EASYRPG_STRUCT_TYPED_FIELD(int, spirit),
	EASYRPG_STRUCT_TYPED_FIELD(int, agility),
	EASYRPG_STRUCT_TYPED_FIELD(bool, transparent),
	EASYRPG_STRUCT_TYPED_FIELD(int, exp),
	EASYRPG_STRUCT_TYPED_FIELD(int, gold),
	EASYRPG_STRUCT_TYPED_FIELD(int, drop_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, drop_prob),
	EASYRPG_STRUCT_TYPED_FIELD(bool, critical_hit),
	EASYRPG_STRUCT_TYPED_FIELD(int, critical_hit_chance),
	EASYRPG_STRUCT_TYPED_FIELD(bool, miss),
	EASYRPG_STRUCT_TYPED_FIELD(bool, levitate),
	EASYRPG_STRUCT_SIZE_FIELD(uint8_t, state_ranks),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint8_t>, state_ranks),
	EASYRPG_STRUCT_SIZE_FIELD(uint8_t, attribute_ranks),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint8_t>, attribute_ranks),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::EnemyAction>, actions),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
