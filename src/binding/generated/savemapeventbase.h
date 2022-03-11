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
#include <lcf/rpg/savemapeventbase.h>
#include "binding/binding_base.h"
#include "binding/moveroute.h"

class ProjectData;

/**
 * Binding::Generated::SaveMapEventBase class.
 * Exposes lcf::rpg::SaveMapEventBase to QML.
 */
namespace Binding::Generated {
class SaveMapEventBase : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(bool active READ active WRITE set_active NOTIFY active_changed)
	Q_PROPERTY(int map_id READ map_id WRITE set_map_id NOTIFY map_id_changed)
	Q_PROPERTY(int position_x READ position_x WRITE set_position_x NOTIFY position_x_changed)
	Q_PROPERTY(int position_y READ position_y WRITE set_position_y NOTIFY position_y_changed)
	Q_PROPERTY(int direction READ direction WRITE set_direction NOTIFY direction_changed)
	Q_PROPERTY(int sprite_direction READ sprite_direction WRITE set_sprite_direction NOTIFY sprite_direction_changed)
	Q_PROPERTY(int anim_frame READ anim_frame WRITE set_anim_frame NOTIFY anim_frame_changed)
	Q_PROPERTY(int transparency READ transparency WRITE set_transparency NOTIFY transparency_changed)
	Q_PROPERTY(int remaining_step READ remaining_step WRITE set_remaining_step NOTIFY remaining_step_changed)
	Q_PROPERTY(int move_frequency READ move_frequency WRITE set_move_frequency NOTIFY move_frequency_changed)
	Q_PROPERTY(int layer READ layer WRITE set_layer NOTIFY layer_changed)
	Q_PROPERTY(bool overlap_forbidden READ overlap_forbidden WRITE set_overlap_forbidden NOTIFY overlap_forbidden_changed)
	Q_PROPERTY(int32_t animation_type READ animation_type CONSTANT)
	Q_PROPERTY(bool lock_facing READ lock_facing WRITE set_lock_facing NOTIFY lock_facing_changed)
	Q_PROPERTY(int move_speed READ move_speed WRITE set_move_speed NOTIFY move_speed_changed)
	Q_PROPERTY(Binding::MoveRoute* move_route READ move_route CONSTANT)
	Q_PROPERTY(bool move_route_overwrite READ move_route_overwrite WRITE set_move_route_overwrite NOTIFY move_route_overwrite_changed)
	Q_PROPERTY(int move_route_index READ move_route_index WRITE set_move_route_index NOTIFY move_route_index_changed)
	Q_PROPERTY(bool move_route_repeated READ move_route_repeated WRITE set_move_route_repeated NOTIFY move_route_repeated_changed)
	Q_PROPERTY(bool sprite_transparent READ sprite_transparent WRITE set_sprite_transparent NOTIFY sprite_transparent_changed)
	Q_PROPERTY(bool route_through READ route_through WRITE set_route_through NOTIFY route_through_changed)
	Q_PROPERTY(int anim_paused READ anim_paused WRITE set_anim_paused NOTIFY anim_paused_changed)
	Q_PROPERTY(bool through READ through WRITE set_through NOTIFY through_changed)
	Q_PROPERTY(int stop_count READ stop_count WRITE set_stop_count NOTIFY stop_count_changed)
	Q_PROPERTY(int anim_count READ anim_count WRITE set_anim_count NOTIFY anim_count_changed)
	Q_PROPERTY(int max_stop_count READ max_stop_count WRITE set_max_stop_count NOTIFY max_stop_count_changed)
	Q_PROPERTY(bool jumping READ jumping WRITE set_jumping NOTIFY jumping_changed)
	Q_PROPERTY(int begin_jump_x READ begin_jump_x WRITE set_begin_jump_x NOTIFY begin_jump_x_changed)
	Q_PROPERTY(int begin_jump_y READ begin_jump_y WRITE set_begin_jump_y NOTIFY begin_jump_y_changed)
	Q_PROPERTY(bool pause READ pause WRITE set_pause NOTIFY pause_changed)
	Q_PROPERTY(bool flying READ flying WRITE set_flying NOTIFY flying_changed)
	Q_PROPERTY(QString sprite_name READ sprite_name WRITE set_sprite_name NOTIFY sprite_name_changed)
	Q_PROPERTY(int sprite_id READ sprite_id WRITE set_sprite_id NOTIFY sprite_id_changed)
	Q_PROPERTY(bool processed READ processed WRITE set_processed NOTIFY processed_changed)
	Q_PROPERTY(int flash_red READ flash_red WRITE set_flash_red NOTIFY flash_red_changed)
	Q_PROPERTY(int flash_green READ flash_green WRITE set_flash_green NOTIFY flash_green_changed)
	Q_PROPERTY(int flash_blue READ flash_blue WRITE set_flash_blue NOTIFY flash_blue_changed)
	Q_PROPERTY(double flash_current_level READ flash_current_level WRITE set_flash_current_level NOTIFY flash_current_level_changed)
	Q_PROPERTY(int flash_time_left READ flash_time_left WRITE set_flash_time_left NOTIFY flash_time_left_changed)

public:
	SaveMapEventBase(ProjectData& project, lcf::rpg::SaveMapEventBase& data, QObject* parent = nullptr);

