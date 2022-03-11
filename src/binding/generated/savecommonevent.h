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

#pragma once

// Headers
#include <lcf/rpg/savecommonevent.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/saveeventexecstate.h"

class ProjectData;

/**
 * Binding::Generated::SaveCommonEvent class.
 * Exposes lcf::rpg::SaveCommonEvent to QML.
 */
namespace Binding::Generated {
class SaveCommonEvent : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(Binding::SaveEventExecState* parallel_event_execstate READ parallel_event_execstate CONSTANT)

public:
	SaveCommonEvent(ProjectData& project, lcf::rpg::SaveCommonEvent& data, QObject* parent = nullptr);

	lcf::rpg::SaveCommonEvent& data();
	int id();
	Binding::SaveEventExecState* parallel_event_execstate();

signals:

protected:
	lcf::rpg::SaveCommonEvent& m_data;
	Binding::SaveEventExecState* m_parallel_event_execstate;
};
} // namespace Binding::Generated
