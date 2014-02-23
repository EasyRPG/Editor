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

// Read SaveActor.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SaveActor

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::string, name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, title),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, sprite_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, sprite_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, sprite_flags),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, face_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, face_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, level),
	EASYRPG_STRUCT_TYPED_FIELD(int, exp),
	EASYRPG_STRUCT_TYPED_FIELD(int, hp_mod),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_mod),
	EASYRPG_STRUCT_TYPED_FIELD(int, attack_mod),
	EASYRPG_STRUCT_TYPED_FIELD(int, defense_mod),
	EASYRPG_STRUCT_TYPED_FIELD(int, spirit_mod),
	EASYRPG_STRUCT_TYPED_FIELD(int, agility_mod),
	EASYRPG_STRUCT_TYPED_FIELD(int, skills_size),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, skills),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, equipped),
	EASYRPG_STRUCT_TYPED_FIELD(int, current_hp),
	EASYRPG_STRUCT_TYPED_FIELD(int, current_sp),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint32_t>, battle_commands),
	EASYRPG_STRUCT_TYPED_FIELD(int, status_size),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, status),
	EASYRPG_STRUCT_TYPED_FIELD(bool, changed_class),
	EASYRPG_STRUCT_TYPED_FIELD(int, class_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, row),
	EASYRPG_STRUCT_TYPED_FIELD(bool, two_weapon),
	EASYRPG_STRUCT_TYPED_FIELD(bool, lock_equipment),
	EASYRPG_STRUCT_TYPED_FIELD(bool, auto_battle),
	EASYRPG_STRUCT_TYPED_FIELD(bool, mighty_guard),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_60),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
