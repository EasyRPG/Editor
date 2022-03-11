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
#include "rect.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Rect::Rect(ProjectData& project, lcf::rpg::Rect& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int Rect::l() {
		return m_data.l;
	}
	void Rect::set_l(const int& new_l) {
		if (m_data.l == new_l)
			return;
		m_data.l = new_l;
		emit l_changed();
	}

	int Rect::t() {
		return m_data.t;
	}
	void Rect::set_t(const int& new_t) {
		if (m_data.t == new_t)
			return;
		m_data.t = new_t;
		emit t_changed();
	}

	int Rect::r() {
		return m_data.r;
	}
	void Rect::set_r(const int& new_r) {
		if (m_data.r == new_r)
			return;
		m_data.r = new_r;
		emit r_changed();
	}

	int Rect::b() {
		return m_data.b;
	}
	void Rect::set_b(const int& new_b) {
		if (m_data.b == new_b)
			return;
		m_data.b = new_b;
		emit b_changed();
	}

} // namespace Binding::Generated
