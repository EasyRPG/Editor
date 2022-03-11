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
#include <lcf/rpg/system.h>
#include "binding/binding_base.h"
#include "binding/sound.h"
#include "binding/music.h"
#include "binding/music.h"
#include "binding/music.h"
#include "binding/sound.h"
#include "binding/testbattler.h"
#include "binding/music.h"
#include "binding/sound.h"
#include "binding/sound.h"
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

class ProjectData;

/**
 * Binding::Generated::System class.
 * Exposes lcf::rpg::System to QML.
 */
namespace Binding::Generated {
class System : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int ldb_id READ ldb_id WRITE set_ldb_id NOTIFY ldb_id_changed)
	Q_PROPERTY(QString boat_name READ boat_name WRITE set_boat_name NOTIFY boat_name_changed)
	Q_PROPERTY(QString ship_name READ ship_name WRITE set_ship_name NOTIFY ship_name_changed)
	Q_PROPERTY(QString airship_name READ airship_name WRITE set_airship_name NOTIFY airship_name_changed)
	Q_PROPERTY(int boat_index READ boat_index WRITE set_boat_index NOTIFY boat_index_changed)
	Q_PROPERTY(int ship_index READ ship_index WRITE set_ship_index NOTIFY ship_index_changed)
	Q_PROPERTY(int airship_index READ airship_index WRITE set_airship_index NOTIFY airship_index_changed)
	Q_PROPERTY(QString title_name READ title_name WRITE set_title_name NOTIFY title_name_changed)
	Q_PROPERTY(QString gameover_name READ gameover_name WRITE set_gameover_name NOTIFY gameover_name_changed)
	Q_PROPERTY(QString system_name READ system_name WRITE set_system_name NOTIFY system_name_changed)
	Q_PROPERTY(QString system2_name READ system2_name WRITE set_system2_name NOTIFY system2_name_changed)
	Q_PROPERTY(QVector<int> party READ party WRITE set_party NOTIFY party_changed)
	Q_PROPERTY(QVector<int> menu_commands READ menu_commands WRITE set_menu_commands NOTIFY menu_commands_changed)
	Q_PROPERTY(Binding::Music* title_music READ title_music CONSTANT)
	Q_PROPERTY(Binding::Music* battle_music READ battle_music CONSTANT)
	Q_PROPERTY(Binding::Music* battle_end_music READ battle_end_music CONSTANT)
	Q_PROPERTY(Binding::Music* inn_music READ inn_music CONSTANT)
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
	Q_PROPERTY(int32_t transition_out READ transition_out CONSTANT)
	Q_PROPERTY(int32_t transition_in READ transition_in CONSTANT)
	Q_PROPERTY(int32_t battle_start_fadeout READ battle_start_fadeout CONSTANT)
	Q_PROPERTY(int32_t battle_start_fadein READ battle_start_fadein CONSTANT)
	Q_PROPERTY(int32_t battle_end_fadeout READ battle_end_fadeout CONSTANT)
	Q_PROPERTY(int32_t battle_end_fadein READ battle_end_fadein CONSTANT)
	Q_PROPERTY(int32_t message_stretch READ message_stretch CONSTANT)
	Q_PROPERTY(int32_t font_id READ font_id CONSTANT)
	Q_PROPERTY(int selected_condition READ selected_condition WRITE set_selected_condition NOTIFY selected_condition_changed)
	Q_PROPERTY(int32_t selected_hero READ selected_hero CONSTANT)
	Q_PROPERTY(QString battletest_background READ battletest_background WRITE set_battletest_background NOTIFY battletest_background_changed)
	Q_PROPERTY(QVector<Binding::TestBattler*> battletest_data READ battletest_data CONSTANT)
	Q_PROPERTY(int save_count READ save_count WRITE set_save_count NOTIFY save_count_changed)
	Q_PROPERTY(int32_t battletest_terrain READ battletest_terrain CONSTANT)
	Q_PROPERTY(int32_t battletest_formation READ battletest_formation CONSTANT)
	Q_PROPERTY(int32_t battletest_condition READ battletest_condition CONSTANT)
	Q_PROPERTY(int32_t equipment_setting READ equipment_setting CONSTANT)
	Q_PROPERTY(int32_t battletest_alt_terrain READ battletest_alt_terrain CONSTANT)
	Q_PROPERTY(bool show_frame READ show_frame WRITE set_show_frame NOTIFY show_frame_changed)
	Q_PROPERTY(QString frame_name READ frame_name WRITE set_frame_name NOTIFY frame_name_changed)
	Q_PROPERTY(bool invert_animations READ invert_animations WRITE set_invert_animations NOTIFY invert_animations_changed)
	Q_PROPERTY(bool show_title READ show_title WRITE set_show_title NOTIFY show_title_changed)
	Q_PROPERTY(int easyrpg_alternative_exp READ easyrpg_alternative_exp WRITE set_easyrpg_alternative_exp NOTIFY easyrpg_alternative_exp_changed)
	Q_PROPERTY(QVector<int> easyrpg_battle_options READ easyrpg_battle_options WRITE set_easyrpg_battle_options NOTIFY easyrpg_battle_options_changed)
	Q_PROPERTY(int easyrpg_max_actor_hp READ easyrpg_max_actor_hp WRITE set_easyrpg_max_actor_hp NOTIFY easyrpg_max_actor_hp_changed)
	Q_PROPERTY(int easyrpg_max_enemy_hp READ easyrpg_max_enemy_hp WRITE set_easyrpg_max_enemy_hp NOTIFY easyrpg_max_enemy_hp_changed)
	Q_PROPERTY(int easyrpg_max_damage READ easyrpg_max_damage WRITE set_easyrpg_max_damage NOTIFY easyrpg_max_damage_changed)
	Q_PROPERTY(int easyrpg_max_exp READ easyrpg_max_exp WRITE set_easyrpg_max_exp NOTIFY easyrpg_max_exp_changed)
	Q_PROPERTY(int easyrpg_max_level READ easyrpg_max_level WRITE set_easyrpg_max_level NOTIFY easyrpg_max_level_changed)
	Q_PROPERTY(int easyrpg_max_savefiles READ easyrpg_max_savefiles WRITE set_easyrpg_max_savefiles NOTIFY easyrpg_max_savefiles_changed)
	Q_PROPERTY(int easyrpg_max_item_count READ easyrpg_max_item_count WRITE set_easyrpg_max_item_count NOTIFY easyrpg_max_item_count_changed)
	Q_PROPERTY(int easyrpg_variable_min_value READ easyrpg_variable_min_value WRITE set_easyrpg_variable_min_value NOTIFY easyrpg_variable_min_value_changed)
	Q_PROPERTY(int easyrpg_variable_max_value READ easyrpg_variable_max_value WRITE set_easyrpg_variable_max_value NOTIFY easyrpg_variable_max_value_changed)
	Q_PROPERTY(int easyrpg_max_actor_sp READ easyrpg_max_actor_sp WRITE set_easyrpg_max_actor_sp NOTIFY easyrpg_max_actor_sp_changed)
	Q_PROPERTY(int easyrpg_max_enemy_sp READ easyrpg_max_enemy_sp WRITE set_easyrpg_max_enemy_sp NOTIFY easyrpg_max_enemy_sp_changed)
	Q_PROPERTY(int easyrpg_max_stat_base_value READ easyrpg_max_stat_base_value WRITE set_easyrpg_max_stat_base_value NOTIFY easyrpg_max_stat_base_value_changed)
	Q_PROPERTY(int easyrpg_max_stat_battle_value READ easyrpg_max_stat_battle_value WRITE set_easyrpg_max_stat_battle_value NOTIFY easyrpg_max_stat_battle_value_changed)
	Q_PROPERTY(bool easyrpg_use_rpg2k_battle_system READ easyrpg_use_rpg2k_battle_system WRITE set_easyrpg_use_rpg2k_battle_system NOTIFY easyrpg_use_rpg2k_battle_system_changed)
	Q_PROPERTY(bool easyrpg_battle_use_rpg2ke_strings READ easyrpg_battle_use_rpg2ke_strings WRITE set_easyrpg_battle_use_rpg2ke_strings NOTIFY easyrpg_battle_use_rpg2ke_strings_changed)
	Q_PROPERTY(bool easyrpg_use_rpg2k_battle_commands READ easyrpg_use_rpg2k_battle_commands WRITE set_easyrpg_use_rpg2k_battle_commands NOTIFY easyrpg_use_rpg2k_battle_commands_changed)
	Q_PROPERTY(int easyrpg_default_actorai READ easyrpg_default_actorai WRITE set_easyrpg_default_actorai NOTIFY easyrpg_default_actorai_changed)
	Q_PROPERTY(int easyrpg_default_enemyai READ easyrpg_default_enemyai WRITE set_easyrpg_default_enemyai NOTIFY easyrpg_default_enemyai_changed)

