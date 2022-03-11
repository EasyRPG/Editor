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
#include "battlecommand.h"
#include "common/dbstring.h"

namespace Binding::Generated {
	BattleCommand::BattleCommand(ProjectData& project, lcf::rpg::BattleCommand& data, QObject* parent) : Binding::BindingBase(project, parent), m_data(data) {
	}
	int BattleCommand::id() {
		return m_data.ID;
	}
	QString BattleCommand::name() {
		return ToQString(m_data.name);
	}
	void BattleCommand::set_name(const QString& new_name) {
		if (ToQString(m_data.name) == new_name)
			return;
		m_data.name = ToDBString(new_name);
		emit name_changed();
	}

	int32_t BattleCommand::type() {
		return m_data.type;
	}

} // namespace Binding::Generated
