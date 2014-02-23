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

// Read SaveInventory.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SaveInventory

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, party_size),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, party),
	EASYRPG_STRUCT_TYPED_FIELD(int, items_size),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, item_ids),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint8_t>, item_counts),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint8_t>, item_usage),
	EASYRPG_STRUCT_TYPED_FIELD(int, gold),
	EASYRPG_STRUCT_TYPED_FIELD(int, timer1_secs),
	EASYRPG_STRUCT_TYPED_FIELD(bool, timer1_active),
	EASYRPG_STRUCT_TYPED_FIELD(bool, timer1_visible),
	EASYRPG_STRUCT_TYPED_FIELD(bool, timer1_battle),
	EASYRPG_STRUCT_TYPED_FIELD(int, timer2_secs),
	EASYRPG_STRUCT_TYPED_FIELD(bool, timer2_active),
	EASYRPG_STRUCT_TYPED_FIELD(bool, timer2_visible),
	EASYRPG_STRUCT_TYPED_FIELD(bool, timer2_battle),
	EASYRPG_STRUCT_TYPED_FIELD(int, battles),
	EASYRPG_STRUCT_TYPED_FIELD(int, defeats),
	EASYRPG_STRUCT_TYPED_FIELD(int, escapes),
	EASYRPG_STRUCT_TYPED_FIELD(int, victories),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_29),
	EASYRPG_STRUCT_TYPED_FIELD(int, steps),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
