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

#ifndef _LMU_READER_CHUNKS_H_
#define _LMU_READER_CHUNKS_H_

/**
 * LMU Reader namespace.
 */
namespace LMU_Reader {
	struct ChunkEventPageCondition {
		enum Index {
			/** Bitflag */
			flags				= 0x01,
			/** Integer */
			switch_a_id			= 0x02,
			/** Integer */
			switch_b_id			= 0x03,
			/** Integer */
			variable_id			= 0x04,
			/** Integer */
			variable_value		= 0x05,
			/** Integer */
			item_id				= 0x06,
			/** Integer */
			actor_id			= 0x07,
			/** Integer */
			timer_sec			= 0x08,
			/** Integer - RPG2003 */
			timer2_sec			= 0x09,
			/** Integer - RPG2003 */
			compare_operator	= 0x0A 
		};
	};
	struct ChunkMoveRoute {
		enum Index {
			/** Integer */
			move_commands_size	= 0x0B,
			/** Array - RPG::MoveCommand */
			move_commands		= 0x0C,
			/** Flag */
			repeat				= 0x15,
			/** Flag */
			skippable			= 0x16 
		};
	};
	struct ChunkEventPage {
		enum Index {
			/** RPG::EventPageCondition */
			condition			= 0x02,
			/** String */
			character_name		= 0x15,
			/** Integer */
			character_index		= 0x16,
			/** Integer */
			character_direction	= 0x17,
			/** Integer */
			character_pattern	= 0x18,
			/** Integer */
			translucent			= 0x19,
			/** Integer */
			move_type			= 0x1F,
			/** Integer */
			move_frequency		= 0x20,
			/** Integer */
			trigger				= 0x21,
			/** Integer */
			priority_type		= 0x22,
			/** Flag */
			overlap				= 0x23,
			/** Integer */
			animation_type		= 0x24,
			/** Integer */
			move_speed			= 0x25,
			/** RPG::MoveRoute */
			move_route			= 0x29,
			/** Integer */
			event_commands_size	= 0x33,
			/** Array - RPG::EventCommand */
			event_commands		= 0x34 
		};
	};
	struct ChunkEvent {
		enum Index {
			/** String */
			name	= 0x01,
			/** Integer */
			x		= 0x02,
			/** Integer */
			y		= 0x03,
			/** Array - RPG::EventPage */
			pages	= 0x05 
		};
	};
	struct ChunkMap {
		enum Index {
			/** Integer */
			chipset_id				= 0x01,
			/** Integer */
			width					= 0x02,
			/** Integer */
			height					= 0x03,
			/** Integer */
			scroll_type				= 0x0B,
			/** Flag */
			parallax_flag			= 0x1F,
			/** String */
			parallax_name			= 0x20,
			/** Flag */
			parallax_loop_x			= 0x21,
			/** Flag */
			parallax_loop_y			= 0x22,
			/** Flag */
			parallax_auto_loop_x	= 0x23,
			/** Integer */
			parallax_sx				= 0x24,
			/** Flag */
			parallax_auto_loop_y	= 0x25,
			/** Integer */
			parallax_sy				= 0x26,
			/** Flag */
			generator_flag			= 0x28,
			/** Integer */
			generator_mode			= 0x29,
			/** Bool */
			top_level				= 0x2A,
			/** Integer */
			generator_tiles			= 0x30,
			/** Integer */
			generator_width			= 0x31,
			/** Integer */
			generator_height		= 0x32,
			/** Flag */
			generator_surround		= 0x33,
			/** Flag */
			generator_upper_wall	= 0x34,
			/** Flag */
			generator_floor_b		= 0x35,
			/** Flag */
			generator_floor_c		= 0x36,
			/** Flag */
			generator_extra_b		= 0x37,
			/** Flag */
			generator_extra_c		= 0x38,
			/** Uint32 x 9 */
			generator_x				= 0x3C,
			/** Uint32 x 9 */
			generator_y				= 0x3D,
			/** Array - Short */
			generator_tile_ids		= 0x3E,
			/** Array - Short */
			lower_layer				= 0x47,
			/** Array - Short */
			upper_layer				= 0x48,
			/** Array - RPG::Event */
			events					= 0x51,
			/** Integer */
			save_times				= 0x5B 
		};
	};
}

#endif
