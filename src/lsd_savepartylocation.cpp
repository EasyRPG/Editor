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
#include "lsd_reader.h"
#include "lsd_chunks.h"
#include "reader_struct.h"

// Read SavePartyLocation.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SavePartyLocation

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, map_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, position_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, position_y),
	EASYRPG_STRUCT_TYPED_FIELD(int, facing1),
	EASYRPG_STRUCT_TYPED_FIELD(int, facing2),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_17),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_20),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_21),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_23),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_25),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::MoveRoute, move_route),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_2a),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_2b),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_2c),
	EASYRPG_STRUCT_TYPED_FIELD(bool, sprite_transparent),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_2f),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_33),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_34),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_35),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_36),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_3e),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_3f),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, sprite_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, sprite_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_4b),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_51),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_52),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_53),
	EASYRPG_STRUCT_TYPED_FIELD(int, pan_state),
	EASYRPG_STRUCT_TYPED_FIELD(int, pan_current_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, pan_current_y),
	EASYRPG_STRUCT_TYPED_FIELD(int, pan_finish_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, pan_finish_y),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_79),
	EASYRPG_STRUCT_TYPED_FIELD(int, encounter_steps),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_83),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_84),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
