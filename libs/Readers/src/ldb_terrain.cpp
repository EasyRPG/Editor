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

// Read Terrain.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT Terrain

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::string, name),
	EASYRPG_STRUCT_TYPED_FIELD(int, damage),
	EASYRPG_STRUCT_TYPED_FIELD(int, encounter_rate),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, background_name),
	EASYRPG_STRUCT_TYPED_FIELD(bool, boat_pass),
	EASYRPG_STRUCT_TYPED_FIELD(bool, ship_pass),
	EASYRPG_STRUCT_TYPED_FIELD(bool, airship_pass),
	EASYRPG_STRUCT_TYPED_FIELD(bool, airship_land),
	EASYRPG_STRUCT_TYPED_FIELD(int, bush_depth),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, footstep),
	EASYRPG_STRUCT_TYPED_FIELD(bool, on_damage_se),
	EASYRPG_STRUCT_TYPED_FIELD(int, background_type),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, background_a_name),
	EASYRPG_STRUCT_TYPED_FIELD(bool, background_a_scrollh),
	EASYRPG_STRUCT_TYPED_FIELD(bool, background_a_scrollv),
	EASYRPG_STRUCT_TYPED_FIELD(int, background_a_scrollh_speed),
	EASYRPG_STRUCT_TYPED_FIELD(int, background_a_scrollv_speed),
	EASYRPG_STRUCT_TYPED_FIELD(bool, background_b),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, background_b_name),
	EASYRPG_STRUCT_TYPED_FIELD(bool, background_b_scrollh),
	EASYRPG_STRUCT_TYPED_FIELD(bool, background_b_scrollv),
	EASYRPG_STRUCT_TYPED_FIELD(int, background_b_scrollh_speed),
	EASYRPG_STRUCT_TYPED_FIELD(int, background_b_scrollv_speed),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Terrain::Flags, special_flags),
	EASYRPG_STRUCT_TYPED_FIELD(int, special_back_party),
	EASYRPG_STRUCT_TYPED_FIELD(int, special_back_enemies),
	EASYRPG_STRUCT_TYPED_FIELD(int, special_lateral_party),
	EASYRPG_STRUCT_TYPED_FIELD(int, special_lateral_enemies),
	EASYRPG_STRUCT_TYPED_FIELD(int, grid_location),
	EASYRPG_STRUCT_TYPED_FIELD(int, grid_a),
	EASYRPG_STRUCT_TYPED_FIELD(int, grid_b),
	EASYRPG_STRUCT_TYPED_FIELD(int, grid_c),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
