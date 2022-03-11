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
#include "savepanorama.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SavePanorama::SavePanorama(ProjectData& project, lcf::rpg::SavePanorama& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int SavePanorama::pan_x() {
		return m_data.pan_x;
	}
	void SavePanorama::set_pan_x(const int& new_pan_x) {
		if (m_data.pan_x == new_pan_x)
			return;
		m_data.pan_x = new_pan_x;
		emit pan_x_changed();
	}

	int SavePanorama::pan_y() {
		return m_data.pan_y;
	}
	void SavePanorama::set_pan_y(const int& new_pan_y) {
		if (m_data.pan_y == new_pan_y)
			return;
		m_data.pan_y = new_pan_y;
		emit pan_y_changed();
	}

} // namespace Binding::Generated
