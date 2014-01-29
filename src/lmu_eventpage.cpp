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
#include "lmu_reader.h"
#include "lmu_chunks.h"
#include "reader_struct.h"

// Read EventPage.

#define EASYRPG_CHUNK_SUFFIX LMU_Reader
#define EASYRPG_CURRENT_STRUCT EventPage

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(RPG::EventPageCondition, condition),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, character_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, character_index),
	EASYRPG_STRUCT_TYPED_FIELD(int, character_direction),
	EASYRPG_STRUCT_TYPED_FIELD(int, character_pattern),
	EASYRPG_STRUCT_TYPED_FIELD(bool, translucent),
	EASYRPG_STRUCT_TYPED_FIELD(int, move_type),
	EASYRPG_STRUCT_TYPED_FIELD(int, move_frequency),
	EASYRPG_STRUCT_TYPED_FIELD(int, trigger),
	EASYRPG_STRUCT_TYPED_FIELD(int, priority_type),
	EASYRPG_STRUCT_TYPED_FIELD(bool, overlap),
	EASYRPG_STRUCT_TYPED_FIELD(int, animation_type),
	EASYRPG_STRUCT_TYPED_FIELD(int, move_speed),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::MoveRoute, move_route),
	EASYRPG_STRUCT_SIZE_FIELD(RPG::EventCommand, event_commands),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::EventCommand>, event_commands),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
