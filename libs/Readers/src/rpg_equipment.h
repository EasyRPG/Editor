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

#ifndef _RPG_EQUIPMENT_H_
#define _RPG_EQUIPMENT_H_

// Headers
#include "reader_types.h"

/**
 * RPG::Equipment class.
 */
namespace RPG {
	class Equipment {
	public:
		Equipment();

		int16_t weapon_id;
		int16_t shield_id;
		int16_t armor_id;
		int16_t helmet_id;
		int16_t accessory_id;
	};
}

#endif
