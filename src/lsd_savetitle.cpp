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

// Read SaveTitle.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SaveTitle

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(double, timestamp),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, hero_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, hero_level),
	EASYRPG_STRUCT_TYPED_FIELD(int, hero_hp),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, face1_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, face1_id),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, face2_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, face2_id),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, face3_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, face3_id),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, face4_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, face4_id),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
