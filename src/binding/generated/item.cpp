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
#include "item.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Item::Item(ProjectData& project, lcf::rpg::Item& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		for (auto& var: m_data.animation_data) {
			m_animation_data.push_back(new Binding::BattlerAnimationItemSkill(m_project, var, this));
		}
	}
	int Item::id() {
		return m_data.ID;
	}
	QString Item::name() {
		return ToQString(m_data.name);
	}
	void Item::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	QString Item::description() {
		return ToQString(m_data.description);
	}
	void Item::set_description(const QString& new_description) {
		if (ToQString(m_data.description) == new_description)
			return;
		m_data.description = ToDBString(new_description);
		emit description_changed();
	}

	int32_t Item::type() {
		return m_data.type;
	}

	int Item::price() {
		return m_data.price;
	}
	void Item::set_price(const int& new_price) {
		if (m_data.price == new_price)
			return;
		m_data.price = new_price;
		emit price_changed();
	}

	int Item::uses() {
		return m_data.uses;
	}
	void Item::set_uses(const int& new_uses) {
		if (m_data.uses == new_uses)
			return;
		m_data.uses = new_uses;
		emit uses_changed();
	}

	int Item::atk_points1() {
		return m_data.atk_points1;
	}
	void Item::set_atk_points1(const int& new_atk_points1) {
		if (m_data.atk_points1 == new_atk_points1)
			return;
		m_data.atk_points1 = new_atk_points1;
		emit atk_points1_changed();
	}

	int Item::def_points1() {
		return m_data.def_points1;
	}
	void Item::set_def_points1(const int& new_def_points1) {
		if (m_data.def_points1 == new_def_points1)
			return;
		m_data.def_points1 = new_def_points1;
		emit def_points1_changed();
	}

	int Item::spi_points1() {
		return m_data.spi_points1;
	}
	void Item::set_spi_points1(const int& new_spi_points1) {
		if (m_data.spi_points1 == new_spi_points1)
			return;
		m_data.spi_points1 = new_spi_points1;
		emit spi_points1_changed();
	}

	int Item::agi_points1() {
		return m_data.agi_points1;
	}
	void Item::set_agi_points1(const int& new_agi_points1) {
		if (m_data.agi_points1 == new_agi_points1)
			return;
		m_data.agi_points1 = new_agi_points1;
		emit agi_points1_changed();
	}

	bool Item::two_handed() {
		return m_data.two_handed;
	}
	void Item::set_two_handed(const bool& new_two_handed) {
		if (m_data.two_handed == new_two_handed)
			return;
		m_data.two_handed = new_two_handed;
		emit two_handed_changed();
	}

	int Item::sp_cost() {
		return m_data.sp_cost;
	}
	void Item::set_sp_cost(const int& new_sp_cost) {
		if (m_data.sp_cost == new_sp_cost)
			return;
		m_data.sp_cost = new_sp_cost;
		emit sp_cost_changed();
	}

	int Item::hit() {
		return m_data.hit;
	}
	void Item::set_hit(const int& new_hit) {
		if (m_data.hit == new_hit)
			return;
		m_data.hit = new_hit;
		emit hit_changed();
	}

	int Item::critical_hit() {
		return m_data.critical_hit;
	}
	void Item::set_critical_hit(const int& new_critical_hit) {
		if (m_data.critical_hit == new_critical_hit)
			return;
		m_data.critical_hit = new_critical_hit;
		emit critical_hit_changed();
	}

	int32_t Item::animation_id() {
		return m_data.animation_id;
	}

	bool Item::preemptive() {
		return m_data.preemptive;
	}
	void Item::set_preemptive(const bool& new_preemptive) {
		if (m_data.preemptive == new_preemptive)
			return;
		m_data.preemptive = new_preemptive;
		emit preemptive_changed();
	}

	bool Item::dual_attack() {
		return m_data.dual_attack;
	}
	void Item::set_dual_attack(const bool& new_dual_attack) {
		if (m_data.dual_attack == new_dual_attack)
			return;
		m_data.dual_attack = new_dual_attack;
		emit dual_attack_changed();
	}

	bool Item::attack_all() {
		return m_data.attack_all;
	}
	void Item::set_attack_all(const bool& new_attack_all) {
		if (m_data.attack_all == new_attack_all)
			return;
		m_data.attack_all = new_attack_all;
		emit attack_all_changed();
	}

	bool Item::ignore_evasion() {
		return m_data.ignore_evasion;
	}
	void Item::set_ignore_evasion(const bool& new_ignore_evasion) {
		if (m_data.ignore_evasion == new_ignore_evasion)
			return;
		m_data.ignore_evasion = new_ignore_evasion;
		emit ignore_evasion_changed();
	}

	bool Item::prevent_critical() {
		return m_data.prevent_critical;
	}
	void Item::set_prevent_critical(const bool& new_prevent_critical) {
		if (m_data.prevent_critical == new_prevent_critical)
			return;
		m_data.prevent_critical = new_prevent_critical;
		emit prevent_critical_changed();
	}

	bool Item::raise_evasion() {
		return m_data.raise_evasion;
	}
	void Item::set_raise_evasion(const bool& new_raise_evasion) {
		if (m_data.raise_evasion == new_raise_evasion)
			return;
		m_data.raise_evasion = new_raise_evasion;
		emit raise_evasion_changed();
	}

	bool Item::half_sp_cost() {
		return m_data.half_sp_cost;
	}
	void Item::set_half_sp_cost(const bool& new_half_sp_cost) {
		if (m_data.half_sp_cost == new_half_sp_cost)
			return;
		m_data.half_sp_cost = new_half_sp_cost;
		emit half_sp_cost_changed();
	}

	bool Item::no_terrain_damage() {
		return m_data.no_terrain_damage;
	}
	void Item::set_no_terrain_damage(const bool& new_no_terrain_damage) {
		if (m_data.no_terrain_damage == new_no_terrain_damage)
			return;
		m_data.no_terrain_damage = new_no_terrain_damage;
		emit no_terrain_damage_changed();
	}

	bool Item::cursed() {
		return m_data.cursed;
	}
	void Item::set_cursed(const bool& new_cursed) {
		if (m_data.cursed == new_cursed)
			return;
		m_data.cursed = new_cursed;
		emit cursed_changed();
	}

	bool Item::entire_party() {
		return m_data.entire_party;
	}
	void Item::set_entire_party(const bool& new_entire_party) {
		if (m_data.entire_party == new_entire_party)
			return;
		m_data.entire_party = new_entire_party;
		emit entire_party_changed();
	}

	int Item::recover_hp_rate() {
		return m_data.recover_hp_rate;
	}
	void Item::set_recover_hp_rate(const int& new_recover_hp_rate) {
		if (m_data.recover_hp_rate == new_recover_hp_rate)
			return;
		m_data.recover_hp_rate = new_recover_hp_rate;
		emit recover_hp_rate_changed();
	}

	int Item::recover_hp() {
		return m_data.recover_hp;
	}
	void Item::set_recover_hp(const int& new_recover_hp) {
		if (m_data.recover_hp == new_recover_hp)
			return;
		m_data.recover_hp = new_recover_hp;
		emit recover_hp_changed();
	}

	int Item::recover_sp_rate() {
		return m_data.recover_sp_rate;
	}
	void Item::set_recover_sp_rate(const int& new_recover_sp_rate) {
		if (m_data.recover_sp_rate == new_recover_sp_rate)
			return;
		m_data.recover_sp_rate = new_recover_sp_rate;
		emit recover_sp_rate_changed();
	}

	int Item::recover_sp() {
		return m_data.recover_sp;
	}
	void Item::set_recover_sp(const int& new_recover_sp) {
		if (m_data.recover_sp == new_recover_sp)
			return;
		m_data.recover_sp = new_recover_sp;
		emit recover_sp_changed();
	}

	bool Item::occasion_field1() {
		return m_data.occasion_field1;
	}
	void Item::set_occasion_field1(const bool& new_occasion_field1) {
		if (m_data.occasion_field1 == new_occasion_field1)
			return;
		m_data.occasion_field1 = new_occasion_field1;
		emit occasion_field1_changed();
	}

	bool Item::ko_only() {
		return m_data.ko_only;
	}
	void Item::set_ko_only(const bool& new_ko_only) {
		if (m_data.ko_only == new_ko_only)
			return;
		m_data.ko_only = new_ko_only;
		emit ko_only_changed();
	}

	int Item::max_hp_points() {
		return m_data.max_hp_points;
	}
	void Item::set_max_hp_points(const int& new_max_hp_points) {
		if (m_data.max_hp_points == new_max_hp_points)
			return;
		m_data.max_hp_points = new_max_hp_points;
		emit max_hp_points_changed();
	}

	int Item::max_sp_points() {
		return m_data.max_sp_points;
	}
	void Item::set_max_sp_points(const int& new_max_sp_points) {
		if (m_data.max_sp_points == new_max_sp_points)
			return;
		m_data.max_sp_points = new_max_sp_points;
		emit max_sp_points_changed();
	}

	int Item::atk_points2() {
		return m_data.atk_points2;
	}
	void Item::set_atk_points2(const int& new_atk_points2) {
		if (m_data.atk_points2 == new_atk_points2)
			return;
		m_data.atk_points2 = new_atk_points2;
		emit atk_points2_changed();
	}

	int Item::def_points2() {
		return m_data.def_points2;
	}
	void Item::set_def_points2(const int& new_def_points2) {
		if (m_data.def_points2 == new_def_points2)
			return;
		m_data.def_points2 = new_def_points2;
		emit def_points2_changed();
	}

	int Item::spi_points2() {
		return m_data.spi_points2;
	}
	void Item::set_spi_points2(const int& new_spi_points2) {
		if (m_data.spi_points2 == new_spi_points2)
			return;
		m_data.spi_points2 = new_spi_points2;
		emit spi_points2_changed();
	}

	int Item::agi_points2() {
		return m_data.agi_points2;
	}
	void Item::set_agi_points2(const int& new_agi_points2) {
		if (m_data.agi_points2 == new_agi_points2)
			return;
		m_data.agi_points2 = new_agi_points2;
		emit agi_points2_changed();
	}

	int Item::using_message() {
		return m_data.using_message;
	}
	void Item::set_using_message(const int& new_using_message) {
		if (m_data.using_message == new_using_message)
			return;
		m_data.using_message = new_using_message;
		emit using_message_changed();
	}

	int32_t Item::skill_id() {
		return m_data.skill_id;
	}

	int32_t Item::switch_id() {
		return m_data.switch_id;
	}

	bool Item::occasion_field2() {
		return m_data.occasion_field2;
	}
	void Item::set_occasion_field2(const bool& new_occasion_field2) {
		if (m_data.occasion_field2 == new_occasion_field2)
			return;
		m_data.occasion_field2 = new_occasion_field2;
		emit occasion_field2_changed();
	}

	bool Item::occasion_battle() {
		return m_data.occasion_battle;
	}
	void Item::set_occasion_battle(const bool& new_occasion_battle) {
		if (m_data.occasion_battle == new_occasion_battle)
			return;
		m_data.occasion_battle = new_occasion_battle;
		emit occasion_battle_changed();
	}

	QVector<bool> Item::actor_set() {
		return QVector<bool>(m_data.actor_set.begin(), m_data.actor_set.end());
	}
	void Item::set_actor_set(const QVector<bool>& new_actor_set) {
		if (QVector<bool>(m_data.actor_set.begin(), m_data.actor_set.end()) == new_actor_set)
			return;
		m_data.actor_set = decltype(m_data.actor_set)(new_actor_set.begin(), new_actor_set.end());
		emit actor_set_changed();
	}

	QVector<bool> Item::state_set() {
		return QVector<bool>(m_data.state_set.begin(), m_data.state_set.end());
	}
	void Item::set_state_set(const QVector<bool>& new_state_set) {
		if (QVector<bool>(m_data.state_set.begin(), m_data.state_set.end()) == new_state_set)
			return;
		m_data.state_set = decltype(m_data.state_set)(new_state_set.begin(), new_state_set.end());
		emit state_set_changed();
	}

	QVector<bool> Item::attribute_set() {
		return QVector<bool>(m_data.attribute_set.begin(), m_data.attribute_set.end());
	}
	void Item::set_attribute_set(const QVector<bool>& new_attribute_set) {
		if (QVector<bool>(m_data.attribute_set.begin(), m_data.attribute_set.end()) == new_attribute_set)
			return;
		m_data.attribute_set = decltype(m_data.attribute_set)(new_attribute_set.begin(), new_attribute_set.end());
		emit attribute_set_changed();
	}

	int Item::state_chance() {
		return m_data.state_chance;
	}
	void Item::set_state_chance(const int& new_state_chance) {
		if (m_data.state_chance == new_state_chance)
			return;
		m_data.state_chance = new_state_chance;
		emit state_chance_changed();
	}

	bool Item::reverse_state_effect() {
		return m_data.reverse_state_effect;
	}
	void Item::set_reverse_state_effect(const bool& new_reverse_state_effect) {
		if (m_data.reverse_state_effect == new_reverse_state_effect)
			return;
		m_data.reverse_state_effect = new_reverse_state_effect;
		emit reverse_state_effect_changed();
	}

	int32_t Item::weapon_animation() {
		return m_data.weapon_animation;
	}

	QVector<Binding::BattlerAnimationItemSkill*>& Item::animation_data() {
		return m_animation_data;
	}

	bool Item::use_skill() {
		return m_data.use_skill;
	}
	void Item::set_use_skill(const bool& new_use_skill) {
		if (m_data.use_skill == new_use_skill)
			return;
		m_data.use_skill = new_use_skill;
		emit use_skill_changed();
	}

	QVector<bool> Item::class_set() {
		return QVector<bool>(m_data.class_set.begin(), m_data.class_set.end());
	}
	void Item::set_class_set(const QVector<bool>& new_class_set) {
		if (QVector<bool>(m_data.class_set.begin(), m_data.class_set.end()) == new_class_set)
			return;
		m_data.class_set = decltype(m_data.class_set)(new_class_set.begin(), new_class_set.end());
		emit class_set_changed();
	}

	int32_t Item::ranged_trajectory() {
		return m_data.ranged_trajectory;
	}

	int32_t Item::ranged_target() {
		return m_data.ranged_target;
	}

	QString Item::easyrpg_using_message() {
		return ToQString(m_data.easyrpg_using_message);
	}
	void Item::set_easyrpg_using_message(const QString& new_easyrpg_using_message) {
		if (ToQString(m_data.easyrpg_using_message) == new_easyrpg_using_message)
			return;
		m_data.easyrpg_using_message = ToDBString(new_easyrpg_using_message);
		emit easyrpg_using_message_changed();
	}

	int Item::easyrpg_max_count() {
		return m_data.easyrpg_max_count;
	}
	void Item::set_easyrpg_max_count(const int& new_easyrpg_max_count) {
		if (m_data.easyrpg_max_count == new_easyrpg_max_count)
			return;
		m_data.easyrpg_max_count = new_easyrpg_max_count;
		emit easyrpg_max_count_changed();
	}

} // namespace Binding::Generated
