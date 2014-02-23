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

#ifndef _RPG_TROOPPAGECONDITION_H_
#define _RPG_TROOPPAGECONDITION_H_

/**
 * RPG::TroopPageCondition class.
 */
namespace RPG {
	class TroopPageCondition {
	public:
		TroopPageCondition();

		struct Flags {
			bool switch_a;
			bool switch_b;
			bool variable;
			bool turn;
			bool fatigue;
			bool enemy_hp;
			bool actor_hp;
			bool turn_enemy;
			bool turn_actor;
			bool command_actor;
		} flags;
		int switch_a_id;
		int switch_b_id;
		int variable_id;
		int variable_value;
		int turn_a;
		int turn_b;
		int fatigue_min;
		int fatigue_max;
		int enemy_id;
		int enemy_hp_min;
		int enemy_hp_max;
		int actor_id;
		int actor_hp_min;
		int actor_hp_max;
		int turn_enemy_id;
		int turn_enemy_a;
		int turn_enemy_b;
		int turn_actor_id;
		int turn_actor_a;
		int turn_actor_b;
		int command_actor_id;
		int command_id;
	};
}

#endif
