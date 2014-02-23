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

/*
 * Headers
 */
#include "ldb_reader.h"
#include "ldb_chunks.h"
#include "reader_struct.h"


// Read TroopPageCondition.

typedef RPG::TroopPageCondition::Flags flags_type;

template <>
char const* const Flags<flags_type>::name("TroopPageCondition_Flags");

template <>
const Flags<flags_type>::Flag* Flags<flags_type>::flags[] = {
	new Flags<flags_type>::Flag(&flags_type::switch_a,		"switch_a"		),
	new Flags<flags_type>::Flag(&flags_type::switch_b,		"switch_b"		),
	new Flags<flags_type>::Flag(&flags_type::variable,		"variable"		),
	new Flags<flags_type>::Flag(&flags_type::turn,			"turn"			),
	new Flags<flags_type>::Flag(&flags_type::fatigue,		"fatigue"		),
	new Flags<flags_type>::Flag(&flags_type::enemy_hp,		"enemy_hp"		),
	new Flags<flags_type>::Flag(&flags_type::actor_hp,		"actor_hp"		),
	new Flags<flags_type>::Flag(&flags_type::turn_enemy,	"turn_enemy"	),
	new Flags<flags_type>::Flag(&flags_type::turn_actor,	"turn_actor"	),
	new Flags<flags_type>::Flag(&flags_type::command_actor,	"command_actor"	),
	NULL
};

template <>
const uint32_t Flags<flags_type>::max_size = 2;

