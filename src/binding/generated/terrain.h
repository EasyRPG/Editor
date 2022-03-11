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
#include <lcf/rpg/terrain.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/sound.h"

class ProjectData;

/**
 * Binding::Generated::Terrain class.
 * Exposes lcf::rpg::Terrain to QML.
 */
namespace Binding::Generated {
class Terrain : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(int damage READ damage WRITE set_damage NOTIFY damage_changed)
	Q_PROPERTY(int encounter_rate READ encounter_rate WRITE set_encounter_rate NOTIFY encounter_rate_changed)
	Q_PROPERTY(QString background_name READ background_name WRITE set_background_name NOTIFY background_name_changed)
	Q_PROPERTY(bool boat_pass READ boat_pass WRITE set_boat_pass NOTIFY boat_pass_changed)
	Q_PROPERTY(bool ship_pass READ ship_pass WRITE set_ship_pass NOTIFY ship_pass_changed)
	Q_PROPERTY(bool airship_pass READ airship_pass WRITE set_airship_pass NOTIFY airship_pass_changed)
	Q_PROPERTY(bool airship_land READ airship_land WRITE set_airship_land NOTIFY airship_land_changed)
	Q_PROPERTY(int bush_depth READ bush_depth WRITE set_bush_depth NOTIFY bush_depth_changed)
	Q_PROPERTY(Binding::Sound* footstep READ footstep CONSTANT)
	Q_PROPERTY(bool on_damage_se READ on_damage_se WRITE set_on_damage_se NOTIFY on_damage_se_changed)
	Q_PROPERTY(int background_type READ background_type WRITE set_background_type NOTIFY background_type_changed)
	Q_PROPERTY(QString background_a_name READ background_a_name WRITE set_background_a_name NOTIFY background_a_name_changed)
	Q_PROPERTY(bool background_a_scrollh READ background_a_scrollh WRITE set_background_a_scrollh NOTIFY background_a_scrollh_changed)
	Q_PROPERTY(bool background_a_scrollv READ background_a_scrollv WRITE set_background_a_scrollv NOTIFY background_a_scrollv_changed)
	Q_PROPERTY(int background_a_scrollh_speed READ background_a_scrollh_speed WRITE set_background_a_scrollh_speed NOTIFY background_a_scrollh_speed_changed)
	Q_PROPERTY(int background_a_scrollv_speed READ background_a_scrollv_speed WRITE set_background_a_scrollv_speed NOTIFY background_a_scrollv_speed_changed)
	Q_PROPERTY(bool background_b READ background_b WRITE set_background_b NOTIFY background_b_changed)
	Q_PROPERTY(QString background_b_name READ background_b_name WRITE set_background_b_name NOTIFY background_b_name_changed)
	Q_PROPERTY(bool background_b_scrollh READ background_b_scrollh WRITE set_background_b_scrollh NOTIFY background_b_scrollh_changed)
	Q_PROPERTY(bool background_b_scrollv READ background_b_scrollv WRITE set_background_b_scrollv NOTIFY background_b_scrollv_changed)
	Q_PROPERTY(int background_b_scrollh_speed READ background_b_scrollh_speed WRITE set_background_b_scrollh_speed NOTIFY background_b_scrollh_speed_changed)
	Q_PROPERTY(int background_b_scrollv_speed READ background_b_scrollv_speed WRITE set_background_b_scrollv_speed NOTIFY background_b_scrollv_speed_changed)
	Q_PROPERTY(int special_back_party READ special_back_party WRITE set_special_back_party NOTIFY special_back_party_changed)
	Q_PROPERTY(int special_back_enemies READ special_back_enemies WRITE set_special_back_enemies NOTIFY special_back_enemies_changed)
	Q_PROPERTY(int special_lateral_party READ special_lateral_party WRITE set_special_lateral_party NOTIFY special_lateral_party_changed)
	Q_PROPERTY(int special_lateral_enemies READ special_lateral_enemies WRITE set_special_lateral_enemies NOTIFY special_lateral_enemies_changed)
	Q_PROPERTY(int grid_location READ grid_location WRITE set_grid_location NOTIFY grid_location_changed)
	Q_PROPERTY(int grid_top_y READ grid_top_y WRITE set_grid_top_y NOTIFY grid_top_y_changed)
	Q_PROPERTY(int grid_elongation READ grid_elongation WRITE set_grid_elongation NOTIFY grid_elongation_changed)
	Q_PROPERTY(int grid_inclination READ grid_inclination WRITE set_grid_inclination NOTIFY grid_inclination_changed)
	Q_PROPERTY(bool easyrpg_damage_in_percent READ easyrpg_damage_in_percent WRITE set_easyrpg_damage_in_percent NOTIFY easyrpg_damage_in_percent_changed)
	Q_PROPERTY(bool easyrpg_damage_can_kill READ easyrpg_damage_can_kill WRITE set_easyrpg_damage_can_kill NOTIFY easyrpg_damage_can_kill_changed)

public:
	Terrain(ProjectData& project, lcf::rpg::Terrain& data, QObject* parent = nullptr);

