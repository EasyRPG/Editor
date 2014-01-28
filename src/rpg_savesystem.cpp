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
#include "rpg_savesystem.h"

/**
 * Constructor.
 */
RPG::SaveSystem::SaveSystem() {
	screen = 0;
	frame_count = 0;
	graphics_name = "";
	switches_size = 0;
	variables_size = 0;
	message_transparent = -1;
	message_position = -1;
	message_placement = -1;
	message_continue = -1;
	face_name = "";
	face_id = 0;
	face_right = false;
	face_flip = false;
	transparent = false;
	unknown_3d = -1;
	transition_out = -1;
	transition_in = -1;
	battle_start_fadeout = -1;
	battle_start_fadein = -1;
	battle_end_fadeout = -1;
	battle_end_fadein = -1;
	teleport_allowed = false;
	escape_allowed = false;
	save_allowed = false;
	menu_allowed = false;
	save_count = 0;
	save_slot = 1;
}
