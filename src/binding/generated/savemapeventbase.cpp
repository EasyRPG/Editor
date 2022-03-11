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
#include "savemapeventbase.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveMapEventBase::SaveMapEventBase(ProjectData& project, lcf::rpg::SaveMapEventBase& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_move_route = new Binding::MoveRoute(m_project, m_data.move_route, this);
	}
	bool SaveMapEventBase::active() {
		return m_data.active;
	}
	void SaveMapEventBase::set_active(const bool& new_active) {
		if (m_data.active == new_active)
			return;
		m_data.active = new_active;
		emit active_changed();
	}

	int SaveMapEventBase::map_id() {
		return m_data.map_id;
	}
	void SaveMapEventBase::set_map_id(const int& new_map_id) {
		if (m_data.map_id == new_map_id)
			return;
		m_data.map_id = new_map_id;
		emit map_id_changed();
	}

	int SaveMapEventBase::position_x() {
		return m_data.position_x;
	}
	void SaveMapEventBase::set_position_x(const int& new_position_x) {
		if (m_data.position_x == new_position_x)
			return;
		m_data.position_x = new_position_x;
		emit position_x_changed();
	}

	int SaveMapEventBase::position_y() {
		return m_data.position_y;
	}
	void SaveMapEventBase::set_position_y(const int& new_position_y) {
		if (m_data.position_y == new_position_y)
			return;
		m_data.position_y = new_position_y;
		emit position_y_changed();
	}

	int SaveMapEventBase::direction() {
		return m_data.direction;
	}
	void SaveMapEventBase::set_direction(const int& new_direction) {
		if (m_data.direction == new_direction)
			return;
		m_data.direction = new_direction;
		emit direction_changed();
	}

	int SaveMapEventBase::sprite_direction() {
		return m_data.sprite_direction;
	}
	void SaveMapEventBase::set_sprite_direction(const int& new_sprite_direction) {
		if (m_data.sprite_direction == new_sprite_direction)
			return;
		m_data.sprite_direction = new_sprite_direction;
		emit sprite_direction_changed();
	}

	int SaveMapEventBase::anim_frame() {
		return m_data.anim_frame;
	}
	void SaveMapEventBase::set_anim_frame(const int& new_anim_frame) {
		if (m_data.anim_frame == new_anim_frame)
			return;
		m_data.anim_frame = new_anim_frame;
		emit anim_frame_changed();
	}

	int SaveMapEventBase::transparency() {
		return m_data.transparency;
	}
	void SaveMapEventBase::set_transparency(const int& new_transparency) {
		if (m_data.transparency == new_transparency)
			return;
		m_data.transparency = new_transparency;
		emit transparency_changed();
	}

	int SaveMapEventBase::remaining_step() {
		return m_data.remaining_step;
	}
	void SaveMapEventBase::set_remaining_step(const int& new_remaining_step) {
		if (m_data.remaining_step == new_remaining_step)
			return;
		m_data.remaining_step = new_remaining_step;
		emit remaining_step_changed();
	}

	int SaveMapEventBase::move_frequency() {
		return m_data.move_frequency;
	}
	void SaveMapEventBase::set_move_frequency(const int& new_move_frequency) {
		if (m_data.move_frequency == new_move_frequency)
			return;
		m_data.move_frequency = new_move_frequency;
		emit move_frequency_changed();
	}

	int SaveMapEventBase::layer() {
		return m_data.layer;
	}
	void SaveMapEventBase::set_layer(const int& new_layer) {
		if (m_data.layer == new_layer)
			return;
		m_data.layer = new_layer;
		emit layer_changed();
	}

	bool SaveMapEventBase::overlap_forbidden() {
		return m_data.overlap_forbidden;
	}
	void SaveMapEventBase::set_overlap_forbidden(const bool& new_overlap_forbidden) {
		if (m_data.overlap_forbidden == new_overlap_forbidden)
			return;
		m_data.overlap_forbidden = new_overlap_forbidden;
		emit overlap_forbidden_changed();
	}

	int32_t SaveMapEventBase::animation_type() {
		return m_data.animation_type;
	}

	bool SaveMapEventBase::lock_facing() {
		return m_data.lock_facing;
	}
	void SaveMapEventBase::set_lock_facing(const bool& new_lock_facing) {
		if (m_data.lock_facing == new_lock_facing)
			return;
		m_data.lock_facing = new_lock_facing;
		emit lock_facing_changed();
	}

	int SaveMapEventBase::move_speed() {
		return m_data.move_speed;
	}
	void SaveMapEventBase::set_move_speed(const int& new_move_speed) {
		if (m_data.move_speed == new_move_speed)
			return;
		m_data.move_speed = new_move_speed;
		emit move_speed_changed();
	}

	Binding::MoveRoute* SaveMapEventBase::move_route() {
		return m_move_route;
	}

	bool SaveMapEventBase::move_route_overwrite() {
		return m_data.move_route_overwrite;
	}
	void SaveMapEventBase::set_move_route_overwrite(const bool& new_move_route_overwrite) {
		if (m_data.move_route_overwrite == new_move_route_overwrite)
			return;
		m_data.move_route_overwrite = new_move_route_overwrite;
		emit move_route_overwrite_changed();
	}

	int SaveMapEventBase::move_route_index() {
		return m_data.move_route_index;
	}
	void SaveMapEventBase::set_move_route_index(const int& new_move_route_index) {
		if (m_data.move_route_index == new_move_route_index)
			return;
		m_data.move_route_index = new_move_route_index;
		emit move_route_index_changed();
	}

	bool SaveMapEventBase::move_route_repeated() {
		return m_data.move_route_repeated;
	}
	void SaveMapEventBase::set_move_route_repeated(const bool& new_move_route_repeated) {
		if (m_data.move_route_repeated == new_move_route_repeated)
			return;
		m_data.move_route_repeated = new_move_route_repeated;
		emit move_route_repeated_changed();
	}

	bool SaveMapEventBase::sprite_transparent() {
		return m_data.sprite_transparent;
	}
	void SaveMapEventBase::set_sprite_transparent(const bool& new_sprite_transparent) {
		if (m_data.sprite_transparent == new_sprite_transparent)
			return;
		m_data.sprite_transparent = new_sprite_transparent;
		emit sprite_transparent_changed();
	}

	bool SaveMapEventBase::route_through() {
		return m_data.route_through;
	}
	void SaveMapEventBase::set_route_through(const bool& new_route_through) {
		if (m_data.route_through == new_route_through)
			return;
		m_data.route_through = new_route_through;
		emit route_through_changed();
	}

	int SaveMapEventBase::anim_paused() {
		return m_data.anim_paused;
	}
	void SaveMapEventBase::set_anim_paused(const int& new_anim_paused) {
		if (m_data.anim_paused == new_anim_paused)
			return;
		m_data.anim_paused = new_anim_paused;
		emit anim_paused_changed();
	}

	bool SaveMapEventBase::through() {
		return m_data.through;
	}
	void SaveMapEventBase::set_through(const bool& new_through) {
		if (m_data.through == new_through)
			return;
		m_data.through = new_through;
		emit through_changed();
	}

	int SaveMapEventBase::stop_count() {
		return m_data.stop_count;
	}
	void SaveMapEventBase::set_stop_count(const int& new_stop_count) {
		if (m_data.stop_count == new_stop_count)
			return;
		m_data.stop_count = new_stop_count;
		emit stop_count_changed();
	}

	int SaveMapEventBase::anim_count() {
		return m_data.anim_count;
	}
	void SaveMapEventBase::set_anim_count(const int& new_anim_count) {
		if (m_data.anim_count == new_anim_count)
			return;
		m_data.anim_count = new_anim_count;
		emit anim_count_changed();
	}

	int SaveMapEventBase::max_stop_count() {
		return m_data.max_stop_count;
	}
	void SaveMapEventBase::set_max_stop_count(const int& new_max_stop_count) {
		if (m_data.max_stop_count == new_max_stop_count)
			return;
		m_data.max_stop_count = new_max_stop_count;
		emit max_stop_count_changed();
	}

	bool SaveMapEventBase::jumping() {
		return m_data.jumping;
	}
	void SaveMapEventBase::set_jumping(const bool& new_jumping) {
		if (m_data.jumping == new_jumping)
			return;
		m_data.jumping = new_jumping;
		emit jumping_changed();
	}

	int SaveMapEventBase::begin_jump_x() {
		return m_data.begin_jump_x;
	}
	void SaveMapEventBase::set_begin_jump_x(const int& new_begin_jump_x) {
		if (m_data.begin_jump_x == new_begin_jump_x)
			return;
		m_data.begin_jump_x = new_begin_jump_x;
		emit begin_jump_x_changed();
	}

	int SaveMapEventBase::begin_jump_y() {
		return m_data.begin_jump_y;
	}
	void SaveMapEventBase::set_begin_jump_y(const int& new_begin_jump_y) {
		if (m_data.begin_jump_y == new_begin_jump_y)
			return;
		m_data.begin_jump_y = new_begin_jump_y;
		emit begin_jump_y_changed();
	}

	bool SaveMapEventBase::pause() {
		return m_data.pause;
	}
	void SaveMapEventBase::set_pause(const bool& new_pause) {
		if (m_data.pause == new_pause)
			return;
		m_data.pause = new_pause;
		emit pause_changed();
	}

	bool SaveMapEventBase::flying() {
		return m_data.flying;
	}
	void SaveMapEventBase::set_flying(const bool& new_flying) {
		if (m_data.flying == new_flying)
			return;
		m_data.flying = new_flying;
		emit flying_changed();
	}

	QString SaveMapEventBase::sprite_name() {
		return QString::fromStdString(m_data.sprite_name);
	}
	void SaveMapEventBase::set_sprite_name(const QString& new_sprite_name) {
		if (QString::fromStdString(m_data.sprite_name) == new_sprite_name)
			return;
		m_data.sprite_name = new_sprite_name.toStdString();
		emit sprite_name_changed();
	}

	int SaveMapEventBase::sprite_id() {
		return m_data.sprite_id;
	}
	void SaveMapEventBase::set_sprite_id(const int& new_sprite_id) {
		if (m_data.sprite_id == new_sprite_id)
			return;
		m_data.sprite_id = new_sprite_id;
		emit sprite_id_changed();
	}

	bool SaveMapEventBase::processed() {
		return m_data.processed;
	}
	void SaveMapEventBase::set_processed(const bool& new_processed) {
		if (m_data.processed == new_processed)
			return;
		m_data.processed = new_processed;
		emit processed_changed();
	}

	int SaveMapEventBase::flash_red() {
		return m_data.flash_red;
	}
	void SaveMapEventBase::set_flash_red(const int& new_flash_red) {
		if (m_data.flash_red == new_flash_red)
			return;
		m_data.flash_red = new_flash_red;
		emit flash_red_changed();
	}

	int SaveMapEventBase::flash_green() {
		return m_data.flash_green;
	}
	void SaveMapEventBase::set_flash_green(const int& new_flash_green) {
		if (m_data.flash_green == new_flash_green)
			return;
		m_data.flash_green = new_flash_green;
		emit flash_green_changed();
	}

	int SaveMapEventBase::flash_blue() {
		return m_data.flash_blue;
	}
	void SaveMapEventBase::set_flash_blue(const int& new_flash_blue) {
		if (m_data.flash_blue == new_flash_blue)
			return;
		m_data.flash_blue = new_flash_blue;
		emit flash_blue_changed();
	}

	double SaveMapEventBase::flash_current_level() {
		return m_data.flash_current_level;
	}
	void SaveMapEventBase::set_flash_current_level(const double& new_flash_current_level) {
		if (m_data.flash_current_level == new_flash_current_level)
			return;
		m_data.flash_current_level = new_flash_current_level;
		emit flash_current_level_changed();
	}

	int SaveMapEventBase::flash_time_left() {
		return m_data.flash_time_left;
	}
	void SaveMapEventBase::set_flash_time_left(const int& new_flash_time_left) {
		if (m_data.flash_time_left == new_flash_time_left)
			return;
		m_data.flash_time_left = new_flash_time_left;
		emit flash_time_left_changed();
	}

} // namespace Binding::Generated