	lcf::rpg::Terrain& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	int damage();
	void set_damage(const int& new_damage);
	int encounter_rate();
	void set_encounter_rate(const int& new_encounter_rate);
	QString background_name();
	void set_background_name(const QString& new_background_name);
	bool boat_pass();
	void set_boat_pass(const bool& new_boat_pass);
	bool ship_pass();
	void set_ship_pass(const bool& new_ship_pass);
	bool airship_pass();
	void set_airship_pass(const bool& new_airship_pass);
	bool airship_land();
	void set_airship_land(const bool& new_airship_land);
	int bush_depth();
	void set_bush_depth(const int& new_bush_depth);
	Binding::Sound* footstep();
	bool on_damage_se();
	void set_on_damage_se(const bool& new_on_damage_se);
	int background_type();
	void set_background_type(const int& new_background_type);
	QString background_a_name();
	void set_background_a_name(const QString& new_background_a_name);
	bool background_a_scrollh();
	void set_background_a_scrollh(const bool& new_background_a_scrollh);
	bool background_a_scrollv();
	void set_background_a_scrollv(const bool& new_background_a_scrollv);
	int background_a_scrollh_speed();
	void set_background_a_scrollh_speed(const int& new_background_a_scrollh_speed);
	int background_a_scrollv_speed();
	void set_background_a_scrollv_speed(const int& new_background_a_scrollv_speed);
	bool background_b();
	void set_background_b(const bool& new_background_b);
	QString background_b_name();
	void set_background_b_name(const QString& new_background_b_name);
	bool background_b_scrollh();
	void set_background_b_scrollh(const bool& new_background_b_scrollh);
	bool background_b_scrollv();
	void set_background_b_scrollv(const bool& new_background_b_scrollv);
	int background_b_scrollh_speed();
	void set_background_b_scrollh_speed(const int& new_background_b_scrollh_speed);
	int background_b_scrollv_speed();
	void set_background_b_scrollv_speed(const int& new_background_b_scrollv_speed);
	int special_back_party();
	void set_special_back_party(const int& new_special_back_party);
	int special_back_enemies();
	void set_special_back_enemies(const int& new_special_back_enemies);
	int special_lateral_party();
	void set_special_lateral_party(const int& new_special_lateral_party);
	int special_lateral_enemies();
	void set_special_lateral_enemies(const int& new_special_lateral_enemies);
	int grid_location();
	void set_grid_location(const int& new_grid_location);
	int grid_top_y();
	void set_grid_top_y(const int& new_grid_top_y);
	int grid_elongation();
	void set_grid_elongation(const int& new_grid_elongation);
	int grid_inclination();
	void set_grid_inclination(const int& new_grid_inclination);
	bool easyrpg_damage_in_percent();
	void set_easyrpg_damage_in_percent(const bool& new_easyrpg_damage_in_percent);
	bool easyrpg_damage_can_kill();
	void set_easyrpg_damage_can_kill(const bool& new_easyrpg_damage_can_kill);

signals:
	void name_changed();
	void damage_changed();
	void encounter_rate_changed();
	void background_name_changed();
	void boat_pass_changed();
	void ship_pass_changed();
	void airship_pass_changed();
	void airship_land_changed();
	void bush_depth_changed();
	void on_damage_se_changed();
	void background_type_changed();
	void background_a_name_changed();
	void background_a_scrollh_changed();
	void background_a_scrollv_changed();
	void background_a_scrollh_speed_changed();
	void background_a_scrollv_speed_changed();
	void background_b_changed();
	void background_b_name_changed();
	void background_b_scrollh_changed();
	void background_b_scrollv_changed();
	void background_b_scrollh_speed_changed();
	void background_b_scrollv_speed_changed();
	void special_back_party_changed();
	void special_back_enemies_changed();
	void special_lateral_party_changed();
	void special_lateral_enemies_changed();
	void grid_location_changed();
	void grid_top_y_changed();
	void grid_elongation_changed();
	void grid_inclination_changed();
	void easyrpg_damage_in_percent_changed();
	void easyrpg_damage_can_kill_changed();

protected:
	lcf::rpg::Terrain& m_data;
	Binding::Sound* m_footstep;
};
} // namespace Binding::Generated
