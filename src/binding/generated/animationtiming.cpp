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
#include "animationtiming.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	AnimationTiming::AnimationTiming(ProjectData& project, lcf::rpg::AnimationTiming& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_se = new Binding::Sound(m_project, m_data.se, this);
	}
	int AnimationTiming::id() {
		return m_data.ID;
	}
	int AnimationTiming::frame() {
		return m_data.frame;
	}
	void AnimationTiming::set_frame(const int& new_frame) {
		if (m_data.frame == new_frame)
			return;
		m_data.frame = new_frame;
		emit frame_changed();
	}

	Binding::Sound* AnimationTiming::se() {
		return m_se;
	}

	int AnimationTiming::flash_scope() {
		return m_data.flash_scope;
	}
	void AnimationTiming::set_flash_scope(const int& new_flash_scope) {
		if (m_data.flash_scope == new_flash_scope)
			return;
		m_data.flash_scope = new_flash_scope;
		emit flash_scope_changed();
	}

	int AnimationTiming::flash_red() {
		return m_data.flash_red;
	}
	void AnimationTiming::set_flash_red(const int& new_flash_red) {
		if (m_data.flash_red == new_flash_red)
			return;
		m_data.flash_red = new_flash_red;
		emit flash_red_changed();
	}

	int AnimationTiming::flash_green() {
		return m_data.flash_green;
	}
	void AnimationTiming::set_flash_green(const int& new_flash_green) {
		if (m_data.flash_green == new_flash_green)
			return;
		m_data.flash_green = new_flash_green;
		emit flash_green_changed();
	}

	int AnimationTiming::flash_blue() {
		return m_data.flash_blue;
	}
	void AnimationTiming::set_flash_blue(const int& new_flash_blue) {
		if (m_data.flash_blue == new_flash_blue)
			return;
		m_data.flash_blue = new_flash_blue;
		emit flash_blue_changed();
	}

	int AnimationTiming::flash_power() {
		return m_data.flash_power;
	}
	void AnimationTiming::set_flash_power(const int& new_flash_power) {
		if (m_data.flash_power == new_flash_power)
			return;
		m_data.flash_power = new_flash_power;
		emit flash_power_changed();
	}

	int AnimationTiming::screen_shake() {
		return m_data.screen_shake;
	}
	void AnimationTiming::set_screen_shake(const int& new_screen_shake) {
		if (m_data.screen_shake == new_screen_shake)
			return;
		m_data.screen_shake = new_screen_shake;
		emit screen_shake_changed();
	}

} // namespace Binding::Generated
