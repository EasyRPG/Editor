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
#include "system.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	System::System(ProjectData& project, lcf::rpg::System& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_title_music = new Binding::Music(m_project, m_data.title_music, this);
		m_battle_music = new Binding::Music(m_project, m_data.battle_music, this);
		m_battle_end_music = new Binding::Music(m_project, m_data.battle_end_music, this);
		m_inn_music = new Binding::Music(m_project, m_data.inn_music, this);
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
		{
			m_battletest_data = new ArrayAdapter(this);
			auto& arr = m_battletest_data->data();
			for (auto& var: m_data.battletest_data)
				arr.push_back(new Binding::TestBattler(m_project, var, this));
		}
	}
	int System::ldb_id() {
		return m_data.ldb_id;
	}
	void System::set_ldb_id(const int& new_ldb_id) {
		if (m_data.ldb_id == new_ldb_id)
			return;
		m_data.ldb_id = new_ldb_id;
		emit ldb_id_changed();
	}

	QString System::boat_name() {
		return ToQString(m_data.boat_name);
	}
	void System::set_boat_name(const QString& new_boat_name) {
		if (ToQString(m_data.boat_name) == new_boat_name)
			return;
		m_data.boat_name = ToDBString(new_boat_name);
		emit boat_name_changed();
	}

	QString System::ship_name() {
		return ToQString(m_data.ship_name);
	}
	void System::set_ship_name(const QString& new_ship_name) {
		if (ToQString(m_data.ship_name) == new_ship_name)
			return;
		m_data.ship_name = ToDBString(new_ship_name);
		emit ship_name_changed();
	}

	QString System::airship_name() {
		return ToQString(m_data.airship_name);
	}
	void System::set_airship_name(const QString& new_airship_name) {
		if (ToQString(m_data.airship_name) == new_airship_name)
			return;
		m_data.airship_name = ToDBString(new_airship_name);
		emit airship_name_changed();
	}

	int System::boat_index() {
		return m_data.boat_index;
	}
	void System::set_boat_index(const int& new_boat_index) {
		if (m_data.boat_index == new_boat_index)
			return;
		m_data.boat_index = new_boat_index;
		emit boat_index_changed();
	}

	int System::ship_index() {
		return m_data.ship_index;
	}
	void System::set_ship_index(const int& new_ship_index) {
		if (m_data.ship_index == new_ship_index)
			return;
		m_data.ship_index = new_ship_index;
		emit ship_index_changed();
	}

	int System::airship_index() {
		return m_data.airship_index;
	}
	void System::set_airship_index(const int& new_airship_index) {
		if (m_data.airship_index == new_airship_index)
			return;
		m_data.airship_index = new_airship_index;
		emit airship_index_changed();
	}

	QString System::title_name() {
		return ToQString(m_data.title_name);
	}
	void System::set_title_name(const QString& new_title_name) {
		if (ToQString(m_data.title_name) == new_title_name)
			return;
		m_data.title_name = ToDBString(new_title_name);
		emit title_name_changed();
	}

	QString System::gameover_name() {
		return ToQString(m_data.gameover_name);
	}
	void System::set_gameover_name(const QString& new_gameover_name) {
		if (ToQString(m_data.gameover_name) == new_gameover_name)
			return;
		m_data.gameover_name = ToDBString(new_gameover_name);
		emit gameover_name_changed();
	}

	QString System::system_name() {
		return ToQString(m_data.system_name);
	}
	void System::set_system_name(const QString& new_system_name) {
		if (ToQString(m_data.system_name) == new_system_name)
			return;
		m_data.system_name = ToDBString(new_system_name);
		emit system_name_changed();
	}

	QString System::system2_name() {
		return ToQString(m_data.system2_name);
	}
	void System::set_system2_name(const QString& new_system2_name) {
		if (ToQString(m_data.system2_name) == new_system2_name)
			return;
		m_data.system2_name = ToDBString(new_system2_name);
		emit system2_name_changed();
	}

	QVector<int> System::party() {
		return QVector<int>(m_data.party.begin(), m_data.party.end());
	}
	void System::set_party(const QVector<int>& new_party) {
		if (QVector<int>(m_data.party.begin(), m_data.party.end()) == new_party)
			return;
		m_data.party = decltype(m_data.party)(new_party.begin(), new_party.end());
		emit party_changed();
	}

	QVector<int> System::menu_commands() {
		return QVector<int>(m_data.menu_commands.begin(), m_data.menu_commands.end());
	}
	void System::set_menu_commands(const QVector<int>& new_menu_commands) {
		if (QVector<int>(m_data.menu_commands.begin(), m_data.menu_commands.end()) == new_menu_commands)
			return;
		m_data.menu_commands = decltype(m_data.menu_commands)(new_menu_commands.begin(), new_menu_commands.end());
		emit menu_commands_changed();
	}

	Binding::Music* System::title_music() {
		return m_title_music;
	}

	Binding::Music* System::battle_music() {
		return m_battle_music;
	}

	Binding::Music* System::battle_end_music() {
		return m_battle_end_music;
	}

	Binding::Music* System::inn_music() {
		return m_inn_music;
	}

	Binding::Music* System::boat_music() {
		return m_boat_music;
	}

	Binding::Music* System::ship_music() {
		return m_ship_music;
	}

	Binding::Music* System::airship_music() {
		return m_airship_music;
	}

	Binding::Music* System::gameover_music() {
		return m_gameover_music;
	}

	Binding::Sound* System::cursor_se() {
		return m_cursor_se;
	}

	Binding::Sound* System::decision_se() {
		return m_decision_se;
	}

	Binding::Sound* System::cancel_se() {
		return m_cancel_se;
	}

	Binding::Sound* System::buzzer_se() {
		return m_buzzer_se;
	}

	Binding::Sound* System::battle_se() {
		return m_battle_se;
	}

	Binding::Sound* System::escape_se() {
		return m_escape_se;
	}

	Binding::Sound* System::enemy_attack_se() {
		return m_enemy_attack_se;
	}

	Binding::Sound* System::enemy_damaged_se() {
		return m_enemy_damaged_se;
	}

	Binding::Sound* System::actor_damaged_se() {
		return m_actor_damaged_se;
	}

	Binding::Sound* System::dodge_se() {
		return m_dodge_se;
	}

	Binding::Sound* System::enemy_death_se() {
		return m_enemy_death_se;
	}

	Binding::Sound* System::item_se() {
		return m_item_se;
	}

	int System::transition_out() {
		return m_data.transition_out;
	}
	void System::set_transition_out(const int& new_transition_out) {
		if (m_data.transition_out == new_transition_out)
			return;
		m_data.transition_out = new_transition_out;
		emit transition_out_changed();
	}

	int System::transition_in() {
		return m_data.transition_in;
	}
	void System::set_transition_in(const int& new_transition_in) {
		if (m_data.transition_in == new_transition_in)
			return;
		m_data.transition_in = new_transition_in;
		emit transition_in_changed();
	}

	int System::battle_start_fadeout() {
		return m_data.battle_start_fadeout;
	}
	void System::set_battle_start_fadeout(const int& new_battle_start_fadeout) {
		if (m_data.battle_start_fadeout == new_battle_start_fadeout)
			return;
		m_data.battle_start_fadeout = new_battle_start_fadeout;
		emit battle_start_fadeout_changed();
	}

	int System::battle_start_fadein() {
		return m_data.battle_start_fadein;
	}
	void System::set_battle_start_fadein(const int& new_battle_start_fadein) {
		if (m_data.battle_start_fadein == new_battle_start_fadein)
			return;
		m_data.battle_start_fadein = new_battle_start_fadein;
		emit battle_start_fadein_changed();
	}

	int System::battle_end_fadeout() {
		return m_data.battle_end_fadeout;
	}
	void System::set_battle_end_fadeout(const int& new_battle_end_fadeout) {
		if (m_data.battle_end_fadeout == new_battle_end_fadeout)
			return;
		m_data.battle_end_fadeout = new_battle_end_fadeout;
		emit battle_end_fadeout_changed();
	}

	int System::battle_end_fadein() {
		return m_data.battle_end_fadein;
	}
	void System::set_battle_end_fadein(const int& new_battle_end_fadein) {
		if (m_data.battle_end_fadein == new_battle_end_fadein)
			return;
		m_data.battle_end_fadein = new_battle_end_fadein;
		emit battle_end_fadein_changed();
	}

	int System::message_stretch() {
		return m_data.message_stretch;
	}
	void System::set_message_stretch(const int& new_message_stretch) {
		if (m_data.message_stretch == new_message_stretch)
			return;
		m_data.message_stretch = new_message_stretch;
		emit message_stretch_changed();
	}

	int System::font_id() {
		return m_data.font_id;
	}
	void System::set_font_id(const int& new_font_id) {
		if (m_data.font_id == new_font_id)
			return;
		m_data.font_id = new_font_id;
		emit font_id_changed();
	}

	int System::selected_condition() {
		return m_data.selected_condition;
	}
	void System::set_selected_condition(const int& new_selected_condition) {
		if (m_data.selected_condition == new_selected_condition)
			return;
		m_data.selected_condition = new_selected_condition;
		emit selected_condition_changed();
	}

	int System::selected_hero() {
		return m_data.selected_hero;
	}
	void System::set_selected_hero(const int& new_selected_hero) {
		if (m_data.selected_hero == new_selected_hero)
			return;
		m_data.selected_hero = new_selected_hero;
		emit selected_hero_changed();
	}

	QString System::battletest_background() {
		return ToQString(m_data.battletest_background);
	}
	void System::set_battletest_background(const QString& new_battletest_background) {
		if (ToQString(m_data.battletest_background) == new_battletest_background)
			return;
		m_data.battletest_background = ToDBString(new_battletest_background);
		emit battletest_background_changed();
	}

	ArrayAdapter* System::battletest_data() {
		return m_battletest_data;
	}

	int System::save_count() {
		return m_data.save_count;
	}
	void System::set_save_count(const int& new_save_count) {
		if (m_data.save_count == new_save_count)
			return;
		m_data.save_count = new_save_count;
		emit save_count_changed();
	}

	int System::battletest_terrain() {
		return m_data.battletest_terrain;
	}
	void System::set_battletest_terrain(const int& new_battletest_terrain) {
		if (m_data.battletest_terrain == new_battletest_terrain)
			return;
		m_data.battletest_terrain = new_battletest_terrain;
		emit battletest_terrain_changed();
	}

	int System::battletest_formation() {
		return m_data.battletest_formation;
	}
	void System::set_battletest_formation(const int& new_battletest_formation) {
		if (m_data.battletest_formation == new_battletest_formation)
			return;
		m_data.battletest_formation = new_battletest_formation;
		emit battletest_formation_changed();
	}

	int System::battletest_condition() {
		return m_data.battletest_condition;
	}
	void System::set_battletest_condition(const int& new_battletest_condition) {
		if (m_data.battletest_condition == new_battletest_condition)
			return;
		m_data.battletest_condition = new_battletest_condition;
		emit battletest_condition_changed();
	}

	int System::equipment_setting() {
		return m_data.equipment_setting;
	}
	void System::set_equipment_setting(const int& new_equipment_setting) {
		if (m_data.equipment_setting == new_equipment_setting)
			return;
		m_data.equipment_setting = new_equipment_setting;
		emit equipment_setting_changed();
	}

	int System::battletest_alt_terrain() {
		return m_data.battletest_alt_terrain;
	}
	void System::set_battletest_alt_terrain(const int& new_battletest_alt_terrain) {
		if (m_data.battletest_alt_terrain == new_battletest_alt_terrain)
			return;
		m_data.battletest_alt_terrain = new_battletest_alt_terrain;
		emit battletest_alt_terrain_changed();
	}

	bool System::show_frame() {
		return m_data.show_frame;
	}
	void System::set_show_frame(const bool& new_show_frame) {
		if (m_data.show_frame == new_show_frame)
			return;
		m_data.show_frame = new_show_frame;
		emit show_frame_changed();
	}

	QString System::frame_name() {
		return ToQString(m_data.frame_name);
	}
	void System::set_frame_name(const QString& new_frame_name) {
		if (ToQString(m_data.frame_name) == new_frame_name)
			return;
		m_data.frame_name = ToDBString(new_frame_name);
		emit frame_name_changed();
	}

	bool System::invert_animations() {
		return m_data.invert_animations;
	}
	void System::set_invert_animations(const bool& new_invert_animations) {
		if (m_data.invert_animations == new_invert_animations)
			return;
		m_data.invert_animations = new_invert_animations;
		emit invert_animations_changed();
	}

	bool System::show_title() {
		return m_data.show_title;
	}
	void System::set_show_title(const bool& new_show_title) {
		if (m_data.show_title == new_show_title)
			return;
		m_data.show_title = new_show_title;
		emit show_title_changed();
	}

	int System::easyrpg_alternative_exp() {
		return m_data.easyrpg_alternative_exp;
	}
	void System::set_easyrpg_alternative_exp(const int& new_easyrpg_alternative_exp) {
		if (m_data.easyrpg_alternative_exp == new_easyrpg_alternative_exp)
			return;
		m_data.easyrpg_alternative_exp = new_easyrpg_alternative_exp;
		emit easyrpg_alternative_exp_changed();
	}

	QVector<int> System::easyrpg_battle_options() {
		return QVector<int>(m_data.easyrpg_battle_options.begin(), m_data.easyrpg_battle_options.end());
	}
	void System::set_easyrpg_battle_options(const QVector<int>& new_easyrpg_battle_options) {
		if (QVector<int>(m_data.easyrpg_battle_options.begin(), m_data.easyrpg_battle_options.end()) == new_easyrpg_battle_options)
			return;
		m_data.easyrpg_battle_options = decltype(m_data.easyrpg_battle_options)(new_easyrpg_battle_options.begin(), new_easyrpg_battle_options.end());
		emit easyrpg_battle_options_changed();
	}

	int System::easyrpg_max_actor_hp() {
		return m_data.easyrpg_max_actor_hp;
	}
	void System::set_easyrpg_max_actor_hp(const int& new_easyrpg_max_actor_hp) {
		if (m_data.easyrpg_max_actor_hp == new_easyrpg_max_actor_hp)
			return;
		m_data.easyrpg_max_actor_hp = new_easyrpg_max_actor_hp;
		emit easyrpg_max_actor_hp_changed();
	}

	int System::easyrpg_max_enemy_hp() {
		return m_data.easyrpg_max_enemy_hp;
	}
	void System::set_easyrpg_max_enemy_hp(const int& new_easyrpg_max_enemy_hp) {
		if (m_data.easyrpg_max_enemy_hp == new_easyrpg_max_enemy_hp)
			return;
		m_data.easyrpg_max_enemy_hp = new_easyrpg_max_enemy_hp;
		emit easyrpg_max_enemy_hp_changed();
	}

	int System::easyrpg_max_damage() {
		return m_data.easyrpg_max_damage;
	}
	void System::set_easyrpg_max_damage(const int& new_easyrpg_max_damage) {
		if (m_data.easyrpg_max_damage == new_easyrpg_max_damage)
			return;
		m_data.easyrpg_max_damage = new_easyrpg_max_damage;
		emit easyrpg_max_damage_changed();
	}

	int System::easyrpg_max_exp() {
		return m_data.easyrpg_max_exp;
	}
	void System::set_easyrpg_max_exp(const int& new_easyrpg_max_exp) {
		if (m_data.easyrpg_max_exp == new_easyrpg_max_exp)
			return;
		m_data.easyrpg_max_exp = new_easyrpg_max_exp;
		emit easyrpg_max_exp_changed();
	}

	int System::easyrpg_max_level() {
		return m_data.easyrpg_max_level;
	}
	void System::set_easyrpg_max_level(const int& new_easyrpg_max_level) {
		if (m_data.easyrpg_max_level == new_easyrpg_max_level)
			return;
		m_data.easyrpg_max_level = new_easyrpg_max_level;
		emit easyrpg_max_level_changed();
	}

	int System::easyrpg_max_savefiles() {
		return m_data.easyrpg_max_savefiles;
	}
	void System::set_easyrpg_max_savefiles(const int& new_easyrpg_max_savefiles) {
		if (m_data.easyrpg_max_savefiles == new_easyrpg_max_savefiles)
			return;
		m_data.easyrpg_max_savefiles = new_easyrpg_max_savefiles;
		emit easyrpg_max_savefiles_changed();
	}

	int System::easyrpg_max_item_count() {
		return m_data.easyrpg_max_item_count;
	}
	void System::set_easyrpg_max_item_count(const int& new_easyrpg_max_item_count) {
		if (m_data.easyrpg_max_item_count == new_easyrpg_max_item_count)
			return;
		m_data.easyrpg_max_item_count = new_easyrpg_max_item_count;
		emit easyrpg_max_item_count_changed();
	}

	int System::easyrpg_variable_min_value() {
		return m_data.easyrpg_variable_min_value;
	}
	void System::set_easyrpg_variable_min_value(const int& new_easyrpg_variable_min_value) {
		if (m_data.easyrpg_variable_min_value == new_easyrpg_variable_min_value)
			return;
		m_data.easyrpg_variable_min_value = new_easyrpg_variable_min_value;
		emit easyrpg_variable_min_value_changed();
	}

	int System::easyrpg_variable_max_value() {
		return m_data.easyrpg_variable_max_value;
	}
	void System::set_easyrpg_variable_max_value(const int& new_easyrpg_variable_max_value) {
		if (m_data.easyrpg_variable_max_value == new_easyrpg_variable_max_value)
			return;
		m_data.easyrpg_variable_max_value = new_easyrpg_variable_max_value;
		emit easyrpg_variable_max_value_changed();
	}

	int System::easyrpg_max_actor_sp() {
		return m_data.easyrpg_max_actor_sp;
	}
	void System::set_easyrpg_max_actor_sp(const int& new_easyrpg_max_actor_sp) {
		if (m_data.easyrpg_max_actor_sp == new_easyrpg_max_actor_sp)
			return;
		m_data.easyrpg_max_actor_sp = new_easyrpg_max_actor_sp;
		emit easyrpg_max_actor_sp_changed();
	}

	int System::easyrpg_max_enemy_sp() {
		return m_data.easyrpg_max_enemy_sp;
	}
	void System::set_easyrpg_max_enemy_sp(const int& new_easyrpg_max_enemy_sp) {
		if (m_data.easyrpg_max_enemy_sp == new_easyrpg_max_enemy_sp)
			return;
		m_data.easyrpg_max_enemy_sp = new_easyrpg_max_enemy_sp;
		emit easyrpg_max_enemy_sp_changed();
	}

	int System::easyrpg_max_stat_base_value() {
		return m_data.easyrpg_max_stat_base_value;
	}
	void System::set_easyrpg_max_stat_base_value(const int& new_easyrpg_max_stat_base_value) {
		if (m_data.easyrpg_max_stat_base_value == new_easyrpg_max_stat_base_value)
			return;
		m_data.easyrpg_max_stat_base_value = new_easyrpg_max_stat_base_value;
		emit easyrpg_max_stat_base_value_changed();
	}

	int System::easyrpg_max_stat_battle_value() {
		return m_data.easyrpg_max_stat_battle_value;
	}
	void System::set_easyrpg_max_stat_battle_value(const int& new_easyrpg_max_stat_battle_value) {
		if (m_data.easyrpg_max_stat_battle_value == new_easyrpg_max_stat_battle_value)
			return;
		m_data.easyrpg_max_stat_battle_value = new_easyrpg_max_stat_battle_value;
		emit easyrpg_max_stat_battle_value_changed();
	}

	bool System::easyrpg_use_rpg2k_battle_system() {
		return m_data.easyrpg_use_rpg2k_battle_system;
	}
	void System::set_easyrpg_use_rpg2k_battle_system(const bool& new_easyrpg_use_rpg2k_battle_system) {
		if (m_data.easyrpg_use_rpg2k_battle_system == new_easyrpg_use_rpg2k_battle_system)
			return;
		m_data.easyrpg_use_rpg2k_battle_system = new_easyrpg_use_rpg2k_battle_system;
		emit easyrpg_use_rpg2k_battle_system_changed();
	}

	bool System::easyrpg_battle_use_rpg2ke_strings() {
		return m_data.easyrpg_battle_use_rpg2ke_strings;
	}
	void System::set_easyrpg_battle_use_rpg2ke_strings(const bool& new_easyrpg_battle_use_rpg2ke_strings) {
		if (m_data.easyrpg_battle_use_rpg2ke_strings == new_easyrpg_battle_use_rpg2ke_strings)
			return;
		m_data.easyrpg_battle_use_rpg2ke_strings = new_easyrpg_battle_use_rpg2ke_strings;
		emit easyrpg_battle_use_rpg2ke_strings_changed();
	}

	bool System::easyrpg_use_rpg2k_battle_commands() {
		return m_data.easyrpg_use_rpg2k_battle_commands;
	}
	void System::set_easyrpg_use_rpg2k_battle_commands(const bool& new_easyrpg_use_rpg2k_battle_commands) {
		if (m_data.easyrpg_use_rpg2k_battle_commands == new_easyrpg_use_rpg2k_battle_commands)
			return;
		m_data.easyrpg_use_rpg2k_battle_commands = new_easyrpg_use_rpg2k_battle_commands;
		emit easyrpg_use_rpg2k_battle_commands_changed();
	}

	int System::easyrpg_default_actorai() {
		return m_data.easyrpg_default_actorai;
	}
	void System::set_easyrpg_default_actorai(const int& new_easyrpg_default_actorai) {
		if (m_data.easyrpg_default_actorai == new_easyrpg_default_actorai)
			return;
		m_data.easyrpg_default_actorai = new_easyrpg_default_actorai;
		emit easyrpg_default_actorai_changed();
	}

	int System::easyrpg_default_enemyai() {
		return m_data.easyrpg_default_enemyai;
	}
	void System::set_easyrpg_default_enemyai(const int& new_easyrpg_default_enemyai) {
		if (m_data.easyrpg_default_enemyai == new_easyrpg_default_enemyai)
			return;
		m_data.easyrpg_default_enemyai = new_easyrpg_default_enemyai;
		emit easyrpg_default_enemyai_changed();
	}

} // namespace Binding::Generated
