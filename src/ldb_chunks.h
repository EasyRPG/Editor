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

#ifndef _LDB_READER_CHUNKS_H_
#define _LDB_READER_CHUNKS_H_

/**
 * LDB Reader namespace.
 */
namespace LDB_Reader {
	struct ChunkLearning {
		enum Index {
			/** Integer */
			level		= 0x01,
			/** Integer */
			skill_id	= 0x02 
		};
	};
	struct ChunkActor {
		enum Index {
			/** String */
			name					= 0x01,
			/** String */
			title					= 0x02,
			/** String */
			character_name			= 0x03,
			/** Integer */
			character_index			= 0x04,
			/** Flag */
			transparent				= 0x05,
			/** Integer */
			initial_level			= 0x07,
			/** Integer */
			final_level				= 0x08,
			/** Flag */
			critical_hit			= 0x09,
			/** Integer */
			critical_hit_chance		= 0x0A,
			/** String */
			face_name				= 0x0F,
			/** Integer */
			face_index				= 0x10,
			/** Flag */
			two_swords_style		= 0x15,
			/** Flag */
			fix_equipment			= 0x16,
			/** Flag */
			auto_battle				= 0x17,
			/** Flag */
			super_guard				= 0x18,
			/** Array x 6 - Short */
			parameters				= 0x1F,
			/** Integer */
			exp_base				= 0x29,
			/** Integer */
			exp_inflation			= 0x2A,
			/** Integer */
			exp_correction			= 0x2B,
			/** Integer x 5 */
			initial_equipment		= 0x33,
			/** Integer */
			unarmed_animation		= 0x38,
			/** Integer - RPG2003 */
			class_id				= 0x39,
			/** Integer - RPG2003 */
			battle_x				= 0x3B,
			/** Integer - RPG2003 */
			battle_y				= 0x3C,
			/** Integer - RPG2003 */
			battler_animation		= 0x3E,
			/** Array - RPG::Learning */
			skills					= 0x3F,
			/** Flag */
			rename_skill			= 0x42,
			/** String */
			skill_name				= 0x43,
			/** Integer */
			state_ranks_size		= 0x47,
			/** Array - Short */
			state_ranks				= 0x48,
			/** Integer */
			attribute_ranks_size	= 0x49,
			/** Array - Short */
			attribute_ranks			= 0x4A,
			/** Array - RPG::BattleCommand - RPG2003 */
			battle_commands			= 0x50 
		};
	};
	struct ChunkSound {
		enum Index {
			/** String */
			name	= 0x01,
			/** Integer */
			volume	= 0x03,
			/** Integer */
			tempo	= 0x04,
			/** Integer */
			balance	= 0x05 
		};
	};
	struct ChunkAnimationTiming {
		enum Index {
			/** Integer */
			frame			= 0x01,
			/** RPG::Sound */
			se				= 0x02,
			/** Integer */
			flash_scope		= 0x03,
			/** Integer */
			flash_red		= 0x04,
			/** Integer */
			flash_green		= 0x05,
			/** Integer */
			flash_blue		= 0x06,
			/** Integer */
			flash_power		= 0x07,
			/** Integer - RPG2003 - TODO: Get chunk id */
			screen_shake	= 0x08 
		};
	};
	struct ChunkAnimationCellData {
		enum Index {
			/** Bool - TODO: Needs confirmation */
			priority		= 0x01,
			/** Integer */
			cell_id			= 0x02,
			/** Integer */
			x				= 0x03,
			/** Integer */
			y				= 0x04,
			/** Integer */
			zoom			= 0x05,
			/** Integer */
			tone_red		= 0x06,
			/** Integer */
			tone_green		= 0x07,
			/** Integer */
			tone_blue		= 0x08,
			/** Integer */
			tone_gray		= 0x09,
			/** Integer */
			transparency	= 0x0A 
		};
	};
	struct ChunkAnimationFrame {
		enum Index {
			/** Array - RPG::AnimationCellData */
			cells	= 0x01 
		};
	};
	struct ChunkAnimation {
		enum Index {
			/** String */
			name			= 0x01,
			/** String */
			animation_name	= 0x02,
			/** Array - RPG::AnimationTiming */
			timings			= 0x06,
			/** Integer */
			scope			= 0x09,
			/** Integer */
			position		= 0x0A,
			/** Array - RPG::AnimationFrames */
			frames			= 0x0C 
		};
	};
	struct ChunkAttribute {
		enum Index {
			/** String */
			name	= 0x01,
			/** Integer */
			type	= 0x02,
			/** Integer */
			a_rate	= 0x0B,
			/** Integer */
			b_rate	= 0x0C,
			/** Integer */
			c_rate	= 0x0D,
			/** Integer */
			d_rate	= 0x0E,
			/** Integer */
			e_rate	= 0x0F 
		};
	};
	struct ChunkBattleCommand {
		enum Index {
			/** String */
			name	= 0x01,
			/** Integer */
			type	= 0x02 
		};
	};
	struct ChunkBattleCommands {
		enum Index {
			/** Integer */
			placement		= 0x02,
			/** Integer */
			death_handler1	= 0x04,
			/** Integer */
			row				= 0x06,
			/** Integer */
			battle_type		= 0x07,
			/** Integer */
			unknown1		= 0x09,
			/** Array - RPG::BattleCommand */
			commands		= 0x0A,
			/** Integer */
			death_handler2	= 0x0F,
			/** Integer */
			death_event		= 0x10,
			/** Integer */
			window_size		= 0x14,
			/** Integer */
			transparency	= 0x18,
			/** Integer */
			teleport		= 0x19,
			/** Integer */
			teleport_id		= 0x1A,
			/** Integer */
			teleport_x		= 0x1B,
			/** Integer */
			teleport_y		= 0x1C,
			/** Integer */
			teleport_face	= 0x1D 
		};
	};
	struct ChunkBattlerAnimationExtension {
		enum Index {
			/** String */
			name			= 0x01,
			/** String */
			battler_name	= 0x02,
			/** Integer */
			battler_index	= 0x03,
			/** Integer */
			animation_type	= 0x04,
			/** Integer */
			animation_id	= 0x05 
		};
	};
	struct ChunkBattlerAnimation {
		enum Index {
			/** String */
			name		= 0x01,
			/** Integer */
			speed		= 0x02,
			/** Array - RPG::BattlerAnimationExtension */
			base_data	= 0x0A,
			/** Array - RPG::BattlerAnimationExtension */
			weapon_data	= 0x0B 
		};
	};
	struct ChunkBattlerAnimationData {
		enum Index {
			/** Integer */
			move		= 0x05,
			/** Integer */
			after_image	= 0x06,
			/** Integer */
			pose		= 0x0E 
		};
	};
	struct ChunkChipset {
		enum Index {
			/** String */
			name				= 0x01,
			/** String */
			chipset_name		= 0x02,
			/** Array - Short x 162 */
			terrain_data		= 0x03,
			/** Array - Bitflag x 162 */
			passable_data_lower	= 0x04,
			/** Array - Bitflag x 144 */
			passable_data_upper	= 0x05,
			/** Integer */
			animation_type		= 0x0B,
			/** Integer */
			animation_speed		= 0x0C 
		};
	};
	struct ChunkClass {
		enum Index {
			/** String */
			name					= 0x01,
			/** Flag */
			two_swords_style		= 0x15,
			/** Flag */
			fix_equipment			= 0x16,
			/** Flag */
			auto_battle				= 0x17,
			/** Flag */
			super_guard				= 0x18,
			/** Array x 6 - Short */
			parameters				= 0x1F,
			/** Integer */
			exp_base				= 0x29,
			/** Integer */
			exp_inflation			= 0x2A,
			/** Integer */
			exp_correction			= 0x2B,
			/** Integer */
			unarmed_animation		= 0x3E,
			/** Array - RPG::Learning */
			skills					= 0x3F,
			/** Integer */
			state_ranks_size		= 0x47,
			/** Array - Short */
			state_ranks				= 0x48,
			/** Integer */
			attribute_ranks_size	= 0x49,
			/** Array - Short */
			attribute_ranks			= 0x4A,
			/** Array - Uint32 */
			battle_commands			= 0x50 
		};
	};
	struct ChunkCommonEvent {
		enum Index {
			/** String */
			name				= 0x01,
			/** Integer */
			trigger				= 0x0B,
			/** Flag */
			switch_flag			= 0x0C,
			/** Integer */
			switch_id			= 0x0D,
			/** Integer */
			event_commands_size	= 0x15,
			/** Array - RPG::EventCommand */
			event_commands		= 0x16 
		};
	};
	struct ChunkSkill {
		enum Index {
			/** String */
			name					= 0x01,
			/** String */
			description				= 0x02,
			/** String - RPG2000 */
			using_message1			= 0x03,
			/** String - RPG2000 */
			using_message2			= 0x04,
			/** Integer - RPG2000 */
			failure_message			= 0x07,
			/** Integer */
			type					= 0x08,
			/** Integer - RPG2003 */
			sp_type					= 0x09,
			/** Integer - RPG2003 */
			sp_percent				= 0x0A,
			/** Integer */
			sp_cost					= 0x0B,
			/** Integer */
			scope					= 0x0C,
			/** Integer */
			switch_id				= 0x0D,
			/** Integer */
			animation_id			= 0x0E,
			/** RPG::Sound */
			sound_effect			= 0x10,
			/** Flag */
			occasion_field			= 0x12,
			/** Flag */
			occasion_battle			= 0x13,
			/** Flag - RPG2003 */
			state_effect			= 0x14,
			/** Integer */
			pdef_f					= 0x15,
			/** Integer */
			mdef_f					= 0x16,
			/** Integer */
			variance				= 0x17,
			/** Integer */
			power					= 0x18,
			/** Integer */
			hit						= 0x19,
			/** Flag */
			affect_hp				= 0x1F,
			/** Flag */
			affect_sp				= 0x20,
			/** Flag */
			affect_attack			= 0x21,
			/** Flag */
			affect_defense			= 0x22,
			/** Flag */
			affect_spirit			= 0x23,
			/** Flag */
			affect_agility			= 0x24,
			/** Flag */
			absorb_damage			= 0x25,
			/** Flag */
			ignore_defense			= 0x26,
			/** Integer */
			state_effects_size		= 0x29,
			/** Array - Flag */
			state_effects			= 0x2A,
			/** Integer */
			attribute_effects_size	= 0x2B,
			/** Array - Flag */
			attribute_effects		= 0x2C,
			/** Flag */
			affect_attr_defence		= 0x2D,
			/** Integer - RPG2003 */
			battler_animation		= 0x31,
			/** ? - RPG2003 */
			battler_animation_data	= 0x32 
		};
	};
	struct ChunkItemAnimation {
		enum Index {
			/**  */
			type			= 0x03,
			/**  */
			weapon_anim		= 0x04,
			/**  */
			movement		= 0x05,
			/**  */
			after_image		= 0x06,
			/**  */
			attacks			= 0x07,
			/**  */
			ranged			= 0x08,
			/**  */
			ranged_anim		= 0x09,
			/**  */
			ranged_speed	= 0x0C,
			/**  */
			battle_anim		= 0x0D 
		};
	};
	struct ChunkItem {
		enum Index {
			/** String */
			name				= 0x01,
			/** String */
			description			= 0x02,
			/** Integer */
			type				= 0x03,
			/** Integer */
			price				= 0x05,
			/** Integer */
			uses				= 0x06,
			/** Integer */
			atk_points1			= 0x0B,
			/** Integer */
			def_points1			= 0x0C,
			/** Integer */
			spi_points1			= 0x0D,
			/** Integer */
			agi_points1			= 0x0E,
			/** Flag */
			two_handed			= 0x0F,
			/** Integer */
			sp_cost				= 0x10,
			/** Integer */
			hit					= 0x11,
			/** Integer */
			critical_hit		= 0x12,
			/** Integer */
			animation_id		= 0x14,
			/** Flag */
			preemptive			= 0x15,
			/** Flag */
			dual_attack			= 0x16,
			/** Flag */
			attack_all			= 0x17,
			/** Flag */
			ignore_evasion		= 0x18,
			/** Flag */
			prevent_critical	= 0x19,
			/** Flag */
			raise_evasion		= 0x1A,
			/** Flag */
			half_sp_cost		= 0x1B,
			/** Flag */
			no_terrain_damage	= 0x1C,
			/** Flag - RPG2003 */
			cursed				= 0x1D,
			/** Flag */
			entire_party		= 0x1F,
			/** Integer */
			recover_hp			= 0x20,
			/** Integer */
			recover_hp_rate		= 0x21,
			/** Integer */
			recover_sp			= 0x22,
			/** Integer */
			recover_sp_rate		= 0x23,
			/** Flag */
			occasion_field1		= 0x25,
			/** Flag */
			ko_only				= 0x26,
			/** Integer */
			max_hp_points		= 0x29,
			/** Integer */
			max_sp_points		= 0x2A,
			/** Integer */
			atk_points2			= 0x2B,
			/** Integer */
			def_points2			= 0x2C,
			/** Integer */
			spi_points2			= 0x2D,
			/** Integer */
			agi_points2			= 0x2E,
			/** Integer */
			using_message		= 0x33,
			/** Integer - RPG2003 */
			skill_id			= 0x35,
			/** Integer */
			switch_id			= 0x37,
			/** Flag */
			occasion_field2		= 0x39,
			/** Flag */
			occasion_battle		= 0x3A,
			/** Integer */
			actor_set_size		= 0x3D,
			/** Array - Flag */
			actor_set			= 0x3E,
			/** Integer */
			state_set_size		= 0x3F,
			/** Array - Flag */
			state_set			= 0x40,
			/** Integer */
			attribute_set_size	= 0x41,
			/** Array - Flag */
			attribute_set		= 0x42,
			/** Integer */
			state_chance		= 0x43,
			/** Flag */
			state_effect		= 0x44,
			/** Integer - RPG2003 */
			weapon_animation	= 0x45,
			/** Array - RPG2003 */
			animation_data		= 0x46,
			/** Flag - RPG2003 */
			use_skill			= 0x47,
			/** Integer - RPG2003 */
			class_set_size		= 0x48,
			/** Array - Flag - RPG2003 */
			class_set			= 0x49,
			/** Integer */
			ranged_trajectory	= 0x4B,
			/** Integer */
			ranged_target		= 0x4C 
		};
	};
	struct ChunkEnemyAction {
		enum Index {
			/** Integer */
			kind				= 0x01,
			/** Integer */
			basic				= 0x02,
			/** Integer */
			skill_id			= 0x03,
			/** Integer */
			enemy_id			= 0x04,
			/** Integer */
			condition_type		= 0x05,
			/** Integer */
			condition_param1	= 0x06,
			/** Integer */
			condition_param2	= 0x07,
			/** Integer */
			switch_id			= 0x08,
			/** Flag */
			switch_on			= 0x09,
			/** Integer */
			switch_on_id		= 0x0A,
			/** Flag */
			switch_off			= 0x0B,
			/** Integer */
			switch_off_id		= 0x0C,
			/** Integer */
			rating				= 0x0D 
		};
	};
	struct ChunkEnemy {
		enum Index {
			/** String */
			name					= 0x01,
			/** String */
			battler_name			= 0x02,
			/** Integer */
			battler_hue				= 0x03,
			/** Integer */
			max_hp					= 0x04,
			/** Integer */
			max_sp					= 0x05,
			/** Integer */
			attack					= 0x06,
			/** Integer */
			defense					= 0x07,
			/** Integer */
			spirit					= 0x08,
			/** Integer */
			agility					= 0x09,
			/** Flag */
			transparent				= 0x0A,
			/** Integer */
			exp						= 0x0B,
			/** Integer */
			gold					= 0x0C,
			/** Integer */
			drop_id					= 0x0D,
			/** Integer */
			drop_prob				= 0x0E,
			/** Flag */
			critical_hit			= 0x15,
			/** Integer */
			critical_hit_chance		= 0x16,
			/** Flag */
			miss					= 0x1A,
			/** Flag */
			levitate				= 0x1C,
			/** Integer */
			state_ranks_size		= 0x1F,
			/** Array - Short */
			state_ranks				= 0x20,
			/** Integer */
			attribute_ranks_size	= 0x21,
			/** Array - Short */
			attribute_ranks			= 0x22,
			/** Array - RPG::EnemyAction */
			actions					= 0x2A 
		};
	};
	struct ChunkTroopMember {
		enum Index {
			/** Integer */
			enemy_id	= 0x01,
			/** Integer */
			x			= 0x02,
			/** Integer */
			y			= 0x03,
			/** Flag */
			invisible	= 0x04 
		};
	};
	struct ChunkTroopPageCondition {
		enum Index {
			/** Bitflag - x 2 if RPG2003 */
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
			turn_a				= 0x06,
			/** Integer */
			turn_b				= 0x07,
			/** Integer */
			fatigue_min			= 0x08,
			/** Integer */
			fatigue_max			= 0x09,
			/** Integer */
			enemy_id			= 0x0A,
			/** Integer */
			enemy_hp_min		= 0x0B,
			/** Integer */
			enemy_hp_max		= 0x0C,
			/** Integer */
			actor_id			= 0x0D,
			/** Integer */
			actor_hp_min		= 0x0E,
			/** Integer */
			actor_hp_max		= 0x0F,
			/** Integer - RPG2003 */
			turn_enemy_id		= 0x10,
			/** Integer - RPG2003 */
			turn_enemy_a		= 0x11,
			/** Integer - RPG2003 */
			turn_enemy_b		= 0x12,
			/** Integer - RPG2003 */
			turn_actor_id		= 0x13,
			/** Integer - RPG2003 */
			turn_actor_a		= 0x14,
			/** Integer - RPG2003 */
			turn_actor_b		= 0x15,
			/** Integer - RPG2003 */
			command_actor_id	= 0x16,
			/** Integer - RPG2003 */
			command_id			= 0x17 
		};
	};
	struct ChunkTroopPage {
		enum Index {
			/** RPG::TroopPageCondition */
			condition			= 0x02,
			/** Integer */
			event_commands_size	= 0x0B,
			/** Array - RPG::EventCommand */
			event_commands		= 0x0C 
		};
	};
	struct ChunkTroop {
		enum Index {
			/** String */
			name				= 0x01,
			/** Array - RPG::TroopMember */
			members				= 0x02,
			/** Integer */
			terrain_set_size	= 0x04,
			/** Array - Flag */
			terrain_set			= 0x05,
			/** Array - RPG::TroopPage */
			pages				= 0x0B 
		};
	};
	struct ChunkTerrain {
		enum Index {
			/** String */
			name						= 0x01,
			/** Integer */
			damage						= 0x02,
			/** Integer */
			encounter_rate				= 0x03,
			/** String */
			background_name				= 0x04,
			/** Flag */
			boat_pass					= 0x05,
			/** Flag */
			ship_pass					= 0x06,
			/** Flag */
			airship_pass				= 0x07,
			/** Flag */
			airship_land				= 0x09,
			/** Integer */
			bush_depth					= 0x0B,
			/** RPG::Sound - RPG2003 */
			footstep					= 0x0F,
			/** Flag - RPG2003 */
			on_damage_se				= 0x10,
			/** Integer - RPG2003 */
			background_type				= 0x11,
			/** String - RPG2003 */
			background_a_name			= 0x15,
			/** Flag - RPG2003 */
			background_a_scrollh		= 0x16,
			/** Flag - RPG2003 */
			background_a_scrollv		= 0x17,
			/** Integer - RPG2003 */
			background_a_scrollh_speed	= 0x18,
			/** Integer - RPG2003 */
			background_a_scrollv_speed	= 0x19,
			/** Flag - RPG2003 */
			background_b				= 0x1E,
			/** String - RPG2003 */
			background_b_name			= 0x1F,
			/** Flag - RPG2003 */
			background_b_scrollh		= 0x20,
			/** Flag - RPG2003 */
			background_b_scrollv		= 0x21,
			/** Integer - RPG2003 */
			background_b_scrollh_speed	= 0x22,
			/** Integer - RPG2003 */
			background_b_scrollv_speed	= 0x23,
			/** Bitflag - RPG2003 */
			special_flags				= 0x28,
			/** Integer - RPG2003 */
			special_back_party			= 0x29,
			/** Integer - RPG2003 */
			special_back_enemies		= 0x2A,
			/** Integer - RPG2003 */
			special_lateral_party		= 0x2B,
			/** Integer - RPG2003 */
			special_lateral_enemies		= 0x2C,
			/** Integer - RPG2003 */
			grid_location				= 0x2D,
			/** Integer - RPG2003 */
			grid_a						= 0x2E,
			/** Integer - RPG2003 */
			grid_b						= 0x2F,
			/** Integer - RPG2003 */
			grid_c						= 0x30 
		};
	};
	struct ChunkState {
		enum Index {
			/** String */
			name					= 0x01,
			/** Integer */
			type					= 0x02,
			/** Integer */
			color					= 0x03,
			/** Integer */
			priority				= 0x04,
			/** Integer */
			restriction				= 0x05,
			/** Integer */
			a_rate					= 0x0B,
			/** Integer */
			b_rate					= 0x0C,
			/** Integer */
			c_rate					= 0x0D,
			/** Integer */
			d_rate					= 0x0E,
			/** Integer */
			e_rate					= 0x0F,
			/** Integer */
			hold_turn				= 0x15,
			/** Integer */
			auto_release_prob		= 0x16,
			/** Integer */
			release_by_damage		= 0x17,
			/** Integer - RPG2003 */
			affect_type				= 0x1E,
			/** Flag */
			affect_attack			= 0x1F,
			/** Flag */
			affect_defense			= 0x20,
			/** Flag */
			affect_spirit			= 0x21,
			/** Flag */
			affect_agility			= 0x22,
			/** Integer */
			reduce_hit_ratio		= 0x23,
			/** Flag - RPG2003 */
			avoid_attacks			= 0x24,
			/** Flag - RPG2003 */
			reflect_magic			= 0x25,
			/** Flag - RPG2003 */
			cursed					= 0x26,
			/** Integer - RPG2003 */
			battler_animation_id	= 0x27,
			/** Flag */
			restrict_skill			= 0x29,
			/** Integer */
			restrict_skill_level	= 0x2A,
			/** Flag */
			restrict_magic			= 0x2B,
			/** Integer */
			restrict_magic_level	= 0x2C,
			/** Integer */
			hp_change_type			= 0x2D,
			/** Integer */
			sp_change_type			= 0x2E,
			/** String */
			message_actor			= 0x33,
			/** String */
			message_enemy			= 0x34,
			/** String */
			message_already			= 0x35,
			/** String */
			message_affected		= 0x36,
			/** String */
			message_recovery		= 0x37,
			/** Integer */
			hp_change_max			= 0x3D,
			/** Integer */
			hp_change_val			= 0x3E,
			/** Integer */
			hp_change_map_val		= 0x3F,
			/** Integer */
			hp_change_map_steps		= 0x40,
			/** Integer */
			sp_change_max			= 0x41,
			/** Integer */
			sp_change_val			= 0x42,
			/** Integer */
			sp_change_map_val		= 0x43,
			/** Integer */
			sp_change_map_steps		= 0x44 
		};
	};
	struct ChunkTerms {
		enum Index {
			/** String */
			encounter			= 0x01,
			/** String */
			special_combat		= 0x02,
			/** String */
			escape_success		= 0x03,
			/** String */
			escape_failure		= 0x04,
			/** String */
			victory				= 0x05,
			/** String */
			defeat				= 0x06,
			/** String */
			exp_received		= 0x07,
			/** String */
			gold_recieved_a		= 0x08,
			/** String */
			gold_recieved_b		= 0x09,
			/** String */
			item_recieved		= 0x0A,
			/** String */
			attacking			= 0x0B,
			/** String */
			actor_critical		= 0x0C,
			/** String */
			enemy_critical		= 0x0D,
			/** String */
			defending			= 0x0E,
			/** String */
			observing			= 0x0F,
			/** String */
			focus				= 0x10,
			/** String */
			autodestruction		= 0x11,
			/** String */
			enemy_escape		= 0x12,
			/** String */
			enemy_transform		= 0x13,
			/** String */
			enemy_damaged		= 0x14,
			/** String */
			enemy_undamaged		= 0x15,
			/** String */
			actor_damaged		= 0x16,
			/** String */
			actor_undamaged		= 0x17,
			/** String */
			skill_failure_a		= 0x18,
			/** String */
			skill_failure_b		= 0x19,
			/** String */
			skill_failure_c		= 0x1A,
			/** String */
			dodge				= 0x1B,
			/** String */
			use_item			= 0x1C,
			/** String */
			hp_recovery			= 0x1D,
			/** String */
			parameter_increase	= 0x1E,
			/** String */
			parameter_decrease	= 0x1F,
			/** String */
			actor_hp_absorbed	= 0x20,
			/** String */
			enemy_hp_absorbed	= 0x21,
			/** String */
			resistance_increase	= 0x22,
			/** String */
			resistance_decrease	= 0x23,
			/** String */
			level_up			= 0x24,
			/** String */
			skill_learned		= 0x25,
			/** String */
			battle_start		= 0x26,
			/** String */
			miss				= 0x27,
			/** String */
			shop_greeting1		= 0x29,
			/** String */
			shop_regreeting1	= 0x2A,
			/** String */
			shop_buy1			= 0x2B,
			/** String */
			shop_sell1			= 0x2C,
			/** String */
			shop_leave1			= 0x2D,
			/** String */
			shop_buy_select1	= 0x2E,
			/** String */
			shop_buy_number1	= 0x2F,
			/** String */
			shop_purchased1		= 0x30,
			/** String */
			shop_sell_select1	= 0x31,
			/** String */
			shop_sell_number1	= 0x32,
			/** String */
			shop_sold1			= 0x33,
			/** String */
			shop_greeting2		= 0x36,
			/** String */
			shop_regreeting2	= 0x37,
			/** String */
			shop_buy2			= 0x38,
			/** String */
			shop_sell2			= 0x39,
			/** String */
			shop_leave2			= 0x3A,
			/** String */
			shop_buy_select2	= 0x3B,
			/** String */
			shop_buy_number2	= 0x3C,
			/** String */
			shop_purchased2		= 0x3D,
			/** String */
			shop_sell_select2	= 0x3E,
			/** String */
			shop_sell_number2	= 0x3F,
			/** String */
			shop_sold2			= 0x40,
			/** String */
			shop_greeting3		= 0x43,
			/** String */
			shop_regreeting3	= 0x44,
			/** String */
			shop_buy3			= 0x45,
			/** String */
			shop_sell3			= 0x46,
			/** String */
			shop_leave3			= 0x47,
			/** String */
			shop_buy_select3	= 0x48,
			/** String */
			shop_buy_number3	= 0x49,
			/** String */
			shop_purchased3		= 0x4A,
			/** String */
			shop_sell_select3	= 0x4B,
			/** String */
			shop_sell_number3	= 0x4C,
			/** String */
			shop_sold3			= 0x4D,
			/** String */
			inn_a_greeting_1	= 0x50,
			/** String */
			inn_a_greeting_2	= 0x51,
			/** String */
			inn_a_greeting_3	= 0x52,
			/** String */
			inn_a_accept		= 0x53,
			/** String */
			inn_a_cancel		= 0x54,
			/** String */
			inn_b_greeting_1	= 0x55,
			/** String */
			inn_b_greeting_2	= 0x56,
			/** String */
			inn_b_greeting_3	= 0x57,
			/** String */
			inn_b_accept		= 0x58,
			/** String */
			inn_b_cancel		= 0x59,
			/** String */
			possessed_items		= 0x5C,
			/** String */
			equipped_items		= 0x5D,
			/** String */
			gold				= 0x5F,
			/** String */
			battle_fight		= 0x65,
			/** String */
			battle_auto			= 0x66,
			/** String */
			battle_escape		= 0x67,
			/** String */
			command_attack		= 0x68,
			/** String */
			command_defend		= 0x69,
			/** String */
			command_item		= 0x6A,
			/** String */
			command_skill		= 0x6B,
			/** String */
			menu_equipment		= 0x6C,
			/** String */
			menu_save			= 0x6E,
			/** String */
			menu_quit			= 0x70,
			/** String */
			new_game			= 0x72,
			/** String */
			load_game			= 0x73,
			/** String */
			exit_game			= 0x75,
			/** String */
			status				= 0x76,
			/** String */
			row					= 0x77,
			/** String */
			order				= 0x78,
			/** String */
			wait_on				= 0x79,
			/** String */
			wait_off			= 0x7A,
			/** String */
			level				= 0x7B,
			/** String */
			health_points		= 0x7C,
			/** String */
			spirit_points		= 0x7D,
			/** String */
			normal_status		= 0x7E,
			/** String - char x 2? */
			exp_short			= 0x7F,
			/** String - char x 2? */
			lvl_short			= 0x80,
			/** String - char x 2? */
			hp_short			= 0x81,
			/** String - char x 2? */
			sp_short			= 0x82,
			/** String */
			sp_cost				= 0x83,
			/** String */
			attack				= 0x84,
			/** String */
			defense				= 0x85,
			/** String */
			spirit				= 0x86,
			/** String */
			agility				= 0x87,
			/** String */
			weapon				= 0x88,
			/** String */
			shield				= 0x89,
			/** String */
			armor				= 0x8A,
			/** String */
			helmet				= 0x8B,
			/** String */
			accessory			= 0x8C,
			/** String */
			save_game_message	= 0x92,
			/** String */
			load_game_message	= 0x93,
			/** String */
			file				= 0x94,
			/** String */
			exit_game_message	= 0x97,
			/** String */
			yes					= 0x98,
			/** String */
			no					= 0x99 
		};
	};
	struct ChunkMusic {
		enum Index {
			/** String */
			name	= 0x01,
			/** Integer */
			fadein	= 0x02,
			/** Integer */
			volume	= 0x03,
			/** Integer */
			tempo	= 0x04,
			/** Integer */
			balance	= 0x05 
		};
	};
	struct ChunkTestBattler {
		enum Index {
			/** Integer */
			actor_id		= 0x01,
			/** Integer */
			level			= 0x02,
			/** Integer */
			weapon_id		= 0x0B,
			/** Integer */
			shield_id		= 0x0C,
			/** Integer */
			armor_id		= 0x0D,
			/** Integer */
			helmet_id		= 0x0E,
			/** Integer */
			accessory_id	= 0x0F 
		};
	};
	struct ChunkSystem {
		enum Index {
			/** Integer - RPG2003 */
			ldb_id					= 0x0A,
			/** String */
			boat_name				= 0x0B,
			/** String */
			ship_name				= 0x0C,
			/** String */
			airship_name			= 0x0D,
			/** Integer */
			boat_index				= 0x0E,
			/** Integer */
			ship_index				= 0x0F,
			/** Integer */
			airship_index			= 0x10,
			/** String */
			title_name				= 0x11,
			/** String */
			gameover_name			= 0x12,
			/** String */
			system_name				= 0x13,
			/** String - RPG2003 */
			system2_name			= 0x14,
			/** Integer */
			party_size				= 0x15,
			/** Array - Short */
			party					= 0x16,
			/** Integer - RPG2003 */
			menu_commands_size		= 0x1A,
			/** Array - Short - RPG2003 */
			menu_commands			= 0x1B,
			/** RPG::Music */
			title_music				= 0x1F,
			/** RPG::Music */
			battle_music			= 0x20,
			/** RPG::Music */
			battle_end_music		= 0x21,
			/** RPG::Music */
			inn_music				= 0x22,
			/** RPG::Music */
			boat_music				= 0x23,
			/** RPG::Music */
			ship_music				= 0x24,
			/** RPG::Music */
			airship_music			= 0x25,
			/** RPG::Music */
			gameover_music			= 0x26,
			/** RPG::Sound */
			cursor_se				= 0x29,
			/** RPG::Sound */
			decision_se				= 0x2A,
			/** RPG::Sound */
			cancel_se				= 0x2B,
			/** RPG::Sound */
			buzzer_se				= 0x2C,
			/** RPG::Sound */
			battle_se				= 0x2D,
			/** RPG::Sound */
			escape_se				= 0x2E,
			/** RPG::Sound */
			enemy_attack_se			= 0x2F,
			/** RPG::Sound */
			enemy_damaged_se		= 0x30,
			/** RPG::Sound */
			actor_damaged_se		= 0x31,
			/** RPG::Sound */
			dodge_se				= 0x32,
			/** RPG::Sound */
			enemy_death_se			= 0x33,
			/** RPG::Sound */
			item_se					= 0x34,
			/** Integer */
			transition_out			= 0x3D,
			/** Integer */
			transition_in			= 0x3E,
			/** Integer */
			battle_start_fadeout	= 0x3F,
			/** Integer */
			battle_start_fadein		= 0x40,
			/** Integer */
			battle_end_fadeout		= 0x41,
			/** Integer */
			battle_end_fadein		= 0x42,
			/** Integer */
			message_stretch			= 0x47,
			/** Integer */
			font_id					= 0x48,
			/** Integer */
			selected_condition		= 0x51,
			/** Integer */
			selected_hero			= 0x52,
			/** String */
			battletest_background	= 0x54,
			/** Array - RPG::TestBattler */
			battletest_data			= 0x55,
			/** Integer */
			saved_times				= 0x5B,
			/** Integer */
			battletest_terrain		= 0x5E,
			/** Integer */
			battletest_formation	= 0x5F,
			/** Integer */
			battletest_condition	= 0x60,
			/** Flag - RPG2003 */
			show_frame				= 0x63,
			/** String - RPG2003 */
			frame_name				= 0x64,
			/** Flag - RPG2003 */
			invert_animations		= 0x65 
		};
	};
	struct ChunkSwitch {
		enum Index {
			/** String */
			name	= 0x01 
		};
	};
	struct ChunkVariable {
		enum Index {
			/** String */
			name	= 0x01 
		};
	};
	struct ChunkDatabase {
		enum Index {
			/** RPG::Actor */
			actors				= 0x0B,
			/** RPG::Skill */
			skills				= 0x0C,
			/** RPG::Item */
			items				= 0x0D,
			/** RPG::Enemy */
			enemies				= 0x0E,
			/** RPG::Troop */
			troops				= 0x0F,
			/** RPG::Terrain */
			terrains			= 0x10,
			/** RPG::Attribute */
			attributes			= 0x11,
			/** RPG::State */
			states				= 0x12,
			/** RPG::Animation */
			animations			= 0x13,
			/** RPG::Chipset */
			chipsets			= 0x14,
			/** RPG::Terms */
			terms				= 0x15,
			/** RPG::System */
			system				= 0x16,
			/** RPG::Switchs */
			switches			= 0x17,
			/** RPG::Variables */
			variables			= 0x18,
			/** RPG::CommonEvent */
			commonevents		= 0x19,
			/** Duplicated? - Not used - RPG2003 */
			commoneventD1		= 0x1A,
			/** Duplicated? - Not used - RPG2003 */
			commoneventD2		= 0x1B,
			/** Duplicated? - Not used - RPG2003 */
			commoneventD3		= 0x1C,
			/** RPG::BattleCommand - RPG2003 */
			battlecommands		= 0x1D,
			/** RPG::Class - RPG2003 */
			classes				= 0x1E,
			/** Duplicated? - Not used - RPG2003 */
			classD1				= 0x1F,
			/** RPG::BattlerAnimation - RPG2003 */
			battleranimations	= 0x20 
		};
	};
}

#endif
