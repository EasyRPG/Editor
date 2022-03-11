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
#include <lcf/rpg/commonevent.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/eventcommand.h"

class ProjectData;

/**
 * Binding::Generated::CommonEvent class.
 * Exposes lcf::rpg::CommonEvent to QML.
 */
namespace Binding::Generated {
class CommonEvent : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(int trigger READ trigger WRITE set_trigger NOTIFY trigger_changed)
	Q_PROPERTY(bool switch_flag READ switch_flag WRITE set_switch_flag NOTIFY switch_flag_changed)
	Q_PROPERTY(int switch_id READ switch_id WRITE set_switch_id NOTIFY switch_id_changed)
	Q_PROPERTY(ArrayAdapter* event_commands READ event_commands CONSTANT)

public:
	CommonEvent(ProjectData& project, lcf::rpg::CommonEvent& data, QObject* parent = nullptr);

	lcf::rpg::CommonEvent& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	int trigger();
	void set_trigger(const int& new_trigger);
	bool switch_flag();
	void set_switch_flag(const bool& new_switch_flag);
	int switch_id();
	void set_switch_id(const int& new_switch_id);
	ArrayAdapter* event_commands();

signals:
	void name_changed();
	void trigger_changed();
	void switch_flag_changed();
	void switch_id_changed();

protected:
	lcf::rpg::CommonEvent& m_data;
	ArrayAdapter* m_event_commands;
};
} // namespace Binding::Generated
