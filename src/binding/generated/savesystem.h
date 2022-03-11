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
#include <lcf/rpg/savesystem.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/sound.h"
#include "binding/music.h"
#include "binding/music.h"
#include "binding/music.h"
#include "binding/sound.h"
#include "binding/music.h"
#include "binding/music.h"
#include "binding/music.h"
#include "binding/sound.h"
#include "binding/sound.h"
#include "binding/music.h"
#include "binding/sound.h"
#include "binding/sound.h"
#include "binding/sound.h"
#include "binding/sound.h"
#include "binding/sound.h"
#include "binding/sound.h"
#include "binding/sound.h"
#include "binding/music.h"
#include "binding/music.h"
#include "binding/sound.h"
#include "binding/music.h"
#include "binding/music.h"
#include "binding/music.h"

class ProjectData;

/**
 * Binding::Generated::SaveSystem class.
 * Exposes lcf::rpg::SaveSystem to QML.
 */
namespace Binding::Generated {
class SaveSystem : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int32_t scene READ scene CONSTANT)
	Q_PROPERTY(int frame_count READ frame_count WRITE set_frame_count NOTIFY frame_count_changed)
	Q_PROPERTY(QString graphics_name READ graphics_name WRITE set_graphics_name NOTIFY graphics_name_changed)
	Q_PROPERTY(int32_t message_stretch READ message_stretch CONSTANT)
	Q_PROPERTY(int32_t font_id READ font_id CONSTANT)
	Q_PROPERTY(QVector<bool> switches READ switches WRITE set_switches NOTIFY switches_changed)
	Q_PROPERTY(QVector<int> variables READ variables WRITE set_variables NOTIFY variables_changed)
	Q_PROPERTY(int message_transparent READ message_transparent WRITE set_message_transparent NOTIFY message_transparent_changed)
	Q_PROPERTY(int message_position READ message_position WRITE set_message_position NOTIFY message_position_changed)
	Q_PROPERTY(int message_prevent_overlap READ message_prevent_overlap WRITE set_message_prevent_overlap NOTIFY message_prevent_overlap_changed)
	Q_PROPERTY(int message_continue_events READ message_continue_events WRITE set_message_continue_events NOTIFY message_continue_events_changed)
	Q_PROPERTY(QString face_name READ face_name WRITE set_face_name NOTIFY face_name_changed)
	Q_PROPERTY(int face_id READ face_id WRITE set_face_id NOTIFY face_id_changed)
	Q_PROPERTY(bool face_right READ face_right WRITE set_face_right NOTIFY face_right_changed)
	Q_PROPERTY(bool face_flip READ face_flip WRITE set_face_flip NOTIFY face_flip_changed)
	Q_PROPERTY(bool event_message_active READ event_message_active WRITE set_event_message_active NOTIFY event_message_active_changed)
	Q_PROPERTY(bool music_stopping READ music_stopping WRITE set_music_stopping NOTIFY music_stopping_changed)
	Q_PROPERTY(Binding::Music* title_music READ title_music CONSTANT)
	Q_PROPERTY(Binding::Music* battle_music READ battle_music CONSTANT)
	Q_PROPERTY(Binding::Music* battle_end_music READ battle_end_music CONSTANT)
	Q_PROPERTY(Binding::Music* inn_music READ inn_music CONSTANT)
	Q_PROPERTY(Binding::Music* current_music READ current_music CONSTANT)
	Q_PROPERTY(Binding::Music* before_vehicle_music READ before_vehicle_music CONSTANT)
	Q_PROPERTY(Binding::Music* before_battle_music READ before_battle_music CONSTANT)
	Q_PROPERTY(Binding::Music* stored_music READ stored_music CONSTANT)
	Q_PROPERTY(Binding::Music* boat_music READ boat_music CONSTANT)
	Q_PROPERTY(Binding::Music* ship_music READ ship_music CONSTANT)
	Q_PROPERTY(Binding::Music* airship_music READ airship_music CONSTANT)
	Q_PROPERTY(Binding::Music* gameover_music READ gameover_music CONSTANT)
	Q_PROPERTY(Binding::Sound* cursor_se READ cursor_se CONSTANT)
	Q_PROPERTY(Binding::Sound* decision_se READ decision_se CONSTANT)
	Q_PROPERTY(Binding::Sound* cancel_se READ cancel_se CONSTANT)
	Q_PROPERTY(Binding::Sound* buzzer_se READ buzzer_se CONSTANT)
	Q_PROPERTY(Binding::Sound* battle_se READ battle_se CONSTANT)
	Q_PROPERTY(Binding::Sound* escape_se READ escape_se CONSTANT)
	Q_PROPERTY(Binding::Sound* enemy_attack_se READ enemy_attack_se CONSTANT)
	Q_PROPERTY(Binding::Sound* enemy_damaged_se READ enemy_damaged_se CONSTANT)
	Q_PROPERTY(Binding::Sound* actor_damaged_se READ actor_damaged_se CONSTANT)
	Q_PROPERTY(Binding::Sound* dodge_se READ dodge_se CONSTANT)
	Q_PROPERTY(Binding::Sound* enemy_death_se READ enemy_death_se CONSTANT)
	Q_PROPERTY(Binding::Sound* item_se READ item_se CONSTANT)
	Q_PROPERTY(int transition_out READ transition_out WRITE set_transition_out NOTIFY transition_out_changed)
	Q_PROPERTY(int transition_in READ transition_in WRITE set_transition_in NOTIFY transition_in_changed)
	Q_PROPERTY(int battle_start_fadeout READ battle_start_fadeout WRITE set_battle_start_fadeout NOTIFY battle_start_fadeout_changed)
	Q_PROPERTY(int battle_start_fadein READ battle_start_fadein WRITE set_battle_start_fadein NOTIFY battle_start_fadein_changed)
	Q_PROPERTY(int battle_end_fadeout READ battle_end_fadeout WRITE set_battle_end_fadeout NOTIFY battle_end_fadeout_changed)
	Q_PROPERTY(int battle_end_fadein READ battle_end_fadein WRITE set_battle_end_fadein NOTIFY battle_end_fadein_changed)
	Q_PROPERTY(bool teleport_allowed READ teleport_allowed WRITE set_teleport_allowed NOTIFY teleport_allowed_changed)
	Q_PROPERTY(bool escape_allowed READ escape_allowed WRITE set_escape_allowed NOTIFY escape_allowed_changed)
	Q_PROPERTY(bool save_allowed READ save_allowed WRITE set_save_allowed NOTIFY save_allowed_changed)
	Q_PROPERTY(bool menu_allowed READ menu_allowed WRITE set_menu_allowed NOTIFY menu_allowed_changed)
	Q_PROPERTY(QString background READ background WRITE set_background NOTIFY background_changed)
	Q_PROPERTY(int save_count READ save_count WRITE set_save_count NOTIFY save_count_changed)
	Q_PROPERTY(int save_slot READ save_slot WRITE set_save_slot NOTIFY save_slot_changed)
	Q_PROPERTY(int32_t atb_mode READ atb_mode CONSTANT)
	Q_PROPERTY(int maniac_frameskip READ maniac_frameskip WRITE set_maniac_frameskip NOTIFY maniac_frameskip_changed)
	Q_PROPERTY(int maniac_picture_limit READ maniac_picture_limit WRITE set_maniac_picture_limit NOTIFY maniac_picture_limit_changed)
	Q_PROPERTY(QVector<int> maniac_options READ maniac_options WRITE set_maniac_options NOTIFY maniac_options_changed)
	Q_PROPERTY(QVector<int> maniac_joypad_bindings READ maniac_joypad_bindings WRITE set_maniac_joypad_bindings NOTIFY maniac_joypad_bindings_changed)

