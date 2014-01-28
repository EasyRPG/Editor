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

// Read SaveMapEvent.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SaveMapEvent

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_01),
	EASYRPG_STRUCT_TYPED_FIELD(int, map_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, position_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, position_y),
	EASYRPG_STRUCT_TYPED_FIELD(int, facing1),
	EASYRPG_STRUCT_TYPED_FIELD(int, facing2),
	EASYRPG_STRUCT_TYPED_FIELD(int, anim_frame),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_18),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_1f),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_20),
	EASYRPG_STRUCT_TYPED_FIELD(int, layer),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_22),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_23),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_24),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_25),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::MoveRoute, move_route),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_2a),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_2b),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_2f),
	EASYRPG_STRUCT_TYPED_FIELD(int, anim_paused),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_33),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_34),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_35),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_36),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_3e),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_3f),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_47),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, sprite_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, sprite_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_4b),
	EASYRPG_STRUCT_TYPED_FIELD(int, flash_red),
	EASYRPG_STRUCT_TYPED_FIELD(int, flash_green),
	EASYRPG_STRUCT_TYPED_FIELD(int, flash_blue),
	EASYRPG_STRUCT_TYPED_FIELD(double, flash_current_level),
	EASYRPG_STRUCT_TYPED_FIELD(int, flash_time_left),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_66),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_67),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveEventData, event_data),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
