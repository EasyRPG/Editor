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
#include "learning.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	Learning::Learning(ProjectData& project, lcf::rpg::Learning& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int Learning::id() {
		return m_data.ID;
	}
	int Learning::level() {
		return m_data.level;
	}
	void Learning::set_level(const int& new_level) {
		if (m_data.level == new_level)
			return;
		m_data.level = new_level;
		emit level_changed();
	}

	int32_t Learning::skill_id() {
		return m_data.skill_id;
	}

} // namespace Binding::Generated
