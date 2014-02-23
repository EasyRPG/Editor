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

// Read BattleCommands.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT BattleCommands

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, placement),
	EASYRPG_STRUCT_TYPED_FIELD(int, death_handler1),
	EASYRPG_STRUCT_TYPED_FIELD(int, row),
	EASYRPG_STRUCT_TYPED_FIELD(int, battle_type),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown1),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::BattleCommand>, commands),
	EASYRPG_STRUCT_TYPED_FIELD(int, death_handler2),
	EASYRPG_STRUCT_TYPED_FIELD(int, death_event),
	EASYRPG_STRUCT_TYPED_FIELD(int, window_size),
	EASYRPG_STRUCT_TYPED_FIELD(int, transparency),
	EASYRPG_STRUCT_TYPED_FIELD(bool, teleport),
	EASYRPG_STRUCT_TYPED_FIELD(int, teleport_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, teleport_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, teleport_y),
	EASYRPG_STRUCT_TYPED_FIELD(int, teleport_face),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