	lcf::rpg::SaveMapEventBase& data();
	bool active();
	void set_active(const bool& new_active);
	int map_id();
	void set_map_id(const int& new_map_id);
	int position_x();
	void set_position_x(const int& new_position_x);
	int position_y();
	void set_position_y(const int& new_position_y);
	int direction();
	void set_direction(const int& new_direction);
	int sprite_direction();
	void set_sprite_direction(const int& new_sprite_direction);
	int anim_frame();
	void set_anim_frame(const int& new_anim_frame);
	int transparency();
	void set_transparency(const int& new_transparency);
	int remaining_step();
	void set_remaining_step(const int& new_remaining_step);
	int move_frequency();
	void set_move_frequency(const int& new_move_frequency);
	int layer();
	void set_layer(const int& new_layer);
	bool overlap_forbidden();
	void set_overlap_forbidden(const bool& new_overlap_forbidden);
	int32_t animation_type();
	bool lock_facing();
	void set_lock_facing(const bool& new_lock_facing);
	int move_speed();
	void set_move_speed(const int& new_move_speed);
	Binding::MoveRoute* move_route();
	bool move_route_overwrite();
	void set_move_route_overwrite(const bool& new_move_route_overwrite);
	int move_route_index();
	void set_move_route_index(const int& new_move_route_index);
	bool move_route_repeated();
	void set_move_route_repeated(const bool& new_move_route_repeated);
	bool sprite_transparent();
	void set_sprite_transparent(const bool& new_sprite_transparent);
	bool route_through();
	void set_route_through(const bool& new_route_through);
	int anim_paused();
	void set_anim_paused(const int& new_anim_paused);
	bool through();
	void set_through(const bool& new_through);
	int stop_count();
	void set_stop_count(const int& new_stop_count);
	int anim_count();
	void set_anim_count(const int& new_anim_count);
	int max_stop_count();
	void set_max_stop_count(const int& new_max_stop_count);
	bool jumping();
	void set_jumping(const bool& new_jumping);
	int begin_jump_x();
	void set_begin_jump_x(const int& new_begin_jump_x);
	int begin_jump_y();
	void set_begin_jump_y(const int& new_begin_jump_y);
	bool pause();
	void set_pause(const bool& new_pause);
	bool flying();
	void set_flying(const bool& new_flying);
	QString sprite_name();
	void set_sprite_name(const QString& new_sprite_name);
	int sprite_id();
	void set_sprite_id(const int& new_sprite_id);
	bool processed();
	void set_processed(const bool& new_processed);
	int flash_red();
	void set_flash_red(const int& new_flash_red);
	int flash_green();
	void set_flash_green(const int& new_flash_green);
	int flash_blue();
	void set_flash_blue(const int& new_flash_blue);
	double flash_current_level();
	void set_flash_current_level(const double& new_flash_current_level);
	int flash_time_left();
	void set_flash_time_left(const int& new_flash_time_left);

signals:
	void active_changed();
	void map_id_changed();
	void position_x_changed();
	void position_y_changed();
	void direction_changed();
	void sprite_direction_changed();
	void anim_frame_changed();
	void transparency_changed();
	void remaining_step_changed();
	void move_frequency_changed();
	void layer_changed();
	void overlap_forbidden_changed();
	void lock_facing_changed();
	void move_speed_changed();
	void move_route_overwrite_changed();
	void move_route_index_changed();
	void move_route_repeated_changed();
	void sprite_transparent_changed();
	void route_through_changed();
	void anim_paused_changed();
	void through_changed();
	void stop_count_changed();
	void anim_count_changed();
	void max_stop_count_changed();
	void jumping_changed();
	void begin_jump_x_changed();
	void begin_jump_y_changed();
	void pause_changed();
	void flying_changed();
	void sprite_name_changed();
	void sprite_id_changed();
	void processed_changed();
	void flash_red_changed();
	void flash_green_changed();
	void flash_blue_changed();
	void flash_current_level_changed();
	void flash_time_left_changed();

protected:
	lcf::rpg::SaveMapEventBase& m_data;
	Binding::MoveRoute* m_move_route;
};
} // namespace Binding::Generated
