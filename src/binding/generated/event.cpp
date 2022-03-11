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
#include "event.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Event::Event(ProjectData& project, lcf::rpg::Event& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_pages = new ArrayAdapter(this);
			auto& arr = m_pages->data();
			for (auto& var: m_data.pages)
				arr.push_back(new Binding::EventPage(m_project, var, this));
		}
	}
	int Event::id() {
		return m_data.ID;
	}
	QString Event::name() {
		return ToQString(m_data.name);
	}
	void Event::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	int Event::x() {
		return m_data.x;
	}
	void Event::set_x(const int& new_x) {
		if (m_data.x == new_x)
			return;
		m_data.x = new_x;
		emit x_changed();
	}

	int Event::y() {
		return m_data.y;
	}
	void Event::set_y(const int& new_y) {
		if (m_data.y == new_y)
			return;
		m_data.y = new_y;
		emit y_changed();
	}

	ArrayAdapter* Event::pages() {
		return m_pages;
	}

} // namespace Binding::Generated
