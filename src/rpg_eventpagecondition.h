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

#ifndef _RPG_EVENTPAGECONDITION_H_
#define _RPG_EVENTPAGECONDITION_H_

/**
 * RPG::EventPageCondition class.
 */
namespace RPG {
	class EventPageCondition {
	public:
		enum Comparison {
			Comparison_equal = 0,
			Comparison_greater_equal = 1,
			Comparison_less_equal = 2,
			Comparison_greater = 3,
			Comparison_less = 4,
			Comparison_not_equal = 5
		};

		EventPageCondition();

		struct Flags {
			bool switch_a;
			bool switch_b;
			bool variable;
			bool item;
			bool actor;
			bool timer;
			bool timer2;
		} flags;
		int switch_a_id;
		int switch_b_id;
		int variable_id;
		int variable_value;
		int item_id;
		int actor_id;
		int timer_sec;
		int timer2_sec;
		int compare_operator;
	};
}

#endif
