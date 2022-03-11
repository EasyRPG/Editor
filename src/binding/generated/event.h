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
#include <lcf/rpg/event.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"
#include "binding/eventpage.h"

class ProjectData;

/**
 * Binding::Generated::Event class.
 * Exposes lcf::rpg::Event to QML.
 */
namespace Binding::Generated {
class Event : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
	Q_PROPERTY(int x READ x WRITE set_x NOTIFY x_changed)
	Q_PROPERTY(int y READ y WRITE set_y NOTIFY y_changed)
	Q_PROPERTY(ArrayAdapter* pages READ pages CONSTANT)

public:
	Event(ProjectData& project, lcf::rpg::Event& data, QObject* parent = nullptr);

	lcf::rpg::Event& data();
	int id();
	QString name();
	void set_name(const QString& new_name);
	int x();
	void set_x(const int& new_x);
	int y();
	void set_y(const int& new_y);
	ArrayAdapter* pages();

signals:
	void name_changed();
	void x_changed();
	void y_changed();

protected:
	lcf::rpg::Event& m_data;
	ArrayAdapter* m_pages;
};
} // namespace Binding::Generated
