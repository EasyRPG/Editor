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
#include <lcf/rpg/enemy.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/enemyaction.h"

class ProjectData;

/**
 * Binding::Generated::Enemy class.
 * Exposes lcf::rpg::Enemy to QML.
 */
namespace Binding::Generated {
class Enemy : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(QString battler_name READ battler_name WRITE set_battler_name NOTIFY battler_name_changed)
	Q_PROPERTY(int battler_hue READ battler_hue WRITE set_battler_hue NOTIFY battler_hue_changed)
	Q_PROPERTY(int max_hp READ max_hp WRITE set_max_hp NOTIFY max_hp_changed)
	Q_PROPERTY(int max_sp READ max_sp WRITE set_max_sp NOTIFY max_sp_changed)
	Q_PROPERTY(int attack READ attack WRITE set_attack NOTIFY attack_changed)
	Q_PROPERTY(int defense READ defense WRITE set_defense NOTIFY defense_changed)
	Q_PROPERTY(int spirit READ spirit WRITE set_spirit NOTIFY spirit_changed)
	Q_PROPERTY(int agility READ agility WRITE set_agility NOTIFY agility_changed)
	Q_PROPERTY(bool transparent READ transparent WRITE set_transparent NOTIFY transparent_changed)
	Q_PROPERTY(int exp READ exp WRITE set_exp NOTIFY exp_changed)
	Q_PROPERTY(int gold READ gold WRITE set_gold NOTIFY gold_changed)
	Q_PROPERTY(int32_t drop_id READ drop_id CONSTANT)
	Q_PROPERTY(int drop_prob READ drop_prob WRITE set_drop_prob NOTIFY drop_prob_changed)
	Q_PROPERTY(bool critical_hit READ critical_hit WRITE set_critical_hit NOTIFY critical_hit_changed)
	Q_PROPERTY(int critical_hit_chance READ critical_hit_chance WRITE set_critical_hit_chance NOTIFY critical_hit_chance_changed)
	Q_PROPERTY(bool miss READ miss WRITE set_miss NOTIFY miss_changed)
	Q_PROPERTY(bool levitate READ levitate WRITE set_levitate NOTIFY levitate_changed)
	Q_PROPERTY(QVector<int> state_ranks READ state_ranks WRITE set_state_ranks NOTIFY state_ranks_changed)
	Q_PROPERTY(QVector<int> attribute_ranks READ attribute_ranks WRITE set_attribute_ranks NOTIFY attribute_ranks_changed)
	Q_PROPERTY(ArrayAdapter* actions READ actions CONSTANT)
	Q_PROPERTY(int32_t maniac_unarmed_animation READ maniac_unarmed_animation CONSTANT)
	Q_PROPERTY(int easyrpg_enemyai READ easyrpg_enemyai WRITE set_easyrpg_enemyai NOTIFY easyrpg_enemyai_changed)
	Q_PROPERTY(bool easyrpg_prevent_critical READ easyrpg_prevent_critical WRITE set_easyrpg_prevent_critical NOTIFY easyrpg_prevent_critical_changed)
	Q_PROPERTY(bool easyrpg_raise_evasion READ easyrpg_raise_evasion WRITE set_easyrpg_raise_evasion NOTIFY easyrpg_raise_evasion_changed)
	Q_PROPERTY(bool easyrpg_immune_to_attribute_downshifts READ easyrpg_immune_to_attribute_downshifts WRITE set_easyrpg_immune_to_attribute_downshifts NOTIFY easyrpg_immune_to_attribute_downshifts_changed)
	Q_PROPERTY(bool easyrpg_ignore_evasion READ easyrpg_ignore_evasion WRITE set_easyrpg_ignore_evasion NOTIFY easyrpg_ignore_evasion_changed)
	Q_PROPERTY(int easyrpg_hit READ easyrpg_hit WRITE set_easyrpg_hit NOTIFY easyrpg_hit_changed)
	Q_PROPERTY(QVector<bool> easyrpg_state_set READ easyrpg_state_set WRITE set_easyrpg_state_set NOTIFY easyrpg_state_set_changed)
	Q_PROPERTY(int easyrpg_state_chance READ easyrpg_state_chance WRITE set_easyrpg_state_chance NOTIFY easyrpg_state_chance_changed)
	Q_PROPERTY(QVector<bool> easyrpg_attribute_set READ easyrpg_attribute_set WRITE set_easyrpg_attribute_set NOTIFY easyrpg_attribute_set_changed)
	Q_PROPERTY(bool easyrpg_super_guard READ easyrpg_super_guard WRITE set_easyrpg_super_guard NOTIFY easyrpg_super_guard_changed)
	Q_PROPERTY(bool easyrpg_attack_all READ easyrpg_attack_all WRITE set_easyrpg_attack_all NOTIFY easyrpg_attack_all_changed)

public:
	Enemy(ProjectData& project, lcf::rpg::Enemy& data, QObject* parent = nullptr);