public:
	SaveSystem(ProjectData& project, lcf::rpg::SaveSystem& data, QObject* parent = nullptr);

	lcf::rpg::SaveSystem& data();
	int32_t scene();
	int frame_count();
	void set_frame_count(const int& new_frame_count);
	QString graphics_name();
	void set_graphics_name(const QString& new_graphics_name);
	int32_t message_stretch();
	int32_t font_id();
	QVector<bool> switches();
	void set_switches(const QVector<bool>& new_switches);
	QVector<int> variables();
	void set_variables(const QVector<int>& new_variables);
	int message_transparent();
	void set_message_transparent(const int& new_message_transparent);
	int message_position();
	void set_message_position(const int& new_message_position);
	int message_prevent_overlap();
	void set_message_prevent_overlap(const int& new_message_prevent_overlap);
	int message_continue_events();
	void set_message_continue_events(const int& new_message_continue_events);
	QString face_name();
	void set_face_name(const QString& new_face_name);
	int face_id();
	void set_face_id(const int& new_face_id);
	bool face_right();
	void set_face_right(const bool& new_face_right);
	bool face_flip();
	void set_face_flip(const bool& new_face_flip);
	bool event_message_active();
	void set_event_message_active(const bool& new_event_message_active);
	bool music_stopping();
	void set_music_stopping(const bool& new_music_stopping);
	Binding::Music* title_music();
	Binding::Music* battle_music();
	Binding::Music* battle_end_music();
	Binding::Music* inn_music();
	Binding::Music* current_music();
	Binding::Music* before_vehicle_music();
	Binding::Music* before_battle_music();
	Binding::Music* stored_music();
	Binding::Music* boat_music();
	Binding::Music* ship_music();
	Binding::Music* airship_music();
	Binding::Music* gameover_music();
	Binding::Sound* cursor_se();
	Binding::Sound* decision_se();
	Binding::Sound* cancel_se();
	Binding::Sound* buzzer_se();
	Binding::Sound* battle_se();
	Binding::Sound* escape_se();
	Binding::Sound* enemy_attack_se();
	Binding::Sound* enemy_damaged_se();
	Binding::Sound* actor_damaged_se();
	Binding::Sound* dodge_se();
	Binding::Sound* enemy_death_se();
	Binding::Sound* item_se();
	int transition_out();
	void set_transition_out(const int& new_transition_out);
	int transition_in();
	void set_transition_in(const int& new_transition_in);
	int battle_start_fadeout();
	void set_battle_start_fadeout(const int& new_battle_start_fadeout);
	int battle_start_fadein();
	void set_battle_start_fadein(const int& new_battle_start_fadein);
	int battle_end_fadeout();
	void set_battle_end_fadeout(const int& new_battle_end_fadeout);
	int battle_end_fadein();
	void set_battle_end_fadein(const int& new_battle_end_fadein);
	bool teleport_allowed();
	void set_teleport_allowed(const bool& new_teleport_allowed);
	bool escape_allowed();
	void set_escape_allowed(const bool& new_escape_allowed);
	bool save_allowed();
	void set_save_allowed(const bool& new_save_allowed);
	bool menu_allowed();
	void set_menu_allowed(const bool& new_menu_allowed);
	QString background();
	void set_background(const QString& new_background);
	int save_count();
	void set_save_count(const int& new_save_count);
	int save_slot();
	void set_save_slot(const int& new_save_slot);
	int32_t atb_mode();
	int maniac_frameskip();
	void set_maniac_frameskip(const int& new_maniac_frameskip);
	int maniac_picture_limit();
	void set_maniac_picture_limit(const int& new_maniac_picture_limit);
	QVector<int> maniac_options();
	void set_maniac_options(const QVector<int>& new_maniac_options);
	QVector<int> maniac_joypad_bindings();
	void set_maniac_joypad_bindings(const QVector<int>& new_maniac_joypad_bindings);

