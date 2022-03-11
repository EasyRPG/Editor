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
#include "animation.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Animation::Animation(ProjectData& project, lcf::rpg::Animation& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_timings = new ArrayAdapter(this);
			auto& arr = m_timings->data();
			for (auto& var: m_data.timings)
				arr.push_back(new Binding::AnimationTiming(m_project, var, this));
		}
		{
			m_frames = new ArrayAdapter(this);
			auto& arr = m_frames->data();
			for (auto& var: m_data.frames)
				arr.push_back(new Binding::AnimationFrame(m_project, var, this));
		}
	}
	int Animation::id() {
		return m_data.ID;
	}
	QString Animation::name() {
		return ToQString(m_data.name);
	}
	void Animation::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	QString Animation::animation_name() {
		return ToQString(m_data.animation_name);
	}
	void Animation::set_animation_name(const QString& new_animation_name) {
		if (ToQString(m_data.animation_name) == new_animation_name)
			return;
		m_data.animation_name = ToDBString(new_animation_name);
		emit animation_name_changed();
	}

	bool Animation::large() {
		return m_data.large;
	}
	void Animation::set_large(const bool& new_large) {
		if (m_data.large == new_large)
			return;
		m_data.large = new_large;
		emit large_changed();
	}

	ArrayAdapter* Animation::timings() {
		return m_timings;
	}

	int Animation::scope() {
		return m_data.scope;
	}
	void Animation::set_scope(const int& new_scope) {
		if (m_data.scope == new_scope)
			return;
		m_data.scope = new_scope;
		emit scope_changed();
	}

	int Animation::position() {
		return m_data.position;
	}
	void Animation::set_position(const int& new_position) {
		if (m_data.position == new_position)
			return;
		m_data.position = new_position;
		emit position_changed();
	}

	ArrayAdapter* Animation::frames() {
		return m_frames;
	}

} // namespace Binding::Generated
