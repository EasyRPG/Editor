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

// Read SaveScreen.

#define EASYRPG_CHUNK_SUFFIX LSD_Reader
#define EASYRPG_CURRENT_STRUCT SaveScreen

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(int, tint_finish_red),
	EASYRPG_STRUCT_TYPED_FIELD(int, tint_finish_green),
	EASYRPG_STRUCT_TYPED_FIELD(int, tint_finish_blue),
	EASYRPG_STRUCT_TYPED_FIELD(int, tint_finish_sat),
	EASYRPG_STRUCT_TYPED_FIELD(double, tint_current_red),
	EASYRPG_STRUCT_TYPED_FIELD(double, tint_current_green),
	EASYRPG_STRUCT_TYPED_FIELD(double, tint_current_blue),
	EASYRPG_STRUCT_TYPED_FIELD(double, tint_current_sat),
	EASYRPG_STRUCT_TYPED_FIELD(int, tint_time_left),
	EASYRPG_STRUCT_TYPED_FIELD(bool, flash_continuous),
	EASYRPG_STRUCT_TYPED_FIELD(int, flash_red),
	EASYRPG_STRUCT_TYPED_FIELD(int, flash_green),
	EASYRPG_STRUCT_TYPED_FIELD(int, flash_blue),
	EASYRPG_STRUCT_TYPED_FIELD(double, flash_current_level),
	EASYRPG_STRUCT_TYPED_FIELD(int, flash_time_left),
	EASYRPG_STRUCT_TYPED_FIELD(bool, shake_continuous),
	EASYRPG_STRUCT_TYPED_FIELD(int, shake_strength),
	EASYRPG_STRUCT_TYPED_FIELD(int, shake_speed),
	EASYRPG_STRUCT_TYPED_FIELD(int, shake_position),
	EASYRPG_STRUCT_TYPED_FIELD(int, shake_time_left),
	EASYRPG_STRUCT_TYPED_FIELD(int, pan_x),
	EASYRPG_STRUCT_TYPED_FIELD(int, pan_y),
	EASYRPG_STRUCT_TYPED_FIELD(int, battleanim_id),
	EASYRPG_STRUCT_TYPED_FIELD(int, battleanim_target),
	EASYRPG_STRUCT_TYPED_FIELD(int, battleanim_unk_2d),
	EASYRPG_STRUCT_TYPED_FIELD(bool, battleanim_global),
	EASYRPG_STRUCT_TYPED_FIELD(int, weather),
	EASYRPG_STRUCT_TYPED_FIELD(int, weather_strength),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