public:
	System(ProjectData& project, lcf::rpg::System& data, QObject* parent = nullptr);

	lcf::rpg::System& data();
	int ldb_id();
	void set_ldb_id(const int& new_ldb_id);
	QString boat_name();
	void set_boat_name(const QString& new_boat_name);
	QString ship_name();
	void set_ship_name(const QString& new_ship_name);
	QString airship_name();
	void set_airship_name(const QString& new_airship_name);
	int boat_index();
	void set_boat_index(const int& new_boat_index);
	int ship_index();
	void set_ship_index(const int& new_ship_index);
	int airship_index();
	void set_airship_index(const int& new_airship_index);
	QString title_name();
	void set_title_name(const QString& new_title_name);
	QString gameover_name();
	void set_gameover_name(const QString& new_gameover_name);
	QString system_name();
	void set_system_name(const QString& new_system_name);
	QString system2_name();
	void set_system2_name(const QString& new_system2_name);
	QVector<int> party();
	void set_party(const QVector<int>& new_party);
	QVector<int> menu_commands();
	void set_menu_commands(const QVector<int>& new_menu_commands);
	Binding::Music* title_music();
	Binding::Music* battle_music();
	Binding::Music* battle_end_music();
	Binding::Music* inn_music();
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
	int32_t transition_out();
	int32_t transition_in();
	int32_t battle_start_fadeout();
	int32_t battle_start_fadein();
	int32_t battle_end_fadeout();
	int32_t battle_end_fadein();
	int32_t message_stretch();
	int32_t font_id();
	int selected_condition();
	void set_selected_condition(const int& new_selected_condition);
	int32_t selected_hero();
	QString battletest_background();
	void set_battletest_background(const QString& new_battletest_background);
	QVector<Binding::TestBattler*>& battletest_data();
	int save_count();
	void set_save_count(const int& new_save_count);
	int32_t battletest_terrain();
	int32_t battletest_formation();
	int32_t battletest_condition();
	int32_t equipment_setting();
	int32_t battletest_alt_terrain();
	bool show_frame();
	void set_show_frame(const bool& new_show_frame);
	QString frame_name();
	void set_frame_name(const QString& new_frame_name);
	bool invert_animations();
	void set_invert_animations(const bool& new_invert_animations);
	bool show_title();
	void set_show_title(const bool& new_show_title);
	int easyrpg_alternative_exp();
	void set_easyrpg_alternative_exp(const int& new_easyrpg_alternative_exp);
	QVector<int> easyrpg_battle_options();
	void set_easyrpg_battle_options(const QVector<int>& new_easyrpg_battle_options);
	int easyrpg_max_actor_hp();
	void set_easyrpg_max_actor_hp(const int& new_easyrpg_max_actor_hp);
	int easyrpg_max_enemy_hp();
	void set_easyrpg_max_enemy_hp(const int& new_easyrpg_max_enemy_hp);
	int easyrpg_max_damage();
	void set_easyrpg_max_damage(const int& new_easyrpg_max_damage);
	int easyrpg_max_exp();
	void set_easyrpg_max_exp(const int& new_easyrpg_max_exp);
	int easyrpg_max_level();
	void set_easyrpg_max_level(const int& new_easyrpg_max_level);
	int easyrpg_max_savefiles();
	void set_easyrpg_max_savefiles(const int& new_easyrpg_max_savefiles);
	int easyrpg_max_item_count();
	void set_easyrpg_max_item_count(const int& new_easyrpg_max_item_count);
	int easyrpg_variable_min_value();
	void set_easyrpg_variable_min_value(const int& new_easyrpg_variable_min_value);
	int easyrpg_variable_max_value();
	void set_easyrpg_variable_max_value(const int& new_easyrpg_variable_max_value);
	int easyrpg_max_actor_sp();
	void set_easyrpg_max_actor_sp(const int& new_easyrpg_max_actor_sp);
	int easyrpg_max_enemy_sp();
	void set_easyrpg_max_enemy_sp(const int& new_easyrpg_max_enemy_sp);
	int easyrpg_max_stat_base_value();
	void set_easyrpg_max_stat_base_value(const int& new_easyrpg_max_stat_base_value);
	int easyrpg_max_stat_battle_value();
	void set_easyrpg_max_stat_battle_value(const int& new_easyrpg_max_stat_battle_value);
	bool easyrpg_use_rpg2k_battle_system();
	void set_easyrpg_use_rpg2k_battle_system(const bool& new_easyrpg_use_rpg2k_battle_system);
	bool easyrpg_battle_use_rpg2ke_strings();
	void set_easyrpg_battle_use_rpg2ke_strings(const bool& new_easyrpg_battle_use_rpg2ke_strings);
	bool easyrpg_use_rpg2k_battle_commands();
	void set_easyrpg_use_rpg2k_battle_commands(const bool& new_easyrpg_use_rpg2k_battle_commands);
	int easyrpg_default_actorai();
	void set_easyrpg_default_actorai(const int& new_easyrpg_default_actorai);
	int easyrpg_default_enemyai();
	void set_easyrpg_default_enemyai(const int& new_easyrpg_default_enemyai);

