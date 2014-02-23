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
#include "rpg_saveinventory.h"

/**
 * Constructor.
 */
RPG::SaveInventory::SaveInventory() {
	party_size = 0;
	items_size = 0;
	gold = 0;
	timer1_secs = 0;
	timer1_active = false;
	timer1_visible = false;
	timer1_battle = false;
	timer2_secs = 0;
	timer2_active = false;
	timer2_visible = false;
	timer2_battle = false;
	battles = 0;
	defeats = 0;
	escapes = 0;
	victories = 0;
	unknown_29 = -1;
	steps = 0;
}
