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
#include <lcf/rpg/saveeasyrpgdata.h>
#include "binding/binding_base.h"

class ProjectData;

/**
 * Binding::Generated::SaveEasyRpgData class.
 * Exposes lcf::rpg::SaveEasyRpgData to QML.
 */
namespace Binding::Generated {
class SaveEasyRpgData : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int version READ version WRITE set_version NOTIFY version_changed)

public:
	SaveEasyRpgData(ProjectData& project, lcf::rpg::SaveEasyRpgData& data, QObject* parent = nullptr);

	lcf::rpg::SaveEasyRpgData& data();
	int version();
	void set_version(const int& new_version);

signals:
	void version_changed();

protected:
	lcf::rpg::SaveEasyRpgData& m_data;
};
} // namespace Binding::Generated
