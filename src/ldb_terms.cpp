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
#include "ldb_reader.h"
#include "ldb_chunks.h"
#include "reader_struct.h"

// Read Terms.

#define EASYRPG_CHUNK_SUFFIX LDB_Reader
#define EASYRPG_CURRENT_STRUCT Terms

EASYRPG_STRUCT_FIELDS_BEGIN()
	EASYRPG_STRUCT_TYPED_FIELD(std::string, encounter),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, special_combat),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, escape_success),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, escape_failure),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, victory),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, defeat),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, exp_received),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, gold_recieved_a),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, gold_recieved_b),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, item_recieved),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, attacking),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, actor_critical),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, enemy_critical),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, defending),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, observing),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, focus),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, autodestruction),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, enemy_escape),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, enemy_transform),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, enemy_damaged),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, enemy_undamaged),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, actor_damaged),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, actor_undamaged),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, skill_failure_a),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, skill_failure_b),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, skill_failure_c),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, dodge),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, use_item),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, hp_recovery),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, parameter_increase),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, parameter_decrease),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, actor_hp_absorbed),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, enemy_hp_absorbed),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, resistance_increase),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, resistance_decrease),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, level_up),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, skill_learned),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, battle_start),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, miss),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_greeting1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_regreeting1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_buy1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sell1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_leave1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_buy_select1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_buy_number1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_purchased1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sell_select1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sell_number1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sold1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_greeting2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_regreeting2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_buy2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sell2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_leave2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_buy_select2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_buy_number2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_purchased2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sell_select2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sell_number2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sold2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_greeting3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_regreeting3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_buy3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sell3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_leave3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_buy_select3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_buy_number3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_purchased3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sell_select3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sell_number3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shop_sold3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_a_greeting_1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_a_greeting_2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_a_greeting_3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_a_accept),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_a_cancel),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_b_greeting_1),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_b_greeting_2),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_b_greeting_3),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_b_accept),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, inn_b_cancel),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, possessed_items),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, equipped_items),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, gold),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, battle_fight),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, battle_auto),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, battle_escape),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, command_attack),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, command_defend),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, command_item),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, command_skill),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, menu_equipment),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, menu_save),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, menu_quit),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, new_game),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, load_game),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, exit_game),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, status),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, row),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, order),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, wait_on),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, wait_off),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, level),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, health_points),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, spirit_points),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, normal_status),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, exp_short),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, lvl_short),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, hp_short),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, sp_short),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, sp_cost),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, attack),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, defense),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, spirit),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, agility),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, weapon),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, shield),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, armor),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, helmet),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, accessory),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, save_game_message),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, load_game_message),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, file),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, exit_game_message),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, yes),
	EASYRPG_STRUCT_TYPED_FIELD(std::string, no),
EASYRPG_STRUCT_FIELDS_END()

#undef EASYRPG_CURRENT_STRUCT
#undef EASYRPG_CHUNK_SUFFIX
