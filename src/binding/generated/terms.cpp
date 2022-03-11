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

// Headers
#include "terms.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Terms::Terms(ProjectData& project, lcf::rpg::Terms& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	QString Terms::encounter() {
		return ToQString(m_data.encounter);
	}
	void Terms::set_encounter(const QString& new_encounter) {
		if (ToQString(m_data.encounter) == new_encounter)
			return;
		m_data.encounter = ToDBString(new_encounter);
		emit encounter_changed();
	}

	QString Terms::special_combat() {
		return ToQString(m_data.special_combat);
	}
	void Terms::set_special_combat(const QString& new_special_combat) {
		if (ToQString(m_data.special_combat) == new_special_combat)
			return;
		m_data.special_combat = ToDBString(new_special_combat);
		emit special_combat_changed();
	}

	QString Terms::escape_success() {
		return ToQString(m_data.escape_success);
	}
	void Terms::set_escape_success(const QString& new_escape_success) {
		if (ToQString(m_data.escape_success) == new_escape_success)
			return;
		m_data.escape_success = ToDBString(new_escape_success);
		emit escape_success_changed();
	}

	QString Terms::escape_failure() {
		return ToQString(m_data.escape_failure);
	}
	void Terms::set_escape_failure(const QString& new_escape_failure) {
		if (ToQString(m_data.escape_failure) == new_escape_failure)
			return;
		m_data.escape_failure = ToDBString(new_escape_failure);
		emit escape_failure_changed();
	}

	QString Terms::victory() {
		return ToQString(m_data.victory);
	}
	void Terms::set_victory(const QString& new_victory) {
		if (ToQString(m_data.victory) == new_victory)
			return;
		m_data.victory = ToDBString(new_victory);
		emit victory_changed();
	}

	QString Terms::defeat() {
		return ToQString(m_data.defeat);
	}
	void Terms::set_defeat(const QString& new_defeat) {
		if (ToQString(m_data.defeat) == new_defeat)
			return;
		m_data.defeat = ToDBString(new_defeat);
		emit defeat_changed();
	}

	QString Terms::exp_received() {
		return ToQString(m_data.exp_received);
	}
	void Terms::set_exp_received(const QString& new_exp_received) {
		if (ToQString(m_data.exp_received) == new_exp_received)
			return;
		m_data.exp_received = ToDBString(new_exp_received);
		emit exp_received_changed();
	}

	QString Terms::gold_recieved_a() {
		return ToQString(m_data.gold_recieved_a);
	}
	void Terms::set_gold_recieved_a(const QString& new_gold_recieved_a) {
		if (ToQString(m_data.gold_recieved_a) == new_gold_recieved_a)
			return;
		m_data.gold_recieved_a = ToDBString(new_gold_recieved_a);
		emit gold_recieved_a_changed();
	}

	QString Terms::gold_recieved_b() {
		return ToQString(m_data.gold_recieved_b);
	}
	void Terms::set_gold_recieved_b(const QString& new_gold_recieved_b) {
		if (ToQString(m_data.gold_recieved_b) == new_gold_recieved_b)
			return;
		m_data.gold_recieved_b = ToDBString(new_gold_recieved_b);
		emit gold_recieved_b_changed();
	}

	QString Terms::item_recieved() {
		return ToQString(m_data.item_recieved);
	}
	void Terms::set_item_recieved(const QString& new_item_recieved) {
		if (ToQString(m_data.item_recieved) == new_item_recieved)
			return;
		m_data.item_recieved = ToDBString(new_item_recieved);
		emit item_recieved_changed();
	}

	QString Terms::attacking() {
		return ToQString(m_data.attacking);
	}
	void Terms::set_attacking(const QString& new_attacking) {
		if (ToQString(m_data.attacking) == new_attacking)
			return;
		m_data.attacking = ToDBString(new_attacking);
		emit attacking_changed();
	}

	QString Terms::enemy_critical() {
		return ToQString(m_data.enemy_critical);
	}
	void Terms::set_enemy_critical(const QString& new_enemy_critical) {
		if (ToQString(m_data.enemy_critical) == new_enemy_critical)
			return;
		m_data.enemy_critical = ToDBString(new_enemy_critical);
		emit enemy_critical_changed();
	}

	QString Terms::actor_critical() {
		return ToQString(m_data.actor_critical);
	}
	void Terms::set_actor_critical(const QString& new_actor_critical) {
		if (ToQString(m_data.actor_critical) == new_actor_critical)
			return;
		m_data.actor_critical = ToDBString(new_actor_critical);
		emit actor_critical_changed();
	}

	QString Terms::defending() {
		return ToQString(m_data.defending);
	}
	void Terms::set_defending(const QString& new_defending) {
		if (ToQString(m_data.defending) == new_defending)
			return;
		m_data.defending = ToDBString(new_defending);
		emit defending_changed();
	}

	QString Terms::observing() {
		return ToQString(m_data.observing);
	}
	void Terms::set_observing(const QString& new_observing) {
		if (ToQString(m_data.observing) == new_observing)
			return;
		m_data.observing = ToDBString(new_observing);
		emit observing_changed();
	}

	QString Terms::focus() {
		return ToQString(m_data.focus);
	}
	void Terms::set_focus(const QString& new_focus) {
		if (ToQString(m_data.focus) == new_focus)
			return;
		m_data.focus = ToDBString(new_focus);
		emit focus_changed();
	}

	QString Terms::autodestruction() {
		return ToQString(m_data.autodestruction);
	}
	void Terms::set_autodestruction(const QString& new_autodestruction) {
		if (ToQString(m_data.autodestruction) == new_autodestruction)
			return;
		m_data.autodestruction = ToDBString(new_autodestruction);
		emit autodestruction_changed();
	}

	QString Terms::enemy_escape() {
		return ToQString(m_data.enemy_escape);
	}
	void Terms::set_enemy_escape(const QString& new_enemy_escape) {
		if (ToQString(m_data.enemy_escape) == new_enemy_escape)
			return;
		m_data.enemy_escape = ToDBString(new_enemy_escape);
		emit enemy_escape_changed();
	}

	QString Terms::enemy_transform() {
		return ToQString(m_data.enemy_transform);
	}
	void Terms::set_enemy_transform(const QString& new_enemy_transform) {
		if (ToQString(m_data.enemy_transform) == new_enemy_transform)
			return;
		m_data.enemy_transform = ToDBString(new_enemy_transform);
		emit enemy_transform_changed();
	}

	QString Terms::enemy_damaged() {
		return ToQString(m_data.enemy_damaged);
	}
	void Terms::set_enemy_damaged(const QString& new_enemy_damaged) {
		if (ToQString(m_data.enemy_damaged) == new_enemy_damaged)
			return;
		m_data.enemy_damaged = ToDBString(new_enemy_damaged);
		emit enemy_damaged_changed();
	}

	QString Terms::enemy_undamaged() {
		return ToQString(m_data.enemy_undamaged);
	}
	void Terms::set_enemy_undamaged(const QString& new_enemy_undamaged) {
		if (ToQString(m_data.enemy_undamaged) == new_enemy_undamaged)
			return;
		m_data.enemy_undamaged = ToDBString(new_enemy_undamaged);
		emit enemy_undamaged_changed();
	}

	QString Terms::actor_damaged() {
		return ToQString(m_data.actor_damaged);
	}
	void Terms::set_actor_damaged(const QString& new_actor_damaged) {
		if (ToQString(m_data.actor_damaged) == new_actor_damaged)
			return;
		m_data.actor_damaged = ToDBString(new_actor_damaged);
		emit actor_damaged_changed();
	}

	QString Terms::actor_undamaged() {
		return ToQString(m_data.actor_undamaged);
	}
	void Terms::set_actor_undamaged(const QString& new_actor_undamaged) {
		if (ToQString(m_data.actor_undamaged) == new_actor_undamaged)
			return;
		m_data.actor_undamaged = ToDBString(new_actor_undamaged);
		emit actor_undamaged_changed();
	}

	QString Terms::skill_failure_a() {
		return ToQString(m_data.skill_failure_a);
	}
	void Terms::set_skill_failure_a(const QString& new_skill_failure_a) {
		if (ToQString(m_data.skill_failure_a) == new_skill_failure_a)
			return;
		m_data.skill_failure_a = ToDBString(new_skill_failure_a);
		emit skill_failure_a_changed();
	}

	QString Terms::skill_failure_b() {
		return ToQString(m_data.skill_failure_b);
	}
	void Terms::set_skill_failure_b(const QString& new_skill_failure_b) {
		if (ToQString(m_data.skill_failure_b) == new_skill_failure_b)
			return;
		m_data.skill_failure_b = ToDBString(new_skill_failure_b);
		emit skill_failure_b_changed();
	}

	QString Terms::skill_failure_c() {
		return ToQString(m_data.skill_failure_c);
	}
	void Terms::set_skill_failure_c(const QString& new_skill_failure_c) {
		if (ToQString(m_data.skill_failure_c) == new_skill_failure_c)
			return;
		m_data.skill_failure_c = ToDBString(new_skill_failure_c);
		emit skill_failure_c_changed();
	}

	QString Terms::dodge() {
		return ToQString(m_data.dodge);
	}
	void Terms::set_dodge(const QString& new_dodge) {
		if (ToQString(m_data.dodge) == new_dodge)
			return;
		m_data.dodge = ToDBString(new_dodge);
		emit dodge_changed();
	}

	QString Terms::use_item() {
		return ToQString(m_data.use_item);
	}
	void Terms::set_use_item(const QString& new_use_item) {
		if (ToQString(m_data.use_item) == new_use_item)
			return;
		m_data.use_item = ToDBString(new_use_item);
		emit use_item_changed();
	}

	QString Terms::hp_recovery() {
		return ToQString(m_data.hp_recovery);
	}
	void Terms::set_hp_recovery(const QString& new_hp_recovery) {
		if (ToQString(m_data.hp_recovery) == new_hp_recovery)
			return;
		m_data.hp_recovery = ToDBString(new_hp_recovery);
		emit hp_recovery_changed();
	}

	QString Terms::parameter_increase() {
		return ToQString(m_data.parameter_increase);
	}
	void Terms::set_parameter_increase(const QString& new_parameter_increase) {
		if (ToQString(m_data.parameter_increase) == new_parameter_increase)
			return;
		m_data.parameter_increase = ToDBString(new_parameter_increase);
		emit parameter_increase_changed();
	}

	QString Terms::parameter_decrease() {
		return ToQString(m_data.parameter_decrease);
	}
	void Terms::set_parameter_decrease(const QString& new_parameter_decrease) {
		if (ToQString(m_data.parameter_decrease) == new_parameter_decrease)
			return;
		m_data.parameter_decrease = ToDBString(new_parameter_decrease);
		emit parameter_decrease_changed();
	}

	QString Terms::enemy_hp_absorbed() {
		return ToQString(m_data.enemy_hp_absorbed);
	}
	void Terms::set_enemy_hp_absorbed(const QString& new_enemy_hp_absorbed) {
		if (ToQString(m_data.enemy_hp_absorbed) == new_enemy_hp_absorbed)
			return;
		m_data.enemy_hp_absorbed = ToDBString(new_enemy_hp_absorbed);
		emit enemy_hp_absorbed_changed();
	}

	QString Terms::actor_hp_absorbed() {
		return ToQString(m_data.actor_hp_absorbed);
	}
	void Terms::set_actor_hp_absorbed(const QString& new_actor_hp_absorbed) {
		if (ToQString(m_data.actor_hp_absorbed) == new_actor_hp_absorbed)
			return;
		m_data.actor_hp_absorbed = ToDBString(new_actor_hp_absorbed);
		emit actor_hp_absorbed_changed();
	}

	QString Terms::resistance_increase() {
		return ToQString(m_data.resistance_increase);
	}
	void Terms::set_resistance_increase(const QString& new_resistance_increase) {
		if (ToQString(m_data.resistance_increase) == new_resistance_increase)
			return;
		m_data.resistance_increase = ToDBString(new_resistance_increase);
		emit resistance_increase_changed();
	}

	QString Terms::resistance_decrease() {
		return ToQString(m_data.resistance_decrease);
	}
	void Terms::set_resistance_decrease(const QString& new_resistance_decrease) {
		if (ToQString(m_data.resistance_decrease) == new_resistance_decrease)
			return;
		m_data.resistance_decrease = ToDBString(new_resistance_decrease);
		emit resistance_decrease_changed();
	}

	QString Terms::level_up() {
		return ToQString(m_data.level_up);
	}
	void Terms::set_level_up(const QString& new_level_up) {
		if (ToQString(m_data.level_up) == new_level_up)
			return;
		m_data.level_up = ToDBString(new_level_up);
		emit level_up_changed();
	}

	QString Terms::skill_learned() {
		return ToQString(m_data.skill_learned);
	}
	void Terms::set_skill_learned(const QString& new_skill_learned) {
		if (ToQString(m_data.skill_learned) == new_skill_learned)
			return;
		m_data.skill_learned = ToDBString(new_skill_learned);
		emit skill_learned_changed();
	}

	QString Terms::battle_start() {
		return ToQString(m_data.battle_start);
	}
	void Terms::set_battle_start(const QString& new_battle_start) {
		if (ToQString(m_data.battle_start) == new_battle_start)
			return;
		m_data.battle_start = ToDBString(new_battle_start);
		emit battle_start_changed();
	}

	QString Terms::miss() {
		return ToQString(m_data.miss);
	}
	void Terms::set_miss(const QString& new_miss) {
		if (ToQString(m_data.miss) == new_miss)
			return;
		m_data.miss = ToDBString(new_miss);
		emit miss_changed();
	}

	QString Terms::shop_greeting1() {
		return ToQString(m_data.shop_greeting1);
	}
	void Terms::set_shop_greeting1(const QString& new_shop_greeting1) {
		if (ToQString(m_data.shop_greeting1) == new_shop_greeting1)
			return;
		m_data.shop_greeting1 = ToDBString(new_shop_greeting1);
		emit shop_greeting1_changed();
	}

	QString Terms::shop_regreeting1() {
		return ToQString(m_data.shop_regreeting1);
	}
	void Terms::set_shop_regreeting1(const QString& new_shop_regreeting1) {
		if (ToQString(m_data.shop_regreeting1) == new_shop_regreeting1)
			return;
		m_data.shop_regreeting1 = ToDBString(new_shop_regreeting1);
		emit shop_regreeting1_changed();
	}

	QString Terms::shop_buy1() {
		return ToQString(m_data.shop_buy1);
	}
	void Terms::set_shop_buy1(const QString& new_shop_buy1) {
		if (ToQString(m_data.shop_buy1) == new_shop_buy1)
			return;
		m_data.shop_buy1 = ToDBString(new_shop_buy1);
		emit shop_buy1_changed();
	}

	QString Terms::shop_sell1() {
		return ToQString(m_data.shop_sell1);
	}
	void Terms::set_shop_sell1(const QString& new_shop_sell1) {
		if (ToQString(m_data.shop_sell1) == new_shop_sell1)
			return;
		m_data.shop_sell1 = ToDBString(new_shop_sell1);
		emit shop_sell1_changed();
	}

	QString Terms::shop_leave1() {
		return ToQString(m_data.shop_leave1);
	}
	void Terms::set_shop_leave1(const QString& new_shop_leave1) {
		if (ToQString(m_data.shop_leave1) == new_shop_leave1)
			return;
		m_data.shop_leave1 = ToDBString(new_shop_leave1);
		emit shop_leave1_changed();
	}

	QString Terms::shop_buy_select1() {
		return ToQString(m_data.shop_buy_select1);
	}
	void Terms::set_shop_buy_select1(const QString& new_shop_buy_select1) {
		if (ToQString(m_data.shop_buy_select1) == new_shop_buy_select1)
			return;
		m_data.shop_buy_select1 = ToDBString(new_shop_buy_select1);
		emit shop_buy_select1_changed();
	}

	QString Terms::shop_buy_number1() {
		return ToQString(m_data.shop_buy_number1);
	}
	void Terms::set_shop_buy_number1(const QString& new_shop_buy_number1) {
		if (ToQString(m_data.shop_buy_number1) == new_shop_buy_number1)
			return;
		m_data.shop_buy_number1 = ToDBString(new_shop_buy_number1);
		emit shop_buy_number1_changed();
	}

	QString Terms::shop_purchased1() {
		return ToQString(m_data.shop_purchased1);
	}
	void Terms::set_shop_purchased1(const QString& new_shop_purchased1) {
		if (ToQString(m_data.shop_purchased1) == new_shop_purchased1)
			return;
		m_data.shop_purchased1 = ToDBString(new_shop_purchased1);
		emit shop_purchased1_changed();
	}

	QString Terms::shop_sell_select1() {
		return ToQString(m_data.shop_sell_select1);
	}
	void Terms::set_shop_sell_select1(const QString& new_shop_sell_select1) {
		if (ToQString(m_data.shop_sell_select1) == new_shop_sell_select1)
			return;
		m_data.shop_sell_select1 = ToDBString(new_shop_sell_select1);
		emit shop_sell_select1_changed();
	}

	QString Terms::shop_sell_number1() {
		return ToQString(m_data.shop_sell_number1);
	}
	void Terms::set_shop_sell_number1(const QString& new_shop_sell_number1) {
		if (ToQString(m_data.shop_sell_number1) == new_shop_sell_number1)
			return;
		m_data.shop_sell_number1 = ToDBString(new_shop_sell_number1);
		emit shop_sell_number1_changed();
	}

	QString Terms::shop_sold1() {
		return ToQString(m_data.shop_sold1);
	}
	void Terms::set_shop_sold1(const QString& new_shop_sold1) {
		if (ToQString(m_data.shop_sold1) == new_shop_sold1)
			return;
		m_data.shop_sold1 = ToDBString(new_shop_sold1);
		emit shop_sold1_changed();
	}

	QString Terms::shop_greeting2() {
		return ToQString(m_data.shop_greeting2);
	}
	void Terms::set_shop_greeting2(const QString& new_shop_greeting2) {
		if (ToQString(m_data.shop_greeting2) == new_shop_greeting2)
			return;
		m_data.shop_greeting2 = ToDBString(new_shop_greeting2);
		emit shop_greeting2_changed();
	}

	QString Terms::shop_regreeting2() {
		return ToQString(m_data.shop_regreeting2);
	}
	void Terms::set_shop_regreeting2(const QString& new_shop_regreeting2) {
		if (ToQString(m_data.shop_regreeting2) == new_shop_regreeting2)
			return;
		m_data.shop_regreeting2 = ToDBString(new_shop_regreeting2);
		emit shop_regreeting2_changed();
	}

	QString Terms::shop_buy2() {
		return ToQString(m_data.shop_buy2);
	}
	void Terms::set_shop_buy2(const QString& new_shop_buy2) {
		if (ToQString(m_data.shop_buy2) == new_shop_buy2)
			return;
		m_data.shop_buy2 = ToDBString(new_shop_buy2);
		emit shop_buy2_changed();
	}

	QString Terms::shop_sell2() {
		return ToQString(m_data.shop_sell2);
	}
	void Terms::set_shop_sell2(const QString& new_shop_sell2) {
		if (ToQString(m_data.shop_sell2) == new_shop_sell2)
			return;
		m_data.shop_sell2 = ToDBString(new_shop_sell2);
		emit shop_sell2_changed();
	}

	QString Terms::shop_leave2() {
		return ToQString(m_data.shop_leave2);
	}
	void Terms::set_shop_leave2(const QString& new_shop_leave2) {
		if (ToQString(m_data.shop_leave2) == new_shop_leave2)
			return;
		m_data.shop_leave2 = ToDBString(new_shop_leave2);
		emit shop_leave2_changed();
	}

	QString Terms::shop_buy_select2() {
		return ToQString(m_data.shop_buy_select2);
	}
	void Terms::set_shop_buy_select2(const QString& new_shop_buy_select2) {
		if (ToQString(m_data.shop_buy_select2) == new_shop_buy_select2)
			return;
		m_data.shop_buy_select2 = ToDBString(new_shop_buy_select2);
		emit shop_buy_select2_changed();
	}

	QString Terms::shop_buy_number2() {
		return ToQString(m_data.shop_buy_number2);
	}
	void Terms::set_shop_buy_number2(const QString& new_shop_buy_number2) {
		if (ToQString(m_data.shop_buy_number2) == new_shop_buy_number2)
			return;
		m_data.shop_buy_number2 = ToDBString(new_shop_buy_number2);
		emit shop_buy_number2_changed();
	}

	QString Terms::shop_purchased2() {
		return ToQString(m_data.shop_purchased2);
	}
	void Terms::set_shop_purchased2(const QString& new_shop_purchased2) {
		if (ToQString(m_data.shop_purchased2) == new_shop_purchased2)
			return;
		m_data.shop_purchased2 = ToDBString(new_shop_purchased2);
		emit shop_purchased2_changed();
	}

	QString Terms::shop_sell_select2() {
		return ToQString(m_data.shop_sell_select2);
	}
	void Terms::set_shop_sell_select2(const QString& new_shop_sell_select2) {
		if (ToQString(m_data.shop_sell_select2) == new_shop_sell_select2)
			return;
		m_data.shop_sell_select2 = ToDBString(new_shop_sell_select2);
		emit shop_sell_select2_changed();
	}

	QString Terms::shop_sell_number2() {
		return ToQString(m_data.shop_sell_number2);
	}
	void Terms::set_shop_sell_number2(const QString& new_shop_sell_number2) {
		if (ToQString(m_data.shop_sell_number2) == new_shop_sell_number2)
			return;
		m_data.shop_sell_number2 = ToDBString(new_shop_sell_number2);
		emit shop_sell_number2_changed();
	}

	QString Terms::shop_sold2() {
		return ToQString(m_data.shop_sold2);
	}
	void Terms::set_shop_sold2(const QString& new_shop_sold2) {
		if (ToQString(m_data.shop_sold2) == new_shop_sold2)
			return;
		m_data.shop_sold2 = ToDBString(new_shop_sold2);
		emit shop_sold2_changed();
	}

	QString Terms::shop_greeting3() {
		return ToQString(m_data.shop_greeting3);
	}
	void Terms::set_shop_greeting3(const QString& new_shop_greeting3) {
		if (ToQString(m_data.shop_greeting3) == new_shop_greeting3)
			return;
		m_data.shop_greeting3 = ToDBString(new_shop_greeting3);
		emit shop_greeting3_changed();
	}

	QString Terms::shop_regreeting3() {
		return ToQString(m_data.shop_regreeting3);
	}
	void Terms::set_shop_regreeting3(const QString& new_shop_regreeting3) {
		if (ToQString(m_data.shop_regreeting3) == new_shop_regreeting3)
			return;
		m_data.shop_regreeting3 = ToDBString(new_shop_regreeting3);
		emit shop_regreeting3_changed();
	}

	QString Terms::shop_buy3() {
		return ToQString(m_data.shop_buy3);
	}
	void Terms::set_shop_buy3(const QString& new_shop_buy3) {
		if (ToQString(m_data.shop_buy3) == new_shop_buy3)
			return;
		m_data.shop_buy3 = ToDBString(new_shop_buy3);
		emit shop_buy3_changed();
	}

	QString Terms::shop_sell3() {
		return ToQString(m_data.shop_sell3);
	}
	void Terms::set_shop_sell3(const QString& new_shop_sell3) {
		if (ToQString(m_data.shop_sell3) == new_shop_sell3)
			return;
		m_data.shop_sell3 = ToDBString(new_shop_sell3);
		emit shop_sell3_changed();
	}

	QString Terms::shop_leave3() {
		return ToQString(m_data.shop_leave3);
	}
	void Terms::set_shop_leave3(const QString& new_shop_leave3) {
		if (ToQString(m_data.shop_leave3) == new_shop_leave3)
			return;
		m_data.shop_leave3 = ToDBString(new_shop_leave3);
		emit shop_leave3_changed();
	}

	QString Terms::shop_buy_select3() {
		return ToQString(m_data.shop_buy_select3);
	}
	void Terms::set_shop_buy_select3(const QString& new_shop_buy_select3) {
		if (ToQString(m_data.shop_buy_select3) == new_shop_buy_select3)
			return;
		m_data.shop_buy_select3 = ToDBString(new_shop_buy_select3);
		emit shop_buy_select3_changed();
	}

	QString Terms::shop_buy_number3() {
		return ToQString(m_data.shop_buy_number3);
	}
	void Terms::set_shop_buy_number3(const QString& new_shop_buy_number3) {
		if (ToQString(m_data.shop_buy_number3) == new_shop_buy_number3)
			return;
		m_data.shop_buy_number3 = ToDBString(new_shop_buy_number3);
		emit shop_buy_number3_changed();
	}

	QString Terms::shop_purchased3() {
		return ToQString(m_data.shop_purchased3);
	}
	void Terms::set_shop_purchased3(const QString& new_shop_purchased3) {
		if (ToQString(m_data.shop_purchased3) == new_shop_purchased3)
			return;
		m_data.shop_purchased3 = ToDBString(new_shop_purchased3);
		emit shop_purchased3_changed();
	}

	QString Terms::shop_sell_select3() {
		return ToQString(m_data.shop_sell_select3);
	}
	void Terms::set_shop_sell_select3(const QString& new_shop_sell_select3) {
		if (ToQString(m_data.shop_sell_select3) == new_shop_sell_select3)
			return;
		m_data.shop_sell_select3 = ToDBString(new_shop_sell_select3);
		emit shop_sell_select3_changed();
	}

	QString Terms::shop_sell_number3() {
		return ToQString(m_data.shop_sell_number3);
	}
	void Terms::set_shop_sell_number3(const QString& new_shop_sell_number3) {
		if (ToQString(m_data.shop_sell_number3) == new_shop_sell_number3)
			return;
		m_data.shop_sell_number3 = ToDBString(new_shop_sell_number3);
		emit shop_sell_number3_changed();
	}

	QString Terms::shop_sold3() {
		return ToQString(m_data.shop_sold3);
	}
	void Terms::set_shop_sold3(const QString& new_shop_sold3) {
		if (ToQString(m_data.shop_sold3) == new_shop_sold3)
			return;
		m_data.shop_sold3 = ToDBString(new_shop_sold3);
		emit shop_sold3_changed();
	}

	QString Terms::inn_a_greeting_1() {
		return ToQString(m_data.inn_a_greeting_1);
	}
	void Terms::set_inn_a_greeting_1(const QString& new_inn_a_greeting_1) {
		if (ToQString(m_data.inn_a_greeting_1) == new_inn_a_greeting_1)
			return;
		m_data.inn_a_greeting_1 = ToDBString(new_inn_a_greeting_1);
		emit inn_a_greeting_1_changed();
	}

	QString Terms::inn_a_greeting_2() {
		return ToQString(m_data.inn_a_greeting_2);
	}
	void Terms::set_inn_a_greeting_2(const QString& new_inn_a_greeting_2) {
		if (ToQString(m_data.inn_a_greeting_2) == new_inn_a_greeting_2)
			return;
		m_data.inn_a_greeting_2 = ToDBString(new_inn_a_greeting_2);
		emit inn_a_greeting_2_changed();
	}

	QString Terms::inn_a_greeting_3() {
		return ToQString(m_data.inn_a_greeting_3);
	}
	void Terms::set_inn_a_greeting_3(const QString& new_inn_a_greeting_3) {
		if (ToQString(m_data.inn_a_greeting_3) == new_inn_a_greeting_3)
			return;
		m_data.inn_a_greeting_3 = ToDBString(new_inn_a_greeting_3);
		emit inn_a_greeting_3_changed();
	}

	QString Terms::inn_a_accept() {
		return ToQString(m_data.inn_a_accept);
	}
	void Terms::set_inn_a_accept(const QString& new_inn_a_accept) {
		if (ToQString(m_data.inn_a_accept) == new_inn_a_accept)
			return;
		m_data.inn_a_accept = ToDBString(new_inn_a_accept);
		emit inn_a_accept_changed();
	}

	QString Terms::inn_a_cancel() {
		return ToQString(m_data.inn_a_cancel);
	}
	void Terms::set_inn_a_cancel(const QString& new_inn_a_cancel) {
		if (ToQString(m_data.inn_a_cancel) == new_inn_a_cancel)
			return;
		m_data.inn_a_cancel = ToDBString(new_inn_a_cancel);
		emit inn_a_cancel_changed();
	}

	QString Terms::inn_b_greeting_1() {
		return ToQString(m_data.inn_b_greeting_1);
	}
	void Terms::set_inn_b_greeting_1(const QString& new_inn_b_greeting_1) {
		if (ToQString(m_data.inn_b_greeting_1) == new_inn_b_greeting_1)
			return;
		m_data.inn_b_greeting_1 = ToDBString(new_inn_b_greeting_1);
		emit inn_b_greeting_1_changed();
	}

	QString Terms::inn_b_greeting_2() {
		return ToQString(m_data.inn_b_greeting_2);
	}
	void Terms::set_inn_b_greeting_2(const QString& new_inn_b_greeting_2) {
		if (ToQString(m_data.inn_b_greeting_2) == new_inn_b_greeting_2)
			return;
		m_data.inn_b_greeting_2 = ToDBString(new_inn_b_greeting_2);
		emit inn_b_greeting_2_changed();
	}

	QString Terms::inn_b_greeting_3() {
		return ToQString(m_data.inn_b_greeting_3);
	}
	void Terms::set_inn_b_greeting_3(const QString& new_inn_b_greeting_3) {
		if (ToQString(m_data.inn_b_greeting_3) == new_inn_b_greeting_3)
			return;
		m_data.inn_b_greeting_3 = ToDBString(new_inn_b_greeting_3);
		emit inn_b_greeting_3_changed();
	}

	QString Terms::inn_b_accept() {
		return ToQString(m_data.inn_b_accept);
	}
	void Terms::set_inn_b_accept(const QString& new_inn_b_accept) {
		if (ToQString(m_data.inn_b_accept) == new_inn_b_accept)
			return;
		m_data.inn_b_accept = ToDBString(new_inn_b_accept);
		emit inn_b_accept_changed();
	}

	QString Terms::inn_b_cancel() {
		return ToQString(m_data.inn_b_cancel);
	}
	void Terms::set_inn_b_cancel(const QString& new_inn_b_cancel) {
		if (ToQString(m_data.inn_b_cancel) == new_inn_b_cancel)
			return;
		m_data.inn_b_cancel = ToDBString(new_inn_b_cancel);
		emit inn_b_cancel_changed();
	}

	QString Terms::possessed_items() {
		return ToQString(m_data.possessed_items);
	}
	void Terms::set_possessed_items(const QString& new_possessed_items) {
		if (ToQString(m_data.possessed_items) == new_possessed_items)
			return;
		m_data.possessed_items = ToDBString(new_possessed_items);
		emit possessed_items_changed();
	}

	QString Terms::equipped_items() {
		return ToQString(m_data.equipped_items);
	}
	void Terms::set_equipped_items(const QString& new_equipped_items) {
		if (ToQString(m_data.equipped_items) == new_equipped_items)
			return;
		m_data.equipped_items = ToDBString(new_equipped_items);
		emit equipped_items_changed();
	}

	QString Terms::gold() {
		return ToQString(m_data.gold);
	}
	void Terms::set_gold(const QString& new_gold) {
		if (ToQString(m_data.gold) == new_gold)
			return;
		m_data.gold = ToDBString(new_gold);
		emit gold_changed();
	}

	QString Terms::battle_fight() {
		return ToQString(m_data.battle_fight);
	}
	void Terms::set_battle_fight(const QString& new_battle_fight) {
		if (ToQString(m_data.battle_fight) == new_battle_fight)
			return;
		m_data.battle_fight = ToDBString(new_battle_fight);
		emit battle_fight_changed();
	}

	QString Terms::battle_auto() {
		return ToQString(m_data.battle_auto);
	}
	void Terms::set_battle_auto(const QString& new_battle_auto) {
		if (ToQString(m_data.battle_auto) == new_battle_auto)
			return;
		m_data.battle_auto = ToDBString(new_battle_auto);
		emit battle_auto_changed();
	}

	QString Terms::battle_escape() {
		return ToQString(m_data.battle_escape);
	}
	void Terms::set_battle_escape(const QString& new_battle_escape) {
		if (ToQString(m_data.battle_escape) == new_battle_escape)
			return;
		m_data.battle_escape = ToDBString(new_battle_escape);
		emit battle_escape_changed();
	}

	QString Terms::command_attack() {
		return ToQString(m_data.command_attack);
	}
	void Terms::set_command_attack(const QString& new_command_attack) {
		if (ToQString(m_data.command_attack) == new_command_attack)
			return;
		m_data.command_attack = ToDBString(new_command_attack);
		emit command_attack_changed();
	}

	QString Terms::command_defend() {
		return ToQString(m_data.command_defend);
	}
	void Terms::set_command_defend(const QString& new_command_defend) {
		if (ToQString(m_data.command_defend) == new_command_defend)
			return;
		m_data.command_defend = ToDBString(new_command_defend);
		emit command_defend_changed();
	}

	QString Terms::command_item() {
		return ToQString(m_data.command_item);
	}
	void Terms::set_command_item(const QString& new_command_item) {
		if (ToQString(m_data.command_item) == new_command_item)
			return;
		m_data.command_item = ToDBString(new_command_item);
		emit command_item_changed();
	}

	QString Terms::command_skill() {
		return ToQString(m_data.command_skill);
	}
	void Terms::set_command_skill(const QString& new_command_skill) {
		if (ToQString(m_data.command_skill) == new_command_skill)
			return;
		m_data.command_skill = ToDBString(new_command_skill);
		emit command_skill_changed();
	}

	QString Terms::menu_equipment() {
		return ToQString(m_data.menu_equipment);
	}
	void Terms::set_menu_equipment(const QString& new_menu_equipment) {
		if (ToQString(m_data.menu_equipment) == new_menu_equipment)
			return;
		m_data.menu_equipment = ToDBString(new_menu_equipment);
		emit menu_equipment_changed();
	}

	QString Terms::menu_save() {
		return ToQString(m_data.menu_save);
	}
	void Terms::set_menu_save(const QString& new_menu_save) {
		if (ToQString(m_data.menu_save) == new_menu_save)
			return;
		m_data.menu_save = ToDBString(new_menu_save);
		emit menu_save_changed();
	}

	QString Terms::menu_quit() {
		return ToQString(m_data.menu_quit);
	}
	void Terms::set_menu_quit(const QString& new_menu_quit) {
		if (ToQString(m_data.menu_quit) == new_menu_quit)
			return;
		m_data.menu_quit = ToDBString(new_menu_quit);
		emit menu_quit_changed();
	}

	QString Terms::new_game() {
		return ToQString(m_data.new_game);
	}
	void Terms::set_new_game(const QString& new_new_game) {
		if (ToQString(m_data.new_game) == new_new_game)
			return;
		m_data.new_game = ToDBString(new_new_game);
		emit new_game_changed();
	}

	QString Terms::load_game() {
		return ToQString(m_data.load_game);
	}
	void Terms::set_load_game(const QString& new_load_game) {
		if (ToQString(m_data.load_game) == new_load_game)
			return;
		m_data.load_game = ToDBString(new_load_game);
		emit load_game_changed();
	}

	QString Terms::exit_game() {
		return ToQString(m_data.exit_game);
	}
	void Terms::set_exit_game(const QString& new_exit_game) {
		if (ToQString(m_data.exit_game) == new_exit_game)
			return;
		m_data.exit_game = ToDBString(new_exit_game);
		emit exit_game_changed();
	}

	QString Terms::status() {
		return ToQString(m_data.status);
	}
	void Terms::set_status(const QString& new_status) {
		if (ToQString(m_data.status) == new_status)
			return;
		m_data.status = ToDBString(new_status);
		emit status_changed();
	}

	QString Terms::row() {
		return ToQString(m_data.row);
	}
	void Terms::set_row(const QString& new_row) {
		if (ToQString(m_data.row) == new_row)
			return;
		m_data.row = ToDBString(new_row);
		emit row_changed();
	}

	QString Terms::order() {
		return ToQString(m_data.order);
	}
	void Terms::set_order(const QString& new_order) {
		if (ToQString(m_data.order) == new_order)
			return;
		m_data.order = ToDBString(new_order);
		emit order_changed();
	}

	QString Terms::wait_on() {
		return ToQString(m_data.wait_on);
	}
	void Terms::set_wait_on(const QString& new_wait_on) {
		if (ToQString(m_data.wait_on) == new_wait_on)
			return;
		m_data.wait_on = ToDBString(new_wait_on);
		emit wait_on_changed();
	}

	QString Terms::wait_off() {
		return ToQString(m_data.wait_off);
	}
	void Terms::set_wait_off(const QString& new_wait_off) {
		if (ToQString(m_data.wait_off) == new_wait_off)
			return;
		m_data.wait_off = ToDBString(new_wait_off);
		emit wait_off_changed();
	}

	QString Terms::level() {
		return ToQString(m_data.level);
	}
	void Terms::set_level(const QString& new_level) {
		if (ToQString(m_data.level) == new_level)
			return;
		m_data.level = ToDBString(new_level);
		emit level_changed();
	}

	QString Terms::health_points() {
		return ToQString(m_data.health_points);
	}
	void Terms::set_health_points(const QString& new_health_points) {
		if (ToQString(m_data.health_points) == new_health_points)
			return;
		m_data.health_points = ToDBString(new_health_points);
		emit health_points_changed();
	}

	QString Terms::spirit_points() {
		return ToQString(m_data.spirit_points);
	}
	void Terms::set_spirit_points(const QString& new_spirit_points) {
		if (ToQString(m_data.spirit_points) == new_spirit_points)
			return;
		m_data.spirit_points = ToDBString(new_spirit_points);
		emit spirit_points_changed();
	}

	QString Terms::normal_status() {
		return ToQString(m_data.normal_status);
	}
	void Terms::set_normal_status(const QString& new_normal_status) {
		if (ToQString(m_data.normal_status) == new_normal_status)
			return;
		m_data.normal_status = ToDBString(new_normal_status);
		emit normal_status_changed();
	}

	QString Terms::exp_short() {
		return ToQString(m_data.exp_short);
	}
	void Terms::set_exp_short(const QString& new_exp_short) {
		if (ToQString(m_data.exp_short) == new_exp_short)
			return;
		m_data.exp_short = ToDBString(new_exp_short);
		emit exp_short_changed();
	}

	QString Terms::lvl_short() {
		return ToQString(m_data.lvl_short);
	}
	void Terms::set_lvl_short(const QString& new_lvl_short) {
		if (ToQString(m_data.lvl_short) == new_lvl_short)
			return;
		m_data.lvl_short = ToDBString(new_lvl_short);
		emit lvl_short_changed();
	}

	QString Terms::hp_short() {
		return ToQString(m_data.hp_short);
	}
	void Terms::set_hp_short(const QString& new_hp_short) {
		if (ToQString(m_data.hp_short) == new_hp_short)
			return;
		m_data.hp_short = ToDBString(new_hp_short);
		emit hp_short_changed();
	}

	QString Terms::sp_short() {
		return ToQString(m_data.sp_short);
	}
	void Terms::set_sp_short(const QString& new_sp_short) {
		if (ToQString(m_data.sp_short) == new_sp_short)
			return;
		m_data.sp_short = ToDBString(new_sp_short);
		emit sp_short_changed();
	}

	QString Terms::sp_cost() {
		return ToQString(m_data.sp_cost);
	}
	void Terms::set_sp_cost(const QString& new_sp_cost) {
		if (ToQString(m_data.sp_cost) == new_sp_cost)
			return;
		m_data.sp_cost = ToDBString(new_sp_cost);
		emit sp_cost_changed();
	}

	QString Terms::attack() {
		return ToQString(m_data.attack);
	}
	void Terms::set_attack(const QString& new_attack) {
		if (ToQString(m_data.attack) == new_attack)
			return;
		m_data.attack = ToDBString(new_attack);
		emit attack_changed();
	}

	QString Terms::defense() {
		return ToQString(m_data.defense);
	}
	void Terms::set_defense(const QString& new_defense) {
		if (ToQString(m_data.defense) == new_defense)
			return;
		m_data.defense = ToDBString(new_defense);
		emit defense_changed();
	}

	QString Terms::spirit() {
		return ToQString(m_data.spirit);
	}
	void Terms::set_spirit(const QString& new_spirit) {
		if (ToQString(m_data.spirit) == new_spirit)
			return;
		m_data.spirit = ToDBString(new_spirit);
		emit spirit_changed();
	}

	QString Terms::agility() {
		return ToQString(m_data.agility);
	}
	void Terms::set_agility(const QString& new_agility) {
		if (ToQString(m_data.agility) == new_agility)
			return;
		m_data.agility = ToDBString(new_agility);
		emit agility_changed();
	}

	QString Terms::weapon() {
		return ToQString(m_data.weapon);
	}
	void Terms::set_weapon(const QString& new_weapon) {
		if (ToQString(m_data.weapon) == new_weapon)
			return;
		m_data.weapon = ToDBString(new_weapon);
		emit weapon_changed();
	}

	QString Terms::shield() {
		return ToQString(m_data.shield);
	}
	void Terms::set_shield(const QString& new_shield) {
		if (ToQString(m_data.shield) == new_shield)
			return;
		m_data.shield = ToDBString(new_shield);
		emit shield_changed();
	}

	QString Terms::armor() {
		return ToQString(m_data.armor);
	}
	void Terms::set_armor(const QString& new_armor) {
		if (ToQString(m_data.armor) == new_armor)
			return;
		m_data.armor = ToDBString(new_armor);
		emit armor_changed();
	}

	QString Terms::helmet() {
		return ToQString(m_data.helmet);
	}
	void Terms::set_helmet(const QString& new_helmet) {
		if (ToQString(m_data.helmet) == new_helmet)
			return;
		m_data.helmet = ToDBString(new_helmet);
		emit helmet_changed();
	}

	QString Terms::accessory() {
		return ToQString(m_data.accessory);
	}
	void Terms::set_accessory(const QString& new_accessory) {
		if (ToQString(m_data.accessory) == new_accessory)
			return;
		m_data.accessory = ToDBString(new_accessory);
		emit accessory_changed();
	}

	QString Terms::save_game_message() {
		return ToQString(m_data.save_game_message);
	}
	void Terms::set_save_game_message(const QString& new_save_game_message) {
		if (ToQString(m_data.save_game_message) == new_save_game_message)
			return;
		m_data.save_game_message = ToDBString(new_save_game_message);
		emit save_game_message_changed();
	}

	QString Terms::load_game_message() {
		return ToQString(m_data.load_game_message);
	}
	void Terms::set_load_game_message(const QString& new_load_game_message) {
		if (ToQString(m_data.load_game_message) == new_load_game_message)
			return;
		m_data.load_game_message = ToDBString(new_load_game_message);
		emit load_game_message_changed();
	}

	QString Terms::file() {
		return ToQString(m_data.file);
	}
	void Terms::set_file(const QString& new_file) {
		if (ToQString(m_data.file) == new_file)
			return;
		m_data.file = ToDBString(new_file);
		emit file_changed();
	}

	QString Terms::exit_game_message() {
		return ToQString(m_data.exit_game_message);
	}
	void Terms::set_exit_game_message(const QString& new_exit_game_message) {
		if (ToQString(m_data.exit_game_message) == new_exit_game_message)
			return;
		m_data.exit_game_message = ToDBString(new_exit_game_message);
		emit exit_game_message_changed();
	}

	QString Terms::yes() {
		return ToQString(m_data.yes);
	}
	void Terms::set_yes(const QString& new_yes) {
		if (ToQString(m_data.yes) == new_yes)
			return;
		m_data.yes = ToDBString(new_yes);
		emit yes_changed();
	}

	QString Terms::no() {
		return ToQString(m_data.no);
	}
	void Terms::set_no(const QString& new_no) {
		if (ToQString(m_data.no) == new_no)
			return;
		m_data.no = ToDBString(new_no);
		emit no_changed();
	}

	QString Terms::easyrpg_item_number_separator() {
		return ToQString(m_data.easyrpg_item_number_separator);
	}
	void Terms::set_easyrpg_item_number_separator(const QString& new_easyrpg_item_number_separator) {
		if (ToQString(m_data.easyrpg_item_number_separator) == new_easyrpg_item_number_separator)
			return;
		m_data.easyrpg_item_number_separator = ToDBString(new_easyrpg_item_number_separator);
		emit easyrpg_item_number_separator_changed();
	}

	QString Terms::easyrpg_skill_cost_separator() {
		return ToQString(m_data.easyrpg_skill_cost_separator);
	}
	void Terms::set_easyrpg_skill_cost_separator(const QString& new_easyrpg_skill_cost_separator) {
		if (ToQString(m_data.easyrpg_skill_cost_separator) == new_easyrpg_skill_cost_separator)
			return;
		m_data.easyrpg_skill_cost_separator = ToDBString(new_easyrpg_skill_cost_separator);
		emit easyrpg_skill_cost_separator_changed();
	}

	QString Terms::easyrpg_equipment_arrow() {
		return ToQString(m_data.easyrpg_equipment_arrow);
	}
	void Terms::set_easyrpg_equipment_arrow(const QString& new_easyrpg_equipment_arrow) {
		if (ToQString(m_data.easyrpg_equipment_arrow) == new_easyrpg_equipment_arrow)
			return;
		m_data.easyrpg_equipment_arrow = ToDBString(new_easyrpg_equipment_arrow);
		emit easyrpg_equipment_arrow_changed();
	}

	QString Terms::easyrpg_status_scene_name() {
		return ToQString(m_data.easyrpg_status_scene_name);
	}
	void Terms::set_easyrpg_status_scene_name(const QString& new_easyrpg_status_scene_name) {
		if (ToQString(m_data.easyrpg_status_scene_name) == new_easyrpg_status_scene_name)
			return;
		m_data.easyrpg_status_scene_name = ToDBString(new_easyrpg_status_scene_name);
		emit easyrpg_status_scene_name_changed();
	}

	QString Terms::easyrpg_status_scene_class() {
		return ToQString(m_data.easyrpg_status_scene_class);
	}
	void Terms::set_easyrpg_status_scene_class(const QString& new_easyrpg_status_scene_class) {
		if (ToQString(m_data.easyrpg_status_scene_class) == new_easyrpg_status_scene_class)
			return;
		m_data.easyrpg_status_scene_class = ToDBString(new_easyrpg_status_scene_class);
		emit easyrpg_status_scene_class_changed();
	}

	QString Terms::easyrpg_status_scene_title() {
		return ToQString(m_data.easyrpg_status_scene_title);
	}
	void Terms::set_easyrpg_status_scene_title(const QString& new_easyrpg_status_scene_title) {
		if (ToQString(m_data.easyrpg_status_scene_title) == new_easyrpg_status_scene_title)
			return;
		m_data.easyrpg_status_scene_title = ToDBString(new_easyrpg_status_scene_title);
		emit easyrpg_status_scene_title_changed();
	}

	QString Terms::easyrpg_status_scene_condition() {
		return ToQString(m_data.easyrpg_status_scene_condition);
	}
	void Terms::set_easyrpg_status_scene_condition(const QString& new_easyrpg_status_scene_condition) {
		if (ToQString(m_data.easyrpg_status_scene_condition) == new_easyrpg_status_scene_condition)
			return;
		m_data.easyrpg_status_scene_condition = ToDBString(new_easyrpg_status_scene_condition);
		emit easyrpg_status_scene_condition_changed();
	}

	QString Terms::easyrpg_status_scene_front() {
		return ToQString(m_data.easyrpg_status_scene_front);
	}
	void Terms::set_easyrpg_status_scene_front(const QString& new_easyrpg_status_scene_front) {
		if (ToQString(m_data.easyrpg_status_scene_front) == new_easyrpg_status_scene_front)
			return;
		m_data.easyrpg_status_scene_front = ToDBString(new_easyrpg_status_scene_front);
		emit easyrpg_status_scene_front_changed();
	}

	QString Terms::easyrpg_status_scene_back() {
		return ToQString(m_data.easyrpg_status_scene_back);
	}
	void Terms::set_easyrpg_status_scene_back(const QString& new_easyrpg_status_scene_back) {
		if (ToQString(m_data.easyrpg_status_scene_back) == new_easyrpg_status_scene_back)
			return;
		m_data.easyrpg_status_scene_back = ToDBString(new_easyrpg_status_scene_back);
		emit easyrpg_status_scene_back_changed();
	}

	QString Terms::easyrpg_order_scene_confirm() {
		return ToQString(m_data.easyrpg_order_scene_confirm);
	}
	void Terms::set_easyrpg_order_scene_confirm(const QString& new_easyrpg_order_scene_confirm) {
		if (ToQString(m_data.easyrpg_order_scene_confirm) == new_easyrpg_order_scene_confirm)
			return;
		m_data.easyrpg_order_scene_confirm = ToDBString(new_easyrpg_order_scene_confirm);
		emit easyrpg_order_scene_confirm_changed();
	}

	QString Terms::easyrpg_order_scene_redo() {
		return ToQString(m_data.easyrpg_order_scene_redo);
	}
	void Terms::set_easyrpg_order_scene_redo(const QString& new_easyrpg_order_scene_redo) {
		if (ToQString(m_data.easyrpg_order_scene_redo) == new_easyrpg_order_scene_redo)
			return;
		m_data.easyrpg_order_scene_redo = ToDBString(new_easyrpg_order_scene_redo);
		emit easyrpg_order_scene_redo_changed();
	}

	QString Terms::easyrpg_battle2k3_double_attack() {
		return ToQString(m_data.easyrpg_battle2k3_double_attack);
	}
	void Terms::set_easyrpg_battle2k3_double_attack(const QString& new_easyrpg_battle2k3_double_attack) {
		if (ToQString(m_data.easyrpg_battle2k3_double_attack) == new_easyrpg_battle2k3_double_attack)
			return;
		m_data.easyrpg_battle2k3_double_attack = ToDBString(new_easyrpg_battle2k3_double_attack);
		emit easyrpg_battle2k3_double_attack_changed();
	}

	QString Terms::easyrpg_battle2k3_defend() {
		return ToQString(m_data.easyrpg_battle2k3_defend);
	}
	void Terms::set_easyrpg_battle2k3_defend(const QString& new_easyrpg_battle2k3_defend) {
		if (ToQString(m_data.easyrpg_battle2k3_defend) == new_easyrpg_battle2k3_defend)
			return;
		m_data.easyrpg_battle2k3_defend = ToDBString(new_easyrpg_battle2k3_defend);
		emit easyrpg_battle2k3_defend_changed();
	}

	QString Terms::easyrpg_battle2k3_observe() {
		return ToQString(m_data.easyrpg_battle2k3_observe);
	}
	void Terms::set_easyrpg_battle2k3_observe(const QString& new_easyrpg_battle2k3_observe) {
		if (ToQString(m_data.easyrpg_battle2k3_observe) == new_easyrpg_battle2k3_observe)
			return;
		m_data.easyrpg_battle2k3_observe = ToDBString(new_easyrpg_battle2k3_observe);
		emit easyrpg_battle2k3_observe_changed();
	}

	QString Terms::easyrpg_battle2k3_charge() {
		return ToQString(m_data.easyrpg_battle2k3_charge);
	}
	void Terms::set_easyrpg_battle2k3_charge(const QString& new_easyrpg_battle2k3_charge) {
		if (ToQString(m_data.easyrpg_battle2k3_charge) == new_easyrpg_battle2k3_charge)
			return;
		m_data.easyrpg_battle2k3_charge = ToDBString(new_easyrpg_battle2k3_charge);
		emit easyrpg_battle2k3_charge_changed();
	}

	QString Terms::easyrpg_battle2k3_selfdestruct() {
		return ToQString(m_data.easyrpg_battle2k3_selfdestruct);
	}
	void Terms::set_easyrpg_battle2k3_selfdestruct(const QString& new_easyrpg_battle2k3_selfdestruct) {
		if (ToQString(m_data.easyrpg_battle2k3_selfdestruct) == new_easyrpg_battle2k3_selfdestruct)
			return;
		m_data.easyrpg_battle2k3_selfdestruct = ToDBString(new_easyrpg_battle2k3_selfdestruct);
		emit easyrpg_battle2k3_selfdestruct_changed();
	}

	QString Terms::easyrpg_battle2k3_escape() {
		return ToQString(m_data.easyrpg_battle2k3_escape);
	}
	void Terms::set_easyrpg_battle2k3_escape(const QString& new_easyrpg_battle2k3_escape) {
		if (ToQString(m_data.easyrpg_battle2k3_escape) == new_easyrpg_battle2k3_escape)
			return;
		m_data.easyrpg_battle2k3_escape = ToDBString(new_easyrpg_battle2k3_escape);
		emit easyrpg_battle2k3_escape_changed();
	}

	QString Terms::easyrpg_battle2k3_special_combat_back() {
		return ToQString(m_data.easyrpg_battle2k3_special_combat_back);
	}
	void Terms::set_easyrpg_battle2k3_special_combat_back(const QString& new_easyrpg_battle2k3_special_combat_back) {
		if (ToQString(m_data.easyrpg_battle2k3_special_combat_back) == new_easyrpg_battle2k3_special_combat_back)
			return;
		m_data.easyrpg_battle2k3_special_combat_back = ToDBString(new_easyrpg_battle2k3_special_combat_back);
		emit easyrpg_battle2k3_special_combat_back_changed();
	}

	QString Terms::easyrpg_battle2k3_skill() {
		return ToQString(m_data.easyrpg_battle2k3_skill);
	}
	void Terms::set_easyrpg_battle2k3_skill(const QString& new_easyrpg_battle2k3_skill) {
		if (ToQString(m_data.easyrpg_battle2k3_skill) == new_easyrpg_battle2k3_skill)
			return;
		m_data.easyrpg_battle2k3_skill = ToDBString(new_easyrpg_battle2k3_skill);
		emit easyrpg_battle2k3_skill_changed();
	}

	QString Terms::easyrpg_battle2k3_item() {
		return ToQString(m_data.easyrpg_battle2k3_item);
	}
	void Terms::set_easyrpg_battle2k3_item(const QString& new_easyrpg_battle2k3_item) {
		if (ToQString(m_data.easyrpg_battle2k3_item) == new_easyrpg_battle2k3_item)
			return;
		m_data.easyrpg_battle2k3_item = ToDBString(new_easyrpg_battle2k3_item);
		emit easyrpg_battle2k3_item_changed();
	}

} // namespace Binding::Generated
