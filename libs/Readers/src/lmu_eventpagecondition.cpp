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

// Read EventPageCondition.

#define EASYRPG_CHUNK_SUFFIX LMU_Reader
#define EASYRPG_CURRENT_STRUCT EventPageCondition

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(RPG::EventPageCondition::Flags, flags),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_a_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, switch_b_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, variable_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, variable_value),
	EASYRPG_STRUCT_TYPED_FIELD(int, item_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, actor_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, timer_sec),
	EASYRPG_STRUCT_TYPED_FIELD(int, timer2_sec),
	EASYRPG_STRUCT_TYPED_FIELD(int, compare_operator),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
