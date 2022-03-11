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
#include <lcf/rpg/movecommand.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::MoveCommand class.
 * Exposes lcf::rpg::MoveCommand to QML.
 */
namespace Binding::Generated {
class MoveCommand : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int command_id READ command_id WRITE set_command_id NOTIFY command_id_changed)
	Q_PROPERTY(QString parameter_string READ parameter_string WRITE set_parameter_string NOTIFY parameter_string_changed)
	Q_PROPERTY(int parameter_a READ parameter_a WRITE set_parameter_a NOTIFY parameter_a_changed)
	Q_PROPERTY(int parameter_b READ parameter_b WRITE set_parameter_b NOTIFY parameter_b_changed)
	Q_PROPERTY(int parameter_c READ parameter_c WRITE set_parameter_c NOTIFY parameter_c_changed)

public:
	MoveCommand(ProjectData& project, lcf::rpg::MoveCommand& data, QObject* parent = nullptr);

	lcf::rpg::MoveCommand& data();
	int command_id();
	void set_command_id(const int& new_command_id);
	QString parameter_string();
	void set_parameter_string(const QString& new_parameter_string);
	int parameter_a();
	void set_parameter_a(const int& new_parameter_a);
	int parameter_b();
	void set_parameter_b(const int& new_parameter_b);
	int parameter_c();
	void set_parameter_c(const int& new_parameter_c);

signals:
	void command_id_changed();
	void parameter_string_changed();
	void parameter_a_changed();
	void parameter_b_changed();
	void parameter_c_changed();

protected:
	lcf::rpg::MoveCommand& m_data;
};
} // namespace Binding::Generated