signals:
	void ldb_id_changed();
	void boat_name_changed();
	void ship_name_changed();
	void airship_name_changed();
	void boat_index_changed();
	void ship_index_changed();
	void airship_index_changed();
	void title_name_changed();
	void gameover_name_changed();
	void system_name_changed();
	void system2_name_changed();
	void party_changed();
	void menu_commands_changed();
	void selected_condition_changed();
	void battletest_background_changed();
	void save_count_changed();
	void show_frame_changed();
	void frame_name_changed();
	void invert_animations_changed();
	void show_title_changed();
	void easyrpg_alternative_exp_changed();
	void easyrpg_battle_options_changed();
	void easyrpg_max_actor_hp_changed();
	void easyrpg_max_enemy_hp_changed();
	void easyrpg_max_damage_changed();
	void easyrpg_max_exp_changed();
	void easyrpg_max_level_changed();
	void easyrpg_max_savefiles_changed();
	void easyrpg_max_item_count_changed();
	void easyrpg_variable_min_value_changed();
	void easyrpg_variable_max_value_changed();
	void easyrpg_max_actor_sp_changed();
	void easyrpg_max_enemy_sp_changed();
	void easyrpg_max_stat_base_value_changed();
	void easyrpg_max_stat_battle_value_changed();
	void easyrpg_use_rpg2k_battle_system_changed();
	void easyrpg_battle_use_rpg2ke_strings_changed();
	void easyrpg_use_rpg2k_battle_commands_changed();
	void easyrpg_default_actorai_changed();
	void easyrpg_default_enemyai_changed();

protected:
	lcf::rpg::System& m_data;
	Binding::Music* m_title_music;
	Binding::Music* m_battle_music;
	Binding::Music* m_battle_end_music;
	Binding::Music* m_inn_music;
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
	QVector<Binding::TestBattler*> m_battletest_data;
};
} // namespace Binding::Generated
