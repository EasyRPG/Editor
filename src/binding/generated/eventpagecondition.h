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
#include <lcf/rpg/eventpagecondition.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::EventPageCondition class.
 * Exposes lcf::rpg::EventPageCondition to QML.
 */
namespace Binding::Generated {
class EventPageCondition : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int switch_a_id READ switch_a_id WRITE set_switch_a_id NOTIFY switch_a_id_changed)
	Q_PROPERTY(int switch_b_id READ switch_b_id WRITE set_switch_b_id NOTIFY switch_b_id_changed)
	Q_PROPERTY(int variable_id READ variable_id WRITE set_variable_id NOTIFY variable_id_changed)
	Q_PROPERTY(int variable_value READ variable_value WRITE set_variable_value NOTIFY variable_value_changed)
	Q_PROPERTY(int item_id READ item_id WRITE set_item_id NOTIFY item_id_changed)
	Q_PROPERTY(int actor_id READ actor_id WRITE set_actor_id NOTIFY actor_id_changed)
	Q_PROPERTY(int timer_sec READ timer_sec WRITE set_timer_sec NOTIFY timer_sec_changed)
	Q_PROPERTY(int timer2_sec READ timer2_sec WRITE set_timer2_sec NOTIFY timer2_sec_changed)
	Q_PROPERTY(int compare_operator READ compare_operator WRITE set_compare_operator NOTIFY compare_operator_changed)

public:
	EventPageCondition(ProjectData& project, lcf::rpg::EventPageCondition& data, QObject* parent = nullptr);

	lcf::rpg::EventPageCondition& data();
	int switch_a_id();
	void set_switch_a_id(const int& new_switch_a_id);
	int switch_b_id();
	void set_switch_b_id(const int& new_switch_b_id);
	int variable_id();
	void set_variable_id(const int& new_variable_id);
	int variable_value();
	void set_variable_value(const int& new_variable_value);
	int item_id();
	void set_item_id(const int& new_item_id);
	int actor_id();
	void set_actor_id(const int& new_actor_id);
	int timer_sec();
	void set_timer_sec(const int& new_timer_sec);
	int timer2_sec();
	void set_timer2_sec(const int& new_timer2_sec);
	int compare_operator();
	void set_compare_operator(const int& new_compare_operator);

signals:
	void switch_a_id_changed();
	void switch_b_id_changed();
	void variable_id_changed();
	void variable_value_changed();
	void item_id_changed();
	void actor_id_changed();
	void timer_sec_changed();
	void timer2_sec_changed();
	void compare_operator_changed();

protected:
	lcf::rpg::EventPageCondition& m_data;
};
} // namespace Binding::Generated
