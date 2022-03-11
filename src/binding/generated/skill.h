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
#include <lcf/rpg/skill.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/battleranimationitemskill.h"
#include "binding/sound.h"

class ProjectData;

/**
 * Binding::Generated::Skill class.
 * Exposes lcf::rpg::Skill to QML.
 */
namespace Binding::Generated {
class Skill : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(QString description READ description WRITE set_description NOTIFY description_changed)
	Q_PROPERTY(QString using_message1 READ using_message1 WRITE set_using_message1 NOTIFY using_message1_changed)
	Q_PROPERTY(QString using_message2 READ using_message2 WRITE set_using_message2 NOTIFY using_message2_changed)
	Q_PROPERTY(int failure_message READ failure_message WRITE set_failure_message NOTIFY failure_message_changed)
	Q_PROPERTY(int type READ type WRITE set_type NOTIFY type_changed)
	Q_PROPERTY(int sp_type READ sp_type WRITE set_sp_type NOTIFY sp_type_changed)
	Q_PROPERTY(int sp_percent READ sp_percent WRITE set_sp_percent NOTIFY sp_percent_changed)
	Q_PROPERTY(int sp_cost READ sp_cost WRITE set_sp_cost NOTIFY sp_cost_changed)
	Q_PROPERTY(int scope READ scope WRITE set_scope NOTIFY scope_changed)
	Q_PROPERTY(int switch_id READ switch_id WRITE set_switch_id NOTIFY switch_id_changed)
	Q_PROPERTY(int animation_id READ animation_id WRITE set_animation_id NOTIFY animation_id_changed)
	Q_PROPERTY(Binding::Sound* sound_effect READ sound_effect CONSTANT)
	Q_PROPERTY(bool occasion_field READ occasion_field WRITE set_occasion_field NOTIFY occasion_field_changed)
	Q_PROPERTY(bool occasion_battle READ occasion_battle WRITE set_occasion_battle NOTIFY occasion_battle_changed)
	Q_PROPERTY(bool reverse_state_effect READ reverse_state_effect WRITE set_reverse_state_effect NOTIFY reverse_state_effect_changed)
	Q_PROPERTY(int physical_rate READ physical_rate WRITE set_physical_rate NOTIFY physical_rate_changed)
	Q_PROPERTY(int magical_rate READ magical_rate WRITE set_magical_rate NOTIFY magical_rate_changed)
	Q_PROPERTY(int variance READ variance WRITE set_variance NOTIFY variance_changed)
	Q_PROPERTY(int power READ power WRITE set_power NOTIFY power_changed)
	Q_PROPERTY(int hit READ hit WRITE set_hit NOTIFY hit_changed)
	Q_PROPERTY(bool affect_hp READ affect_hp WRITE set_affect_hp NOTIFY affect_hp_changed)
	Q_PROPERTY(bool affect_sp READ affect_sp WRITE set_affect_sp NOTIFY affect_sp_changed)
	Q_PROPERTY(bool affect_attack READ affect_attack WRITE set_affect_attack NOTIFY affect_attack_changed)
	Q_PROPERTY(bool affect_defense READ affect_defense WRITE set_affect_defense NOTIFY affect_defense_changed)
	Q_PROPERTY(bool affect_spirit READ affect_spirit WRITE set_affect_spirit NOTIFY affect_spirit_changed)
	Q_PROPERTY(bool affect_agility READ affect_agility WRITE set_affect_agility NOTIFY affect_agility_changed)
	Q_PROPERTY(bool absorb_damage READ absorb_damage WRITE set_absorb_damage NOTIFY absorb_damage_changed)
	Q_PROPERTY(bool ignore_defense READ ignore_defense WRITE set_ignore_defense NOTIFY ignore_defense_changed)
	Q_PROPERTY(QVector<bool> state_effects READ state_effects WRITE set_state_effects NOTIFY state_effects_changed)
	Q_PROPERTY(QVector<bool> attribute_effects READ attribute_effects WRITE set_attribute_effects NOTIFY attribute_effects_changed)
	Q_PROPERTY(bool affect_attr_defence READ affect_attr_defence WRITE set_affect_attr_defence NOTIFY affect_attr_defence_changed)
	Q_PROPERTY(int battler_animation READ battler_animation WRITE set_battler_animation NOTIFY battler_animation_changed)
	Q_PROPERTY(ArrayAdapter* battler_animation_data READ battler_animation_data CONSTANT)
	Q_PROPERTY(QString easyrpg_battle2k3_message READ easyrpg_battle2k3_message WRITE set_easyrpg_battle2k3_message NOTIFY easyrpg_battle2k3_message_changed)
	Q_PROPERTY(bool easyrpg_ignore_reflect READ easyrpg_ignore_reflect WRITE set_easyrpg_ignore_reflect NOTIFY easyrpg_ignore_reflect_changed)
	Q_PROPERTY(int easyrpg_state_hit READ easyrpg_state_hit WRITE set_easyrpg_state_hit NOTIFY easyrpg_state_hit_changed)
	Q_PROPERTY(int easyrpg_attribute_hit READ easyrpg_attribute_hit WRITE set_easyrpg_attribute_hit NOTIFY easyrpg_attribute_hit_changed)
	Q_PROPERTY(bool easyrpg_ignore_restrict_skill READ easyrpg_ignore_restrict_skill WRITE set_easyrpg_ignore_restrict_skill NOTIFY easyrpg_ignore_restrict_skill_changed)
	Q_PROPERTY(bool easyrpg_ignore_restrict_magic READ easyrpg_ignore_restrict_magic WRITE set_easyrpg_ignore_restrict_magic NOTIFY easyrpg_ignore_restrict_magic_changed)
	Q_PROPERTY(bool easyrpg_enable_stat_absorbing READ easyrpg_enable_stat_absorbing WRITE set_easyrpg_enable_stat_absorbing NOTIFY easyrpg_enable_stat_absorbing_changed)
	Q_PROPERTY(bool easyrpg_affected_by_evade_all_physical_attacks READ easyrpg_affected_by_evade_all_physical_attacks WRITE set_easyrpg_affected_by_evade_all_physical_attacks NOTIFY easyrpg_affected_by_evade_all_physical_attacks_changed)
	Q_PROPERTY(int easyrpg_critical_hit_chance READ easyrpg_critical_hit_chance WRITE set_easyrpg_critical_hit_chance NOTIFY easyrpg_critical_hit_chance_changed)
	Q_PROPERTY(bool easyrpg_affected_by_row_modifiers READ easyrpg_affected_by_row_modifiers WRITE set_easyrpg_affected_by_row_modifiers NOTIFY easyrpg_affected_by_row_modifiers_changed)
	Q_PROPERTY(int easyrpg_hp_type READ easyrpg_hp_type WRITE set_easyrpg_hp_type NOTIFY easyrpg_hp_type_changed)
	Q_PROPERTY(int easyrpg_hp_percent READ easyrpg_hp_percent WRITE set_easyrpg_hp_percent NOTIFY easyrpg_hp_percent_changed)
	Q_PROPERTY(int easyrpg_hp_cost READ easyrpg_hp_cost WRITE set_easyrpg_hp_cost NOTIFY easyrpg_hp_cost_changed)

public:
	Skill(ProjectData& project, lcf::rpg::Skill& data, QObject* parent = nullptr);

