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

// Read SaveEvents.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SaveEvents

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::SaveEventCommands>, events),
	EASYRPG_STRUCT_TYPED_FIELD(int, events_size),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_16),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_17),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_18),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_1c),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_20),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_24),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_25),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
