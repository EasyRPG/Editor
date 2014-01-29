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
#include "lmt_reader.h"
#include "lmt_chunks.h"
#include "reader_struct.h"

// Read MapInfo.

#define EASYRPG_CHUNK_SUFFIX LMT_Reader
#define EASYRPG_CURRENT_STRUCT MapInfo

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::string, name),
	EASYRPG_STRUCT_TYPED_FIELD(int, parent_map),
	EASYRPG_STRUCT_TYPED_FIELD(int, indentation),
	EASYRPG_STRUCT_TYPED_FIELD(int, type),
	EASYRPG_STRUCT_TYPED_FIELD(int, scrollbar_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, scrollbar_y),
	EASYRPG_STRUCT_TYPED_FIELD(bool, expanded_node),
	EASYRPG_STRUCT_TYPED_FIELD(int, music_type),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, music),
	EASYRPG_STRUCT_TYPED_FIELD(int, background_type),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, background_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, teleport),
	EASYRPG_STRUCT_TYPED_FIELD(int, escape),
	EASYRPG_STRUCT_TYPED_FIELD(int, save),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Encounter>, encounters),
	EASYRPG_STRUCT_TYPED_FIELD(int, encounter_steps),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Rect, area_rect),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
