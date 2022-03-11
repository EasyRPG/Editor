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
#include "enemy.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Enemy::Enemy(ProjectData& project, lcf::rpg::Enemy& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		for (auto& var: m_data.actions) {
			m_actions.push_back(new Binding::EnemyAction(m_project, var, this));
		}
	}
	int Enemy::id() {
		return m_data.ID;
	}
	QString Enemy::name() {
		return ToQString(m_data.name);
	}
	void Enemy::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	QString Enemy::battler_name() {
		return ToQString(m_data.battler_name);
	}
	void Enemy::set_battler_name(const QString& new_battler_name) {
		if (ToQString(m_data.battler_name) == new_battler_name)
			return;
		m_data.battler_name = ToDBString(new_battler_name);
		emit battler_name_changed();
	}

	int Enemy::battler_hue() {
		return m_data.battler_hue;
	}
	void Enemy::set_battler_hue(const int& new_battler_hue) {
		if (m_data.battler_hue == new_battler_hue)
			return;
		m_data.battler_hue = new_battler_hue;
		emit battler_hue_changed();
	}

	int Enemy::max_hp() {
		return m_data.max_hp;
	}
	void Enemy::set_max_hp(const int& new_max_hp) {
		if (m_data.max_hp == new_max_hp)
			return;
		m_data.max_hp = new_max_hp;
		emit max_hp_changed();
	}

	int Enemy::max_sp() {
		return m_data.max_sp;
	}
	void Enemy::set_max_sp(const int& new_max_sp) {
		if (m_data.max_sp == new_max_sp)
			return;
		m_data.max_sp = new_max_sp;
		emit max_sp_changed();
	}

	int Enemy::attack() {
		return m_data.attack;
	}
	void Enemy::set_attack(const int& new_attack) {
		if (m_data.attack == new_attack)
			return;
		m_data.attack = new_attack;
		emit attack_changed();
	}

	int Enemy::defense() {
		return m_data.defense;
	}
	void Enemy::set_defense(const int& new_defense) {
		if (m_data.defense == new_defense)
			return;
		m_data.defense = new_defense;
		emit defense_changed();
	}

	int Enemy::spirit() {
		return m_data.spirit;
	}
	void Enemy::set_spirit(const int& new_spirit) {
		if (m_data.spirit == new_spirit)
			return;
		m_data.spirit = new_spirit;
		emit spirit_changed();
	}

	int Enemy::agility() {
		return m_data.agility;
	}
	void Enemy::set_agility(const int& new_agility) {
		if (m_data.agility == new_agility)
			return;
		m_data.agility = new_agility;
		emit agility_changed();
	}

	bool Enemy::transparent() {
		return m_data.transparent;
	}
	void Enemy::set_transparent(const bool& new_transparent) {
		if (m_data.transparent == new_transparent)
			return;
		m_data.transparent = new_transparent;
		emit transparent_changed();
	}

	int Enemy::exp() {
		return m_data.exp;
	}
	void Enemy::set_exp(const int& new_exp) {
		if (m_data.exp == new_exp)
			return;
		m_data.exp = new_exp;
		emit exp_changed();
	}

	int Enemy::gold() {
		return m_data.gold;
	}
	void Enemy::set_gold(const int& new_gold) {
		if (m_data.gold == new_gold)
			return;
		m_data.gold = new_gold;
		emit gold_changed();
	}

	int32_t Enemy::drop_id() {
		return m_data.drop_id;
	}

	int Enemy::drop_prob() {
		return m_data.drop_prob;
	}
	void Enemy::set_drop_prob(const int& new_drop_prob) {
		if (m_data.drop_prob == new_drop_prob)
			return;
		m_data.drop_prob = new_drop_prob;
		emit drop_prob_changed();
	}

	bool Enemy::critical_hit() {
		return m_data.critical_hit;
	}
	void Enemy::set_critical_hit(const bool& new_critical_hit) {
		if (m_data.critical_hit == new_critical_hit)
			return;
		m_data.critical_hit = new_critical_hit;
		emit critical_hit_changed();
	}

	int Enemy::critical_hit_chance() {
		return m_data.critical_hit_chance;
	}
	void Enemy::set_critical_hit_chance(const int& new_critical_hit_chance) {
		if (m_data.critical_hit_chance == new_critical_hit_chance)
			return;
		m_data.critical_hit_chance = new_critical_hit_chance;
		emit critical_hit_chance_changed();
	}

	bool Enemy::miss() {
		return m_data.miss;
	}
	void Enemy::set_miss(const bool& new_miss) {
		if (m_data.miss == new_miss)
			return;
		m_data.miss = new_miss;
		emit miss_changed();
	}

	bool Enemy::levitate() {
		return m_data.levitate;
	}
	void Enemy::set_levitate(const bool& new_levitate) {
		if (m_data.levitate == new_levitate)
			return;
		m_data.levitate = new_levitate;
		emit levitate_changed();
	}

	QVector<int> Enemy::state_ranks() {
		return QVector<int>(m_data.state_ranks.begin(), m_data.state_ranks.end());
	}
	void Enemy::set_state_ranks(const QVector<int>& new_state_ranks) {
		if (QVector<int>(m_data.state_ranks.begin(), m_data.state_ranks.end()) == new_state_ranks)
			return;
		m_data.state_ranks = decltype(m_data.state_ranks)(new_state_ranks.begin(), new_state_ranks.end());
		emit state_ranks_changed();
	}

	QVector<int> Enemy::attribute_ranks() {
		return QVector<int>(m_data.attribute_ranks.begin(), m_data.attribute_ranks.end());
	}
	void Enemy::set_attribute_ranks(const QVector<int>& new_attribute_ranks) {
		if (QVector<int>(m_data.attribute_ranks.begin(), m_data.attribute_ranks.end()) == new_attribute_ranks)
			return;
		m_data.attribute_ranks = decltype(m_data.attribute_ranks)(new_attribute_ranks.begin(), new_attribute_ranks.end());
		emit attribute_ranks_changed();
	}

	QVector<Binding::EnemyAction*>& Enemy::actions() {
		return m_actions;
	}

	int32_t Enemy::maniac_unarmed_animation() {
		return m_data.maniac_unarmed_animation;
	}

	int Enemy::easyrpg_enemyai() {
		return m_data.easyrpg_enemyai;
	}
	void Enemy::set_easyrpg_enemyai(const int& new_easyrpg_enemyai) {
		if (m_data.easyrpg_enemyai == new_easyrpg_enemyai)
			return;
		m_data.easyrpg_enemyai = new_easyrpg_enemyai;
		emit easyrpg_enemyai_changed();
	}

	bool Enemy::easyrpg_prevent_critical() {
		return m_data.easyrpg_prevent_critical;
	}
	void Enemy::set_easyrpg_prevent_critical(const bool& new_easyrpg_prevent_critical) {
		if (m_data.easyrpg_prevent_critical == new_easyrpg_prevent_critical)
			return;
		m_data.easyrpg_prevent_critical = new_easyrpg_prevent_critical;
		emit easyrpg_prevent_critical_changed();
	}

	bool Enemy::easyrpg_raise_evasion() {
		return m_data.easyrpg_raise_evasion;
	}
	void Enemy::set_easyrpg_raise_evasion(const bool& new_easyrpg_raise_evasion) {
		if (m_data.easyrpg_raise_evasion == new_easyrpg_raise_evasion)
			return;
		m_data.easyrpg_raise_evasion = new_easyrpg_raise_evasion;
		emit easyrpg_raise_evasion_changed();
	}

	bool Enemy::easyrpg_immune_to_attribute_downshifts() {
		return m_data.easyrpg_immune_to_attribute_downshifts;
	}
	void Enemy::set_easyrpg_immune_to_attribute_downshifts(const bool& new_easyrpg_immune_to_attribute_downshifts) {
		if (m_data.easyrpg_immune_to_attribute_downshifts == new_easyrpg_immune_to_attribute_downshifts)
			return;
		m_data.easyrpg_immune_to_attribute_downshifts = new_easyrpg_immune_to_attribute_downshifts;
		emit easyrpg_immune_to_attribute_downshifts_changed();
	}

	bool Enemy::easyrpg_ignore_evasion() {
		return m_data.easyrpg_ignore_evasion;
	}
	void Enemy::set_easyrpg_ignore_evasion(const bool& new_easyrpg_ignore_evasion) {
		if (m_data.easyrpg_ignore_evasion == new_easyrpg_ignore_evasion)
			return;
		m_data.easyrpg_ignore_evasion = new_easyrpg_ignore_evasion;
		emit easyrpg_ignore_evasion_changed();
	}

	int Enemy::easyrpg_hit() {
		return m_data.easyrpg_hit;
	}
	void Enemy::set_easyrpg_hit(const int& new_easyrpg_hit) {
		if (m_data.easyrpg_hit == new_easyrpg_hit)
			return;
		m_data.easyrpg_hit = new_easyrpg_hit;
		emit easyrpg_hit_changed();
	}

	QVector<bool> Enemy::easyrpg_state_set() {
		return QVector<bool>(m_data.easyrpg_state_set.begin(), m_data.easyrpg_state_set.end());
	}
	void Enemy::set_easyrpg_state_set(const QVector<bool>& new_easyrpg_state_set) {
		if (QVector<bool>(m_data.easyrpg_state_set.begin(), m_data.easyrpg_state_set.end()) == new_easyrpg_state_set)
			return;
		m_data.easyrpg_state_set = decltype(m_data.easyrpg_state_set)(new_easyrpg_state_set.begin(), new_easyrpg_state_set.end());
		emit easyrpg_state_set_changed();
	}

	int Enemy::easyrpg_state_chance() {
		return m_data.easyrpg_state_chance;
	}
	void Enemy::set_easyrpg_state_chance(const int& new_easyrpg_state_chance) {
		if (m_data.easyrpg_state_chance == new_easyrpg_state_chance)
			return;
		m_data.easyrpg_state_chance = new_easyrpg_state_chance;
		emit easyrpg_state_chance_changed();
	}

	QVector<bool> Enemy::easyrpg_attribute_set() {
		return QVector<bool>(m_data.easyrpg_attribute_set.begin(), m_data.easyrpg_attribute_set.end());
	}
	void Enemy::set_easyrpg_attribute_set(const QVector<bool>& new_easyrpg_attribute_set) {
		if (QVector<bool>(m_data.easyrpg_attribute_set.begin(), m_data.easyrpg_attribute_set.end()) == new_easyrpg_attribute_set)
			return;
		m_data.easyrpg_attribute_set = decltype(m_data.easyrpg_attribute_set)(new_easyrpg_attribute_set.begin(), new_easyrpg_attribute_set.end());
		emit easyrpg_attribute_set_changed();
	}

	bool Enemy::easyrpg_super_guard() {
		return m_data.easyrpg_super_guard;
	}
	void Enemy::set_easyrpg_super_guard(const bool& new_easyrpg_super_guard) {
		if (m_data.easyrpg_super_guard == new_easyrpg_super_guard)
			return;
		m_data.easyrpg_super_guard = new_easyrpg_super_guard;
		emit easyrpg_super_guard_changed();
	}

	bool Enemy::easyrpg_attack_all() {
		return m_data.easyrpg_attack_all;
	}
	void Enemy::set_easyrpg_attack_all(const bool& new_easyrpg_attack_all) {
		if (m_data.easyrpg_attack_all == new_easyrpg_attack_all)
			return;
		m_data.easyrpg_attack_all = new_easyrpg_attack_all;
		emit easyrpg_attack_all_changed();
	}

} // namespace Binding::Generated
