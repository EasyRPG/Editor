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
#include <lcf/rpg/enemyaction.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::EnemyAction class.
 * Exposes lcf::rpg::EnemyAction to QML.
 */
namespace Binding::Generated {
class EnemyAction : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(int32_t kind READ kind CONSTANT)
	Q_PROPERTY(int32_t basic READ basic CONSTANT)
	Q_PROPERTY(int32_t skill_id READ skill_id CONSTANT)
	Q_PROPERTY(int32_t enemy_id READ enemy_id CONSTANT)
	Q_PROPERTY(int32_t condition_type READ condition_type CONSTANT)
	Q_PROPERTY(int condition_param1 READ condition_param1 WRITE set_condition_param1 NOTIFY condition_param1_changed)
	Q_PROPERTY(int condition_param2 READ condition_param2 WRITE set_condition_param2 NOTIFY condition_param2_changed)
	Q_PROPERTY(int32_t switch_id READ switch_id CONSTANT)
	Q_PROPERTY(bool switch_on READ switch_on WRITE set_switch_on NOTIFY switch_on_changed)
	Q_PROPERTY(int32_t switch_on_id READ switch_on_id CONSTANT)
	Q_PROPERTY(bool switch_off READ switch_off WRITE set_switch_off NOTIFY switch_off_changed)
	Q_PROPERTY(int32_t switch_off_id READ switch_off_id CONSTANT)
	Q_PROPERTY(int rating READ rating WRITE set_rating NOTIFY rating_changed)

public:
	EnemyAction(ProjectData& project, lcf::rpg::EnemyAction& data, QObject* parent = nullptr);

	lcf::rpg::EnemyAction& data();
	int id();
	int32_t kind();
	int32_t basic();
	int32_t skill_id();
	int32_t enemy_id();
	int32_t condition_type();
	int condition_param1();
	void set_condition_param1(const int& new_condition_param1);
	int condition_param2();
	void set_condition_param2(const int& new_condition_param2);
	int32_t switch_id();
	bool switch_on();
	void set_switch_on(const bool& new_switch_on);
	int32_t switch_on_id();
	bool switch_off();
	void set_switch_off(const bool& new_switch_off);
	int32_t switch_off_id();
	int rating();
	void set_rating(const int& new_rating);

signals:
	void condition_param1_changed();
	void condition_param2_changed();
	void switch_on_changed();
	void switch_off_changed();
	void rating_changed();

protected:
	lcf::rpg::EnemyAction& m_data;
};
} // namespace Binding::Generated
