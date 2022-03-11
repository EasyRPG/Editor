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
#include "savecommonevent.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	SaveCommonEvent::SaveCommonEvent(ProjectData& project, lcf::rpg::SaveCommonEvent& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_parallel_event_execstate = new Binding::SaveEventExecState(m_project, m_data.parallel_event_execstate, this);
	}
	int SaveCommonEvent::id() {
		return m_data.ID;
	}
	Binding::SaveEventExecState* SaveCommonEvent::parallel_event_execstate() {
		return m_parallel_event_execstate;
	}

} // namespace Binding::Generated
