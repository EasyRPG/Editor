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
#include "trooppage.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	TroopPage::TroopPage(ProjectData& project, lcf::rpg::TroopPage& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
		m_condition = new Binding::TroopPageCondition(m_project, m_data.condition, this);
		{
			m_event_commands = new ArrayAdapter(this);
			auto& arr = m_event_commands->data();
			for (auto& var: m_data.event_commands)
				arr.push_back(new Binding::EventCommand(m_project, var, this));
		}
	}
	int TroopPage::id() {
		return m_data.ID;
	}
	Binding::TroopPageCondition* TroopPage::condition() {
		return m_condition;
	}

	ArrayAdapter* TroopPage::event_commands() {
		return m_event_commands;
	}

} // namespace Binding::Generated
