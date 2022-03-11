/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
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

// Headers
#include <lcf/rpg/terms.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::Terms class.
 * Exposes lcf::rpg::Terms to QML.
 */
namespace Binding::Generated {
class Terms : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(QString encounter READ encounter WRITE set_encounter NOTIFY encounter_changed)
	Q_PROPERTY(QString special_combat READ special_combat WRITE set_special_combat NOTIFY special_combat_changed)
	Q_PROPERTY(QString escape_success READ escape_success WRITE set_escape_success NOTIFY escape_success_changed)
	Q_PROPERTY(QString escape_failure READ escape_failure WRITE set_escape_failure NOTIFY escape_failure_changed)
	Q_PROPERTY(QString victory READ victory WRITE set_victory NOTIFY victory_changed)
	Q_PROPERTY(QString defeat READ defeat WRITE set_defeat NOTIFY defeat_changed)
	Q_PROPERTY(QString exp_received READ exp_received WRITE set_exp_received NOTIFY exp_received_changed)
	Q_PROPERTY(QString gold_recieved_a READ gold_recieved_a WRITE set_gold_recieved_a NOTIFY gold_recieved_a_changed)
	Q_PROPERTY(QString gold_recieved_b READ gold_recieved_b WRITE set_gold_recieved_b NOTIFY gold_recieved_b_changed)
	Q_PROPERTY(QString item_recieved READ item_recieved WRITE set_item_recieved NOTIFY item_recieved_changed)
	Q_PROPERTY(QString attacking READ attacking WRITE set_attacking NOTIFY attacking_changed)
	Q_PROPERTY(QString enemy_critical READ enemy_critical WRITE set_enemy_critical NOTIFY enemy_critical_changed)
	Q_PROPERTY(QString actor_critical READ actor_critical WRITE set_actor_critical NOTIFY actor_critical_changed)
	Q_PROPERTY(QString defending READ defending WRITE set_defending NOTIFY defending_changed)
	Q_PROPERTY(QString observing READ observing WRITE set_observing NOTIFY observing_changed)
	Q_PROPERTY(QString focus READ focus WRITE set_focus NOTIFY focus_changed)
	Q_PROPERTY(QString autodestruction READ autodestruction WRITE set_autodestruction NOTIFY autodestruction_changed)
	Q_PROPERTY(QString enemy_escape READ enemy_escape WRITE set_enemy_escape NOTIFY enemy_escape_changed)
	Q_PROPERTY(QString enemy_transform READ enemy_transform WRITE set_enemy_transform NOTIFY enemy_transform_changed)
	Q_PROPERTY(QString enemy_damaged READ enemy_damaged WRITE set_enemy_damaged NOTIFY enemy_damaged_changed)
	Q_PROPERTY(QString enemy_undamaged READ enemy_undamaged WRITE set_enemy_undamaged NOTIFY enemy_undamaged_changed)
	Q_PROPERTY(QString actor_damaged READ actor_damaged WRITE set_actor_damaged NOTIFY actor_damaged_changed)
	Q_PROPERTY(QString actor_undamaged READ actor_undamaged WRITE set_actor_undamaged NOTIFY actor_undamaged_changed)
	Q_PROPERTY(QString skill_failure_a READ skill_failure_a WRITE set_skill_failure_a NOTIFY skill_failure_a_changed)
	Q_PROPERTY(QString skill_failure_b READ skill_failure_b WRITE set_skill_failure_b NOTIFY skill_failure_b_changed)
	Q_PROPERTY(QString skill_failure_c READ skill_failure_c WRITE set_skill_failure_c NOTIFY skill_failure_c_changed)
	Q_PROPERTY(QString dodge READ dodge WRITE set_dodge NOTIFY dodge_changed)
	Q_PROPERTY(QString use_item READ use_item WRITE set_use_item NOTIFY use_item_changed)
	Q_PROPERTY(QString hp_recovery READ hp_recovery WRITE set_hp_recovery NOTIFY hp_recovery_changed)
	Q_PROPERTY(QString parameter_increase READ parameter_increase WRITE set_parameter_increase NOTIFY parameter_increase_changed)
	Q_PROPERTY(QString parameter_decrease READ parameter_decrease WRITE set_parameter_decrease NOTIFY parameter_decrease_changed)
	Q_PROPERTY(QString enemy_hp_absorbed READ enemy_hp_absorbed WRITE set_enemy_hp_absorbed NOTIFY enemy_hp_absorbed_changed)
	Q_PROPERTY(QString actor_hp_absorbed READ actor_hp_absorbed WRITE set_actor_hp_absorbed NOTIFY actor_hp_absorbed_changed)
	Q_PROPERTY(QString resistance_increase READ resistance_increase WRITE set_resistance_increase NOTIFY resistance_increase_changed)
	Q_PROPERTY(QString resistance_decrease READ resistance_decrease WRITE set_resistance_decrease NOTIFY resistance_decrease_changed)
	Q_PROPERTY(QString level_up READ level_up WRITE set_level_up NOTIFY level_up_changed)
	Q_PROPERTY(QString skill_learned READ skill_learned WRITE set_skill_learned NOTIFY skill_learned_changed)
	Q_PROPERTY(QString battle_start READ battle_start WRITE set_battle_start NOTIFY battle_start_changed)
	Q_PROPERTY(QString miss READ miss WRITE set_miss NOTIFY miss_changed)
	Q_PROPERTY(QString shop_greeting1 READ shop_greeting1 WRITE set_shop_greeting1 NOTIFY shop_greeting1_changed)
	Q_PROPERTY(QString shop_regreeting1 READ shop_regreeting1 WRITE set_shop_regreeting1 NOTIFY shop_regreeting1_changed)
	Q_PROPERTY(QString shop_buy1 READ shop_buy1 WRITE set_shop_buy1 NOTIFY shop_buy1_changed)
	Q_PROPERTY(QString shop_sell1 READ shop_sell1 WRITE set_shop_sell1 NOTIFY shop_sell1_changed)
	Q_PROPERTY(QString shop_leave1 READ shop_leave1 WRITE set_shop_leave1 NOTIFY shop_leave1_changed)
	Q_PROPERTY(QString shop_buy_select1 READ shop_buy_select1 WRITE set_shop_buy_select1 NOTIFY shop_buy_select1_changed)
	Q_PROPERTY(QString shop_buy_number1 READ shop_buy_number1 WRITE set_shop_buy_number1 NOTIFY shop_buy_number1_changed)
	Q_PROPERTY(QString shop_purchased1 READ shop_purchased1 WRITE set_shop_purchased1 NOTIFY shop_purchased1_changed)
	Q_PROPERTY(QString shop_sell_select1 READ shop_sell_select1 WRITE set_shop_sell_select1 NOTIFY shop_sell_select1_changed)
	Q_PROPERTY(QString shop_sell_number1 READ shop_sell_number1 WRITE set_shop_sell_number1 NOTIFY shop_sell_number1_changed)
	Q_PROPERTY(QString shop_sold1 READ shop_sold1 WRITE set_shop_sold1 NOTIFY shop_sold1_changed)
	Q_PROPERTY(QString shop_greeting2 READ shop_greeting2 WRITE set_shop_greeting2 NOTIFY shop_greeting2_changed)
	Q_PROPERTY(QString shop_regreeting2 READ shop_regreeting2 WRITE set_shop_regreeting2 NOTIFY shop_regreeting2_changed)
	Q_PROPERTY(QString shop_buy2 READ shop_buy2 WRITE set_shop_buy2 NOTIFY shop_buy2_changed)
	Q_PROPERTY(QString shop_sell2 READ shop_sell2 WRITE set_shop_sell2 NOTIFY shop_sell2_changed)
	Q_PROPERTY(QString shop_leave2 READ shop_leave2 WRITE set_shop_leave2 NOTIFY shop_leave2_changed)
	Q_PROPERTY(QString shop_buy_select2 READ shop_buy_select2 WRITE set_shop_buy_select2 NOTIFY shop_buy_select2_changed)
	Q_PROPERTY(QString shop_buy_number2 READ shop_buy_number2 WRITE set_shop_buy_number2 NOTIFY shop_buy_number2_changed)
	Q_PROPERTY(QString shop_purchased2 READ shop_purchased2 WRITE set_shop_purchased2 NOTIFY shop_purchased2_changed)
	Q_PROPERTY(QString shop_sell_select2 READ shop_sell_select2 WRITE set_shop_sell_select2 NOTIFY shop_sell_select2_changed)
	Q_PROPERTY(QString shop_sell_number2 READ shop_sell_number2 WRITE set_shop_sell_number2 NOTIFY shop_sell_number2_changed)
	Q_PROPERTY(QString shop_sold2 READ shop_sold2 WRITE set_shop_sold2 NOTIFY shop_sold2_changed)
	Q_PROPERTY(QString shop_greeting3 READ shop_greeting3 WRITE set_shop_greeting3 NOTIFY shop_greeting3_changed)
	Q_PROPERTY(QString shop_regreeting3 READ shop_regreeting3 WRITE set_shop_regreeting3 NOTIFY shop_regreeting3_changed)
	Q_PROPERTY(QString shop_buy3 READ shop_buy3 WRITE set_shop_buy3 NOTIFY shop_buy3_changed)
	Q_PROPERTY(QString shop_sell3 READ shop_sell3 WRITE set_shop_sell3 NOTIFY shop_sell3_changed)
	Q_PROPERTY(QString shop_leave3 READ shop_leave3 WRITE set_shop_leave3 NOTIFY shop_leave3_changed)
	Q_PROPERTY(QString shop_buy_select3 READ shop_buy_select3 WRITE set_shop_buy_select3 NOTIFY shop_buy_select3_changed)
	Q_PROPERTY(QString shop_buy_number3 READ shop_buy_number3 WRITE set_shop_buy_number3 NOTIFY shop_buy_number3_changed)
	Q_PROPERTY(QString shop_purchased3 READ shop_purchased3 WRITE set_shop_purchased3 NOTIFY shop_purchased3_changed)
	Q_PROPERTY(QString shop_sell_select3 READ shop_sell_select3 WRITE set_shop_sell_select3 NOTIFY shop_sell_select3_changed)
	Q_PROPERTY(QString shop_sell_number3 READ shop_sell_number3 WRITE set_shop_sell_number3 NOTIFY shop_sell_number3_changed)
	Q_PROPERTY(QString shop_sold3 READ shop_sold3 WRITE set_shop_sold3 NOTIFY shop_sold3_changed)
	Q_PROPERTY(QString inn_a_greeting_1 READ inn_a_greeting_1 WRITE set_inn_a_greeting_1 NOTIFY inn_a_greeting_1_changed)
	Q_PROPERTY(QString inn_a_greeting_2 READ inn_a_greeting_2 WRITE set_inn_a_greeting_2 NOTIFY inn_a_greeting_2_changed)
	Q_PROPERTY(QString inn_a_greeting_3 READ inn_a_greeting_3 WRITE set_inn_a_greeting_3 NOTIFY inn_a_greeting_3_changed)
	Q_PROPERTY(QString inn_a_accept READ inn_a_accept WRITE set_inn_a_accept NOTIFY inn_a_accept_changed)
	Q_PROPERTY(QString inn_a_cancel READ inn_a_cancel WRITE set_inn_a_cancel NOTIFY inn_a_cancel_changed)
	Q_PROPERTY(QString inn_b_greeting_1 READ inn_b_greeting_1 WRITE set_inn_b_greeting_1 NOTIFY inn_b_greeting_1_changed)
	Q_PROPERTY(QString inn_b_greeting_2 READ inn_b_greeting_2 WRITE set_inn_b_greeting_2 NOTIFY inn_b_greeting_2_changed)
	Q_PROPERTY(QString inn_b_greeting_3 READ inn_b_greeting_3 WRITE set_inn_b_greeting_3 NOTIFY inn_b_greeting_3_changed)
	Q_PROPERTY(QString inn_b_accept READ inn_b_accept WRITE set_inn_b_accept NOTIFY inn_b_accept_changed)
	Q_PROPERTY(QString inn_b_cancel READ inn_b_cancel WRITE set_inn_b_cancel NOTIFY inn_b_cancel_changed)
	Q_PROPERTY(QString possessed_items READ possessed_items WRITE set_possessed_items NOTIFY possessed_items_changed)
	Q_PROPERTY(QString equipped_items READ equipped_items WRITE set_equipped_items NOTIFY equipped_items_changed)
	Q_PROPERTY(QString gold READ gold WRITE set_gold NOTIFY gold_changed)
	Q_PROPERTY(QString battle_fight READ battle_fight WRITE set_battle_fight NOTIFY battle_fight_changed)
	Q_PROPERTY(QString battle_auto READ battle_auto WRITE set_battle_auto NOTIFY battle_auto_changed)
	Q_PROPERTY(QString battle_escape READ battle_escape WRITE set_battle_escape NOTIFY battle_escape_changed)
	Q_PROPERTY(QString command_attack READ command_attack WRITE set_command_attack NOTIFY command_attack_changed)
	Q_PROPERTY(QString command_defend READ command_defend WRITE set_command_defend NOTIFY command_defend_changed)
	Q_PROPERTY(QString command_item READ command_item WRITE set_command_item NOTIFY command_item_changed)
	Q_PROPERTY(QString command_skill READ command_skill WRITE set_command_skill NOTIFY command_skill_changed)
	Q_PROPERTY(QString menu_equipment READ menu_equipment WRITE set_menu_equipment NOTIFY menu_equipment_changed)
	Q_PROPERTY(QString menu_save READ menu_save WRITE set_menu_save NOTIFY menu_save_changed)
	Q_PROPERTY(QString menu_quit READ menu_quit WRITE set_menu_quit NOTIFY menu_quit_changed)
	Q_PROPERTY(QString new_game READ new_game WRITE set_new_game NOTIFY new_game_changed)
	Q_PROPERTY(QString load_game READ load_game WRITE set_load_game NOTIFY load_game_changed)
	Q_PROPERTY(QString exit_game READ exit_game WRITE set_exit_game NOTIFY exit_game_changed)
	Q_PROPERTY(QString status READ status WRITE set_status NOTIFY status_changed)
	Q_PROPERTY(QString row READ row WRITE set_row NOTIFY row_changed)
	Q_PROPERTY(QString order READ order WRITE set_order NOTIFY order_changed)
	Q_PROPERTY(QString wait_on READ wait_on WRITE set_wait_on NOTIFY wait_on_changed)
	Q_PROPERTY(QString wait_off READ wait_off WRITE set_wait_off NOTIFY wait_off_changed)
	Q_PROPERTY(QString level READ level WRITE set_level NOTIFY level_changed)
	Q_PROPERTY(QString health_points READ health_points WRITE set_health_points NOTIFY health_points_changed)
	Q_PROPERTY(QString spirit_points READ spirit_points WRITE set_spirit_points NOTIFY spirit_points_changed)
	Q_PROPERTY(QString normal_status READ normal_status WRITE set_normal_status NOTIFY normal_status_changed)
	Q_PROPERTY(QString exp_short READ exp_short WRITE set_exp_short NOTIFY exp_short_changed)
	Q_PROPERTY(QString lvl_short READ lvl_short WRITE set_lvl_short NOTIFY lvl_short_changed)
	Q_PROPERTY(QString hp_short READ hp_short WRITE set_hp_short NOTIFY hp_short_changed)
	Q_PROPERTY(QString sp_short READ sp_short WRITE set_sp_short NOTIFY sp_short_changed)
	Q_PROPERTY(QString sp_cost READ sp_cost WRITE set_sp_cost NOTIFY sp_cost_changed)
	Q_PROPERTY(QString attack READ attack WRITE set_attack NOTIFY attack_changed)
	Q_PROPERTY(QString defense READ defense WRITE set_defense NOTIFY defense_changed)
	Q_PROPERTY(QString spirit READ spirit WRITE set_spirit NOTIFY spirit_changed)
	Q_PROPERTY(QString agility READ agility WRITE set_agility NOTIFY agility_changed)
	Q_PROPERTY(QString weapon READ weapon WRITE set_weapon NOTIFY weapon_changed)
	Q_PROPERTY(QString shield READ shield WRITE set_shield NOTIFY shield_changed)
	Q_PROPERTY(QString armor READ armor WRITE set_armor NOTIFY armor_changed)
	Q_PROPERTY(QString helmet READ helmet WRITE set_helmet NOTIFY helmet_changed)
	Q_PROPERTY(QString accessory READ accessory WRITE set_accessory NOTIFY accessory_changed)
	Q_PROPERTY(QString save_game_message READ save_game_message WRITE set_save_game_message NOTIFY save_game_message_changed)
	Q_PROPERTY(QString load_game_message READ load_game_message WRITE set_load_game_message NOTIFY load_game_message_changed)
	Q_PROPERTY(QString file READ file WRITE set_file NOTIFY file_changed)
	Q_PROPERTY(QString exit_game_message READ exit_game_message WRITE set_exit_game_message NOTIFY exit_game_message_changed)
	Q_PROPERTY(QString yes READ yes WRITE set_yes NOTIFY yes_changed)
	Q_PROPERTY(QString no READ no WRITE set_no NOTIFY no_changed)
	Q_PROPERTY(QString easyrpg_item_number_separator READ easyrpg_item_number_separator WRITE set_easyrpg_item_number_separator NOTIFY easyrpg_item_number_separator_changed)
	Q_PROPERTY(QString easyrpg_skill_cost_separator READ easyrpg_skill_cost_separator WRITE set_easyrpg_skill_cost_separator NOTIFY easyrpg_skill_cost_separator_changed)
	Q_PROPERTY(QString easyrpg_equipment_arrow READ easyrpg_equipment_arrow WRITE set_easyrpg_equipment_arrow NOTIFY easyrpg_equipment_arrow_changed)
	Q_PROPERTY(QString easyrpg_status_scene_name READ easyrpg_status_scene_name WRITE set_easyrpg_status_scene_name NOTIFY easyrpg_status_scene_name_changed)
	Q_PROPERTY(QString easyrpg_status_scene_class READ easyrpg_status_scene_class WRITE set_easyrpg_status_scene_class NOTIFY easyrpg_status_scene_class_changed)
	Q_PROPERTY(QString easyrpg_status_scene_title READ easyrpg_status_scene_title WRITE set_easyrpg_status_scene_title NOTIFY easyrpg_status_scene_title_changed)
	Q_PROPERTY(QString easyrpg_status_scene_condition READ easyrpg_status_scene_condition WRITE set_easyrpg_status_scene_condition NOTIFY easyrpg_status_scene_condition_changed)
	Q_PROPERTY(QString easyrpg_status_scene_front READ easyrpg_status_scene_front WRITE set_easyrpg_status_scene_front NOTIFY easyrpg_status_scene_front_changed)
	Q_PROPERTY(QString easyrpg_status_scene_back READ easyrpg_status_scene_back WRITE set_easyrpg_status_scene_back NOTIFY easyrpg_status_scene_back_changed)
	Q_PROPERTY(QString easyrpg_order_scene_confirm READ easyrpg_order_scene_confirm WRITE set_easyrpg_order_scene_confirm NOTIFY easyrpg_order_scene_confirm_changed)
	Q_PROPERTY(QString easyrpg_order_scene_redo READ easyrpg_order_scene_redo WRITE set_easyrpg_order_scene_redo NOTIFY easyrpg_order_scene_redo_changed)
	Q_PROPERTY(QString easyrpg_battle2k3_double_attack READ easyrpg_battle2k3_double_attack WRITE set_easyrpg_battle2k3_double_attack NOTIFY easyrpg_battle2k3_double_attack_changed)
	Q_PROPERTY(QString easyrpg_battle2k3_defend READ easyrpg_battle2k3_defend WRITE set_easyrpg_battle2k3_defend NOTIFY easyrpg_battle2k3_defend_changed)
	Q_PROPERTY(QString easyrpg_battle2k3_observe READ easyrpg_battle2k3_observe WRITE set_easyrpg_battle2k3_observe NOTIFY easyrpg_battle2k3_observe_changed)
	Q_PROPERTY(QString easyrpg_battle2k3_charge READ easyrpg_battle2k3_charge WRITE set_easyrpg_battle2k3_charge NOTIFY easyrpg_battle2k3_charge_changed)
	Q_PROPERTY(QString easyrpg_battle2k3_selfdestruct READ easyrpg_battle2k3_selfdestruct WRITE set_easyrpg_battle2k3_selfdestruct NOTIFY easyrpg_battle2k3_selfdestruct_changed)
	Q_PROPERTY(QString easyrpg_battle2k3_escape READ easyrpg_battle2k3_escape WRITE set_easyrpg_battle2k3_escape NOTIFY easyrpg_battle2k3_escape_changed)
	Q_PROPERTY(QString easyrpg_battle2k3_special_combat_back READ easyrpg_battle2k3_special_combat_back WRITE set_easyrpg_battle2k3_special_combat_back NOTIFY easyrpg_battle2k3_special_combat_back_changed)
	Q_PROPERTY(QString easyrpg_battle2k3_skill READ easyrpg_battle2k3_skill WRITE set_easyrpg_battle2k3_skill NOTIFY easyrpg_battle2k3_skill_changed)
	Q_PROPERTY(QString easyrpg_battle2k3_item READ easyrpg_battle2k3_item WRITE set_easyrpg_battle2k3_item NOTIFY easyrpg_battle2k3_item_changed)

public:
	Terms(ProjectData& project, lcf::rpg::Terms& data, QObject* parent = nullptr);

