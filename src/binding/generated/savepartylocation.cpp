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
#include "savepartylocation.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SavePartyLocation::SavePartyLocation(ProjectData& project, lcf::rpg::SavePartyLocation& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	bool SavePartyLocation::boarding() {
		return m_data.boarding;
	}
	void SavePartyLocation::set_boarding(const bool& new_boarding) {
		if (m_data.boarding == new_boarding)
			return;
		m_data.boarding = new_boarding;
		emit boarding_changed();
	}

	bool SavePartyLocation::aboard() {
		return m_data.aboard;
	}
	void SavePartyLocation::set_aboard(const bool& new_aboard) {
		if (m_data.aboard == new_aboard)
			return;
		m_data.aboard = new_aboard;
		emit aboard_changed();
	}

	int32_t SavePartyLocation::vehicle() {
		return m_data.vehicle;
	}

	bool SavePartyLocation::unboarding() {
		return m_data.unboarding;
	}
	void SavePartyLocation::set_unboarding(const bool& new_unboarding) {
		if (m_data.unboarding == new_unboarding)
			return;
		m_data.unboarding = new_unboarding;
		emit unboarding_changed();
	}

	int SavePartyLocation::preboard_move_speed() {
		return m_data.preboard_move_speed;
	}
	void SavePartyLocation::set_preboard_move_speed(const int& new_preboard_move_speed) {
		if (m_data.preboard_move_speed == new_preboard_move_speed)
			return;
		m_data.preboard_move_speed = new_preboard_move_speed;
		emit preboard_move_speed_changed();
	}

	bool SavePartyLocation::menu_calling() {
		return m_data.menu_calling;
	}
	void SavePartyLocation::set_menu_calling(const bool& new_menu_calling) {
		if (m_data.menu_calling == new_menu_calling)
			return;
		m_data.menu_calling = new_menu_calling;
		emit menu_calling_changed();
	}

	int32_t SavePartyLocation::pan_state() {
		return m_data.pan_state;
	}

	int SavePartyLocation::pan_current_x() {
		return m_data.pan_current_x;
	}
	void SavePartyLocation::set_pan_current_x(const int& new_pan_current_x) {
		if (m_data.pan_current_x == new_pan_current_x)
			return;
		m_data.pan_current_x = new_pan_current_x;
		emit pan_current_x_changed();
	}

	int SavePartyLocation::pan_current_y() {
		return m_data.pan_current_y;
	}
	void SavePartyLocation::set_pan_current_y(const int& new_pan_current_y) {
		if (m_data.pan_current_y == new_pan_current_y)
			return;
		m_data.pan_current_y = new_pan_current_y;
		emit pan_current_y_changed();
	}

	int SavePartyLocation::pan_finish_x() {
		return m_data.pan_finish_x;
	}
	void SavePartyLocation::set_pan_finish_x(const int& new_pan_finish_x) {
		if (m_data.pan_finish_x == new_pan_finish_x)
			return;
		m_data.pan_finish_x = new_pan_finish_x;
		emit pan_finish_x_changed();
	}

	int SavePartyLocation::pan_finish_y() {
		return m_data.pan_finish_y;
	}
	void SavePartyLocation::set_pan_finish_y(const int& new_pan_finish_y) {
		if (m_data.pan_finish_y == new_pan_finish_y)
			return;
		m_data.pan_finish_y = new_pan_finish_y;
		emit pan_finish_y_changed();
	}

	int SavePartyLocation::pan_speed() {
		return m_data.pan_speed;
	}
	void SavePartyLocation::set_pan_speed(const int& new_pan_speed) {
		if (m_data.pan_speed == new_pan_speed)
			return;
		m_data.pan_speed = new_pan_speed;
		emit pan_speed_changed();
	}

	int SavePartyLocation::encounter_steps() {
		return m_data.encounter_steps;
	}
	void SavePartyLocation::set_encounter_steps(const int& new_encounter_steps) {
		if (m_data.encounter_steps == new_encounter_steps)
			return;
		m_data.encounter_steps = new_encounter_steps;
		emit encounter_steps_changed();
	}

	bool SavePartyLocation::encounter_calling() {
		return m_data.encounter_calling;
	}
	void SavePartyLocation::set_encounter_calling(const bool& new_encounter_calling) {
		if (m_data.encounter_calling == new_encounter_calling)
			return;
		m_data.encounter_calling = new_encounter_calling;
		emit encounter_calling_changed();
	}

	int SavePartyLocation::map_save_count() {
		return m_data.map_save_count;
	}
	void SavePartyLocation::set_map_save_count(const int& new_map_save_count) {
		if (m_data.map_save_count == new_map_save_count)
			return;
		m_data.map_save_count = new_map_save_count;
		emit map_save_count_changed();
	}

	int SavePartyLocation::database_save_count() {
		return m_data.database_save_count;
	}
	void SavePartyLocation::set_database_save_count(const int& new_database_save_count) {
		if (m_data.database_save_count == new_database_save_count)
			return;
		m_data.database_save_count = new_database_save_count;
		emit database_save_count_changed();
	}

} // namespace Binding::Generated