signals:
	void frame_count_changed();
	void graphics_name_changed();
	void switches_changed();
	void variables_changed();
	void message_transparent_changed();
	void message_position_changed();
	void message_prevent_overlap_changed();
	void message_continue_events_changed();
	void face_name_changed();
	void face_id_changed();
	void face_right_changed();
	void face_flip_changed();
	void event_message_active_changed();
	void music_stopping_changed();
	void transition_out_changed();
	void transition_in_changed();
	void battle_start_fadeout_changed();
	void battle_start_fadein_changed();
	void battle_end_fadeout_changed();
	void battle_end_fadein_changed();
	void teleport_allowed_changed();
	void escape_allowed_changed();
	void save_allowed_changed();
	void menu_allowed_changed();
	void background_changed();
	void save_count_changed();
	void save_slot_changed();
	void maniac_frameskip_changed();
	void maniac_picture_limit_changed();
	void maniac_options_changed();
	void maniac_joypad_bindings_changed();

protected:
	lcf::rpg::SaveSystem& m_data;
	Binding::Music* m_title_music;
	Binding::Music* m_battle_music;
	Binding::Music* m_battle_end_music;
	Binding::Music* m_inn_music;
	Binding::Music* m_current_music;
	Binding::Music* m_before_vehicle_music;
	Binding::Music* m_before_battle_music;
	Binding::Music* m_stored_music;
	Binding::Music* m_boat_music;
	Binding::Music* m_ship_music;
	Binding::Music* m_airship_music;
	Binding::Music* m_gameover_music;
	Binding::Sound* m_cursor_se;
	Binding::Sound* m_decision_se;
	Binding::Sound* m_cancel_se;
	Binding::Sound* m_buzzer_se;
	Binding::Sound* m_battle_se;
	Binding::Sound* m_escape_se;
	Binding::Sound* m_enemy_attack_se;
	Binding::Sound* m_enemy_damaged_se;
	Binding::Sound* m_actor_damaged_se;
	Binding::Sound* m_dodge_se;
	Binding::Sound* m_enemy_death_se;
	Binding::Sound* m_item_se;
};
} // namespace Binding::Generated
