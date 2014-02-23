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

// Read Save.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT Save

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveTitle, title),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveSystem, system),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveScreen, screen),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::SavePicture>, pictures),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SavePartyLocation, party_location),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveVehicleLocation, boat_location),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveVehicleLocation, ship_location),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveVehicleLocation, airship_location),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::SaveActor>, actors),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveInventory, inventory),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::SaveTarget>, targets),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveMapInfo, map_info),
	EASYRPG_STRUCT_TYPED_FIELD(int, unknown_70),
	EASYRPG_STRUCT_TYPED_FIELD(RPG::SaveEvents, events),
	EASYRPG_STRUCT_TYPED_FIELD(std::vector<RPG::SaveCommonEvent>, common_events),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