	lcf::rpg::Skill& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	QString description();
	void set_description(const QString& new_description);
	QString using_message1();
	void set_using_message1(const QString& new_using_message1);
	QString using_message2();
	void set_using_message2(const QString& new_using_message2);
	int failure_message();
	void set_failure_message(const int& new_failure_message);
	int type();
	void set_type(const int& new_type);
	int sp_type();
	void set_sp_type(const int& new_sp_type);
	int sp_percent();
	void set_sp_percent(const int& new_sp_percent);
	int sp_cost();
	void set_sp_cost(const int& new_sp_cost);
	int scope();
	void set_scope(const int& new_scope);
	int switch_id();
	void set_switch_id(const int& new_switch_id);
	int animation_id();
	void set_animation_id(const int& new_animation_id);
	Binding::Sound* sound_effect();
	bool occasion_field();
	void set_occasion_field(const bool& new_occasion_field);
	bool occasion_battle();
	void set_occasion_battle(const bool& new_occasion_battle);
	bool reverse_state_effect();
	void set_reverse_state_effect(const bool& new_reverse_state_effect);
	int physical_rate();
	void set_physical_rate(const int& new_physical_rate);
	int magical_rate();
	void set_magical_rate(const int& new_magical_rate);
	int variance();
	void set_variance(const int& new_variance);
	int power();
	void set_power(const int& new_power);
	int hit();
	void set_hit(const int& new_hit);
	bool affect_hp();
	void set_affect_hp(const bool& new_affect_hp);
	bool affect_sp();
	void set_affect_sp(const bool& new_affect_sp);
	bool affect_attack();
	void set_affect_attack(const bool& new_affect_attack);
	bool affect_defense();
	void set_affect_defense(const bool& new_affect_defense);
	bool affect_spirit();
	void set_affect_spirit(const bool& new_affect_spirit);
	bool affect_agility();
	void set_affect_agility(const bool& new_affect_agility);
	bool absorb_damage();
	void set_absorb_damage(const bool& new_absorb_damage);
	bool ignore_defense();
	void set_ignore_defense(const bool& new_ignore_defense);
	QVector<bool> state_effects();
	void set_state_effects(const QVector<bool>& new_state_effects);
	QVector<bool> attribute_effects();
	void set_attribute_effects(const QVector<bool>& new_attribute_effects);
	bool affect_attr_defence();
	void set_affect_attr_defence(const bool& new_affect_attr_defence);
	int battler_animation();
	void set_battler_animation(const int& new_battler_animation);
	ArrayAdapter* battler_animation_data();
	QString easyrpg_battle2k3_message();
	void set_easyrpg_battle2k3_message(const QString& new_easyrpg_battle2k3_message);
	bool easyrpg_ignore_reflect();
	void set_easyrpg_ignore_reflect(const bool& new_easyrpg_ignore_reflect);
	int easyrpg_state_hit();
	void set_easyrpg_state_hit(const int& new_easyrpg_state_hit);
	int easyrpg_attribute_hit();
	void set_easyrpg_attribute_hit(const int& new_easyrpg_attribute_hit);
	bool easyrpg_ignore_restrict_skill();
	void set_easyrpg_ignore_restrict_skill(const bool& new_easyrpg_ignore_restrict_skill);
	bool easyrpg_ignore_restrict_magic();
	void set_easyrpg_ignore_restrict_magic(const bool& new_easyrpg_ignore_restrict_magic);
	bool easyrpg_enable_stat_absorbing();
	void set_easyrpg_enable_stat_absorbing(const bool& new_easyrpg_enable_stat_absorbing);
	bool easyrpg_affected_by_evade_all_physical_attacks();
	void set_easyrpg_affected_by_evade_all_physical_attacks(const bool& new_easyrpg_affected_by_evade_all_physical_attacks);
	int easyrpg_critical_hit_chance();
	void set_easyrpg_critical_hit_chance(const int& new_easyrpg_critical_hit_chance);
	bool easyrpg_affected_by_row_modifiers();
	void set_easyrpg_affected_by_row_modifiers(const bool& new_easyrpg_affected_by_row_modifiers);
	int easyrpg_hp_type();
	void set_easyrpg_hp_type(const int& new_easyrpg_hp_type);
	int easyrpg_hp_percent();
	void set_easyrpg_hp_percent(const int& new_easyrpg_hp_percent);
	int easyrpg_hp_cost();
	void set_easyrpg_hp_cost(const int& new_easyrpg_hp_cost);

signals:
	void name_changed();
	void description_changed();
	void using_message1_changed();
	void using_message2_changed();
	void failure_message_changed();
	void type_changed();
	void sp_type_changed();
	void sp_percent_changed();
	void sp_cost_changed();
	void scope_changed();
	void switch_id_changed();
	void animation_id_changed();
	void occasion_field_changed();
	void occasion_battle_changed();
	void reverse_state_effect_changed();
	void physical_rate_changed();
	void magical_rate_changed();
	void variance_changed();
	void power_changed();
	void hit_changed();
	void affect_hp_changed();
	void affect_sp_changed();
	void affect_attack_changed();
	void affect_defense_changed();
	void affect_spirit_changed();
	void affect_agility_changed();
	void absorb_damage_changed();
	void ignore_defense_changed();
	void state_effects_changed();
	void attribute_effects_changed();
	void affect_attr_defence_changed();
	void battler_animation_changed();
	void easyrpg_battle2k3_message_changed();
	void easyrpg_ignore_reflect_changed();
	void easyrpg_state_hit_changed();
	void easyrpg_attribute_hit_changed();
	void easyrpg_ignore_restrict_skill_changed();
	void easyrpg_ignore_restrict_magic_changed();
	void easyrpg_enable_stat_absorbing_changed();
	void easyrpg_affected_by_evade_all_physical_attacks_changed();
	void easyrpg_critical_hit_chance_changed();
	void easyrpg_affected_by_row_modifiers_changed();
	void easyrpg_hp_type_changed();
	void easyrpg_hp_percent_changed();
	void easyrpg_hp_cost_changed();

protected:
	lcf::rpg::Skill& m_data;
	Binding::Sound* m_sound_effect;
	ArrayAdapter* m_battler_animation_data;
};
} // namespace Binding::Generated
