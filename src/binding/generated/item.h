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
#include <lcf/rpg/item.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/battleranimationitemskill.h"

class ProjectData;

/**
 * Binding::Generated::Item class.
 * Exposes lcf::rpg::Item to QML.
 */
namespace Binding::Generated {
class Item : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(QString description READ description WRITE set_description NOTIFY description_changed)
	Q_PROPERTY(int type READ type WRITE set_type NOTIFY type_changed)
	Q_PROPERTY(int price READ price WRITE set_price NOTIFY price_changed)
	Q_PROPERTY(int uses READ uses WRITE set_uses NOTIFY uses_changed)
	Q_PROPERTY(int atk_points1 READ atk_points1 WRITE set_atk_points1 NOTIFY atk_points1_changed)
	Q_PROPERTY(int def_points1 READ def_points1 WRITE set_def_points1 NOTIFY def_points1_changed)
	Q_PROPERTY(int spi_points1 READ spi_points1 WRITE set_spi_points1 NOTIFY spi_points1_changed)
	Q_PROPERTY(int agi_points1 READ agi_points1 WRITE set_agi_points1 NOTIFY agi_points1_changed)
	Q_PROPERTY(bool two_handed READ two_handed WRITE set_two_handed NOTIFY two_handed_changed)
	Q_PROPERTY(int sp_cost READ sp_cost WRITE set_sp_cost NOTIFY sp_cost_changed)
	Q_PROPERTY(int hit READ hit WRITE set_hit NOTIFY hit_changed)
	Q_PROPERTY(int critical_hit READ critical_hit WRITE set_critical_hit NOTIFY critical_hit_changed)
	Q_PROPERTY(int animation_id READ animation_id WRITE set_animation_id NOTIFY animation_id_changed)
	Q_PROPERTY(bool preemptive READ preemptive WRITE set_preemptive NOTIFY preemptive_changed)
	Q_PROPERTY(bool dual_attack READ dual_attack WRITE set_dual_attack NOTIFY dual_attack_changed)
	Q_PROPERTY(bool attack_all READ attack_all WRITE set_attack_all NOTIFY attack_all_changed)
	Q_PROPERTY(bool ignore_evasion READ ignore_evasion WRITE set_ignore_evasion NOTIFY ignore_evasion_changed)
	Q_PROPERTY(bool prevent_critical READ prevent_critical WRITE set_prevent_critical NOTIFY prevent_critical_changed)
	Q_PROPERTY(bool raise_evasion READ raise_evasion WRITE set_raise_evasion NOTIFY raise_evasion_changed)
	Q_PROPERTY(bool half_sp_cost READ half_sp_cost WRITE set_half_sp_cost NOTIFY half_sp_cost_changed)
	Q_PROPERTY(bool no_terrain_damage READ no_terrain_damage WRITE set_no_terrain_damage NOTIFY no_terrain_damage_changed)
	Q_PROPERTY(bool cursed READ cursed WRITE set_cursed NOTIFY cursed_changed)
	Q_PROPERTY(bool entire_party READ entire_party WRITE set_entire_party NOTIFY entire_party_changed)
	Q_PROPERTY(int recover_hp_rate READ recover_hp_rate WRITE set_recover_hp_rate NOTIFY recover_hp_rate_changed)
	Q_PROPERTY(int recover_hp READ recover_hp WRITE set_recover_hp NOTIFY recover_hp_changed)
	Q_PROPERTY(int recover_sp_rate READ recover_sp_rate WRITE set_recover_sp_rate NOTIFY recover_sp_rate_changed)
	Q_PROPERTY(int recover_sp READ recover_sp WRITE set_recover_sp NOTIFY recover_sp_changed)
	Q_PROPERTY(bool occasion_field1 READ occasion_field1 WRITE set_occasion_field1 NOTIFY occasion_field1_changed)
	Q_PROPERTY(bool ko_only READ ko_only WRITE set_ko_only NOTIFY ko_only_changed)
	Q_PROPERTY(int max_hp_points READ max_hp_points WRITE set_max_hp_points NOTIFY max_hp_points_changed)
	Q_PROPERTY(int max_sp_points READ max_sp_points WRITE set_max_sp_points NOTIFY max_sp_points_changed)
	Q_PROPERTY(int atk_points2 READ atk_points2 WRITE set_atk_points2 NOTIFY atk_points2_changed)
	Q_PROPERTY(int def_points2 READ def_points2 WRITE set_def_points2 NOTIFY def_points2_changed)
	Q_PROPERTY(int spi_points2 READ spi_points2 WRITE set_spi_points2 NOTIFY spi_points2_changed)
	Q_PROPERTY(int agi_points2 READ agi_points2 WRITE set_agi_points2 NOTIFY agi_points2_changed)
	Q_PROPERTY(int using_message READ using_message WRITE set_using_message NOTIFY using_message_changed)
	Q_PROPERTY(int skill_id READ skill_id WRITE set_skill_id NOTIFY skill_id_changed)
	Q_PROPERTY(int switch_id READ switch_id WRITE set_switch_id NOTIFY switch_id_changed)
	Q_PROPERTY(bool occasion_field2 READ occasion_field2 WRITE set_occasion_field2 NOTIFY occasion_field2_changed)
	Q_PROPERTY(bool occasion_battle READ occasion_battle WRITE set_occasion_battle NOTIFY occasion_battle_changed)
	Q_PROPERTY(QVector<bool> actor_set READ actor_set WRITE set_actor_set NOTIFY actor_set_changed)
	Q_PROPERTY(QVector<bool> state_set READ state_set WRITE set_state_set NOTIFY state_set_changed)
	Q_PROPERTY(QVector<bool> attribute_set READ attribute_set WRITE set_attribute_set NOTIFY attribute_set_changed)
	Q_PROPERTY(int state_chance READ state_chance WRITE set_state_chance NOTIFY state_chance_changed)
	Q_PROPERTY(bool reverse_state_effect READ reverse_state_effect WRITE set_reverse_state_effect NOTIFY reverse_state_effect_changed)
	Q_PROPERTY(int weapon_animation READ weapon_animation WRITE set_weapon_animation NOTIFY weapon_animation_changed)
	Q_PROPERTY(ArrayAdapter* animation_data READ animation_data CONSTANT)
	Q_PROPERTY(bool use_skill READ use_skill WRITE set_use_skill NOTIFY use_skill_changed)
	Q_PROPERTY(QVector<bool> class_set READ class_set WRITE set_class_set NOTIFY class_set_changed)
	Q_PROPERTY(int ranged_trajectory READ ranged_trajectory WRITE set_ranged_trajectory NOTIFY ranged_trajectory_changed)
	Q_PROPERTY(int ranged_target READ ranged_target WRITE set_ranged_target NOTIFY ranged_target_changed)
	Q_PROPERTY(QString easyrpg_using_message READ easyrpg_using_message WRITE set_easyrpg_using_message NOTIFY easyrpg_using_message_changed)
	Q_PROPERTY(int easyrpg_max_count READ easyrpg_max_count WRITE set_easyrpg_max_count NOTIFY easyrpg_max_count_changed)

public:
	Item(ProjectData& project, lcf::rpg::Item& data, QObject* parent = nullptr);

