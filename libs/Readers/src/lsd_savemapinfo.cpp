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

// Read SaveMapInfo.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SaveMapInfo

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, pan_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, pan_y),
	EASYRPG_STRUCT_TYPED_FIELD(int, encounter_rate),
	EASYRPG_STRUCT_TYPED_FIELD(int, chipset_id),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::SaveMapEvent>, events),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint8_t>, lower_tiles),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint8_t>, upper_tiles),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, parallax_name),
	EASYRPG_STRUCT_TYPED_FIELD(bool, parallax_horz),
	EASYRPG_STRUCT_TYPED_FIELD(bool, parallax_vert),
	EASYRPG_STRUCT_TYPED_FIELD(bool, parallax_horz_auto),
	EASYRPG_STRUCT_TYPED_FIELD(int, parallax_horz_speed),
	EASYRPG_STRUCT_TYPED_FIELD(bool, parallax_vert_auto),
	EASYRPG_STRUCT_TYPED_FIELD(int, parallax_vert_speed),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
