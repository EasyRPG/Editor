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
#include "savesystem.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveSystem::SaveSystem(ProjectData& project, lcf::rpg::SaveSystem& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_title_music = new Binding::Music(m_project, m_data.title_music, this);
		m_battle_music = new Binding::Music(m_project, m_data.battle_music, this);
		m_battle_end_music = new Binding::Music(m_project, m_data.battle_end_music, this);
		m_inn_music = new Binding::Music(m_project, m_data.inn_music, this);
		m_current_music = new Binding::Music(m_project, m_data.current_music, this);
		m_before_vehicle_music = new Binding::Music(m_project, m_data.before_vehicle_music, this);
		m_before_battle_music = new Binding::Music(m_project, m_data.before_battle_music, this);
		m_stored_music = new Binding::Music(m_project, m_data.stored_music, this);
		m_boat_music = new Binding::Music(m_project, m_data.boat_music, this);
		m_ship_music = new Binding::Music(m_project, m_data.ship_music, this);
		m_airship_music = new Binding::Music(m_project, m_data.airship_music, this);
		m_gameover_music = new Binding::Music(m_project, m_data.gameover_music, this);
		m_cursor_se = new Binding::Sound(m_project, m_data.cursor_se, this);
		m_decision_se = new Binding::Sound(m_project, m_data.decision_se, this);
		m_cancel_se = new Binding::Sound(m_project, m_data.cancel_se, this);
		m_buzzer_se = new Binding::Sound(m_project, m_data.buzzer_se, this);
		m_battle_se = new Binding::Sound(m_project, m_data.battle_se, this);
		m_escape_se = new Binding::Sound(m_project, m_data.escape_se, this);
		m_enemy_attack_se = new Binding::Sound(m_project, m_data.enemy_attack_se, this);
		m_enemy_damaged_se = new Binding::Sound(m_project, m_data.enemy_damaged_se, this);
		m_actor_damaged_se = new Binding::Sound(m_project, m_data.actor_damaged_se, this);
		m_dodge_se = new Binding::Sound(m_project, m_data.dodge_se, this);
		m_enemy_death_se = new Binding::Sound(m_project, m_data.enemy_death_se, this);
		m_item_se = new Binding::Sound(m_project, m_data.item_se, this);
	}
	int SaveSystem::scene() {
		return m_data.scene;
	}
	void SaveSystem::set_scene(const int& new_scene) {
		if (m_data.scene == new_scene)
			return;
		m_data.scene = new_scene;
		emit scene_changed();
	}

	int SaveSystem::frame_count() {
		return m_data.frame_count;
	}
	void SaveSystem::set_frame_count(const int& new_frame_count) {
		if (m_data.frame_count == new_frame_count)
			return;
		m_data.frame_count = new_frame_count;
		emit frame_count_changed();
	}

	QString SaveSystem::graphics_name() {
		return QString::fromStdString(m_data.graphics_name);
	}
	void SaveSystem::set_graphics_name(const QString& new_graphics_name) {
		if (QString::fromStdString(m_data.graphics_name) == new_graphics_name)
			return;
		m_data.graphics_name = new_graphics_name.toStdString();
		emit graphics_name_changed();
	}

	int SaveSystem::message_stretch() {
		return m_data.message_stretch;
	}
	void SaveSystem::set_message_stretch(const int& new_message_stretch) {
		if (m_data.message_stretch == new_message_stretch)
			return;
		m_data.message_stretch = new_message_stretch;
		emit message_stretch_changed();
	}

	int SaveSystem::font_id() {
		return m_data.font_id;
	}
	void SaveSystem::set_font_id(const int& new_font_id) {
		if (m_data.font_id == new_font_id)
			return;
		m_data.font_id = new_font_id;
		emit font_id_changed();
	}

	QVector<bool> SaveSystem::switches() {
		return QVector<bool>(m_data.switches.begin(), m_data.switches.end());
	}
	void SaveSystem::set_switches(const QVector<bool>& new_switches) {
		if (QVector<bool>(m_data.switches.begin(), m_data.switches.end()) == new_switches)
			return;
		m_data.switches = decltype(m_data.switches)(new_switches.begin(), new_switches.end());
		emit switches_changed();
	}

	QVector<int> SaveSystem::variables() {
		return QVector<int>(m_data.variables.begin(), m_data.variables.end());
	}
	void SaveSystem::set_variables(const QVector<int>& new_variables) {
		if (QVector<int>(m_data.variables.begin(), m_data.variables.end()) == new_variables)
			return;
		m_data.variables = decltype(m_data.variables)(new_variables.begin(), new_variables.end());
		emit variables_changed();
	}

	int SaveSystem::message_transparent() {
		return m_data.message_transparent;
	}
	void SaveSystem::set_message_transparent(const int& new_message_transparent) {
		if (m_data.message_transparent == new_message_transparent)
			return;
		m_data.message_transparent = new_message_transparent;
		emit message_transparent_changed();
	}

	int SaveSystem::message_position() {
		return m_data.message_position;
	}
	void SaveSystem::set_message_position(const int& new_message_position) {
		if (m_data.message_position == new_message_position)
			return;
		m_data.message_position = new_message_position;
		emit message_position_changed();
	}

	int SaveSystem::message_prevent_overlap() {
		return m_data.message_prevent_overlap;
	}
	void SaveSystem::set_message_prevent_overlap(const int& new_message_prevent_overlap) {
		if (m_data.message_prevent_overlap == new_message_prevent_overlap)
			return;
		m_data.message_prevent_overlap = new_message_prevent_overlap;
		emit message_prevent_overlap_changed();
	}

	int SaveSystem::message_continue_events() {
		return m_data.message_continue_events;
	}
	void SaveSystem::set_message_continue_events(const int& new_message_continue_events) {
		if (m_data.message_continue_events == new_message_continue_events)
			return;
		m_data.message_continue_events = new_message_continue_events;
		emit message_continue_events_changed();
	}

	QString SaveSystem::face_name() {
		return QString::fromStdString(m_data.face_name);
	}
	void SaveSystem::set_face_name(const QString& new_face_name) {
		if (QString::fromStdString(m_data.face_name) == new_face_name)
			return;
		m_data.face_name = new_face_name.toStdString();
		emit face_name_changed();
	}

	int SaveSystem::face_id() {
		return m_data.face_id;
	}
	void SaveSystem::set_face_id(const int& new_face_id) {
		if (m_data.face_id == new_face_id)
			return;
		m_data.face_id = new_face_id;
		emit face_id_changed();
	}

	bool SaveSystem::face_right() {
		return m_data.face_right;
	}
	void SaveSystem::set_face_right(const bool& new_face_right) {
		if (m_data.face_right == new_face_right)
			return;
		m_data.face_right = new_face_right;
		emit face_right_changed();
	}

	bool SaveSystem::face_flip() {
		return m_data.face_flip;
	}
	void SaveSystem::set_face_flip(const bool& new_face_flip) {
		if (m_data.face_flip == new_face_flip)
			return;
		m_data.face_flip = new_face_flip;
		emit face_flip_changed();
	}

	bool SaveSystem::event_message_active() {
		return m_data.event_message_active;
	}
	void SaveSystem::set_event_message_active(const bool& new_event_message_active) {
		if (m_data.event_message_active == new_event_message_active)
			return;
		m_data.event_message_active = new_event_message_active;
		emit event_message_active_changed();
	}

	bool SaveSystem::music_stopping() {
		return m_data.music_stopping;
	}
	void SaveSystem::set_music_stopping(const bool& new_music_stopping) {
		if (m_data.music_stopping == new_music_stopping)
			return;
		m_data.music_stopping = new_music_stopping;
		emit music_stopping_changed();
	}

	Binding::Music* SaveSystem::title_music() {
		return m_title_music;
	}

	Binding::Music* SaveSystem::battle_music() {
		return m_battle_music;
	}

	Binding::Music* SaveSystem::battle_end_music() {
		return m_battle_end_music;
	}

	Binding::Music* SaveSystem::inn_music() {
		return m_inn_music;
	}

	Binding::Music* SaveSystem::current_music() {
		return m_current_music;
	}

	Binding::Music* SaveSystem::before_vehicle_music() {
		return m_before_vehicle_music;
	}

	Binding::Music* SaveSystem::before_battle_music() {
		return m_before_battle_music;
	}

	Binding::Music* SaveSystem::stored_music() {
		return m_stored_music;
	}

	Binding::Music* SaveSystem::boat_music() {
		return m_boat_music;
	}

	Binding::Music* SaveSystem::ship_music() {
		return m_ship_music;
	}

	Binding::Music* SaveSystem::airship_music() {
		return m_airship_music;
	}

	Binding::Music* SaveSystem::gameover_music() {
		return m_gameover_music;
	}

	Binding::Sound* SaveSystem::cursor_se() {
		return m_cursor_se;
	}

	Binding::Sound* SaveSystem::decision_se() {
		return m_decision_se;
	}

	Binding::Sound* SaveSystem::cancel_se() {
		return m_cancel_se;
	}

	Binding::Sound* SaveSystem::buzzer_se() {
		return m_buzzer_se;
	}

	Binding::Sound* SaveSystem::battle_se() {
		return m_battle_se;
	}

	Binding::Sound* SaveSystem::escape_se() {
		return m_escape_se;
	}

	Binding::Sound* SaveSystem::enemy_attack_se() {
		return m_enemy_attack_se;
	}

	Binding::Sound* SaveSystem::enemy_damaged_se() {
		return m_enemy_damaged_se;
	}

	Binding::Sound* SaveSystem::actor_damaged_se() {
		return m_actor_damaged_se;
	}

	Binding::Sound* SaveSystem::dodge_se() {
		return m_dodge_se;
	}

	Binding::Sound* SaveSystem::enemy_death_se() {
		return m_enemy_death_se;
	}

	Binding::Sound* SaveSystem::item_se() {
		return m_item_se;
	}

	int SaveSystem::transition_out() {
		return m_data.transition_out;
	}
	void SaveSystem::set_transition_out(const int& new_transition_out) {
		if (m_data.transition_out == new_transition_out)
			return;
		m_data.transition_out = new_transition_out;
		emit transition_out_changed();
	}

	int SaveSystem::transition_in() {
		return m_data.transition_in;
	}
	void SaveSystem::set_transition_in(const int& new_transition_in) {
		if (m_data.transition_in == new_transition_in)
			return;
		m_data.transition_in = new_transition_in;
		emit transition_in_changed();
	}

	int SaveSystem::battle_start_fadeout() {
		return m_data.battle_start_fadeout;
	}
	void SaveSystem::set_battle_start_fadeout(const int& new_battle_start_fadeout) {
		if (m_data.battle_start_fadeout == new_battle_start_fadeout)
			return;
		m_data.battle_start_fadeout = new_battle_start_fadeout;
		emit battle_start_fadeout_changed();
	}

	int SaveSystem::battle_start_fadein() {
		return m_data.battle_start_fadein;
	}
	void SaveSystem::set_battle_start_fadein(const int& new_battle_start_fadein) {
		if (m_data.battle_start_fadein == new_battle_start_fadein)
			return;
		m_data.battle_start_fadein = new_battle_start_fadein;
		emit battle_start_fadein_changed();
	}

	int SaveSystem::battle_end_fadeout() {
		return m_data.battle_end_fadeout;
	}
	void SaveSystem::set_battle_end_fadeout(const int& new_battle_end_fadeout) {
		if (m_data.battle_end_fadeout == new_battle_end_fadeout)
			return;
		m_data.battle_end_fadeout = new_battle_end_fadeout;
		emit battle_end_fadeout_changed();
	}

	int SaveSystem::battle_end_fadein() {
		return m_data.battle_end_fadein;
	}
	void SaveSystem::set_battle_end_fadein(const int& new_battle_end_fadein) {
		if (m_data.battle_end_fadein == new_battle_end_fadein)
			return;
		m_data.battle_end_fadein = new_battle_end_fadein;
		emit battle_end_fadein_changed();
	}

	bool SaveSystem::teleport_allowed() {
		return m_data.teleport_allowed;
	}
	void SaveSystem::set_teleport_allowed(const bool& new_teleport_allowed) {
		if (m_data.teleport_allowed == new_teleport_allowed)
			return;
		m_data.teleport_allowed = new_teleport_allowed;
		emit teleport_allowed_changed();
	}

	bool SaveSystem::escape_allowed() {
		return m_data.escape_allowed;
	}
	void SaveSystem::set_escape_allowed(const bool& new_escape_allowed) {
		if (m_data.escape_allowed == new_escape_allowed)
			return;
		m_data.escape_allowed = new_escape_allowed;
		emit escape_allowed_changed();
	}

	bool SaveSystem::save_allowed() {
		return m_data.save_allowed;
	}
	void SaveSystem::set_save_allowed(const bool& new_save_allowed) {
		if (m_data.save_allowed == new_save_allowed)
			return;
		m_data.save_allowed = new_save_allowed;
		emit save_allowed_changed();
	}

	bool SaveSystem::menu_allowed() {
		return m_data.menu_allowed;
	}
	void SaveSystem::set_menu_allowed(const bool& new_menu_allowed) {
		if (m_data.menu_allowed == new_menu_allowed)
			return;
		m_data.menu_allowed = new_menu_allowed;
		emit menu_allowed_changed();
	}

	QString SaveSystem::background() {
		return QString::fromStdString(m_data.background);
	}
	void SaveSystem::set_background(const QString& new_background) {
		if (QString::fromStdString(m_data.background) == new_background)
			return;
		m_data.background = new_background.toStdString();
		emit background_changed();
	}

	int SaveSystem::save_count() {
		return m_data.save_count;
	}
	void SaveSystem::set_save_count(const int& new_save_count) {
		if (m_data.save_count == new_save_count)
			return;
		m_data.save_count = new_save_count;
		emit save_count_changed();
	}

	int SaveSystem::save_slot() {
		return m_data.save_slot;
	}
	void SaveSystem::set_save_slot(const int& new_save_slot) {
		if (m_data.save_slot == new_save_slot)
			return;
		m_data.save_slot = new_save_slot;
		emit save_slot_changed();
	}

	int SaveSystem::atb_mode() {
		return m_data.atb_mode;
	}
	void SaveSystem::set_atb_mode(const int& new_atb_mode) {
		if (m_data.atb_mode == new_atb_mode)
			return;
		m_data.atb_mode = new_atb_mode;
		emit atb_mode_changed();
	}

	int SaveSystem::maniac_frameskip() {
		return m_data.maniac_frameskip;
	}
	void SaveSystem::set_maniac_frameskip(const int& new_maniac_frameskip) {
		if (m_data.maniac_frameskip == new_maniac_frameskip)
			return;
		m_data.maniac_frameskip = new_maniac_frameskip;
		emit maniac_frameskip_changed();
	}

	int SaveSystem::maniac_picture_limit() {
		return m_data.maniac_picture_limit;
	}
	void SaveSystem::set_maniac_picture_limit(const int& new_maniac_picture_limit) {
		if (m_data.maniac_picture_limit == new_maniac_picture_limit)
			return;
		m_data.maniac_picture_limit = new_maniac_picture_limit;
		emit maniac_picture_limit_changed();
	}

	QVector<int> SaveSystem::maniac_options() {
		return QVector<int>(m_data.maniac_options.begin(), m_data.maniac_options.end());
	}
	void SaveSystem::set_maniac_options(const QVector<int>& new_maniac_options) {
		if (QVector<int>(m_data.maniac_options.begin(), m_data.maniac_options.end()) == new_maniac_options)
			return;
		m_data.maniac_options = decltype(m_data.maniac_options)(new_maniac_options.begin(), new_maniac_options.end());
		emit maniac_options_changed();
	}

	QVector<int> SaveSystem::maniac_joypad_bindings() {
		return QVector<int>(m_data.maniac_joypad_bindings.begin(), m_data.maniac_joypad_bindings.end());
	}
	void SaveSystem::set_maniac_joypad_bindings(const QVector<int>& new_maniac_joypad_bindings) {
		if (QVector<int>(m_data.maniac_joypad_bindings.begin(), m_data.maniac_joypad_bindings.end()) == new_maniac_joypad_bindings)
			return;
		m_data.maniac_joypad_bindings = decltype(m_data.maniac_joypad_bindings)(new_maniac_joypad_bindings.begin(), new_maniac_joypad_bindings.end());
		emit maniac_joypad_bindings_changed();
	}

} // namespace Binding::Generated
