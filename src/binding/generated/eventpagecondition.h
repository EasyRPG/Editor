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
	Q_PROPERTY(int32_t switch_a_id READ switch_a_id CONSTANT)
	Q_PROPERTY(int32_t switch_b_id READ switch_b_id CONSTANT)
	Q_PROPERTY(int32_t variable_id READ variable_id CONSTANT)
	Q_PROPERTY(int variable_value READ variable_value WRITE set_variable_value NOTIFY variable_value_changed)
	Q_PROPERTY(int32_t item_id READ item_id CONSTANT)
	Q_PROPERTY(int32_t actor_id READ actor_id CONSTANT)
	Q_PROPERTY(int timer_sec READ timer_sec WRITE set_timer_sec NOTIFY timer_sec_changed)
	Q_PROPERTY(int timer2_sec READ timer2_sec WRITE set_timer2_sec NOTIFY timer2_sec_changed)
	Q_PROPERTY(int32_t compare_operator READ compare_operator CONSTANT)

public:
	EventPageCondition(ProjectData& project, lcf::rpg::EventPageCondition& data, QObject* parent = nullptr);

	lcf::rpg::EventPageCondition& data();
	int32_t switch_a_id();
	int32_t switch_b_id();
	int32_t variable_id();
	int variable_value();
	void set_variable_value(const int& new_variable_value);
	int32_t item_id();
	int32_t actor_id();
	int timer_sec();
	void set_timer_sec(const int& new_timer_sec);
	int timer2_sec();
	void set_timer2_sec(const int& new_timer2_sec);
	int32_t compare_operator();

signals:
	void variable_value_changed();
	void timer_sec_changed();
	void timer2_sec_changed();

protected:
	lcf::rpg::EventPageCondition& m_data;
};
} // namespace Binding::Generated
