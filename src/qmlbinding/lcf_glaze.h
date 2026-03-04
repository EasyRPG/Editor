/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QString>
#include <glaze/glaze.hpp>
#include <lcf/dbbitarray.h>
#include <lcf/dbstring.h>
#include <lcf/rpg/database.h>
#include <lcf/rpg/terms.h>
#include <lcf/rpg/terrain.h>
#include <lcf/rpg/troop.h>
#include <lcf/rpg/trooppagecondition.h>

namespace {
template<typename RETTYPE, typename LCFTYPE>
static RETTYPE glaze_get(LCFTYPE* data, QString jsonPtr) {
	return glz::get<RETTYPE>(*data, jsonPtr.toStdString()).value();
}
}

namespace glz {

// JSON support for the custom lcf types
template <> struct from<JSON, lcf::DBString> {
	template <auto Opts>
	static void op(lcf::DBString &value, is_context auto &&ctx, auto &&it,
								 auto &&end) {
		std::string str;
		parse<JSON>::op<Opts>(str, ctx, it, end);
		value = lcf::DBString(str);
	}
};

template <> struct to<JSON, lcf::DBString> {
	template <auto Opts>
	static void op(lcf::DBString &value, is_context auto &&ctx, auto &&b,
								 auto &&ix) noexcept {
		std::string str = lcf::ToString(value);
		serialize<JSON>::op<Opts>(str, ctx, b, ix);
	}
};

template <> struct from<JSON, lcf::DBBitArray> {
	template <auto Opts>
	static void op(lcf::DBBitArray &value, is_context auto &&ctx, auto &&it,
								 auto &&end) {
		std::vector<bool> v;
		parse<JSON>::op<Opts>(v, ctx, it, end);
		value = lcf::DBBitArray{v.begin(), v.end()};
	}
};

template <> struct to<JSON, lcf::DBBitArray> {
	template <auto Opts>
	static void op(lcf::DBBitArray &value, is_context auto &&ctx, auto &&b,
								 auto &&ix) noexcept {
		std::vector<bool> v{value.begin(), value.end()};
		serialize<JSON>::op<Opts>(v, ctx, b, ix);
	}
};

// Flags are unions which glaze cannot automatically handle
template <> struct meta<lcf::rpg::TroopPageCondition::Flags> {
	using T = lcf::rpg::TroopPageCondition::Flags;
	static constexpr auto value = object(
		"switch_a", &T::switch_a,
		"switch_b", &T::switch_b,
		"variable", &T::variable,
		"turn", &T::turn,
		"fatigue", &T::fatigue,
		"enemy_hp", &T::enemy_hp,
		"actor_hp", &T::actor_hp,
		"turn_enemy", &T::turn_enemy,
		"turn_actor", &T::turn_actor,
		"command_actor", &T::command_actor
	);
};

template <> struct meta<lcf::rpg::Terrain::Flags> {
	using T = lcf::rpg::Terrain::Flags;
	static constexpr auto value = object(
		"back_party", &T::back_party,
		"back_enemies", &T::back_enemies,
		"lateral_party", &T::lateral_party,
		"lateral_enemies", &T::lateral_enemies
	);
};

// Terms has too many fields
// The automatic "magic" of glaze has a limit of 100
template<>
struct meta<lcf::rpg::Terms> {
	using T = lcf::rpg::Terms;
	static constexpr auto value = object(
		"encounter", &T::encounter,
		"special_combat", &T::special_combat,
		"escape_success", &T::escape_success,
		"escape_failure", &T::escape_failure,
		"victory", &T::victory,
		"defeat", &T::defeat,
		"exp_received", &T::exp_received,
		"gold_recieved_a", &T::gold_recieved_a,
		"gold_recieved_b", &T::gold_recieved_b,
		"item_recieved", &T::item_recieved,
		"attacking", &T::attacking,
		"enemy_critical", &T::enemy_critical,
		"actor_critical", &T::actor_critical,
		"defending", &T::defending,
		"observing", &T::observing,
		"focus", &T::focus,
		"autodestruction", &T::autodestruction,
		"enemy_escape", &T::enemy_escape,
		"enemy_transform", &T::enemy_transform,
		"enemy_damaged", &T::enemy_damaged,
		"enemy_undamaged", &T::enemy_undamaged,
		"actor_damaged", &T::actor_damaged,
		"actor_undamaged", &T::actor_undamaged,
		"skill_failure_a", &T::skill_failure_a,
		"skill_failure_b", &T::skill_failure_b,
		"skill_failure_c", &T::skill_failure_c,
		"dodge", &T::dodge,
		"use_item", &T::use_item,
		"hp_recovery", &T::hp_recovery,
		"parameter_increase", &T::parameter_increase,
		"parameter_decrease", &T::parameter_decrease,
		"enemy_hp_absorbed", &T::enemy_hp_absorbed,
		"actor_hp_absorbed", &T::actor_hp_absorbed,
		"resistance_increase", &T::resistance_increase,
		"resistance_decrease", &T::resistance_decrease,
		"level_up", &T::level_up,
		"skill_learned", &T::skill_learned,
		"battle_start", &T::battle_start,
		"miss", &T::miss,
		"shop_greeting1", &T::shop_greeting1,
		"shop_regreeting1", &T::shop_regreeting1,
		"shop_buy1", &T::shop_buy1,
		"shop_sell1", &T::shop_sell1,
		"shop_leave1", &T::shop_leave1,
		"shop_buy_select1", &T::shop_buy_select1,
		"shop_buy_number1", &T::shop_buy_number1,
		"shop_purchased1", &T::shop_purchased1,
		"shop_sell_select1", &T::shop_sell_select1,
		"shop_sell_number1", &T::shop_sell_number1,
		"shop_sold1", &T::shop_sold1,
		"shop_greeting2", &T::shop_greeting2,
		"shop_regreeting2", &T::shop_regreeting2,
		"shop_buy2", &T::shop_buy2,
		"shop_sell2", &T::shop_sell2,
		"shop_leave2", &T::shop_leave2,
		"shop_buy_select2", &T::shop_buy_select2,
		"shop_buy_number2", &T::shop_buy_number2,
		"shop_purchased2", &T::shop_purchased2,
		"shop_sell_select2", &T::shop_sell_select2,
		"shop_sell_number2", &T::shop_sell_number2,
		"shop_sold2", &T::shop_sold2,
		"shop_greeting3", &T::shop_greeting3,
		"shop_regreeting3", &T::shop_regreeting3,
		"shop_buy3", &T::shop_buy3,
		"shop_sell3", &T::shop_sell3,
		"shop_leave3", &T::shop_leave3,
		"shop_buy_select3", &T::shop_buy_select3,
		"shop_buy_number3", &T::shop_buy_number3,
		"shop_purchased3", &T::shop_purchased3,
		"shop_sell_select3", &T::shop_sell_select3,
		"shop_sell_number3", &T::shop_sell_number3,
		"shop_sold3", &T::shop_sold3,
		"inn_a_greeting_1", &T::inn_a_greeting_1,
		"inn_a_greeting_2", &T::inn_a_greeting_2,
		"inn_a_greeting_3", &T::inn_a_greeting_3,
		"inn_a_accept", &T::inn_a_accept,
		"inn_a_cancel", &T::inn_a_cancel,
		"inn_b_greeting_1", &T::inn_b_greeting_1,
		"inn_b_greeting_2", &T::inn_b_greeting_2,
		"inn_b_greeting_3", &T::inn_b_greeting_3,
		"inn_b_accept", &T::inn_b_accept,
		"inn_b_cancel", &T::inn_b_cancel,
		"possessed_items", &T::possessed_items,
		"equipped_items", &T::equipped_items,
		"gold", &T::gold,
		"battle_fight", &T::battle_fight,
		"battle_auto", &T::battle_auto,
		"battle_escape", &T::battle_escape,
		"command_attack", &T::command_attack,
		"command_defend", &T::command_defend,
		"command_item", &T::command_item,
		"command_skill", &T::command_skill,
		"menu_equipment", &T::menu_equipment,
		"menu_save", &T::menu_save,
		"menu_quit", &T::menu_quit,
		"new_game", &T::new_game,
		"load_game", &T::load_game,
		"exit_game", &T::exit_game,
		"status", &T::status,
		"row", &T::row,
		"order", &T::order,
		"wait_on", &T::wait_on,
		"wait_off", &T::wait_off,
		"level", &T::level,
		"health_points", &T::health_points,
		"spirit_points", &T::spirit_points,
		"normal_status", &T::normal_status,
		"exp_short", &T::exp_short,
		"lvl_short", &T::lvl_short,
		"hp_short", &T::hp_short,
		"sp_short", &T::sp_short,
		"sp_cost", &T::sp_cost,
		"attack", &T::attack,
		"defense", &T::defense,
		"spirit", &T::spirit,
		"agility", &T::agility,
		"weapon", &T::weapon,
		"shield", &T::shield,
		"armor", &T::armor,
		"helmet", &T::helmet,
		"accessory", &T::accessory,
		"save_game_message", &T::save_game_message,
		"load_game_message", &T::load_game_message,
		"file", &T::file,
		"exit_game_message", &T::exit_game_message,
		"yes", &T::yes,
		"no", &T::no,
		"maniac_item_received_a", &T::maniac_item_received_a,
		"maniac_level_up_a", &T::maniac_level_up_a,
		"maniac_level_up_b", &T::maniac_level_up_b,
		"maniac_level_up_c", &T::maniac_level_up_c,
		"maniac_exp_received_a", &T::maniac_exp_received_a,
		"maniac_skill_learned_a", &T::maniac_skill_learned_a,
		"easyrpg_item_number_separator", &T::easyrpg_item_number_separator,
		"easyrpg_skill_cost_separator", &T::easyrpg_skill_cost_separator,
		"easyrpg_equipment_arrow", &T::easyrpg_equipment_arrow,
		"easyrpg_status_scene_name", &T::easyrpg_status_scene_name,
		"easyrpg_status_scene_class", &T::easyrpg_status_scene_class,
		"easyrpg_status_scene_title", &T::easyrpg_status_scene_title,
		"easyrpg_status_scene_condition", &T::easyrpg_status_scene_condition,
		"easyrpg_status_scene_front", &T::easyrpg_status_scene_front,
		"easyrpg_status_scene_back", &T::easyrpg_status_scene_back,
		"easyrpg_order_scene_confirm", &T::easyrpg_order_scene_confirm,
		"easyrpg_order_scene_redo", &T::easyrpg_order_scene_redo,
		"easyrpg_battle2k3_double_attack", &T::easyrpg_battle2k3_double_attack,
		"easyrpg_battle2k3_defend", &T::easyrpg_battle2k3_defend,
		"easyrpg_battle2k3_observe", &T::easyrpg_battle2k3_observe,
		"easyrpg_battle2k3_charge", &T::easyrpg_battle2k3_charge,
		"easyrpg_battle2k3_selfdestruct", &T::easyrpg_battle2k3_selfdestruct,
		"easyrpg_battle2k3_escape", &T::easyrpg_battle2k3_escape,
		"easyrpg_battle2k3_special_combat_back", &T::easyrpg_battle2k3_special_combat_back,
		"easyrpg_battle2k3_skill", &T::easyrpg_battle2k3_skill,
		"easyrpg_battle2k3_item", &T::easyrpg_battle2k3_item
	);
};

} // namespace glz
