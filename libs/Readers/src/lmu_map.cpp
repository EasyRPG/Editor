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

// Read Map.

#define EASYRPG_CHUNK_SUFFIX LMU_Reader
#define EASYRPG_CURRENT_STRUCT Map

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, chipset_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, width),
	EASYRPG_STRUCT_TYPED_FIELD(int, height),
	EASYRPG_STRUCT_TYPED_FIELD(int, scroll_type),
	EASYRPG_STRUCT_TYPED_FIELD(bool, parallax_flag),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, parallax_name),
	EASYRPG_STRUCT_TYPED_FIELD(bool, parallax_loop_x),
	EASYRPG_STRUCT_TYPED_FIELD(bool, parallax_loop_y),
	EASYRPG_STRUCT_TYPED_FIELD(bool, parallax_auto_loop_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, parallax_sx),
	EASYRPG_STRUCT_TYPED_FIELD(bool, parallax_auto_loop_y),
	EASYRPG_STRUCT_TYPED_FIELD(int, parallax_sy),
	EASYRPG_STRUCT_TYPED_FIELD(bool, generator_flag),
	EASYRPG_STRUCT_TYPED_FIELD(int, generator_mode),
	EASYRPG_STRUCT_TYPED_FIELD(bool, top_level),
	EASYRPG_STRUCT_TYPED_FIELD(int, generator_tiles),
	EASYRPG_STRUCT_TYPED_FIELD(int, generator_width),
	EASYRPG_STRUCT_TYPED_FIELD(int, generator_height),
	EASYRPG_STRUCT_TYPED_FIELD(bool, generator_surround),
	EASYRPG_STRUCT_TYPED_FIELD(bool, generator_upper_wall),
	EASYRPG_STRUCT_TYPED_FIELD(bool, generator_floor_b),
	EASYRPG_STRUCT_TYPED_FIELD(bool, generator_floor_c),
	EASYRPG_STRUCT_TYPED_FIELD(bool, generator_extra_b),
	EASYRPG_STRUCT_TYPED_FIELD(bool, generator_extra_c),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint32_t>, generator_x),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint32_t>, generator_y),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, generator_tile_ids),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, lower_layer),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, upper_layer),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Event>, events),
	EASYRPG_STRUCT_TYPED_FIELD(int, save_times),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
