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


// Read Terrain.

typedef RPG::Terrain::Flags flags_type;

template <>
char const* const Flags<flags_type>::name("Terrain_Flags");

template <>
const Flags<flags_type>::Flag* Flags<flags_type>::flags[] = {
	new Flags<flags_type>::Flag(&flags_type::back_party,		"back_party"		),
	new Flags<flags_type>::Flag(&flags_type::back_enemies,		"back_enemies"		),
	new Flags<flags_type>::Flag(&flags_type::lateral_party,		"lateral_party"		),
	new Flags<flags_type>::Flag(&flags_type::lateral_enemies,	"lateral_enemies"	),
	NULL
};

template <>
const uint32_t Flags<flags_type>::max_size = 1;

