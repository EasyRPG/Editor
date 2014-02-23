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

// Read EnemyAction.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT EnemyAction

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, kind),
	EASYRPG_STRUCT_TYPED_FIELD(int, basic),
	EASYRPG_STRUCT_TYPED_FIELD(int, skill_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, enemy_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, condition_type),
	EASYRPG_STRUCT_TYPED_FIELD(int, condition_param1),
	EASYRPG_STRUCT_TYPED_FIELD(int, condition_param2),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_id),
	EASYRPG_STRUCT_TYPED_FIELD(bool, switch_on),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_on_id),
	EASYRPG_STRUCT_TYPED_FIELD(bool, switch_off),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_off_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, rating),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
