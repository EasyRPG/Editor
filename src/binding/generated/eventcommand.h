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
#include <lcf/rpg/eventcommand.h>
#include "binding/binding_base.h"
#include "binding/array_adapter.h"

class ProjectData;

/**
 * Binding::Generated::EventCommand class.
 * Exposes lcf::rpg::EventCommand to QML.
 */
namespace Binding::Generated {
class EventCommand : public Binding::BindingBase {
	Q_OBJECT
	Q_PROPERTY(int32_t code READ code CONSTANT)
	Q_PROPERTY(int indent READ indent WRITE set_indent NOTIFY indent_changed)
	Q_PROPERTY(QString string READ string WRITE set_string NOTIFY string_changed)
	Q_PROPERTY(QVector<int> parameters READ parameters WRITE set_parameters NOTIFY parameters_changed)

public:
	EventCommand(ProjectData& project, lcf::rpg::EventCommand& data, QObject* parent = nullptr);

	lcf::rpg::EventCommand& data();
	int32_t code();
	int indent();
	void set_indent(const int& new_indent);
	QString string();
	void set_string(const QString& new_string);
	QVector<int> parameters();
	void set_parameters(const QVector<int>& new_parameters);

signals:
	void indent_changed();
	void string_changed();
	void parameters_changed();

protected:
	lcf::rpg::EventCommand& m_data;
};
} // namespace Binding::Generated