	lcf::rpg::Item& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	QString description();
	void set_description(const QString& new_description);
	int type();
	void set_type(const int& new_type);
	int price();
	void set_price(const int& new_price);
	int uses();
	void set_uses(const int& new_uses);
	int atk_points1();
	void set_atk_points1(const int& new_atk_points1);
	int def_points1();
	void set_def_points1(const int& new_def_points1);
	int spi_points1();
	void set_spi_points1(const int& new_spi_points1);
	int agi_points1();
	void set_agi_points1(const int& new_agi_points1);
	bool two_handed();
	void set_two_handed(const bool& new_two_handed);
	int sp_cost();
	void set_sp_cost(const int& new_sp_cost);
	int hit();
	void set_hit(const int& new_hit);
	int critical_hit();
	void set_critical_hit(const int& new_critical_hit);
	int animation_id();
	void set_animation_id(const int& new_animation_id);
	bool preemptive();
	void set_preemptive(const bool& new_preemptive);
	bool dual_attack();
	void set_dual_attack(const bool& new_dual_attack);
	bool attack_all();
	void set_attack_all(const bool& new_attack_all);
	bool ignore_evasion();
	void set_ignore_evasion(const bool& new_ignore_evasion);
	bool prevent_critical();
	void set_prevent_critical(const bool& new_prevent_critical);
	bool raise_evasion();
	void set_raise_evasion(const bool& new_raise_evasion);
	bool half_sp_cost();
	void set_half_sp_cost(const bool& new_half_sp_cost);
	bool no_terrain_damage();
	void set_no_terrain_damage(const bool& new_no_terrain_damage);
	bool cursed();
	void set_cursed(const bool& new_cursed);
	bool entire_party();
	void set_entire_party(const bool& new_entire_party);
	int recover_hp_rate();
	void set_recover_hp_rate(const int& new_recover_hp_rate);
	int recover_hp();
	void set_recover_hp(const int& new_recover_hp);
	int recover_sp_rate();
	void set_recover_sp_rate(const int& new_recover_sp_rate);
	int recover_sp();
	void set_recover_sp(const int& new_recover_sp);
	bool occasion_field1();
	void set_occasion_field1(const bool& new_occasion_field1);
	bool ko_only();
	void set_ko_only(const bool& new_ko_only);
	int max_hp_points();
	void set_max_hp_points(const int& new_max_hp_points);
	int max_sp_points();
	void set_max_sp_points(const int& new_max_sp_points);
	int atk_points2();
	void set_atk_points2(const int& new_atk_points2);
	int def_points2();
	void set_def_points2(const int& new_def_points2);
	int spi_points2();
	void set_spi_points2(const int& new_spi_points2);
	int agi_points2();
	void set_agi_points2(const int& new_agi_points2);
	int using_message();
	void set_using_message(const int& new_using_message);
	int skill_id();
	void set_skill_id(const int& new_skill_id);
	int switch_id();
	void set_switch_id(const int& new_switch_id);
	bool occasion_field2();
	void set_occasion_field2(const bool& new_occasion_field2);
	bool occasion_battle();
	void set_occasion_battle(const bool& new_occasion_battle);
	QVector<bool> actor_set();
	void set_actor_set(const QVector<bool>& new_actor_set);
	QVector<bool> state_set();
	void set_state_set(const QVector<bool>& new_state_set);
	QVector<bool> attribute_set();
	void set_attribute_set(const QVector<bool>& new_attribute_set);
	int state_chance();
	void set_state_chance(const int& new_state_chance);
	bool reverse_state_effect();
	void set_reverse_state_effect(const bool& new_reverse_state_effect);
	int weapon_animation();
	void set_weapon_animation(const int& new_weapon_animation);
	ArrayAdapter* animation_data();
	bool use_skill();
	void set_use_skill(const bool& new_use_skill);
	QVector<bool> class_set();
	void set_class_set(const QVector<bool>& new_class_set);
	int ranged_trajectory();
	void set_ranged_trajectory(const int& new_ranged_trajectory);
	int ranged_target();
	void set_ranged_target(const int& new_ranged_target);
	QString easyrpg_using_message();
	void set_easyrpg_using_message(const QString& new_easyrpg_using_message);
	int easyrpg_max_count();
	void set_easyrpg_max_count(const int& new_easyrpg_max_count);

signals:
	void name_changed();
	void description_changed();
	void type_changed();
	void price_changed();
	void uses_changed();
	void atk_points1_changed();
	void def_points1_changed();
	void spi_points1_changed();
	void agi_points1_changed();
	void two_handed_changed();
	void sp_cost_changed();
	void hit_changed();
	void critical_hit_changed();
	void animation_id_changed();
	void preemptive_changed();
	void dual_attack_changed();
	void attack_all_changed();
	void ignore_evasion_changed();
	void prevent_critical_changed();
	void raise_evasion_changed();
	void half_sp_cost_changed();
	void no_terrain_damage_changed();
	void cursed_changed();
	void entire_party_changed();
	void recover_hp_rate_changed();
	void recover_hp_changed();
	void recover_sp_rate_changed();
	void recover_sp_changed();
	void occasion_field1_changed();
	void ko_only_changed();
	void max_hp_points_changed();
	void max_sp_points_changed();
	void atk_points2_changed();
	void def_points2_changed();
	void spi_points2_changed();
	void agi_points2_changed();
	void using_message_changed();
	void skill_id_changed();
	void switch_id_changed();
	void occasion_field2_changed();
	void occasion_battle_changed();
	void actor_set_changed();
	void state_set_changed();
	void attribute_set_changed();
	void state_chance_changed();
	void reverse_state_effect_changed();
	void weapon_animation_changed();
	void use_skill_changed();
	void class_set_changed();
	void ranged_trajectory_changed();
	void ranged_target_changed();
	void easyrpg_using_message_changed();
	void easyrpg_max_count_changed();

protected:
	lcf::rpg::Item& m_data;
	ArrayAdapter* m_animation_data;
};
} // namespace Binding::Generated
