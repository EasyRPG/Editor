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
#include <lcf/rpg/class.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/parameters.h"
#include "binding/learning.h"

class ProjectData;

/**
 * Binding::Generated::Class class.
 * Exposes lcf::rpg::Class to QML.
 */
namespace Binding::Generated {
class Class : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(bool two_weapon READ two_weapon WRITE set_two_weapon NOTIFY two_weapon_changed)
	Q_PROPERTY(bool lock_equipment READ lock_equipment WRITE set_lock_equipment NOTIFY lock_equipment_changed)
	Q_PROPERTY(bool auto_battle READ auto_battle WRITE set_auto_battle NOTIFY auto_battle_changed)
	Q_PROPERTY(bool super_guard READ super_guard WRITE set_super_guard NOTIFY super_guard_changed)
	Q_PROPERTY(Binding::Parameters* parameters READ parameters CONSTANT)
	Q_PROPERTY(int exp_base READ exp_base WRITE set_exp_base NOTIFY exp_base_changed)
	Q_PROPERTY(int exp_inflation READ exp_inflation WRITE set_exp_inflation NOTIFY exp_inflation_changed)
	Q_PROPERTY(int exp_correction READ exp_correction WRITE set_exp_correction NOTIFY exp_correction_changed)
	Q_PROPERTY(int battler_animation READ battler_animation WRITE set_battler_animation NOTIFY battler_animation_changed)
	Q_PROPERTY(ArrayAdapter* skills READ skills CONSTANT)
	Q_PROPERTY(QVector<int> state_ranks READ state_ranks WRITE set_state_ranks NOTIFY state_ranks_changed)
	Q_PROPERTY(QVector<int> attribute_ranks READ attribute_ranks WRITE set_attribute_ranks NOTIFY attribute_ranks_changed)
	Q_PROPERTY(QVector<int> battle_commands READ battle_commands WRITE set_battle_commands NOTIFY battle_commands_changed)

public:
	Class(ProjectData& project, lcf::rpg::Class& data, QObject* parent = nullptr);

	lcf::rpg::Class& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	bool two_weapon();
	void set_two_weapon(const bool& new_two_weapon);
	bool lock_equipment();
	void set_lock_equipment(const bool& new_lock_equipment);
	bool auto_battle();
	void set_auto_battle(const bool& new_auto_battle);
	bool super_guard();
	void set_super_guard(const bool& new_super_guard);
	Binding::Parameters* parameters();
	int exp_base();
	void set_exp_base(const int& new_exp_base);
	int exp_inflation();
	void set_exp_inflation(const int& new_exp_inflation);
	int exp_correction();
	void set_exp_correction(const int& new_exp_correction);
	int battler_animation();
	void set_battler_animation(const int& new_battler_animation);
	ArrayAdapter* skills();
	QVector<int> state_ranks();
	void set_state_ranks(const QVector<int>& new_state_ranks);
	QVector<int> attribute_ranks();
	void set_attribute_ranks(const QVector<int>& new_attribute_ranks);
	QVector<int> battle_commands();
	void set_battle_commands(const QVector<int>& new_battle_commands);

signals:
	void name_changed();
	void two_weapon_changed();
	void lock_equipment_changed();
	void auto_battle_changed();
	void super_guard_changed();
	void exp_base_changed();
	void exp_inflation_changed();
	void exp_correction_changed();
	void battler_animation_changed();
	void state_ranks_changed();
	void attribute_ranks_changed();
	void battle_commands_changed();

protected:
	lcf::rpg::Class& m_data;
	Binding::Parameters* m_parameters;
	ArrayAdapter* m_skills;
};
} // namespace Binding::Generated
