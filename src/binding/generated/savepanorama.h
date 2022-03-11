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
#include <lcf/rpg/savepanorama.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::SavePanorama class.
 * Exposes lcf::rpg::SavePanorama to QML.
 */
namespace Binding::Generated {
class SavePanorama : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int pan_x READ pan_x WRITE set_pan_x NOTIFY pan_x_changed)
	Q_PROPERTY(int pan_y READ pan_y WRITE set_pan_y NOTIFY pan_y_changed)

public:
	SavePanorama(ProjectData& project, lcf::rpg::SavePanorama& data, QObject* parent = nullptr);

	lcf::rpg::SavePanorama& data();
	int pan_x();
	void set_pan_x(const int& new_pan_x);
	int pan_y();
	void set_pan_y(const int& new_pan_y);

signals:
	void pan_x_changed();
	void pan_y_changed();

protected:
	lcf::rpg::SavePanorama& m_data;
};
} // namespace Binding::Generated
