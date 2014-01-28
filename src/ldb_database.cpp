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

// Read Database.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT Database

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Actor>, actors),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Skill>, skills),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Item>, items),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Enemy>, enemies),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Troop>, troops),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Terrain>, terrains),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Attribute>, attributes),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::State>, states),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Animation>, animations),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Chipset>, chipsets),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::Terms, terms),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::System, system),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Switch>, switches),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Variable>, variables),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::CommonEvent>, commonevents),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::BattleCommands, battlecommands),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::Class>, classes),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::BattlerAnimation>, battleranimations),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
