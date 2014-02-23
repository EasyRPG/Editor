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

// Read Skill.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT Skill

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::string, name),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, description),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, using_message1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, using_message2),
	EASYRPG_STRUCT_TYPED_FIELD(int, failure_message),
	EASYRPG_STRUCT_TYPED_FIELD(int, type),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_type),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_percent),
	EASYRPG_STRUCT_TYPED_FIELD(int, sp_cost),
	EASYRPG_STRUCT_TYPED_FIELD(int, scope),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, animation_id),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Sound, sound_effect),
	EASYRPG_STRUCT_TYPED_FIELD(bool, occasion_field),
	EASYRPG_STRUCT_TYPED_FIELD(bool, occasion_battle),
	EASYRPG_STRUCT_TYPED_FIELD(bool, state_effect),
	EASYRPG_STRUCT_TYPED_FIELD(int, pdef_f),
	EASYRPG_STRUCT_TYPED_FIELD(int, mdef_f),
	EASYRPG_STRUCT_TYPED_FIELD(int, variance),
	EASYRPG_STRUCT_TYPED_FIELD(int, power),
	EASYRPG_STRUCT_TYPED_FIELD(int, hit),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_hp),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_sp),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_attack),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_defense),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_spirit),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_agility),
	EASYRPG_STRUCT_TYPED_FIELD(bool, absorb_damage),
	EASYRPG_STRUCT_TYPED_FIELD(bool, ignore_defense),
	EASYRPG_STRUCT_SIZE_FIELD(bool, state_effects),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<bool>, state_effects),
	EASYRPG_STRUCT_SIZE_FIELD(bool, attribute_effects),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<bool>, attribute_effects),
	EASYRPG_STRUCT_TYPED_FIELD(bool, affect_attr_defence),
	EASYRPG_STRUCT_TYPED_FIELD(int, battler_animation),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::BattlerAnimationData>, battler_animation_data),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
