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

// Read System.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT System

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, ldb_id),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, boat_name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, ship_name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, airship_name),
	EASYRPG_STRUCT_TYPED_FIELD(int, boat_index),
	EASYRPG_STRUCT_TYPED_FIELD(int, ship_index),
	EASYRPG_STRUCT_TYPED_FIELD(int, airship_index),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, title_name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, gameover_name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, system_name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, system2_name),
	EASYRPG_STRUCT_SIZE_FIELD(int16_t, party),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, party),
	EASYRPG_STRUCT_SIZE_FIELD(int16_t, menu_commands),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<int16_t>, menu_commands),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, title_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, battle_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, battle_end_music),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Music, inn_music),
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
	EASYRPG_STRUCT_TYPED_FIELD(int, transition_out),
	EASYRPG_STRUCT_TYPED_FIELD(int, transition_in),
	EASYRPG_STRUCT_TYPED_FIELD(int, battle_start_fadeout),
	EASYRPG_STRUCT_TYPED_FIELD(int, battle_start_fadein),
	EASYRPG_STRUCT_TYPED_FIELD(int, battle_end_fadeout),
	EASYRPG_STRUCT_TYPED_FIELD(int, battle_end_fadein),
	EASYRPG_STRUCT_TYPED_FIELD(int, message_stretch),
	EASYRPG_STRUCT_TYPED_FIELD(int, font_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, selected_condition),
	EASYRPG_STRUCT_TYPED_FIELD(int, selected_hero),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, battletest_background),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::TestBattler>, battletest_data),
	EASYRPG_STRUCT_TYPED_FIELD(int, saved_times),
	EASYRPG_STRUCT_TYPED_FIELD(int, battletest_terrain),
	EASYRPG_STRUCT_TYPED_FIELD(int, battletest_formation),
	EASYRPG_STRUCT_TYPED_FIELD(int, battletest_condition),
	EASYRPG_STRUCT_TYPED_FIELD(bool, show_frame),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, frame_name),
	EASYRPG_STRUCT_TYPED_FIELD(bool, invert_animations),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
