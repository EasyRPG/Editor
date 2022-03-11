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
#include <lcf/rpg/saveactor.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::SaveActor class.
 * Exposes lcf::rpg::SaveActor to QML.
 */
namespace Binding::Generated {
class SaveActor : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(QString title READ title WRITE set_title NOTIFY title_changed)
	Q_PROPERTY(QString sprite_name READ sprite_name WRITE set_sprite_name NOTIFY sprite_name_changed)
	Q_PROPERTY(int sprite_id READ sprite_id WRITE set_sprite_id NOTIFY sprite_id_changed)
	Q_PROPERTY(int transparency READ transparency WRITE set_transparency NOTIFY transparency_changed)
	Q_PROPERTY(QString face_name READ face_name WRITE set_face_name NOTIFY face_name_changed)
	Q_PROPERTY(int face_id READ face_id WRITE set_face_id NOTIFY face_id_changed)
	Q_PROPERTY(int level READ level WRITE set_level NOTIFY level_changed)
	Q_PROPERTY(int exp READ exp WRITE set_exp NOTIFY exp_changed)
	Q_PROPERTY(int hp_mod READ hp_mod WRITE set_hp_mod NOTIFY hp_mod_changed)
	Q_PROPERTY(int sp_mod READ sp_mod WRITE set_sp_mod NOTIFY sp_mod_changed)
	Q_PROPERTY(int attack_mod READ attack_mod WRITE set_attack_mod NOTIFY attack_mod_changed)
	Q_PROPERTY(int defense_mod READ defense_mod WRITE set_defense_mod NOTIFY defense_mod_changed)
	Q_PROPERTY(int spirit_mod READ spirit_mod WRITE set_spirit_mod NOTIFY spirit_mod_changed)
	Q_PROPERTY(int agility_mod READ agility_mod WRITE set_agility_mod NOTIFY agility_mod_changed)
	Q_PROPERTY(QVector<int> skills READ skills WRITE set_skills NOTIFY skills_changed)
	Q_PROPERTY(QVector<int> equipped READ equipped WRITE set_equipped NOTIFY equipped_changed)
	Q_PROPERTY(int current_hp READ current_hp WRITE set_current_hp NOTIFY current_hp_changed)
	Q_PROPERTY(int current_sp READ current_sp WRITE set_current_sp NOTIFY current_sp_changed)
	Q_PROPERTY(QVector<int> battle_commands READ battle_commands WRITE set_battle_commands NOTIFY battle_commands_changed)
	Q_PROPERTY(QVector<int> status READ status WRITE set_status NOTIFY status_changed)
	Q_PROPERTY(bool changed_battle_commands READ changed_battle_commands WRITE set_changed_battle_commands NOTIFY changed_battle_commands_changed)
	Q_PROPERTY(int class_id READ class_id WRITE set_class_id NOTIFY class_id_changed)
	Q_PROPERTY(int row READ row WRITE set_row NOTIFY row_changed)
	Q_PROPERTY(bool two_weapon READ two_weapon WRITE set_two_weapon NOTIFY two_weapon_changed)
	Q_PROPERTY(bool lock_equipment READ lock_equipment WRITE set_lock_equipment NOTIFY lock_equipment_changed)
	Q_PROPERTY(bool auto_battle READ auto_battle WRITE set_auto_battle NOTIFY auto_battle_changed)
	Q_PROPERTY(bool super_guard READ super_guard WRITE set_super_guard NOTIFY super_guard_changed)
	Q_PROPERTY(int battler_animation READ battler_animation WRITE set_battler_animation NOTIFY battler_animation_changed)

public:
	SaveActor(ProjectData& project, lcf::rpg::SaveActor& data, QObject* parent = nullptr);

	lcf::rpg::SaveActor& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	QString title();
	void set_title(const QString& new_title);
	QString sprite_name();
	void set_sprite_name(const QString& new_sprite_name);
	int sprite_id();
	void set_sprite_id(const int& new_sprite_id);
	int transparency();
	void set_transparency(const int& new_transparency);
	QString face_name();
	void set_face_name(const QString& new_face_name);
	int face_id();
	void set_face_id(const int& new_face_id);
	int level();
	void set_level(const int& new_level);
	int exp();
	void set_exp(const int& new_exp);
	int hp_mod();
	void set_hp_mod(const int& new_hp_mod);
	int sp_mod();
	void set_sp_mod(const int& new_sp_mod);
	int attack_mod();
	void set_attack_mod(const int& new_attack_mod);
	int defense_mod();
	void set_defense_mod(const int& new_defense_mod);
	int spirit_mod();
	void set_spirit_mod(const int& new_spirit_mod);
	int agility_mod();
	void set_agility_mod(const int& new_agility_mod);
	QVector<int> skills();
	void set_skills(const QVector<int>& new_skills);
	QVector<int> equipped();
	void set_equipped(const QVector<int>& new_equipped);
	int current_hp();
	void set_current_hp(const int& new_current_hp);
	int current_sp();
	void set_current_sp(const int& new_current_sp);
	QVector<int> battle_commands();
	void set_battle_commands(const QVector<int>& new_battle_commands);
	QVector<int> status();
	void set_status(const QVector<int>& new_status);
	bool changed_battle_commands();
	void set_changed_battle_commands(const bool& new_changed_battle_commands);
	int class_id();
	void set_class_id(const int& new_class_id);
	int row();
	void set_row(const int& new_row);
	bool two_weapon();
	void set_two_weapon(const bool& new_two_weapon);
	bool lock_equipment();
	void set_lock_equipment(const bool& new_lock_equipment);
	bool auto_battle();
	void set_auto_battle(const bool& new_auto_battle);
	bool super_guard();
	void set_super_guard(const bool& new_super_guard);
	int battler_animation();
	void set_battler_animation(const int& new_battler_animation);

signals:
	void name_changed();
	void title_changed();
	void sprite_name_changed();
	void sprite_id_changed();
	void transparency_changed();
	void face_name_changed();
	void face_id_changed();
	void level_changed();
	void exp_changed();
	void hp_mod_changed();
	void sp_mod_changed();
	void attack_mod_changed();
	void defense_mod_changed();
	void spirit_mod_changed();
	void agility_mod_changed();
	void skills_changed();
	void equipped_changed();
	void current_hp_changed();
	void current_sp_changed();
	void battle_commands_changed();
	void status_changed();
	void changed_battle_commands_changed();
	void class_id_changed();
	void row_changed();
	void two_weapon_changed();
	void lock_equipment_changed();
	void auto_battle_changed();
	void super_guard_changed();
	void battler_animation_changed();

protected:
	lcf::rpg::SaveActor& m_data;
};
} // namespace Binding::Generated
