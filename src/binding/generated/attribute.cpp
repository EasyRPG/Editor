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
#include "attribute.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Attribute::Attribute(ProjectData& project, lcf::rpg::Attribute& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int Attribute::id() {
		return m_data.ID;
	}
	QString Attribute::name() {
		return ToQString(m_data.name);
	}
	void Attribute::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	int Attribute::type() {
		return m_data.type;
	}
	void Attribute::set_type(const int& new_type) {
		if (m_data.type == new_type)
			return;
		m_data.type = new_type;
		emit type_changed();
	}

	int Attribute::a_rate() {
		return m_data.a_rate;
	}
	void Attribute::set_a_rate(const int& new_a_rate) {
		if (m_data.a_rate == new_a_rate)
			return;
		m_data.a_rate = new_a_rate;
		emit a_rate_changed();
	}

	int Attribute::b_rate() {
		return m_data.b_rate;
	}
	void Attribute::set_b_rate(const int& new_b_rate) {
		if (m_data.b_rate == new_b_rate)
			return;
		m_data.b_rate = new_b_rate;
		emit b_rate_changed();
	}

	int Attribute::c_rate() {
		return m_data.c_rate;
	}
	void Attribute::set_c_rate(const int& new_c_rate) {
		if (m_data.c_rate == new_c_rate)
			return;
		m_data.c_rate = new_c_rate;
		emit c_rate_changed();
	}

	int Attribute::d_rate() {
		return m_data.d_rate;
	}
	void Attribute::set_d_rate(const int& new_d_rate) {
		if (m_data.d_rate == new_d_rate)
			return;
		m_data.d_rate = new_d_rate;
		emit d_rate_changed();
	}

	int Attribute::e_rate() {
		return m_data.e_rate;
	}
	void Attribute::set_e_rate(const int& new_e_rate) {
		if (m_data.e_rate == new_e_rate)
			return;
		m_data.e_rate = new_e_rate;
		emit e_rate_changed();
	}

} // namespace Binding::Generated
