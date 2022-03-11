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
#include "eventpage.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	EventPage::EventPage(ProjectData& project, lcf::rpg::EventPage& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_condition = new Binding::EventPageCondition(m_project, m_data.condition, this);
		m_move_route = new Binding::MoveRoute(m_project, m_data.move_route, this);
		{
			m_event_commands = new ArrayAdapter(this);
			auto& arr = m_event_commands->data();
			for (auto& var: m_data.event_commands)
				arr.push_back(new Binding::EventCommand(m_project, var, this));
		}
	}
	int EventPage::id() {
		return m_data.ID;
	}
	Binding::EventPageCondition* EventPage::condition() {
		return m_condition;
	}

	QString EventPage::character_name() {
		return ToQString(m_data.character_name);
	}
	void EventPage::set_character_name(const QString& new_character_name) {
		if (ToQString(m_data.character_name) == new_character_name)
			return;
		m_data.character_name = ToDBString(new_character_name);
		emit character_name_changed();
	}

	int EventPage::character_index() {
		return m_data.character_index;
	}
	void EventPage::set_character_index(const int& new_character_index) {
		if (m_data.character_index == new_character_index)
			return;
		m_data.character_index = new_character_index;
		emit character_index_changed();
	}

	int32_t EventPage::character_direction() {
		return m_data.character_direction;
	}

	int32_t EventPage::character_pattern() {
		return m_data.character_pattern;
	}

	bool EventPage::translucent() {
		return m_data.translucent;
	}
	void EventPage::set_translucent(const bool& new_translucent) {
		if (m_data.translucent == new_translucent)
			return;
		m_data.translucent = new_translucent;
		emit translucent_changed();
	}

	int32_t EventPage::move_type() {
		return m_data.move_type;
	}

	int EventPage::move_frequency() {
		return m_data.move_frequency;
	}
	void EventPage::set_move_frequency(const int& new_move_frequency) {
		if (m_data.move_frequency == new_move_frequency)
			return;
		m_data.move_frequency = new_move_frequency;
		emit move_frequency_changed();
	}

	int32_t EventPage::trigger() {
		return m_data.trigger;
	}

	int32_t EventPage::layer() {
		return m_data.layer;
	}

	bool EventPage::overlap_forbidden() {
		return m_data.overlap_forbidden;
	}
	void EventPage::set_overlap_forbidden(const bool& new_overlap_forbidden) {
		if (m_data.overlap_forbidden == new_overlap_forbidden)
			return;
		m_data.overlap_forbidden = new_overlap_forbidden;
		emit overlap_forbidden_changed();
	}

	int32_t EventPage::animation_type() {
		return m_data.animation_type;
	}

	int32_t EventPage::move_speed() {
		return m_data.move_speed;
	}

	Binding::MoveRoute* EventPage::move_route() {
		return m_move_route;
	}

	ArrayAdapter* EventPage::event_commands() {
		return m_event_commands;
	}

} // namespace Binding::Generated
