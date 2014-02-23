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

// Read SaveSystem.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SaveSystem

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, screen),
	EASYRPG_STRUCT_TYPED_FIELD(int, frame_count),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, graphics_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, switches_size),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<bool>, switches),
	EASYRPG_STRUCT_TYPED_FIELD(int, variables_size),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<uint32_t>, variables),
	EASYRPG_STRUCT_TYPED_FIELD(int, message_transparent),
	EASYRPG_STRUCT_TYPED_FIELD(int, message_position),
	EASYRPG_STRUCT_TYPED_FIELD(int, message_placement),
	EASYRPG_STRUCT_TYPED_FIELD(int, message_continue),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, face_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, face_id),
	EASYRPG_STRUCT_TYPED_FIELD(bool, face_right),
	EASYRPG_STRUCT_TYPED_FIELD(bool, face_flip),
	EASYRPG_STRUCT_TYPED_FIELD(bool, transparent),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_3d),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, title_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, battle_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, battle_end_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, inn_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, current_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, unknown1_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, unknown2_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, stored_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, boat_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, ship_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, airship_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, gameover_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, cursor_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, decision_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, cancel_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, buzzer_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, battle_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, escape_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, enemy_attack_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, enemy_damaged_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, actor_damaged_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, dodge_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, enemy_death_se),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, item_se),
	EASYRPG_STRUCT_TYPED_FIELD(uint8_t, transition_out),
	EASYRPG_STRUCT_TYPED_FIELD(uint8_t, transition_in),
	EASYRPG_STRUCT_TYPED_FIELD(uint8_t, battle_start_fadeout),
	EASYRPG_STRUCT_TYPED_FIELD(uint8_t, battle_start_fadein),
	EASYRPG_STRUCT_TYPED_FIELD(uint8_t, battle_end_fadeout),
	EASYRPG_STRUCT_TYPED_FIELD(uint8_t, battle_end_fadein),
	EASYRPG_STRUCT_TYPED_FIELD(bool, teleport_allowed),
	EASYRPG_STRUCT_TYPED_FIELD(bool, escape_allowed),
	EASYRPG_STRUCT_TYPED_FIELD(bool, save_allowed),
	EASYRPG_STRUCT_TYPED_FIELD(bool, menu_allowed),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, background),
	EASYRPG_STRUCT_TYPED_FIELD(int, save_count),
	EASYRPG_STRUCT_TYPED_FIELD(int, save_slot),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
