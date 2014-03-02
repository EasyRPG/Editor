/*
 * This file is part of EasyRPG.
 *
 * EasyRPG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

// Headers
#include "reader_options.h"
#include "rpg_actor.h"
#include "rpg_event.h"
#include "rpg_map.h"
#include "rpg_mapinfo.h"
#include "rpg_system.h"
#include "rpg_save.h"
#include "rpg_chipset.h"
#include "rpg_parameters.h"
#include "data.h"

void RPG::SaveActor::Setup(int actor_id) {
	const RPG::Actor& actor = Data::actors[actor_id - 1];
	ID = actor.ID;
	name = actor.name;
	title = actor.title;
	sprite_name = actor.character_name;
	sprite_id = actor.character_index;
	sprite_flags = actor.transparent ? 3 : 0;
	face_name = actor.face_name;
	face_id = actor.face_index;
	level = actor.initial_level;
	exp = 0;
	hp_mod = 0;
	sp_mod = 0;
	attack_mod = 0;
	defense_mod = 0;
	spirit_mod = 0;
	agility_mod = 0;
	skills_size = 0;
	skills.clear();
	equipped.clear();
	equipped.push_back(actor.initial_equipment.weapon_id);
	equipped.push_back(actor.initial_equipment.shield_id);
	equipped.push_back(actor.initial_equipment.armor_id);
	equipped.push_back(actor.initial_equipment.helmet_id);
	equipped.push_back(actor.initial_equipment.accessory_id);
	current_hp = 0;
	current_sp = 0;
	battle_commands = actor.battle_commands;
	status_size = 0;
	status.clear();
	changed_class = false;
	class_id = actor.class_id;
	row = -1;
	two_weapon = actor.two_swords_style;
	lock_equipment = actor.fix_equipment;
	auto_battle = actor.auto_battle;
	mighty_guard = actor.super_guard;
	unknown_60 = -1;
}

void RPG::SaveInventory::Setup() {
	party = Data::system.party;
	party_size = party.size();
}

void RPG::SaveMapEvent::Setup(const RPG::Event& event) {
	ID = event.ID;
	position_x = event.x;
	position_y = event.y;
}

void RPG::SaveMapInfo::Setup() {
	position_x = 0;
	position_y = 0;
	lower_tiles.resize(144);
	upper_tiles.resize(144);
	for (int i = 0; i < 144; i++) {
		lower_tiles[i] = i;
		upper_tiles[i] = i;
	}
}

void RPG::SaveMapInfo::Setup(const RPG::Map& map) {
	chipset_id = map.chipset_id;
	parallax_name = map.parallax_name;
	parallax_horz = map.parallax_loop_x;
	parallax_vert = map.parallax_loop_y;
	parallax_horz_auto = map.parallax_auto_loop_x;
	parallax_vert_auto = map.parallax_auto_loop_y;
	parallax_horz_speed = map.parallax_sx;
	parallax_vert_speed = map.parallax_sy;
}

void RPG::SaveMapInfo::Setup(const RPG::MapInfo& map_info) {
	encounter_rate = map_info.encounter_steps;
}

void RPG::SaveSystem::Setup() {
	const RPG::System& system = Data::system;
	screen = 0;
	frame_count = 0;
	graphics_name = system.system_name;
	switches_size = Data::switches.size();
	switches.clear();
	switches.resize(switches_size);
	variables_size = Data::variables.size();
	variables.clear();
	variables.resize(variables_size);
	face_name = "";
	face_id = -1;
	face_right = false;
	face_flip = false;
	transparent = false;
	unknown_3d = -1;
	title_music = system.title_music;
	battle_music = system.battle_music;
	battle_end_music = system.battle_end_music;
	inn_music = system.inn_music;
	// current_music
	// unknown1_music FIXME
	// unknown2_music FIXME
	// stored_music
	boat_music = system.boat_music;
	ship_music = system.ship_music;
	airship_music = system.airship_music;
	gameover_music = system.gameover_music;
	cursor_se = system.cursor_se;
	decision_se = system.decision_se;
	cancel_se = system.cancel_se;
	buzzer_se = system.buzzer_se;
	battle_se = system.battle_se;
	escape_se = system.escape_se;
	enemy_attack_se = system.enemy_attack_se;
	enemy_damaged_se = system.enemy_damaged_se;
	actor_damaged_se = system.actor_damaged_se;
	dodge_se = system.dodge_se;
	enemy_death_se = system.enemy_death_se;
	item_se = system.item_se;
	transition_out = system.transition_out;
	transition_in = system.transition_in;
	battle_start_fadeout = system.battle_start_fadeout;
	battle_start_fadein = system.battle_start_fadein;
	battle_end_fadeout = system.battle_end_fadeout;
	battle_end_fadein = system.battle_end_fadein;
	teleport_allowed = true;
	escape_allowed = true;
	save_allowed = true;
	menu_allowed = true;
	background = "";
	save_count = 0;
	save_slot = -1;
}

void RPG::Save::Setup() {
	system.Setup();
	screen = RPG::SaveScreen();
	pictures.clear();
	pictures.resize(50);
	for (int i = 1; i <= (int)pictures.size(); i++) {
		pictures[i - 1].ID = i;
	}
	actors.clear();
	actors.resize(Data::actors.size());
	for (int i = 1; i <= (int) actors.size(); i++)
		actors[i - 1].Setup(i);
	map_info.Setup();
}

void RPG::Actor::Init() {
#if RPGMAKER == RPG2K3
	final_level = 99;
	exp_base = 300;
	exp_inflation = 300;
#endif
	parameters.Setup(final_level);
}

void RPG::MapInfo::Init() {
	music.name = "(OFF)";
}

void RPG::Chipset::Init() {
	terrain_data.resize(162, 1);
	passable_data_lower.resize(162, 15);
	passable_data_upper.resize(162, 15);
}

void RPG::Parameters::Setup(int final_level) {
	maxhp.resize(final_level + 1);
	maxsp.resize(final_level + 1);
	attack.resize(final_level + 1);
	defense.resize(final_level + 1);
	spirit.resize(final_level + 1);
	agility.resize(final_level + 1);
	for (int i = 0; i <= final_level; i++) {
		maxhp[i] = 1;
		maxsp[i] = 0;
		attack[i] = 1;
		defense[i] = 1;
		spirit[i] = 1;
		agility[i] = 1;
	}
}
