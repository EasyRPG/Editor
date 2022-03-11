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
#include <lcf/rpg/eventpage.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/eventpagecondition.h"
#include "binding/eventcommand.h"
#include "binding/moveroute.h"

class ProjectData;

/**
 * Binding::Generated::EventPage class.
 * Exposes lcf::rpg::EventPage to QML.
 */
namespace Binding::Generated {
class EventPage : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(Binding::EventPageCondition* condition READ condition CONSTANT)
	Q_PROPERTY(QString character_name READ character_name WRITE set_character_name NOTIFY character_name_changed)
	Q_PROPERTY(int character_index READ character_index WRITE set_character_index NOTIFY character_index_changed)
	Q_PROPERTY(int character_direction READ character_direction WRITE set_character_direction NOTIFY character_direction_changed)
	Q_PROPERTY(int character_pattern READ character_pattern WRITE set_character_pattern NOTIFY character_pattern_changed)
	Q_PROPERTY(bool translucent READ translucent WRITE set_translucent NOTIFY translucent_changed)
	Q_PROPERTY(int move_type READ move_type WRITE set_move_type NOTIFY move_type_changed)
	Q_PROPERTY(int move_frequency READ move_frequency WRITE set_move_frequency NOTIFY move_frequency_changed)
	Q_PROPERTY(int trigger READ trigger WRITE set_trigger NOTIFY trigger_changed)
	Q_PROPERTY(int layer READ layer WRITE set_layer NOTIFY layer_changed)
	Q_PROPERTY(bool overlap_forbidden READ overlap_forbidden WRITE set_overlap_forbidden NOTIFY overlap_forbidden_changed)
	Q_PROPERTY(int animation_type READ animation_type WRITE set_animation_type NOTIFY animation_type_changed)
	Q_PROPERTY(int move_speed READ move_speed WRITE set_move_speed NOTIFY move_speed_changed)
	Q_PROPERTY(Binding::MoveRoute* move_route READ move_route CONSTANT)
	Q_PROPERTY(ArrayAdapter* event_commands READ event_commands CONSTANT)

public:
	EventPage(ProjectData& project, lcf::rpg::EventPage& data, QObject* parent = nullptr);

	lcf::rpg::EventPage& data();
	int id();
	Binding::EventPageCondition* condition();
	QString character_name();
	void set_character_name(const QString& new_character_name);
	int character_index();
	void set_character_index(const int& new_character_index);
	int character_direction();
	void set_character_direction(const int& new_character_direction);
	int character_pattern();
	void set_character_pattern(const int& new_character_pattern);
	bool translucent();
	void set_translucent(const bool& new_translucent);
	int move_type();
	void set_move_type(const int& new_move_type);
	int move_frequency();
	void set_move_frequency(const int& new_move_frequency);
	int trigger();
	void set_trigger(const int& new_trigger);
	int layer();
	void set_layer(const int& new_layer);
	bool overlap_forbidden();
	void set_overlap_forbidden(const bool& new_overlap_forbidden);
	int animation_type();
	void set_animation_type(const int& new_animation_type);
	int move_speed();
	void set_move_speed(const int& new_move_speed);
	Binding::MoveRoute* move_route();
	ArrayAdapter* event_commands();

signals:
	void character_name_changed();
	void character_index_changed();
	void character_direction_changed();
	void character_pattern_changed();
	void translucent_changed();
	void move_type_changed();
	void move_frequency_changed();
	void trigger_changed();
	void layer_changed();
	void overlap_forbidden_changed();
	void animation_type_changed();
	void move_speed_changed();

protected:
	lcf::rpg::EventPage& m_data;
	Binding::EventPageCondition* m_condition;
	Binding::MoveRoute* m_move_route;
	ArrayAdapter* m_event_commands;
};
} // namespace Binding::Generated
