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
#include "rpg_eventpagecondition.h"

/**
 * Constructor.
 */
RPG::EventPageCondition::EventPageCondition() {
	flags.switch_a = false;
	flags.switch_b = false;
	flags.variable = false;
	flags.item = false;
	flags.actor = false;
	flags.timer = false;
	flags.timer2 = false;
	switch_a_id = 1;
	switch_b_id = 1;
	variable_id = 1;
	variable_value = 0;
	item_id = 1;
	actor_id = 1;
	timer_sec = 0;
	timer2_sec = 0;
	compare_operator = 1;
}
