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
#include "terrain.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Terrain::Terrain(ProjectData& project, lcf::rpg::Terrain& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_footstep = new Binding::Sound(m_project, m_data.footstep, this);
	}
	int Terrain::id() {
		return m_data.ID;
	}
	QString Terrain::name() {
		return ToQString(m_data.name);
	}
	void Terrain::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	int Terrain::damage() {
		return m_data.damage;
	}
	void Terrain::set_damage(const int& new_damage) {
		if (m_data.damage == new_damage)
			return;
		m_data.damage = new_damage;
		emit damage_changed();
	}

	int Terrain::encounter_rate() {
		return m_data.encounter_rate;
	}
	void Terrain::set_encounter_rate(const int& new_encounter_rate) {
		if (m_data.encounter_rate == new_encounter_rate)
			return;
		m_data.encounter_rate = new_encounter_rate;
		emit encounter_rate_changed();
	}

	QString Terrain::background_name() {
		return ToQString(m_data.background_name);
	}
	void Terrain::set_background_name(const QString& new_background_name) {
		if (ToQString(m_data.background_name) == new_background_name)
			return;
		m_data.background_name = ToDBString(new_background_name);
		emit background_name_changed();
	}

	bool Terrain::boat_pass() {
		return m_data.boat_pass;
	}
	void Terrain::set_boat_pass(const bool& new_boat_pass) {
		if (m_data.boat_pass == new_boat_pass)
			return;
		m_data.boat_pass = new_boat_pass;
		emit boat_pass_changed();
	}

	bool Terrain::ship_pass() {
		return m_data.ship_pass;
	}
	void Terrain::set_ship_pass(const bool& new_ship_pass) {
		if (m_data.ship_pass == new_ship_pass)
			return;
		m_data.ship_pass = new_ship_pass;
		emit ship_pass_changed();
	}

	bool Terrain::airship_pass() {
		return m_data.airship_pass;
	}
	void Terrain::set_airship_pass(const bool& new_airship_pass) {
		if (m_data.airship_pass == new_airship_pass)
			return;
		m_data.airship_pass = new_airship_pass;
		emit airship_pass_changed();
	}

	bool Terrain::airship_land() {
		return m_data.airship_land;
	}
	void Terrain::set_airship_land(const bool& new_airship_land) {
		if (m_data.airship_land == new_airship_land)
			return;
		m_data.airship_land = new_airship_land;
		emit airship_land_changed();
	}

	int Terrain::bush_depth() {
		return m_data.bush_depth;
	}
	void Terrain::set_bush_depth(const int& new_bush_depth) {
		if (m_data.bush_depth == new_bush_depth)
			return;
		m_data.bush_depth = new_bush_depth;
		emit bush_depth_changed();
	}

	Binding::Sound* Terrain::footstep() {
		return m_footstep;
	}

	bool Terrain::on_damage_se() {
		return m_data.on_damage_se;
	}
	void Terrain::set_on_damage_se(const bool& new_on_damage_se) {
		if (m_data.on_damage_se == new_on_damage_se)
			return;
		m_data.on_damage_se = new_on_damage_se;
		emit on_damage_se_changed();
	}

	int Terrain::background_type() {
		return m_data.background_type;
	}
	void Terrain::set_background_type(const int& new_background_type) {
		if (m_data.background_type == new_background_type)
			return;
		m_data.background_type = new_background_type;
		emit background_type_changed();
	}

	QString Terrain::background_a_name() {
		return ToQString(m_data.background_a_name);
	}
	void Terrain::set_background_a_name(const QString& new_background_a_name) {
		if (ToQString(m_data.background_a_name) == new_background_a_name)
			return;
		m_data.background_a_name = ToDBString(new_background_a_name);
		emit background_a_name_changed();
	}

	bool Terrain::background_a_scrollh() {
		return m_data.background_a_scrollh;
	}
	void Terrain::set_background_a_scrollh(const bool& new_background_a_scrollh) {
		if (m_data.background_a_scrollh == new_background_a_scrollh)
			return;
		m_data.background_a_scrollh = new_background_a_scrollh;
		emit background_a_scrollh_changed();
	}

	bool Terrain::background_a_scrollv() {
		return m_data.background_a_scrollv;
	}
	void Terrain::set_background_a_scrollv(const bool& new_background_a_scrollv) {
		if (m_data.background_a_scrollv == new_background_a_scrollv)
			return;
		m_data.background_a_scrollv = new_background_a_scrollv;
		emit background_a_scrollv_changed();
	}

	int Terrain::background_a_scrollh_speed() {
		return m_data.background_a_scrollh_speed;
	}
	void Terrain::set_background_a_scrollh_speed(const int& new_background_a_scrollh_speed) {
		if (m_data.background_a_scrollh_speed == new_background_a_scrollh_speed)
			return;
		m_data.background_a_scrollh_speed = new_background_a_scrollh_speed;
		emit background_a_scrollh_speed_changed();
	}

	int Terrain::background_a_scrollv_speed() {
		return m_data.background_a_scrollv_speed;
	}
	void Terrain::set_background_a_scrollv_speed(const int& new_background_a_scrollv_speed) {
		if (m_data.background_a_scrollv_speed == new_background_a_scrollv_speed)
			return;
		m_data.background_a_scrollv_speed = new_background_a_scrollv_speed;
		emit background_a_scrollv_speed_changed();
	}

	bool Terrain::background_b() {
		return m_data.background_b;
	}
	void Terrain::set_background_b(const bool& new_background_b) {
		if (m_data.background_b == new_background_b)
			return;
		m_data.background_b = new_background_b;
		emit background_b_changed();
	}

	QString Terrain::background_b_name() {
		return ToQString(m_data.background_b_name);
	}
	void Terrain::set_background_b_name(const QString& new_background_b_name) {
		if (ToQString(m_data.background_b_name) == new_background_b_name)
			return;
		m_data.background_b_name = ToDBString(new_background_b_name);
		emit background_b_name_changed();
	}

	bool Terrain::background_b_scrollh() {
		return m_data.background_b_scrollh;
	}
	void Terrain::set_background_b_scrollh(const bool& new_background_b_scrollh) {
		if (m_data.background_b_scrollh == new_background_b_scrollh)
			return;
		m_data.background_b_scrollh = new_background_b_scrollh;
		emit background_b_scrollh_changed();
	}

	bool Terrain::background_b_scrollv() {
		return m_data.background_b_scrollv;
	}
	void Terrain::set_background_b_scrollv(const bool& new_background_b_scrollv) {
		if (m_data.background_b_scrollv == new_background_b_scrollv)
			return;
		m_data.background_b_scrollv = new_background_b_scrollv;
		emit background_b_scrollv_changed();
	}

	int Terrain::background_b_scrollh_speed() {
		return m_data.background_b_scrollh_speed;
	}
	void Terrain::set_background_b_scrollh_speed(const int& new_background_b_scrollh_speed) {
		if (m_data.background_b_scrollh_speed == new_background_b_scrollh_speed)
			return;
		m_data.background_b_scrollh_speed = new_background_b_scrollh_speed;
		emit background_b_scrollh_speed_changed();
	}

	int Terrain::background_b_scrollv_speed() {
		return m_data.background_b_scrollv_speed;
	}
	void Terrain::set_background_b_scrollv_speed(const int& new_background_b_scrollv_speed) {
		if (m_data.background_b_scrollv_speed == new_background_b_scrollv_speed)
			return;
		m_data.background_b_scrollv_speed = new_background_b_scrollv_speed;
		emit background_b_scrollv_speed_changed();
	}

	int Terrain::special_back_party() {
		return m_data.special_back_party;
	}
	void Terrain::set_special_back_party(const int& new_special_back_party) {
		if (m_data.special_back_party == new_special_back_party)
			return;
		m_data.special_back_party = new_special_back_party;
		emit special_back_party_changed();
	}

	int Terrain::special_back_enemies() {
		return m_data.special_back_enemies;
	}
	void Terrain::set_special_back_enemies(const int& new_special_back_enemies) {
		if (m_data.special_back_enemies == new_special_back_enemies)
			return;
		m_data.special_back_enemies = new_special_back_enemies;
		emit special_back_enemies_changed();
	}

	int Terrain::special_lateral_party() {
		return m_data.special_lateral_party;
	}
	void Terrain::set_special_lateral_party(const int& new_special_lateral_party) {
		if (m_data.special_lateral_party == new_special_lateral_party)
			return;
		m_data.special_lateral_party = new_special_lateral_party;
		emit special_lateral_party_changed();
	}

	int Terrain::special_lateral_enemies() {
		return m_data.special_lateral_enemies;
	}
	void Terrain::set_special_lateral_enemies(const int& new_special_lateral_enemies) {
		if (m_data.special_lateral_enemies == new_special_lateral_enemies)
			return;
		m_data.special_lateral_enemies = new_special_lateral_enemies;
		emit special_lateral_enemies_changed();
	}

	int Terrain::grid_location() {
		return m_data.grid_location;
	}
	void Terrain::set_grid_location(const int& new_grid_location) {
		if (m_data.grid_location == new_grid_location)
			return;
		m_data.grid_location = new_grid_location;
		emit grid_location_changed();
	}

	int Terrain::grid_top_y() {
		return m_data.grid_top_y;
	}
	void Terrain::set_grid_top_y(const int& new_grid_top_y) {
		if (m_data.grid_top_y == new_grid_top_y)
			return;
		m_data.grid_top_y = new_grid_top_y;
		emit grid_top_y_changed();
	}

	int Terrain::grid_elongation() {
		return m_data.grid_elongation;
	}
	void Terrain::set_grid_elongation(const int& new_grid_elongation) {
		if (m_data.grid_elongation == new_grid_elongation)
			return;
		m_data.grid_elongation = new_grid_elongation;
		emit grid_elongation_changed();
	}

	int Terrain::grid_inclination() {
		return m_data.grid_inclination;
	}
	void Terrain::set_grid_inclination(const int& new_grid_inclination) {
		if (m_data.grid_inclination == new_grid_inclination)
			return;
		m_data.grid_inclination = new_grid_inclination;
		emit grid_inclination_changed();
	}

	bool Terrain::easyrpg_damage_in_percent() {
		return m_data.easyrpg_damage_in_percent;
	}
	void Terrain::set_easyrpg_damage_in_percent(const bool& new_easyrpg_damage_in_percent) {
		if (m_data.easyrpg_damage_in_percent == new_easyrpg_damage_in_percent)
			return;
		m_data.easyrpg_damage_in_percent = new_easyrpg_damage_in_percent;
		emit easyrpg_damage_in_percent_changed();
	}

	bool Terrain::easyrpg_damage_can_kill() {
		return m_data.easyrpg_damage_can_kill;
	}
	void Terrain::set_easyrpg_damage_can_kill(const bool& new_easyrpg_damage_can_kill) {
		if (m_data.easyrpg_damage_can_kill == new_easyrpg_damage_can_kill)
			return;
		m_data.easyrpg_damage_can_kill = new_easyrpg_damage_can_kill;
		emit easyrpg_damage_can_kill_changed();
	}

} // namespace Binding::Generated