	lcf::rpg::Terms& data();
	QString encounter();
	void set_encounter(const QString& new_encounter);
	QString special_combat();
	void set_special_combat(const QString& new_special_combat);
	QString escape_success();
	void set_escape_success(const QString& new_escape_success);
	QString escape_failure();
	void set_escape_failure(const QString& new_escape_failure);
	QString victory();
	void set_victory(const QString& new_victory);
	QString defeat();
	void set_defeat(const QString& new_defeat);
	QString exp_received();
	void set_exp_received(const QString& new_exp_received);
	QString gold_recieved_a();
	void set_gold_recieved_a(const QString& new_gold_recieved_a);
	QString gold_recieved_b();
	void set_gold_recieved_b(const QString& new_gold_recieved_b);
	QString item_recieved();
	void set_item_recieved(const QString& new_item_recieved);
	QString attacking();
	void set_attacking(const QString& new_attacking);
	QString enemy_critical();
	void set_enemy_critical(const QString& new_enemy_critical);
	QString actor_critical();
	void set_actor_critical(const QString& new_actor_critical);
	QString defending();
	void set_defending(const QString& new_defending);
	QString observing();
	void set_observing(const QString& new_observing);
	QString focus();
	void set_focus(const QString& new_focus);
	QString autodestruction();
	void set_autodestruction(const QString& new_autodestruction);
	QString enemy_escape();
	void set_enemy_escape(const QString& new_enemy_escape);
	QString enemy_transform();
	void set_enemy_transform(const QString& new_enemy_transform);
	QString enemy_damaged();
	void set_enemy_damaged(const QString& new_enemy_damaged);
	QString enemy_undamaged();
	void set_enemy_undamaged(const QString& new_enemy_undamaged);
	QString actor_damaged();
	void set_actor_damaged(const QString& new_actor_damaged);
	QString actor_undamaged();
	void set_actor_undamaged(const QString& new_actor_undamaged);
	QString skill_failure_a();
	void set_skill_failure_a(const QString& new_skill_failure_a);
	QString skill_failure_b();
	void set_skill_failure_b(const QString& new_skill_failure_b);
	QString skill_failure_c();
	void set_skill_failure_c(const QString& new_skill_failure_c);
	QString dodge();
	void set_dodge(const QString& new_dodge);
	QString use_item();
	void set_use_item(const QString& new_use_item);
	QString hp_recovery();
	void set_hp_recovery(const QString& new_hp_recovery);
	QString parameter_increase();
	void set_parameter_increase(const QString& new_parameter_increase);
	QString parameter_decrease();
	void set_parameter_decrease(const QString& new_parameter_decrease);
	QString enemy_hp_absorbed();
	void set_enemy_hp_absorbed(const QString& new_enemy_hp_absorbed);
	QString actor_hp_absorbed();
	void set_actor_hp_absorbed(const QString& new_actor_hp_absorbed);
	QString resistance_increase();
	void set_resistance_increase(const QString& new_resistance_increase);
	QString resistance_decrease();
	void set_resistance_decrease(const QString& new_resistance_decrease);
	QString level_up();
	void set_level_up(const QString& new_level_up);
	QString skill_learned();
	void set_skill_learned(const QString& new_skill_learned);
	QString battle_start();
	void set_battle_start(const QString& new_battle_start);
	QString miss();
	void set_miss(const QString& new_miss);
	QString shop_greeting1();
	void set_shop_greeting1(const QString& new_shop_greeting1);
	QString shop_regreeting1();
	void set_shop_regreeting1(const QString& new_shop_regreeting1);
	QString shop_buy1();
	void set_shop_buy1(const QString& new_shop_buy1);
	QString shop_sell1();
	void set_shop_sell1(const QString& new_shop_sell1);
	QString shop_leave1();
	void set_shop_leave1(const QString& new_shop_leave1);
	QString shop_buy_select1();
	void set_shop_buy_select1(const QString& new_shop_buy_select1);
	QString shop_buy_number1();
	void set_shop_buy_number1(const QString& new_shop_buy_number1);
	QString shop_purchased1();
	void set_shop_purchased1(const QString& new_shop_purchased1);
	QString shop_sell_select1();
	void set_shop_sell_select1(const QString& new_shop_sell_select1);
	QString shop_sell_number1();
	void set_shop_sell_number1(const QString& new_shop_sell_number1);
	QString shop_sold1();
	void set_shop_sold1(const QString& new_shop_sold1);
	QString shop_greeting2();
	void set_shop_greeting2(const QString& new_shop_greeting2);
	QString shop_regreeting2();
	void set_shop_regreeting2(const QString& new_shop_regreeting2);
	QString shop_buy2();
	void set_shop_buy2(const QString& new_shop_buy2);
	QString shop_sell2();
	void set_shop_sell2(const QString& new_shop_sell2);
	QString shop_leave2();
	void set_shop_leave2(const QString& new_shop_leave2);
	QString shop_buy_select2();
	void set_shop_buy_select2(const QString& new_shop_buy_select2);
	QString shop_buy_number2();
	void set_shop_buy_number2(const QString& new_shop_buy_number2);
	QString shop_purchased2();
	void set_shop_purchased2(const QString& new_shop_purchased2);
	QString shop_sell_select2();
	void set_shop_sell_select2(const QString& new_shop_sell_select2);
	QString shop_sell_number2();
	void set_shop_sell_number2(const QString& new_shop_sell_number2);
	QString shop_sold2();
	void set_shop_sold2(const QString& new_shop_sold2);
	QString shop_greeting3();
	void set_shop_greeting3(const QString& new_shop_greeting3);
	QString shop_regreeting3();
	void set_shop_regreeting3(const QString& new_shop_regreeting3);
	QString shop_buy3();
	void set_shop_buy3(const QString& new_shop_buy3);
	QString shop_sell3();
	void set_shop_sell3(const QString& new_shop_sell3);
	QString shop_leave3();
	void set_shop_leave3(const QString& new_shop_leave3);
	QString shop_buy_select3();
	void set_shop_buy_select3(const QString& new_shop_buy_select3);
	QString shop_buy_number3();
	void set_shop_buy_number3(const QString& new_shop_buy_number3);
	QString shop_purchased3();
	void set_shop_purchased3(const QString& new_shop_purchased3);
	QString shop_sell_select3();
	void set_shop_sell_select3(const QString& new_shop_sell_select3);
	QString shop_sell_number3();
	void set_shop_sell_number3(const QString& new_shop_sell_number3);
	QString shop_sold3();
	void set_shop_sold3(const QString& new_shop_sold3);
	QString inn_a_greeting_1();
	void set_inn_a_greeting_1(const QString& new_inn_a_greeting_1);
	QString inn_a_greeting_2();
	void set_inn_a_greeting_2(const QString& new_inn_a_greeting_2);
	QString inn_a_greeting_3();
	void set_inn_a_greeting_3(const QString& new_inn_a_greeting_3);
	QString inn_a_accept();
	void set_inn_a_accept(const QString& new_inn_a_accept);
	QString inn_a_cancel();
	void set_inn_a_cancel(const QString& new_inn_a_cancel);
	QString inn_b_greeting_1();
	void set_inn_b_greeting_1(const QString& new_inn_b_greeting_1);
	QString inn_b_greeting_2();
	void set_inn_b_greeting_2(const QString& new_inn_b_greeting_2);
	QString inn_b_greeting_3();
	void set_inn_b_greeting_3(const QString& new_inn_b_greeting_3);
	QString inn_b_accept();
	void set_inn_b_accept(const QString& new_inn_b_accept);
	QString inn_b_cancel();
	void set_inn_b_cancel(const QString& new_inn_b_cancel);
	QString possessed_items();
	void set_possessed_items(const QString& new_possessed_items);
	QString equipped_items();
	void set_equipped_items(const QString& new_equipped_items);
	QString gold();
	void set_gold(const QString& new_gold);
	QString battle_fight();
	void set_battle_fight(const QString& new_battle_fight);
	QString battle_auto();
	void set_battle_auto(const QString& new_battle_auto);
	QString battle_escape();
	void set_battle_escape(const QString& new_battle_escape);
	QString command_attack();
	void set_command_attack(const QString& new_command_attack);
	QString command_defend();
	void set_command_defend(const QString& new_command_defend);
	QString command_item();
	void set_command_item(const QString& new_command_item);
	QString command_skill();
	void set_command_skill(const QString& new_command_skill);
	QString menu_equipment();
	void set_menu_equipment(const QString& new_menu_equipment);
	QString menu_save();
	void set_menu_save(const QString& new_menu_save);
	QString menu_quit();
	void set_menu_quit(const QString& new_menu_quit);
	QString new_game();
	void set_new_game(const QString& new_new_game);
	QString load_game();
	void set_load_game(const QString& new_load_game);
	QString exit_game();
	void set_exit_game(const QString& new_exit_game);
	QString status();
	void set_status(const QString& new_status);
	QString row();
	void set_row(const QString& new_row);
	QString order();
	void set_order(const QString& new_order);
	QString wait_on();
	void set_wait_on(const QString& new_wait_on);
	QString wait_off();
	void set_wait_off(const QString& new_wait_off);
	QString level();
	void set_level(const QString& new_level);
	QString health_points();
	void set_health_points(const QString& new_health_points);
	QString spirit_points();
	void set_spirit_points(const QString& new_spirit_points);
	QString normal_status();
	void set_normal_status(const QString& new_normal_status);
	QString exp_short();
	void set_exp_short(const QString& new_exp_short);
	QString lvl_short();
	void set_lvl_short(const QString& new_lvl_short);
	QString hp_short();
	void set_hp_short(const QString& new_hp_short);
	QString sp_short();
	void set_sp_short(const QString& new_sp_short);
	QString sp_cost();
	void set_sp_cost(const QString& new_sp_cost);
	QString attack();
	void set_attack(const QString& new_attack);
	QString defense();
	void set_defense(const QString& new_defense);
	QString spirit();
	void set_spirit(const QString& new_spirit);
	QString agility();
	void set_agility(const QString& new_agility);
	QString weapon();
	void set_weapon(const QString& new_weapon);
	QString shield();
	void set_shield(const QString& new_shield);
	QString armor();
	void set_armor(const QString& new_armor);
	QString helmet();
	void set_helmet(const QString& new_helmet);
	QString accessory();
	void set_accessory(const QString& new_accessory);
	QString save_game_message();
	void set_save_game_message(const QString& new_save_game_message);
	QString load_game_message();
	void set_load_game_message(const QString& new_load_game_message);
	QString file();
	void set_file(const QString& new_file);
	QString exit_game_message();
	void set_exit_game_message(const QString& new_exit_game_message);
	QString yes();
	void set_yes(const QString& new_yes);
	QString no();
	void set_no(const QString& new_no);
	QString easyrpg_item_number_separator();
	void set_easyrpg_item_number_separator(const QString& new_easyrpg_item_number_separator);
	QString easyrpg_skill_cost_separator();
	void set_easyrpg_skill_cost_separator(const QString& new_easyrpg_skill_cost_separator);
	QString easyrpg_equipment_arrow();
	void set_easyrpg_equipment_arrow(const QString& new_easyrpg_equipment_arrow);
	QString easyrpg_status_scene_name();
	void set_easyrpg_status_scene_name(const QString& new_easyrpg_status_scene_name);
	QString easyrpg_status_scene_class();
	void set_easyrpg_status_scene_class(const QString& new_easyrpg_status_scene_class);
	QString easyrpg_status_scene_title();
	void set_easyrpg_status_scene_title(const QString& new_easyrpg_status_scene_title);
	QString easyrpg_status_scene_condition();
	void set_easyrpg_status_scene_condition(const QString& new_easyrpg_status_scene_condition);
	QString easyrpg_status_scene_front();
	void set_easyrpg_status_scene_front(const QString& new_easyrpg_status_scene_front);
	QString easyrpg_status_scene_back();
	void set_easyrpg_status_scene_back(const QString& new_easyrpg_status_scene_back);
	QString easyrpg_order_scene_confirm();
	void set_easyrpg_order_scene_confirm(const QString& new_easyrpg_order_scene_confirm);
	QString easyrpg_order_scene_redo();
	void set_easyrpg_order_scene_redo(const QString& new_easyrpg_order_scene_redo);
	QString easyrpg_battle2k3_double_attack();
	void set_easyrpg_battle2k3_double_attack(const QString& new_easyrpg_battle2k3_double_attack);
	QString easyrpg_battle2k3_defend();
	void set_easyrpg_battle2k3_defend(const QString& new_easyrpg_battle2k3_defend);
	QString easyrpg_battle2k3_observe();
	void set_easyrpg_battle2k3_observe(const QString& new_easyrpg_battle2k3_observe);
	QString easyrpg_battle2k3_charge();
	void set_easyrpg_battle2k3_charge(const QString& new_easyrpg_battle2k3_charge);
	QString easyrpg_battle2k3_selfdestruct();
	void set_easyrpg_battle2k3_selfdestruct(const QString& new_easyrpg_battle2k3_selfdestruct);
	QString easyrpg_battle2k3_escape();
	void set_easyrpg_battle2k3_escape(const QString& new_easyrpg_battle2k3_escape);
	QString easyrpg_battle2k3_special_combat_back();
	void set_easyrpg_battle2k3_special_combat_back(const QString& new_easyrpg_battle2k3_special_combat_back);
	QString easyrpg_battle2k3_skill();
	void set_easyrpg_battle2k3_skill(const QString& new_easyrpg_battle2k3_skill);
	QString easyrpg_battle2k3_item();
	void set_easyrpg_battle2k3_item(const QString& new_easyrpg_battle2k3_item);

signals:
	void encounter_changed();
	void special_combat_changed();
	void escape_success_changed();
	void escape_failure_changed();
	void victory_changed();
	void defeat_changed();
	void exp_received_changed();
	void gold_recieved_a_changed();
	void gold_recieved_b_changed();
	void item_recieved_changed();
	void attacking_changed();
	void enemy_critical_changed();
	void actor_critical_changed();
	void defending_changed();
	void observing_changed();
	void focus_changed();
	void autodestruction_changed();
	void enemy_escape_changed();
	void enemy_transform_changed();
	void enemy_damaged_changed();
	void enemy_undamaged_changed();
	void actor_damaged_changed();
	void actor_undamaged_changed();
	void skill_failure_a_changed();
	void skill_failure_b_changed();
	void skill_failure_c_changed();
	void dodge_changed();
	void use_item_changed();
	void hp_recovery_changed();
	void parameter_increase_changed();
	void parameter_decrease_changed();
	void enemy_hp_absorbed_changed();
	void actor_hp_absorbed_changed();
	void resistance_increase_changed();
	void resistance_decrease_changed();
	void level_up_changed();
	void skill_learned_changed();
	void battle_start_changed();
	void miss_changed();
	void shop_greeting1_changed();
	void shop_regreeting1_changed();
	void shop_buy1_changed();
	void shop_sell1_changed();
	void shop_leave1_changed();
	void shop_buy_select1_changed();
	void shop_buy_number1_changed();
	void shop_purchased1_changed();
	void shop_sell_select1_changed();
	void shop_sell_number1_changed();
	void shop_sold1_changed();
	void shop_greeting2_changed();
	void shop_regreeting2_changed();
	void shop_buy2_changed();
	void shop_sell2_changed();
	void shop_leave2_changed();
	void shop_buy_select2_changed();
	void shop_buy_number2_changed();
	void shop_purchased2_changed();
	void shop_sell_select2_changed();
	void shop_sell_number2_changed();
	void shop_sold2_changed();
	void shop_greeting3_changed();
	void shop_regreeting3_changed();
	void shop_buy3_changed();
	void shop_sell3_changed();
	void shop_leave3_changed();
	void shop_buy_select3_changed();
	void shop_buy_number3_changed();
	void shop_purchased3_changed();
	void shop_sell_select3_changed();
	void shop_sell_number3_changed();
	void shop_sold3_changed();
	void inn_a_greeting_1_changed();
	void inn_a_greeting_2_changed();
	void inn_a_greeting_3_changed();
	void inn_a_accept_changed();
	void inn_a_cancel_changed();
	void inn_b_greeting_1_changed();
	void inn_b_greeting_2_changed();
	void inn_b_greeting_3_changed();
	void inn_b_accept_changed();
	void inn_b_cancel_changed();
	void possessed_items_changed();
	void equipped_items_changed();
	void gold_changed();
	void battle_fight_changed();
	void battle_auto_changed();
	void battle_escape_changed();
	void command_attack_changed();
	void command_defend_changed();
	void command_item_changed();
	void command_skill_changed();
	void menu_equipment_changed();
	void menu_save_changed();
	void menu_quit_changed();
	void new_game_changed();
	void load_game_changed();
	void exit_game_changed();
	void status_changed();
	void row_changed();
	void order_changed();
	void wait_on_changed();
	void wait_off_changed();
	void level_changed();
	void health_points_changed();
	void spirit_points_changed();
	void normal_status_changed();
	void exp_short_changed();
	void lvl_short_changed();
	void hp_short_changed();
	void sp_short_changed();
	void sp_cost_changed();
	void attack_changed();
	void defense_changed();
	void spirit_changed();
	void agility_changed();
	void weapon_changed();
	void shield_changed();
	void armor_changed();
	void helmet_changed();
	void accessory_changed();
	void save_game_message_changed();
	void load_game_message_changed();
	void file_changed();
	void exit_game_message_changed();
	void yes_changed();
	void no_changed();
	void easyrpg_item_number_separator_changed();
	void easyrpg_skill_cost_separator_changed();
	void easyrpg_equipment_arrow_changed();
	void easyrpg_status_scene_name_changed();
	void easyrpg_status_scene_class_changed();
	void easyrpg_status_scene_title_changed();
	void easyrpg_status_scene_condition_changed();
	void easyrpg_status_scene_front_changed();
	void easyrpg_status_scene_back_changed();
	void easyrpg_order_scene_confirm_changed();
	void easyrpg_order_scene_redo_changed();
	void easyrpg_battle2k3_double_attack_changed();
	void easyrpg_battle2k3_defend_changed();
	void easyrpg_battle2k3_observe_changed();
	void easyrpg_battle2k3_charge_changed();
	void easyrpg_battle2k3_selfdestruct_changed();
	void easyrpg_battle2k3_escape_changed();
	void easyrpg_battle2k3_special_combat_back_changed();
	void easyrpg_battle2k3_skill_changed();
	void easyrpg_battle2k3_item_changed();

protected:
	lcf::rpg::Terms& m_data;
};
} // namespace Binding::Generated
