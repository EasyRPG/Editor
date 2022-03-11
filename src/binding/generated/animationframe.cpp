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
#include "animationframe.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	AnimationFrame::AnimationFrame(ProjectData& project, lcf::rpg::AnimationFrame& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		{
			m_cells = new ArrayAdapter(this);
			auto& arr = m_cells->data();
			for (auto& var: m_data.cells)
				arr.push_back(new Binding::AnimationCellData(m_project, var, this));
		}
	}
	int AnimationFrame::id() {
		return m_data.ID;
	}
	ArrayAdapter* AnimationFrame::cells() {
		return m_cells;
	}

} // namespace Binding::Generated
