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
#include <lcf/rpg/rect.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::Rect class.
 * Exposes lcf::rpg::Rect to QML.
 */
namespace Binding::Generated {
class Rect : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int l READ l WRITE set_l NOTIFY l_changed)
	Q_PROPERTY(int t READ t WRITE set_t NOTIFY t_changed)
	Q_PROPERTY(int r READ r WRITE set_r NOTIFY r_changed)
	Q_PROPERTY(int b READ b WRITE set_b NOTIFY b_changed)

public:
	Rect(ProjectData& project, lcf::rpg::Rect& data, QObject* parent = nullptr);

	lcf::rpg::Rect& data();
	int l();
	void set_l(const int& new_l);
	int t();
	void set_t(const int& new_t);
	int r();
	void set_r(const int& new_r);
	int b();
	void set_b(const int& new_b);

signals:
	void l_changed();
	void t_changed();
	void r_changed();
	void b_changed();

protected:
	lcf::rpg::Rect& m_data;
};
} // namespace Binding::Generated
