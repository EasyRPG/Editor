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
#include "skill.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Skill::Skill(ProjectData& project, lcf::rpg::Skill& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_sound_effect = new Binding::Sound(m_project, m_data.sound_effect, this);
		for (auto& var: m_data.battler_animation_data) {
			m_battler_animation_data.push_back(new Binding::BattlerAnimationItemSkill(m_project, var, this));
		}
	}
	int Skill::id() {
		return m_data.ID;
	}
	QString Skill::name() {
		return ToQString(m_data.name);
	}
	void Skill::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	QString Skill::description() {
		return ToQString(m_data.description);
	}
	void Skill::set_description(const QString& new_description) {
		if (ToQString(m_data.description) == new_description)
			return;
		m_data.description = ToDBString(new_description);
		emit description_changed();
	}

	QString Skill::using_message1() {
		return ToQString(m_data.using_message1);
	}
	void Skill::set_using_message1(const QString& new_using_message1) {
		if (ToQString(m_data.using_message1) == new_using_message1)
			return;
		m_data.using_message1 = ToDBString(new_using_message1);
		emit using_message1_changed();
	}

	QString Skill::using_message2() {
		return ToQString(m_data.using_message2);
	}
	void Skill::set_using_message2(const QString& new_using_message2) {
		if (ToQString(m_data.using_message2) == new_using_message2)
			return;
		m_data.using_message2 = ToDBString(new_using_message2);
		emit using_message2_changed();
	}

	int Skill::failure_message() {
		return m_data.failure_message;
	}
	void Skill::set_failure_message(const int& new_failure_message) {
		if (m_data.failure_message == new_failure_message)
			return;
		m_data.failure_message = new_failure_message;
		emit failure_message_changed();
	}

	int32_t Skill::type() {
		return m_data.type;
	}

	int32_t Skill::sp_type() {
		return m_data.sp_type;
	}

	int Skill::sp_percent() {
		return m_data.sp_percent;
	}
	void Skill::set_sp_percent(const int& new_sp_percent) {
		if (m_data.sp_percent == new_sp_percent)
			return;
		m_data.sp_percent = new_sp_percent;
		emit sp_percent_changed();
	}

	int Skill::sp_cost() {
		return m_data.sp_cost;
	}
	void Skill::set_sp_cost(const int& new_sp_cost) {
		if (m_data.sp_cost == new_sp_cost)
			return;
		m_data.sp_cost = new_sp_cost;
		emit sp_cost_changed();
	}

	int32_t Skill::scope() {
		return m_data.scope;
	}

	int32_t Skill::switch_id() {
		return m_data.switch_id;
	}

	int32_t Skill::animation_id() {
		return m_data.animation_id;
	}

	Binding::Sound* Skill::sound_effect() {
		return m_sound_effect;
	}

	bool Skill::occasion_field() {
		return m_data.occasion_field;
	}
	void Skill::set_occasion_field(const bool& new_occasion_field) {
		if (m_data.occasion_field == new_occasion_field)
			return;
		m_data.occasion_field = new_occasion_field;
		emit occasion_field_changed();
	}

	bool Skill::occasion_battle() {
		return m_data.occasion_battle;
	}
	void Skill::set_occasion_battle(const bool& new_occasion_battle) {
		if (m_data.occasion_battle == new_occasion_battle)
			return;
		m_data.occasion_battle = new_occasion_battle;
		emit occasion_battle_changed();
	}

	bool Skill::reverse_state_effect() {
		return m_data.reverse_state_effect;
	}
	void Skill::set_reverse_state_effect(const bool& new_reverse_state_effect) {
		if (m_data.reverse_state_effect == new_reverse_state_effect)
			return;
		m_data.reverse_state_effect = new_reverse_state_effect;
		emit reverse_state_effect_changed();
	}

	int Skill::physical_rate() {
		return m_data.physical_rate;
	}
	void Skill::set_physical_rate(const int& new_physical_rate) {
		if (m_data.physical_rate == new_physical_rate)
			return;
		m_data.physical_rate = new_physical_rate;
		emit physical_rate_changed();
	}

	int Skill::magical_rate() {
		return m_data.magical_rate;
	}
	void Skill::set_magical_rate(const int& new_magical_rate) {
		if (m_data.magical_rate == new_magical_rate)
			return;
		m_data.magical_rate = new_magical_rate;
		emit magical_rate_changed();
	}

	int Skill::variance() {
		return m_data.variance;
	}
	void Skill::set_variance(const int& new_variance) {
		if (m_data.variance == new_variance)
			return;
		m_data.variance = new_variance;
		emit variance_changed();
	}

	int Skill::power() {
		return m_data.power;
	}
	void Skill::set_power(const int& new_power) {
		if (m_data.power == new_power)
			return;
		m_data.power = new_power;
		emit power_changed();
	}

	int Skill::hit() {
		return m_data.hit;
	}
	void Skill::set_hit(const int& new_hit) {
		if (m_data.hit == new_hit)
			return;
		m_data.hit = new_hit;
		emit hit_changed();
	}

	bool Skill::affect_hp() {
		return m_data.affect_hp;
	}
	void Skill::set_affect_hp(const bool& new_affect_hp) {
		if (m_data.affect_hp == new_affect_hp)
			return;
		m_data.affect_hp = new_affect_hp;
		emit affect_hp_changed();
	}

	bool Skill::affect_sp() {
		return m_data.affect_sp;
	}
	void Skill::set_affect_sp(const bool& new_affect_sp) {
		if (m_data.affect_sp == new_affect_sp)
			return;
		m_data.affect_sp = new_affect_sp;
		emit affect_sp_changed();
	}

	bool Skill::affect_attack() {
		return m_data.affect_attack;
	}
	void Skill::set_affect_attack(const bool& new_affect_attack) {
		if (m_data.affect_attack == new_affect_attack)
			return;
		m_data.affect_attack = new_affect_attack;
		emit affect_attack_changed();
	}

	bool Skill::affect_defense() {
		return m_data.affect_defense;
	}
	void Skill::set_affect_defense(const bool& new_affect_defense) {
		if (m_data.affect_defense == new_affect_defense)
			return;
		m_data.affect_defense = new_affect_defense;
		emit affect_defense_changed();
	}

	bool Skill::affect_spirit() {
		return m_data.affect_spirit;
	}
	void Skill::set_affect_spirit(const bool& new_affect_spirit) {
		if (m_data.affect_spirit == new_affect_spirit)
			return;
		m_data.affect_spirit = new_affect_spirit;
		emit affect_spirit_changed();
	}

	bool Skill::affect_agility() {
		return m_data.affect_agility;
	}
	void Skill::set_affect_agility(const bool& new_affect_agility) {
		if (m_data.affect_agility == new_affect_agility)
			return;
		m_data.affect_agility = new_affect_agility;
		emit affect_agility_changed();
	}

	bool Skill::absorb_damage() {
		return m_data.absorb_damage;
	}
	void Skill::set_absorb_damage(const bool& new_absorb_damage) {
		if (m_data.absorb_damage == new_absorb_damage)
			return;
		m_data.absorb_damage = new_absorb_damage;
		emit absorb_damage_changed();
	}

	bool Skill::ignore_defense() {
		return m_data.ignore_defense;
	}
	void Skill::set_ignore_defense(const bool& new_ignore_defense) {
		if (m_data.ignore_defense == new_ignore_defense)
			return;
		m_data.ignore_defense = new_ignore_defense;
		emit ignore_defense_changed();
	}

	QVector<bool> Skill::state_effects() {
		return QVector<bool>(m_data.state_effects.begin(), m_data.state_effects.end());
	}
	void Skill::set_state_effects(const QVector<bool>& new_state_effects) {
		if (QVector<bool>(m_data.state_effects.begin(), m_data.state_effects.end()) == new_state_effects)
			return;
		m_data.state_effects = decltype(m_data.state_effects)(new_state_effects.begin(), new_state_effects.end());
		emit state_effects_changed();
	}

	QVector<bool> Skill::attribute_effects() {
		return QVector<bool>(m_data.attribute_effects.begin(), m_data.attribute_effects.end());
	}
	void Skill::set_attribute_effects(const QVector<bool>& new_attribute_effects) {
		if (QVector<bool>(m_data.attribute_effects.begin(), m_data.attribute_effects.end()) == new_attribute_effects)
			return;
		m_data.attribute_effects = decltype(m_data.attribute_effects)(new_attribute_effects.begin(), new_attribute_effects.end());
		emit attribute_effects_changed();
	}

	bool Skill::affect_attr_defence() {
		return m_data.affect_attr_defence;
	}
	void Skill::set_affect_attr_defence(const bool& new_affect_attr_defence) {
		if (m_data.affect_attr_defence == new_affect_attr_defence)
			return;
		m_data.affect_attr_defence = new_affect_attr_defence;
		emit affect_attr_defence_changed();
	}

	int32_t Skill::battler_animation() {
		return m_data.battler_animation;
	}

	QVector<Binding::BattlerAnimationItemSkill*>& Skill::battler_animation_data() {
		return m_battler_animation_data;
	}

	QString Skill::easyrpg_battle2k3_message() {
		return ToQString(m_data.easyrpg_battle2k3_message);
	}
	void Skill::set_easyrpg_battle2k3_message(const QString& new_easyrpg_battle2k3_message) {
		if (ToQString(m_data.easyrpg_battle2k3_message) == new_easyrpg_battle2k3_message)
			return;
		m_data.easyrpg_battle2k3_message = ToDBString(new_easyrpg_battle2k3_message);
		emit easyrpg_battle2k3_message_changed();
	}

	bool Skill::easyrpg_ignore_reflect() {
		return m_data.easyrpg_ignore_reflect;
	}
	void Skill::set_easyrpg_ignore_reflect(const bool& new_easyrpg_ignore_reflect) {
		if (m_data.easyrpg_ignore_reflect == new_easyrpg_ignore_reflect)
			return;
		m_data.easyrpg_ignore_reflect = new_easyrpg_ignore_reflect;
		emit easyrpg_ignore_reflect_changed();
	}

	int Skill::easyrpg_state_hit() {
		return m_data.easyrpg_state_hit;
	}
	void Skill::set_easyrpg_state_hit(const int& new_easyrpg_state_hit) {
		if (m_data.easyrpg_state_hit == new_easyrpg_state_hit)
			return;
		m_data.easyrpg_state_hit = new_easyrpg_state_hit;
		emit easyrpg_state_hit_changed();
	}

	int Skill::easyrpg_attribute_hit() {
		return m_data.easyrpg_attribute_hit;
	}
	void Skill::set_easyrpg_attribute_hit(const int& new_easyrpg_attribute_hit) {
		if (m_data.easyrpg_attribute_hit == new_easyrpg_attribute_hit)
			return;
		m_data.easyrpg_attribute_hit = new_easyrpg_attribute_hit;
		emit easyrpg_attribute_hit_changed();
	}

	bool Skill::easyrpg_ignore_restrict_skill() {
		return m_data.easyrpg_ignore_restrict_skill;
	}
	void Skill::set_easyrpg_ignore_restrict_skill(const bool& new_easyrpg_ignore_restrict_skill) {
		if (m_data.easyrpg_ignore_restrict_skill == new_easyrpg_ignore_restrict_skill)
			return;
		m_data.easyrpg_ignore_restrict_skill = new_easyrpg_ignore_restrict_skill;
		emit easyrpg_ignore_restrict_skill_changed();
	}

	bool Skill::easyrpg_ignore_restrict_magic() {
		return m_data.easyrpg_ignore_restrict_magic;
	}
	void Skill::set_easyrpg_ignore_restrict_magic(const bool& new_easyrpg_ignore_restrict_magic) {
		if (m_data.easyrpg_ignore_restrict_magic == new_easyrpg_ignore_restrict_magic)
			return;
		m_data.easyrpg_ignore_restrict_magic = new_easyrpg_ignore_restrict_magic;
		emit easyrpg_ignore_restrict_magic_changed();
	}

	bool Skill::easyrpg_enable_stat_absorbing() {
		return m_data.easyrpg_enable_stat_absorbing;
	}
	void Skill::set_easyrpg_enable_stat_absorbing(const bool& new_easyrpg_enable_stat_absorbing) {
		if (m_data.easyrpg_enable_stat_absorbing == new_easyrpg_enable_stat_absorbing)
			return;
		m_data.easyrpg_enable_stat_absorbing = new_easyrpg_enable_stat_absorbing;
		emit easyrpg_enable_stat_absorbing_changed();
	}

	bool Skill::easyrpg_affected_by_evade_all_physical_attacks() {
		return m_data.easyrpg_affected_by_evade_all_physical_attacks;
	}
	void Skill::set_easyrpg_affected_by_evade_all_physical_attacks(const bool& new_easyrpg_affected_by_evade_all_physical_attacks) {
		if (m_data.easyrpg_affected_by_evade_all_physical_attacks == new_easyrpg_affected_by_evade_all_physical_attacks)
			return;
		m_data.easyrpg_affected_by_evade_all_physical_attacks = new_easyrpg_affected_by_evade_all_physical_attacks;
		emit easyrpg_affected_by_evade_all_physical_attacks_changed();
	}

	int Skill::easyrpg_critical_hit_chance() {
		return m_data.easyrpg_critical_hit_chance;
	}
	void Skill::set_easyrpg_critical_hit_chance(const int& new_easyrpg_critical_hit_chance) {
		if (m_data.easyrpg_critical_hit_chance == new_easyrpg_critical_hit_chance)
			return;
		m_data.easyrpg_critical_hit_chance = new_easyrpg_critical_hit_chance;
		emit easyrpg_critical_hit_chance_changed();
	}

	bool Skill::easyrpg_affected_by_row_modifiers() {
		return m_data.easyrpg_affected_by_row_modifiers;
	}
	void Skill::set_easyrpg_affected_by_row_modifiers(const bool& new_easyrpg_affected_by_row_modifiers) {
		if (m_data.easyrpg_affected_by_row_modifiers == new_easyrpg_affected_by_row_modifiers)
			return;
		m_data.easyrpg_affected_by_row_modifiers = new_easyrpg_affected_by_row_modifiers;
		emit easyrpg_affected_by_row_modifiers_changed();
	}

	int32_t Skill::easyrpg_hp_type() {
		return m_data.easyrpg_hp_type;
	}

	int Skill::easyrpg_hp_percent() {
		return m_data.easyrpg_hp_percent;
	}
	void Skill::set_easyrpg_hp_percent(const int& new_easyrpg_hp_percent) {
		if (m_data.easyrpg_hp_percent == new_easyrpg_hp_percent)
			return;
		m_data.easyrpg_hp_percent = new_easyrpg_hp_percent;
		emit easyrpg_hp_percent_changed();
	}

	int Skill::easyrpg_hp_cost() {
		return m_data.easyrpg_hp_cost;
	}
	void Skill::set_easyrpg_hp_cost(const int& new_easyrpg_hp_cost) {
		if (m_data.easyrpg_hp_cost == new_easyrpg_hp_cost)
			return;
		m_data.easyrpg_hp_cost = new_easyrpg_hp_cost;
		emit easyrpg_hp_cost_changed();
	}

} // namespace Binding::Generated
