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

// Read SavePicture.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SavePicture

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::string, name),
	EASYRPG_STRUCT_TYPED_FIELD(double, start_x),
	EASYRPG_STRUCT_TYPED_FIELD(double, start_y),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_x),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_y),
	EASYRPG_STRUCT_TYPED_FIELD(bool, picture_scrolls),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_magnify),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_top_trans),
	EASYRPG_STRUCT_TYPED_FIELD(bool, transparency),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_red),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_green),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_blue),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_sat),
	EASYRPG_STRUCT_TYPED_FIELD(int, effect_mode),
	EASYRPG_STRUCT_TYPED_FIELD(double, effect_speed),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_bot_trans),
	EASYRPG_STRUCT_TYPED_FIELD(double, finish_x),
	EASYRPG_STRUCT_TYPED_FIELD(double, finish_y),
	EASYRPG_STRUCT_TYPED_FIELD(int, finish_magnify),
	EASYRPG_STRUCT_TYPED_FIELD(int, finish_top_trans),
	EASYRPG_STRUCT_TYPED_FIELD(int, finish_bot_trans),
	EASYRPG_STRUCT_TYPED_FIELD(int, finish_red),
	EASYRPG_STRUCT_TYPED_FIELD(int, finish_green),
	EASYRPG_STRUCT_TYPED_FIELD(int, finish_blue),
	EASYRPG_STRUCT_TYPED_FIELD(int, finish_sat),
	EASYRPG_STRUCT_TYPED_FIELD(int, effect2_speed),
	EASYRPG_STRUCT_TYPED_FIELD(int, time_left),
	EASYRPG_STRUCT_TYPED_FIELD(double, current_rotation),
	EASYRPG_STRUCT_TYPED_FIELD(int, current_waver),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