	lcf::rpg::Enemy& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	QString battler_name();
	void set_battler_name(const QString& new_battler_name);
	int battler_hue();
	void set_battler_hue(const int& new_battler_hue);
	int max_hp();
	void set_max_hp(const int& new_max_hp);
	int max_sp();
	void set_max_sp(const int& new_max_sp);
	int attack();
	void set_attack(const int& new_attack);
	int defense();
	void set_defense(const int& new_defense);
	int spirit();
	void set_spirit(const int& new_spirit);
	int agility();
	void set_agility(const int& new_agility);
	bool transparent();
	void set_transparent(const bool& new_transparent);
	int exp();
	void set_exp(const int& new_exp);
	int gold();
	void set_gold(const int& new_gold);
	int32_t drop_id();
	int drop_prob();
	void set_drop_prob(const int& new_drop_prob);
	bool critical_hit();
	void set_critical_hit(const bool& new_critical_hit);
	int critical_hit_chance();
	void set_critical_hit_chance(const int& new_critical_hit_chance);
	bool miss();
	void set_miss(const bool& new_miss);
	bool levitate();
	void set_levitate(const bool& new_levitate);
	QVector<int> state_ranks();
	void set_state_ranks(const QVector<int>& new_state_ranks);
	QVector<int> attribute_ranks();
	void set_attribute_ranks(const QVector<int>& new_attribute_ranks);
	ArrayAdapter* actions();
	int32_t maniac_unarmed_animation();
	int easyrpg_enemyai();
	void set_easyrpg_enemyai(const int& new_easyrpg_enemyai);
	bool easyrpg_prevent_critical();
	void set_easyrpg_prevent_critical(const bool& new_easyrpg_prevent_critical);
	bool easyrpg_raise_evasion();
	void set_easyrpg_raise_evasion(const bool& new_easyrpg_raise_evasion);
	bool easyrpg_immune_to_attribute_downshifts();
	void set_easyrpg_immune_to_attribute_downshifts(const bool& new_easyrpg_immune_to_attribute_downshifts);
	bool easyrpg_ignore_evasion();
	void set_easyrpg_ignore_evasion(const bool& new_easyrpg_ignore_evasion);
	int easyrpg_hit();
	void set_easyrpg_hit(const int& new_easyrpg_hit);
	QVector<bool> easyrpg_state_set();
	void set_easyrpg_state_set(const QVector<bool>& new_easyrpg_state_set);
	int easyrpg_state_chance();
	void set_easyrpg_state_chance(const int& new_easyrpg_state_chance);
	QVector<bool> easyrpg_attribute_set();
	void set_easyrpg_attribute_set(const QVector<bool>& new_easyrpg_attribute_set);
	bool easyrpg_super_guard();
	void set_easyrpg_super_guard(const bool& new_easyrpg_super_guard);
	bool easyrpg_attack_all();
	void set_easyrpg_attack_all(const bool& new_easyrpg_attack_all);

signals:
	void name_changed();
	void battler_name_changed();
	void battler_hue_changed();
	void max_hp_changed();
	void max_sp_changed();
	void attack_changed();
	void defense_changed();
	void spirit_changed();
	void agility_changed();
	void transparent_changed();
	void exp_changed();
	void gold_changed();
	void drop_prob_changed();
	void critical_hit_changed();
	void critical_hit_chance_changed();
	void miss_changed();
	void levitate_changed();
	void state_ranks_changed();
	void attribute_ranks_changed();
	void easyrpg_enemyai_changed();
	void easyrpg_prevent_critical_changed();
	void easyrpg_raise_evasion_changed();
	void easyrpg_immune_to_attribute_downshifts_changed();
	void easyrpg_ignore_evasion_changed();
	void easyrpg_hit_changed();
	void easyrpg_state_set_changed();
	void easyrpg_state_chance_changed();
	void easyrpg_attribute_set_changed();
	void easyrpg_super_guard_changed();
	void easyrpg_attack_all_changed();

protected:
	lcf::rpg::Enemy& m_data;
	ArrayAdapter* m_actions;
};
} // namespace Binding::Generated
