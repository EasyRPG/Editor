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
#include <lcf/rpg/savepartylocation.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::SavePartyLocation class.
 * Exposes lcf::rpg::SavePartyLocation to QML.
 */
namespace Binding::Generated {
class SavePartyLocation : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(bool boarding READ boarding WRITE set_boarding NOTIFY boarding_changed)
	Q_PROPERTY(bool aboard READ aboard WRITE set_aboard NOTIFY aboard_changed)
	Q_PROPERTY(int vehicle READ vehicle WRITE set_vehicle NOTIFY vehicle_changed)
	Q_PROPERTY(bool unboarding READ unboarding WRITE set_unboarding NOTIFY unboarding_changed)
	Q_PROPERTY(int preboard_move_speed READ preboard_move_speed WRITE set_preboard_move_speed NOTIFY preboard_move_speed_changed)
	Q_PROPERTY(bool menu_calling READ menu_calling WRITE set_menu_calling NOTIFY menu_calling_changed)
	Q_PROPERTY(int pan_state READ pan_state WRITE set_pan_state NOTIFY pan_state_changed)
	Q_PROPERTY(int pan_current_x READ pan_current_x WRITE set_pan_current_x NOTIFY pan_current_x_changed)
	Q_PROPERTY(int pan_current_y READ pan_current_y WRITE set_pan_current_y NOTIFY pan_current_y_changed)
	Q_PROPERTY(int pan_finish_x READ pan_finish_x WRITE set_pan_finish_x NOTIFY pan_finish_x_changed)
	Q_PROPERTY(int pan_finish_y READ pan_finish_y WRITE set_pan_finish_y NOTIFY pan_finish_y_changed)
	Q_PROPERTY(int pan_speed READ pan_speed WRITE set_pan_speed NOTIFY pan_speed_changed)
	Q_PROPERTY(int encounter_steps READ encounter_steps WRITE set_encounter_steps NOTIFY encounter_steps_changed)
	Q_PROPERTY(bool encounter_calling READ encounter_calling WRITE set_encounter_calling NOTIFY encounter_calling_changed)
	Q_PROPERTY(int map_save_count READ map_save_count WRITE set_map_save_count NOTIFY map_save_count_changed)
	Q_PROPERTY(int database_save_count READ database_save_count WRITE set_database_save_count NOTIFY database_save_count_changed)

public:
	SavePartyLocation(ProjectData& project, lcf::rpg::SavePartyLocation& data, QObject* parent = nullptr);

	lcf::rpg::SavePartyLocation& data();
	bool boarding();
	void set_boarding(const bool& new_boarding);
	bool aboard();
	void set_aboard(const bool& new_aboard);
	int vehicle();
	void set_vehicle(const int& new_vehicle);
	bool unboarding();
	void set_unboarding(const bool& new_unboarding);
	int preboard_move_speed();
	void set_preboard_move_speed(const int& new_preboard_move_speed);
	bool menu_calling();
	void set_menu_calling(const bool& new_menu_calling);
	int pan_state();
	void set_pan_state(const int& new_pan_state);
	int pan_current_x();
	void set_pan_current_x(const int& new_pan_current_x);
	int pan_current_y();
	void set_pan_current_y(const int& new_pan_current_y);
	int pan_finish_x();
	void set_pan_finish_x(const int& new_pan_finish_x);
	int pan_finish_y();
	void set_pan_finish_y(const int& new_pan_finish_y);
	int pan_speed();
	void set_pan_speed(const int& new_pan_speed);
	int encounter_steps();
	void set_encounter_steps(const int& new_encounter_steps);
	bool encounter_calling();
	void set_encounter_calling(const bool& new_encounter_calling);
	int map_save_count();
	void set_map_save_count(const int& new_map_save_count);
	int database_save_count();
	void set_database_save_count(const int& new_database_save_count);

signals:
	void boarding_changed();
	void aboard_changed();
	void vehicle_changed();
	void unboarding_changed();
	void preboard_move_speed_changed();
	void menu_calling_changed();
	void pan_state_changed();
	void pan_current_x_changed();
	void pan_current_y_changed();
	void pan_finish_x_changed();
	void pan_finish_y_changed();
	void pan_speed_changed();
	void encounter_steps_changed();
	void encounter_calling_changed();
	void map_save_count_changed();
	void database_save_count_changed();

protected:
	lcf::rpg::SavePartyLocation& m_data;
};
} // namespace Binding::Generated
